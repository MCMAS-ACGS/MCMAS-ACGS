#include <ctime>
#include "types.hh"
#include "utilities.hh"
#include "atlk.hh"
#include <unistd.h>
#include <string>
#include<sstream>
#include <iostream>

using namespace std;
extern map<string, map<string, vector<BDD*>* >* >* integer_variable_BDDs(Cudd * bddmgr, vector<BDD> * v);
extern map<int,vector<BDD*>*>* agent_prot_map;
extern BDD complete_integer_BDDs(Cudd * bddmgr, vector<BDD> * v, BDD a, map<string, map<string, vector<BDD*>* >* >* int_vars);
extern BDD compute_reach(BDD in_st, vector<BDD> *v, vector<BDD> *pv, vector<BDD> *a, vector<BDD> *vRT, Cudd *bddmgr, unsigned int *acounter1, int id, unsigned long *threadmem);
extern void free_mcmas_memory(bdd_parameters *para);
extern map< string, vector< vector< BDD* >* >*> map_uniform_prots;
extern bool *satisfied;
extern map< string, BDD > * is_new_evaluation;
extern map< string, string> * shash_map;
extern BDD all_reach;

modal_formula_ast::modal_formula_ast(atomic_proposition * obj1)
{       // term
  op = 0;
  obj[0] = obj1;
}

modal_formula_ast::modal_formula_ast(unsigned char o, modal_formula_ast * f1)
{       // single operand formula
  op = o;
  obj[0] = f1;
}

modal_formula_ast::modal_formula_ast(unsigned char o, modal_formula_ast * f1,
                             modal_formula_ast * f2)
{       // two operands formula
  op = o;
  obj[0] = f1;
  obj[1] = f2;
}

modal_formula_ast::~modal_formula_ast()
{
}

unsigned char
modal_formula_ast::get_op()
{
  return op;
}



Object *
modal_formula_ast::get_operand(unsigned char i)
{
  if (i == 0 && obj[0] != NULL)
    return (obj[0]);
  else if (i == 1 && obj[1] != NULL &&
           (op == 1 || op == 2 || op == 4 || op == 8 || op == 9 || op == 10 || op == 11||
             op == 12|| op == 13|| op == 14))
    return (obj[1]);
  else {
    cout << " error: operand " << i << " not found!" << endl;
    exit(1);
  }
}

string
modal_formula_ast::to_string()
{
  if (op == 0)
    return ((atomic_proposition *) obj[0])->to_string();
  else if (op == 1)
    return "(" + ((modal_formula_ast *) obj[0])->to_string() + " && " +
      ((modal_formula_ast *) obj[1])->to_string() + ")";
  else if (op == 2)
    return "(" + ((modal_formula_ast *) obj[0])->to_string() + " || " +
      ((modal_formula_ast *) obj[1])->to_string() + ")";
  else if (op == 3)
    return "(! " + ((modal_formula_ast *) obj[0])->to_string() + ")";
  else if (op == 4)
    return "(" + ((modal_formula_ast *) obj[0])->to_string() + " -> " +
      ((modal_formula_ast *) obj[1])->to_string() + ")";
  else if (op == 5){
    return "(X " + ((modal_formula_ast *) obj[0])->to_string() + ")";}
  else if (op == 6)
    return "(F " + ((modal_formula_ast *) obj[0])->to_string() + ")";
  else if (op == 7)
    return "(G " + ((modal_formula_ast *) obj[0])->to_string() + ")";
  else if (op == 8)
    return "(" + ((modal_formula_ast *) obj[0])->to_string() + " U " +
    	((modal_formula_ast *) obj[1])->to_string() + ")";
  else if (op == 9)
    return "(" + ((modal_formula_ast *) obj[0])->to_string() + " R " +
    	((modal_formula_ast *) obj[1])->to_string() + ")";
  else if (op == 10)
    return "(K(" + ((modal_formula_ast *) obj[0])->to_string() + "," +
    	((modal_formula_ast *) obj[1])->to_string() + "))";
  else if (op == 11)
    return "(E(" + ((modal_formula_ast *) obj[0])->to_string() + ", " +
    	((modal_formula_ast *) obj[1])->to_string() + "))";
  else if (op == 12)
    return "(C(" + ((modal_formula_ast *) obj[0])->to_string() + ", " +
    	((modal_formula_ast *) obj[1])->to_string() + "))";
  else if (op == 13)
    return "(D(" + ((modal_formula_ast *) obj[0])->to_string() + ", " +
    	((modal_formula_ast *) obj[1])->to_string() + "))";
  else //if (op == 14)
    return "<" + ((modal_formula_ast *) obj[0])->to_string() + ">(" +
    	((modal_formula_ast *) obj[1])->to_string() + ")";
}


bool
modal_formula_ast::check_atomic_proposition(unsigned char type)
{
  // type=0: atomic proposition, type=1: agent, type=2: group, type=3: agent or group
  bool b1, b2, b3;
  switch (op) {
  case 1:     // AND
  case 2:     // OR
  case 4:     // IMPLIES
  case 8:      // U
  case 9:      // R
    b1 = ((modal_formula_ast *) obj[0])->check_atomic_proposition(0);
    b2 = ((modal_formula_ast *) obj[1])->check_atomic_proposition(0);
    return (b1 && b2);
  case 3:     // NOT
  case 5:      // X
  case 6:      // F
  case 7:      // G
    return ((modal_formula_ast *) obj[0])->check_atomic_proposition(0);
  case 10:	//K
    b1 = ((modal_formula_ast *) obj[0])->check_atomic_proposition(1);
    b2 = ((modal_formula_ast *) obj[1])->check_atomic_proposition(0);
    return (b1 && b2);
  case 11:
  case 12:
  case 13:
  case 14:      // <A>
	b1 = ((modal_formula_ast *) obj[0])->check_atomic_proposition(2); 
	b2 = ((modal_formula_ast *) obj[1])->check_atomic_proposition(0);
    return (b1 && b2);
	
  case 0:     // A leaf node
    string name = ((atomic_proposition *) obj[0])->get_proposition();
    switch (type) {
      case 0:
	    if (is_evaluation->find(name) != is_evaluation->end()) {
		  return true;
	    }
	    else {
		  cout << "    atomic proposition " << name << " is not defined." <<endl;
		  return false;
	    }
      case 1:
        if (is_agents->find(name) == is_agents->end()) {
          cout << "    agent " << name << " is not defined." << endl;
          return false;
        } else
          return true;
      case 2:
        if (is_groups->find(name) == is_groups->end()) {
          cout << "    group " << name << " is not defined." << endl;
          return false;
        } else
          return true;
      case 3:
        if (is_agents->find(name) == is_agents->end() && is_groups->find(name) == is_groups->end()) {
          cout << "    agent " << name << " is not defined." << endl;
          return false;
        } else
          return true;
    }
  }
  return false;
}


bool 
modal_formula_ast::check_pure_ltl()
{
  // type=0: atomic proposition, type=1: agent, type=2: group, type=3: agent or group
  bool b1, b2;
  switch (op) {
  case 0:
  	return true;
  case 1:     // AND
  case 2:     // OR
  case 4:     // IMPLIES
  case 8:      // U
  case 9:      // R
    b1 = ((modal_formula_ast *) obj[0])->check_pure_ltl();
    b2 = ((modal_formula_ast *) obj[1])->check_pure_ltl();
    return (b1 && b2);
  case 3:     // NOT
  case 5:      // X
  case 6:      // F
  case 7:      // G
    return ((modal_formula_ast *) obj[0])->check_pure_ltl();
  case 10:      // K,E,D,C,<A>
  case 11:
  case 12:
  case 13:
  case 14:
    return false;
  }
}

