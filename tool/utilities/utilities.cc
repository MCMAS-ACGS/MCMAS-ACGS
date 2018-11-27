#include "utilities.hh"
#include "cuddInt.h"
#include "tinyxml.hh"
#include <functional>
#include <queue>
#include <cstring>
#include <iostream>
#include <string>
#include <sstream>
#include <memory>
#include <algorithm>
#include <stdexcept>
#include "tinyxml.hh"
#include <iterator>
#include "types.hh"

using namespace std;
extern vector< basic_agent* > *agents;
extern map< string, unsigned int >* is_agents_index;
extern map< string, bool_expression * >*is_evaluation;
extern map< string, BDD > * is_new_evaluation; 
void free_mcmas_memory(bdd_parameters *para);
extern bool is_valid_state(BDD state, vector<BDD> v);
extern BDD all_reach;
extern vector<BDD>* all_reach_vec;


extern map<string, map<string, vector<BDD*>* >* >* integer_variable_BDDs(Cudd * bddmgr, vector<BDD> * v);
extern BDD complete_integer_BDDs(Cudd * bddmgr, vector<BDD> * v, BDD a, map<string, map<string, vector<BDD*>* >* >* int_vars);
BDD compute_reach(BDD in_st, vector<BDD> *v, vector<BDD> *pv, vector<BDD> *a, vector<BDD> *vRT, Cudd *bddmgr, unsigned int *acounter1, int id, unsigned long *threadmem);
BDD
Exists(Cudd * bddmgr, vector<BDD> * v, BDD x)
{
  BDD tmp = bddmgr->bddOne();  
  for (unsigned int j = 0; j < v->size(); j++) {
    tmp = tmp * (*v)[j];
  } return x.ExistAbstract(tmp);
}

BDD
Exists(Cudd * bddmgr, vector<BDD> * v, vector<BDD> * a, BDD x)
{
  BDD tmp = bddmgr->bddOne();  
  for (unsigned int j = 0; j < v->size(); j++) {
    tmp = tmp * (*v)[j];
  } 
  for (unsigned int j = 0; j < a->size(); j++) {
    tmp = tmp * (*a)[j];
  }
  return x.ExistAbstract(tmp);
}

BDD
Exists(Cudd * bddmgr, vector<BDD> * v, BDD x, unsigned int start, unsigned int end)
{
  BDD tmp = bddmgr->bddOne();  
  for (unsigned int j = start; j <= end; j++) {
    tmp = tmp * (*v)[j];
  } return x.ExistAbstract(tmp);
}

BDD
Abstract_key_var(Cudd * bddmgr, vector<BDD> * v, BDD x, int index_begin, int index_end)
{
  BDD tmp = bddmgr->bddOne();  
  for (int j = 0; j < index_begin; j++) {
    tmp = tmp * (*v)[j];
  }
  for (unsigned int j = index_end+1; j < v->size(); j++) {
    tmp = tmp * (*v)[j];
  } 
  return x.ExistAbstract(tmp);
}

ADD
ADDExists(Cudd * bddmgr, vector<ADD> v, ADD x)
{
  ADD tmp = bddmgr->addOne(); 
  for (unsigned int j = 0; j < v.size(); j++) {
    tmp = tmp * v[j];
  } 
  return x.ExistAbstract(tmp);
}

BDD
timesTrans(BDD * from, BDD * to, vector<BDD> * vRT)
{
  BDD result;
  result = (*from) * (*to) * (*vRT)[0];
  for (unsigned int i = 1; i < agents->size(); i++)
    result *= (*vRT)[i];
  return result;
}

BDD
timesRT(BDD * state, Cudd * bddmgr, vector<BDD> * vRT, vector<BDD> * a)
{
  BDD result;
  result = (*state) * (*vRT)[0];
  for (unsigned int i = 1; i < agents->size(); i++)
    result *= (*vRT)[i];
  result = Exists(bddmgr, a, result);
  return result;
}

BDD 
compute_successors(BDD *state, Cudd * bddmgr, vector<BDD> * vRT, vector<BDD> * a, vector<BDD> *v, vector<BDD> *pv)
{
  BDD result = timesRT(state, bddmgr, vRT, a);
  result = Exists(bddmgr, v, result);
  result = result.SwapVariables(*v, *pv);
  return result;
}

BDD
check_EX(BDD next, bdd_parameters * para)
{
  if(options["nobddcache"] == 0) {
    if (para->calReachRT) {
      BDD reachRT1 = *para->reach;
      for (unsigned int i = 0; i < agents->size(); i++)
        reachRT1 *= (*para->vRT)[i];
      para->reachRT = new BDD(reachRT1);
      para->calReachRT = false;
    }
  }
  BDD result = next.SwapVariables(*para->v, *para->pv); 
  if(options["nobddcache"] == 0)
    result = result * (*para->reachRT);
  else {
    for (unsigned int i = 0; i < agents->size(); i++)
      result *= (*para->vRT)[i];
  }
  result = Exists(para->bddmgr, para->pv, result);     
  result = Exists(para->bddmgr, para->a, result);     
  result = result * (*para->reach);
  return result;
}

BDD
check_EF(BDD p, bdd_parameters * para)
{
  // Computes the fixpoint iterating false
  BDD tmp = para->bddmgr->bddOne();
  BDD q = para->bddmgr->bddZero();
  while (q != tmp) {
    tmp = q;
    q = p + check_EX(tmp, para);//q-->tau(z), tmp-->z
  }
  return q * (*para->reach);
}

BDD
check_EG(BDD p, bdd_parameters * para)
{
  // Computes the fixpoint iterating false
  if(is_fairness->empty()) {
    BDD tmp = para->bddmgr->bddZero();
    BDD q = para->bddmgr->bddOne();
    while (q != tmp) {
      tmp = q;
      BDD x = check_EX(tmp, para);
      q = p * x;//q-->tau(z), tmp-->z
    }
    return q;
  } else
    return check_EG_fair(p, para);
}



BDD
check_EU(BDD p, BDD q, bdd_parameters * para)
{                               // See Huth-Ryan, pag. 180
  BDD W = p;
  BDD X = *para->reach;
  BDD Y = q;
  while (X != Y) {
    X = Y;
    Y = Y + (W * check_EX(Y, para));
  }
  return Y;
}


BDD
check_EU_Qh(BDD p, BDD q, bdd_parameters * para, vector< BDD* >* qh)
{       
  BDD W = p;
  BDD X = *para->reach;
  BDD Y = q;
  BDD Z = Y;
  qh->push_back(new BDD(Y));
  while (X != Y) {
    X = Y;
    Z = W * check_EX(Z, para);
    Z = Z - Y;
    Y = Y + Z;
    if(X != Y)
      qh->push_back(new BDD(Z));
  }
  return Y;
}

BDD
check_AU(BDD p, BDD q, bdd_parameters * para)
{                               // Tricky one, see Huth Ryan pag. 167 and 179
  BDD result = !(check_EU(!q, !p * !q, para) + check_EG(!q, para)) * (*para->reach);
  return result;
}


BDD
check_AU_RT(BDD p, BDD q, int k, bdd_parameters * para)
{                               
	BDD allAU = q;
	for(int i=1; i<=k; i++) {
		// get predecesors of allAU
		BDD t = check_EX(allAU, para);
		// remove states that are included in AU^0 - AU^(i-1) already
		t -= allAU;
		if(t == para->bddmgr->bddZero())
			break;
		// get states that can reach states outside allAU
		BDD t1 = check_EX(*para->reach - allAU, para);
		// remove from t the states that can reach states outside allAU
		t -= t1;
		// remove from t the states that do not satisfy p
		t *= p;
		if(t != para->bddmgr->bddZero()) {
			allAU += t;
		} else 
			break;
	}

  return allAU;
}

BDD
check_EU_RT(BDD p, BDD q, int k, bdd_parameters * para)
{                               
	BDD allEU = q;
	BDD lastEU = q;
	for(int i=1; i<=k; i++) {
		// get predecesors of allEU
		BDD t = check_EX(lastEU, para);
		// remove states that are included in EU^0 - EU^(i-1) already
		t -= allEU;
		// remove from t the states that do not satisfy p
		t *= p;
		if(t != para->bddmgr->bddZero()) {
			allEU += t;
			lastEU = t;
		} else 
			break;
	}

  return allEU;
}

BDD
check_nO(BDD next, string name, bdd_parameters * para)
{
  // Check deontic
  next = next.SwapVariables(*para->v, *para->pv);       // Now it's the next state
  BDD RO = (*is_agents)[name]->encode_greenstates(para);
  BDD result = Exists(para->bddmgr, para->pv, RO * next * (*para->reach));      // States from which...
  return result;
}

BDD
check_GK(BDD next, string name, bdd_parameters * para)
{
  set < string > gi = (*is_groups)[name];
  BDD tmp = para->bddmgr->bddZero();
  BDD ntmp = all_reach - next;
  for (set < string >::iterator igs = gi.begin(); igs != gi.end(); igs++) {
    basic_agent *agent = (*is_agents)[*igs];
    tmp += agent->project_local_state(&ntmp, para->bddmgr, para->v);
  }
  tmp = all_reach - tmp;
  return tmp;
}

