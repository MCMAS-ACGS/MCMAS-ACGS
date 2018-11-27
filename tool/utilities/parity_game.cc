#include <ctime>
#include "types.hh"
#include "utilities.hh"
#include "atlk.hh"
#include <tuple>
#include <unistd.h>
#include <string>
#include <cstdio>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <sstream>
#include <queue>
#include <memory>
extern void free_cudd_memory(bdd_parameters *para);
extern void free_mcmas_memory(bdd_parameters *para);
extern map< string, vector< vector< BDD* >* >*> map_uniform_prots;
extern bool bool_result;
extern BDD result;
extern map< string, unsigned int >* is_agents_index;
extern map< string, BDD > * is_new_evaluation; 
extern map< string, string> * shash_map;
extern vector< basic_agent * >*agents;
extern vector<BDD>* all_reach_vec;
extern map<int,vector<BDD*>*>* agent_prot_map;


parity_game::parity_game(dpa_tree* hdl_dpaTree, string hdl_grp, bdd_parameters* hdl_para)
{       
  pg_st_p0 = new vector<pair<unsigned int, unsigned int>>; 
  pg_st_p1 = new vector<pair<unsigned int, unsigned int>>; 
  pg_init = new vector<unsigned int>;
  pg_trs = new map<unsigned int, pair<unsigned int, unsigned int>>;
  pg_colr = new multimap <unsigned int, unsigned int>;
  st_count = 0;
  tr_count = 0;
  dpaTree = hdl_dpaTree;
  grp = hdl_grp;
  para = hdl_para; 
  model_id=0;
}

parity_game::~parity_game()
{
  if(pg_trs!=NULL&&pg_trs->size()!=0){
	delete pg_trs;
  }
  if(pg_colr!=NULL&&pg_colr->size()!=0){
	delete pg_colr;
  }	
  if(pg_st_p0!=NULL&&pg_st_p0->size()!=0){
	delete pg_st_p0;
  }
  if(pg_st_p1!=NULL&&pg_st_p1->size()!=0){
	delete pg_st_p1;
  }
  if(pg_init!=NULL&&pg_init->size()!=0){
	delete pg_init;
  }
  if(all_pg_V!=NULL&&all_pg_V->size()!=0) {
  	for(map<unsigned int, pg_V3*>::iterator it = all_pg_V->begin(); it!=all_pg_V->end(); it++)
		delete it->second;
	all_pg_V->clear();
	delete all_pg_V;
  }
  delete dpaTree->dpaTrs;
  delete dpaTree->dpaSts;
  delete dpaTree->dpaColr;
  delete dpaTree->dpa_alpha;
  delete dpaTree;
}

unsigned int 
parity_game::addV(unsigned int player, unsigned int color, pg_V3* v){
  
  pair<unsigned int, unsigned int> p(st_count,color);
  if (player == 0)
  	pg_st_p0->push_back(p);
  else
  	pg_st_p1->push_back(p);

  // update color
  pair<unsigned int, unsigned int> c(color,st_count);
  pg_colr->insert(c);

  // update map
  pair<unsigned int, pg_V3*> p2(st_count,v);
  all_pg_V->insert(p2);

  // update init_set
  st_count = st_count + 1;
  
  return st_count;
  
}


void 
parity_game::addE(unsigned int sid_V0, unsigned int sid_V1){
  pair<unsigned int, unsigned int> p1(sid_V0, sid_V1);
  pair<unsigned int, pair<unsigned int, unsigned int> > p(tr_count,p1);
  pg_trs->insert(p);
  tr_count = tr_count + 1;
}


void 
parity_game::addV1(pg_V3 * v0, vector<basic_agent *>* agents_in,vector<basic_agent *>* agents_out, vector<bdd_parameters>* para_vec) {
  for (vector<bdd_parameters>::iterator i = para_vec->begin(); i!= para_vec->end(); i++) {
	pg_V3 * v1=new pg_V3;
	v1->my_mode = 1;
	v1->sid = st_count;
    v1->reach_id = v0->reach_id;
    v1->s_state = v0->s_state;
    v1->type = 1;   
	v1->f_r = v0->f_r;
	v1->p_state = -1;
	v1->father = v0->sid;
	v1->para_in = new bdd_parameters(*i);

	v1->ibdd = -1; 
	v1->Gset = new vector<map<string, map<unsigned int, string>*>*>;
//	v1->Gset = v0->Gset;
    nodes_processing.push(v1);	
	addV(1,0,v1); // st_count++
	addE(v0->sid,v1->sid);
  }
}