bool 
modal_formula_ast::check_tight_atl() //gurantee <A> is tightly bounded with X,G,U
{
  // type=0: atomic proposition, type=1: agent, type=2: group, type=3: agent or group
  bool b1, b2;
  switch (op) {
  case 0:
	return true;
  case 1:     // AND
  case 2:     // OR
  case 4:  {   // IMPLIES
	b1 = ((modal_formula_ast *) obj[0])->check_tight_atl();
	b2 = ((modal_formula_ast *) obj[1])->check_tight_atl();
	return (b1 && b2);
  }
  case 8:	   // U
  case 9: {    // R
  	b1 = ((modal_formula_ast *) obj[0])->check_tight_atl();
    b2 = ((modal_formula_ast *) obj[1])->check_tight_atl();
    return (b1 && b2);
  }
  case 3:     // NOT
  case 5:      // X
  case 6:      // F
  case 7: {    // G
    return ((modal_formula_ast *) obj[0])->check_tight_atl();
  }
  case 10:      // K,E,D,C
  case 11:
  case 12:
  case 13:
	return ((modal_formula_ast *) obj[1])->check_tight_atl();
  case 14:{ //<A>
   	unsigned char cur_op =((modal_formula_ast *) obj[1])->get_op();
	if(cur_op==5||cur_op==6||cur_op==7){
	  modal_formula_ast* sub_formula = (modal_formula_ast *) obj[1];
	  modal_formula_ast* sub_sub_formula = (modal_formula_ast*) sub_formula->get_operand(0);
	  return sub_sub_formula->check_tight_atl();	  
	} else if(cur_op==8||cur_op==9){
	  bool b1 = ((modal_formula_ast *) ((modal_formula_ast *) obj[1])->get_operand(0))->check_tight_atl();
	  bool b2 = ((modal_formula_ast *) ((modal_formula_ast *) obj[1])->get_operand(1))->check_tight_atl();
	  return b1&&b2;
	} else{
	  return false;
	}
  }}
}

bool 
modal_formula_ast::check_pure_atl() //gurantee <A> is tightly bounded with X,G,U
{
  // type=0: atomic proposition, type=1: agent, type=2: group, type=3: agent or group
  bool b1, b2;
  modal_formula_ast * sub_formula = (modal_formula_ast *) obj[1];
  unsigned char next_op = sub_formula->get_op();
  switch (next_op) {
  case 0:
  case 1:     // AND
  case 2:     // OR
  case 3:     // NOT
  case 4:     // IMPLIES
  case 10:     // K,E,D,C
  case 11:
  case 12:
  case 13:
  case 14:   //<A>
	return false;
  case 5:      // X
  case 6:      // F
  case 7:{     // G
    modal_formula_ast * sub_sub_formula = (modal_formula_ast *) (sub_formula->get_operand(0));
	unsigned char next_next_op = sub_sub_formula->get_op();
    if(next_next_op==0)
	  return true;
	else
	  return false;
  }
  case 8:      // U
  case 9:{	   // R
    modal_formula_ast * sub_sub_formula_0 = (modal_formula_ast *) (sub_formula->get_operand(0));
	modal_formula_ast * sub_sub_formula_1 = (modal_formula_ast *) (sub_formula->get_operand(1));
    unsigned char next_next_op_0 = sub_sub_formula_0->get_op();
	unsigned char next_next_op_1 = sub_sub_formula_1->get_op();
    if((next_next_op_0==0)&&(next_next_op_1==0))
	  return true;
	else
	  return false;
  }}
}

modal_formula_ast*
modal_formula_ast::reduce2simple_atl(bdd_parameters* para, bool if_nest, bool atl_pg){
  modal_formula_ast * simple_atl = NULL;
  modal_formula_ast * sub_formula = (modal_formula_ast *) obj[1];
  unsigned char next_op = sub_formula->get_op();
  switch (next_op) {
  case 0:
  case 1:     // AND
  case 2:     // OR
  case 3:	  // NOT
  case 4:     // IMPLIES
  case 10:      // K,E,D,C
  case 11:
  case 12:
  case 13:
  case 14:{ //<A>
	cout << "Error!! <> in this formla is not a Vanilla ATL!" << endl;
    free_mcmas_memory(NULL);
    exit(-1);
  }  
  case 5:   // X-->ATLX
  case 6:	// F-->ATLG
  case 7:{	// G-->ATLF
	modal_formula_ast * sub_sub_formula = (modal_formula_ast *) sub_formula->get_operand(0);
	string st = sub_sub_formula->to_string();
	if (is_new_evaluation->find(st)!=is_new_evaluation->end()){
	  atomic_proposition * ap = new atomic_proposition(new string(st));
	  modal_formula_ast * ap_formula = new modal_formula_ast(ap);
	  modal_formula_ast * simple_atl_sub_formula = new modal_formula_ast(next_op,ap_formula);
	  simple_atl = new modal_formula_ast(14,(modal_formula_ast*)obj[0],simple_atl_sub_formula);
	}
	else{
	  BDD sub_sub_result = sub_sub_formula->check_formula_ast(para,1,atl_pg); 
	  
      string new_ap_hash = "new_eva"+ int2string(is_new_evaluation->size());	
	  pair<string, BDD> p1(new_ap_hash,sub_sub_result);
	  pair<string,string> p2(st,new_ap_hash);
	  if(options["nobddcache"] == 0)
	    (*para->BDD_cache)[st] = sub_sub_result;

	  is_new_evaluation->insert(p1);
	  shash_map->insert(p2);
      	
	  atomic_proposition* ap = new atomic_proposition(&(*shash_map)[st]);
	  modal_formula_ast * ap_formula = new modal_formula_ast(ap);
	  modal_formula_ast * simple_atl_sub_formula = new modal_formula_ast(next_op,ap_formula);
	  simple_atl = new modal_formula_ast(14,(modal_formula_ast*)obj[0],simple_atl_sub_formula);
	}
	break;
  }
  case 8: 	// U
  case 9:{	// R-->ATLU
    modal_formula_ast * sub_sub_formula_0 = (modal_formula_ast *) (sub_formula->get_operand(0));
	modal_formula_ast * sub_sub_formula_1 = (modal_formula_ast *) (sub_formula->get_operand(1));
	string st_0 = sub_sub_formula_0->to_string();
	string st_1 = sub_sub_formula_1->to_string();

	modal_formula_ast * ap_formula_0 = NULL;
	modal_formula_ast * ap_formula_1 = NULL;
	// for formula_0
	if (is_new_evaluation->find(st_0)!=is_new_evaluation->end()){
	  atomic_proposition * ap_0 = new atomic_proposition(new string(st_0));
	  ap_formula_0 = new modal_formula_ast(ap_0);
	}
	else{
	  BDD sub_sub_result = sub_sub_formula_0->check_formula_ast(para,1,atl_pg);
      string new_ap_hash = "new_eva"+ int2string(is_new_evaluation->size());	
	  pair<string, BDD> p1(new_ap_hash,sub_sub_result);
	  pair<string,string> p2(st_0,new_ap_hash);
	  if(options["nobddcache"] == 0)
	    (*para->BDD_cache)[st_0] = sub_sub_result;

	  is_new_evaluation->insert(p1);
	  shash_map->insert(p2);
      	
	  atomic_proposition* ap = new atomic_proposition(&(*shash_map)[st_0]);
	  ap_formula_0 = new modal_formula_ast(ap);
	}

	// for formula_1
	if (is_new_evaluation->find(st_1)!=is_new_evaluation->end()){
	  atomic_proposition * ap_1 = new atomic_proposition(new string(st_1));
	  ap_formula_1 = new modal_formula_ast(ap_1);
	}
	else{
	  BDD sub_sub_result = sub_sub_formula_1->check_formula_ast(para,1,atl_pg);
      string new_ap_hash = "new_eva"+ int2string(is_new_evaluation->size());	
	  pair<string, BDD> p1(new_ap_hash,sub_sub_result);
	  pair<string,string> p2(st_1,new_ap_hash);
	  if(options["nobddcache"] == 0)
	    (*para->BDD_cache)[st_1] = sub_sub_result;

	  is_new_evaluation->insert(p1);
	  shash_map->insert(p2);
      	
	  atomic_proposition* ap = new atomic_proposition(&(*shash_map)[st_1]);
	  ap_formula_1 = new modal_formula_ast(ap);
	}

	modal_formula_ast * simple_atl_sub_formula = new modal_formula_ast(next_op,ap_formula_0,ap_formula_1);
	simple_atl = new modal_formula_ast(14,(modal_formula_ast*)obj[0],simple_atl_sub_formula);
	break;
  }}
  return simple_atl;
}