BDD
SCGS_check_GK(BDD next, string name, bdd_parameters * para)
{
  set < string > gi = (*is_groups)[name];
  BDD tmp = para->bddmgr->bddZero();  
  BDD ntmp = !next * all_reach;  
  for (set < string >::iterator igs = gi.begin(); igs != gi.end(); igs++) {
    basic_agent *agent = (*is_agents)[*igs];
	if(agent->get_strategy_type()=="ior"||agent->get_strategy_type()=="isr")
      tmp += agent->project_local_state(&ntmp, para->bddmgr, para->v);
	else
	  tmp += ntmp;
  }
  tmp = all_reach - tmp;
  return tmp;
}


// not only consider the reachable state, but also the unreachable state, that means all states should be considered
BDD
SCGS_check_GK_2(BDD next, string name, bdd_parameters * para)
{
  set < string > gi = (*is_groups)[name];
  BDD tmp = para->bddmgr->bddZero();  
  BDD ntmp = !next * all_reach;  
  for (set < string >::iterator igs = gi.begin(); igs != gi.end(); igs++) {
    basic_agent *agent = (*is_agents)[*igs];
	if(agent->get_strategy_type()=="isr"){
      tmp += agent->project_local_state(&ntmp, para->bddmgr, para->v);
	}
	else
	  tmp += ntmp;
  }
  tmp = all_reach - tmp;
  return tmp;
}

BDD
SCGS_check_GK_3(BDD next, string name, bdd_parameters * para)
{
  set < string > gi = (*is_groups)[name];
  BDD tmp = next;  
  for (set < string >::iterator igs = gi.begin(); igs != gi.end(); igs++) {
    basic_agent *agent = (*is_agents)[*igs];
	if(agent->get_strategy_type()=="isr"){
      tmp += (agent->project_local_state(&next, para->bddmgr, para->v)*all_reach);
	}
  }
  return tmp;
}


BDD
check_DK(BDD next, string name, bdd_parameters * para)
{
  set < string > gi = (*is_groups)[name];
  BDD tmp = para->bddmgr->bddOne();
  BDD ntmp = all_reach - next;
  vector<BDD> *v = para->v;

  if(gi.find((*agents)[0]->get_name()) == gi.end()) {
    map< string, basictype * >*envars = (*agents)[0]->get_vars();
    if(envars != NULL && envars->size() > 0) {
      set<string> *alllobs = new set<string>();
      for (set < string >::iterator igs = gi.begin(); igs != gi.end(); igs++) {
        basic_agent *agent = (*is_agents)[*igs];
        map< string, variable * >* lobs = agent->get_lobsvars();
        if (lobs != NULL && lobs->size() > 0)
          for (map< string, variable * >::iterator i = lobs->begin(); i != lobs->end(); i++)
            alllobs->insert(i->first);
      }
                        
      for (map< string, basictype * >::iterator i = envars->begin();
           i != envars->end(); i++) {
        if (alllobs->find(i->first) == alllobs->end()) {  
          basictype *bt = i->second;
          int index_begin = bt->get_index_begin();
          int index_end = bt->get_index_end();
          for (int j = index_begin; j <= index_end; j++)
            tmp = tmp * (*v)[j];
        }
      }
      delete alllobs;
    }
  }

  for (unsigned int i=1; i<agents->size(); i++) {
    basic_agent *agent = (*agents)[i];
    if(gi.find(agent->get_name()) == gi.end()) {
      int index_begin = agent->get_var_index_begin();
      int index_end = agent->get_var_index_end();
      for (int j = index_begin; j <= index_end; j++) {
        tmp = tmp * (*v)[j];
      }
    }
                
  }

  tmp = all_reach - ntmp.ExistAbstract(tmp);
  return tmp;
}

BDD
SCGS_check_DK(BDD next, string name, bdd_parameters * para)
{
  set < string > gi = (*is_groups)[name];
  BDD tmp = para->bddmgr->bddOne();
  BDD ntmp = !next * all_reach;
  vector<BDD> *v = para->v;

  if(gi.find((*agents)[0]->get_name()) == gi.end()) {
    map< string, basictype * >*envars = (*agents)[0]->get_vars(); 
    if(envars != NULL && envars->size() > 0) {
      set<string> *alllobs = new set<string>();
      for (set < string >::iterator igs = gi.begin(); igs != gi.end(); igs++) {
        basic_agent *agent = (*is_agents)[*igs];
        map< string, variable * >* lobs = agent->get_lobsvars();
        if (lobs != NULL && lobs->size() > 0)
          for (map< string, variable * >::iterator i = lobs->begin(); i != lobs->end(); i++)
            alllobs->insert(i->first);
      }
                        
      for (map< string, basictype * >::iterator i = envars->begin();
           i != envars->end(); i++) {
        if (alllobs->find(i->first) == alllobs->end()) {  
          basictype *bt = i->second;
          int index_begin = bt->get_index_begin();
          int index_end = bt->get_index_end();
          for (int j = index_begin; j <= index_end; j++)
            tmp = tmp * (*v)[j];
        }
      }
      delete alllobs;
    }
  }

  BDD tmp2 = tmp;
  for (unsigned int i=1; i<agents->size(); i++) {
  	
    basic_agent *agent = (*agents)[i];
	bool b1 = gi.find(agent->get_name()) == gi.end();
    bool b2 = ((agent->get_strategy_type() == "isr") || (agent->get_strategy_type() == "ior"));
	if((!b1)&&(!b2)){ 
      tmp = all_reach - ntmp.ExistAbstract(tmp2);
	  return tmp;
	}
	else{
	  if(gi.find(agent->get_name()) == gi.end()) {
		int index_begin = agent->get_var_index_begin();
		int index_end = agent->get_var_index_end();
		for (int j = index_begin; j <= index_end; j++) {
		  tmp = tmp * (*v)[j];
		}
	  }
	}                
  }

  tmp = all_reach - ntmp.ExistAbstract(tmp);
  return tmp;
}

BDD
check_GCK(BDD next, string name, bdd_parameters * para)
{
  // GCK p = GK(p * GCK(p)) see fhmv:rak, section 11.5
  BDD tmp = all_reach;
  BDD tmp2 = next;
  set < string > gi = (*is_groups)[name];
  while (tmp != tmp2) {
    tmp2 = tmp;
    tmp = next * tmp;
    BDD ntmp = all_reach - tmp;
    tmp = para->bddmgr->bddZero();
    for (set < string >::iterator igs = gi.begin(); igs != gi.end(); igs++) {
      basic_agent *agent = (*is_agents)[*igs];
      tmp += agent->project_local_state(&ntmp, para->bddmgr, para->v);
    }
    tmp = all_reach - tmp;
  }
  return tmp;
}

BDD
SCGS_check_GCK(BDD next, string name, bdd_parameters * para)
{
  // GCK p = GK(p * GCK(p)) see fhmv:rak, section 11.5
  BDD tmp = all_reach;
  BDD tmp2 = next;
  set < string > gi = (*is_groups)[name];
  while (tmp != tmp2) {
    tmp2 = tmp;
    tmp = next * tmp;
    BDD ntmp = !tmp * all_reach;
    tmp = para->bddmgr->bddZero();
    for (set < string >::iterator igs = gi.begin(); igs != gi.end(); igs++) {
      basic_agent *agent = (*is_agents)[*igs];
	  if(agent->get_strategy_type()=="isr"||agent->get_strategy_type()=="ior")
        tmp += agent->project_local_state(&ntmp, para->bddmgr, para->v);
	  else
	  	tmp += ntmp;
    }
    tmp = all_reach - tmp;
  }
  return tmp;
}


BDD
check_ATLX(BDD next, string grpname, bdd_parameters * para)
{
  BDD result = para->bddmgr->bddZero();
  BDD actagtin = para->bddmgr->bddOne();        
  BDD actagtout = para->bddmgr->bddOne();      
  int begin, end;
  map < string, set < string > >::iterator gi = is_groups->find(grpname);
  set < string > names_g = gi->second;  // the list of agt names in groups
  for (map < string, basic_agent * >::iterator i = is_agents->begin();
       i != is_agents->end(); i++) {
    begin = i->second->get_action_index_begin();
    end = i->second->get_action_index_end();   
    if (names_g.find(i->first) == names_g.end()) {
      for (int j = begin; j <= end; j++) {
        actagtout = actagtout * (*para->a)[j];
      }}

    else {
      for (int j = begin; j <= end; j++) {
        actagtin = actagtin * (*para->a)[j];
      }}} 
  BDD partial = (!next) * (*para->reach);

  partial = partial.SwapVariables(*para->v, *para->pv);
  for (unsigned int i = 0; i < agents->size(); i++)
    partial = partial * (*para->vevol)[i];
  partial = Exists(para->bddmgr, para->pv, partial);
  partial = partial * (*para->reach);

  for (unsigned int i = 0; i < agents->size(); i++)
    partial = partial * (*para->vprot)[i];
  partial = partial.ExistAbstract(actagtout);

  partial = (!partial) * (*para->reach);
  for (unsigned int i = 0; i < agents->size(); i++)
    partial = partial * (*para->vprot)[i];
  partial = partial.ExistAbstract(actagtout);

  result = partial.ExistAbstract(actagtin) * (*para->reach);
  return result;
}

