# MCMAS-ACGS Model Checker 
This is a model checker for ATLK* on Agents' Abilities Augmented Concurrent Game Structures (ACGS), extended from MCMAS. In this tool, each agent is matched with an individual strategic abilities: IR, Ir, ior (objective ir) or isr (subjective ir). All the experiements are under folder "examples", and running reports are under folder "result_report". We also give a quite simple example in "examples/example.ispl". Files generated intermediately like Buchi.gff, DPA.dpa, Parity_game.gff are all in folder "data". You can also define your own system file written with .ispl grammer. For more details about .ispl, please visit: <http://vas.doc.ic.ac.uk/software/mcmas/manual.pdf>.

Since an external tool Goal is embedded in our model checker (under folder "goal-tool" ), you need revise the following options: 

1. Change followings to your local goal-tool path:

    - utilities/modal_formula_ast.cc: 
   
    `string cmd_ltl2buchi="../goal-tool/gc translate -m ltl2ba -sf -sb -rbm -o \"data/my_buchi.gff\" \""+ phi_name+"\"";`
   
    `string cmd_bu2DPA = "../goal-tool/gc convert -t dpw -o  \"data/my_dpa.dpa\" \"data/my_buchi.gff\"";`
   
    - utilities/pg_handler.cc:
   
    `string  cmd="../goal-tool/gc solve -p P0 -r \"data/my_pg.gff\"";`
   
2. System requirements for compiling (support both Linux and Windows platform):
    - Operating system: Linux, Windows using Cygwin.
    - Complier: flex 2.5.4 or higher, GNU bison 2.3 or higher, GNU g++ 4.0.1 or higher.
    - Type `make`, then you will get the executable `MCMAS_ACGS`.
   
3. Runnig MCMAS_ACGS:
     - `./MCMAS_ACGS your_system_file.ispl`
     - support another two options: 
     
        - -pg Choose Lemma for Model Checking (1 -- Lemma3, 0 -- Lemma1, default 1)"
        - -sat Whether to check all of states or not (1 -- also check the unreachable states when the system starts from the given initial state, 0 not check, default 1)" 
   
