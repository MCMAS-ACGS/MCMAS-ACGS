#include <ctime>
#include "types.hh"
#include <sys/timeb.h>
#include "utilities.hh"
#include "atlk.hh"
#include <unistd.h>
#include <string>
#include <stdio.h>
#include <iostream>
#include <iterator>
#include <memory>
#include <stdexcept>
#include "tinyxml.hh"
#include <sstream>
#include <memory>
using namespace std;
extern bool if_ir;
extern void free_mcmas_memory(bdd_parameters *para);
extern map< string, vector< vector< BDD* >* >*> map_uniform_prots;
extern bool bool_result;
extern BDD result;
extern bool *satisfied;
extern map< string, BDD > * is_new_evaluation; 

pg_handler::pg_handler(string group, bdd_parameters * p)
{      
  para = p;
  grp = group;
  dpa_parse();
}

pg_handler::~pg_handler()
{ 
  delete pg_game;  	
}

dpa_tree * 
pg_handler::get_dT() 
{
	return dT;
}

string 
pg_handler::get_grp()
{
	return grp;
}

bdd_parameters *  
pg_handler::get_para()
{
	return para;
}
void 
pg_handler::dpa_parse()
{  
  TiXmlDocument dpa_doc("data/my_dpa.dpa");
  dT = new dpa_tree;
  dT->dpa_alpha = new vector<string>;
  dT->dpaSts = new vector<unsigned int>;
  dT->dpaColr = new map<unsigned int, unsigned int>;
  dT->dpaTrs = new multimap<unsigned int, pair<unsigned int, BDD> >;
  bool loadOk = dpa_doc.LoadFile();
  
  if (!loadOk){
    cout<<"Could not load the dpa file! Error: "<<dpa_doc.ErrorDesc()<<endl;
	exit(1);
  }

  TiXmlElement *structure = dpa_doc.RootElement(); 
  TiXmlElement *elem = structure;

  for (TiXmlElement *struc_ele = elem->FirstChildElement(); struc_ele!=NULL; struc_ele = struc_ele->NextSiblingElement())
  {
	const char * value = struc_ele->Value();	
	if (strcmp(value, "Alphabet") == 0){
	  for (TiXmlElement *sub_elem = struc_ele->FirstChildElement(); sub_elem != NULL; sub_elem = sub_elem->NextSiblingElement())
	  {
		string s(sub_elem->FirstChild()->Value());
		dT->dpa_alpha->push_back(s); 
	  }
	}
	
	if (strcmp(value, "StateSet") == 0){
	  for (TiXmlElement *sub_elem = struc_ele->FirstChildElement(); sub_elem != NULL; sub_elem = sub_elem->NextSiblingElement())
	  {
		const char *state_value = sub_elem->FirstAttribute()->Value();
		unsigned int sid = char2int(state_value);
		dT->dpaSts->push_back(sid);
	  }
	}

	if (strcmp(value, "InitialStateSet") == 0){
	  TiXmlElement *sub_elem = struc_ele->FirstChildElement(); 
	  const char *stateID = sub_elem->FirstChild()->Value();
	  stringstream strValue;
      strValue<<stateID;
	  unsigned int intValue;
	  strValue>>intValue;
	  dT->dpaInit = intValue;
	}

	if (strcmp(value, "TransitionSet") == 0){
      for (TiXmlElement *sub_elem = struc_ele->FirstChildElement(); sub_elem != NULL; sub_elem = sub_elem->NextSiblingElement())
	  {
		const char *transID = sub_elem->FirstAttribute()->Value();
		unsigned int tid = char2int(transID);
		TiXmlElement *from_ele = sub_elem->FirstChildElement();
		const char *from = from_ele->FirstChild()->Value();
		unsigned int from_id = char2int(from);

		TiXmlElement *to_ele = from_ele->NextSiblingElement();
		const char *to = to_ele->FirstChild()->Value();    
		unsigned int to_id = char2int(to);

		const char *label = to_ele->NextSiblingElement()->FirstChild()->Value();
		BDD label2bdd = get_dpt_trans_label(label,para);
		pair<unsigned int,BDD> p1(to_id,label2bdd);
		pair<unsigned int, pair<unsigned int, BDD> > p2(from_id,p1);
		dT->dpaTrs->insert(p2);		
	  }
	}

	if (strcmp(value, "Acc") == 0) {
	  unsigned int color_num = 0;
	  for (TiXmlElement *sub_elem = struc_ele->FirstChildElement(); sub_elem != NULL; sub_elem = sub_elem->NextSiblingElement())
	  {
		for (TiXmlElement *color_state = sub_elem->FirstChildElement(); color_state != NULL; color_state = color_state->NextSiblingElement())
		{
		  const char* state = color_state->FirstChild()->Value();
		  unsigned int sid = char2int(state);		  
		  pair<unsigned int, unsigned int> a(sid, color_num);
		  dT->dpaColr->insert(a);
		 }
		color_num = color_num + 1;
	  }
	}
  }  
}



