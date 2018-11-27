/* ******************************************************************************************************************************
 *            MCMAS-ACGS --  Model Checker for Agents' Abilities Augmented Concurrent Game Structures (ACGS), an extension from MCMAS
 *
 *     Copyright (C) 2018
 *     This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License 
 *     as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.
 *     This model checker is a prototype tool for checing ATLK*, and hope it will be useful.
 *	
 ********************************************************************************************************************************/
#include <functional>
#include <unistd.h>
#include <sys/types.h>
#include <sched.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <setjmp.h>
#include <signal.h>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cctype>
#include <ctime>
#include "types.hh"
#include "utilities.hh"
#include "atlk.hh"
#include "mcmas-driver.hh"
#include "cuddObj.hh"
#include <sys/timeb.h>
#include <memory>
using namespace std;
vector< string * >*string_table;
vector< bool_expression * >*logic_expression_table;
vector< bool_expression * >*logic_expression_table1;
vector< variable * >*variable_table;
map< string, basic_agent * >*is_agents;
map< string, unsigned int >*is_agents_index;
vector< basic_agent * >*agents;
map< string, map< string, vector< BDD* >* >* >* integerBDDs = NULL;
map< string, map< string, BDD* >* >* enumerateBDDs = NULL;
BDD all_reach;
vector<BDD>* all_reach_vec;
map<int,vector<BDD*>*>* agent_prot_map; //for split strategy of agent_r(IR-->Ir)

map< string, bool_expression * >*is_evaluation;
map< string, BDD >*is_new_evaluation;
map< string, string >* shash_map;
bool_expression *is_istates = NULL;
map< string, set< string > >*is_groups;
vector< modal_formula > *is_formulae;
vector< modal_formula_ast > *is_formulae_ast;
double *time_vec=NULL;
vector< fairness_expression * >*is_fairness;
int obsvars_bdd_length;
int envars_bdd_length;
map< string, int >options;
string cex_prefix;    // Destination directory for counterexamples
int scount;     // a global counter for counterexamples.
int states_count = 0;
int actions_count = 0;
Cudd_ReorderingType REORDERING = CUDD_REORDER_GROUP_SIFT; //CUDD_REORDER_GROUP_SIFT_CONV;
bdd_parameters * parameters; /* copy of the single parameters for the signal handler */
bool force_atlk = false;
vector< vector< BDD* >* >* uniform_prots = NULL;
bool *satisfied = NULL;
bool *satisfied_ast = NULL;
unsigned int num_of_satisfied = 0;
double reachablestates = 0;
unsigned int num_of_strategies = 0;
string ufgroup_name = "";
bool global_consistency_check();
void exec_simulation(void *ptr);
void *compute_partial_state_space( void *ptr );
void allocate_bdd_variables(vector<BDD> *v, vector<ADD> *addv, 
                            vector<BDD> *pv, vector<ADD> *addpv,
                            vector<BDD> *a, Cudd *bddmgr);
BDD compute_reach(BDD in_st, vector<BDD> *v, vector<BDD> *pv, 
                  vector<BDD> *a, vector<BDD> *vRT, Cudd *bddmgr,
                  unsigned int *acounter1, int id, unsigned long *threadmem);