void
parity_game::addV2(vector<basic_agent*>* agents_ir_out, vector<basic_agent*>* agents_Ir_out, vector<basic_agent*>* agents_IR_in, bdd_parameters * para) { //deal one level one time --> 每次生成一整层同类型的node2
  bool agent_out_has_ir = !(agents_ir_out->size()==0);
  bool agent_out_has_Ir = !(agents_Ir_out->size()==0);
  
  while ((!nodes_processing.empty())&&(nodes_processing.front()->type!=2)) {
  	
	if (nodes_processing.front()->type==1) { // father is V1, G is empty
	  
	  unsigned int p0 = dpaTree->dpaInit;
	  pg_V3 * v1 = (pg_V3*) (nodes_processing.front());
	  BDD* s = v1->s_state;
	  vector<BDD*>* s_equi = get_equiv_state(para, s, grp);	  
	  s_equi->push_back(s);	

	  for (vector<BDD*>::iterator i = s_equi->begin() ; i!= s_equi->end(); i++) {	
	  	vector<vector<int>* >* countex = new vector<vector<int>* >;
	  	map<int, BDD*>* idbdd = new map<int, BDD*>;
	  	map<string, int>* bddid = new map<string, int>;
	  	vector<vector<transition* > >* cextr = new vector<vector<transition* > >;
      	BDD* new_init = new BDD(*(*i));
      
	  	SCGS_export_model(v1->para_in, new_init, countex, idbdd, cextr); 

	    for (map<int,BDD*>::iterator it = idbdd->begin(); it!=idbdd->end(); it++) {
	      string statr = state_to_str(*it->second, *para->v);
		  pair<string,int> p(statr,it->first);	  
		  bddid->insert(p);
	    }
	
	    model mm;
	  	mm.cextr = cextr;
	 	mm.idbdd = idbdd;
	  	mm.is_temp = new BDD(*(*i));
	  	mm.bddid = bddid;
	  	mm.model_id = model_id++;
	  	delete countex;
	  	delete new_init;	  

		string st_str = state_to_str(*(*i), *para->v);
		vector<map<string, map<unsigned int, string>*>*>* G = new vector<map<string, map<unsigned int, string>*>*>;
		pg_V3 *v2 = new pg_V3;
		v2->my_mode = 2;
		v2->sid=st_count;
		v2->reach_id = v1->reach_id;
		v2->s_state = *i;
		v2->type = 2;
		v2->f_r = mm;
		v2->ibdd = (*v2->f_r.bddid)[st_str];
		v2->p_state = p0;
		v2->Gset = G;
		v2->father = v1->sid;		  
		addV(0,(*dpaTree->dpaColr)[p0],v2);
		addE(v1->sid,v2->sid);
		
		nodes_processing.push(v2);
		  
		pair<unsigned int,unsigned int> p1(v2->reach_id,v2->f_r.model_id);
		tuple<pair<unsigned int,unsigned int>, int, int> t(p1,v2->ibdd,v2->p_state);
		pair<tuple<pair<unsigned int,unsigned int>, int, int>,unsigned int> p(t,v2->sid);
	  	nodes_processing_for_check.insert(p);
	  }	
	   nodes_processing.pop();
	}	
	
	else if (nodes_processing.front()->type==3) {		
 	  pg_V3 * v3 = nodes_processing.front();
	  BDD* s = v3->s_state;
	  int this_ibdd = v3->ibdd;
	  vector<unsigned int>* np_vec = get_next_p(v3,dpaTree);		
	  vector<map<string, map<unsigned int, string>*>*>* pre_Gset = v3->Gset;
	  vector <transition*> cur_id_trans = v3->f_R;		
	  set<int>* next_s_state_id = new set<int>;        
	  if((!agent_out_has_ir)&&(!agent_out_has_Ir)){ 	  
		for (unsigned int t = 0; t < cur_id_trans.size(); t++) {
		  transition* tr = cur_id_trans[t];
		  string to_state_string = state_to_str(*tr->getto(), *para->v);
		  int my_to_id = (*v3->f_r.bddid)[to_state_string];
		  next_s_state_id->insert(my_to_id);
		}
		  
		for(vector<unsigned int>::iterator it = np_vec->begin(); it< np_vec->end(); it++){
		  for(set<int>::iterator iter = next_s_state_id->begin(); iter!=next_s_state_id->end();iter++){
			pg_V3 * v2 = new pg_V3;
			v2->my_mode = 0;
			v2->sid = st_count;
			v2->reach_id = v3->reach_id;
			v2->s_state = (*v3->f_r.idbdd)[*iter];
			v2->type = 2;
			string st_str = state_to_str(*v2->s_state,*para->v);			 
			v2->f_r = v3->f_r;		 
			v2->ibdd = (*v2->f_r.bddid)[st_str]; 
			v2->p_state = *it;
			v2->father = v3->sid;
			v2->Gset = pre_Gset;
			pair<bool, unsigned int> p_result2 = check_processed_V2(v2);
			pair<bool, unsigned int> p_result3 = check_processing_V2(v2);				  
			bool ck2 = p_result2.first;
			bool ck3 = p_result3.first;
			unsigned int processed_id2 = p_result2.second;
			unsigned int processed_id3 = p_result3.second;
			  
			if(ck2){
			  addE(v3->sid, processed_id2);
			}
			else{
			  if(ck3)
			    addE(v3->sid, processed_id3);
			  else{
				addV(0, (*dpaTree->dpaColr)[*it],v2);
				addE(v3->sid,v2->sid);
			    nodes_processing.push(v2);
				
				pair<unsigned int,unsigned int> p1(v2->reach_id,v2->f_r.model_id);
		  		tuple<pair<unsigned int,unsigned int>, int, int> t(p1,v2->ibdd,v2->p_state);
		  		pair<tuple<pair<unsigned int,unsigned int>, int, int>,unsigned int> p(t,v2->sid);
	  	  		nodes_processing_for_check.insert(p);
			  }
			}
	      }
		}

		pair<unsigned int,unsigned int> p1(v3->reach_id,v3->f_r.model_id);
		tuple<pair<unsigned int,unsigned int>, int, int> t(p1,v3->ibdd,v3->p_state);
		pair<tuple<pair<unsigned int,unsigned int>, int, int>,unsigned int> p(t,v3->sid);
	  	nodes_processed.insert(p);
		nodes_processing.pop();
	  }
	  else {
		string from_state_string = state_to_str(*v3->s_state, *para->v);
		int my_from_id = (*v3->f_r.bddid)[from_state_string];		  
		map<string,vector<transition*> >* to_map = new map<string,vector<transition*> >;
		for (vector<transition*>::iterator iter=cur_id_trans.begin(); iter!=cur_id_trans.end(); iter++) {
		  BDD* next_state = (*iter)->getto();
		  string next_state_str = state_to_str(*next_state, *para->v);
		  if(to_map->find(next_state_str)!=to_map->end()){
		    (*to_map)[next_state_str].push_back(*iter);
		  }
		  else{
		    vector<transition*> new_vec;
		    new_vec.push_back(*iter);
		    pair <string, vector<transition*> > p (next_state_str,new_vec);
		    to_map->insert(p);
		  }
		}
		
		for(map<string,vector<transition*> >::iterator iter=to_map->begin();iter!=to_map->end();iter++){
		  vector<map<string, map<unsigned int, string>*>*>* new_Gset = new vector<map<string, map<unsigned int, string>*>*>;
		  map<string,vector<transition* > >* Gset_map = new map<string,vector<transition*> >;
		  for(unsigned int jk=0; jk<iter->second.size();jk++){
		  	transition* tr_cur = (iter->second)[jk];
		  	BDD * label = tr_cur->getlabel();
			string s="";
			for (vector<basic_agent*>::iterator i = agents_Ir_out->begin();i!=agents_Ir_out->end();i++) {
			  s += (*i)->action_to_str(*label, *para->a);
			}
			for (vector<basic_agent*>::iterator i = agents_ir_out->begin();i!=agents_ir_out->end();i++) {
			  s += (*i)->action_to_str(*label, *para->a);
			}
  			if (Gset_map->find(s)!=Gset_map->end())   
			  (*Gset_map)[s].push_back(tr_cur);
			else {
			  vector <transition*> trs_vec;
			  trs_vec.push_back(tr_cur);
			  pair <string, vector <transition*> > p (s,trs_vec);
			  Gset_map->insert(p);
			}

		  }
		  
		  for(map<string,vector<transition*> >::iterator iter3=Gset_map->begin();iter3!=Gset_map->end();iter3++){
			if(pre_Gset->size()==0){ 
			  map<string, map<unsigned int, string>*>* g_prim=new map<string, map<unsigned int, string>*>;
			  transition* temp = iter3->second.at(0);
			  for (vector<basic_agent*>::iterator i = agents_Ir_out->begin();i!=agents_Ir_out->end();i++) {
				string s_action=(*i)->action_to_str(*temp->getlabel(), *para->a); 
				string s_name = (*i)->get_name();
				map<unsigned int,string>* agt_prot = new map<unsigned int,string>;
				(*agt_prot)[my_from_id]=s_action;
				(*g_prim)[s_name] = agt_prot;
				
			  }

			  for (vector<basic_agent*>::iterator i = agents_ir_out->begin();i!=agents_ir_out->end();i++) {
				string s_action=(*i)->action_to_str(*temp->getlabel(), *para->a); 
				string s_name = (*i)->get_name();
				map<unsigned int,string>* agt_prot = new map<unsigned int,string>;		  
				for(map<int,BDD*>::iterator i2 = v3->f_r.idbdd->begin(); i2!=v3->f_r.idbdd->end(); i2++){
			      string st_equi = (*i)->seeable_state_to_str(*i2->second, *para->v);
		          string st_v3 = (*i)->seeable_state_to_str(*v3->s_state, *para->v);
				  if(st_equi==st_v3){
				    (*agt_prot)[i2->first]=s_action;
				  }
				}
				
				(*g_prim)[s_name] = agt_prot;
			  }				
			  new_Gset->push_back(new map<string, map<unsigned int, string>*>(*g_prim));
			}
			else{
			  transition* temp = iter3->second.at(0);
			  for(unsigned int j=0;j<pre_Gset->size();j++){
				map<string, map<unsigned int, string>*>* g = (*pre_Gset)[j];
				map<string, map<unsigned int, string>*>* g_prim = check_compatible(my_from_id, v3, para, g,temp,agents_Ir_out,agents_ir_out);
				if(g_prim->size()!=0){
			      new_Gset->push_back(new map<string, map<unsigned int, string>*>(*g_prim));
			    }
			  }
			}
		  }
		  if(new_Gset->size()!=0){
			for(vector<unsigned int>::iterator it = np_vec->begin(); it< np_vec->end(); it++){
			  pg_V3 * v2 = new pg_V3;
			  v2->my_mode = 1;
			  v2->sid = st_count;
			  v2->reach_id = v3->reach_id;
			  v2->s_state = iter->second.at(0)->getto();
			  v2->type = 2;
			  v2->f_r = v3->f_r;	  
			  string st_str = state_to_str(*v2->s_state,*para->v);	
			  v2->ibdd = (*v2->f_r.bddid)[st_str];
			  v2->p_state = *it;
			  v2->father = v3->sid;
			  v2->Gset = new_Gset;
			  pair<bool, unsigned int> p_result2 = check_processed_V2(v2);
			  pair<bool, unsigned int> p_result3 = check_processing_V2(v2);			  
              bool ck2 = p_result2.first;
			  bool ck3 = p_result3.first;
			  unsigned int processed_id2 = p_result2.second;
			  unsigned int processed_id3 = p_result3.second;
			  if(ck2){
				addE(v3->sid, processed_id2);
			  }
			  else{
				if(ck3)
				  addE(v3->sid, processed_id3);
				else{
				  addV(0, (*dpaTree->dpaColr)[*it],v2);
				  addE(v3->sid,v2->sid);
				  nodes_processing.push(v2);								
				  pair<unsigned int,unsigned int> p1(v2->reach_id,v2->f_r.model_id);
				  tuple<pair<unsigned int,unsigned int>, int, int> t(p1,v2->ibdd,v2->p_state);
				  pair<tuple<pair<unsigned int,unsigned int>, int, int>,unsigned int> p(t,v2->sid);
				  nodes_processing_for_check.insert(p);
				}
			  }
			}
		  }
		  else{
			delete new_Gset;
		  }
		}
		pair<unsigned int,unsigned int> p1(v3->reach_id,v3->f_r.model_id);
		tuple<pair<unsigned int,unsigned int>, int, int> t(p1,v3->ibdd,v3->p_state);  
		pair<tuple<pair<unsigned int,unsigned int>, int, int>,unsigned int> p(t,v3->sid);
	  	nodes_processed.insert(p);
		nodes_processing.pop();
	  }
	}
	else {
	  cout << "There are some error(s) when judging the front node type in queue!" << endl;
	  free_mcmas_memory(NULL);
	  exit(-1);
	}
  }
}