modal_formula_ast*
modal_formula_ast::reduce2pureltl(bdd_parameters* para, bool atl_pg)
{
  BDD original_reach = *para->original_reach;
  // type=0: atomic proposition, type=1: agent, type=2: group, type=3: agent or group
  modal_formula_ast *reduced_ltl = NULL;
  switch (op) {
  case 0:
  	return this;
  case 1:     // AND
  case 2:     // OR
  case 4:     // IMPLIES
  case 8:      // U  
  case 9:      // R  
    reduced_ltl = new modal_formula_ast(op,((modal_formula_ast *) obj[0])->reduce2pureltl(para,atl_pg), ((modal_formula_ast *) obj[1])->reduce2pureltl(para,atl_pg));
    return reduced_ltl;
  case 3:	  // NOT
  case 5: 	 // X
  case 6: 	 // F
  case 7: 	 // G
	reduced_ltl = new modal_formula_ast(op,((modal_formula_ast *) obj[0])->reduce2pureltl(para,atl_pg));
	return reduced_ltl;
  case 10:{   //K(i,phi)
    string st = to_string();
    if (shash_map->find(st)!=shash_map->end()){
	  atomic_proposition* ap = new atomic_proposition(&(*shash_map)[st]);
	  modal_formula_ast* ap_formula = new modal_formula_ast(ap);
	  return ap_formula;	
	}
	else{
	  modal_formula_ast* new_ast = ((modal_formula_ast *) obj[1])->reduce2pureltl(para,atl_pg);
      Object *id = ((modal_formula_ast *) obj[0])->get_operand(0);
	  string individual_name = ((atomic_proposition *) id)->get_proposition();

	  string sub_formula = ((modal_formula_ast *) obj[1])->to_string();
	  BDD sub_formula_result = all_reach;
	  
	  if (para->BDD_cache->find(sub_formula) != para->BDD_cache->end()){
		sub_formula_result *= ((*para->BDD_cache)[sub_formula]);
	  }
	  else{
		sub_formula_result *= ((modal_formula_ast *) obj[1])->check_formula_ast(para,1,atl_pg);
		(*para->BDD_cache)[sub_formula]=sub_formula_result;
	  }

	  BDD af = !sub_formula_result * all_reach;
	  sub_formula_result = sub_formula_result - SCGS_get_nK_states(&af, individual_name, para);

      string new_ap_hash = "new_eva"+ int2string(is_new_evaluation->size());
	  pair<string, BDD> p1(new_ap_hash,sub_formula_result);
	  pair<string,string> p2(st,new_ap_hash);
	  if(options["nobddcache"] == 0)
	    (*para->BDD_cache)[st] = sub_formula_result;

	  is_new_evaluation->insert(p1);
	  shash_map->insert(p2);

	  atomic_proposition* ap = new atomic_proposition(&(*shash_map)[st]);
	  reduced_ltl = new modal_formula_ast(ap);
	  return reduced_ltl;
	}
  }  
  case 11:{	  //E(A, phi) 
    string st = to_string();
    if (shash_map->find(st)!=shash_map->end()){
	  atomic_proposition* ap = new atomic_proposition(&(*shash_map)[st]);
	  modal_formula_ast* ap_formula = new modal_formula_ast(ap);
	  return ap_formula;	
	}
	else{
	  modal_formula_ast* new_ast = ((modal_formula_ast *) obj[1])
	  	->reduce2pureltl(para,atl_pg);
	  Object *id = ((modal_formula_ast *) obj[0])->get_operand(0);
	  string grp_name = ((atomic_proposition *) id)->get_proposition();

	  string sub_formula = ((modal_formula_ast *) obj[1])->to_string();
	  BDD sub_formula_result = all_reach;
	  if (para->BDD_cache->find(sub_formula) != para->BDD_cache->end()){
		sub_formula_result *= ((*para->BDD_cache)[sub_formula]);
	  }
	  else{
		sub_formula_result *= ((modal_formula_ast *) obj[1])->check_formula_ast(para,1,atl_pg);
		(*para->BDD_cache)[sub_formula]=sub_formula_result;
	  }

	  sub_formula_result = SCGS_check_GK(sub_formula_result, grp_name, para)*sub_formula_result;	  
      string new_ap_hash = "new_eva"+ int2string(is_new_evaluation->size());
	  pair<string, BDD> p1(new_ap_hash,sub_formula_result);
	  pair<string,string> p2(st,new_ap_hash);
	  if(options["nobddcache"] == 0)
		(*para->BDD_cache)[st] = sub_formula_result;

	  is_new_evaluation->insert(p1);
	  shash_map->insert(p2);

	  atomic_proposition* ap = new atomic_proposition(&(*shash_map)[st]);
	  reduced_ltl = new modal_formula_ast(ap);//
	  return reduced_ltl;
	}
  }
  case 12:{   //D(A, phi)
    string st = this->to_string();
    if (shash_map->find(st)!=shash_map->end()){
	  atomic_proposition* ap = new atomic_proposition(&(*shash_map)[st]);
	  modal_formula_ast* ap_formula = new modal_formula_ast(ap);
	  return ap_formula;	
	}
	else{
	  modal_formula_ast* new_ast = ((modal_formula_ast *) obj[1])->reduce2pureltl(para,atl_pg);
	  Object *id = ((modal_formula_ast *) obj[0])->get_operand(0);
	  string grp_name = ((atomic_proposition *) id)->get_proposition();

	  string sub_formula = ((modal_formula_ast *) obj[1])->to_string();
	  BDD sub_formula_result = all_reach;
	  if (para->BDD_cache->find(sub_formula) != para->BDD_cache->end()){
		sub_formula_result *= ((*para->BDD_cache)[sub_formula]);
	  }
	  else{
		sub_formula_result *= ((modal_formula_ast *) obj[1])->check_formula_ast(para,1,atl_pg);
		(*para->BDD_cache)[sub_formula]=sub_formula_result;
	  }

	  sub_formula_result = SCGS_check_DK(sub_formula_result, grp_name, para)*sub_formula_result;	  
      string new_ap_hash = "new_eva"+ int2string(is_new_evaluation->size());
	  pair<string, BDD> p1(new_ap_hash,sub_formula_result);
	  pair<string,string> p2(st,new_ap_hash);
	  if(options["nobddcache"] == 0)
		(*para->BDD_cache)[st] = sub_formula_result;

	  is_new_evaluation->insert(p1);
	  shash_map->insert(p2);

	  atomic_proposition* ap = new atomic_proposition(&(*shash_map)[st]);
	  reduced_ltl = new modal_formula_ast(ap);//
	  return reduced_ltl;
	}
  }
  case 13:{	  //C(A,phi)
    string st = this->to_string();
    if (shash_map->find(st)!=shash_map->end()){
	  atomic_proposition* ap = new atomic_proposition(&(*shash_map)[st]);
	  modal_formula_ast* ap_formula = new modal_formula_ast(ap);
	  return ap_formula;	
	}
	else{
	  modal_formula_ast* new_ast = ((modal_formula_ast *) obj[1])->reduce2pureltl(para,atl_pg);
	  Object *id = ((modal_formula_ast *) obj[0])->get_operand(0);
	  string grp_name = ((atomic_proposition *) id)->get_proposition();

	  string sub_formula = ((modal_formula_ast *) obj[1])->to_string();
	  BDD sub_formula_result = all_reach;
	  if (para->BDD_cache->find(sub_formula) != para->BDD_cache->end()){
		sub_formula_result *= ((*para->BDD_cache)[sub_formula]);
	  }
	  else{
		sub_formula_result *= ((modal_formula_ast *) obj[1])->check_formula_ast(para,1,atl_pg);
		(*para->BDD_cache)[sub_formula]=sub_formula_result;
	  }

	  sub_formula_result = SCGS_check_GCK(sub_formula_result, grp_name, para)*sub_formula_result;	  
      string new_ap_hash = "new_eva"+ int2string(is_new_evaluation->size());
	  pair<string, BDD> p1(new_ap_hash,sub_formula_result);
	  pair<string,string> p2(st,new_ap_hash);
	  if(options["nobddcache"] == 0)
		(*para->BDD_cache)[st] = sub_formula_result;

	  is_new_evaluation->insert(p1);
	  shash_map->insert(p2);

	  atomic_proposition* ap = new atomic_proposition(&(*shash_map)[st]);
	  reduced_ltl = new modal_formula_ast(ap);//
	  return reduced_ltl;
	}
  }
  case 14:{      // <A>
    string st = this->to_string();
	if (shash_map->find(st)!=shash_map->end()){
	  atomic_proposition* ap = new atomic_proposition(&(*shash_map)[st]);
	  modal_formula_ast* ap_formula = new modal_formula_ast(ap);
	  return ap_formula;
	}
	else{
	  BDD new_ap;
	  Object *id = ((modal_formula_ast *) obj[0])->get_operand(0);
	  string grp = ((atomic_proposition *) id)->get_proposition();
	  if(atl_pg){
		modal_formula_ast* new_ast = ((modal_formula_ast *) obj[1])->reduce2pureltl(para,atl_pg);
		reduced_ltl = new modal_formula_ast(op,(modal_formula_ast *) obj[0],new_ast);		
		new_ap = reduced_ltl->check_simple_ast(para,grp,1); 

		string new_ap_hash = "new_eva"+ int2string(is_new_evaluation->size());	
	    pair<string, BDD> p1(new_ap_hash,new_ap);
	    pair<string,string> p2(st,new_ap_hash);
	    if(options["nobddcache"] == 0)
	      (*para->BDD_cache)[st] = new_ap;

	    is_new_evaluation->insert(p1);
	    shash_map->insert(p2);
		
	    atomic_proposition* ap = new atomic_proposition(&(*shash_map)[st]);
	    reduced_ltl = new modal_formula_ast(ap);//
	    return reduced_ltl;
	  
	  } else{
		new_ap = this->check_simple_atl(para,grp,1);  
		string new_ap_hash = this->to_string();
	    pair<string, BDD> p1(new_ap_hash,new_ap);
	  	pair<string,string> p2(st,new_ap_hash);
	  	if(options["nobddcache"] == 0)
	    	(*para->BDD_cache)[st] = new_ap;

	  	is_new_evaluation->insert(p1);
	  	shash_map->insert(p2);
		
	  	atomic_proposition* ap = new atomic_proposition(&(*shash_map)[st]);
	  	reduced_ltl = new modal_formula_ast(ap);//
	  	return reduced_ltl;
	  }      
	}
  }
  }
}