BDD
check_ATLG_aux(BDD p, string grpname, bdd_parameters * para)
{
  BDD tmp = p;
  BDD q = para->bddmgr->bddOne();
  while (q != tmp) {
    q = tmp;
    tmp = p * check_ATLX(tmp, grpname, para);
  }
  return q;
}

BDD
check_ATLG(BDD p, string grpname, bdd_parameters * para)
{
  if(is_fairness->empty()) {
    return check_ATLG_aux(p, grpname, para);
  } else
    return check_ATLG_fair(p, grpname, para);
}

BDD
check_ATLU(BDD q1, BDD q2, string grpname, bdd_parameters * para)
{
  BDD r = para->bddmgr->bddZero();
  BDD t = q2;
  while (t != r) {
    r = t;
    t = r + check_ATLX(r, grpname, para) * q1;
  }
  return r;
}

BDD
check_ATLX_fair(BDD next, string grpname, BDD fair_reach,
                bdd_parameters * para)
{
  return check_ATLX(next * fair_reach, grpname, para);
}

BDD
check_ATLG_fair(BDD p, string grpname, bdd_parameters * para)
{
  BDD tmp = para->bddmgr->bddZero();
  BDD q = para->bddmgr->bddOne();
  BDD fc_bdd = para->bddmgr->bddOne();
  while (q != tmp) {
    tmp = q;
    for (vector < fairness_expression * >::iterator fi =
           is_fairness->begin(); fi != is_fairness->end(); fi++) {
      BDD hf = (*fi)->get_bdd_representation(); // The BDD for the fairness constraint
      BDD tmp1 = check_ATLU(p, q * hf, grpname, para);
      
      fc_bdd = fc_bdd * check_ATLX(tmp1, grpname, para);
    }
    q = p * fc_bdd;
  }
  return q;
}

BDD
check_ATLU_fair(BDD q1, BDD q2, string grpname, BDD fair_reach,
                bdd_parameters * para)
{
  return check_ATLU(q1, q2 * fair_reach, grpname, para);
}

BDD
check_EG_fair(BDD p, bdd_parameters * para)
{
  // Computes the fixpoint iterating false
  // See "Efficient generation of counterexamples and witnesses in
  // symbolic model checking", Clarke Grumberg McMillan Zhao, 1995
  // Section 4, p.3
  BDD tmp = para->bddmgr->bddZero();
  BDD q = para->bddmgr->bddOne();
  BDD fc_bdd = para->bddmgr->bddOne();
  while (q != tmp) {
    tmp = q;
    for (vector < fairness_expression * >::iterator fi =
           is_fairness->begin(); fi != is_fairness->end(); fi++) {
      BDD hf = (*fi)->get_bdd_representation(); // The BDD for the fairness constraint
      BDD tmp1 = check_EU(p, q * hf, para);
      fc_bdd = fc_bdd * check_EX(tmp1, para);
    }
    q = p * fc_bdd;
  }
  return q;
}




BDD
check_EG_fair_Qh(BDD p, bdd_parameters * para, vector< vector < BDD* >* >* Qh) 
{
  if(Qh->empty()) {
    for(unsigned int k=0; k<is_fairness->size(); k++) 
      Qh->push_back(new vector< BDD* >());
  }
  
  BDD tmp = para->bddmgr->bddZero();
  BDD q = para->bddmgr->bddOne();
  BDD fc_bdd = para->bddmgr->bddOne();
  //int x = 0;
  while (q != tmp) {
    tmp = q;
    //x = 0;
    for (unsigned int k=0; k<is_fairness->size(); k++) {
      BDD hf = (*is_fairness)[k]->get_bdd_representation(); // The BDD for the fairness constraint
      vector< BDD* >* qh = (*Qh)[k];
      if(!qh->empty()) {
        for(unsigned int j=0; j<qh->size(); j++) {
          BDD* t = qh->back();
          qh->pop_back();
          delete t;
        }
      }
      BDD tmp1 = check_EU_Qh(p, q * hf, para, qh);
      fc_bdd = fc_bdd * check_EX(tmp1, para);
      //x++;
    }
    q = p * fc_bdd;
  }
  return q;
}

BDD
check_EF_fair(BDD p, BDD fair_reach, bdd_parameters * para)
{
  return check_EU_fair(*para->reach, p, fair_reach, para);
}

BDD
check_EX_fair(BDD p, BDD fair_reach, bdd_parameters * para)
{
  return check_EX(p * fair_reach, para);
}

BDD
check_EU_fair(BDD p, BDD q, BDD fair_reach, bdd_parameters * para)
{
  return check_EU(p * fair_reach, q * fair_reach, para);
}

BDD
check_nO_fair(BDD next, string name, BDD fair_reach, bdd_parameters * para)
{
  // Check deontic
  next = next.SwapVariables(*para->v, *para->pv);       // Now it's the next state
  BDD RO = (*is_agents)[name]->encode_greenstates(para);
  BDD result = Exists(para->bddmgr, para->pv, RO * next * fair_reach);  // States from which...
  return result;
}

BDD
check_GK_fair(BDD next, string name, BDD fair_reach, bdd_parameters * para)
{
  set < string > gi = (*is_groups)[name];
  BDD tmp = para->bddmgr->bddZero();
  BDD ntmp = fair_reach - next;
  for (set < string >::iterator igs = gi.begin(); igs != gi.end(); igs++) {
    basic_agent *agent = (*is_agents)[*igs];
    tmp += agent->project_local_state(&ntmp, para->bddmgr, para->v);
  }
  tmp = (*para->reach) - tmp;
  return tmp;
}

BDD
check_DK_fair(BDD next, string name, BDD fair_reach, bdd_parameters * para)
{
  set < string > gi = (*is_groups)[name];
  BDD tmp = para->bddmgr->bddOne();
  BDD ntmp = fair_reach - next;
  for (set < string >::iterator igs = gi.begin(); igs != gi.end(); igs++) {
    basic_agent *agent = (*is_agents)[*igs];
    tmp *= agent->project_local_state(&ntmp, para->bddmgr, para->v);
  }
  tmp = (*para->reach) - tmp;
  return tmp;
}

BDD
check_GCK_fair(BDD next, string name, BDD fair_reach,
               bdd_parameters * para)
{
  // GCK p = GK(p * GCK(p)) see fhmv:rak, section 11.5
  BDD tmp = *para->reach;
  BDD tmp2 = next;
  set < string > gi = (*is_groups)[name];
  while (tmp != tmp2) {
    tmp2 = tmp;
    tmp = next * tmp;
    BDD ntmp = fair_reach - tmp;
    tmp = para->bddmgr->bddZero();
    for (set < string >::iterator igs = gi.begin(); igs != gi.end(); igs++) {
      basic_agent *agent = (*is_agents)[*igs];
      tmp += agent->project_local_state(&ntmp, para->bddmgr, para->v);
    }
    tmp = (*para->reach) - tmp;
  }
  return tmp;
}

BDD
get_K_states(BDD aset1, BDD * state, string name, bdd_parameters * para)
{
  basic_agent *agent = (*is_agents)[name];
  BDD localstate = agent->project_local_state(state, para->bddmgr, para->v);
  return aset1 * localstate;
}

BDD
get_nK_states(BDD * state, string name, bdd_parameters * para)
{
  basic_agent *agent = (*is_agents)[name];
  
  BDD localstate = agent->project_local_state(state, para->bddmgr, para->v);
  return all_reach * localstate;
}

BDD
SCGS_get_nK_states(BDD * state, string name, bdd_parameters * para)
{
  basic_agent *agent = (*is_agents)[name];
  BDD localstate;
  if(agent->get_strategy_type()=="isr" || agent->get_strategy_type()=="ior")
    localstate = agent->project_local_state(state, para->bddmgr, para->v);
  else
  	localstate=*state;
  return all_reach * localstate;
}

BDD
get_nK_states_fair(BDD * state, string name, BDD fair_reach,
                   bdd_parameters * para)
{
  basic_agent *agent = (*is_agents)[name];
  BDD localstate = agent->project_local_state(state, para->bddmgr, para->v);
  return fair_reach * localstate;
}

BDD
get_GK_states(BDD aset1, BDD * state, string name, bdd_parameters * para)
{
  BDD tmpaset1 = para->bddmgr->bddZero();
  set < string > names_g = (*is_groups)[name];
  for (set < string >::iterator igs = names_g.begin(); igs != names_g.end();
       igs++) {
    basic_agent *agent = (*is_agents)[*igs];
    BDD localstate = agent->project_local_state(state, para->bddmgr, para->v);
    tmpaset1 = tmpaset1 + (aset1 * localstate);
  }
  return tmpaset1;
}