BDD 
pg_handler::pg_solve(bool if_nest)
{
  struct timeb tmb_mc, tmb_mc1;
  ftime(&tmb_mc);
  pg_game = new parity_game(this->dT,this->grp, this->para);
  BDD my_result = pg_game->build_pg(if_nest);  
  ftime(&tmb_mc1);

  cout << " -----  time for building_pg is " << ((tmb_mc1.time-tmb_mc.time) + (tmb_mc1.millitm-tmb_mc.millitm)/1000.0) << endl;
  
  vector< pair <unsigned int, unsigned int> > * pg_st_p0 = pg_game->get_st_p0(); // <sid,color>
  vector< pair <unsigned int, unsigned int> > * pg_st_p1 = pg_game->get_st_p1();
  vector<unsigned int> * pg_init = pg_game->get_init();
  map<unsigned int, pair<unsigned int, unsigned int> > * pg_trs = pg_game->get_trs();
  multimap<unsigned int, unsigned int> * pg_colr = pg_game->get_colr(); // <color, sid[]>
  map<unsigned int, pg_V3*>* pg_nodes = pg_game->get_pg_nodes();

	//convert pg to .gff
  TiXmlDocument * pg_doc = new TiXmlDocument; 
	

  TiXmlDeclaration *decl = new TiXmlDeclaration("1.0", "UTF-8", "no");
  pg_doc->LinkEndChild(decl);
	
  TiXmlElement *pgStructure = new TiXmlElement("Structure");
  pgStructure->SetAttribute("label-on", "Transition"); 
  pgStructure->SetAttribute("type", "game");
  pg_doc->LinkEndChild(pgStructure);
	
  TiXmlElement *pg_alp_ele = new TiXmlElement("Alphabet");
  pg_alp_ele->SetAttribute("type", "Propositional");
  pgStructure->LinkEndChild(pg_alp_ele);
	
  TiXmlElement *pg_state_set_ele = new TiXmlElement("StateSet");
  pgStructure->LinkEndChild(pg_state_set_ele);
  unsigned int pg_state_count = 0;
	
  TiXmlElement *pg_istate_set_ele = new TiXmlElement("InitialStateSet"); 
  pgStructure->LinkEndChild(pg_istate_set_ele);
  unsigned int pg_istate_count = 0;
	
  TiXmlElement *pg_trans_set_ele = new TiXmlElement("TransitionSet");
  pg_trans_set_ele->SetAttribute("complete", "false");
  pgStructure->LinkEndChild(pg_trans_set_ele);
  unsigned int pg_trans_count = 0;
	
  TiXmlElement *pg_acc_ele = new TiXmlElement("Acc");
  pg_acc_ele->SetAttribute("type", "Parity");
  pgStructure->LinkEndChild(pg_acc_ele);
  unsigned int pg_acc_set_count = 0;
	  
  for ( vector<unsigned int>::iterator i=pg_init->begin(); i!=pg_init->end();i++) {
	TiXmlElement *pg_istate = new TiXmlElement("StateID");
	pg_istate_set_ele->LinkEndChild(pg_istate);
	TiXmlText *pg_istate_ID = new TiXmlText(int2string(*i).c_str()); 
	pg_istate->LinkEndChild(pg_istate_ID);
  }	
	
  for (vector<pair<unsigned int, unsigned int> >::iterator i =pg_st_p0->begin(); i!=pg_st_p0->end(); i++) {
	TiXmlElement *pg_state = new TiXmlElement("State");
	pg_state->SetAttribute("sid", int2string((*i).first).c_str());
	pg_state_set_ele->LinkEndChild(pg_state);
	TiXmlElement *player = new TiXmlElement("Player");
	pg_state->LinkEndChild(player);
	TiXmlText *playerContent = new TiXmlText("P0");
	player->LinkEndChild(playerContent);
  }
	
  for (vector<pair<unsigned int, unsigned int> >::iterator i =pg_st_p1->begin(); i!=pg_st_p1->end(); i++) {
	TiXmlElement *pg_state = new TiXmlElement("State");
	pg_state->SetAttribute("sid", int2string((*i).first).c_str());
	pg_state_set_ele->LinkEndChild(pg_state);
	TiXmlElement *player = new TiXmlElement("Player");
	pg_state->LinkEndChild(player);
	TiXmlText *playerContent = new TiXmlText("P1");
	player->LinkEndChild(playerContent);
  }
	
  for (map<unsigned int, pair<unsigned int, unsigned int> >::iterator i = pg_trs->begin(); i!= pg_trs->end(); i++) {
	TiXmlElement *trans_ele = new TiXmlElement("transition");
	trans_ele->SetAttribute("tid", int2string(i->first).c_str());
	pg_trans_set_ele->LinkEndChild(trans_ele);

	TiXmlElement *from = new TiXmlElement("From");
	TiXmlText *from_ID = new TiXmlText(int2string((i->second).first).c_str()); 
	from->LinkEndChild(from_ID);
	trans_ele->LinkEndChild(from);

	TiXmlElement *to = new TiXmlElement("To");
	TiXmlText *to_ID = new TiXmlText(int2string((i->second).second).c_str());
	to->LinkEndChild(to_ID);
	trans_ele->LinkEndChild(to);
  }

  unsigned int curt_clr = 0;	
  for (multimap<unsigned int, unsigned int>::iterator i = pg_colr->begin(); i!=pg_colr->end();i=pg_colr->lower_bound(curt_clr)) {	  
	TiXmlElement *pg_acc_set = new TiXmlElement("AccSet");
	pg_acc_ele->LinkEndChild(pg_acc_set);
	for (multimap<unsigned int, unsigned int>::iterator j = pg_colr->lower_bound(curt_clr); j!=pg_colr->upper_bound(curt_clr); j++) {
	  TiXmlElement *pg_acc_state = new TiXmlElement("StateID");
	  pg_acc_set->LinkEndChild(pg_acc_state);
	  TiXmlText *acc_ID = new TiXmlText(int2string(j->second).c_str()); 
	  pg_acc_state->LinkEndChild(acc_ID);
	}
	curt_clr=curt_clr+1;
  }
	  
  pg_doc->SaveFile("data/my_pg.gff");
  delete pg_doc;
  
  // need change it to your goal-tool's path !!!
  string  cmd=".../goal-tool/gc solve -p P0 -r \"data/my_pg.gff\"";
  
  const char * cmd_solve = cmd.c_str();
  struct timeb tmb_mc2, tmb_mc3;
  ftime(&tmb_mc2);
  system(cmd_solve);	
  cout<<endl;
  ftime(&tmb_mc3);
   cout << " -----  time for solve with goal is " << ((tmb_mc3.time-tmb_mc2.time) + (tmb_mc3.millitm-tmb_mc2.millitm)/1000.0) << endl;
  
  char buffer[256];
  string model_string = "";
  FILE* pipe = popen(cmd_solve, "r");
  if (!pipe) throw std::runtime_error("popen() failed!");
  try{
	while (!feof(pipe)) {
	  if (fgets(buffer, 128, pipe) != NULL)
		model_string += buffer;
	}
  }catch (...) {
	pclose(pipe);
	throw;
  }
	
  pclose(pipe);	
	
  stringstream ss(model_string);
  istream_iterator<string> begin(ss);
  istream_iterator<string> end;

  set <string> win_region(begin, end);
  BDD win_models = para->bddmgr->bddZero();
  
  if (pg_init!=NULL) {
    for (vector<unsigned int>::iterator i = pg_init->begin(); i < pg_init->end(); i++) {
	  string ss = "s"+int2string(*i);
	  if ((win_region.find(ss))!= (win_region.end())){
		BDD win_state = *(*pg_nodes)[*i]->s_state;
		win_models = win_models + win_state;
	  }
	}
  }
  else{
	cout << "Parity game has not been built yet!" << endl;
	free_mcmas_memory(NULL);
	exit(-1);
  }
  
  return win_models;
}