//modal_formula*
//modal_formula_ast::ast2formula(bdd_parameters * para){ 
//  modal_formula_ast * sub_formula = (modal_formula_ast *)obj[1];  
//  unsigned char next_op = sub_formula->get_op();
//  string grp = obj[0];
//  
//  switch (next_op) {
//  case 0:
//  case 1:     // AND
//  case 2:     // OR
//  case 3:     // NOT
//  case 4:     // IMPLIES
//  case 9:     // K,E,D,C
//  case 10:
//  case 11:
//  case 12:
//  case 13:{   //<A>
//	cout << "Error! We cannot transfer this ATL_ast to ATL!" << endl;
//	free_mcmas_memory(NULL);
//	exit(-1);
//  }
//  case 5:{     // X
//    modal_formula_ast * sub_sub_formula = (modal_formula_ast *)(sub_formula->get_operand(0));
//	string st = sub_sub_formula->to_string();
//    if (is_new_evaluation->find(st)!=shash_map->end()){
//	  atomic_proposition* ap = new atomic_proposition(&(*shash_map)[st]);
//	  modal_formula* ap_formula = new modal_formula(ap);
//	  if(grp=="Empty"){ 
//		modal_formula* new_formula = new modal_formula(12,ap_formula);
//		return new_formula;
//	  } else{
//		modal_formula* new_formula = new modal_formula(45,(modal_formula*)obj[0],ap_formula);
//		return new_formula;
//	  }
//	  
//	} else{
//	  cout << "Error! We cannot find the proposition when transferring this ATL_ast to ATL!" << endl;
//	  free_mcmas_memory(NULL);
//	  exit(-1);
//	}
//  }
//  case 6:{     // F
//    modal_formula_ast * sub_sub_formula = (modal_formula_ast *)(sub_formula->get_operand(0));
//	string st = sub_sub_formula->to_string();
//    if (is_new_evaluation->find(st)!=shash_map->end()){
//	  atomic_proposition* ap = new atomic_proposition(&(*shash_map)[st]);
//	  modal_formula* ap_formula = new modal_formula(ap);	  
//	  if(grp=="Empty"){ 
//		modal_formula* new_formula = new modal_formula(14,ap_formula);
//		return new_formula;
//	  } else{
//		modal_formula* new_formula = new modal_formula(46,(modal_formula*)obj[0],ap_formula);
//		return new_formula;
//	  }
//	} else{
//	  cout << "Error! We cannot find the proposition when transferring this ATL_ast to ATL!" << endl;
//	  free_mcmas_memory(NULL);
//	  exit(-1);
//	}
//  }
//  case 7:{     // G
//    modal_formula_ast * sub_sub_formula = (modal_formula_ast *)(sub_formula->get_operand(0));
//	string st = sub_sub_formula->to_string();
//    if (is_new_evaluation->find(st)!=shash_map->end()){
//	  atomic_proposition* ap = new atomic_proposition(&(*shash_map)[st]);
//	  modal_formula* ap_formula = new modal_formula(ap);	  
//	  if(grp=="Empty"){ 
//		modal_formula* new_formula = new modal_formula(10,ap_formula);
//		return new_formula;
//	  } else{
//		modal_formula* new_formula = new modal_formula(47,(modal_formula*)obj[0],ap_formula);
//		return new_formula;
//	  }
//	} else{
//	  cout << "Error! We cannot find the proposition when transferring this ATL_ast to ATL!" << endl;
//	  free_mcmas_memory(NULL);
//	  exit(-1);
//	}
//  }
//    
//  }
//  case 8:{	   // U
//    modal_formula_ast * sub_sub_formula_0 = (modal_formula_ast *)(sub_formula->get_operand(0));
//	modal_formula_ast * sub_sub_formula_1 = (modal_formula_ast *)(sub_formula->get_operand(1));
//	string st_0 = sub_sub_formula_0->to_string();
//	string st_1 = sub_sub_formula_0->to_string();
//	bool in_new_eva = (is_new_evaluation->find(st_0)!=is_new_evaluation->end())&&(is_new_evaluation->find(st_1)!=is_new_evaluation->end());
//    if(in_new_eva){
//	  atomic_proposition* ap_0 = new atomic_proposition(&(*shash_map)[st_0]);
//	  atomic_proposition* ap_1 = new atomic_proposition(&(*shash_map)[st_1]);
//	  modal_formula* ap_formula_0 = new modal_formula(ap_0);	
//	  modal_formula* ap_formula_1 = new modal_formula(ap_1);
//	  if(grp=="Empty"){ 
//		modal_formula* new_formula = new modal_formula(16,ap_formula_0,ap_formula_1);
//		return new_formula;
//	  } else{
//		modal_formula* new_formula = new modal_formula(48,(modal_formula*)obj[0],ap_formula_0,ap_formula_1);
//		return new_formula;
//	  }
//	} else{
//	  cout << "Error! We cannot find the proposition when transferring this ATL_ast to ATL!" << endl;
//	  free_mcmas_memory(NULL);
//	  exit(-1);
//	}
//  }  
//  case 9:{	   // R
//    modal_formula_ast * sub_sub_formula_0 = (modal_formula_ast *)(sub_formula->get_operand(0));
//	modal_formula_ast * sub_sub_formula_1 = (modal_formula_ast *)(sub_formula->get_operand(1));
//	string st_0 = sub_sub_formula_0->to_string();
//	string st_1 = sub_sub_formula_0->to_string();
//	bool in_new_eva = (is_new_evaluation->find(st_0)!=is_new_evaluation->end())&&(is_new_evaluation->find(st_1)!=is_new_evaluation->end());
//    if(in_new_eva){
//	  atomic_proposition* ap_0 = new atomic_proposition(&(*shash_map)[st_0]);
//	  atomic_proposition* ap_1 = new atomic_proposition(&(*shash_map)[st_1]);
//	  modal_formula* ap_formula_0 = new modal_formula(ap_0);	
//	  modal_formula* ap_formula_1 = new modal_formula(ap_1);
//	  if(grp=="Empty"){ 
//		modal_formula* new_formula = new modal_formula(18,ap_formula_0,ap_formula_1);
//		return new_formula;
//	  } else{
//		modal_formula* new_formula = new modal_formula(49,(modal_formula*)obj[0],ap_formula_0,ap_formula_1);
//		return new_formula;
//	  }
//	} else{
//	  cout << "Error! We cannot find the proposition when transferring this ATL_ast to ATL!" << endl;
//	  free_mcmas_memory(NULL);
//	  exit(-1);
//	}
//  }
//  
//}
//}