BDD
get_DK_states(BDD aset1, BDD * state, string name, bdd_parameters * para)
{
  BDD tmpaset1 = aset1;
  set < string > names_g = (*is_groups)[name];
  for (set < string >::iterator igs = names_g.begin(); igs != names_g.end();
       igs++) {
    basic_agent *agent = (*is_agents)[*igs];
    BDD localstate = agent->project_local_state(state, para->bddmgr, para->v);
    tmpaset1 = tmpaset1 * localstate;
  }
  return tmpaset1;
}

DdNode *
addApplyLT(DdManager * mgr, DdNode ** n1, DdNode ** n2)
{
  DdNode *F, *G;
  F = *n1;
  G = *n2;
  if (F->index == CUDD_CONST_INDEX && G->index == CUDD_CONST_INDEX) {
    if (F->type.value < G->type.value)
      return mgr->one;

    else
      return mgr->zero;
  }
  return (NULL);
}

ADD
addLT(Cudd * bddmgr, ADD a1, ADD a2)
{
  DdNode *n1 = a1.getNode();
  DdNode *n2 = a2.getNode();
  DdNode *result = Cudd_addApply(bddmgr->getManager(), &addApplyLT, n1, n2);
  ADD res(*bddmgr, result);
  return res;
}

DdNode *
addApplyGT(DdManager * mgr, DdNode ** n1, DdNode ** n2)
{
  DdNode *F, *G;
  F = *n1;
  G = *n2;
  if (F->index == CUDD_CONST_INDEX && G->index == CUDD_CONST_INDEX) {
    if (F->type.value > G->type.value)
      return mgr->one;

    else
      return mgr->zero;
  }
  return (NULL);
}

ADD
addGT(Cudd * bddmgr, ADD a1, ADD a2)
{
  DdNode *n1 = a1.getNode();
  DdNode *n2 = a2.getNode();
  DdNode *result = Cudd_addApply(bddmgr->getManager(), &addApplyGT, n1, n2);
  ADD res(*bddmgr, result);
  return res;
}

DdNode *
addApplyEQ(DdManager * mgr, DdNode ** n1, DdNode ** n2)
{
  DdNode *F, *G;
  F = *n1;
  G = *n2;
  if (F->index == CUDD_CONST_INDEX && G->index == CUDD_CONST_INDEX) {
    if (F->type.value == G->type.value)
      return mgr->one;

    else
      return mgr->zero;
  }
  return (NULL);
}

ADD
addEQ(Cudd * bddmgr, ADD a1, ADD a2)
{
  DdNode *n1 = a1.getNode();
  DdNode *n2 = a2.getNode();
  DdNode *result = Cudd_addApply(bddmgr->getManager(), &addApplyEQ, n1, n2);
  ADD res(*bddmgr, result);
  return res;
}

DdNode *
addApplyGE(DdManager * mgr, DdNode ** n1, DdNode ** n2)
{
  DdNode *F, *G;
  F = *n1;
  G = *n2;
  if (F->index == CUDD_CONST_INDEX && G->index == CUDD_CONST_INDEX) {
    if (F->type.value >= G->type.value)
      return mgr->one;

    else
      return mgr->zero;
  }
  return (NULL);
}

ADD
addGE(Cudd * bddmgr, ADD a1, ADD a2)
{
  DdNode *n1 = a1.getNode();
  DdNode *n2 = a2.getNode();
  DdNode *result = Cudd_addApply(bddmgr->getManager(), &addApplyGE, n1, n2);
  ADD res(*bddmgr, result);
  return res;
}

DdNode *
addApplyLE(DdManager * mgr, DdNode ** n1, DdNode ** n2)
{
  DdNode *F, *G;
  F = *n1;
  G = *n2;
  if (F->index == CUDD_CONST_INDEX && G->index == CUDD_CONST_INDEX) {
    if (F->type.value <= G->type.value)
      return mgr->one;

    else
      return mgr->zero;
  }
  return (NULL);
}

ADD
addLE(Cudd * bddmgr, ADD a1, ADD a2)
{
  DdNode *n1 = a1.getNode();
  DdNode *n2 = a2.getNode();
  DdNode *result = Cudd_addApply(bddmgr->getManager(), &addApplyLE, n1, n2);
  ADD res(*bddmgr, result);
  return res;
}

DdNode *
addApplyNEQ(DdManager * mgr, DdNode ** n1, DdNode ** n2)
{
  DdNode *F, *G;
  F = *n1;
  G = *n2;
  if (F->index == CUDD_CONST_INDEX && G->index == CUDD_CONST_INDEX) {
    if (F->type.value != G->type.value)
      return mgr->one;

    else
      return mgr->zero;
  }
  return (NULL);
}

ADD
addNEQ(Cudd * bddmgr, ADD a1, ADD a2)
{
  DdNode *n1 = a1.getNode();
  DdNode *n2 = a2.getNode();
  DdNode *result = Cudd_addApply(bddmgr->getManager(), &addApplyNEQ, n1, n2);
  ADD res(*bddmgr, result);
  return res;
}

int
search_string_table(string * s)
{
  for (unsigned int i = 0; i < string_table->size(); i++)
    if (s->compare(*(*string_table)[i]) == 0)
      return i;
  return -1;
}

int
search_variable_table(variable * v)
{
  for (unsigned int i = 0; i < variable_table->size(); i++)
    if (v->equal_to((*variable_table)[i]))
      return i;
  return -1;
}

int
search_logic_expression_table(bool_expression * le)
{
  for (unsigned int i = 0; i < logic_expression_table->size(); i++)
    if (le->equal_to((*logic_expression_table)[i]))
      return i;
  return -1;
}
int
search_logic_expression_table(expression * e1, expression * e2)
{
  for (unsigned int i = 0; i < logic_expression_table->size(); i++)
    if (((*logic_expression_table)[i])->equal_to(e1, e2))
      return i;
  return -1;
}

int
search_logic_expression_table1(bool_expression * le)
{
  for (unsigned int i = 0; i < logic_expression_table1->size(); i++)
    if (le->equal_to((*logic_expression_table1)[i]))
      return i;
  return -1;
}
int
search_logic_expression_table1(expression * e1, expression * e2)
{
  for (unsigned int i = 0; i < logic_expression_table1->size(); i++)
    if (((*logic_expression_table1)[i])->equal_to(e1, e2))
      return i;
  return -1;
}


//vector<BDD*>*
//get_equiv_state(bdd_parameters * para, BDD* s, string grpname){	
//  vector<BDD*> * equiv_states = new vector<BDD*>;
//  if (grpname=="none"||grpname=="Empty"){
//	return equiv_states;
//  }
//  map < string, set < string > >::iterator gi = is_groups->find(grpname);
//  set < string > names_g = gi->second;  // the list of agt names in groups
//   
//  for (map < string, basic_agent * >::iterator i = is_agents->begin(); i != is_agents->end(); i++) {
//  	unsigned int counter =0 ;
//  	if (names_g.find(i->first) == names_g.end()) {
//	  continue;
//	}
//	else if(i->second->get_strategy_type()!="isr"){
//      continue;
//	}
//	else {
//	  vector<BDD>* vec_state = para->vec_reach;	 
//	  for(unsigned int j = 0; j<para->vec_reach->size();j++){	  	
//        BDD b = (*para->vec_reach)[j];
//		if(b!=(*s)){
//		  basic_agent * a = i->second;
//		  string st_j = a->seeable_state_to_str(b,*para->v);
//		  string st_s = a->seeable_state_to_str(*s,*para->v);
//		  if (st_j==st_s) {
//			equiv_states->push_back(&((*para->vec_reach)[j]));
//			cout<<"this equiv_state is: "<<state_to_str(b, *para->v);
//		  }
//		}
//	  }
//	}
//  }
//  cout<<"equiv_states size is: "<<equiv_states->size()<<endl;
//  return equiv_states;
//}

//compare to SCGS_check_GK_2, *s must be a valid state
vector<BDD*>*
get_equiv_state(bdd_parameters * para, BDD* s, string grpname){	
  vector<BDD*> * equiv_states = new vector<BDD*>;
  if (grpname=="none"||grpname=="Empty"){
	return equiv_states;
  }
  map < string, set < string > >::iterator gi = is_groups->find(grpname);
  set < string > names_g = gi->second;  // the list of agt names in groups
  BDD tmp = para->bddmgr->bddZero();	
  BDD next = *s;
  for (map < string, basic_agent * >::iterator i = is_agents->begin(); i != is_agents->end(); i++) {
  	unsigned int counter =0 ;
  	if (names_g.find(i->first) == names_g.end()) {
	  continue;
	}
	else if(i->second->get_strategy_type()!="isr"){
      continue;
	}
	else {
	  basic_agent* agent = i->second;	  
 	  tmp += (agent->project_local_state(&next, para->bddmgr, para->v) * all_reach);
	}		  
  }

  BDD local_state = tmp;
  map<string, map<string, vector<BDD*>* >* >* int_vars = integer_variable_BDDs(para->bddmgr, para->v);	  
  while(local_state!=para->bddmgr->bddZero()){
	BDD curinitstate = local_state.PickOneMinterm(*para->v);
	curinitstate = complete_integer_BDDs(para->bddmgr, para->v, curinitstate, int_vars);	  
	local_state = local_state - curinitstate; 
	bool valid = is_valid_state(curinitstate, *para->v)&&(curinitstate!=(*s));	  
	if (valid){ 
  	  equiv_states->push_back(new BDD(curinitstate));
	} 
  }
  return equiv_states;
}