void
parity_game::addV3(bool agent_in_has_IR, vector<basic_agent*>* agents_IR_in, bdd_parameters* para) {
  unsigned char t = nodes_processing.front()->type;
  if (t == 2) {	
	while ((!nodes_processing.empty())&&(nodes_processing.front()->type==2)) {
	  pg_V3 * v2 = (nodes_processing.front());
	  map<string, vector <transition*> > *  f_R_map = split_by_Rin(v2, grp, agent_in_has_IR, para); 
	  if(f_R_map!=NULL){
		for (map<string, vector <transition*> >::iterator it = f_R_map->begin(); it != f_R_map->end(); it++){
		  if(it->second.size()==0)
			continue;
		
		  pg_V3 * v3 = new pg_V3;
		  v3->my_mode = 0;
		  v3->sid = st_count;
		  v3->reach_id = v2->reach_id;
		  v3->s_state = v2->s_state;
		  v3->type = 3;
		  v3->f_r = v2->f_r;
		  v3->ibdd = (*v3->f_r.bddid)[state_to_str(*v3->s_state,*para->v)];
		  v3->p_state = v2->p_state;
		  v3->father = v2->sid;
		  v3->Gset = v2->Gset;		    		    
		  v3->f_R = it->second;
		  pair<bool, unsigned int> p_result2 = check_processed(v3,agents_IR_in);
		  pair<bool, unsigned int> p_result3 = check_processing(v3,agents_IR_in);			  
		  bool ck2 = p_result2.first;
		  bool ck3 = p_result3.first;
		  unsigned int processed_id2 = p_result2.second;
		  unsigned int processed_id3 = p_result3.second;
		  if(ck2){ 
			addE(v2->sid, processed_id2);
		  }
		  else{
			if(ck3)
			  addE(v2->sid, processed_id3);
			else{
			  addV(1, (*dpaTree->dpaColr)[v3->p_state],v3);
			  addE(v2->sid,v3->sid);
			  nodes_processing.push(v3);
			  pair<unsigned int,unsigned int> p1(v3->reach_id,v3->f_r.model_id);
			  tuple<pair<unsigned int,unsigned int>, int, int> t(p1,v3->ibdd,v3->p_state);
			  pair<tuple<pair<unsigned int,unsigned int>, int, int>,unsigned int> p(t,v3->sid);
			  nodes_processing_for_check.insert(p);
			}
		  }
		}

		pair<unsigned int,unsigned int> p1(v2->reach_id,v2->f_r.model_id);
		tuple<pair<unsigned int,unsigned int>, int, int> t(p1,v2->ibdd,v2->p_state);
		pair<tuple<pair<unsigned int,unsigned int>, int, int>,unsigned int> p(t,v2->sid);
		  
	  	nodes_processed.insert(p);
		nodes_processing.pop();
	  }
	  else{
		cout << "There are some error(s) when get f_R_map!!" << endl;
		free_mcmas_memory(NULL);
		exit(-1);
	  }
  	}
  }
  else {
    cout << "There are some error(s) when adding new pg_V3!" << endl;
	free_mcmas_memory(NULL);
	exit(-1);
  }
}