modal_formula*
modal_formula_ast::ast2formula_CTL(bdd_parameters * para){
  modal_formula_ast * sub_formula = (modal_formula_ast *)obj[1];  
  unsigned char next_op = sub_formula->get_op();
  Object *id = ((modal_formula_ast *) obj[0])->get_operand(0);
  string grp = ((atomic_proposition *) id)->get_proposition();;
  switch (next_op) {
  case 0:
  case 1:     // AND
  case 2:     // OR
  case 3:     // NOT
  case 4:     // IMPLIES
  case 10:     // K,E,D,C
  case 11:
  case 12:
  case 13:
  case 14:{   //<A>
	cout << "Error! We cannot transfer this ATL_ast to ATL!" << endl;
	free_mcmas_memory(NULL);
	exit(-1);
  }
  case 5:{     // X
    modal_formula_ast * sub_sub_formula = (modal_formula_ast *)(sub_formula->get_operand(0));
	string st = sub_sub_formula->to_string();
    bool in_new_eva = is_new_evaluation->find(st)!=is_new_evaluation->end();
	bool in_eva = is_evaluation->find(st)!=is_evaluation->end();
    if (in_new_eva||in_eva){
	  atomic_proposition* ap = new atomic_proposition(new string(st));
	  modal_formula* ap_formula = new modal_formula(ap); 
	  modal_formula* new_formula = new modal_formula(12,ap_formula);
	  return new_formula;	  
	} else{
	  cout << "Error! We cannot find the proposition: "<<st<<" when transferring this ATL_ast to ATL!" << endl;
	  free_mcmas_memory(NULL);
	  exit(-1);
	}
  }
  case 6:{     // F
    modal_formula_ast * sub_sub_formula = (modal_formula_ast *)(sub_formula->get_operand(0));
	string st = sub_sub_formula->to_string();
    bool in_new_eva = is_new_evaluation->find(st)!=is_new_evaluation->end();
	bool in_eva = is_evaluation->find(st)!=is_evaluation->end();
    if (in_new_eva||in_eva){
	  atomic_proposition* ap = new atomic_proposition(new string(st));
	  modal_formula* ap_formula = new modal_formula(ap);	  
	  modal_formula* new_formula = new modal_formula(14,ap_formula);
	  return new_formula;
	} else{
	  cout << "Error! We cannot find the proposition: "<<st<<" when transferring this ATL_ast to ATL!" << endl;
	  free_mcmas_memory(NULL);
	  exit(-1);
	}
  }
  case 7:{     // G
    modal_formula_ast * sub_sub_formula = (modal_formula_ast *)(sub_formula->get_operand(0));
	string st = sub_sub_formula->to_string();
    bool in_new_eva = is_new_evaluation->find(st)!=is_new_evaluation->end();
	bool in_eva = is_evaluation->find(st)!=is_evaluation->end();
    if (in_new_eva||in_eva){
	  atomic_proposition* ap = new atomic_proposition(new string(st));
	  modal_formula* ap_formula = new modal_formula(ap);	    
	  modal_formula* new_formula = new modal_formula(10,ap_formula);
	  return new_formula;
	} else{
	  cout << "Error! We cannot find the proposition: " <<st<<" when transferring this ATL_ast to ATL!" << endl;
	  free_mcmas_memory(NULL);
	  exit(-1);
	}    
  }
  case 8:{	   // U
    modal_formula_ast * sub_sub_formula_0 = (modal_formula_ast *)(sub_formula->get_operand(0));
	modal_formula_ast * sub_sub_formula_1 = (modal_formula_ast *)(sub_formula->get_operand(1));
	string st_0 = sub_sub_formula_0->to_string();
	string st_1 = sub_sub_formula_1->to_string();
	bool in_new_eva = (is_new_evaluation->find(st_0)!=is_new_evaluation->end())&&(is_new_evaluation->find(st_1)!=is_new_evaluation->end());
	bool in_eva = (is_evaluation->find(st_0)!=is_evaluation->end())&&(is_evaluation->find(st_1)!=is_evaluation->end());
    if(in_new_eva||in_eva){
	  atomic_proposition* ap_0 = new atomic_proposition(new string(st_0));
	  atomic_proposition* ap_1 = new atomic_proposition(new string(st_1));
	  modal_formula* ap_formula_0 = new modal_formula(ap_0);	
	  modal_formula* ap_formula_1 = new modal_formula(ap_1);
	  modal_formula* new_formula = new modal_formula(16,ap_formula_0,ap_formula_1);
	  return new_formula;
	} else{
	  cout << "Error! We cannot find the proposition: "<<st_0<<" and "<<st_1<<" when transferring this ATL_ast to ATL!" << endl;
	  free_mcmas_memory(NULL);
	  exit(-1);
	}
  }  
  case 9:{	   // R
    modal_formula_ast * sub_sub_formula_0 = (modal_formula_ast *)(sub_formula->get_operand(0));
	modal_formula_ast * sub_sub_formula_1 = (modal_formula_ast *)(sub_formula->get_operand(1));
	string st_0 = sub_sub_formula_0->to_string();
	string st_1 = sub_sub_formula_0->to_string();
	bool in_new_eva = (is_new_evaluation->find(st_0)!=is_new_evaluation->end())&&(is_new_evaluation->find(st_1)!=is_new_evaluation->end());
	bool in_eva = (is_evaluation->find(st_0)!=is_evaluation->end())&&(is_evaluation->find(st_1)!=is_evaluation->end());
    if(in_new_eva||in_eva){
	  atomic_proposition* ap_0 = new atomic_proposition(new string(st_0));
	  atomic_proposition* ap_1 = new atomic_proposition(new string(st_1));
	  modal_formula* ap_formula_0 = new modal_formula(ap_0);	
	  modal_formula* ap_formula_1 = new modal_formula(ap_1);
	  modal_formula* new_formula = new modal_formula(18,ap_formula_0,ap_formula_1);
	  return new_formula;
	} else{
	  cout << "Error! We cannot find the proposition: "<<st_0<<" and "<<st_1<<" when transferring this ATL_ast to ATL!" << endl;
	  free_mcmas_memory(NULL);
	  exit(-1);
	}
  }
}
}