vector< model > * 
get_rin_Str(int reach_id, BDD* state, string grp, vector<basic_agent*> * agent_Ir_in, bdd_parameters * para, vector<bdd_parameters>* para_vec){
  vector<model>* models;
  string cex_prefix = int2string(reach_id);
  
  if (grp=="none"||grp=="Empty") {
	vector<vector<int>* > *countex = new vector<vector<int>* >;
    map<int, BDD*> *idbdd = new map< int, BDD * >;
    map<string, int>* bddid = new map< string, int>;
    vector<vector<transition* > >* cextr = new vector<vector<transition* > >;
    BDD* new_init = new BDD(*state);
	
	bdd_parameters* new_para = new bdd_parameters(*para);
	new_para->vec_reach = new vector<BDD>;
	new_para->num_of_inits = new int(0);
	new_para->original_reach = new BDD(para->bddmgr->bddZero());
    SCGS_export_model(new_para, new_init, countex, idbdd, cextr);  
	string fname = cex_prefix + "the unique model";  
	
	for (map<int,BDD*>::iterator it = idbdd->begin(); it!=idbdd->end(); it++) {
	  string statr = state_to_str(*it->second, *para->v);
		
	  pair<string,int> p(statr,it->first);	 
	  bddid->insert(p);
	}

	model mm;
	int model_id = 0;
	mm.cextr = cextr;
	mm.idbdd = idbdd;
	mm.is_temp = new BDD(*state);
	mm.bddid = bddid;
	mm.model_id = model_id;
	models = new vector<model>;
	models->push_back(mm);
	delete countex;
	delete new_init;
	delete new_para->vec_reach;
	delete new_para->num_of_inits;
	delete new_para->original_reach;
  }
  else{	
    map < string, set < string > >::iterator gi = is_groups->find(grp);
	set < string > names_g = gi->second;	
	int model_id = 0;
	vector<model>* model_vec = new vector<model>;	
	for (vector<bdd_parameters>::iterator i = para_vec->begin(); i!=para_vec->end(); i++) {
	  vector<vector<int>* >* countex = new vector<vector<int>* >;
	  map<int, BDD*>* idbdd = new map<int, BDD*>;
	  map<string, int>* bddid = new map<string, int>;
	  vector<vector<transition* > >* cextr = new vector<vector<transition* > >;
      BDD* new_init = new BDD(*state);
      
	  SCGS_export_model(new bdd_parameters(*i), new_init, countex, idbdd, cextr); 

	  for (map<int,BDD*>::iterator it = idbdd->begin(); it!=idbdd->end(); it++) {
	    string statr = state_to_str(*it->second, *(*i).v);
		pair<string,int> p(statr,it->first);	  
		bddid->insert(p);
	  }
	
	  model mm;
	  mm.cextr = cextr;
	  mm.idbdd = idbdd;
	  mm.is_temp = new BDD(*state);
	  mm.bddid = bddid;
	  mm.model_id = model_id;
	  model_vec->push_back(mm);
	  model_id = model_id + 1;
	  delete countex;
	  delete new_init;
	}
	
	bool atl_print = (options["ATLprint"] == 1); 
    if(agent_Ir_in->size()==0){
	  fill_models(model_vec, para);
	  if(atl_print){
		//export the model into .doc
		for(unsigned int i=0;i<model_vec->size(); i++){
		  string fname = cex_prefix + "model" + int2string(i);
		  SCGS_print_cex(para, fname, "statespace", (*model_vec)[i].idbdd, (*model_vec)[i].cextr);
		}
	  }
	  return model_vec;
	}
	
	models = model_split_Ir(model_vec,agent_Ir_in,para);	
	fill_models(models,para);
	if(atl_print){
	  //export the model into .doc
	  for(unsigned int i=0;i<models->size(); i++){
		string fname = cex_prefix + "model" + int2string(i);
		SCGS_print_cex(para, fname, "statespace", (*models)[i].idbdd, (*models)[i].cextr);
	  }
	}
  }
  return models;
}

void
fill_models(vector<model>* model_vec, bdd_parameters* para){
  int model_id=0;
  for(unsigned int i=0;i<model_vec->size();i++){  	
    int cextr_order=0;
	model this_model = (*model_vec)[i];
	vector<vector<transition*> >* this_cextr = this_model.cextr;
	for(vector<vector<transition*> >::iterator it =this_cextr->begin();it<this_cextr->end();it++){
	  transition* tr = (*it).at(0);
	  BDD* from_bdd = tr->getfrom();
	  string from_string = state_to_str(*from_bdd , *para->v); 
	  int my_from_id = (*this_model.bddid)[from_string];
	  
	  if(cextr_order==my_from_id){
	  	cextr_order=cextr_order+1;
	  }
	  else{
	  	vector<transition*> vec_non;
	  	it = this_cextr->insert(this_cextr->begin()+cextr_order, vec_non);
		cextr_order=cextr_order+1;   
	  }
	} 
  }
}

bool 
cextr_find_equiv(model m, BDD* state, bdd_parameters* para){
  vector<vector<transition*> >* this_cextr = m.cextr;
  for(vector<vector<transition*> >::iterator i=this_cextr->begin(); i<this_cextr->end(); i++){
  	if((*i).size()==0){
	  continue;
	}
    transition* t = (*i).at(0);
	BDD* this_state = t->getfrom();
    string this_string = state_to_str(*this_state, *para->v);
	string that_string = state_to_str(*state, *para->v);
	if(this_string==that_string)
	  return true;
  }
  return false;
}

void
transform_uni(vector< vector< BDD* >* >* uniform_rin_prots, unsigned int k, bdd_parameters* para, vector<bdd_parameters>* para_vec){
  if(k < uniform_rin_prots->size()-1){
  	vector<BDD*>* uni_prot = (*uniform_rin_prots)[k];
	for(vector<BDD*>::iterator i = uni_prot->begin(); i != uni_prot->end();i++) {
      BDD tmpRT = (*para->vevol)[k]* (*(*i));
	  (para->vRT)->push_back(tmpRT);
	  transform_uni(uniform_rin_prots, k+1, para, para_vec);
	  para->vRT->pop_back();
	}
  }
  else {
    vector<BDD*>* uni_prot = (*uniform_rin_prots)[k];
	for(vector< BDD*>::iterator i = uni_prot->begin(); i != uni_prot->end();i++) {		
      BDD tmpRT = (*para->vevol)[k] * (*(*i));
	  (para->vRT)->push_back(tmpRT);
      bdd_parameters p = *para;
	  p.vec_reach = new vector<BDD>;
	  p.original_reach = new BDD(para->bddmgr->bddZero());
	  p.num_of_inits = new int(0);
	  p.vRT = new vector<BDD>(*para->vRT);
	  para_vec->push_back(p);
	  para->vRT->pop_back();		
	}
  }
}

BDD
transform_uni_for_atl_empty(vector< vector< BDD* >* >* uniform_r_prots, unsigned int k, bdd_parameters* para, vector<bdd_parameters>* para_vec, BDD result_before, modal_formula f){
  BDD result_after = result_before;
  if(k < uniform_r_prots->size()-1){
  	vector<BDD*>* uni_prot = (*uniform_r_prots)[k];
	for(vector<BDD*>::iterator i = uni_prot->begin(); i != uni_prot->end();i++) {
      BDD tmpRT = (*para->vevol)[k]* (*(*i));
	  (para->vRT)->push_back(tmpRT);
	  (para->vprot)->push_back(*(*i));
	  result_after = result_after *  transform_uni_for_atl_empty(uniform_r_prots, k+1, para, para_vec,result_before,f);
	  if(result_after == para->bddmgr->bddZero())
	  	return para->bddmgr->bddZero();
	 
	  para->vRT->pop_back();
	  para->vprot->pop_back();
	}
  }
  else {
    vector<BDD*>* uni_prot = (*uniform_r_prots)[k];
	unsigned int time = 0;
	for(vector< BDD*>::iterator i = uni_prot->begin(); i != uni_prot->end();i++) {		
      BDD tmpRT = (*para->vevol)[k] * (*(*i));
	  (para->vRT)->push_back(tmpRT);
	  (para->vprot)->push_back(*(*i));
	  unsigned int acounter1 = 1;
	  unsigned long threadmem = 0;
	  
	  bdd_parameters p = *para;
	  p.vRT = new vector<BDD>(*para->vRT);
	  p.in_st = new BDD(*para->in_st);
	  p.vprot = new vector<BDD>(*para->vprot);
	  p.vevol = new vector<BDD>(*para->vevol);
	  BDD reach = compute_reach(*p.in_st, p.v, p.pv, p.a, p.vRT, p.bddmgr, &acounter1, 1, &threadmem);
//	  p.reach = new BDD(*para->reach);
	  p.reach = new BDD(reach);
	  BDD cur_result = f.check_formula(&p);	  
	  result_after = result_after * cur_result;
	  
	  para->vprot->pop_back();
	  para->vRT->pop_back();
	  delete p.reach;
	  delete p.in_st;
	  delete p.vRT;
	  delete p.vprot;
	  delete p.vevol;
	  if(result_after == para->bddmgr->bddZero())
	  	break;
	}
  }  
  return result_after;
}

