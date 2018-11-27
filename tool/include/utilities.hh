#ifndef UTILITIES_HH
# define UTILITIES_HH
#include <vector>
#include <cmath>
#include "types.hh"
#include "cuddObj.hh"

using namespace std;

extern "C++" {
  inline int log_2(int x) {
    if(x==1)
      return 1;
    else
      return (int)ceil(log2(x));
  }
  BDD Exists(Cudd *bddmgr, vector<BDD>* v, BDD x);
  BDD Exists(Cudd *bddmgr, vector<BDD>* v, vector<BDD>* a, BDD x);
  BDD Exists(Cudd * bddmgr, vector<BDD> * v, BDD x, unsigned int start, unsigned int end);
  BDD Abstract_key_var(Cudd * bddmgr, vector<BDD> * v, BDD x, int index_begin, int index_end);
  ADD ADDExists(Cudd * bddmgr, vector<ADD> v, ADD x);
  BDD check_EX (BDD next, bdd_parameters *para);
  BDD check_EF (BDD p, bdd_parameters *para);
  BDD check_EG (BDD p, bdd_parameters *para);
  BDD check_EU(BDD p, BDD q, bdd_parameters *para);
  BDD check_AU(BDD p, BDD q, bdd_parameters *para);
  BDD check_nK (BDD next, BDD RK, bdd_parameters *para);
  BDD check_nO (BDD next, string name, bdd_parameters *para);
  BDD check_GK (BDD next, string name, bdd_parameters *para);
  BDD SCGS_check_GK(BDD next, string name, bdd_parameters * para);
  BDD SCGS_check_GK_2(BDD next, string name, bdd_parameters * para);
  BDD SCGS_check_GK_3(BDD next, string name, bdd_parameters * para);
  BDD check_DK (BDD next, string name, bdd_parameters *para);
  BDD SCGS_check_DK(BDD next, string name, bdd_parameters * para);
  BDD check_GCK (BDD next, string name, bdd_parameters *para);
  BDD SCGS_check_GCK(BDD next, string name, bdd_parameters * para);
  BDD check_ATLX(BDD next, string grpname, bdd_parameters *para);
  BDD check_ATLG(BDD p, string grpname, bdd_parameters *para);
  BDD check_ATLG_aux(BDD p, string grpname, bdd_parameters * para);
  BDD check_ATLU(BDD q1, BDD q2, string grpname, bdd_parameters *para); 
  BDD check_ATLR(BDD q1, BDD q2, string grpname, bdd_parameters *para); 
  BDD check_EU_Qh(BDD p, BDD q, bdd_parameters * para, vector< BDD* >* qh);
  BDD check_EG_fair_Qh(BDD p, bdd_parameters * para, vector< vector < BDD* >* >* Qh);
  BDD check_EG_fair (BDD p, bdd_parameters *para);
  BDD check_EF_fair (BDD p, BDD fair_reach, bdd_parameters *para);
  BDD check_EX_fair (BDD p, BDD fair_reach, bdd_parameters *para);
  BDD check_EU_fair(BDD p, BDD q, BDD fair_reach, bdd_parameters *para);
  BDD check_nO_fair (BDD next, string name, BDD fair_reach, bdd_parameters *para);
  BDD check_GK_fair (BDD next, string name, BDD fair_reach, bdd_parameters *para);
  BDD check_DK_fair (BDD next, string name, BDD fair_reach, bdd_parameters *para);
  BDD check_GCK_fair (BDD next, string name, BDD fair_reach, bdd_parameters *para);
  BDD check_ATLX_fair(BDD next, string grpname, BDD fair_reach, bdd_parameters *para);
  BDD check_ATLG_fair(BDD p, string grpname, bdd_parameters *para);
  BDD check_ATLU_fair(BDD q1, BDD q2, string grpname, BDD fair_reach, bdd_parameters *para);  
  BDD lemma2_calculate(bdd_parameters* para, bdd_parameters* para_in, vector<bdd_parameters>* para_vec_out, modal_formula f,string grp);
  BDD transform_uni_for_atl_empty(vector< vector< BDD* >* >* uniform_r_prots, unsigned int k, bdd_parameters* para, vector<bdd_parameters>* para_vec, BDD result_before, modal_formula f);
  void transform_uni_for_atl_grp_in(map<unsigned int, vector< BDD* >* >* uniform_rin_prots,vector<unsigned int>* index_vec_in, unsigned int k, bdd_parameters* para, vector<bdd_parameters>* para_vec);
  void transform_uni_for_atl_grp_out(map<unsigned int, vector< BDD* >* >* uniform_rin_prots, vector<unsigned int>* index_vec_out,unsigned int k, bdd_parameters* para, vector<bdd_parameters>* para_vec);
 
  BDD get_K_states(BDD aset1, BDD *state, string name, bdd_parameters *para);
  BDD get_nK_states(BDD *state, string name, bdd_parameters *para);
  BDD SCGS_get_nK_states(BDD * state, string name, bdd_parameters * para);
  BDD get_nK_states_fair(BDD *state, string name, BDD fair_reach, bdd_parameters *para);
  BDD get_GK_states(BDD aset1, BDD *state, string name, bdd_parameters *para);
  BDD get_DK_states(BDD aset1, BDD *state, string name, bdd_parameters *para);
  void  global_print_state(BDD local_state, bdd_parameters* para);

  DdNode * addApplyLT(DdManager* mgr, DdNode ** n1, DdNode ** n2);
  DdNode * addApplyLE(DdManager* mgr, DdNode ** n1, DdNode ** n2);
  DdNode * addApplyGT(DdManager* mgr, DdNode ** n1, DdNode ** n2);
  DdNode * addApplyGE(DdManager* mgr, DdNode ** n1, DdNode ** n2);
  DdNode * addApplyEQ(DdManager* mgr, DdNode ** n1, DdNode ** n2);
  DdNode * addApplyNEQ(DdManager* mgr, DdNode ** n1, DdNode ** n2);

  ADD addLT(Cudd * bddmgr, ADD a1, ADD a2);
  ADD addLE(Cudd * bddmgr, ADD a1, ADD a2);
  ADD addGT(Cudd * bddmgr, ADD a1, ADD a2);
  ADD addGE(Cudd * bddmgr, ADD a1, ADD a2);
  ADD addEQ(Cudd * bddmgr, ADD a1, ADD a2);
  ADD addNEQ(Cudd * bddmgr, ADD a1, ADD a2);
  // Calculate X * RT with local transition relations
  BDD timesTrans(BDD *from, BDD *to, vector<BDD> *vRT);

  // Remove actions from X * RT
  BDD timesRT(BDD *state, Cudd *bddmgr, vector<BDD> *vRT, vector<BDD> *a);
  BDD compute_successors(BDD *state, Cudd * bddmgr, vector<BDD> * vRT, vector<BDD> * a, vector<BDD> *v, vector<BDD> *pv);
  int search_string_table(string *s);
  int search_variable_table(variable *v);
  int search_logic_expression_table(bool_expression *le);
  int search_logic_expression_table1(bool_expression *le);
  int search_logic_expression_table(expression *e1, expression *e2);
  int search_logic_expression_table1(expression *e1, expression *e2);
  vector<BDD*>* get_equiv_state(bdd_parameters * para, BDD* s, string grpname);
  vector<BDD> * get_rin_Str(BDD state, vector< basic_agent * >* agents_r_in,bdd_parameters * para);

  
}