BDD 
modal_formula_ast::check_simple_atl(bdd_parameters * para, string grp, bool if_nest){
  cout<<"we use lemma 2 to check ATL"<<endl;
  map < string, set < string > >::iterator gi = is_groups->find(grp);
  set < string > names_g = gi->second;
  bool is_empty = *(names_g.begin())=="Empty";  
  if(is_empty){
    vector< vector< BDD*>* >* uniform_r_prots = new vector< vector< BDD*>* >;
    for(vector<basic_agent*>::iterator i = agents->begin();i!=agents->end();i++) {
	  basic_agent* ag = *i;
	  int index = (*is_agents_index)[(*i)->get_name()];
	  if(ag->get_strategy_type()=="Ir"){
		(*agent_prot_map)[index] = ag->get_abs_protocol_Ir(para);
	   	uniform_r_prots->push_back((*agent_prot_map)[index]);
	  } else if (ag->get_strategy_type()=="ior"||ag->get_strategy_type()=="isr") { 
	    vector<BDD*>* uni_prot = new vector<BDD*>;
		BDD oneline_temp = para->bddmgr->bddZero();
		BDD* other_condition = new BDD(*para->original_reach);
		if(ag->get_protocol()->size()==0){
		  BDD* one_bdd = new BDD(para->bddmgr->bddOne());
		  uni_prot->push_back(one_bdd);
		} else{
		  ag->encode_protocol_ir(para, 0, uni_prot, oneline_temp, other_condition);
		}
		
		(*agent_prot_map)[index] = uni_prot;
		uniform_r_prots->push_back(uni_prot); 	  
	  } else {
		vector<BDD*>* new_vec = new vector<BDD*>;
		new_vec->push_back(new BDD((*para->vprot)[index]));
		uniform_r_prots->push_back(new_vec);
	  }
	}
	
	vector<bdd_parameters>* para_vec = new vector<bdd_parameters>;
	bdd_parameters* p = new bdd_parameters(*para);
	p->vRT = new vector<BDD>;
	p->vprot = new vector<BDD>;
	p->in_st = new BDD(*para->in_st);
	
	BDD result = para->bddmgr->bddOne();

	modal_formula* new_formula = this->ast2formula_CTL(para);
	BDD final_result = transform_uni_for_atl_empty(uniform_r_prots,0, p, para_vec, result, *new_formula);
	
	delete p->vRT;
	delete p->vprot;
	delete p->in_st;
	delete new_formula;
	delete uniform_r_prots;
	return final_result;
  } 
  else{
	vector<unsigned int>* index_vec_in = new vector<unsigned int>;
    vector<unsigned int>* index_vec_out = new vector<unsigned int>;
  	map<unsigned int, vector< BDD*>* >* uniform_rin_prots = new map<unsigned int, vector< BDD*>* >;
	map<unsigned int, vector< BDD*>* >* uniform_rout_prots = new map<unsigned int, vector< BDD*>* >;
	
  	map < string, set < string > >::iterator gi = is_groups->find(grp);
    set < string > names_g = gi->second; 
	vector<basic_agent*>* agents_in = new vector<basic_agent*>;

	for (map < string, basic_agent * >::iterator i = is_agents->begin(); i != is_agents->end(); i++) {
	  unsigned int index = (*is_agents_index)[i->second->get_name()];
	  basic_agent* ag = i->second;  	
	  
      if(names_g.find(i->first) != names_g.end()){ //agent in group
        agents_in->push_back(ag);
		if(ag->get_strategy_type()!="isr"&&ag->get_strategy_type()!="ior"){ //agent_IR/Ir in group 
		  if(agent_prot_map->find(index)==agent_prot_map->end()){
			(*agent_prot_map)[index] = ag->get_abs_protocol_Ir(para);
			(*uniform_rin_prots)[index] = (*agent_prot_map)[index];
		  } else{
			(*uniform_rin_prots)[index] = (*agent_prot_map)[index];
		  }
		} else { 
		  if(agent_prot_map->find(index)==agent_prot_map->end()){
			vector<BDD*>* uni_prot = new vector<BDD*>;
			BDD oneline_temp = para->bddmgr->bddZero();
			BDD* other_condition = new BDD(*para->original_reach);
			if(ag->get_protocol()->size()==0){
			  BDD* one_bdd = new BDD(para->bddmgr->bddOne());
			  uni_prot->push_back(one_bdd);
			} else{
			  ag->encode_protocol_ir(para, 0, uni_prot, oneline_temp, other_condition);
			}
			(*agent_prot_map)[index] = uni_prot;
			(*uniform_rin_prots)[index] = (*agent_prot_map)[index];
		  } else{
			(*uniform_rin_prots)[index] = (*agent_prot_map)[index];
		  }
		}
		index_vec_in->push_back(index);
      }
	  else{ //agent out group
	  	if(ag->get_strategy_type()=="Ir"){
		  if(agent_prot_map->find(index)==agent_prot_map->end()){
			(*agent_prot_map)[index] = ag->get_abs_protocol_Ir(para);
			(*uniform_rout_prots)[index] = (*agent_prot_map)[index];
		  } else{
			(*uniform_rout_prots)[index] = (*agent_prot_map)[index];
		  }
	    }
	    else if(ag->get_strategy_type()=="isr"||ag->get_strategy_type()=="ior") { 
		  if(agent_prot_map->find(index)==agent_prot_map->end()){
			vector<BDD*>* uni_prot = new vector<BDD*>;
			BDD oneline_temp = para->bddmgr->bddZero();
			BDD* other_condition = new BDD(*para->original_reach);
			if(ag->get_protocol()->size()==0){
			  BDD* one_bdd = new BDD(para->bddmgr->bddOne());
			  uni_prot->push_back(one_bdd);
			} else{
			  ag->encode_protocol_ir(para, 0, uni_prot, oneline_temp, other_condition);
			}
			
			(*agent_prot_map)[index] = uni_prot;
			(*uniform_rout_prots)[index] = (*agent_prot_map)[index];
		  } else{
			(*uniform_rout_prots)[index] = (*agent_prot_map)[index];
		  }
		}
	    else{
		  unsigned int index = (*is_agents_index)[i->second->get_name()];
		  vector<BDD*>* new_vec = new vector<BDD*>;
		  new_vec->push_back(new BDD((*para->vprot)[index]));
		  (*uniform_rout_prots)[index] = new_vec;
	    }
		index_vec_out->push_back(index);
	  }
	}

	vector<bdd_parameters>* para_vec_in = new vector<bdd_parameters>;
	bdd_parameters* p_in = new bdd_parameters(*para);
	p_in->vRT = new vector<BDD>;
	p_in->vprot = new vector<BDD>;
	p_in->vevol = new vector<BDD>(*para->vevol);
//	p_in->in_st = new BDD(*para->in_st);
	
	transform_uni_for_atl_grp_in(uniform_rin_prots,index_vec_in, 0, p_in, para_vec_in);
	delete p_in->vRT;
	delete p_in->vprot;
	delete p_in->vevol;
//	delete p_in->in_st;

	vector<bdd_parameters>* para_vec_out = new vector<bdd_parameters>;
	bdd_parameters* p_out = new bdd_parameters(*para);
	p_out->vRT = new vector<BDD>;
	p_out->vprot = new vector<BDD>;
	p_out->vevol = new vector<BDD>(*para->vevol);
	

	if(index_vec_out->size()!=0)
	  transform_uni_for_atl_grp_out(uniform_rout_prots,index_vec_out, 0, p_out, para_vec_out);

	delete p_out->vRT;
	delete p_out->vprot;
	delete p_out->vevol;

	BDD final_result = para->bddmgr->bddZero();
	modal_formula* sub_formula = this->ast2formula_CTL(para);
	
	for(unsigned int i=0;i<para_vec_in->size();i++){
	  bdd_parameters para_in = (*para_vec_in)[i];
	  if(!if_nest){
		BDD in_st = *para->in_st;		
		BDD all_equiv = SCGS_check_GK_3(in_st, grp, para);
	    para_in.in_st = new BDD(in_st);
		BDD tmp = lemma2_calculate(para, &para_in, para_vec_out,*sub_formula,grp);
		
		if(all_equiv*tmp==all_equiv){
		  final_result+=in_st;
		  break;
		}
	  }

	  else{
		for(unsigned int k=0;k<para->vec_reach->size();k++){
		  BDD in_st = (*para->vec_reach)[k];
		  BDD all_equiv = SCGS_check_GK_3(in_st, grp, para);
		  para_in.in_st = new BDD(in_st);
		  BDD tmp = lemma2_calculate(para, &para_in, para_vec_out,*sub_formula,grp);
		  if(all_equiv*tmp==all_equiv){
			final_result+=in_st;		
		  }
		}
	  }
	  delete para_in.vprot;
	  delete para_in.vRT;
	  delete para_in.vevol;
	  delete para_in.in_st;
	}
	
	delete para_vec_out;
	delete para_vec_in;	
	delete agents_in;
	delete uniform_rin_prots;
	delete uniform_rout_prots;
	
	delete index_vec_in;
	delete index_vec_out;
	
	return final_result;
  }
}