void
transform_uni_for_atl_grp_in(map<unsigned int, vector< BDD* >* >* uniform_rin_prots, vector<unsigned int>* index_vec_in, unsigned int k, bdd_parameters* para, vector<bdd_parameters>* para_vec){
  unsigned int index = (*index_vec_in)[k];
  if(k < uniform_rin_prots->size()-1){
  	vector<BDD*>* uni_prot = (*uniform_rin_prots)[index];
	for(vector<BDD*>::iterator i = uni_prot->begin(); i != uni_prot->end();i++) {
      BDD tmpRT = (*para->vevol)[index]* (*(*i));
	  (para->vRT)->push_back(tmpRT);
	  (para->vprot)->push_back(*(*i));
	  transform_uni_for_atl_grp_in(uniform_rin_prots, index_vec_in,k+1, para, para_vec);
	  para->vRT->pop_back();
	  para->vprot->pop_back();
	}
  }
  else {
    vector<BDD*>* uni_prot = (*uniform_rin_prots)[index];
	for(vector<BDD*>::iterator i = uni_prot->begin(); i != uni_prot->end();i++) {	
      BDD tmpRT = (*para->vevol)[index] * (*(*i));	  
	  (para->vRT)->push_back(tmpRT);
	  (para->vprot)->push_back(*(*i));
      bdd_parameters p = *para;
	  p.vRT = new vector<BDD>(*para->vRT);
	  p.vprot = new vector<BDD>(*para->vprot);
//	  p.in_st = new BDD(*para->in_st);
	  p.vevol = new vector<BDD>(*para->vevol);
	  para_vec->push_back(p);
	  para->vRT->pop_back();
	  para->vprot->pop_back();
	}
  }
}

void
transform_uni_for_atl_grp_out(map<unsigned int, vector< BDD* >* >* uniform_rout_prots, vector<unsigned int>* index_vec_out, unsigned int k, bdd_parameters* para, vector<bdd_parameters>* para_vec){
  unsigned int index = (*index_vec_out)[k];
  if(k < uniform_rout_prots->size()-1){
  	vector<BDD*>* uni_prot = (*uniform_rout_prots)[index];
	for(vector<BDD*>::iterator i = uni_prot->begin(); i != uni_prot->end();i++) {
      BDD tmpRT = (*para->vevol)[index]* (*(*i));
	  (para->vRT)->push_back(tmpRT);
	  (para->vprot)->push_back(*(*i));
	  transform_uni_for_atl_grp_out(uniform_rout_prots,index_vec_out, k+1, para, para_vec);
	  para->vRT->pop_back();
	  para->vprot->pop_back();
	}
  }
  else {
    vector<BDD*>* uni_prot = (*uniform_rout_prots)[index];
	for(vector< BDD*>::iterator i = uni_prot->begin(); i != uni_prot->end();i++) {		
      BDD tmpRT = (*para->vevol)[index] * (*(*i));
	  (para->vRT)->push_back(tmpRT);
	  (para->vprot)->push_back(*(*i));
      bdd_parameters p = *para;
	  p.vRT = new vector<BDD>(*para->vRT);
	  p.vprot = new vector<BDD>(*para->vprot);
	  para_vec->push_back(p);
	  para->vRT->pop_back();
	  para->vprot->pop_back();
	}
  }
}

BDD 
lemma2_calculate(bdd_parameters* para, bdd_parameters* para_in, vector<bdd_parameters>* para_vec_out, modal_formula f, string grp){
//  cout<<"this is lemma2_Calculatae test"<<endl;

  BDD bddzero = para_in->bddmgr->bddZero();
  
  BDD one_result = bddzero;
  if(para_vec_out->size()==0){
	unsigned int acounter1 = 1;
	unsigned long threadmem = 0;
    
    for(unsigned int k=0;k<all_reach_vec->size();k++){
	  BDD in_st=(*all_reach_vec)[k];	  
	  bdd_parameters para_in_one = *para_in;
	  para_in_one.vprot = new vector<BDD>(*para_in->vprot); 
	  para_in_one.vRT = new vector<BDD>(*para_in->vRT); 
	  
	  BDD reach = compute_reach(in_st, para_in_one.v, para_in_one.pv, para_in_one.a,para_in_one.vRT, para_in_one.bddmgr, &acounter1, 1, &threadmem);
	  
	  para_in_one.reach = new BDD(reach);
	  BDD cur_result = f.check_formula(&para_in_one);

	  delete para_in_one.reach;
	  delete para_in_one.vprot;
	  delete para_in_one.vRT;
	  if(cur_result*in_st ==in_st){
        one_result+=in_st;
	  }
	}	
	return one_result;
  } 
  
  for(unsigned int k=0;k<all_reach_vec->size();k++){
	BDD in_st=(*all_reach_vec)[k];
    bool if_add = true;

    for(unsigned int i = 0; i<para_vec_out->size(); i++){ 
      bdd_parameters para_out =(*para_vec_out)[i];  
	  vector<BDD>* prot_in = new vector<BDD>(*para_in->vprot);	
      vector<BDD>* vRT_in = new vector<BDD>(*para_in->vRT);	
	  para_out.vprot = new vector<BDD>(*(*para_vec_out)[i].vprot); 
	  para_out.vRT = new vector<BDD>(*(*para_vec_out)[i].vRT); 
      para_out.vprot->insert(para_out.vprot->end(),prot_in->begin(),prot_in->end());
	  para_out.vRT->insert(para_out.vRT->end(),vRT_in->begin(),vRT_in->end());	
	
	  unsigned int acounter1 = 1;
	  unsigned long threadmem = 0;

	  BDD reach = compute_reach(in_st, para_out.v, para_out.pv, para_out.a, para_out.vRT, para_out.bddmgr, &acounter1, 1, &threadmem);
	  para_out.reach = new BDD(reach);
	  BDD cur_result = f.check_formula(&para_out)*reach;

	  delete para_out.reach;
	  delete para_out.vprot;
	  delete para_out.vRT;
	  delete prot_in;
	  delete vRT_in;


	  if(cur_result*in_st == in_st){
		continue;
	  } else{
		if_add = false;
		break;
	  }
	}
	
	if(if_add){
	  one_result+=in_st;
	}
  }
  return one_result;
}


void
global_print_state(BDD local_state, bdd_parameters* para){
  map<string, map<string, vector<BDD*>* >* >* int_vars = integer_variable_BDDs(para->bddmgr, para->v);
  unsigned int counter=0;
  while(local_state!=para->bddmgr->bddZero()){
	BDD curinitstate = local_state.PickOneMinterm(*para->v);
	curinitstate = complete_integer_BDDs(para->bddmgr, para->v, curinitstate, int_vars);	  
	local_state = local_state - curinitstate; 
	bool valid = is_valid_state(curinitstate, *para->v);	
	
	if (valid){ 
	  cout<<"this equiv_states is: "<<state_to_str(curinitstate,*para->v);	  
	  counter++;
	} 
  }
  cout<<"the counter is: "<<counter<<endl;
}

vector<model>* 
model_split_Ir(vector<model>* model_vec,vector<basic_agent* >* agent_Ir_in,bdd_parameters * para){
  vector<model>* models = new vector<model>;
  int model_id = 0;
  for(unsigned int i =0;i<model_vec->size();i++){
    model current_model = (*model_vec)[i];
	map<string, int>* current_bddid = current_model.bddid;
    vector<vector<transition*> >* current_cextr = current_model.cextr;
	map<int,BDD*>* current_idbdd = current_model.idbdd;	
	BDD* is_temp = current_model.is_temp;
	vector<STnode>* leaf = buildTree(current_cextr,agent_Ir_in,para);
	vector<model>* vm = get_model_from_tree(leaf,current_bddid,current_idbdd,is_temp); 
    for(unsigned int j=0;j<vm->size();j++){
	  model this_model = (*vm)[j];
	  this_model.model_id=model_id;
	  models->push_back(this_model);
	  model_id=model_id+1;
	}
  }
  return models;
}