vector< pair <unsigned int, unsigned int> > * 
parity_game::get_st_p0(){

  return pg_st_p0;

}


vector< pair <unsigned int, unsigned int> > * 
parity_game::get_st_p1(){

  return pg_st_p1;

}


vector<unsigned int> * 
parity_game::get_init(){

  return pg_init;

}


map<unsigned int, pair<unsigned int, unsigned int>> * 
parity_game::get_trs(){

  return pg_trs;

}

map<unsigned int, pg_V3*>*
parity_game::get_pg_nodes(){

  return all_pg_V;

}


multimap<unsigned int, unsigned int> * 
parity_game::get_colr(){

  return pg_colr;

}

pair<bool, unsigned int> 
parity_game::check_processed_V2(pg_V3 * v2){
  pair<unsigned int,unsigned int> pp(v2->reach_id,v2->f_r.model_id);
  tuple<pair<unsigned int,unsigned int>, int, int> t(pp,v2->ibdd,v2->p_state);
  
  if (nodes_processed.find(t)!=nodes_processed.end()){
    for (multimap<tuple<pair<unsigned int,unsigned int>, int, int>, unsigned int>::iterator j = nodes_processed.lower_bound(t); j!=nodes_processed.upper_bound(t); j++){  
	  unsigned int node_id = j->second;
	  if((*all_pg_V)[node_id]->type!=2){
		continue;
	  }
	  else{
	  	vector<map<string, map<unsigned int, string>*>*>* m1=v2->Gset;
		vector<map<string, map<unsigned int, string>*>*>* m2=(*all_pg_V)[node_id]->Gset;
	    if( (m1!=NULL)&& (m2!=NULL)){
		  bool b = check_G_set(m1,m2,para);
		  if(b){
		  	pair<bool, unsigned int> p(true, node_id);
		    return p;
		  }
		}
		else if((m1==NULL)&& (m2==NULL)){
		  pair<bool, unsigned int> p(true, node_id);
		  return p;
		}
		else{
		  pair<bool, unsigned int> p(false, 0);
		  return p;
		}
	  }
	}
	pair<bool, unsigned int> p(false, 0);
	return p;
  }
  else{
	pair<bool, unsigned int> p(false, 0);
	return p;
  }
}