bool read_options(int argc, char *argv[]);
void print_help(void);
void mcmas_signal_handler(int signal);
void print_state(BDD state, vector<BDD> v);
void print_states(BDD states, vector<BDD> v, Cudd* bddmgr);
string state_to_str(BDD state, vector<BDD> v);
bool find_same_state(map< string, int >*statehash, string state);
bool is_valid_state(BDD state, vector<BDD> v);
void print_action(BDD state, vector<BDD> a);
void print_action_1(BDD state, vector<BDD> a);
bool is_valid_action(BDD state, vector<BDD> a);
BDD append_variable_BDDs(Cudd * bddmgr, vector<BDD> * v, BDD a);
BDD append_variable_BDD(Cudd * bddmgr, vector<BDD> * v, BDD a, int j);
void produce_witness(bdd_parameters *para, BDD state, string name);
void free_mcmas_memory(bdd_parameters *para);
void free_cudd_memory(bdd_parameters *para);
void my_clear_cex(vector< vector< int >*>* countex, map< int, BDD * >* idbdd, vector< vector< transition > >* cextr);
void clear_cex(vector< vector< int >*>* countex, map< int, BDD * >* idbdd, vector< vector< transition* >* >* cextr);
void my_delete_cex(vector< vector< int >*>* countex, map< int, BDD * >* idbdd, vector< vector< transition > >* cextr);
void delete_cex(vector< vector< int >*>* countex, map< int, BDD * >* idbdd, vector< vector< transition* >* >* cextr);
void do_model_checking(bdd_parameters * para);
void do_model_checking_ATL_ast(bdd_parameters * para);
map<string, map<string, vector<BDD*>* >* >* integer_variable_BDDs(Cudd * bddmgr, vector<BDD> * v);
BDD complete_integer_BDDs(Cudd * bddmgr, vector<BDD> * v, BDD a, map<string, map<string, vector<BDD*>* >* >* int_vars);

void
print_banner(void)
{
  cout <<
    "************************************************************************"
       << endl;
  cout << "                       MCMAS-ACGS v1.0.0 " << endl << endl;
  
  cout <<
    "************************************************************************"
       << endl << endl;
}