vector<STnode>*
buildTree(vector<vector<transition*> >* cextr, vector<basic_agent*>* agent_Ir_in, bdd_parameters* para){
  vector<STnode>* leaf_vec = new vector<STnode>;
  vector<map<string,vector<transition* > >* >* all_map_vector = new vector<map<string,vector<transition *> >* >;
  for (int ac = 0; ac < (int) cextr->size(); ++ac) {
	map<string, vector<transition* > >* one_map_vector = new map<string, vector<transition*> >;
	for (int j = 0; j < (int) cextr->at(ac).size(); ++j) {
	  transition* cur_trans = cextr->at(ac).at(j);
	  BDD* lab = cur_trans->getlabel();
	  string s="";
	  for (unsigned int i = 0; i < agent_Ir_in->size(); ++i) {
	    s += (*agent_Ir_in)[i]->action_to_str(*lab, *para->a) + ";";
	  }
	  if (one_map_vector->find(s)!=one_map_vector->end()) {
	    (*one_map_vector)[s].push_back(cur_trans);
	  }
	  else{
        vector<transition*> trans_vec;
		trans_vec.push_back(cur_trans);
	    pair<string, vector<transition*> > p(s, trans_vec);
		one_map_vector->insert(p);
	  }
	}
	all_map_vector->push_back(one_map_vector);
  }
  
  unsigned int icount = 0;
  queue<STnode> q1;
  STnode root;

  root.id = icount;
  vector<unsigned int>* root_cur_set = new vector<unsigned int>;
  root_cur_set->push_back(0);
  root.current_set = root_cur_set;
  root.current_str = NULL;
  root.processed_states = new set<unsigned int>;  

  icount = icount + 1;
  q1.push(root);
  
  while (!q1.empty()) {
	STnode node_father = q1.front();
	
	if (node_father.current_set->size()==0) {
	  q1.pop(); 
	}
	else{
		
	  vector<unsigned int>* f_cur_set = node_father.current_set;
	  vector<string>* one_sub_label = new vector<string>;
	  vector<vector<string>*>* all_sub_labels = new vector<vector<string>*>;
      generate_sub_label(f_cur_set, all_map_vector, one_sub_label, 0, all_sub_labels);
	  
	  for (unsigned int i = 0; i< all_sub_labels->size(); i++) {
	    vector<string>* v = (*all_sub_labels)[i]; 
	    STnode one_son;
	    one_son.id = icount;
		icount = icount + 1;
		map<unsigned int, vector<transition*> >* son_cur_str;
		if((node_father.current_str)==NULL)
		  son_cur_str = new map<unsigned int, vector<transition*> >;
		else{
		  son_cur_str = new map<unsigned int, vector<transition*> >;
		  for(map<unsigned int, vector<transition*> >::iterator iter = node_father.current_str->begin(); iter != node_father.current_str->end(); iter++){
			(*son_cur_str)[iter->first] = iter->second;
		  }
		}  
	
		vector<unsigned int>* s_cur_set = new vector<unsigned int>;
		for (unsigned int j = 0; j < f_cur_set->size(); j++) {   
		  unsigned int st_id = (*f_cur_set)[j];
		  vector<transition*> vec_tr = (*(*all_map_vector)[st_id])[(*v)[j]];
		  (*son_cur_str)[st_id] = vec_tr;		  
		  for (unsigned int m = 0; m<vec_tr.size(); m++) {
		  	transition* tr = vec_tr[m];
			unsigned int to_id = tr->gettoid();
			bool f_p=node_father.processed_states->find(to_id)==node_father.processed_states->end();
			vector<unsigned int>::iterator it = find(node_father.current_set->begin(), node_father.current_set->end(), to_id);
			bool f_c = it == node_father.current_set->end();
			if( f_p && f_c){
              s_cur_set->push_back(to_id);
			}
		  }
		}
		one_son.current_str = son_cur_str;
		
		
		if(s_cur_set->size()!=0){
		  sort(s_cur_set->begin(),s_cur_set->end());
		  s_cur_set->erase(unique(s_cur_set->begin(),s_cur_set->end()),s_cur_set->end());
		  one_son.current_set = s_cur_set;
		  
		  set<unsigned int>* s_cur_pro = new set<unsigned int>(*(node_father.processed_states));
		  copy(node_father.current_set->begin(), node_father.current_set->end(),inserter(*s_cur_pro, s_cur_pro->end()));
		  one_son.processed_states = s_cur_pro;
	      
		}
		else{	  
		  one_son.current_set = s_cur_set;	
		  set<unsigned int>* s_cur_pro = new set<unsigned int>(*node_father.processed_states);
		  copy(node_father.current_set->begin(), node_father.current_set->end(),inserter(*s_cur_pro, s_cur_pro->end()));
		  one_son.processed_states = s_cur_pro;
		  leaf_vec->push_back(one_son);
		}		
		q1.push(one_son);
	  }
	  
      q1.pop();	
	  for(unsigned int i=0; i<all_sub_labels->size(); i++){
        delete (*all_sub_labels)[i];
	  }
	  all_sub_labels->clear();
	  delete all_sub_labels;
	  delete one_sub_label;
	}
	
	delete node_father.current_set;
    delete node_father.processed_states;
  }
  return leaf_vec;
}

void
generate_sub_label(vector<unsigned int>* f_cur_set, vector<map<string,vector<transition*> >* >* all_map_vector, 
vector<string>* one_sub_label, unsigned int k, vector<vector<string>*>* all_sub_labels){
  if(k<f_cur_set->size()-1){
    unsigned int one_son_id = (*f_cur_set)[k];
	map<string, vector<transition*> >* cur_map = (*all_map_vector)[one_son_id];
    for (map<string, vector<transition*> >::iterator i = cur_map->begin(); i!=cur_map->end(); i++){	
	  one_sub_label->push_back(i->first);
	  generate_sub_label(f_cur_set, all_map_vector, one_sub_label, k+1, all_sub_labels);
	  one_sub_label->pop_back();
	}
  }
  else{
    unsigned int one_son_id = (*f_cur_set)[k];	
	map<string, vector<transition*> >* cur_map = (*all_map_vector)[one_son_id];	
	for (map<string, vector<transition*> >::iterator i = cur_map->begin(); i!=cur_map->end(); i++){
	  one_sub_label->push_back(i->first);
	  vector<string>* sub_label = new vector<string>;
      sub_label->assign(one_sub_label->begin(),one_sub_label->end());
	  all_sub_labels->push_back(sub_label);
	  one_sub_label->pop_back();
	}
  }
}


vector<model>*
get_model_from_tree(vector<STnode>* leaf_vec, map<string, int>* bddid, map<int, BDD*>* idbdd, BDD* is_temp){
  vector<model>* mv = new vector<model>;
  int model_id = 0;
  for (vector<STnode>::iterator i = leaf_vec->begin(); i < leaf_vec->end(); i++) {
    model m;
	m.cextr=new vector<vector<transition*> >;
	for( map<unsigned int, vector<transition*> >::iterator it = (*i).current_str->begin(); it != (*i).current_str->end(); it++ ) {
        vector<transition*> vec_tr;
		for(vector<transition*>::iterator iter = it->second.begin(); iter != it->second.end(); iter++ ){
			vec_tr.push_back(*iter);
		}
		m.cextr->push_back(vec_tr);
    }
	m.bddid = new map<string, int>(*bddid);
	m.idbdd = new map<int, BDD*>(*idbdd);
	m.is_temp = new BDD(*is_temp);
	m.model_id = model_id;
	model_id = model_id + 1;
	mv->push_back(m);
  }
  return mv;
}

map<string, vector <transition*> > * 
split_by_Rin(pg_V3 * v2, string grp, bool agent_in_has_IR, bdd_parameters* para){
  vector<transition*> trs_vec = (*v2->f_r.cextr)[(unsigned int)(v2->ibdd)];  
  map<string, vector <transition*> > * map_R_in = new map<string, vector <transition*> >;   
  if ((grp=="none"||grp=="Empty" )|| (!agent_in_has_IR)){
	pair <string, vector <transition*> > p ("none", trs_vec);
	map_R_in->insert(p);
  }
  else{
  	map < string, set < string > >::iterator gi = is_groups->find(grp);
    set < string > names_g = gi->second;	
    for (vector<transition*>::iterator iter=trs_vec.begin(); iter!=trs_vec.end(); iter++) {
	  BDD * label = (*iter)->getlabel();
	  string s="";	
      for (vector<basic_agent*>::iterator i = agents->begin();i!=agents->end();i++) {
	    if (names_g.find((*i)->get_name()) == names_g.end())
	  	  continue;
	    else if((*i)->get_strategy_type()!="IR")
	  	  continue;
	    else 
      	  s += (*i)->action_to_str(*label, *para->a);
      }
	  
      if (map_R_in!=NULL && map_R_in->find(s)!=map_R_in->end())	  
	    (*map_R_in)[s].push_back(*iter);
      else {
	    vector <transition*> trs_vec;
	    trs_vec.push_back(*iter);
        pair <string, vector <transition*> > p (s,trs_vec);
	    map_R_in->insert(p);
  	  }
	}
  }	
  return map_R_in;
}