pair<bool, unsigned int> 
parity_game::check_processed(pg_V3 * v3, vector<basic_agent*>* agents_IR_in){ 
  pair<unsigned int,unsigned int> pp(v3->reach_id,v3->f_r.model_id);
  tuple<pair<unsigned int,unsigned int>, int, int> t(pp, v3->ibdd, v3->p_state);  
  
  if (nodes_processed.find(t)!=nodes_processed.end()){
  	for (multimap<tuple<pair<unsigned int,unsigned int>, int, int>, unsigned int>::iterator j = nodes_processed.lower_bound(t); j!=nodes_processed.upper_bound(t); j++){
      unsigned int node_id = j->second;
	  if((*all_pg_V)[node_id]->type!=3){
	  	continue;
	  }
	  else{
        vector<map<string, map<unsigned int, string>*>*>* m1 = v3->Gset;
	    vector<map<string, map<unsigned int, string>*>*>* m2 = (*all_pg_V)[node_id]->Gset;
	    vector<transition*> processed_f_R = (*all_pg_V)[node_id]->f_R;
		vector<transition*> this_f_R = v3->f_R;
		
	    if(m1==NULL&&m2==NULL){
	      bool f_R_check=true;
	      if(agents_IR_in->size()!=0){
		    f_R_check =check_f_R(processed_f_R, this_f_R, agents_IR_in, para);
		  }
		  if(f_R_check){
		    pair<bool, unsigned int> p(f_R_check, node_id);
		    return p;
		  }
		}
		else if(m1!=NULL&&m2!=NULL){
		  vector<transition*> processed_f_R = (*all_pg_V)[node_id]->f_R;
		  vector<transition*> this_f_R = v3->f_R;
		  bool b1 = check_f_R(processed_f_R, this_f_R, agents_IR_in, para);
		  bool b2 = check_G_set(m1,m2,para);
		  if(b1&&b2){
		  	pair<bool, unsigned int> p(true, node_id);
		  	return p;
		  }
		  else{
		  	continue;
		  }	
		}
		else
		  continue;
	  }	  
	}
	pair<bool, unsigned int> p(false, 0);
	return p;
  }
  else{
	pair<bool, unsigned int> p(false, 0);
	return p;
  }
}