BDD 
modal_formula_ast::check_simple_ast(bdd_parameters * para,string grp, bool if_nest)
{
  cout<<"we use lemma 4 to check ATL"<<endl;
  string name, phi_name, phi_fn;
  BDD result;
  name = to_string();
  if (grp=="none"||grp=="Empty") {
	phi_name = this->to_string();
  }	else{
	modal_formula_ast * phi = (modal_formula_ast *) obj[1];
	phi_name = phi->to_string();
  }

  //need change it to your goal-tool's path !!!
  string cmd_ltl2buchi=".../goal-tool/gc translate -m ltl2ba -sf -sb -rbm -o \"data/my_buchi.gff\" \""+ phi_name+"\"";
  system(cmd_ltl2buchi.c_str()); 
  cout<<endl;

  //need change it to your goal-tool's path !!!
  string cmd_bu2DPA = ".../goal-tool/gc convert -t dpw -o  \"data/my_dpa.dpa\" \"data/my_buchi.gff\"";

  system(cmd_bu2DPA.c_str());
  cout<<endl;
  pg_handler* pg_hdlr = new pg_handler(grp,para);
  result = pg_hdlr->pg_solve(if_nest);
  delete(pg_hdlr);
  return result;
}


BDD 
modal_formula_ast::check_formula_ast(bdd_parameters * para, bool if_nest, bool atl_pg)
{
  string name,grp;
  BDD result;
  Object *id;
  name = to_string();
  BDD original_reach = *para->original_reach;
  switch (op) {
    case 0:{
	  name = ((atomic_proposition *) obj[0])->get_proposition(); 
	  if(options["nobddcache"] == 0)
	    if (para->BDD_cache->find(name) != para->BDD_cache->end()){
		  (*is_new_evaluation)[name]=(*para->BDD_cache)[name];
		  return ((*para->BDD_cache)[name]);
		}

	  bool_expression *simple = is_evaluation->find(name)->second;
	  result = simple->encode_bdd_flat(para, para->bddmgr->bddOne()) * all_reach;
	  (*is_new_evaluation)[name]=result;
	  if(options["nobddcache"] == 0)
		(*para->BDD_cache)[name] = result;
	  break;
	}
  	case 1:{ // AND
  	  result = ((modal_formula_ast *) obj[0])->check_formula_ast(para,if_nest,atl_pg) *
	    ((modal_formula_ast *) obj[1])->check_formula_ast(para,if_nest, atl_pg);
	  break;
	}
  	case 2:{ // OR
	  result = ((modal_formula_ast *) obj[0])->check_formula_ast(para,if_nest,atl_pg) +
				((modal_formula_ast *) obj[1])->check_formula_ast(para,if_nest,atl_pg);
	  break;
	}
	
  	case 3:{		// NOT
	  result = !((modal_formula_ast *) obj[0])->check_formula_ast(para,if_nest,atl_pg) * all_reach;
	  break;
  	}

	case 4:{ // IMPLIES
	  BDD res1 = !(((modal_formula_ast *) obj[0])->check_formula_ast(para,if_nest,atl_pg)) * all_reach;
      BDD res2 = ((modal_formula_ast *) obj[1])->check_formula_ast(para,if_nest,atl_pg);
      result = res1 + res2;
      break;
	}
  	case 5:{     // X
	  if(options["nobddcache"] == 0)
		if (para->BDD_cache->find(name) != para->BDD_cache->end()){
		  return ((*para->BDD_cache)[name]);
	    }
	  
	  bool if_pure = this->check_pure_ltl();
	  if (if_pure){ 
		result = this->check_simple_ast(para,"none",if_nest);
		if(options["nobddcache"] == 0 && if_nest)
		  (*para->BDD_cache)[name] = result;
	  }
	  else{
	  	modal_formula_ast * pure_ltl = ((modal_formula_ast *) obj[0])->reduce2pureltl(para,atl_pg);
		modal_formula_ast * reduced2simple = new modal_formula_ast(5,pure_ltl);
		result = reduced2simple->check_simple_ast(para,"none",if_nest);	
		if(options["nobddcache"] == 0 && if_nest)
		  (*para->BDD_cache)[name] = result;
	  }
	  break;
	}
  	case 7:{      // G
	  if(options["nobddcache"] == 0)
		if (para->BDD_cache->find(name) != para->BDD_cache->end()){
		  return ((*para->BDD_cache)[name]);
		}

	  bool if_pure = this->check_pure_ltl();
	  if (if_pure){
		result = this->check_simple_ast(para,"none",if_nest);
		if(options["nobddcache"] == 0 && if_nest)
		  (*para->BDD_cache)[name] = result;
	  }
	  else{
		modal_formula_ast * pure_ltl = ((modal_formula_ast *) obj[0])->reduce2pureltl(para,atl_pg);
		modal_formula_ast * reduced2simple = new modal_formula_ast(7,pure_ltl);
		result = reduced2simple->check_simple_ast(para,"none",if_nest);
		if(options["nobddcache"] == 0 && if_nest)
		  (*para->BDD_cache)[name] = result;
	  }
	  break;
	}
  	case 6:{      // F
  	  if(options["nobddcache"] == 0)
	    if (para->BDD_cache->find(name) != para->BDD_cache->end()){
		  return ((*para->BDD_cache)[name]);
		}

	  bool if_pure = this->check_pure_ltl();
	  if (if_pure){ 
		result = this->check_simple_ast(para,"none",if_nest);
		if(options["nobddcache"] == 0 && if_nest)
	      (*para->BDD_cache)[name] = result;
	  }
	  else{
		modal_formula_ast * pure_ltl = ((modal_formula_ast *) obj[0])->reduce2pureltl(para,atl_pg);
		modal_formula_ast * reduced2simple = new modal_formula_ast(6,pure_ltl);
		result = reduced2simple->check_simple_ast(para,"none",if_nest);
		if(options["nobddcache"] == 0 && if_nest)
		  (*para->BDD_cache)[name] = result;
	  }
   	  break;
	}  	
    case 8:{ // U
	  if(options["nobddcache"] == 0)
		if (para->BDD_cache->find(name) != para->BDD_cache->end()){
		  return ((*para->BDD_cache)[name]);
		}

	  bool if_pure1 = ((modal_formula_ast *) obj[0])->check_pure_ltl();
	  bool if_pure2 = ((modal_formula_ast *) obj[1])->check_pure_ltl();
	  if(if_pure1&&if_pure2){
		result = this->check_simple_ast(para,"none", if_nest);
	  }
	  else{
		modal_formula_ast * pure_ltl1 = ((modal_formula_ast *) obj[0])->reduce2pureltl(para,atl_pg);
		modal_formula_ast * pure_ltl2 = ((modal_formula_ast *) obj[0])->reduce2pureltl(para,atl_pg);
		modal_formula_ast * reduced2simple = new modal_formula_ast(8,pure_ltl1,pure_ltl2);
		result = reduced2simple->check_simple_ast(para,"none",if_nest);
	  }
      break;
	}  
	case 9:{ // R
	  if(options["nobddcache"] == 0)
		if (para->BDD_cache->find(name) != para->BDD_cache->end()){
		  return ((*para->BDD_cache)[name]);
		}

	  bool if_pure1 = ((modal_formula_ast *) obj[0])->check_pure_ltl();
	  bool if_pure2 = ((modal_formula_ast *) obj[1])->check_pure_ltl();
	  if(if_pure1&&if_pure2){
		result = this->check_simple_ast(para,"none", if_nest);
	  }
	  else{
		modal_formula_ast * pure_ltl1 = ((modal_formula_ast *) obj[0])->reduce2pureltl(para,atl_pg);
		modal_formula_ast * pure_ltl2 = ((modal_formula_ast *) obj[0])->reduce2pureltl(para,atl_pg);
		modal_formula_ast * reduced2simple = new modal_formula_ast(9,pure_ltl1,pure_ltl2);
		result = reduced2simple->check_simple_ast(para,"none",if_nest);
	  }
      break;
	}
	case 10:{      // K	
	  if(options["nobddcache"] == 0)
	    if (para->BDD_cache->find(name) != para->BDD_cache->end()){
			return ((*para->BDD_cache)[name]);
		}
	  
	  id = ((modal_formula_ast *) obj[0])->get_operand(0);
      string individual_name = ((atomic_proposition *) id)->get_proposition();
	  BDD sub_formula_result = ((modal_formula_ast *) obj[1])->check_formula_ast(para,1,atl_pg);	  
	  BDD af = !sub_formula_result * all_reach; 
	  result = sub_formula_result - SCGS_get_nK_states(&af, individual_name, para); 
	  string new_ap_hash = "new_eva"+ int2string(is_new_evaluation->size());
	  pair<string, BDD> p1(new_ap_hash,result);
	  pair<string,string> p2(name,new_ap_hash);
	  is_new_evaluation->insert(p1);
	  shash_map->insert(p2);		  
	  if(options["nobddcache"] == 0)
		(*para->BDD_cache)[name] = result;
   	  break;
	}  	
	case 11:{      // E
	  if(options["nobddcache"] == 0)
	    if (para->BDD_cache->find(name) != para->BDD_cache->end()){
			return ((*para->BDD_cache)[name]);
		}
	  
	  id = ((modal_formula_ast *) obj[0])->get_operand(0);
      string grp_name = ((atomic_proposition *) id)->get_proposition();
	  BDD sub_formula_result = ((modal_formula_ast *) obj[1])->check_formula_ast(para,1,atl_pg);
	  result = SCGS_check_GK(sub_formula_result, grp_name, para);	  
	  string new_ap_hash = "new_eva"+ int2string(is_new_evaluation->size());
	  pair<string, BDD> p1(new_ap_hash,result);
	  pair<string,string> p2(name,new_ap_hash);
	  is_new_evaluation->insert(p1);
	  shash_map->insert(p2);		  

	  if(options["nobddcache"] == 0)
		(*para->BDD_cache)[name] = result;
  	  
   	  break;
	}
	case 12:{      // C
	  if(options["nobddcache"] == 0)
	    if (para->BDD_cache->find(name) != para->BDD_cache->end())
			return ((*para->BDD_cache)[name]);
	
	  id = ((modal_formula_ast *) obj[0])->get_operand(0);
      string grp_name = ((atomic_proposition *) id)->get_proposition();
	  BDD sub_formula_result = ((modal_formula_ast *) obj[1])->check_formula_ast(para,1,atl_pg);	
	  result = SCGS_check_GCK(sub_formula_result, grp_name, para);
	  string new_ap_hash = "new_eva"+ int2string(is_new_evaluation->size());
	  pair<string, BDD> p1(new_ap_hash,result);
	  pair<string,string> p2(name,new_ap_hash);
	  is_new_evaluation->insert(p1);
	  shash_map->insert(p2);		  

	  if(options["nobddcache"] == 0)
		(*para->BDD_cache)[name] = result;
  	  
   	  break;
	}
	case 13:{      // D
	  if(options["nobddcache"] == 0)
	    if (para->BDD_cache->find(name) != para->BDD_cache->end())
			return ((*para->BDD_cache)[name]);
		
	  id = ((modal_formula_ast *) obj[0])->get_operand(0);
      string grp_name = ((atomic_proposition *) id)->get_proposition();
	  BDD sub_formula_result = ((modal_formula_ast *) obj[1])->check_formula_ast(para,1,atl_pg);
	  result = SCGS_check_DK(sub_formula_result, grp_name, para)*sub_formula_result;
	  string new_ap_hash = "new_eva"+ int2string(is_new_evaluation->size());
	  pair<string, BDD> p1(new_ap_hash,result);
	  pair<string,string> p2(name,new_ap_hash);
	  is_new_evaluation->insert(p1);
	  shash_map->insert(p2);		  

	  if(options["nobddcache"] == 0)
		(*para->BDD_cache)[name] = result;
  	  
   	  break;
	}  	
 	case 14:{	// <A>ltl
 	  if(options["nobddcache"] == 0)
	    if (para->BDD_cache->find(name) != para->BDD_cache->end()){
			return ((*para->BDD_cache)[name]);
		}

	  id = ((modal_formula_ast *) obj[0])->get_operand(0);
      grp = ((atomic_proposition *) id)->get_proposition();

	  //choose lemma2 or lemma4
	  if(atl_pg){ //choose lemma4
		string obj1 = ((modal_formula_ast *) obj[1])->to_string();
		bool if_simple = ((modal_formula_ast *) obj[1])->check_pure_ltl();
		if (if_simple) {
		  result = this->check_simple_ast(para,grp, if_nest);
		  string new_ap_hash = "new_eva"+ int2string(is_new_evaluation->size());
		  pair<string, BDD> p1(new_ap_hash,result);
		  pair<string,string> p2(name,new_ap_hash);
		  is_new_evaluation->insert(p1);
		  shash_map->insert(p2);
		  
		} else{
		  modal_formula_ast * pure_ltl = ((modal_formula_ast *) obj[1])->reduce2pureltl(para,atl_pg); 
		  modal_formula_ast * reduced2simple = new modal_formula_ast(14,(modal_formula_ast *) obj[0],pure_ltl);
		  result = reduced2simple->check_simple_ast(para,grp,if_nest);
		}
	  } 
	  else { //choose lemma2
	    modal_formula_ast * simple_atl = this->reduce2simple_atl(para,if_nest,0);	
		result = simple_atl->check_simple_atl(para,grp,if_nest);
	  } 						

	  if(options["nobddcache"] == 0 && if_nest)
		(*para->BDD_cache)[name] = result;

	  break;
 	}
  }
  return result;
}