map<string, map<unsigned int, string>*>* 
check_compatible(unsigned int my_from_id, pg_V3* v3, bdd_parameters* para, map<string, map<unsigned int, string>*>* g, transition* temp, vector<basic_agent*>* agents_Ir_out, vector<basic_agent*>* agents_ir_out){
  bool result_ck = true;
  map<string, map<unsigned int, string>*>* g_prim = new map<string, map<unsigned int, string>*>; 
  map<string, map<unsigned int, string>*>* g_prim1 = new map<string, map<unsigned int, string>*>; 
  for (vector<basic_agent*>::iterator i = agents_Ir_out->begin();i!=agents_Ir_out->end();i++) {
	string s_action=(*i)->action_to_str(*temp->getlabel(), *para->a); 
	string s_name = (*i)->get_name();
	map<unsigned int,string>* agt_prot;
	if(g->find(s_name)!=g->end())
      agt_prot = new map<unsigned int, string>(*(*g)[s_name]);
	else
	  agt_prot = new map<unsigned int, string>;
	if(agt_prot->find(my_from_id)!=agt_prot->end()){
	  result_ck = ((*agt_prot)[my_from_id]==s_action);
	  if(!result_ck){
		delete agt_prot;
		delete g_prim;
	  	return g_prim1;
	  }
	  else{
		(*g_prim)[s_name] = agt_prot;
	  }
	}
	else{
	  (*agt_prot)[my_from_id]=s_action;
	  (*g_prim)[s_name] = agt_prot;
	}	
  }

  for (vector<basic_agent*>::iterator i = agents_ir_out->begin();i!=agents_ir_out->end();i++) {
	string s_action=(*i)->action_to_str(*temp->getlabel(), *para->a); 
	string s_name = (*i)->get_name();
	map<unsigned int,string>* agt_prot;
  
    if(g->find(s_name)!=g->end())
	  agt_prot = new map<unsigned int, string>(*(*g)[s_name]);
	else
	  agt_prot = new map<unsigned int, string>;	
	
	bool exsit_str = false;
    for(map<unsigned int, string>::iterator iter = agt_prot->begin(); iter!=agt_prot->end(); iter++){
	  BDD* equi_state = (*v3->f_r.idbdd)[iter->first];
	  BDD* cur_state = v3->s_state;
	  string st_equi = (*i)->seeable_state_to_str(*equi_state, *(para->v));
	  string st_cur = (*i)->seeable_state_to_str(*cur_state, *(para->v));
	  if(st_equi==st_cur){
		exsit_str=true;
		result_ck = (iter->second == s_action);
	    if(!result_ck){
		  delete agt_prot;
		  delete g_prim;
		  return g_prim1;
		}
	  }
	}
	if(exsit_str){
	  (*g_prim)[s_name] = agt_prot;
	}
	else{
	  for(map<int,BDD*>::iterator i2 = v3->f_r.idbdd->begin(); i2!=v3->f_r.idbdd->end(); i2++){
	  	string st_equi = (*i)->seeable_state_to_str(*i2->second, *para->v);
		string st_v3 = (*i)->seeable_state_to_str(*v3->s_state, *para->v);
		if(st_equi==st_v3)
		  (*agt_prot)[i2->first]=s_action;
	  }
	  (*g_prim)[s_name] = agt_prot;
	}
  }
  
  return g_prim;
}


BDD
get_dpt_trans_label(const char * label, bdd_parameters* para){
  const char * t = "true";
  if (label==t) {
	return para->bddmgr->bddOne();
  }
  else{
	BDD new_label = para->bddmgr->bddOne();
	string s = label;
	istringstream iss(s);
	vector<string>* s_vec = new vector<string>;
	do {
	  string subs;
	  iss >> subs;
	  s_vec->push_back(subs);
	} while (iss);

	  
	for(vector<string>::iterator it = s_vec->begin(); it<s_vec->end()-1; it++){
	  if (it->at(0)=='~'){
	  	it->erase (it->begin());
		if (is_evaluation->find(*it)!=is_evaluation->end()){
		  bool_expression *simple = (*is_evaluation)[*it];
	      BDD r = simple->encode_bdd_flat(para, para->bddmgr->bddOne()) * all_reach;
		  new_label = (!r) * new_label;
		}
		else if(is_new_evaluation->find(*it)!=is_new_evaluation->end()){
		  new_label = (!((*is_new_evaluation)[*it])) * new_label;
		}
		else{
		  cout << "There are no such evaluation!!!" << endl;
		  free_mcmas_memory(NULL);
		  exit(-1);
		}
	  }
	  else{
		if (is_evaluation->find(*it)!=is_evaluation->end()){
		  bool_expression *simple = (*is_evaluation)[*it];
		  BDD r = simple->encode_bdd_flat(para, para->bddmgr->bddOne()) * all_reach;
		  new_label = r * new_label;
		}
		else if(is_new_evaluation->find(*it)!=is_new_evaluation->end()){
		  new_label = ((*is_new_evaluation)[*it]) * new_label;
		}
		else{
		  cout << "There are no such evaluation!!!" << endl;
		  free_mcmas_memory(NULL);
		  exit(-1);
		}
	  }
    }
	return new_label;
  }
}


vector<unsigned int>* 
get_next_p(pg_V3* v3, dpa_tree * dT)
{ 
  vector<unsigned int>* np_vec = new vector<unsigned int>;	  
  BDD * s = v3->s_state;
  
  multimap <unsigned int, pair<unsigned int, BDD> > * dpaTrs = dT->dpaTrs;
  unsigned int p = v3->p_state;
  bool b = false;
  for (multimap<unsigned int, pair<unsigned int, BDD> >::iterator j = dpaTrs->lower_bound(p); j!=dpaTrs->upper_bound(p); j++) {
  	BDD check = (j->second).second;
	b = (check * (*s) == (*s));

    if(b)
	  np_vec->push_back((j->second).first);
  }
  
  if(np_vec->size()==0){
  	cout << "There are some error(s) when getting next p_state !" << endl;
	free_mcmas_memory(NULL);
	exit(-1);
  }
  return np_vec;
}

bool
check_exist_g(map<string,map<unsigned int, string>*>* g_prim, vector<map<string, map<unsigned int, string>*>*>* m1){
  for(unsigned int i=0;i<m1->size();i++){  	
    map<string,map<unsigned int, string>*>* g_cmpr=(*m1)[i];    
	bool cmpr = check_g_equal(g_cmpr, g_prim);
    if(cmpr)
	  return true;
  }
  return false;
}

bool
check_g_equal(map<string, map<unsigned int, string>*>* g1, map<string, map<unsigned int, string>*>* g2){

  if(g1->size()!=g2->size())
  	return false;
  else{
    map<string,map<unsigned int, string>*>::iterator iter1 = g1->begin();
	map<string,map<unsigned int, string>*>::iterator iter2 = g2->begin();
	while(iter1!=g1->end()){
	  if(iter1->first!=iter2->first)
	  	return false;
	  else{
	    if(iter1->second->size()!=iter2->second->size())
			return false;
		else{
		  map<unsigned int, string>::iterator iter3 = iter1->second->begin();
		  map<unsigned int, string>::iterator iter4 = iter2->second->begin();
		  while(iter3!=iter1->second->end()){
			if(iter3->second!=iter4->second)
				return false;
			else{
				iter3++;
				iter4++;
			}
		  }
		}
		iter1++;
		iter2++;
	  }
	}
    return true;
  }
}


bool 
check_G_set(vector<map<string, map<unsigned int, string>*>*>* m1, vector<map<string, map<unsigned int, string>*>*>* m2, bdd_parameters* para){  
  unsigned int s1 = m1->size();
  unsigned int s2 = m2->size();  
  if(s1!=s2)
    return false;
  else{
  	for(unsigned int i=0;i<s1;i++){
      map<string,map<unsigned int, string>*>* g_prim = (*m1)[i];	
	  bool b=check_exist_g(g_prim,m2);
	  if(!b)
	  	return false;
	  else
	  	continue;
	}

	for(unsigned int i=0;i<s2;i++){
      map<string,map<unsigned int, string>*>* g_prim = (*m2)[i];	
	  bool b=check_exist_g(g_prim,m1);
	  if(!b)
	  	return false;
	  else
	  	continue;
	}
    return true;
  }
}

bool 
check_f_R(vector<transition*> processed_f_R, vector<transition*> this_f_R, vector<basic_agent*>* agents_IR_in, bdd_parameters* para){
  if(processed_f_R.size()!=this_f_R.size())
  	return false;
  else{
	transition* this_t = this_f_R[0];
	transition* processed_t = processed_f_R[0];
    string this_s="";
	string processed_s="";
    for (unsigned int k = 0; k < agents_IR_in->size(); k++) {
  	  this_s += (*agents_IR_in)[k]->action_to_str(*this_t->getlabel(), *para->a);
	  processed_s += (*agents_IR_in)[k]->action_to_str(*processed_t->getlabel(), *para->a);
  	}
	if(this_s==processed_s)
		return true;
	else
		return false;
  }
}

string
int2string(unsigned int val){
  stringstream stream; 
  stream << val;
  return stream.str();
}

unsigned int
char2int(const char* c){
  stringstream strValue;
  strValue << c;
  unsigned int intValue;
  strValue >> intValue;
  return intValue;
}