extern map < string, int > options;
extern map<string, basic_agent *> *is_agents;
extern map<string, unsigned int> *is_agents_index;
extern vector<basic_agent *> *agents;
extern map<string, bool_expression *> *is_evaluation;
extern bool_expression *is_istates;
extern map<string, set<string> > *is_groups;
extern vector<modal_formula> *is_formulae;
extern vector<modal_formula_ast> *is_formulae_ast;

extern vector<fairness_expression *> *is_fairness;
extern int obsvars_bdd_length;
extern int envars_bdd_length;
extern int scount;
extern vector<string *> *string_table;
extern vector<variable *> *variable_table;
extern vector<bool_expression *> *logic_expression_table;
extern vector<bool_expression *> *logic_expression_table1;
extern void print_state(BDD state, vector<BDD> v);
extern void print_states(BDD states, vector<BDD> v, Cudd* bddmgr);
extern void print_action(BDD state, vector<BDD> a);
extern string state_to_str(BDD state, vector<BDD> v);
extern BDD append_variable_BDDs(Cudd * bddmgr, vector<BDD> * v, BDD a);
extern int SCGS_export_model(bdd_parameters * para, BDD *is, vector< vector< int >*> *countex, map< int, BDD * > *idbdd, vector< vector< transition* > > *cextr);
extern int export_model(bdd_parameters * para, BDD *is, vector< vector< int >*> *countex, map< int, BDD * > *idbdd, vector< vector< transition * >*> *cextr);
extern void SCGS_print_cex(bdd_parameters * para, string fname, string str_head, map< int, BDD * > *idbdd, vector< vector< transition* > > *cextr);
extern void print_cex(bdd_parameters * para, string fname, string str_head, map< int, BDD * > *idbdd, vector< vector< transition* >* > *cextr);
extern void clear_cex(vector< vector< int >*>* countex, map< int, BDD * >* idbdd, vector< vector< transition* >* >* cextr);
extern void my_clear_cex(vector< vector< int >*>* countex, map< int, BDD * >* idbdd, vector< vector< transition* > >* cextr);
extern void delete_cex(vector< vector< int >*>* countex, map< int, BDD * >* idbdd, vector< vector< transition* >* >* cextr);
extern void my_delete_cex(vector< vector< int >*>* countex, map< int, BDD * >* idbdd, vector< vector< transition* > >* cextr);
extern int states_count;
extern int actions_count;
extern bool force_atlk;
extern map< string, map< string, vector< BDD* >* >* >* integerBDDs;
extern map< string, map< string, BDD* >* >* enumerateBDDs;
vector<BDD*>* get_equiv_state(bdd_parameters * para, BDD* s, string grpname);
vector<model>* get_rin_Str(int reach_id, BDD* state, string grp, vector<basic_agent*> * agent_Ir_in,bdd_parameters * para,vector<bdd_parameters>* para_vec);
void transform_uni(vector< vector< BDD* >* >* uniform_rin_prots, unsigned int k, bdd_parameters* para, vector<bdd_parameters>* para_vec);
void transform_uni_for_in(vector< pair<bool,vector< BDD* >*> >*uniform_rin_prots, unsigned int k, bdd_parameters* p, vector<bdd_parameters>* para_vec);
void transform_uni_for_out(vector< pair<bool,vector< BDD* >*> >*uniform_rin_prots, unsigned int k, bdd_parameters* p, vector<bdd_parameters>* para_vec);
vector<model>* model_split_Ir(vector<model>* model_vec,vector<basic_agent* >* agent_Ir_in,bdd_parameters * para);
vector<model>* get_model_from_tree(vector<STnode>* leaf_vec, map<string, int>* bddid, map<int, BDD*>* idbdd, BDD* is_temp);
map<string, vector <transition*> >* split_by_Rin(pg_V3 * v2, string grp, bool agent_in_has_IR, bdd_parameters* para);
BDD get_dpt_trans_label(const char * label, bdd_parameters* para);
vector<unsigned int>* get_next_p(pg_V3* v3, dpa_tree * dT);
void generate_sub_label(vector<unsigned int>* f_cur_set, vector<map<string,vector<transition*> >* >* all_map_vector, vector<string>* one_sub_label, unsigned int k, vector<vector<string>*>* all_sub_labels);
vector<STnode>* buildTree(vector<vector<transition*> >* cextr, vector<basic_agent*>* agent_Ir_in, bdd_parameters* para);
string int2string(unsigned int val);
bool check_G_set(vector<map<string, map<unsigned int, string>*>*>* m1, vector<map<string, map<unsigned int, string>*>*>* m2,bdd_parameters* para);
bool check_f_R(vector<transition*> processed_f_R, vector<transition*> this_f_R, vector<basic_agent*>* agents_IR_in, bdd_parameters* para);
bool check_exist_g(map<string,map<unsigned int, string>*>* g_prim, vector<map<string, map<unsigned int, string>*>*>* m1);
bool check_g_equal(map<string, map<unsigned int, string>*>* g1, map<string, map<unsigned int, string>*>* g2);
void my_hdlr_debug(pg_handler* pg_hdlr);
unsigned int char2int(const char* c);
map<string, map<unsigned int, string>*>* check_compatible(unsigned int my_from_id, pg_V3* v3, bdd_parameters* para, map<string, map<unsigned int, string>*>* g, transition* temp, vector<basic_agent*>* agents_Ir_out, vector<basic_agent*>* agents_ir_out);
void fill_models(vector<model>* model_vec, bdd_parameters* para);
bool cextr_find_equiv(model m, BDD* state, bdd_parameters* para);



#endif // ! UTILITIES_HH