pair<bool, unsigned int> 
parity_game::check_processing_V2(pg_V3 * v2){
  pair<unsigned int,unsigned int> pp(v2->reach_id,v2->f_r.model_id);
  tuple<pair<unsigned int,unsigned int>, int, int> t(pp,v2->ibdd,v2->p_state);

  if (nodes_processing_for_check.find(t)!=nodes_processing_for_check.end()){
    for (multimap<tuple<pair<unsigned int,unsigned int>, int, int>, unsigned int>::iterator j = nodes_processing_for_check.lower_bound(t); j!=nodes_processing_for_check.upper_bound(t); j++){  
	  unsigned int node_id = j->second;
	  if((*all_pg_V)[node_id]->type!=2){
		continue;
	  }
	  else{
	  	vector<map<string, map<unsigned int, string>*>*>* m1=v2->Gset;
		vector<map<string, map<unsigned int, string>*>*>* m2=(*all_pg_V)[node_id]->Gset;
	    if( (m1!=NULL)&& (m2!=NULL)){
		  bool b = check_G_set(m1,m2,para);
		  if(b){
		  	pair<bool, unsigned int> p(true, node_id);
		    return p;
		  }
		}
		else if((m1==NULL)&& (m2==NULL)){
		  pair<bool, unsigned int> p(true, node_id);
		  return p;
		}
		else{
		  pair<bool, unsigned int> p(false, 0);
		  return p;
		}
	  }
	}
	pair<bool, unsigned int> p(false, 0);
	return p;
  }
  else{
	pair<bool, unsigned int> p(false, 0);
	return p;
  }
}


pair<bool, unsigned int> 
parity_game::check_processing(pg_V3 * v3, vector<basic_agent*>* agents_IR_in){ 

  pair<unsigned int,unsigned int> pp(v3->reach_id,v3->f_r.model_id);
  tuple<pair<unsigned int,unsigned int>, int, int> t(pp, v3->ibdd, v3->p_state);  
  
  if (nodes_processing_for_check.find(t)!=nodes_processing_for_check.end()){
  	for (multimap<tuple<pair<unsigned int,unsigned int>, int, int>, unsigned int>::iterator j = nodes_processing_for_check.lower_bound(t); j!=nodes_processing_for_check.upper_bound(t); j++){
      unsigned int node_id = j->second;
	  if((*all_pg_V)[node_id]->type!=3){
	  	continue;
	  }
	  else{
        vector<map<string, map<unsigned int, string>*>*>* m1 = v3->Gset;
	    vector<map<string, map<unsigned int, string>*>*>* m2 = (*all_pg_V)[node_id]->Gset;
	    vector<transition*> processed_f_R = (*all_pg_V)[node_id]->f_R;
		vector<transition*> this_f_R = v3->f_R;
		
	    if(m1==NULL&&m2==NULL){
	      bool f_R_check=true;
	      if(agents_IR_in->size()!=0){
		    f_R_check =check_f_R(processed_f_R, this_f_R, agents_IR_in, para);

		  }
		  if(f_R_check){
		    pair<bool, unsigned int> p(f_R_check, node_id);
		    return p;
		  }
		}
		else if(m1!=NULL&&m2!=NULL){
		  vector<transition*> processed_f_R = (*all_pg_V)[node_id]->f_R;
		  vector<transition*> this_f_R = v3->f_R;
		  bool b1 = check_f_R(processed_f_R, this_f_R, agents_IR_in, para);
		  bool b2 = check_G_set(m1,m2,para);
		  if(b1&&b2){
		  	pair<bool, unsigned int> p(true, node_id);
		  	return p;
		  }
		  else{
		  	continue;
		  }
		}
		else
		  continue;
	  }	  
	}
	pair<bool, unsigned int> p(false, 0);
	return p;
  }
  else{
	pair<bool, unsigned int> p(false, 0);
	return p;
  }
}