int
main(int argc, char *argv[])
{
  struct timeb tmb;
  ftime(&tmb);

  struct sigaction sigact;
  sigact.sa_handler = mcmas_signal_handler;
  sigemptyset(&sigact.sa_mask);
  sigact.sa_flags = 0;

  /* signals we want to catch */
  sigaction(SIGINT, &sigact, 0); /* interrupt */
  sigaction(SIGPIPE, &sigact, 0); /* broken pipe, used for timeouts */
  sigaction(SIGABRT, &sigact, 0); /* abort */
  sigaction(SIGTERM, &sigact, 0); /* term, debatable if we can actually catch this */

  unsigned long threadmem = 0;
  std::string filename;
  string s;
  mcmas_driver driver;
  
  if (argc < 2) {
    print_banner();
    print_help();
    exit(1);
  }

  cex_prefix = "";
  if (read_options(argc, argv))
    exit(1);

  if (options["quiet"] == 0) {
    print_banner();
    cout << "Command line:";
    for(int i = 0; i < argc; i++) {
      cout << " " << argv[i];
    }
    cout << endl << endl;
  }  

  is_agents = new map< string, basic_agent * >;
  is_agents_index = new map< string, unsigned int >;
  agents = new vector< basic_agent * >;
  is_evaluation = new map< string, bool_expression * >;
  is_new_evaluation = new map< string, BDD >;
  shash_map = new map< string, string>;
  agent_prot_map = new map<int,vector<BDD*>*>;
  is_groups = new map< string, set< string > >;
  is_formulae = new vector< modal_formula >;
  is_formulae_ast = new vector< modal_formula_ast >;
  is_fairness = new vector< fairness_expression * >;

  string_table = new vector< string * >;
  string_table->push_back(new string("Environment"));
  logic_expression_table = new vector< bool_expression * >;
  logic_expression_table1 = new vector< bool_expression * >;
  variable_table = new vector< variable * >;
  
  filename = argv[argc - 1];
  driver.parse(filename);
  if (!driver.syntax_error) {
    if (options["quiet"] == 0 || options["simulation"] == 0)
      cout << filename << " has been parsed successfull." << endl;
    if (options["quiet"] == 0 || options["simulation"] == 0)
      cout << "Global syntax checking..." << endl;
	
    if (!global_consistency_check()) {
      cout << filename << " has error(s)." << endl;
      free_mcmas_memory(NULL);
      exit(-1);
    }
    if (options["quiet"] == 0)
		cout << "Done" << endl;
  } 
  else {
    cout << filename << " has syntax error(s)." << endl;
    free_mcmas_memory(NULL);
    exit(-1);
  }

  if (options["verbosity"] > 2) {
  }

  // change atlk=0 to atlk=1 if there are fairness constraints
  if(options["ATLsemantics"] == 0 && !force_atlk && !is_fairness->empty())
    options["ATLsemantics"] = 1;
  // disable atl counterexample if there are fairness constraints or atlk > 0
  if(options["ATLsemantics"] > 0 || !is_fairness->empty())
    options["atlcex"] = 0;
  // override ATLsemantics when uniform is set
  if(options["uniform"] == 1) {
    options["atlcex"] = 0;
    // temporally disable cex generation until it is fixed
    //options["cex"] = 0; 
    if(options["ATLsemantics"] == 0 && !force_atlk && !is_fairness->empty())
      options["ATLsemantics"] = 1;
    options["nobddcache"] = 1;
    // check if the name of the group used to split protocols is set properly
    if(!ufgroup_name.empty()) {
      //check if the name is defined
      if(is_groups == NULL || is_groups->find(ufgroup_name) == is_groups->end()) {
        cout << "Group name " << ufgroup_name << " is not defined." << endl;
        free_mcmas_memory(NULL);
        exit(-1);
      }
    }
  }

  if (options["simulation"] == 0 || options["quiet"] == 0)
    cout << "Encoding BDD parameters..." << endl;

  // Calculate the number of BDD variables for states and actions
  for (unsigned int i = 0; i < agents->size(); i++) {
    states_count += (*agents)[i]->state_BDD_length();//只计算vars+obsvars
    actions_count += (*agents)[i]->actions_BDD_length();
  }

  // Calculate the position of every variable and every set of actions，对于每一个agent计算
  int k1 = 0;
  int k2 = 0;
  for (unsigned int i = 0; i < agents->size(); i++) {
    k1 = (*agents)[i]->allocate_BDD_2_variables(k1);
    k2 = (*agents)[i]->allocate_BDD_2_actions(k2);//state_variables和action各算各的
  }

  if (options["verbosity"] > 0) {
    cout << endl << "  Building BDDs variables...";
    cout.flush();
  }

  Cudd *bddmgr = options["cachesize"] > CUDD_CACHE_SLOTS ?
    new Cudd(states_count * 2 + actions_count, 0, CUDD_UNIQUE_SLOTS, options["cachesize"], options["maxmem"], 0) :  // The manager
    new Cudd(states_count * 2 + actions_count, 0, CUDD_UNIQUE_SLOTS, CUDD_CACHE_SLOTS, options["maxmem"], 0);  // The manager
  vector<BDD> *v;
  vector<ADD> *addv;
  vector<BDD> *pv;
  vector<ADD> *addpv;
  vector<BDD> *a;
  vector<BDD> *vevol, *vprot, *vRT;
  vector< vector<BDD> * > *vRT_vector;
  vector< vector<BDD> * > *vprot_vector;
  int bdd_vari_num = Cudd_ReadSize(bddmgr->getManager());
  unsigned int all_reach_counter = 0;

  v = new vector<BDD>;  // Local states
  addv = new vector<ADD>;
  pv = new vector<BDD>; // "Next" local states
  addpv = new vector<ADD>;
  a = new vector<BDD>; // Actions

  // Allocate BDD variables to states and actions
  allocate_bdd_variables(v, addv, pv, addpv, a, bddmgr);

  if (options["verbosity"] > 0) {
    cout << "Done: " << v->size() << " for local states, " << a->
      size() << " for actions." << endl;
  }

  obsvars_bdd_length = (*agents)[0]->obsvars_BDD_length();
  envars_bdd_length = (*agents)[0]->get_var_index_end() + 1;

  vprot = new vector<BDD>;
  vevol = new vector<BDD>;
  vRT = new vector<BDD>;
  
  bdd_parameters *para = new bdd_parameters;
  parameters = para; /* for the signal handler */
  para->bddmgr = bddmgr;
  para->istates = is_istates;
  para->vRT = vRT;
  para->vevol = vevol;
  para->vprot = vprot;
  para->num_of_inits = NULL;
  para->num_of_agents = agents->size();
  para->id = 0;
  para->v = v;
  para->pv = pv;
  para->addv = addv;
  para->addpv = addpv;
  para->a = a;
  para->reach = NULL;
  para->original_reach = NULL;
  para->num_of_inits = new int(0);
  para->reachRT = NULL;
  para->fair_gamma_FO = NULL;
  para->nfair_gamma_FO = NULL;
  para->calReachRT = true;  
  para->BDD_cache = new map< string, BDD > ();
  para->ADD_cache = new map< string, ADD > ();
  para->vec_reach=new vector<BDD>;
  if(options["nomerge"] == 1) {
    para->merge = 0;
    para->vec_in_st = new vector<BDD*>;
    para->vec_formula = new vector<BDD*>;
    para->vec_reachRT = new vector<BDD*>;
    para->vec_istates = new vector<bool_expression*>;
  } else
    para->merge = 1;

  if (options["simulation"] == 1)
    exec_simulation(para);
  else {
    BDD in_st = bddmgr->bddOne();
    BDD reach;

    // REORDERING OF VARIABLES:
    //Cudd_ReorderingType REORDERING = CUDD_REORDER_GROUP_SIFT_CONV;
    if (options["dao"] == 0 || options["dao"] >= 2) // 1: all disable
      Cudd_AutodynEnable(bddmgr->getManager(), REORDERING);
    
    if (options["quiet"] == 0 || options["simulation"] == 0) {
      cout << "Building partial transition relation..." << endl;
    }

    struct timeb t0, t1;
    if (options["quiet"] == 0 && options["verbosity"] > 1)
      ftime(&t0);

     for (unsigned int i = 0; i < agents->size(); i++) {	 	
        if (options["verbosity"] > 0) {
          if (i == 0)
            cout << endl;
          cout << "      Processing " << (*agents)[i]->get_name() <<": protocol... ";
          cout.flush();
        }
        struct timeb tmptmb0;
        ftime(&tmptmb0);
		para->vprot->push_back((*agents)[i]->encode_protocol(para));
		string agent_name = (*agents)[i]->get_name();
			
        (*is_agents_index)[agent_name] = i;
        if (options["verbosity"] > 0) {
          cout << "done, evolution...";
          cout.flush();
        }
        if (options["smv"] == 0) {
		  para->vevol->push_back((*agents)[i]->encode_evolution(para));
	    }
        else{
		  para->vevol->push_back((*agents)[i]->encode_evolution_smv(para));
		}
        if (options["verbosity"] > 0) {
          cout << "done, local transition relation...";
          cout.flush();
        }
        para->vRT->push_back((*para->vprot)[i] * (*para->vevol)[i]);
        struct timeb tmptmb1;
        ftime(&tmptmb1);
        if (options["verbosity"] > 0) 
          cout << "done. " << ((tmptmb1.time-tmptmb0.time) + (tmptmb1.millitm-tmptmb0.millitm)/1000.0) << " seconds" << endl;
     }

	if (options["verbosity"] > 2)
      cout << "Done" << endl;
	
    if (options["quiet"] == 0 && options["verbosity"] > 1) {
      ftime(&t1);
      cout << "It took " << ((t1.time-t0.time) + (t1.millitm-t0.millitm)/1000.0) << " seconds to encode transition relation." << endl;
    }

	unsigned int acounter1 = 1;
	para->original_reach = new BDD(para->bddmgr->bddZero());	
	
	if (options["verbosity"] > 2)
      cout << "Done" << endl;
   
    if (options["quiet"] == 0 && options["verbosity"] > 1) {
      ftime(&t1);
      cout << "It took " << ((t1.time-t0.time) + (t1.millitm-t0.millitm)/1000.0) << " seconds to encode transition relation." << endl;
    }

    if(options["uniform"] == 1) {
      if (options["quiet"] == 0 && options["verbosity"] > 0)
        cout << "Building uniform protocols..." << endl;
      
      build_integer_BDDs(para);
      build_enumerate_BDDs(para);
      uniform_prots = new vector< vector< BDD* >* >;
      set< string > ufg;
      if(!ufgroup_name.empty())
        ufg = is_groups->find(ufgroup_name)->second;

	  for(unsigned int x=0; x<agents->size(); x++) {
	  	if (options["quiet"] == 0 ) {
		  cout << "  processing protocol in agent " << (*agents)[x]->get_name() << "...";				
		  cout.flush();
		}
		basic_agent* agent = (*agents)[x];
		vector< BDD* >* uni_prot;
        if(!ufgroup_name.empty() && ufg.find(agent->get_name()) == ufg.end()) {
          uni_prot = new vector< BDD* >();
          uni_prot->push_back(new BDD((*para->vprot)[x]));
        } else 
          uni_prot= agent->split_protocol((*para->vprot)[x], para);
        uniform_prots->push_back(uni_prot);
        if (options["quiet"] == 0 /*&& options["verbosity"] > 0*/)
          cout << " done: " << uni_prot->size() << " uniform protocols" << endl;
      }
    }
	
    if (options["quiet"] == 0 || options["simulation"] == 0) {
      cout << "Building BDD for initial states..." << endl;
    }
    if (options["quiet"] == 0 && options["verbosity"] > 1)
      ftime(&t0);
	in_st = is_istates->encode_bdd_flat(para, bddmgr->bddOne());
    in_st = append_variable_BDDs(bddmgr, v, in_st);
    if (options["verbosity"] > 2)
      cout << "Done." << endl;
    if (options["quiet"] == 0 && options["verbosity"] > 1) {
      ftime(&t1);
      cout << "It took " << ((t1.time-t0.time) + (t1.millitm-t0.millitm)/1000.0) << " seconds to encode initial states." << endl;
    }
    
    para->in_st = new BDD(in_st);
    
    REORDERING = CUDD_REORDER_GROUP_SIFT;
    if (options["dao"] == 0 || options["dao"] == 3) // 1: all disable, 2: after transition relation, 3: after reachable states
      Cudd_AutodynEnable(bddmgr->getManager(), REORDERING);
    else
      Cudd_AutodynDisable(bddmgr->getManager());
	
    satisfied = new bool[is_formulae->size()];
	satisfied_ast = new bool[is_formulae_ast->size()];
    for(unsigned int x=0; x<is_formulae->size(); x++)
      satisfied[x] = false;
	
	for(unsigned int x=0; x<is_formulae_ast->size(); x++)
      satisfied_ast[x] = false;

	time_vec = new double[is_formulae_ast->size()];

    if(options["uniform"] == 1) { // model checking uniform strategies
  	  traverse_uniform_strategies(uniform_prots, para);
      para->vprot = vprot;
      para->vRT = vRT;
      clear_integer_BDDs(para);
      clear_enumerate_BDDs(para);
      for(unsigned int x=0; x<uniform_prots->size(); x++) {
        vector < BDD* > *uni_prot = (*uniform_prots)[x];
        for(unsigned int y=0; y<uni_prot->size(); y++)
          delete (*uni_prot)[y];
        delete (*uniform_prots)[x];
      }
      delete uniform_prots;
    } 
	else {
      if (options["quiet"] == 0 || options["simulation"] == 0) {
        cout << "Building reachable state space..." << endl;
      }
      
      if (options["quiet"] == 0 && options["verbosity"] > 1)
        ftime(&t0);

	  unsigned int acounter1 = 1;
	  reach = compute_reach(in_st, v, pv, a, vRT, bddmgr, &acounter1, 1, &threadmem);
	  para->reach = new BDD(reach);	  
	  para->original_reach = new BDD(para->bddmgr->bddZero());

      if (options["dao"] > 0) // 1: all disable, 2: after transition relation, 3: after reachable states
        Cudd_AutodynDisable(bddmgr->getManager());
      
      if (options["verbosity"] > 2)
        cout << "Done." << endl;
      
      if (options["quiet"] == 0 && options["verbosity"] > 1) {
        ftime(&t1);
        cout << "It took " << ((t1.time-t0.time) + (t1.millitm-t0.millitm)/1000.0) << " seconds to generate state space." << endl;
      }

	  // Check deadlock of the model
      if(options["deadlock"] == 1) {
        BDD ex = check_EX(para->bddmgr->bddOne(), para);
        bool satisfaction = ex == reach;
	  
        if(satisfaction) {
          if(options["quiet"] == 0) 
            cout << "There is no deadlock state in the model!" << endl;
        } else {  
          BDD diff = reach - ex;
          BDD state = diff.PickOneMinterm(*para->v);
          
          if(options["quiet"] == 0) {
            cout << "Attention: there are deadlock states in the model!" << endl;
            cout << "The following state does not have any successors." << endl;
            print_state(state, *para->v);
            cout << "----------------------------------------" << endl;
          }
  
          if(options["cex"] > 0) 
            produce_witness(para, state, "deadlock");   
        }
      }
  
      // Check arithmetic overflow in the model
      if (options["overflow"] == 1) {
        BDD state;
        bool flag = false;
        BDD rc = reach;
        unsigned int i, j=0;
        for(i=0; i<agents->size(); i++)
          rc *= (*para->vprot)[i];
        for(i=0; i<agents->size(); i++) {
          vector< evolution_line * >* evolution = (*agents)[i]->get_evolution();
          for(j=0; j<evolution->size(); j++) {
            BDD bddevline = (*evolution)[j]->encode_bdd_overflow(para);
            bddevline *= rc;
            if(bddevline != para->bddmgr->bddZero()) {
              state = bddevline.PickOneMinterm(*para->v);
              flag = true;
              break;
            }
          }
          if(flag)
            break;
        }
        if(flag) {
          if(options["quiet"] == 0) {
            cout << "Evolution item " << j+1 << " in Agent " << (*agents)[i]->get_name()
                 << " can cause overflow in the following state: " << endl;
            print_state(state, *para->v);
            cout << "----------------------------------------" << endl;
          }
          if(options["cex"] > 0) 
            produce_witness(para, state, "overflow");
        }
      }
	  
      vector< vector< int >*> *countex = new vector< vector< int >*>;
      map< int, BDD * > *idbdd = new map< int, BDD * >;
      vector< vector< transition* > > *cextr = new vector< vector< transition* > >;
       
      BDD *is_temp = new BDD(*(para->in_st));
      SCGS_export_model(para, is_temp, countex, idbdd, cextr);	  

      string fname = cex_prefix + /*filename.substr(0, tempstr.rfind(".ispl"))*/ + "model";
      my_clear_cex(countex, idbdd, cextr);
      my_delete_cex(countex, idbdd, cextr);
      delete is_temp;

	  all_reach = para->bddmgr->bddZero();
	  

	  bool atl_sat = (options["ATLsat"] == 1); 
	  
	  if(atl_sat){
	  	all_reach_vec = new vector<BDD>;
		BDD tmp = para->bddmgr->bddOne();	
		map<string, map<string, vector<BDD*>* >* >* int_vars = integer_variable_BDDs(para->bddmgr, para->v);	
		while(tmp!=para->bddmgr->bddZero()){
		  BDD curinitstate = tmp.PickOneMinterm(*para->v);
		  curinitstate = complete_integer_BDDs(para->bddmgr, para->v, curinitstate, int_vars);		
		  tmp = tmp - curinitstate; 
		  bool valid = is_valid_state(curinitstate, *para->v);		
		  if (valid){ 
			all_reach += curinitstate;
			all_reach_counter++;
		    all_reach_vec->push_back(curinitstate);
		  }
		}	  
	  } else{
		all_reach += (*para->reach);
		all_reach_counter = para->vec_reach->size();
		all_reach_vec = para->vec_reach;
	  }  
	
	  do_model_checking_ATL_ast(para);
    }
    struct timeb tmb1;
    ftime(&tmb1);
    cout << "  The total execution time = " << ((tmb1.time-tmb.time) + (tmb1.millitm-tmb.millitm)/1000.0) << endl;
    unsigned long memoryinuse = bddmgr->ReadMemoryInUse();
    memoryinuse = (memoryinuse < threadmem) ? threadmem : memoryinuse;
	cout<<"  The number of inits is: "<<*para->num_of_inits<<endl;
	cout<<"  BDD variables used in states_count are : "<<states_count<<endl;
    cout<<"  BDD variables used in actions_count are : "<<actions_count<<endl;
    cout<<"  The number of BDD variables in existance is: "<<bdd_vari_num<<endl;
    cout<<"  BDD memory in use = " << memoryinuse << endl;
	cout<<"  The num of reachable states is: " << para->vec_reach->size()<<endl;
	cout<<"  The num of states is: "<<all_reach_counter<<endl;	


	bool atl_pg = (options["ATLpg"] == 1); 
	bool atl_sat = (options["ATLsat"] == 1); 
	string type="";
	string ag_name="";
	string st_type="";
	for(unsigned int kk=0; kk<agents->size(); kk++){
	  string t = (*agents)[kk]->get_strategy_type();
	  if(t=="IR") { 
		type+="_1";
		st_type+="_IR";
	  }
	  else if(t=="Ir") { 
		type+="_2";
		st_type+="_Ir";
	  }
	  else if(t=="ior") {
		type+="_3";
		st_type+="_ior";
	  }
	  else {
		type+="_4";
		st_type+="_isr";
	  }
	  ag_name+=("_"+(*agents)[kk]->get_name());
	}
	
	string folder_name = "_"+(*agents)[1]->get_name();
	string filename="";
	
	if(atl_pg&&atl_sat){
	  filename +="new_result_report_pg1_sat1/"+folder_name+"/"+type; 
	} else if(atl_pg&&(!atl_sat)){
	  filename +="new_result_report_pg1_sat0/"+folder_name+"/"+type;  
	} else if((!atl_pg)&&atl_sat){
	  filename +="new_result_report_pg0_sat1/"+folder_name+"/"+type; 
	} else {
	  filename +="new_result_report_pg0_sat0/"+folder_name+"/"+type; 
	}
	
	cout<<"filename is: "<<filename<<endl;	
	ofstream myfile(filename.c_str());
	if (myfile.is_open()) {
	  myfile<<endl;
	  myfile<<"*************** The strategy types of agents are: "<< st_type <<" ***************"<<endl<<endl;
	  myfile<<"******************** The output results for ATL* are as follows ***********************"<<endl<<endl;
	  for (unsigned int i = 0; i < is_formulae_ast->size(); ++i) {
		myfile << "  Formula_ast number " << i+1 << ": " <<(*is_formulae_ast)[i].to_string() << ", is " << (satisfied_ast[i] ? "TRUE" : "xxxxxxxxxxxxxxx FALSE xxxxxxxxxxxxxxx") << " in the model."<<endl;
		myfile <<"	Time for checking formula_ast "<<i+1<<" is: "<<time_vec[i]<<endl;
	  }
	
	  myfile<<endl;
	  myfile<<"*************************************** THE END ***************************************"<<endl;
	  myfile << "  The total execution time = " << ((tmb1.time-tmb.time) + (tmb1.millitm-tmb.millitm)/1000.0) << endl;
	  myfile<<"  The number of inits is: "<<*para->num_of_inits<<endl;
	  myfile<<"  BDD variables used in states_count are : "<<states_count<<endl;
	  myfile<<"  BDD variables used in actions_count are : "<<actions_count<<endl;
	  myfile<<"  The number of BDD variables in existance is: "<<bdd_vari_num<<endl;
	  myfile<<"  BDD memory in use = " << memoryinuse << endl;
	  myfile<<"  The num of reachable states is: " << para->vec_reach->size()<<endl;
	  myfile<<"  The num of states is: "<<all_reach_counter<<endl;	
	  myfile << "\n";
	  myfile.close();
	  cout<<"we have successfully write in the result"<<endl;
	} else
	  cout << "Unable to open result_export file";

	if (options["bdd_stats"] == 1) { 
      bddmgr->info();
    }
    in_st = reach = para->bddmgr->bddZero();
    delete satisfied;
	delete satisfied_ast;
  }
 clearmemory:
  free_mcmas_memory(para);
  free_cudd_memory(para);
}