BDD
parity_game::build_pg(bool if_nest)
{
  BDD pg_result=para->bddmgr->bddZero();
  unsigned int folder=20;
  all_pg_V = new map<unsigned int, pg_V3*>;
  vector<basic_agent * >* agents_in;
  vector<basic_agent * >* agents_out;
  vector<basic_agent * >* agents_ir_out=new vector<basic_agent*>;
  vector<basic_agent * >* agents_Ir_out=new vector<basic_agent*>;
  vector<basic_agent*> * agent_Ir_in = new vector<basic_agent*>;
  vector<basic_agent*> * agent_IR_in = new vector<basic_agent*>;  
  bool agent_out_has_ir = false;
  bool agent_out_has_Ir = false;
  bool agent_in_has_IR = false;
  vector< vector< BDD* >* >* uniform_rin_prots = NULL;
  vector<bdd_parameters>* para_vec = NULL;
  if (grp=="none"||grp=="Empty"){ 
	/* ltl, use agents */
  	agents_out = agents;
	agents_in = NULL;
    for (map < string, basic_agent * >::iterator i = is_agents->begin(); i != is_agents->end(); i++) {
	  if ((i->second->get_strategy_type()=="ior")||(i->second->get_strategy_type()=="isr")){
		agent_out_has_ir = true;
		agents_ir_out->push_back(i->second);
	  }
	  else if (i->second->get_strategy_type()=="Ir"){
		agent_out_has_Ir = true;
		agents_Ir_out->push_back(i->second);
	  }
	  else
	  	continue;
    }
  }
  
  else {
	/* ATL, use grp-->agents */
	vector< basic_agent * >* agents_in = new vector<basic_agent *>;
	vector< basic_agent * >* agents_out = new vector<basic_agent *>;
	map < string, set < string > >::iterator gi = is_groups->find(grp);
  	set < string > names_g = gi->second;  
	for (map < string, basic_agent * >::iterator i = is_agents->begin(); i != is_agents->end(); i++) {
      if (names_g.find(i->first) == names_g.end()) {
        agents_out->push_back(i->second);
		if ((i->second->get_strategy_type()=="ior")||(i->second->get_strategy_type()=="isr")){
			agent_out_has_ir = true;
			agents_ir_out->push_back(i->second);
		}
		else if (i->second->get_strategy_type()=="Ir"){
		  agent_out_has_Ir = true;
		  agents_Ir_out->push_back(i->second);
	    }
      }
      else {
        agents_in->push_back(i->second);
		if(i->second->get_strategy_type()=="IR"){
			agent_in_has_IR = true;
			agent_IR_in->push_back(i->second);
		}
	  } 
    }

    uniform_rin_prots = new vector< vector< BDD*>* >;
	for (vector<basic_agent*>::iterator i = agents->begin();i!=agents->end();i++) {
	  unsigned int index = (*is_agents_index)[(*i)->get_name()];
	  basic_agent* ag = *i;
	  if (names_g.find(ag->get_name()) == names_g.end()) {
		vector<BDD*>* new_vec = new vector<BDD*>;
		new_vec->push_back(&(*para->vprot)[index]);
		uniform_rin_prots->push_back(new_vec);
	  }
	  else if(ag->get_strategy_type()=="IR"){
		vector<BDD*>* new_vec = new vector<BDD*>;
		new_vec->push_back(&(*para->vprot)[index]);
		uniform_rin_prots->push_back(new_vec);
	  }
	  else if(ag->get_strategy_type()=="Ir"){
	  	if(agent_prot_map->find(index)==agent_prot_map->end()){
		  (*agent_prot_map)[index] = ag->get_abs_protocol_Ir(para);
		  uniform_rin_prots->push_back((*agent_prot_map)[index]);
		} else{
			uniform_rin_prots->push_back((*agent_prot_map)[index]);
	    }
		agent_Ir_in->push_back(ag);
	  }
	  else { 
		vector<BDD*>* uni_prot;
		
//	    uni_prot = ag->split_protocol((*para->vprot)[index],para);
//		cout<<"uni_prot size is: "<<uni_prot->size()<<endl;
//		uniform_rin_prots->push_back(uni_prot);

		BDD oneline_temp = para->bddmgr->bddZero();
		BDD* other_condition = new BDD(*para->original_reach);
		
		if(ag->get_protocol()->size()==0){
		  BDD* one_bdd = new BDD(para->bddmgr->bddOne());
		  uni_prot = new vector<BDD*>;
		  uni_prot->push_back(one_bdd);		
		} else{
		    if(agent_prot_map->find(index)==agent_prot_map->end()){
              uni_prot = new vector<BDD*>;
			  ag->encode_protocol_ir(para, 0, uni_prot, oneline_temp, other_condition);
			  (*agent_prot_map)[index] = uni_prot;
			} else{
			  uni_prot = (*agent_prot_map)[index];
	    	}	  
		}
		uniform_rin_prots->push_back(uni_prot); 
	  }
	}
	para_vec = new vector<bdd_parameters>;
	bdd_parameters* p = new bdd_parameters(*para);
	p->vRT = new vector<BDD>;
	transform_uni(uniform_rin_prots,0, p, para_vec);
	delete p->vRT;
  }

  
  unsigned int reach_id = 0;
  if(!if_nest){
  	for (int i = 0; i< *para->num_of_inits;i++) {  	
	  pg_V3* v0=new pg_V3;
	  v0->my_mode = 1;
	  v0->sid=st_count;
      v0->reach_id = reach_id;	
	  reach_id = reach_id+1;
 	  v0->s_state = new BDD(para->vec_reach->at(i));
	  v0->type = 0;	
      model v0_model;
	  v0_model.model_id = -1;
      v0->f_r = v0_model;
	
	  v0->Gset = new vector<map<string, map<unsigned int, string>*>*>;
	  v0->ibdd = -1;
	  v0->p_state = -1;	
	  pg_init->push_back(v0->sid); // update game's initial state set
	  addV(0,0,v0);

//	  vector< model > * f_r_in_models = get_rin_Str(reach_id-1,v0->s_state, grp, agent_Ir_in, para, para_vec);
	  addV1(v0,agents_in,agents_out,para_vec); 
	  addV2(agents_ir_out,agents_Ir_out,agent_IR_in,para); 	
      addV3(agent_in_has_IR, agent_IR_in, para);
	  while (!nodes_processing.empty()) {
	  	
	    if (nodes_processing.front()->type==2){
	      addV3(agent_in_has_IR, agent_IR_in,para);
	    }
	    else if(nodes_processing.front()->type==3){
	      addV2(agents_ir_out,agents_Ir_out,agent_IR_in,para);}
	  }
	}
  }
  else{
  	for (vector<BDD>::iterator i = para->vec_reach->begin(); i!=para->vec_reach->end();i++) {
	  pg_V3* v0=new pg_V3;
	  v0->my_mode = 1;
	  v0->sid=st_count;
      v0->reach_id = reach_id;	
	  reach_id = reach_id+1;
	  v0->s_state = new BDD(*i);
	  v0->type = 0;	
	  
      model v0_model;
	  v0_model.model_id = -1;
      v0->f_r = v0_model;
	  v0->Gset = new vector<map<string, map<unsigned int, string>*>*>;
	  v0->ibdd = -1;
	  v0->p_state = -1;	
	  pg_init->push_back(v0->sid); // update game's initial state set
	  addV(0,0,v0);

//	  vector< model > * f_r_in_models = get_rin_Str(reach_id-1,v0->s_state, grp, agent_Ir_in, para, para_vec);  
	  addV1(v0,agents_in,agents_out,para_vec);
	  addV2(agents_ir_out,agents_Ir_out,agent_IR_in,para);
      addV3(agent_in_has_IR, agent_IR_in, para);
	  while (!nodes_processing.empty()) {
	    if (nodes_processing.front()->type==2){
		  addV3(agent_in_has_IR, agent_IR_in,para);
	    }
	    else if(nodes_processing.front()->type==3){
	  	  addV2(agents_ir_out,agents_Ir_out,agent_IR_in,para);
		}
	  }
    }
  }
  
  if(para_vec!=NULL){
  	for(unsigned int i=0;i<para_vec->size();i++){
	  delete (*para_vec)[i].vRT;
	  delete (*para_vec)[i].vec_reach;
	  delete (*para_vec)[i].num_of_inits;
	  delete (*para_vec)[i].original_reach;
	}
  }

  bool atl_print = (options["ATLprint"] == 1); 
  if(atl_print){
  	//export the model info.
  	string filename ="model_export/interpret.dot";  
  	ofstream myfile(filename.c_str());      
  	if (myfile.is_open()) {
      myfile << "sid:  tuple = <state_string, reach_id, model_id, v3->ibdd, v3->p_state, v3->color>" << endl;
      for (map<unsigned int, pg_V3* >::iterator iter = all_pg_V->begin(); iter != all_pg_V->end(); iter++) {
	    int reach_id = iter->second->reach_id;
	    BDD init_ = (*para->vec_reach)[reach_id];
	    string init_s = "";
	    for (unsigned int i = 1; i < agents->size(); i++) {
          init_s+= (*agents)[i]->state_to_str(init_, *para->v);
	    }
        myfile << "sid: " << iter->first << "  tuple = <" <<init_s<<", "<<
        iter->second->reach_id <<", "<<
        iter->second->f_r.model_id << ", "<<iter->second->ibdd<<", " <<iter->second->p_state<<", "<<(*dpaTree->dpaColr)[iter->second->p_state]<<">"<< endl;
      } 
	  myfile << "\n";
      myfile.close();
    }
  }

  

  delete agents_ir_out;
  delete agents_Ir_out;
  delete agent_Ir_in;
  delete agent_IR_in; 
  return pg_result;
}
