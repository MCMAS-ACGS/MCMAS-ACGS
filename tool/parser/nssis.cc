/* A Bison parser, made by GNU Bison 2.5.  */

/* Skeleton implementation for Bison LALR(1) parsers in C++
   
      Copyright (C) 2002-2011 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */


/* First part of user declarations.  */


/* Line 293 of lalr1.cc  */
#line 39 "parser/nssis.cc"


#include "nssis.hh"

/* User implementation prologue.  */

/* Line 299 of lalr1.cc  */
#line 72 "parser/nssis_new.yy"

#include "mcmas-driver.hh"

  extern map < string, int > options;
  extern vector<string *> *string_table;
  extern vector<variable *> *variable_table;
  extern vector<bool_expression *> *logic_expression_table;
  extern vector<bool_expression *> *logic_expression_table1;
  extern map<string, basic_agent *> *is_agents;
  extern vector<basic_agent *> *agents;
  extern map<string, bool_expression *> *is_evaluation;
  extern bool_expression *is_istates;
  extern map<string, set<string> > *is_groups;
  extern vector<modal_formula> *is_formulae;
  extern vector<modal_formula_ast> *is_formulae_ast;
  extern vector<fairness_expression *> *is_fairness;

  extern int search_string_table(string *s);
  extern int search_variable_table(variable *v);
  extern int search_logic_expression_table(expression *e1, expression *e2);
  extern int search_logic_expression_table1(expression *e1, expression *e2);


/* Line 299 of lalr1.cc  */
#line 72 "parser/nssis.cc"

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* FIXME: INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                               \
 do                                                                    \
   if (N)                                                              \
     {                                                                 \
       (Current).begin = YYRHSLOC (Rhs, 1).begin;                      \
       (Current).end   = YYRHSLOC (Rhs, N).end;                        \
     }                                                                 \
   else                                                                \
     {                                                                 \
       (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;        \
     }                                                                 \
 while (false)
#endif

/* Suppress unused-variable warnings by "using" E.  */
#define YYUSE(e) ((void) (e))

/* Enable debugging if requested.  */
#if YYDEBUG

/* A pseudo ostream that takes yydebug_ into account.  */
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)	\
do {							\
  if (yydebug_)						\
    {							\
      *yycdebug_ << Title << ' ';			\
      yy_symbol_print_ ((Type), (Value), (Location));	\
      *yycdebug_ << std::endl;				\
    }							\
} while (false)

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug_)				\
    yy_reduce_print_ (Rule);		\
} while (false)

# define YY_STACK_PRINT()		\
do {					\
  if (yydebug_)				\
    yystack_print_ ();			\
} while (false)

#else /* !YYDEBUG */

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_REDUCE_PRINT(Rule)
# define YY_STACK_PRINT()

#endif /* !YYDEBUG */

#define yyerrok		(yyerrstatus_ = 0)
#define yyclearin	(yychar = yyempty_)

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)


namespace yy {

/* Line 382 of lalr1.cc  */
#line 158 "parser/nssis.cc"

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  mcmas_parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr = "";
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              /* Fall through.  */
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }


  /// Build a parser object.
  mcmas_parser::mcmas_parser (mcmas_driver& driver_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      driver (driver_yyarg)
  {
  }

  mcmas_parser::~mcmas_parser ()
  {
  }

#if YYDEBUG
  /*--------------------------------.
  | Print this symbol on YYOUTPUT.  |
  `--------------------------------*/

  inline void
  mcmas_parser::yy_symbol_value_print_ (int yytype,
			   const semantic_type* yyvaluep, const location_type* yylocationp)
  {
    YYUSE (yylocationp);
    YYUSE (yyvaluep);
    switch (yytype)
      {
        case 75: /* "\"identifier\"" */

/* Line 449 of lalr1.cc  */
#line 248 "parser/nssis_new.yy"
	{ debug_stream () << *(yyvaluep->sval); };

/* Line 449 of lalr1.cc  */
#line 233 "parser/nssis.cc"
	break;
      case 76: /* "\"number\"" */

/* Line 449 of lalr1.cc  */
#line 291 "parser/nssis_new.yy"
	{ debug_stream () << (yyvaluep->ival); };

/* Line 449 of lalr1.cc  */
#line 242 "parser/nssis.cc"
	break;
       default:
	  break;
      }
  }


  void
  mcmas_parser::yy_symbol_print_ (int yytype,
			   const semantic_type* yyvaluep, const location_type* yylocationp)
  {
    *yycdebug_ << (yytype < yyntokens_ ? "token" : "nterm")
	       << ' ' << yytname_[yytype] << " ("
	       << *yylocationp << ": ";
    yy_symbol_value_print_ (yytype, yyvaluep, yylocationp);
    *yycdebug_ << ')';
  }
#endif

  void
  mcmas_parser::yydestruct_ (const char* yymsg,
			   int yytype, semantic_type* yyvaluep, location_type* yylocationp)
  {
    YYUSE (yylocationp);
    YYUSE (yymsg);
    YYUSE (yyvaluep);

    YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

    switch (yytype)
      {
        case 75: /* "\"identifier\"" */

/* Line 480 of lalr1.cc  */
#line 249 "parser/nssis_new.yy"
	{ delete (yyvaluep->sval); };

/* Line 480 of lalr1.cc  */
#line 281 "parser/nssis.cc"
	break;
      case 86: /* "strtypedef" */

/* Line 480 of lalr1.cc  */
#line 269 "parser/nssis_new.yy"
	{ delete (yyvaluep->sval); };

/* Line 480 of lalr1.cc  */
#line 290 "parser/nssis.cc"
	break;
      case 90: /* "obsvardef" */

/* Line 480 of lalr1.cc  */
#line 250 "parser/nssis_new.yy"
	{ delete (yyvaluep->map_vec_basictype); };

/* Line 480 of lalr1.cc  */
#line 299 "parser/nssis.cc"
	break;
      case 91: /* "varidlist" */

/* Line 480 of lalr1.cc  */
#line 251 "parser/nssis_new.yy"
	{ delete (yyvaluep->map_vec_basictype); };

/* Line 480 of lalr1.cc  */
#line 308 "parser/nssis.cc"
	break;
      case 92: /* "onevardef" */

/* Line 480 of lalr1.cc  */
#line 252 "parser/nssis_new.yy"
	{ delete (yyvaluep->_basictype); };

/* Line 480 of lalr1.cc  */
#line 317 "parser/nssis.cc"
	break;
      case 93: /* "enumlist" */

/* Line 480 of lalr1.cc  */
#line 253 "parser/nssis_new.yy"
	{ delete (yyvaluep->set_string); };

/* Line 480 of lalr1.cc  */
#line 326 "parser/nssis.cc"
	break;
      case 97: /* "envardef" */

/* Line 480 of lalr1.cc  */
#line 255 "parser/nssis_new.yy"
	{ delete (yyvaluep->map_vec_basictype); };

/* Line 480 of lalr1.cc  */
#line 335 "parser/nssis.cc"
	break;
      case 98: /* "vardef" */

/* Line 480 of lalr1.cc  */
#line 254 "parser/nssis_new.yy"
	{ delete (yyvaluep->map_vec_basictype); };

/* Line 480 of lalr1.cc  */
#line 344 "parser/nssis.cc"
	break;
      case 102: /* "reddef" */

/* Line 480 of lalr1.cc  */
#line 263 "parser/nssis_new.yy"
	{ delete (yyvaluep->_bool_expression); };

/* Line 480 of lalr1.cc  */
#line 353 "parser/nssis.cc"
	break;
      case 104: /* "rboolcond" */

/* Line 480 of lalr1.cc  */
#line 262 "parser/nssis_new.yy"
	{ delete (yyvaluep->_bool_expression); };

/* Line 480 of lalr1.cc  */
#line 362 "parser/nssis.cc"
	break;
      case 107: /* "envevdef" */

/* Line 480 of lalr1.cc  */
#line 256 "parser/nssis_new.yy"
	{ delete (yyvaluep->vector_evolution_line); };

/* Line 480 of lalr1.cc  */
#line 371 "parser/nssis.cc"
	break;
      case 108: /* "envevdeflist" */

/* Line 480 of lalr1.cc  */
#line 257 "parser/nssis_new.yy"
	{ delete (yyvaluep->vector_evolution_line); };

/* Line 480 of lalr1.cc  */
#line 380 "parser/nssis.cc"
	break;
      case 109: /* "envevline" */

/* Line 480 of lalr1.cc  */
#line 258 "parser/nssis_new.yy"
	{ delete (yyvaluep->_evolution_line); };

/* Line 480 of lalr1.cc  */
#line 389 "parser/nssis.cc"
	break;
      case 110: /* "boolresult" */

/* Line 480 of lalr1.cc  */
#line 259 "parser/nssis_new.yy"
	{ delete (yyvaluep->vector_assignment); };

/* Line 480 of lalr1.cc  */
#line 398 "parser/nssis.cc"
	break;
      case 115: /* "agent" */

/* Line 480 of lalr1.cc  */
#line 268 "parser/nssis_new.yy"
	{ delete (yyvaluep->_basic_agent); };

/* Line 480 of lalr1.cc  */
#line 407 "parser/nssis.cc"
	break;
      case 122: /* "enactiondef" */

/* Line 480 of lalr1.cc  */
#line 271 "parser/nssis_new.yy"
	{ delete (yyvaluep->set_string); };

/* Line 480 of lalr1.cc  */
#line 416 "parser/nssis.cc"
	break;
      case 123: /* "actiondef" */

/* Line 480 of lalr1.cc  */
#line 270 "parser/nssis_new.yy"
	{ delete (yyvaluep->set_string); };

/* Line 480 of lalr1.cc  */
#line 425 "parser/nssis.cc"
	break;
      case 124: /* "actionidlist" */

/* Line 480 of lalr1.cc  */
#line 272 "parser/nssis_new.yy"
	{ delete (yyvaluep->set_string); };

/* Line 480 of lalr1.cc  */
#line 434 "parser/nssis.cc"
	break;
      case 127: /* "enprotdef" */

/* Line 480 of lalr1.cc  */
#line 274 "parser/nssis_new.yy"
	{ delete (yyvaluep->vector_protocol_line); };

/* Line 480 of lalr1.cc  */
#line 443 "parser/nssis.cc"
	break;
      case 128: /* "protdef" */

/* Line 480 of lalr1.cc  */
#line 273 "parser/nssis_new.yy"
	{ delete (yyvaluep->vector_protocol_line); };

/* Line 480 of lalr1.cc  */
#line 452 "parser/nssis.cc"
	break;
      case 130: /* "protdeflist" */

/* Line 480 of lalr1.cc  */
#line 275 "parser/nssis_new.yy"
	{ delete (yyvaluep->vector_protocol_line); };

/* Line 480 of lalr1.cc  */
#line 461 "parser/nssis.cc"
	break;
      case 134: /* "protline" */

/* Line 480 of lalr1.cc  */
#line 276 "parser/nssis_new.yy"
	{ delete (yyvaluep->_protocol_line); };

/* Line 480 of lalr1.cc  */
#line 470 "parser/nssis.cc"
	break;
      case 136: /* "enabledidlist" */

/* Line 480 of lalr1.cc  */
#line 277 "parser/nssis_new.yy"
	{ delete (yyvaluep->set_string); };

/* Line 480 of lalr1.cc  */
#line 479 "parser/nssis.cc"
	break;
      case 137: /* "evdef" */

/* Line 480 of lalr1.cc  */
#line 278 "parser/nssis_new.yy"
	{ delete (yyvaluep->vector_evolution_line); };

/* Line 480 of lalr1.cc  */
#line 488 "parser/nssis.cc"
	break;
      case 138: /* "evdeflist" */

/* Line 480 of lalr1.cc  */
#line 279 "parser/nssis_new.yy"
	{ delete (yyvaluep->vector_evolution_line); };

/* Line 480 of lalr1.cc  */
#line 497 "parser/nssis.cc"
	break;
      case 139: /* "evline" */

/* Line 480 of lalr1.cc  */
#line 280 "parser/nssis_new.yy"
	{ delete (yyvaluep->_evolution_line); };

/* Line 480 of lalr1.cc  */
#line 506 "parser/nssis.cc"
	break;
      case 141: /* "lboolcond" */

/* Line 480 of lalr1.cc  */
#line 260 "parser/nssis_new.yy"
	{ delete (yyvaluep->_bool_expression); };

/* Line 480 of lalr1.cc  */
#line 515 "parser/nssis.cc"
	break;
      case 163: /* "eboolcond" */

/* Line 480 of lalr1.cc  */
#line 261 "parser/nssis_new.yy"
	{ delete (yyvaluep->_bool_expression); };

/* Line 480 of lalr1.cc  */
#line 524 "parser/nssis.cc"
	break;
      case 165: /* "gboolcond" */

/* Line 480 of lalr1.cc  */
#line 281 "parser/nssis_new.yy"
	{ delete (yyvaluep->_bool_expression); };

/* Line 480 of lalr1.cc  */
#line 533 "parser/nssis.cc"
	break;
      case 166: /* "varvalue1" */

/* Line 480 of lalr1.cc  */
#line 264 "parser/nssis_new.yy"
	{ delete (yyvaluep->_expression); };

/* Line 480 of lalr1.cc  */
#line 542 "parser/nssis.cc"
	break;
      case 167: /* "boolvalue" */

/* Line 480 of lalr1.cc  */
#line 282 "parser/nssis_new.yy"
	{ delete (yyvaluep->_bool_value); };

/* Line 480 of lalr1.cc  */
#line 551 "parser/nssis.cc"
	break;
      case 168: /* "varvalue2" */

/* Line 480 of lalr1.cc  */
#line 265 "parser/nssis_new.yy"
	{ delete (yyvaluep->_expression); };

/* Line 480 of lalr1.cc  */
#line 560 "parser/nssis.cc"
	break;
      case 169: /* "varvalue3" */

/* Line 480 of lalr1.cc  */
#line 266 "parser/nssis_new.yy"
	{ delete (yyvaluep->_expression); };

/* Line 480 of lalr1.cc  */
#line 569 "parser/nssis.cc"
	break;
      case 170: /* "varvalue4" */

/* Line 480 of lalr1.cc  */
#line 267 "parser/nssis_new.yy"
	{ delete (yyvaluep->_expression); };

/* Line 480 of lalr1.cc  */
#line 578 "parser/nssis.cc"
	break;
      case 175: /* "evaboolcond" */

/* Line 480 of lalr1.cc  */
#line 283 "parser/nssis_new.yy"
	{ delete (yyvaluep->_bool_expression); };

/* Line 480 of lalr1.cc  */
#line 587 "parser/nssis.cc"
	break;
      case 179: /* "isboolcond" */

/* Line 480 of lalr1.cc  */
#line 284 "parser/nssis_new.yy"
	{ delete (yyvaluep->_bool_expression); };

/* Line 480 of lalr1.cc  */
#line 596 "parser/nssis.cc"
	break;
      case 186: /* "namelist" */

/* Line 480 of lalr1.cc  */
#line 285 "parser/nssis_new.yy"
	{ delete (yyvaluep->set_string); };

/* Line 480 of lalr1.cc  */
#line 605 "parser/nssis.cc"
	break;
      case 187: /* "agentname" */

/* Line 480 of lalr1.cc  */
#line 286 "parser/nssis_new.yy"
	{ delete (yyvaluep->sval); };

/* Line 480 of lalr1.cc  */
#line 614 "parser/nssis.cc"
	break;
      case 205: /* "formula" */

/* Line 480 of lalr1.cc  */
#line 287 "parser/nssis_new.yy"
	{ delete (yyvaluep->_modal_formula); };

/* Line 480 of lalr1.cc  */
#line 623 "parser/nssis.cc"
	break;
      case 215: /* "formula_ast" */

/* Line 480 of lalr1.cc  */
#line 288 "parser/nssis_new.yy"
	{ delete (yyvaluep->_modal_formula_ast); };

/* Line 480 of lalr1.cc  */
#line 632 "parser/nssis.cc"
	break;

	default:
	  break;
      }
  }

  void
  mcmas_parser::yypop_ (unsigned int n)
  {
    yystate_stack_.pop (n);
    yysemantic_stack_.pop (n);
    yylocation_stack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  mcmas_parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  mcmas_parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  mcmas_parser::debug_level_type
  mcmas_parser::debug_level () const
  {
    return yydebug_;
  }

  void
  mcmas_parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif

  inline bool
  mcmas_parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  inline bool
  mcmas_parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  mcmas_parser::parse ()
  {
    /// Lookahead and lookahead in internal form.
    int yychar = yyempty_;
    int yytoken = 0;

    /* State.  */
    int yyn;
    int yylen = 0;
    int yystate = 0;

    /* Error handling.  */
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// Semantic value of the lookahead.
    semantic_type yylval;
    /// Location of the lookahead.
    location_type yylloc;
    /// The locations where the error started and ended.
    location_type yyerror_range[3];

    /// $$.
    semantic_type yyval;
    /// @$.
    location_type yyloc;

    int yyresult;

    YYCDEBUG << "Starting parse" << std::endl;


    /* User initialization code.  */
    
/* Line 565 of lalr1.cc  */
#line 30 "parser/nssis_new.yy"
{
  /* Initialize the initial location.*/
  yylloc.begin.filename = yylloc.end.filename = &driver.file;
}

/* Line 565 of lalr1.cc  */
#line 730 "parser/nssis.cc"

    /* Initialize the stacks.  The initial state will be pushed in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystate_stack_ = state_stack_type (0);
    yysemantic_stack_ = semantic_stack_type (0);
    yylocation_stack_ = location_stack_type (0);
    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yylloc);

    /* New state.  */
  yynewstate:
    yystate_stack_.push (yystate);
    YYCDEBUG << "Entering state " << yystate << std::endl;

    /* Accept?  */
    if (yystate == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    /* Backup.  */
  yybackup:

    /* Try to take a decision without lookahead.  */
    yyn = yypact_[yystate];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    /* Read a lookahead token.  */
    if (yychar == yyempty_)
      {
	YYCDEBUG << "Reading a token: ";
	yychar = yylex (&yylval, &yylloc, driver);
      }


    /* Convert token to internal form.  */
    if (yychar <= yyeof_)
      {
	yychar = yytoken = yyeof_;
	YYCDEBUG << "Now at end of input." << std::endl;
      }
    else
      {
	yytoken = yytranslate_ (yychar);
	YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
      }

    /* If the proper action on seeing token YYTOKEN is to reduce or to
       detect an error, take that action.  */
    yyn += yytoken;
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yytoken)
      goto yydefault;

    /* Reduce or error.  */
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
	if (yy_table_value_is_error_ (yyn))
	  goto yyerrlab;
	yyn = -yyn;
	goto yyreduce;
      }

    /* Shift the lookahead token.  */
    YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

    /* Discard the token being shifted.  */
    yychar = yyempty_;

    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yylloc);

    /* Count tokens shifted since error; after three, turn off error
       status.  */
    if (yyerrstatus_)
      --yyerrstatus_;

    yystate = yyn;
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystate];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    /* If YYLEN is nonzero, implement the default value of the action:
       `$$ = $1'.  Otherwise, use the top of the stack.

       Otherwise, the following line sets YYVAL to garbage.
       This behavior is undocumented and Bison
       users should not rely upon it.  */
    if (yylen)
      yyval = yysemantic_stack_[yylen - 1];
    else
      yyval = yysemantic_stack_[0];

    {
      slice<location_type, location_stack_type> slice (yylocation_stack_, yylen);
      YYLLOC_DEFAULT (yyloc, slice, yylen);
    }
    YY_REDUCE_PRINT (yyn);
    switch (yyn)
      {
	  case 4:

/* Line 690 of lalr1.cc  */
#line 299 "parser/nssis_new.yy"
    {
    options["smv"] = 0;
 }
    break;

  case 5:

/* Line 690 of lalr1.cc  */
#line 302 "parser/nssis_new.yy"
    {
    options["smv"] = 1;
 }
    break;

  case 6:

/* Line 690 of lalr1.cc  */
#line 305 "parser/nssis_new.yy"
    {
  driver.syntax_error = true;
 }
    break;

  case 19:

/* Line 690 of lalr1.cc  */
#line 321 "parser/nssis_new.yy"
    {
   basic_agent *env = new basic_agent((*string_table)[0], new string("IR"), NULL, new map<string, basictype *>, new vector<basictype *>,
					  new map<string, basictype *>, new vector<basictype *>, NULL, new set<string>, 
					  new vector<protocol_line*>, new vector<evolution_line *>);
   (*is_agents)["Environment"] = env;
   agents->insert(agents->begin(), env);
  }
    break;

  case 20:

/* Line 690 of lalr1.cc  */
#line 328 "parser/nssis_new.yy"
    {
   basic_agent *env = new basic_agent((*string_table)[0], new string("IR"), NULL, new map<string, basictype *>, new vector<basictype *>,
					  new map<string, basictype *>, new vector<basictype *>, NULL, new set<string>, 
					  new vector<protocol_line*>, new vector<evolution_line *>);
   (*is_agents)["Environment"] = env;
   agents->insert(agents->begin(), env);
  }
    break;

  case 21:

/* Line 690 of lalr1.cc  */
#line 335 "parser/nssis_new.yy"
    {
   basic_agent *env = new basic_agent((*string_table)[0], new string("IR"), NULL, new map<string, basictype *>, new vector<basictype *>,
					  new map<string, basictype *>, new vector<basictype *>, NULL, new set<string>, 
					  new vector<protocol_line*>, new vector<evolution_line *>);
   (*is_agents)["Environment"] = env;
   agents->insert(agents->begin(), env);
  }
    break;

  case 22:

/* Line 690 of lalr1.cc  */
#line 342 "parser/nssis_new.yy"
    {
   basic_agent *env = new basic_agent((*string_table)[0], new string("IR"), NULL, new map<string, basictype *>, new vector<basictype *>, 
					  new map<string, basictype *>, new vector<basictype *>, NULL, new set<string>, 
					  new vector<protocol_line*>, new vector<evolution_line *>);
   (*is_agents)["Environment"] = env;
   agents->insert(agents->begin(), env);
  }
    break;

  case 23:

/* Line 690 of lalr1.cc  */
#line 349 "parser/nssis_new.yy"
    {
   basic_agent *env = new basic_agent((*string_table)[0], new string("IR"), NULL, new map<string, basictype *>, new vector<basictype *>, 
					  new map<string, basictype *>, new vector<basictype *>, NULL, new set<string>, 
					  new vector<protocol_line*>, new vector<evolution_line *>);
   (*is_agents)["Environment"] = env;
   agents->insert(agents->begin(), env);
  }
    break;

  case 24:

/* Line 690 of lalr1.cc  */
#line 356 "parser/nssis_new.yy"
    {
   basic_agent *env = new basic_agent((*string_table)[0], new string("IR"), NULL, new map<string, basictype *>, new vector<basictype *>, 
					  new map<string, basictype *>, new vector<basictype *>, NULL, new set<string>, 
					  new vector<protocol_line*>, new vector<evolution_line *>);
   (*is_agents)["Environment"] = env;
   agents->insert(agents->begin(), env);
  }
    break;

  case 25:

/* Line 690 of lalr1.cc  */
#line 363 "parser/nssis_new.yy"
    {
   basic_agent *env = new basic_agent((*string_table)[0], new string("IR"), NULL, new map<string, basictype *>, new vector<basictype *>, 
					  new map<string, basictype *>, new vector<basictype *>, NULL, new set<string>, 
					  new vector<protocol_line*>, new vector<evolution_line *>);
   (*is_agents)["Environment"] = env;
   agents->insert(agents->begin(), env);
  }
    break;

  case 26:

/* Line 690 of lalr1.cc  */
#line 370 "parser/nssis_new.yy"
    {
   basic_agent *env = new basic_agent((*string_table)[0], new string("IR"), NULL, new map<string, basictype *>, new vector<basictype *>, 
					  new map<string, basictype *>, new vector<basictype *>, NULL, new set<string>, 
					  new vector<protocol_line*>, new vector<evolution_line *>);
   (*is_agents)["Environment"] = env;
   agents->insert(agents->begin(), env);
  }
    break;

  case 27:

/* Line 690 of lalr1.cc  */
#line 377 "parser/nssis_new.yy"
    {
   basic_agent *env = new basic_agent((*string_table)[0], new string("IR"), NULL, new map<string, basictype *>, new vector<basictype *>, 
					  new map<string, basictype *>, new vector<basictype *>, NULL, new set<string>, 
					  new vector<protocol_line*>, new vector<evolution_line *>);
   (*is_agents)["Environment"] = env;
   agents->insert(agents->begin(), env);
  }
    break;

  case 28:

/* Line 690 of lalr1.cc  */
#line 384 "parser/nssis_new.yy"
    {
   basic_agent *env = new basic_agent((*string_table)[0], new string("IR"), NULL, new map<string, basictype *>, new vector<basictype *>, 
					  new map<string, basictype *>, new vector<basictype *>, NULL, new set<string>, 
					  new vector<protocol_line*>, new vector<evolution_line *>);
   (*is_agents)["Environment"] = env;
   agents->insert(agents->begin(), env);
  }
    break;

  case 29:

/* Line 690 of lalr1.cc  */
#line 391 "parser/nssis_new.yy"
    {
   basic_agent *env = new basic_agent((*string_table)[0], new string("IR"), NULL, new map<string, basictype *>, new vector<basictype *>, 
					  new map<string, basictype *>, new vector<basictype *>, NULL, new set<string>, 
					  new vector<protocol_line*>, new vector<evolution_line *>);
   (*is_agents)["Environment"] = env;
   agents->insert(agents->begin(), env);
  }
    break;

  case 30:

/* Line 690 of lalr1.cc  */
#line 398 "parser/nssis_new.yy"
    {
   basic_agent *env = new basic_agent((*string_table)[0], new string("IR"), NULL, new map<string, basictype *>, new vector<basictype *>, 
					  new map<string, basictype *>, new vector<basictype *>, NULL, new set<string>, 
					  new vector<protocol_line*>, new vector<evolution_line *>);
   (*is_agents)["Environment"] = env;
   agents->insert(agents->begin(), env);
  }
    break;

  case 31:

/* Line 690 of lalr1.cc  */
#line 408 "parser/nssis_new.yy"
    {
  (yyval.ival) = 1;
 }
    break;

  case 32:

/* Line 690 of lalr1.cc  */
#line 411 "parser/nssis_new.yy"
    {
  (yyval.ival) = 0;
  driver.syntax_error = true;
 }
    break;

  case 33:

/* Line 690 of lalr1.cc  */
#line 415 "parser/nssis_new.yy"
    {
  (yyval.ival) = 0;
  driver.syntax_error = true;
 }
    break;

  case 34:

/* Line 690 of lalr1.cc  */
#line 419 "parser/nssis_new.yy"
    {
  (yyval.ival) = 0;
  driver.syntax_error = true;
 }
    break;

  case 35:

/* Line 690 of lalr1.cc  */
#line 423 "parser/nssis_new.yy"
    {
  (yyval.ival) = 1;
 }
    break;

  case 36:

/* Line 690 of lalr1.cc  */
#line 426 "parser/nssis_new.yy"
    {
  (yyval.ival) = 0;
  driver.syntax_error = true;
 }
    break;

  case 37:

/* Line 690 of lalr1.cc  */
#line 430 "parser/nssis_new.yy"
    {
  (yyval.ival) = 0;
  driver.syntax_error = true;
 }
    break;

  case 38:

/* Line 690 of lalr1.cc  */
#line 434 "parser/nssis_new.yy"
    {
  (yyval.ival) = 0;
  driver.syntax_error = true;
 }
    break;

  case 39:

/* Line 690 of lalr1.cc  */
#line 439 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(9) - (1)].ival)==1 && (yysemantic_stack_[(9) - (2)].sval)!=NULL && (yysemantic_stack_[(9) - (3)].map_vec_basictype)!=NULL && (yysemantic_stack_[(9) - (4)].map_vec_basictype)!=NULL && (yysemantic_stack_[(9) - (6)].set_string)!=NULL && (yysemantic_stack_[(9) - (7)].vector_protocol_line)!=NULL && (yysemantic_stack_[(9) - (8)].vector_evolution_line)!=NULL && (yysemantic_stack_[(9) - (9)].ival)==1) { // redstates is NULL if no red state at all
    basic_agent *env = new basic_agent((*string_table)[0], (yysemantic_stack_[(9) - (2)].sval),NULL, (yysemantic_stack_[(9) - (3)].map_vec_basictype)->first, (yysemantic_stack_[(9) - (3)].map_vec_basictype)->second, (yysemantic_stack_[(9) - (4)].map_vec_basictype)->first, (yysemantic_stack_[(9) - (4)].map_vec_basictype)->second, (yysemantic_stack_[(9) - (5)]._bool_expression), (yysemantic_stack_[(9) - (6)].set_string), (yysemantic_stack_[(9) - (7)].vector_protocol_line), (yysemantic_stack_[(9) - (8)].vector_evolution_line));
    (*is_agents)["Environment"] = env;
    agents->push_back(env);
  }
 }
    break;

  case 40:

/* Line 690 of lalr1.cc  */
#line 446 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(8) - (1)].ival)==1 && (yysemantic_stack_[(8) - (2)].sval)!=NULL && (yysemantic_stack_[(8) - (3)].map_vec_basictype)!=NULL && (yysemantic_stack_[(8) - (4)].map_vec_basictype)!=NULL && (yysemantic_stack_[(8) - (5)].set_string)!=NULL && (yysemantic_stack_[(8) - (6)].vector_protocol_line)!=NULL && (yysemantic_stack_[(8) - (7)].vector_evolution_line)!=NULL && (yysemantic_stack_[(8) - (8)].ival)==1) { // redstates is NULL if no red state at all
    basic_agent *env = new basic_agent((*string_table)[0], (yysemantic_stack_[(8) - (2)].sval), NULL, (yysemantic_stack_[(8) - (3)].map_vec_basictype)->first, (yysemantic_stack_[(8) - (3)].map_vec_basictype)->second, (yysemantic_stack_[(8) - (4)].map_vec_basictype)->first, (yysemantic_stack_[(8) - (4)].map_vec_basictype)->second, NULL, (yysemantic_stack_[(8) - (5)].set_string), (yysemantic_stack_[(8) - (6)].vector_protocol_line), (yysemantic_stack_[(8) - (7)].vector_evolution_line));
    (*is_agents)["Environment"] = env;
    agents->push_back(env);
  }
 }
    break;

  case 41:

/* Line 690 of lalr1.cc  */
#line 453 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(8) - (1)].ival)==1 && (yysemantic_stack_[(8) - (2)].sval)!=NULL && (yysemantic_stack_[(8) - (3)].map_vec_basictype)!=NULL && (yysemantic_stack_[(8) - (5)].set_string)!=NULL && (yysemantic_stack_[(8) - (6)].vector_protocol_line)!=NULL && (yysemantic_stack_[(8) - (7)].vector_evolution_line)!=NULL && (yysemantic_stack_[(8) - (8)].ival)==1) { // redstates is NULL if no red state at all
    basic_agent *env = new basic_agent((*string_table)[0], (yysemantic_stack_[(8) - (2)].sval), NULL, new map<string, basictype *>, new vector<basictype *>, (yysemantic_stack_[(8) - (3)].map_vec_basictype)->first, (yysemantic_stack_[(8) - (3)].map_vec_basictype)->second, (yysemantic_stack_[(8) - (4)]._bool_expression), (yysemantic_stack_[(8) - (5)].set_string), (yysemantic_stack_[(8) - (6)].vector_protocol_line), (yysemantic_stack_[(8) - (7)].vector_evolution_line));
    (*is_agents)["Environment"] = env;
    agents->push_back(env);
  }
 }
    break;

  case 42:

/* Line 690 of lalr1.cc  */
#line 460 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(7) - (1)].ival)==1 && (yysemantic_stack_[(7) - (2)].sval)!=NULL && (yysemantic_stack_[(7) - (3)].map_vec_basictype)!=NULL && (yysemantic_stack_[(7) - (4)].set_string)!=NULL && (yysemantic_stack_[(7) - (5)].vector_protocol_line)!=NULL && (yysemantic_stack_[(7) - (6)].vector_evolution_line)!=NULL && (yysemantic_stack_[(7) - (7)].ival)==1) { // redstates is NULL if no red state at all
    basic_agent *env = new basic_agent((*string_table)[0],(yysemantic_stack_[(7) - (2)].sval), NULL, new map<string, basictype *>, new vector<basictype *>, (yysemantic_stack_[(7) - (3)].map_vec_basictype)->first, (yysemantic_stack_[(7) - (3)].map_vec_basictype)->second, NULL, (yysemantic_stack_[(7) - (4)].set_string), (yysemantic_stack_[(7) - (5)].vector_protocol_line), (yysemantic_stack_[(7) - (6)].vector_evolution_line));
    (*is_agents)["Environment"] = env;
    agents->push_back(env);
  }
 }
    break;

  case 43:

/* Line 690 of lalr1.cc  */
#line 467 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(8) - (1)].ival)==1 && (yysemantic_stack_[(8) - (2)].sval)!=NULL && (yysemantic_stack_[(8) - (3)].map_vec_basictype)!=NULL && (yysemantic_stack_[(8) - (5)].set_string)!=NULL && (yysemantic_stack_[(8) - (6)].vector_protocol_line)!=NULL && (yysemantic_stack_[(8) - (7)].vector_evolution_line)!=NULL && (yysemantic_stack_[(8) - (8)].ival)==1) { // redstates is NULL if no red state at all
    basic_agent *env = new basic_agent((*string_table)[0], (yysemantic_stack_[(8) - (2)].sval), NULL, (yysemantic_stack_[(8) - (3)].map_vec_basictype)->first, (yysemantic_stack_[(8) - (3)].map_vec_basictype)->second, new map<string, basictype *>, new vector<basictype *>, (yysemantic_stack_[(8) - (4)]._bool_expression), (yysemantic_stack_[(8) - (5)].set_string), (yysemantic_stack_[(8) - (6)].vector_protocol_line), (yysemantic_stack_[(8) - (7)].vector_evolution_line));
    (*is_agents)["Environment"] = env;
    agents->push_back(env);
  }
 }
    break;

  case 44:

/* Line 690 of lalr1.cc  */
#line 474 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(7) - (1)].ival)==1 && (yysemantic_stack_[(7) - (2)].sval)!=NULL && (yysemantic_stack_[(7) - (3)].map_vec_basictype)!=NULL && (yysemantic_stack_[(7) - (4)].set_string)!=NULL && (yysemantic_stack_[(7) - (5)].vector_protocol_line)!=NULL && (yysemantic_stack_[(7) - (6)].vector_evolution_line)!=NULL && (yysemantic_stack_[(7) - (7)].ival)==1) { // redstates is NULL if no red state at all
    basic_agent *env = new basic_agent((*string_table)[0], (yysemantic_stack_[(7) - (2)].sval), NULL, (yysemantic_stack_[(7) - (3)].map_vec_basictype)->first, (yysemantic_stack_[(7) - (3)].map_vec_basictype)->second, new map<string, basictype *>, new vector<basictype *>, NULL, (yysemantic_stack_[(7) - (4)].set_string), (yysemantic_stack_[(7) - (5)].vector_protocol_line), (yysemantic_stack_[(7) - (6)].vector_evolution_line));
    (*is_agents)["Environment"] = env;
    agents->push_back(env);
  }
 }
    break;

  case 45:

/* Line 690 of lalr1.cc  */
#line 481 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(7) - (1)].ival)==1 && (yysemantic_stack_[(7) - (2)].sval)!=NULL && (yysemantic_stack_[(7) - (4)].set_string)!=NULL && (yysemantic_stack_[(7) - (5)].vector_protocol_line)!=NULL && (yysemantic_stack_[(7) - (6)].vector_evolution_line)!=NULL && (yysemantic_stack_[(7) - (7)].ival)==1) { // redstates is NULL if no red state at all
    basic_agent *env = new basic_agent((*string_table)[0],(yysemantic_stack_[(7) - (2)].sval), NULL, new map<string, basictype *>, new vector<basictype *>, 
				       new map<string, basictype *>, new vector<basictype *>, (yysemantic_stack_[(7) - (3)]._bool_expression), (yysemantic_stack_[(7) - (4)].set_string), (yysemantic_stack_[(7) - (5)].vector_protocol_line), (yysemantic_stack_[(7) - (6)].vector_evolution_line));
    (*is_agents)["Environment"] = env;
    agents->push_back(env);
  }
 }
    break;

  case 46:

/* Line 690 of lalr1.cc  */
#line 489 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(6) - (1)].ival)==1 && (yysemantic_stack_[(6) - (2)].sval)!=NULL && (yysemantic_stack_[(6) - (3)].set_string)!=NULL && (yysemantic_stack_[(6) - (4)].vector_protocol_line)!=NULL && (yysemantic_stack_[(6) - (5)].vector_evolution_line)!=NULL && (yysemantic_stack_[(6) - (6)].ival)==1) { // redstates is NULL if no red state at all
    basic_agent *env = new basic_agent((*string_table)[0], (yysemantic_stack_[(6) - (2)].sval), NULL, new map<string, basictype *>, new vector<basictype *>, 
				       new map<string, basictype *>, new vector<basictype *>, NULL, (yysemantic_stack_[(6) - (3)].set_string), (yysemantic_stack_[(6) - (4)].vector_protocol_line), (yysemantic_stack_[(6) - (5)].vector_evolution_line));
    (*is_agents)["Environment"] = env;
    agents->push_back(env);
  }
 }
    break;

  case 47:

/* Line 690 of lalr1.cc  */
#line 497 "parser/nssis_new.yy"
    {
  driver.syntax_error = true;
  }
    break;

  case 48:

/* Line 690 of lalr1.cc  */
#line 503 "parser/nssis_new.yy"
    {
  (yyval.ival) = 1;
}
    break;

  case 49:

/* Line 690 of lalr1.cc  */
#line 506 "parser/nssis_new.yy"
    {
  (yyval.ival) = 0;
  driver.syntax_error = true;
}
    break;

  case 50:

/* Line 690 of lalr1.cc  */
#line 510 "parser/nssis_new.yy"
    {
  (yyval.ival) = 0;
  driver.syntax_error = true;
}
    break;

  case 51:

/* Line 690 of lalr1.cc  */
#line 514 "parser/nssis_new.yy"
    {
  (yyval.ival) = 0;
  driver.syntax_error = true;
}
    break;

  case 52:

/* Line 690 of lalr1.cc  */
#line 518 "parser/nssis_new.yy"
    {
  (yyval.ival) = 1;
  }
    break;

  case 53:

/* Line 690 of lalr1.cc  */
#line 521 "parser/nssis_new.yy"
    {
  (yyval.ival) = 0;
  driver.syntax_error = true;
}
    break;

  case 54:

/* Line 690 of lalr1.cc  */
#line 525 "parser/nssis_new.yy"
    {
  (yyval.ival) = 0;
  driver.syntax_error = true;
}
    break;

  case 55:

/* Line 690 of lalr1.cc  */
#line 529 "parser/nssis_new.yy"
    {
  (yyval.ival) = 0;
  driver.syntax_error = true;
}
    break;

  case 56:

/* Line 690 of lalr1.cc  */
#line 534 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(3) - (1)].ival)==1 && (yysemantic_stack_[(3) - (3)].ival)==1)
    (yyval.sval) = (yysemantic_stack_[(3) - (2)].sval);
  else
	(yyval.sval) = NULL;
}
    break;

  case 57:

/* Line 690 of lalr1.cc  */
#line 540 "parser/nssis_new.yy"
    {
	(yyval.sval) = NULL ;
}
    break;

  case 58:

/* Line 690 of lalr1.cc  */
#line 543 "parser/nssis_new.yy"
    {
	if((yysemantic_stack_[(2) - (1)].sval)!=NULL) {
	 int i=search_string_table((yysemantic_stack_[(2) - (1)].sval));
	 if(i>=0){
	   (yyval.sval)=new string(*(yysemantic_stack_[(2) - (1)].sval));
	   free((yysemantic_stack_[(2) - (1)].sval));
	 }
	 else{
       (yyval.sval)=new string(*(yysemantic_stack_[(2) - (1)].sval));
	   string_table->push_back((yysemantic_stack_[(2) - (1)].sval));
	 }
	}
	else
	 (yyval.sval)=NULL;
}
    break;

  case 59:

/* Line 690 of lalr1.cc  */
#line 558 "parser/nssis_new.yy"
    {
	(yyval.sval) = NULL;
	driver.syntax_error = true;
	USE((yysemantic_stack_[(2) - (1)].sval));
}
    break;

  case 60:

/* Line 690 of lalr1.cc  */
#line 566 "parser/nssis_new.yy"
    {
  (yyval.ival) = 1;
 }
    break;

  case 61:

/* Line 690 of lalr1.cc  */
#line 569 "parser/nssis_new.yy"
    {
  (yyval.ival) = 0;
  driver.syntax_error = true;
 }
    break;

  case 62:

/* Line 690 of lalr1.cc  */
#line 573 "parser/nssis_new.yy"
    {
  (yyval.ival) = 0;
  driver.syntax_error = true;
 }
    break;

  case 63:

/* Line 690 of lalr1.cc  */
#line 577 "parser/nssis_new.yy"
    {
  (yyval.ival) = 0;
  driver.syntax_error = true;
 }
    break;

  case 64:

/* Line 690 of lalr1.cc  */
#line 581 "parser/nssis_new.yy"
    {
  (yyval.ival) = 1;
 }
    break;

  case 65:

/* Line 690 of lalr1.cc  */
#line 584 "parser/nssis_new.yy"
    {
  (yyval.ival) = 0;
  driver.syntax_error = true;
 }
    break;

  case 66:

/* Line 690 of lalr1.cc  */
#line 588 "parser/nssis_new.yy"
    {
  (yyval.ival) = 0;
  driver.syntax_error = true;
 }
    break;

  case 67:

/* Line 690 of lalr1.cc  */
#line 592 "parser/nssis_new.yy"
    {
  (yyval.ival) = 0;
  driver.syntax_error = true;
 }
    break;

  case 68:

/* Line 690 of lalr1.cc  */
#line 596 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(3) - (1)].ival)==1 && (yysemantic_stack_[(3) - (3)].ival)==1)
    (yyval.map_vec_basictype) = (yysemantic_stack_[(3) - (2)].map_vec_basictype);
  else
    (yyval.map_vec_basictype) = NULL;
 }
    break;

  case 69:

/* Line 690 of lalr1.cc  */
#line 602 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(2) - (1)].ival)==1 && (yysemantic_stack_[(2) - (2)].ival)==1) {
    map<string, basictype *>* a = new map<string, basictype *>;
    vector<basictype *>* b = new vector<basictype *>;
    (yyval.map_vec_basictype) = new pair<map<string, basictype *>*, vector<basictype *>* >(a, b);
  } else
    (yyval.map_vec_basictype) = NULL;
 }
    break;

  case 70:

/* Line 690 of lalr1.cc  */
#line 610 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(2) - (1)]._basictype)!=NULL) {
    map<string, basictype *>* a = new map<string, basictype *>;
    vector<basictype *>* b = new vector<basictype *>;
    (yyval.map_vec_basictype) = new pair<map<string, basictype *>*, vector<basictype *>* >(a, b);
    (*a)[(yysemantic_stack_[(2) - (1)]._basictype)->get_name()] = (yysemantic_stack_[(2) - (1)]._basictype);
    b->push_back((yysemantic_stack_[(2) - (1)]._basictype));
  } else
    (yyval.map_vec_basictype) = NULL;
 }
    break;

  case 71:

/* Line 690 of lalr1.cc  */
#line 620 "parser/nssis_new.yy"
    {
  (yyval.map_vec_basictype) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(2) - (1)]._basictype));
 }
    break;

  case 72:

/* Line 690 of lalr1.cc  */
#line 625 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(3) - (1)].map_vec_basictype)!=NULL && (yysemantic_stack_[(3) - (2)]._basictype)!=NULL) {
    if((yysemantic_stack_[(3) - (1)].map_vec_basictype)->first->find((yysemantic_stack_[(3) - (2)]._basictype)->get_name()) != (yysemantic_stack_[(3) - (1)].map_vec_basictype)->first->end()) {
			if (options["quiet"] == 0)			
				cout << "warning: type " << (yysemantic_stack_[(3) - (2)]._basictype)->get_name() << " has already been defined." << endl;
    } else { 
      (*((yysemantic_stack_[(3) - (1)].map_vec_basictype)->first))[(yysemantic_stack_[(3) - (2)]._basictype)->get_name()] = (yysemantic_stack_[(3) - (2)]._basictype);
      (yysemantic_stack_[(3) - (1)].map_vec_basictype)->second->push_back((yysemantic_stack_[(3) - (2)]._basictype));
      (yyval.map_vec_basictype) = (yysemantic_stack_[(3) - (1)].map_vec_basictype);
    }
  } else
    (yyval.map_vec_basictype) = NULL;
 }
    break;

  case 73:

/* Line 690 of lalr1.cc  */
#line 638 "parser/nssis_new.yy"
    {
  (yyval.map_vec_basictype) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(3) - (1)].map_vec_basictype));
  USE((yysemantic_stack_[(3) - (2)]._basictype));
 }
    break;

  case 74:

/* Line 690 of lalr1.cc  */
#line 644 "parser/nssis_new.yy"
    {
  (yyval.map_vec_basictype) = NULL;
  driver.syntax_error = true;
  }
    break;

  case 75:

/* Line 690 of lalr1.cc  */
#line 649 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(3) - (1)].sval)!=NULL) {
    int i = search_string_table((yysemantic_stack_[(3) - (1)].sval));
    if(i>=0) {
      (yyval._basictype) = new basictype((*string_table)[i]);
      free((yysemantic_stack_[(3) - (1)].sval));
    } else {
      (yyval._basictype) = new basictype((yysemantic_stack_[(3) - (1)].sval));
      string_table->push_back((yysemantic_stack_[(3) - (1)].sval));
    }
  } else
    (yyval._basictype) = NULL;
 }
    break;

  case 76:

/* Line 690 of lalr1.cc  */
#line 662 "parser/nssis_new.yy"
    {
  (yyval._basictype) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(3) - (1)].sval));
 }
    break;

  case 77:

/* Line 690 of lalr1.cc  */
#line 667 "parser/nssis_new.yy"
    {
  (yyval._basictype) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(3) - (1)].sval));
 }
    break;

  case 78:

/* Line 690 of lalr1.cc  */
#line 672 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(5) - (1)].sval)!=NULL) {
    if((yysemantic_stack_[(5) - (3)].ival)>(yysemantic_stack_[(5) - (5)].ival))
      cout << "Error: the lower bound " << (yysemantic_stack_[(5) - (3)].ival) << " is greater than the upper bound " << (yysemantic_stack_[(5) - (5)].ival) << endl;
    int i = search_string_table((yysemantic_stack_[(5) - (1)].sval));
    if(i>=0) {
      (yyval._basictype) = new rangedint((*string_table)[i], (yysemantic_stack_[(5) - (3)].ival), (yysemantic_stack_[(5) - (5)].ival));
      free((yysemantic_stack_[(5) - (1)].sval));
    } else {
      (yyval._basictype) = new rangedint((yysemantic_stack_[(5) - (1)].sval), (yysemantic_stack_[(5) - (3)].ival), (yysemantic_stack_[(5) - (5)].ival));
      string_table->push_back((yysemantic_stack_[(5) - (1)].sval));
    }
  }
  else
    (yyval._basictype) = NULL;
 }
    break;

  case 79:

/* Line 690 of lalr1.cc  */
#line 688 "parser/nssis_new.yy"
    {
  (yyval._basictype) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(5) - (1)].sval));
 }
    break;

  case 80:

/* Line 690 of lalr1.cc  */
#line 693 "parser/nssis_new.yy"
    {
  (yyval._basictype) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(5) - (1)].sval));
 }
    break;

  case 81:

/* Line 690 of lalr1.cc  */
#line 698 "parser/nssis_new.yy"
    {
  (yyval._basictype) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(5) - (1)].sval));
 }
    break;

  case 82:

/* Line 690 of lalr1.cc  */
#line 703 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(5) - (1)].sval)!=NULL && (yysemantic_stack_[(5) - (4)].set_string)!=NULL) {
    int i = search_string_table((yysemantic_stack_[(5) - (1)].sval));
    if(i>=0) {
      (yyval._basictype) = new enumerate((*string_table)[i], (yysemantic_stack_[(5) - (4)].set_string));
      free((yysemantic_stack_[(5) - (1)].sval));
    } else {
      (yyval._basictype) = new enumerate((yysemantic_stack_[(5) - (1)].sval), (yysemantic_stack_[(5) - (4)].set_string));
      string_table->push_back((yysemantic_stack_[(5) - (1)].sval));
    }
  } else
    (yyval._basictype) = NULL;
 }
    break;

  case 83:

/* Line 690 of lalr1.cc  */
#line 716 "parser/nssis_new.yy"
    {
  (yyval._basictype) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(4) - (1)].sval));
  USE((yysemantic_stack_[(4) - (3)].set_string));
 }
    break;

  case 84:

/* Line 690 of lalr1.cc  */
#line 722 "parser/nssis_new.yy"
    {
  (yyval._basictype) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(5) - (1)].sval));
  USE((yysemantic_stack_[(5) - (4)].set_string));
 }
    break;

  case 85:

/* Line 690 of lalr1.cc  */
#line 728 "parser/nssis_new.yy"
    {
  (yyval._basictype) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(4) - (1)].sval));
  USE((yysemantic_stack_[(4) - (3)].set_string));
 }
    break;

  case 86:

/* Line 690 of lalr1.cc  */
#line 734 "parser/nssis_new.yy"
    {
  (yyval._basictype) = NULL;
  driver.syntax_error = true;
 }
    break;

  case 87:

/* Line 690 of lalr1.cc  */
#line 738 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(1) - (1)].sval)!=NULL) {
    (yyval.set_string) = new set<string>;
    (yyval.set_string)->insert(*(yysemantic_stack_[(1) - (1)].sval));
    free ((yysemantic_stack_[(1) - (1)].sval));
  } else
    (yyval.set_string) = NULL;
 }
    break;

  case 88:

/* Line 690 of lalr1.cc  */
#line 746 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(3) - (1)].set_string)!=NULL && (yysemantic_stack_[(3) - (3)].sval)!=NULL) {
    pair<set<string>::iterator, bool> ret = (yysemantic_stack_[(3) - (1)].set_string)->insert(*(yysemantic_stack_[(3) - (3)].sval));
    if(!ret.second && options["quiet"] == 0)
      cout << "warning: " << *(yysemantic_stack_[(3) - (3)].sval) << " has been defined for the enum type." << endl;
    (yyval.set_string) = (yysemantic_stack_[(3) - (1)].set_string);
    free ((yysemantic_stack_[(3) - (3)].sval));
  } else
    (yyval.set_string) = NULL;
	USE((yysemantic_stack_[(3) - (1)].set_string));
 }
    break;

  case 89:

/* Line 690 of lalr1.cc  */
#line 757 "parser/nssis_new.yy"
    {
  (yyval.set_string) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(3) - (1)].set_string));
  USE((yysemantic_stack_[(3) - (3)].sval));
 }
    break;

  case 90:

/* Line 690 of lalr1.cc  */
#line 763 "parser/nssis_new.yy"
    {
  (yyval.set_string) = NULL;
  driver.syntax_error = true;
  }
    break;

  case 91:

/* Line 690 of lalr1.cc  */
#line 767 "parser/nssis_new.yy"
    {
  (yyval.ival) = (yysemantic_stack_[(1) - (1)].ival);
 }
    break;

  case 92:

/* Line 690 of lalr1.cc  */
#line 770 "parser/nssis_new.yy"
    {
  (yyval.ival) = 0-(yysemantic_stack_[(2) - (2)].ival);
 }
    break;

  case 93:

/* Line 690 of lalr1.cc  */
#line 773 "parser/nssis_new.yy"
    {
  (yyval.ival) = -1;
  driver.syntax_error = true;
 }
    break;

  case 94:

/* Line 690 of lalr1.cc  */
#line 777 "parser/nssis_new.yy"
    {
  (yyval.ival) = -1;
  driver.syntax_error = true;
  }
    break;

  case 95:

/* Line 690 of lalr1.cc  */
#line 783 "parser/nssis_new.yy"
    {
  (yyval.ival) = 1;
 }
    break;

  case 96:

/* Line 690 of lalr1.cc  */
#line 786 "parser/nssis_new.yy"
    {
  (yyval.ival) = 0;
  driver.syntax_error = true;
 }
    break;

  case 97:

/* Line 690 of lalr1.cc  */
#line 790 "parser/nssis_new.yy"
    {
  (yyval.ival) = 0;
  driver.syntax_error = true;
 }
    break;

  case 98:

/* Line 690 of lalr1.cc  */
#line 794 "parser/nssis_new.yy"
    {
  (yyval.ival) = 0;
  driver.syntax_error = true;
 }
    break;

  case 99:

/* Line 690 of lalr1.cc  */
#line 798 "parser/nssis_new.yy"
    {
  (yyval.ival) = 1;
 }
    break;

  case 100:

/* Line 690 of lalr1.cc  */
#line 801 "parser/nssis_new.yy"
    {
  (yyval.ival) = 0;
  driver.syntax_error = true;
 }
    break;

  case 101:

/* Line 690 of lalr1.cc  */
#line 805 "parser/nssis_new.yy"
    {
  (yyval.ival) = 0;
  driver.syntax_error = true;
 }
    break;

  case 102:

/* Line 690 of lalr1.cc  */
#line 809 "parser/nssis_new.yy"
    {
  (yyval.ival) = 0;
  driver.syntax_error = true;
 }
    break;

  case 103:

/* Line 690 of lalr1.cc  */
#line 813 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(3) - (1)].ival)==1 && (yysemantic_stack_[(3) - (3)].ival)==1)
    (yyval.map_vec_basictype) = (yysemantic_stack_[(3) - (2)].map_vec_basictype);
  else
    (yyval.map_vec_basictype) = NULL;
 }
    break;

  case 104:

/* Line 690 of lalr1.cc  */
#line 819 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(2) - (1)].ival)==1 && (yysemantic_stack_[(2) - (2)].ival)==1) {
    map<string, basictype *>* a = new map<string, basictype *>;
    vector<basictype *>* b = new vector<basictype *>;
    (yyval.map_vec_basictype) = new pair<map<string, basictype *>*, vector<basictype *>* >(a, b);
  } else
    (yyval.map_vec_basictype) = NULL;
 }
    break;

  case 105:

/* Line 690 of lalr1.cc  */
#line 827 "parser/nssis_new.yy"
    {
  (yyval.map_vec_basictype) = NULL;
  driver.syntax_error = true;
  }
    break;

  case 106:

/* Line 690 of lalr1.cc  */
#line 833 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(3) - (1)].ival)==1 && (yysemantic_stack_[(3) - (3)].ival)==1)
    (yyval.map_vec_basictype) = (yysemantic_stack_[(3) - (2)].map_vec_basictype);
  else
    (yyval.map_vec_basictype) = NULL;
 }
    break;

  case 107:

/* Line 690 of lalr1.cc  */
#line 839 "parser/nssis_new.yy"
    {
  (yyval.map_vec_basictype) = NULL;
  driver.syntax_error = true;
  }
    break;

  case 108:

/* Line 690 of lalr1.cc  */
#line 845 "parser/nssis_new.yy"
    {
  (yyval.ival) = 1;
 }
    break;

  case 109:

/* Line 690 of lalr1.cc  */
#line 848 "parser/nssis_new.yy"
    {
  (yyval.ival) = 0;
  driver.syntax_error = true;
 }
    break;

  case 110:

/* Line 690 of lalr1.cc  */
#line 852 "parser/nssis_new.yy"
    {
  (yyval.ival) = 0;
  driver.syntax_error = true;
 }
    break;

  case 111:

/* Line 690 of lalr1.cc  */
#line 856 "parser/nssis_new.yy"
    {
  (yyval.ival) = 0;
  driver.syntax_error = true;
 }
    break;

  case 112:

/* Line 690 of lalr1.cc  */
#line 860 "parser/nssis_new.yy"
    {
  (yyval.ival) = 1;
 }
    break;

  case 113:

/* Line 690 of lalr1.cc  */
#line 863 "parser/nssis_new.yy"
    {
  (yyval.ival) = 0;
  driver.syntax_error = true;
 }
    break;

  case 114:

/* Line 690 of lalr1.cc  */
#line 867 "parser/nssis_new.yy"
    {
  (yyval.ival) = 0;
  driver.syntax_error = true;
 }
    break;

  case 115:

/* Line 690 of lalr1.cc  */
#line 871 "parser/nssis_new.yy"
    {
  (yyval.ival) = 0;
  driver.syntax_error = true;
 }
    break;

  case 116:

/* Line 690 of lalr1.cc  */
#line 876 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(3) - (1)].ival)==1 && (yysemantic_stack_[(3) - (3)].ival)==1)
    (yyval._bool_expression) = (yysemantic_stack_[(3) - (2)]._bool_expression);
  else
    (yyval._bool_expression) = NULL;
 }
    break;

  case 117:

/* Line 690 of lalr1.cc  */
#line 882 "parser/nssis_new.yy"
    {
  (yyval._bool_expression) = NULL; 
 }
    break;

  case 118:

/* Line 690 of lalr1.cc  */
#line 885 "parser/nssis_new.yy"
    {
  (yyval._bool_expression) = NULL;
  driver.syntax_error = true;
  }
    break;

  case 119:

/* Line 690 of lalr1.cc  */
#line 890 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(3) - (1)].ival)==1 && (yysemantic_stack_[(3) - (3)].ival)==1)
    (yyval._bool_expression) = (yysemantic_stack_[(3) - (2)]._bool_expression);
  else
    (yyval._bool_expression) = NULL;
 }
    break;

  case 120:

/* Line 690 of lalr1.cc  */
#line 896 "parser/nssis_new.yy"
    {
  (yyval._bool_expression) = NULL; 
 }
    break;

  case 121:

/* Line 690 of lalr1.cc  */
#line 899 "parser/nssis_new.yy"
    {
  (yyval._bool_expression) = NULL;
  driver.syntax_error = true;
  }
    break;

  case 122:

/* Line 690 of lalr1.cc  */
#line 904 "parser/nssis_new.yy"
    {
  (yyval._bool_expression) = (yysemantic_stack_[(2) - (1)]._bool_expression);
  }
    break;

  case 123:

/* Line 690 of lalr1.cc  */
#line 907 "parser/nssis_new.yy"
    {
  (yyval._bool_expression) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(2) - (1)]._bool_expression));
  }
    break;

  case 124:

/* Line 690 of lalr1.cc  */
#line 912 "parser/nssis_new.yy"
    {
  (yyval._bool_expression) = NULL;
  driver.syntax_error = true;
  }
    break;

  case 125:

/* Line 690 of lalr1.cc  */
#line 917 "parser/nssis_new.yy"
    {
  (yyval._bool_expression) = (yysemantic_stack_[(2) - (1)]._bool_expression);
  }
    break;

  case 126:

/* Line 690 of lalr1.cc  */
#line 920 "parser/nssis_new.yy"
    {
  (yyval._bool_expression) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(2) - (1)]._bool_expression));
  }
    break;

  case 127:

/* Line 690 of lalr1.cc  */
#line 925 "parser/nssis_new.yy"
    {
  (yyval._bool_expression) = NULL;
  driver.syntax_error = true;
  }
    break;

  case 128:

/* Line 690 of lalr1.cc  */
#line 932 "parser/nssis_new.yy"
    {
  (yyval.ival) = 1;
 }
    break;

  case 129:

/* Line 690 of lalr1.cc  */
#line 935 "parser/nssis_new.yy"
    {
  (yyval.ival) = 0;
  driver.syntax_error = true;
 }
    break;

  case 130:

/* Line 690 of lalr1.cc  */
#line 939 "parser/nssis_new.yy"
    {
  (yyval.ival) = 0;
  driver.syntax_error = true;
 }
    break;

  case 131:

/* Line 690 of lalr1.cc  */
#line 943 "parser/nssis_new.yy"
    {
  (yyval.ival) = 0;
  driver.syntax_error = true;
 }
    break;

  case 132:

/* Line 690 of lalr1.cc  */
#line 947 "parser/nssis_new.yy"
    {
  (yyval.ival) = 1;
 }
    break;

  case 133:

/* Line 690 of lalr1.cc  */
#line 950 "parser/nssis_new.yy"
    {
  (yyval.ival) = 0;
  driver.syntax_error = true;
 }
    break;

  case 134:

/* Line 690 of lalr1.cc  */
#line 954 "parser/nssis_new.yy"
    {
  (yyval.ival) = 0;
  driver.syntax_error = true;
 }
    break;

  case 135:

/* Line 690 of lalr1.cc  */
#line 958 "parser/nssis_new.yy"
    {
  (yyval.ival) = 0;
  driver.syntax_error = true;
 }
    break;

  case 136:

/* Line 690 of lalr1.cc  */
#line 962 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(3) - (1)].ival)==1 && (yysemantic_stack_[(3) - (3)].ival)==1)
    (yyval.vector_evolution_line) = (yysemantic_stack_[(3) - (2)].vector_evolution_line);
  else
    (yyval.vector_evolution_line) = NULL;
 }
    break;

  case 137:

/* Line 690 of lalr1.cc  */
#line 968 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(2) - (1)].ival)==1 && (yysemantic_stack_[(2) - (2)].ival)==1)
    (yyval.vector_evolution_line) = new vector<evolution_line *>;
  else
    (yyval.vector_evolution_line) = NULL;
 }
    break;

  case 138:

/* Line 690 of lalr1.cc  */
#line 974 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(1) - (1)]._evolution_line)!=NULL) {
    (yyval.vector_evolution_line) = new vector<evolution_line *>;
    (yyval.vector_evolution_line)->push_back((yysemantic_stack_[(1) - (1)]._evolution_line));
  } else
    (yyval.vector_evolution_line) = NULL;
 }
    break;

  case 139:

/* Line 690 of lalr1.cc  */
#line 981 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(2) - (1)].vector_evolution_line)!=NULL && (yysemantic_stack_[(2) - (2)]._evolution_line)!=NULL) {
    (yysemantic_stack_[(2) - (1)].vector_evolution_line)->push_back((yysemantic_stack_[(2) - (2)]._evolution_line));
    (yyval.vector_evolution_line) = (yysemantic_stack_[(2) - (1)].vector_evolution_line);
  } else
    (yyval.vector_evolution_line) = NULL;
 }
    break;

  case 140:

/* Line 690 of lalr1.cc  */
#line 988 "parser/nssis_new.yy"
    {
  (yyval.vector_evolution_line) = NULL;
  driver.syntax_error = true;
  }
    break;

  case 141:

/* Line 690 of lalr1.cc  */
#line 992 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(4) - (1)].vector_assignment)!=NULL && (yysemantic_stack_[(4) - (3)]._bool_expression)!=NULL) 
    (yyval._evolution_line) = new evolution_line((yysemantic_stack_[(4) - (1)].vector_assignment), (yysemantic_stack_[(4) - (3)]._bool_expression));
  else
    (yyval._evolution_line) = NULL;
 }
    break;

  case 142:

/* Line 690 of lalr1.cc  */
#line 998 "parser/nssis_new.yy"
    {
  (yyval._evolution_line) = NULL;
  driver.syntax_error = true;
  }
    break;

  case 143:

/* Line 690 of lalr1.cc  */
#line 1002 "parser/nssis_new.yy"
    {
  (yyval.vector_assignment) = (yysemantic_stack_[(3) - (2)].vector_assignment);
 }
    break;

  case 144:

/* Line 690 of lalr1.cc  */
#line 1005 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(3) - (1)].vector_assignment)!=NULL && (yysemantic_stack_[(3) - (3)].vector_assignment)!=NULL) {
    (yyval.vector_assignment) = (yysemantic_stack_[(3) - (1)].vector_assignment);
    vector<assignment*>::iterator i;
    for(i=(yysemantic_stack_[(3) - (3)].vector_assignment)->begin(); i != (yysemantic_stack_[(3) - (3)].vector_assignment)->end(); i++)
      (yyval.vector_assignment)->push_back(*i);
  } else
    (yyval.vector_assignment) = NULL;
 }
    break;

  case 145:

/* Line 690 of lalr1.cc  */
#line 1014 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(3) - (1)].sval)!=NULL && (yysemantic_stack_[(3) - (3)]._expression)!=NULL) {
    assignment *a;
    int i = search_string_table((yysemantic_stack_[(3) - (1)].sval));
    if(i>=0) {
      a = new assignment((*string_table)[i], (yysemantic_stack_[(3) - (3)]._expression));
      free((yysemantic_stack_[(3) - (1)].sval));
    } else {
      a = new assignment((yysemantic_stack_[(3) - (1)].sval), (yysemantic_stack_[(3) - (3)]._expression));
      string_table->push_back((yysemantic_stack_[(3) - (1)].sval));
    }
    (yyval.vector_assignment) = new vector<assignment*>;
    (yyval.vector_assignment)->push_back(a);
  } else
    (yyval.vector_assignment) = NULL;
 }
    break;

  case 146:

/* Line 690 of lalr1.cc  */
#line 1030 "parser/nssis_new.yy"
    {
  (yyval.vector_assignment) = NULL;
  driver.syntax_error = true;
  }
    break;

  case 147:

/* Line 690 of lalr1.cc  */
#line 1035 "parser/nssis_new.yy"
    {
  (yyval.vector_assignment) = (yysemantic_stack_[(3) - (2)].vector_assignment);
 }
    break;

  case 148:

/* Line 690 of lalr1.cc  */
#line 1038 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(3) - (1)].vector_assignment)!=NULL && (yysemantic_stack_[(3) - (3)].vector_assignment)!=NULL) {
    (yyval.vector_assignment) = (yysemantic_stack_[(3) - (1)].vector_assignment);
    vector<assignment*>::iterator i;
    for(i=(yysemantic_stack_[(3) - (3)].vector_assignment)->begin(); i != (yysemantic_stack_[(3) - (3)].vector_assignment)->end(); i++)
      (yyval.vector_assignment)->push_back(*i);
  } else
    (yyval.vector_assignment) = NULL;
 }
    break;

  case 149:

/* Line 690 of lalr1.cc  */
#line 1047 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(3) - (1)].sval)!=NULL && (yysemantic_stack_[(3) - (3)]._expression)!=NULL) {
    assignment *a;
    int i = search_string_table((yysemantic_stack_[(3) - (1)].sval));
    if(i>=0) {
      a = new assignment((*string_table)[i], (yysemantic_stack_[(3) - (3)]._expression));
      free((yysemantic_stack_[(3) - (1)].sval));
    } else {
      a = new assignment((yysemantic_stack_[(3) - (1)].sval), (yysemantic_stack_[(3) - (3)]._expression));
      string_table->push_back((yysemantic_stack_[(3) - (1)].sval));
    }
    (yyval.vector_assignment) = new vector<assignment*>;
    (yyval.vector_assignment)->push_back(a);
  } else
    (yyval.vector_assignment) = NULL;
 }
    break;

  case 150:

/* Line 690 of lalr1.cc  */
#line 1063 "parser/nssis_new.yy"
    {
  (yyval.vector_assignment) = NULL;
  driver.syntax_error = true;
  }
    break;

  case 151:

/* Line 690 of lalr1.cc  */
#line 1068 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(1) - (1)]._basic_agent)!=NULL) {
    (*is_agents)[(yysemantic_stack_[(1) - (1)]._basic_agent)->get_name()] = (yysemantic_stack_[(1) - (1)]._basic_agent);
    agents->push_back((yysemantic_stack_[(1) - (1)]._basic_agent));
  } 
 }
    break;

  case 152:

/* Line 690 of lalr1.cc  */
#line 1074 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(2) - (2)]._basic_agent)!=NULL) {
    if(is_agents->find((yysemantic_stack_[(2) - (2)]._basic_agent)->get_name()) != is_agents->end()) {
			if (options["quiet"] == 0)
				cout << "warning: agent " << (yysemantic_stack_[(2) - (2)]._basic_agent)->get_name() << " already exists." << endl;
    } else
      agents->push_back((yysemantic_stack_[(2) - (2)]._basic_agent));
    (*is_agents)[(yysemantic_stack_[(2) - (2)]._basic_agent)->get_name()] = (yysemantic_stack_[(2) - (2)]._basic_agent);
  }
 }
    break;

  case 153:

/* Line 690 of lalr1.cc  */
#line 1084 "parser/nssis_new.yy"
    {
  driver.syntax_error = true;
  }
    break;

  case 154:

/* Line 690 of lalr1.cc  */
#line 1088 "parser/nssis_new.yy"
    {
  (yyval.ival) = 1;
 }
    break;

  case 155:

/* Line 690 of lalr1.cc  */
#line 1091 "parser/nssis_new.yy"
    {
  (yyval.ival) = 0;
  driver.syntax_error = true;
 }
    break;

  case 156:

/* Line 690 of lalr1.cc  */
#line 1095 "parser/nssis_new.yy"
    {
  (yyval.ival) = 1;
 }
    break;

  case 157:

/* Line 690 of lalr1.cc  */
#line 1098 "parser/nssis_new.yy"
    {
  (yyval.ival) = 0;
  driver.syntax_error = true;
 }
    break;

  case 158:

/* Line 690 of lalr1.cc  */
#line 1102 "parser/nssis_new.yy"
    {
  (yyval.ival) = 0;
  driver.syntax_error = true;
 }
    break;

  case 159:

/* Line 690 of lalr1.cc  */
#line 1106 "parser/nssis_new.yy"
    {
  (yyval.ival) = 0;
  driver.syntax_error = true;
 }
    break;

  case 160:

/* Line 690 of lalr1.cc  */
#line 1111 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(9) - (1)].ival)==1 && (yysemantic_stack_[(9) - (2)].sval)!=NULL && (yysemantic_stack_[(9) - (3)].sval)!=NULL && (yysemantic_stack_[(9) - (4)].map_vec_basictype)!=NULL && 
     (yysemantic_stack_[(9) - (6)].set_string)!=NULL && (yysemantic_stack_[(9) - (7)].vector_protocol_line)!=NULL && (yysemantic_stack_[(9) - (8)].vector_evolution_line)!=NULL && (yysemantic_stack_[(9) - (9)].ival)==1) {// redstates is NULL if no red state at all
    int i = search_string_table((yysemantic_stack_[(9) - (2)].sval));
    if(i>=0) {
      (yyval._basic_agent) = new basic_agent((*string_table)[i],(yysemantic_stack_[(9) - (3)].sval), NULL, NULL, NULL, (yysemantic_stack_[(9) - (4)].map_vec_basictype)->first, (yysemantic_stack_[(9) - (4)].map_vec_basictype)->second, (yysemantic_stack_[(9) - (5)]._bool_expression), (yysemantic_stack_[(9) - (6)].set_string), (yysemantic_stack_[(9) - (7)].vector_protocol_line), (yysemantic_stack_[(9) - (8)].vector_evolution_line));
      free((yysemantic_stack_[(9) - (2)].sval));
    } else {
      (yyval._basic_agent) = new basic_agent((yysemantic_stack_[(9) - (2)].sval), (yysemantic_stack_[(9) - (3)].sval), NULL, NULL, NULL, (yysemantic_stack_[(9) - (4)].map_vec_basictype)->first, (yysemantic_stack_[(9) - (4)].map_vec_basictype)->second, (yysemantic_stack_[(9) - (5)]._bool_expression), (yysemantic_stack_[(9) - (6)].set_string), (yysemantic_stack_[(9) - (7)].vector_protocol_line), (yysemantic_stack_[(9) - (8)].vector_evolution_line));
      string_table->push_back((yysemantic_stack_[(9) - (2)].sval));
    }
  } else
    (yyval._basic_agent) = NULL;
 }
    break;

  case 161:

/* Line 690 of lalr1.cc  */
#line 1125 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(8) - (1)].ival)==1 && (yysemantic_stack_[(8) - (2)].sval)!=NULL && (yysemantic_stack_[(8) - (3)].sval)!=NULL && 
     (yysemantic_stack_[(8) - (4)].map_vec_basictype)!=NULL && (yysemantic_stack_[(8) - (5)].set_string)!=NULL && (yysemantic_stack_[(8) - (6)].vector_protocol_line)!=NULL && (yysemantic_stack_[(8) - (7)].vector_evolution_line)!=NULL && (yysemantic_stack_[(8) - (8)].ival)==1) {// redstates is NULL if no red state at all
    int i = search_string_table((yysemantic_stack_[(8) - (2)].sval));
    if(i>=0) {
      (yyval._basic_agent) = new basic_agent((*string_table)[i], (yysemantic_stack_[(8) - (3)].sval), NULL, NULL, NULL, (yysemantic_stack_[(8) - (4)].map_vec_basictype)->first, (yysemantic_stack_[(8) - (4)].map_vec_basictype)->second, NULL, (yysemantic_stack_[(8) - (5)].set_string), (yysemantic_stack_[(8) - (6)].vector_protocol_line), (yysemantic_stack_[(8) - (7)].vector_evolution_line));
      free((yysemantic_stack_[(8) - (2)].sval));
    } else {
      (yyval._basic_agent) = new basic_agent((yysemantic_stack_[(8) - (2)].sval), (yysemantic_stack_[(8) - (3)].sval), NULL, NULL, NULL, (yysemantic_stack_[(8) - (4)].map_vec_basictype)->first, (yysemantic_stack_[(8) - (4)].map_vec_basictype)->second, NULL, (yysemantic_stack_[(8) - (5)].set_string), (yysemantic_stack_[(8) - (6)].vector_protocol_line), (yysemantic_stack_[(8) - (7)].vector_evolution_line));
      string_table->push_back((yysemantic_stack_[(8) - (2)].sval));
    }
  } else
    (yyval._basic_agent) = NULL;
 }
    break;

  case 162:

/* Line 690 of lalr1.cc  */
#line 1139 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(10) - (1)].ival)==1 && (yysemantic_stack_[(10) - (2)].sval)!=NULL && (yysemantic_stack_[(10) - (3)].sval)!=NULL && (yysemantic_stack_[(10) - (5)].map_vec_basictype)!=NULL && 
     (yysemantic_stack_[(10) - (7)].set_string)!=NULL && (yysemantic_stack_[(10) - (8)].vector_protocol_line)!=NULL && (yysemantic_stack_[(10) - (9)].vector_evolution_line)!=NULL && (yysemantic_stack_[(10) - (10)].ival)==1) {// redstates is NULL if no red state at all
    int i = search_string_table((yysemantic_stack_[(10) - (2)].sval));
    if(i>=0) {
      (yyval._basic_agent) = new basic_agent((*string_table)[i], (yysemantic_stack_[(10) - (3)].sval), (yysemantic_stack_[(10) - (4)].map_string_variable), NULL, NULL, (yysemantic_stack_[(10) - (5)].map_vec_basictype)->first, (yysemantic_stack_[(10) - (5)].map_vec_basictype)->second, (yysemantic_stack_[(10) - (6)]._bool_expression), (yysemantic_stack_[(10) - (7)].set_string), (yysemantic_stack_[(10) - (8)].vector_protocol_line), (yysemantic_stack_[(10) - (9)].vector_evolution_line));
      free((yysemantic_stack_[(10) - (2)].sval));
    } else {
      (yyval._basic_agent) = new basic_agent((yysemantic_stack_[(10) - (2)].sval), (yysemantic_stack_[(10) - (3)].sval),(yysemantic_stack_[(10) - (4)].map_string_variable), NULL, NULL, (yysemantic_stack_[(10) - (5)].map_vec_basictype)->first, (yysemantic_stack_[(10) - (5)].map_vec_basictype)->second, (yysemantic_stack_[(10) - (6)]._bool_expression), (yysemantic_stack_[(10) - (7)].set_string), (yysemantic_stack_[(10) - (8)].vector_protocol_line), (yysemantic_stack_[(10) - (9)].vector_evolution_line));
      string_table->push_back((yysemantic_stack_[(10) - (2)].sval));
    }
  } else
    (yyval._basic_agent) = NULL;
 }
    break;

  case 163:

/* Line 690 of lalr1.cc  */
#line 1153 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(9) - (1)].ival)==1 && (yysemantic_stack_[(9) - (2)].sval)!=NULL && (yysemantic_stack_[(9) - (3)].sval)!=NULL && 
     (yysemantic_stack_[(9) - (5)].map_vec_basictype)!=NULL && (yysemantic_stack_[(9) - (6)].set_string)!=NULL && (yysemantic_stack_[(9) - (7)].vector_protocol_line)!=NULL && (yysemantic_stack_[(9) - (8)].vector_evolution_line)!=NULL && (yysemantic_stack_[(9) - (9)].ival)==1) {// redstates is NULL if no red state at all
    int i = search_string_table((yysemantic_stack_[(9) - (2)].sval));
    if(i>=0) {
      (yyval._basic_agent) = new basic_agent((*string_table)[i],(yysemantic_stack_[(9) - (3)].sval),(yysemantic_stack_[(9) - (4)].map_string_variable), NULL, NULL, (yysemantic_stack_[(9) - (5)].map_vec_basictype)->first, (yysemantic_stack_[(9) - (5)].map_vec_basictype)->second, NULL, (yysemantic_stack_[(9) - (6)].set_string), (yysemantic_stack_[(9) - (7)].vector_protocol_line), (yysemantic_stack_[(9) - (8)].vector_evolution_line));
      free((yysemantic_stack_[(9) - (2)].sval));
    } else {
      (yyval._basic_agent) = new basic_agent((yysemantic_stack_[(9) - (2)].sval),(yysemantic_stack_[(9) - (3)].sval), (yysemantic_stack_[(9) - (4)].map_string_variable), NULL, NULL, (yysemantic_stack_[(9) - (5)].map_vec_basictype)->first, (yysemantic_stack_[(9) - (5)].map_vec_basictype)->second, NULL, (yysemantic_stack_[(9) - (6)].set_string), (yysemantic_stack_[(9) - (7)].vector_protocol_line), (yysemantic_stack_[(9) - (8)].vector_evolution_line));
      string_table->push_back((yysemantic_stack_[(9) - (2)].sval));
    }
  } else
    (yyval._basic_agent) = NULL;
 }
    break;

  case 164:

/* Line 690 of lalr1.cc  */
#line 1167 "parser/nssis_new.yy"
    {
  (yyval._basic_agent) = NULL;
  driver.syntax_error = true;
  }
    break;

  case 165:

/* Line 690 of lalr1.cc  */
#line 1173 "parser/nssis_new.yy"
    {
  (yyval.ival) = 1;
 }
    break;

  case 166:

/* Line 690 of lalr1.cc  */
#line 1176 "parser/nssis_new.yy"
    {
  (yyval.ival) = 0;
  driver.syntax_error = true;
 }
    break;

  case 167:

/* Line 690 of lalr1.cc  */
#line 1180 "parser/nssis_new.yy"
    {
  (yyval.ival) = 0;
  driver.syntax_error = true;
 }
    break;

  case 168:

/* Line 690 of lalr1.cc  */
#line 1184 "parser/nssis_new.yy"
    {
  (yyval.ival) = 0;
  driver.syntax_error = true;
 }
    break;

  case 169:

/* Line 690 of lalr1.cc  */
#line 1188 "parser/nssis_new.yy"
    {
  (yyval.ival) = 0;
  driver.syntax_error = true;
 }
    break;

  case 170:

/* Line 690 of lalr1.cc  */
#line 1192 "parser/nssis_new.yy"
    {
  (yyval.ival) = 0;
  driver.syntax_error = true;
 }
    break;

  case 171:

/* Line 690 of lalr1.cc  */
#line 1196 "parser/nssis_new.yy"
    {
  (yyval.ival) = 0;
  driver.syntax_error = true;
 }
    break;

  case 172:

/* Line 690 of lalr1.cc  */
#line 1200 "parser/nssis_new.yy"
    {
  (yyval.ival) = 0;
  driver.syntax_error = true;
 }
    break;

  case 173:

/* Line 690 of lalr1.cc  */
#line 1204 "parser/nssis_new.yy"
    {
  (yyval.ival) = 1;
 }
    break;

  case 174:

/* Line 690 of lalr1.cc  */
#line 1207 "parser/nssis_new.yy"
    {
  (yyval.ival) = 0;
  driver.syntax_error = true;
 }
    break;

  case 175:

/* Line 690 of lalr1.cc  */
#line 1211 "parser/nssis_new.yy"
    {
  (yyval.ival) = 0;
  driver.syntax_error = true;
 }
    break;

  case 176:

/* Line 690 of lalr1.cc  */
#line 1215 "parser/nssis_new.yy"
    {
  (yyval.ival) = 0;
  driver.syntax_error = true;
 }
    break;

  case 177:

/* Line 690 of lalr1.cc  */
#line 1219 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(3) - (1)].ival)==1 && (yysemantic_stack_[(3) - (3)].ival)==1)
    (yyval.map_string_variable) = (yysemantic_stack_[(3) - (2)].map_string_variable);
  else
    (yyval.map_string_variable) = NULL;
 }
    break;

  case 178:

/* Line 690 of lalr1.cc  */
#line 1225 "parser/nssis_new.yy"
    {
  (yyval.map_string_variable) = NULL;
 }
    break;

  case 179:

/* Line 690 of lalr1.cc  */
#line 1228 "parser/nssis_new.yy"
    {
  (yyval.map_string_variable) = NULL;
  driver.syntax_error = true;
  }
    break;

  case 180:

/* Line 690 of lalr1.cc  */
#line 1232 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(1) - (1)].sval)!=NULL) {
    (yyval.map_string_variable) = new map<string, variable *>;
    if((yyval.map_string_variable)->find(*(yysemantic_stack_[(1) - (1)].sval)) != (yyval.map_string_variable)->end() && options["quiet"] == 0)
      cout << "warning: local observable variable " << *(yysemantic_stack_[(1) - (1)].sval) << " has already been defined." << endl;
    int i = search_string_table((yysemantic_stack_[(1) - (1)].sval));
    if(i>=0) {
      (*(yyval.map_string_variable))[*(yysemantic_stack_[(1) - (1)].sval)] = new variable((*string_table)[0], (*string_table)[i]);
      free((yysemantic_stack_[(1) - (1)].sval));
    } else {
      (*(yyval.map_string_variable))[*(yysemantic_stack_[(1) - (1)].sval)] = new variable((*string_table)[0], (yysemantic_stack_[(1) - (1)].sval));
      string_table->push_back((yysemantic_stack_[(1) - (1)].sval));
    }
  } else
    (yyval.map_string_variable) = NULL;
 }
    break;

  case 181:

/* Line 690 of lalr1.cc  */
#line 1248 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(3) - (1)].map_string_variable)!=NULL && (yysemantic_stack_[(3) - (3)].sval)!=NULL) {
    if((yysemantic_stack_[(3) - (1)].map_string_variable)->find(*(yysemantic_stack_[(3) - (3)].sval)) != (yyval.map_string_variable)->end() && options["quiet"] == 0)
      cout << "warning: local observable variable " << *(yysemantic_stack_[(3) - (3)].sval) << " has already been defined." << endl;
    int i = search_string_table((yysemantic_stack_[(3) - (3)].sval));
    if(i>=0) {
      (*(yysemantic_stack_[(3) - (1)].map_string_variable))[*(yysemantic_stack_[(3) - (3)].sval)] = new variable((*string_table)[0], (*string_table)[i]);
      free((yysemantic_stack_[(3) - (3)].sval));
    } else {
      (*(yysemantic_stack_[(3) - (1)].map_string_variable))[*(yysemantic_stack_[(3) - (3)].sval)] = new variable((*string_table)[0], (yysemantic_stack_[(3) - (3)].sval));
      string_table->push_back((yysemantic_stack_[(3) - (3)].sval));
    }
    (yyval.map_string_variable) = (yysemantic_stack_[(3) - (1)].map_string_variable);
  } else
    (yyval.map_string_variable) = NULL;
 }
    break;

  case 182:

/* Line 690 of lalr1.cc  */
#line 1264 "parser/nssis_new.yy"
    {
  (yyval.map_string_variable) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(3) - (1)].map_string_variable));
  USE((yysemantic_stack_[(3) - (3)].sval));
 }
    break;

  case 183:

/* Line 690 of lalr1.cc  */
#line 1270 "parser/nssis_new.yy"
    {
  (yyval.map_string_variable) = NULL;
  driver.syntax_error = true;
  }
    break;

  case 184:

/* Line 690 of lalr1.cc  */
#line 1277 "parser/nssis_new.yy"
    {
  (yyval.ival) = 1;
 }
    break;

  case 185:

/* Line 690 of lalr1.cc  */
#line 1280 "parser/nssis_new.yy"
    {
  (yyval.ival) = 0;
  driver.syntax_error = true;
 }
    break;

  case 186:

/* Line 690 of lalr1.cc  */
#line 1284 "parser/nssis_new.yy"
    {
  (yyval.ival) = 0;
  driver.syntax_error = true;
 }
    break;

  case 187:

/* Line 690 of lalr1.cc  */
#line 1288 "parser/nssis_new.yy"
    {
  (yyval.ival) = 0;
  driver.syntax_error = true;
 }
    break;

  case 188:

/* Line 690 of lalr1.cc  */
#line 1292 "parser/nssis_new.yy"
    {
  (yyval.ival) = 0;
  driver.syntax_error = true;
 }
    break;

  case 189:

/* Line 690 of lalr1.cc  */
#line 1296 "parser/nssis_new.yy"
    {
  (yyval.ival) = 0;
  driver.syntax_error = true;
 }
    break;

  case 190:

/* Line 690 of lalr1.cc  */
#line 1300 "parser/nssis_new.yy"
    {
  (yyval.ival) = 0;
  driver.syntax_error = true;
 }
    break;

  case 191:

/* Line 690 of lalr1.cc  */
#line 1304 "parser/nssis_new.yy"
    {
  (yyval.ival) = 0;
  driver.syntax_error = true;
 }
    break;

  case 192:

/* Line 690 of lalr1.cc  */
#line 1308 "parser/nssis_new.yy"
    {
  (yyval.ival) = 1;
 }
    break;

  case 193:

/* Line 690 of lalr1.cc  */
#line 1311 "parser/nssis_new.yy"
    {
  (yyval.ival) = 0;
  driver.syntax_error = true;
 }
    break;

  case 194:

/* Line 690 of lalr1.cc  */
#line 1315 "parser/nssis_new.yy"
    {
  (yyval.ival) = 0;
  driver.syntax_error = true;
 }
    break;

  case 195:

/* Line 690 of lalr1.cc  */
#line 1319 "parser/nssis_new.yy"
    {
  (yyval.ival) = 0;
  driver.syntax_error = true;
 }
    break;

  case 196:

/* Line 690 of lalr1.cc  */
#line 1323 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(3) - (1)].ival)==1 && (yysemantic_stack_[(3) - (3)].ival)==1)
    (yyval.set_string) = (yysemantic_stack_[(3) - (2)].set_string);
  else
    (yyval.set_string) = NULL;
 }
    break;

  case 197:

/* Line 690 of lalr1.cc  */
#line 1329 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(2) - (1)].ival)==1 && (yysemantic_stack_[(2) - (2)].ival)==1)
    (yyval.set_string) = new set<string>;
  else
    (yyval.set_string) = NULL;
 }
    break;

  case 198:

/* Line 690 of lalr1.cc  */
#line 1335 "parser/nssis_new.yy"
    {
  (yyval.set_string) = NULL;
  driver.syntax_error = true;
  }
    break;

  case 199:

/* Line 690 of lalr1.cc  */
#line 1341 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(3) - (1)].ival)==1 && (yysemantic_stack_[(3) - (3)].ival)==1) 
    (yyval.set_string) = (yysemantic_stack_[(3) - (2)].set_string);
  else
    (yyval.set_string) = NULL;
 }
    break;

  case 200:

/* Line 690 of lalr1.cc  */
#line 1347 "parser/nssis_new.yy"
    {
  (yyval.set_string) = NULL;
  driver.syntax_error = true;
  }
    break;

  case 201:

/* Line 690 of lalr1.cc  */
#line 1351 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(1) - (1)].sval)!=NULL) {
    (yyval.set_string) = new set<string>;
    (yyval.set_string)->insert(*(yysemantic_stack_[(1) - (1)].sval));
    free ((yysemantic_stack_[(1) - (1)].sval));
  } else
    (yyval.set_string) = NULL;
 }
    break;

  case 202:

/* Line 690 of lalr1.cc  */
#line 1359 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(3) - (1)].set_string)!=NULL && (yysemantic_stack_[(3) - (3)].sval)!=NULL) {
    pair<set<string>::iterator, bool> ret = (yysemantic_stack_[(3) - (1)].set_string)->insert(*(yysemantic_stack_[(3) - (3)].sval));
    if(!ret.second && options["quiet"] == 0)
      cout << "warning: action " << *(yysemantic_stack_[(3) - (3)].sval) << " has been defined." << endl;
    (yyval.set_string) = (yysemantic_stack_[(3) - (1)].set_string);
    free ((yysemantic_stack_[(3) - (3)].sval));
  } else
    (yyval.set_string) = NULL;
 }
    break;

  case 203:

/* Line 690 of lalr1.cc  */
#line 1369 "parser/nssis_new.yy"
    {
  (yyval.set_string) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(3) - (1)].set_string));
  USE((yysemantic_stack_[(3) - (3)].sval));
 }
    break;

  case 204:

/* Line 690 of lalr1.cc  */
#line 1375 "parser/nssis_new.yy"
    {
  (yyval.set_string) = NULL;
  driver.syntax_error = true;
  }
    break;

  case 205:

/* Line 690 of lalr1.cc  */
#line 1382 "parser/nssis_new.yy"
    {
  (yyval.ival) = 1;
 }
    break;

  case 206:

/* Line 690 of lalr1.cc  */
#line 1385 "parser/nssis_new.yy"
    {
  (yyval.ival) = 0;
  driver.syntax_error = true;
 }
    break;

  case 207:

/* Line 690 of lalr1.cc  */
#line 1389 "parser/nssis_new.yy"
    {
  (yyval.ival) = 0;
  driver.syntax_error = true;
 }
    break;

  case 208:

/* Line 690 of lalr1.cc  */
#line 1393 "parser/nssis_new.yy"
    {
  (yyval.ival) = 0;
  driver.syntax_error = true;
 }
    break;

  case 209:

/* Line 690 of lalr1.cc  */
#line 1397 "parser/nssis_new.yy"
    {
  (yyval.ival) = 1;
 }
    break;

  case 210:

/* Line 690 of lalr1.cc  */
#line 1400 "parser/nssis_new.yy"
    {
  (yyval.ival) = 0;
  driver.syntax_error = true;
 }
    break;

  case 211:

/* Line 690 of lalr1.cc  */
#line 1404 "parser/nssis_new.yy"
    {
  (yyval.ival) = 0;
  driver.syntax_error = true;
 }
    break;

  case 212:

/* Line 690 of lalr1.cc  */
#line 1408 "parser/nssis_new.yy"
    {
  (yyval.ival) = 0;
  driver.syntax_error = true;
 }
    break;

  case 213:

/* Line 690 of lalr1.cc  */
#line 1413 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(3) - (1)].ival)==1 && (yysemantic_stack_[(3) - (3)].ival)==1) 
    (yyval.vector_protocol_line) = (yysemantic_stack_[(3) - (2)].vector_protocol_line);
  else
    (yyval.vector_protocol_line) = NULL;
 }
    break;

  case 214:

/* Line 690 of lalr1.cc  */
#line 1419 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(4) - (1)].ival)==1 && (yysemantic_stack_[(4) - (4)].ival)==1) {
    (yyval.vector_protocol_line) = (yysemantic_stack_[(4) - (2)].vector_protocol_line);
    (yyval.vector_protocol_line)->push_back((yysemantic_stack_[(4) - (3)]._protocol_line));
  }
  else
    (yyval.vector_protocol_line) = NULL;
 }
    break;

  case 215:

/* Line 690 of lalr1.cc  */
#line 1427 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(3) - (1)].ival)==1 && (yysemantic_stack_[(3) - (3)].ival)==1) {
    (yyval.vector_protocol_line) = new vector<protocol_line*>;
    (yyval.vector_protocol_line)->push_back((yysemantic_stack_[(3) - (2)]._protocol_line));;
  }
  else
    (yyval.vector_protocol_line) = NULL;
 }
    break;

  case 216:

/* Line 690 of lalr1.cc  */
#line 1435 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(2) - (1)].ival)==1 && (yysemantic_stack_[(2) - (2)].ival)==1) 
    (yyval.vector_protocol_line) = new vector<protocol_line*>;
  else
    (yyval.vector_protocol_line) = NULL;
 }
    break;

  case 217:

/* Line 690 of lalr1.cc  */
#line 1441 "parser/nssis_new.yy"
    {
  (yyval.vector_protocol_line) = NULL;
  driver.syntax_error = true;
  }
    break;

  case 218:

/* Line 690 of lalr1.cc  */
#line 1447 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(3) - (1)].ival)==1 && (yysemantic_stack_[(3) - (3)].ival)==1) 
    (yyval.vector_protocol_line) = (yysemantic_stack_[(3) - (2)].vector_protocol_line);
  else
    (yyval.vector_protocol_line) = NULL;
 }
    break;

  case 219:

/* Line 690 of lalr1.cc  */
#line 1453 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(4) - (1)].ival)==1 && (yysemantic_stack_[(4) - (4)].ival)==1) {
    (yyval.vector_protocol_line) = (yysemantic_stack_[(4) - (2)].vector_protocol_line);
    (yyval.vector_protocol_line)->push_back((yysemantic_stack_[(4) - (3)]._protocol_line));
  }
  else
    (yyval.vector_protocol_line) = NULL;
 }
    break;

  case 220:

/* Line 690 of lalr1.cc  */
#line 1461 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(3) - (1)].ival)==1 && (yysemantic_stack_[(3) - (3)].ival)==1) {
    (yyval.vector_protocol_line) = new vector<protocol_line*>;
    (yyval.vector_protocol_line)->push_back((yysemantic_stack_[(3) - (2)]._protocol_line));;
  }
  else
    (yyval.vector_protocol_line) = NULL;
 }
    break;

  case 221:

/* Line 690 of lalr1.cc  */
#line 1469 "parser/nssis_new.yy"
    {
  (yyval.vector_protocol_line) = NULL;
  driver.syntax_error = true;
  }
    break;

  case 222:

/* Line 690 of lalr1.cc  */
#line 1474 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(1) - (1)]._protocol_line)!=NULL) {
    (yyval.vector_protocol_line) = new vector<protocol_line*>;
    (yyval.vector_protocol_line)->push_back((yysemantic_stack_[(1) - (1)]._protocol_line));
  } else
    (yyval.vector_protocol_line) = NULL;
 }
    break;

  case 223:

/* Line 690 of lalr1.cc  */
#line 1481 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(2) - (1)].vector_protocol_line)!=NULL && (yysemantic_stack_[(2) - (2)]._protocol_line)!=NULL) {
    (yysemantic_stack_[(2) - (1)].vector_protocol_line)->push_back((yysemantic_stack_[(2) - (2)]._protocol_line));
    (yyval.vector_protocol_line) = (yysemantic_stack_[(2) - (1)].vector_protocol_line);
  } else
    (yyval.vector_protocol_line) = NULL;
 }
    break;

  case 224:

/* Line 690 of lalr1.cc  */
#line 1488 "parser/nssis_new.yy"
    {
  (yyval.vector_protocol_line) = NULL;
  driver.syntax_error = true;
  }
    break;

  case 225:

/* Line 690 of lalr1.cc  */
#line 1493 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(1) - (1)]._protocol_line)!=NULL) {
    (yyval.vector_protocol_line) = new vector<protocol_line*>;
    (yyval.vector_protocol_line)->push_back((yysemantic_stack_[(1) - (1)]._protocol_line));
  } else
    (yyval.vector_protocol_line) = NULL;
 }
    break;

  case 226:

/* Line 690 of lalr1.cc  */
#line 1500 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(2) - (1)].vector_protocol_line)!=NULL && (yysemantic_stack_[(2) - (2)]._protocol_line)!=NULL) {
    (yysemantic_stack_[(2) - (1)].vector_protocol_line)->push_back((yysemantic_stack_[(2) - (2)]._protocol_line));
    (yyval.vector_protocol_line) = (yysemantic_stack_[(2) - (1)].vector_protocol_line);
  } else
    (yyval.vector_protocol_line) = NULL;
 }
    break;

  case 227:

/* Line 690 of lalr1.cc  */
#line 1507 "parser/nssis_new.yy"
    {
  (yyval.vector_protocol_line) = NULL;
  driver.syntax_error = true;
  }
    break;

  case 228:

/* Line 690 of lalr1.cc  */
#line 1512 "parser/nssis_new.yy"
    {
  (yyval.ival) = 1;
 }
    break;

  case 229:

/* Line 690 of lalr1.cc  */
#line 1515 "parser/nssis_new.yy"
    {
  (yyval.ival) = 0;
  driver.syntax_error = true;
 }
    break;

  case 230:

/* Line 690 of lalr1.cc  */
#line 1519 "parser/nssis_new.yy"
    {
  (yyval.ival) = 0;
  driver.syntax_error = true;
 }
    break;

  case 231:

/* Line 690 of lalr1.cc  */
#line 1523 "parser/nssis_new.yy"
    {
  (yyval.ival) = 0;
  driver.syntax_error = true;
 }
    break;

  case 232:

/* Line 690 of lalr1.cc  */
#line 1527 "parser/nssis_new.yy"
    {
  (yyval.ival) = 1;
 }
    break;

  case 233:

/* Line 690 of lalr1.cc  */
#line 1530 "parser/nssis_new.yy"
    {
  (yyval.ival) = 0;
  driver.syntax_error = true;
 }
    break;

  case 234:

/* Line 690 of lalr1.cc  */
#line 1534 "parser/nssis_new.yy"
    {
  (yyval.ival) = 0;
  driver.syntax_error = true;
 }
    break;

  case 235:

/* Line 690 of lalr1.cc  */
#line 1538 "parser/nssis_new.yy"
    {
  (yyval.ival) = 0;
  driver.syntax_error = true;
 }
    break;

  case 236:

/* Line 690 of lalr1.cc  */
#line 1542 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(4) - (1)]._bool_expression)!=NULL && (yysemantic_stack_[(4) - (2)].ival)==1 && (yysemantic_stack_[(4) - (3)].set_string)!=NULL && (yysemantic_stack_[(4) - (4)].ival)==1) 
    (yyval._protocol_line) = new protocol_line((yysemantic_stack_[(4) - (1)]._bool_expression), (yysemantic_stack_[(4) - (3)].set_string));
  else
    (yyval._protocol_line) = NULL;
 }
    break;

  case 237:

/* Line 690 of lalr1.cc  */
#line 1548 "parser/nssis_new.yy"
    {
  (yyval._protocol_line) = NULL;
  driver.syntax_error = true;
  }
    break;

  case 238:

/* Line 690 of lalr1.cc  */
#line 1553 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(4) - (1)]._bool_expression)!=NULL && (yysemantic_stack_[(4) - (2)].ival)==1 && (yysemantic_stack_[(4) - (3)].set_string)!=NULL && (yysemantic_stack_[(4) - (4)].ival)==1) 
    (yyval._protocol_line) = new protocol_line((yysemantic_stack_[(4) - (1)]._bool_expression), (yysemantic_stack_[(4) - (3)].set_string));
  else
    (yyval._protocol_line) = NULL;
 }
    break;

  case 239:

/* Line 690 of lalr1.cc  */
#line 1559 "parser/nssis_new.yy"
    {
  (yyval._protocol_line) = NULL;
  driver.syntax_error = true;
  }
    break;

  case 240:

/* Line 690 of lalr1.cc  */
#line 1564 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(4) - (2)].ival)==1 && (yysemantic_stack_[(4) - (3)].set_string)!=NULL && (yysemantic_stack_[(4) - (4)].ival)==1) 
    (yyval._protocol_line) = new protocol_line(new bool_expression(), (yysemantic_stack_[(4) - (3)].set_string));
  else
    (yyval._protocol_line) = NULL;
 }
    break;

  case 241:

/* Line 690 of lalr1.cc  */
#line 1570 "parser/nssis_new.yy"
    {
  (yyval._protocol_line) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(4) - (3)].set_string));
 }
    break;

  case 242:

/* Line 690 of lalr1.cc  */
#line 1576 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(1) - (1)].sval)!=NULL) {
    (yyval.set_string) = new set<string>;
    (yyval.set_string)->insert(*(yysemantic_stack_[(1) - (1)].sval));
    free ((yysemantic_stack_[(1) - (1)].sval));
  } else
    (yyval.set_string) = NULL;
 }
    break;

  case 243:

/* Line 690 of lalr1.cc  */
#line 1584 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(3) - (1)].set_string)!=NULL && (yysemantic_stack_[(3) - (3)].sval)!=NULL) {
    pair<set<string>::iterator, bool> ret = (yysemantic_stack_[(3) - (1)].set_string)->insert(*(yysemantic_stack_[(3) - (3)].sval));
    if(!ret.second && options["quiet"] == 0)
      cout << "warning: action " << *(yysemantic_stack_[(3) - (3)].sval) << " is repeated." << endl;
    (yyval.set_string) = (yysemantic_stack_[(3) - (1)].set_string);
    free ((yysemantic_stack_[(3) - (3)].sval));
  } else
    (yyval.set_string) = NULL;
 }
    break;

  case 244:

/* Line 690 of lalr1.cc  */
#line 1594 "parser/nssis_new.yy"
    {
  (yyval.set_string) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(3) - (1)].set_string));
  USE((yysemantic_stack_[(3) - (3)].sval));
 }
    break;

  case 245:

/* Line 690 of lalr1.cc  */
#line 1600 "parser/nssis_new.yy"
    {
  (yyval.set_string) = NULL;
  driver.syntax_error = true;
  }
    break;

  case 246:

/* Line 690 of lalr1.cc  */
#line 1607 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(3) - (1)].ival)==1 && (yysemantic_stack_[(3) - (3)].ival)==1)
    (yyval.vector_evolution_line) = (yysemantic_stack_[(3) - (2)].vector_evolution_line);
  else
    (yyval.vector_evolution_line) = NULL;
}
    break;

  case 247:

/* Line 690 of lalr1.cc  */
#line 1613 "parser/nssis_new.yy"
    {
  (yyval.vector_evolution_line) = NULL;
  driver.syntax_error = true;
  }
    break;

  case 248:

/* Line 690 of lalr1.cc  */
#line 1617 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(1) - (1)]._evolution_line)!=NULL) {
    (yyval.vector_evolution_line) = new vector<evolution_line*>;
    (yyval.vector_evolution_line)->push_back((yysemantic_stack_[(1) - (1)]._evolution_line));
  } else
    (yyval.vector_evolution_line) = NULL;
 }
    break;

  case 249:

/* Line 690 of lalr1.cc  */
#line 1624 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(2) - (1)].vector_evolution_line)!=NULL && (yysemantic_stack_[(2) - (2)]._evolution_line)!=NULL) {
    (yysemantic_stack_[(2) - (1)].vector_evolution_line)->push_back((yysemantic_stack_[(2) - (2)]._evolution_line));
    (yyval.vector_evolution_line) = (yysemantic_stack_[(2) - (1)].vector_evolution_line);
  } else
    (yyval.vector_evolution_line) = NULL;
 }
    break;

  case 250:

/* Line 690 of lalr1.cc  */
#line 1631 "parser/nssis_new.yy"
    {
  (yyval.vector_evolution_line) = NULL;
  driver.syntax_error = true;
  }
    break;

  case 251:

/* Line 690 of lalr1.cc  */
#line 1636 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(4) - (1)].vector_assignment)!=NULL)
    (yyval._evolution_line) = new evolution_line((yysemantic_stack_[(4) - (1)].vector_assignment), (yysemantic_stack_[(4) - (3)]._bool_expression));
  else
    (yyval._evolution_line) = NULL;
 }
    break;

  case 252:

/* Line 690 of lalr1.cc  */
#line 1642 "parser/nssis_new.yy"
    {
  (yyval._evolution_line) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(4) - (1)].vector_assignment));
  USE((yysemantic_stack_[(4) - (3)]._bool_expression));
 }
    break;

  case 253:

/* Line 690 of lalr1.cc  */
#line 1648 "parser/nssis_new.yy"
    {
  (yyval._evolution_line) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(4) - (1)].vector_assignment));
  USE((yysemantic_stack_[(4) - (3)]._bool_expression));
 }
    break;

  case 254:

/* Line 690 of lalr1.cc  */
#line 1654 "parser/nssis_new.yy"
    {
  (yyval._evolution_line) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(4) - (1)].vector_assignment));
  USE((yysemantic_stack_[(4) - (3)]._bool_expression));
 }
    break;

  case 255:

/* Line 690 of lalr1.cc  */
#line 1660 "parser/nssis_new.yy"
    {
  (yyval._evolution_line) = NULL;
  driver.syntax_error = true;
  }
    break;

  case 256:

/* Line 690 of lalr1.cc  */
#line 1665 "parser/nssis_new.yy"
    { 
  (yyval._bool_expression) = (yysemantic_stack_[(3) - (2)]._bool_expression); 
 }
    break;

  case 257:

/* Line 690 of lalr1.cc  */
#line 1668 "parser/nssis_new.yy"
    { 
  (yyval._bool_expression) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(3) - (2)]._bool_expression));
 }
    break;

  case 258:

/* Line 690 of lalr1.cc  */
#line 1673 "parser/nssis_new.yy"
    { 
  (yyval._bool_expression) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(3) - (2)]._bool_expression));
 }
    break;

  case 259:

/* Line 690 of lalr1.cc  */
#line 1678 "parser/nssis_new.yy"
    { 
  (yyval._bool_expression) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(3) - (2)]._bool_expression));
 }
    break;

  case 260:

/* Line 690 of lalr1.cc  */
#line 1683 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(3) - (1)]._bool_expression)!=NULL && (yysemantic_stack_[(3) - (3)]._bool_expression)!=NULL)
    (yyval._bool_expression) = new bool_expression(1, (yysemantic_stack_[(3) - (1)]._bool_expression), (yysemantic_stack_[(3) - (3)]._bool_expression));
  else
    (yyval._bool_expression) = NULL;
 }
    break;

  case 261:

/* Line 690 of lalr1.cc  */
#line 1689 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(3) - (1)]._bool_expression)!=NULL && (yysemantic_stack_[(3) - (3)]._bool_expression)!=NULL)
    (yyval._bool_expression) = new bool_expression(2, (yysemantic_stack_[(3) - (1)]._bool_expression), (yysemantic_stack_[(3) - (3)]._bool_expression));
  else
    (yyval._bool_expression) = NULL;
 }
    break;

  case 262:

/* Line 690 of lalr1.cc  */
#line 1695 "parser/nssis_new.yy"
    {
  (yyval._bool_expression) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(3) - (1)]._bool_expression));
  USE((yysemantic_stack_[(3) - (3)]._bool_expression));
 }
    break;

  case 263:

/* Line 690 of lalr1.cc  */
#line 1701 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(2) - (2)]._bool_expression)!=NULL)
    (yyval._bool_expression) = new bool_expression(3, (yysemantic_stack_[(2) - (2)]._bool_expression));
  else
    (yyval._bool_expression) = NULL;
 }
    break;

  case 264:

/* Line 690 of lalr1.cc  */
#line 1707 "parser/nssis_new.yy"
    {
  (yyval._bool_expression) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(2) - (2)]._bool_expression));
 }
    break;

  case 265:

/* Line 690 of lalr1.cc  */
#line 1712 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(3) - (1)]._expression)!=NULL && (yysemantic_stack_[(3) - (3)]._expression)!=NULL) {
    logic_expression *expr = new logic_expression((yysemantic_stack_[(3) - (2)]._unsigned_char), (yysemantic_stack_[(3) - (1)]._expression), (yysemantic_stack_[(3) - (3)]._expression));
    (yyval._bool_expression) = new bool_expression(0,  expr);
  } else
    (yyval._bool_expression) = NULL;
 }
    break;

  case 266:

/* Line 690 of lalr1.cc  */
#line 1719 "parser/nssis_new.yy"
    {
  (yyval._bool_expression) = NULL;
  driver.syntax_error = true;
  }
    break;

  case 267:

/* Line 690 of lalr1.cc  */
#line 1724 "parser/nssis_new.yy"
    { 
  (yyval._bool_expression) = (yysemantic_stack_[(3) - (2)]._bool_expression); 
 }
    break;

  case 268:

/* Line 690 of lalr1.cc  */
#line 1727 "parser/nssis_new.yy"
    { 
  (yyval._bool_expression) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(3) - (2)]._bool_expression));
 }
    break;

  case 269:

/* Line 690 of lalr1.cc  */
#line 1732 "parser/nssis_new.yy"
    { 
  (yyval._bool_expression) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(3) - (2)]._bool_expression));
 }
    break;

  case 270:

/* Line 690 of lalr1.cc  */
#line 1737 "parser/nssis_new.yy"
    { 
  (yyval._bool_expression) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(3) - (2)]._bool_expression));
 }
    break;

  case 271:

/* Line 690 of lalr1.cc  */
#line 1742 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(3) - (1)]._bool_expression)!=NULL && (yysemantic_stack_[(3) - (3)]._bool_expression)!=NULL)
    (yyval._bool_expression) = new bool_expression(1, (yysemantic_stack_[(3) - (1)]._bool_expression), (yysemantic_stack_[(3) - (3)]._bool_expression));
  else
    (yyval._bool_expression) = NULL;
 }
    break;

  case 272:

/* Line 690 of lalr1.cc  */
#line 1748 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(3) - (1)]._bool_expression)!=NULL && (yysemantic_stack_[(3) - (3)]._bool_expression)!=NULL)
    (yyval._bool_expression) = new bool_expression(2, (yysemantic_stack_[(3) - (1)]._bool_expression), (yysemantic_stack_[(3) - (3)]._bool_expression));
  else
    (yyval._bool_expression) = NULL;
 }
    break;

  case 273:

/* Line 690 of lalr1.cc  */
#line 1754 "parser/nssis_new.yy"
    {
  (yyval._bool_expression) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(3) - (1)]._bool_expression));
  USE((yysemantic_stack_[(3) - (3)]._bool_expression));
 }
    break;

  case 274:

/* Line 690 of lalr1.cc  */
#line 1760 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(2) - (2)]._bool_expression)!=NULL)
    (yyval._bool_expression) = new bool_expression(3, (yysemantic_stack_[(2) - (2)]._bool_expression));
  else
    (yyval._bool_expression) = NULL;
 }
    break;

  case 275:

/* Line 690 of lalr1.cc  */
#line 1766 "parser/nssis_new.yy"
    {
  (yyval._bool_expression) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(2) - (2)]._bool_expression));
 }
    break;

  case 276:

/* Line 690 of lalr1.cc  */
#line 1771 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(3) - (1)]._expression)!=NULL && (yysemantic_stack_[(3) - (3)]._expression)!=NULL) {
    logic_expression *expr = new logic_expression((yysemantic_stack_[(3) - (2)]._unsigned_char), (yysemantic_stack_[(3) - (1)]._expression), (yysemantic_stack_[(3) - (3)]._expression));
    (yyval._bool_expression) = new bool_expression(0,  expr);
  } else
    (yyval._bool_expression) = NULL;
 }
    break;

  case 277:

/* Line 690 of lalr1.cc  */
#line 1778 "parser/nssis_new.yy"
    {
  (yyval._bool_expression) = NULL;
  driver.syntax_error = true;
 }
    break;

  case 278:

/* Line 690 of lalr1.cc  */
#line 1783 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(3) - (1)]._expression)!=NULL && (yysemantic_stack_[(3) - (3)]._expression)!=NULL) {
    (yyval._expression) = new arithmetic_expression(5, (yysemantic_stack_[(3) - (1)]._expression), (yysemantic_stack_[(3) - (3)]._expression));
  } else
    (yyval._expression) = NULL;
 }
    break;

  case 279:

/* Line 690 of lalr1.cc  */
#line 1789 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(3) - (1)]._expression)!=NULL && (yysemantic_stack_[(3) - (3)]._expression)!=NULL) {
    (yyval._expression) = new arithmetic_expression(6, (yysemantic_stack_[(3) - (1)]._expression), (yysemantic_stack_[(3) - (3)]._expression));
  } else
    (yyval._expression) = NULL;
 }
    break;

  case 280:

/* Line 690 of lalr1.cc  */
#line 1795 "parser/nssis_new.yy"
    {
  (yyval._expression) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(3) - (1)]._expression));
 }
    break;

  case 281:

/* Line 690 of lalr1.cc  */
#line 1800 "parser/nssis_new.yy"
    {
  (yyval._expression) = (yysemantic_stack_[(1) - (1)]._expression);
  }
    break;

  case 282:

/* Line 690 of lalr1.cc  */
#line 1803 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(3) - (1)]._expression)!=NULL && (yysemantic_stack_[(3) - (3)]._expression)!=NULL) {
    (yyval._expression) = new arithmetic_expression(7, (yysemantic_stack_[(3) - (1)]._expression), (yysemantic_stack_[(3) - (3)]._expression));
  } else
    (yyval._expression) = NULL;
 }
    break;

  case 283:

/* Line 690 of lalr1.cc  */
#line 1809 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(3) - (1)]._expression)!=NULL && (yysemantic_stack_[(3) - (3)]._expression)!=NULL) {
    (yyval._expression) = new arithmetic_expression(8, (yysemantic_stack_[(3) - (1)]._expression), (yysemantic_stack_[(3) - (3)]._expression));
  } else
    (yyval._expression) = NULL;
 }
    break;

  case 284:

/* Line 690 of lalr1.cc  */
#line 1815 "parser/nssis_new.yy"
    {
  (yyval._expression) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(3) - (1)]._expression));
 }
    break;

  case 285:

/* Line 690 of lalr1.cc  */
#line 1820 "parser/nssis_new.yy"
    {
  (yyval._expression) = (yysemantic_stack_[(1) - (1)]._expression);
  }
    break;

  case 286:

/* Line 690 of lalr1.cc  */
#line 1823 "parser/nssis_new.yy"
    {
  (yyval._expression) = (yysemantic_stack_[(3) - (2)]._expression);
  }
    break;

  case 287:

/* Line 690 of lalr1.cc  */
#line 1826 "parser/nssis_new.yy"
    {
  (yyval._expression) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(3) - (2)]._expression));
 }
    break;

  case 288:

/* Line 690 of lalr1.cc  */
#line 1831 "parser/nssis_new.yy"
    {
  (yyval._expression) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(3) - (2)]._expression));
 }
    break;

  case 289:

/* Line 690 of lalr1.cc  */
#line 1836 "parser/nssis_new.yy"
    {
  (yyval._expression) = (yysemantic_stack_[(1) - (1)]._expression);
  }
    break;

  case 290:

/* Line 690 of lalr1.cc  */
#line 1840 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(3) - (1)]._expression)!=NULL && (yysemantic_stack_[(3) - (3)]._expression)!=NULL) {
    (yyval._expression) = new bit_expression(10, (yysemantic_stack_[(3) - (1)]._expression), (yysemantic_stack_[(3) - (3)]._expression));
  } else
    (yyval._expression) = NULL;
 }
    break;

  case 291:

/* Line 690 of lalr1.cc  */
#line 1846 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(3) - (1)]._expression)!=NULL && (yysemantic_stack_[(3) - (3)]._expression)!=NULL) {
    (yyval._expression) = new bit_expression(12, (yysemantic_stack_[(3) - (1)]._expression), (yysemantic_stack_[(3) - (3)]._expression));
  } else
    (yyval._expression) = NULL;
 }
    break;

  case 292:

/* Line 690 of lalr1.cc  */
#line 1852 "parser/nssis_new.yy"
    {
  (yyval._expression) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(3) - (1)]._expression));
 }
    break;

  case 293:

/* Line 690 of lalr1.cc  */
#line 1857 "parser/nssis_new.yy"
    {
  (yyval._expression) = (yysemantic_stack_[(1) - (1)]._expression);
  }
    break;

  case 294:

/* Line 690 of lalr1.cc  */
#line 1860 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(3) - (1)]._expression)!=NULL && (yysemantic_stack_[(3) - (3)]._expression)!=NULL) {
    (yyval._expression) = new bit_expression(9, (yysemantic_stack_[(3) - (1)]._expression), (yysemantic_stack_[(3) - (3)]._expression));
  } else
    (yyval._expression) = NULL;
 }
    break;

  case 295:

/* Line 690 of lalr1.cc  */
#line 1866 "parser/nssis_new.yy"
    {
  (yyval._expression) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(3) - (1)]._expression));
 }
    break;

  case 296:

/* Line 690 of lalr1.cc  */
#line 1871 "parser/nssis_new.yy"
    {
  (yyval._expression) = (yysemantic_stack_[(1) - (1)]._expression);
  }
    break;

  case 297:

/* Line 690 of lalr1.cc  */
#line 1874 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(2) - (2)]._expression)!=NULL) {
    (yyval._expression) = new bit_expression(11, (yysemantic_stack_[(2) - (2)]._expression), NULL);
  } else
    (yyval._expression) = NULL;
 }
    break;

  case 298:

/* Line 690 of lalr1.cc  */
#line 1880 "parser/nssis_new.yy"
    {
  (yyval._expression) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(2) - (2)]._expression));
 }
    break;

  case 299:

/* Line 690 of lalr1.cc  */
#line 1885 "parser/nssis_new.yy"
    {
  (yyval._expression) = (yysemantic_stack_[(1) - (1)]._expression);
  }
    break;

  case 300:

/* Line 690 of lalr1.cc  */
#line 1888 "parser/nssis_new.yy"
    {
  (yyval._expression) = (yysemantic_stack_[(3) - (2)]._expression);
  }
    break;

  case 301:

/* Line 690 of lalr1.cc  */
#line 1891 "parser/nssis_new.yy"
    {
  (yyval._expression) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(3) - (2)]._expression));
 }
    break;

  case 302:

/* Line 690 of lalr1.cc  */
#line 1896 "parser/nssis_new.yy"
    {
  (yyval._expression) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(3) - (2)]._expression));
 }
    break;

  case 303:

/* Line 690 of lalr1.cc  */
#line 1901 "parser/nssis_new.yy"
    {
  (yyval._expression) = (yysemantic_stack_[(1) - (1)]._expression);
  }
    break;

  case 304:

/* Line 690 of lalr1.cc  */
#line 1905 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(3) - (1)]._expression)!=NULL && (yysemantic_stack_[(3) - (3)]._expression)!=NULL) {
    (yyval._expression) = new bit_expression(10, (yysemantic_stack_[(3) - (1)]._expression), (yysemantic_stack_[(3) - (3)]._expression));
  } else
    (yyval._expression) = NULL;
 }
    break;

  case 305:

/* Line 690 of lalr1.cc  */
#line 1911 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(3) - (1)]._expression)!=NULL && (yysemantic_stack_[(3) - (3)]._expression)!=NULL) {
    (yyval._expression) = new bit_expression(12, (yysemantic_stack_[(3) - (1)]._expression), (yysemantic_stack_[(3) - (3)]._expression));
  } else
    (yyval._expression) = NULL;
 }
    break;

  case 306:

/* Line 690 of lalr1.cc  */
#line 1917 "parser/nssis_new.yy"
    {
  (yyval._expression) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(3) - (1)]._expression));
 }
    break;

  case 307:

/* Line 690 of lalr1.cc  */
#line 1922 "parser/nssis_new.yy"
    {
  (yyval._expression) = (yysemantic_stack_[(1) - (1)]._expression);
  }
    break;

  case 308:

/* Line 690 of lalr1.cc  */
#line 1925 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(3) - (1)]._expression)!=NULL && (yysemantic_stack_[(3) - (3)]._expression)!=NULL) {
    (yyval._expression) = new bit_expression(9, (yysemantic_stack_[(3) - (1)]._expression), (yysemantic_stack_[(3) - (3)]._expression));
  } else
    (yyval._expression) = NULL;
 }
    break;

  case 309:

/* Line 690 of lalr1.cc  */
#line 1931 "parser/nssis_new.yy"
    {
  (yyval._expression) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(3) - (1)]._expression));
 }
    break;

  case 310:

/* Line 690 of lalr1.cc  */
#line 1936 "parser/nssis_new.yy"
    {
  (yyval._expression) = (yysemantic_stack_[(1) - (1)]._expression);
  }
    break;

  case 311:

/* Line 690 of lalr1.cc  */
#line 1939 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(2) - (2)]._expression)!=NULL) {
    (yyval._expression) = new bit_expression(11, (yysemantic_stack_[(2) - (2)]._expression), NULL);
  } else
    (yyval._expression) = NULL;
 }
    break;

  case 312:

/* Line 690 of lalr1.cc  */
#line 1945 "parser/nssis_new.yy"
    {
  (yyval._expression) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(2) - (2)]._expression));
 }
    break;

  case 313:

/* Line 690 of lalr1.cc  */
#line 1950 "parser/nssis_new.yy"
    {
  (yyval._expression) = (yysemantic_stack_[(1) - (1)]._expression);
  }
    break;

  case 314:

/* Line 690 of lalr1.cc  */
#line 1953 "parser/nssis_new.yy"
    {
  (yyval._expression) = (yysemantic_stack_[(3) - (2)]._expression);
  }
    break;

  case 315:

/* Line 690 of lalr1.cc  */
#line 1956 "parser/nssis_new.yy"
    {
  (yyval._expression) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(3) - (2)]._expression));
 }
    break;

  case 316:

/* Line 690 of lalr1.cc  */
#line 1961 "parser/nssis_new.yy"
    {
  (yyval._expression) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(3) - (2)]._expression));
 }
    break;

  case 317:

/* Line 690 of lalr1.cc  */
#line 1966 "parser/nssis_new.yy"
    {
  (yyval._expression) = (yysemantic_stack_[(1) - (1)]._expression);
  }
    break;

  case 318:

/* Line 690 of lalr1.cc  */
#line 1970 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(3) - (1)]._expression)!=NULL && (yysemantic_stack_[(3) - (3)]._expression)!=NULL) {
    (yyval._expression) = new bit_expression(10, (yysemantic_stack_[(3) - (1)]._expression), (yysemantic_stack_[(3) - (3)]._expression));
  } else
    (yyval._expression) = NULL;
 }
    break;

  case 319:

/* Line 690 of lalr1.cc  */
#line 1976 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(3) - (1)]._expression)!=NULL && (yysemantic_stack_[(3) - (3)]._expression)!=NULL) {
    (yyval._expression) = new bit_expression(12, (yysemantic_stack_[(3) - (1)]._expression), (yysemantic_stack_[(3) - (3)]._expression));
  } else
    (yyval._expression) = NULL;
 }
    break;

  case 320:

/* Line 690 of lalr1.cc  */
#line 1982 "parser/nssis_new.yy"
    {
  (yyval._expression) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(3) - (1)]._expression));
 }
    break;

  case 321:

/* Line 690 of lalr1.cc  */
#line 1987 "parser/nssis_new.yy"
    {
  (yyval._expression) = (yysemantic_stack_[(1) - (1)]._expression);
  }
    break;

  case 322:

/* Line 690 of lalr1.cc  */
#line 1990 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(3) - (1)]._expression)!=NULL && (yysemantic_stack_[(3) - (3)]._expression)!=NULL) {
    (yyval._expression) = new bit_expression(9, (yysemantic_stack_[(3) - (1)]._expression), (yysemantic_stack_[(3) - (3)]._expression));
  } else
    (yyval._expression) = NULL;
 }
    break;

  case 323:

/* Line 690 of lalr1.cc  */
#line 1996 "parser/nssis_new.yy"
    {
  (yyval._expression) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(3) - (1)]._expression));
 }
    break;

  case 324:

/* Line 690 of lalr1.cc  */
#line 2001 "parser/nssis_new.yy"
    {
  (yyval._expression) = (yysemantic_stack_[(1) - (1)]._expression);
  }
    break;

  case 325:

/* Line 690 of lalr1.cc  */
#line 2004 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(2) - (2)]._expression)!=NULL) {
    (yyval._expression) = new bit_expression(11, (yysemantic_stack_[(2) - (2)]._expression), NULL);
  } else
    (yyval._expression) = NULL;
 }
    break;

  case 326:

/* Line 690 of lalr1.cc  */
#line 2010 "parser/nssis_new.yy"
    {
  (yyval._expression) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(2) - (2)]._expression));
 }
    break;

  case 327:

/* Line 690 of lalr1.cc  */
#line 2015 "parser/nssis_new.yy"
    {
  (yyval._expression) = (yysemantic_stack_[(1) - (1)]._expression);
  }
    break;

  case 328:

/* Line 690 of lalr1.cc  */
#line 2018 "parser/nssis_new.yy"
    {
  (yyval._expression) = (yysemantic_stack_[(3) - (2)]._expression);
  }
    break;

  case 329:

/* Line 690 of lalr1.cc  */
#line 2021 "parser/nssis_new.yy"
    {
  (yyval._expression) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(3) - (2)]._expression));
 }
    break;

  case 330:

/* Line 690 of lalr1.cc  */
#line 2026 "parser/nssis_new.yy"
    {
  (yyval._expression) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(3) - (2)]._expression));
 }
    break;

  case 331:

/* Line 690 of lalr1.cc  */
#line 2031 "parser/nssis_new.yy"
    {
  (yyval._expression) = (yysemantic_stack_[(1) - (1)]._expression);
  }
    break;

  case 332:

/* Line 690 of lalr1.cc  */
#line 2035 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(3) - (1)]._expression)!=NULL && (yysemantic_stack_[(3) - (3)]._expression)!=NULL) {
    (yyval._expression) = new arithmetic_expression(5, (yysemantic_stack_[(3) - (1)]._expression), (yysemantic_stack_[(3) - (3)]._expression));
  } else
    (yyval._expression) = NULL;
 }
    break;

  case 333:

/* Line 690 of lalr1.cc  */
#line 2041 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(3) - (1)]._expression)!=NULL && (yysemantic_stack_[(3) - (3)]._expression)!=NULL) {
    (yyval._expression) = new arithmetic_expression(6, (yysemantic_stack_[(3) - (1)]._expression), (yysemantic_stack_[(3) - (3)]._expression));
  } else
    (yyval._expression) = NULL;
 }
    break;

  case 334:

/* Line 690 of lalr1.cc  */
#line 2047 "parser/nssis_new.yy"
    {
  (yyval._expression) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(3) - (1)]._expression));
 }
    break;

  case 335:

/* Line 690 of lalr1.cc  */
#line 2052 "parser/nssis_new.yy"
    {
  (yyval._expression) = (yysemantic_stack_[(1) - (1)]._expression);
  }
    break;

  case 336:

/* Line 690 of lalr1.cc  */
#line 2055 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(3) - (1)]._expression)!=NULL && (yysemantic_stack_[(3) - (3)]._expression)!=NULL) {
    (yyval._expression) = new arithmetic_expression(7, (yysemantic_stack_[(3) - (1)]._expression), (yysemantic_stack_[(3) - (3)]._expression));
  } else
    (yyval._expression) = NULL;
 }
    break;

  case 337:

/* Line 690 of lalr1.cc  */
#line 2061 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(3) - (1)]._expression)!=NULL && (yysemantic_stack_[(3) - (3)]._expression)!=NULL) {
    (yyval._expression) = new arithmetic_expression(8, (yysemantic_stack_[(3) - (1)]._expression), (yysemantic_stack_[(3) - (3)]._expression));
  } else
    (yyval._expression) = NULL;
 }
    break;

  case 338:

/* Line 690 of lalr1.cc  */
#line 2067 "parser/nssis_new.yy"
    {
  (yyval._expression) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(3) - (1)]._expression));
 }
    break;

  case 339:

/* Line 690 of lalr1.cc  */
#line 2072 "parser/nssis_new.yy"
    {
  (yyval._expression) = (yysemantic_stack_[(1) - (1)]._expression);
  }
    break;

  case 340:

/* Line 690 of lalr1.cc  */
#line 2075 "parser/nssis_new.yy"
    {
  (yyval._expression) = (yysemantic_stack_[(3) - (2)]._expression);
  }
    break;

  case 341:

/* Line 690 of lalr1.cc  */
#line 2078 "parser/nssis_new.yy"
    {
  (yyval._expression) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(3) - (2)]._expression));
 }
    break;

  case 342:

/* Line 690 of lalr1.cc  */
#line 2083 "parser/nssis_new.yy"
    {
  (yyval._expression) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(3) - (2)]._expression));
 }
    break;

  case 343:

/* Line 690 of lalr1.cc  */
#line 2088 "parser/nssis_new.yy"
    {
  (yyval._expression) = (yysemantic_stack_[(1) - (1)]._expression);
  }
    break;

  case 344:

/* Line 690 of lalr1.cc  */
#line 2091 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(3) - (1)]._expression)!=NULL && (yysemantic_stack_[(3) - (3)]._expression)!=NULL) {
    (yyval._expression) = new arithmetic_expression(5, (yysemantic_stack_[(3) - (1)]._expression), (yysemantic_stack_[(3) - (3)]._expression));
  } else
    (yyval._expression) = NULL;
 }
    break;

  case 345:

/* Line 690 of lalr1.cc  */
#line 2097 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(3) - (1)]._expression)!=NULL && (yysemantic_stack_[(3) - (3)]._expression)!=NULL) {
    (yyval._expression) = new arithmetic_expression(6, (yysemantic_stack_[(3) - (1)]._expression), (yysemantic_stack_[(3) - (3)]._expression));
  } else
    (yyval._expression) = NULL;
 }
    break;

  case 346:

/* Line 690 of lalr1.cc  */
#line 2103 "parser/nssis_new.yy"
    {
  (yyval._expression) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(3) - (1)]._expression));
 }
    break;

  case 347:

/* Line 690 of lalr1.cc  */
#line 2108 "parser/nssis_new.yy"
    {
  (yyval._expression) = (yysemantic_stack_[(1) - (1)]._expression);
  }
    break;

  case 348:

/* Line 690 of lalr1.cc  */
#line 2111 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(3) - (1)]._expression)!=NULL && (yysemantic_stack_[(3) - (3)]._expression)!=NULL) {
    (yyval._expression) = new arithmetic_expression(7, (yysemantic_stack_[(3) - (1)]._expression), (yysemantic_stack_[(3) - (3)]._expression));
  } else
    (yyval._expression) = NULL;
 }
    break;

  case 349:

/* Line 690 of lalr1.cc  */
#line 2117 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(3) - (1)]._expression)!=NULL && (yysemantic_stack_[(3) - (3)]._expression)!=NULL) {
    (yyval._expression) = new arithmetic_expression(8, (yysemantic_stack_[(3) - (1)]._expression), (yysemantic_stack_[(3) - (3)]._expression));
  } else
    (yyval._expression) = NULL;
 }
    break;

  case 350:

/* Line 690 of lalr1.cc  */
#line 2123 "parser/nssis_new.yy"
    {
  (yyval._expression) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(3) - (1)]._expression));
 }
    break;

  case 351:

/* Line 690 of lalr1.cc  */
#line 2128 "parser/nssis_new.yy"
    {
  (yyval._expression) = (yysemantic_stack_[(1) - (1)]._expression);
  }
    break;

  case 352:

/* Line 690 of lalr1.cc  */
#line 2131 "parser/nssis_new.yy"
    {
  (yyval._expression) = (yysemantic_stack_[(3) - (2)]._expression);
  }
    break;

  case 353:

/* Line 690 of lalr1.cc  */
#line 2134 "parser/nssis_new.yy"
    {
  (yyval._expression) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(3) - (2)]._expression));
 }
    break;

  case 354:

/* Line 690 of lalr1.cc  */
#line 2139 "parser/nssis_new.yy"
    {
  (yyval._expression) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(3) - (2)]._expression));
 }
    break;

  case 355:

/* Line 690 of lalr1.cc  */
#line 2144 "parser/nssis_new.yy"
    {
  (yyval._expression) = (yysemantic_stack_[(1) - (1)]._expression);
  }
    break;

  case 356:

/* Line 690 of lalr1.cc  */
#line 2150 "parser/nssis_new.yy"
    { 
  (yyval._bool_expression) = (yysemantic_stack_[(3) - (2)]._bool_expression); 
 }
    break;

  case 357:

/* Line 690 of lalr1.cc  */
#line 2153 "parser/nssis_new.yy"
    { 
  (yyval._bool_expression) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(3) - (2)]._bool_expression));
 }
    break;

  case 358:

/* Line 690 of lalr1.cc  */
#line 2158 "parser/nssis_new.yy"
    { 
  (yyval._bool_expression) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(3) - (2)]._bool_expression));
 }
    break;

  case 359:

/* Line 690 of lalr1.cc  */
#line 2163 "parser/nssis_new.yy"
    { 
  (yyval._bool_expression) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(3) - (2)]._bool_expression));
 }
    break;

  case 360:

/* Line 690 of lalr1.cc  */
#line 2168 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(3) - (1)]._bool_expression)!=NULL && (yysemantic_stack_[(3) - (3)]._bool_expression)!=NULL)
    (yyval._bool_expression) = new bool_expression(1, (yysemantic_stack_[(3) - (1)]._bool_expression), (yysemantic_stack_[(3) - (3)]._bool_expression));
  else
    (yyval._bool_expression) = NULL;
 }
    break;

  case 361:

/* Line 690 of lalr1.cc  */
#line 2174 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(3) - (1)]._bool_expression)!=NULL && (yysemantic_stack_[(3) - (3)]._bool_expression)!=NULL)
    (yyval._bool_expression) = new bool_expression(2, (yysemantic_stack_[(3) - (1)]._bool_expression), (yysemantic_stack_[(3) - (3)]._bool_expression));
  else
    (yyval._bool_expression) = NULL;
 }
    break;

  case 362:

/* Line 690 of lalr1.cc  */
#line 2180 "parser/nssis_new.yy"
    {
  (yyval._bool_expression) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(3) - (1)]._bool_expression));
  USE((yysemantic_stack_[(3) - (3)]._bool_expression));
 }
    break;

  case 363:

/* Line 690 of lalr1.cc  */
#line 2186 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(2) - (2)]._bool_expression)!=NULL)
    (yyval._bool_expression) = new bool_expression(3, (yysemantic_stack_[(2) - (2)]._bool_expression));
  else
    (yyval._bool_expression) = NULL;
 }
    break;

  case 364:

/* Line 690 of lalr1.cc  */
#line 2192 "parser/nssis_new.yy"
    {
  (yyval._bool_expression) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(2) - (2)]._bool_expression));
 }
    break;

  case 365:

/* Line 690 of lalr1.cc  */
#line 2197 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(3) - (1)]._expression)!=NULL && (yysemantic_stack_[(3) - (3)]._expression)!=NULL) {
    logic_expression *expr = new logic_expression((yysemantic_stack_[(3) - (2)]._unsigned_char), (yysemantic_stack_[(3) - (1)]._expression), (yysemantic_stack_[(3) - (3)]._expression));
    (yyval._bool_expression) = new bool_expression(0,  expr);
  } else
    (yyval._bool_expression) = NULL;
 }
    break;

  case 366:

/* Line 690 of lalr1.cc  */
#line 2204 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(3) - (3)].sval)!=NULL) {
    laction *a = new laction();
    variable *v;
    int i = search_string_table((yysemantic_stack_[(3) - (3)].sval));
    if(i>=0) {
      v = new variable((*string_table)[i]);
      free((yysemantic_stack_[(3) - (3)].sval));
    } else {
      v = new variable((yysemantic_stack_[(3) - (3)].sval));
      string_table->push_back((yysemantic_stack_[(3) - (3)].sval));
    }
    logic_expression *expr = new logic_expression(0, a, v);
    (yyval._bool_expression) = new bool_expression(0,  expr);
  } else
    (yyval._bool_expression) = NULL;
 }
    break;

  case 367:

/* Line 690 of lalr1.cc  */
#line 2221 "parser/nssis_new.yy"
    {
  (yyval._bool_expression) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(3) - (3)].sval));
 }
    break;

  case 368:

/* Line 690 of lalr1.cc  */
#line 2226 "parser/nssis_new.yy"
    {
  (yyval._bool_expression) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(3) - (3)].sval));
 }
    break;

  case 369:

/* Line 690 of lalr1.cc  */
#line 2231 "parser/nssis_new.yy"
    {
  (yyval._bool_expression) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(2) - (2)].sval));
 }
    break;

  case 370:

/* Line 690 of lalr1.cc  */
#line 2236 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(5) - (1)].sval)!=NULL && (yysemantic_stack_[(5) - (5)].sval)!=NULL) {
    laction *a;
    int i = search_string_table((yysemantic_stack_[(5) - (1)].sval));
    if(i>=0) {
      a = new laction((*string_table)[i]);
      free((yysemantic_stack_[(5) - (1)].sval));
    } else {
      a = new laction((yysemantic_stack_[(5) - (1)].sval));
      string_table->push_back((yysemantic_stack_[(5) - (1)].sval));
    }
    variable *v;
    int j = search_string_table((yysemantic_stack_[(5) - (5)].sval));
    if(j>=0) {
      if(i>=0)
	v = new variable((*string_table)[i], (*string_table)[j]);
      else
	v = new variable((yysemantic_stack_[(5) - (1)].sval), (*string_table)[j]);
      free((yysemantic_stack_[(5) - (5)].sval));
    } else {
      if(i>=0)
	v = new variable((*string_table)[i], (yysemantic_stack_[(5) - (5)].sval));
      else
	v = new variable((yysemantic_stack_[(5) - (1)].sval), (yysemantic_stack_[(5) - (5)].sval));
      string_table->push_back((yysemantic_stack_[(5) - (5)].sval));
    }
    i = search_logic_expression_table(a, v);
    if(i>=0) {
      (yyval._bool_expression) = (*logic_expression_table)[i];
      delete a;
      delete v;
    } else {
			logic_expression *expr = new logic_expression(0, a, v);
			bool_expression *bexpr = new bool_expression(0,  expr);
      (yyval._bool_expression) = bexpr;
      logic_expression_table->push_back(bexpr);
    }
  } else
    (yyval._bool_expression) = NULL;
 }
    break;

  case 371:

/* Line 690 of lalr1.cc  */
#line 2276 "parser/nssis_new.yy"
    {
  (yyval._bool_expression) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(5) - (1)].sval));
  USE((yysemantic_stack_[(5) - (5)].sval));
 }
    break;

  case 372:

/* Line 690 of lalr1.cc  */
#line 2282 "parser/nssis_new.yy"
    {
  (yyval._bool_expression) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(5) - (1)].sval));
  USE((yysemantic_stack_[(5) - (5)].sval));
 }
    break;

  case 373:

/* Line 690 of lalr1.cc  */
#line 2288 "parser/nssis_new.yy"
    {
  (yyval._bool_expression) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(5) - (1)].sval));
  USE((yysemantic_stack_[(5) - (5)].sval));
 }
    break;

  case 374:

/* Line 690 of lalr1.cc  */
#line 2294 "parser/nssis_new.yy"
    {
  (yyval._bool_expression) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(4) - (1)].sval));
  USE((yysemantic_stack_[(4) - (4)].sval));
 }
    break;

  case 375:

/* Line 690 of lalr1.cc  */
#line 2300 "parser/nssis_new.yy"
    {
  (yyval._bool_expression) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(4) - (1)].sval));
  USE((yysemantic_stack_[(4) - (4)].sval));
 }
    break;

  case 376:

/* Line 690 of lalr1.cc  */
#line 2306 "parser/nssis_new.yy"
    {
  (yyval._bool_expression) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(5) - (1)].sval));
  USE((yysemantic_stack_[(5) - (5)].sval));
 }
    break;

  case 377:

/* Line 690 of lalr1.cc  */
#line 2312 "parser/nssis_new.yy"
    {
  (yyval._bool_expression) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(3) - (1)].sval));
  USE((yysemantic_stack_[(3) - (3)].sval));
 }
    break;

  case 378:

/* Line 690 of lalr1.cc  */
#line 2318 "parser/nssis_new.yy"
    {
  (yyval._bool_expression) = NULL;
  driver.syntax_error = true;
  }
    break;

  case 379:

/* Line 690 of lalr1.cc  */
#line 2323 "parser/nssis_new.yy"
    {
  (yyval._unsigned_char) = 2;
 }
    break;

  case 380:

/* Line 690 of lalr1.cc  */
#line 2326 "parser/nssis_new.yy"
    {
  (yyval._unsigned_char) = 3;
  }
    break;

  case 381:

/* Line 690 of lalr1.cc  */
#line 2329 "parser/nssis_new.yy"
    {
  (yyval._unsigned_char) = 4;
  }
    break;

  case 382:

/* Line 690 of lalr1.cc  */
#line 2332 "parser/nssis_new.yy"
    {
  (yyval._unsigned_char) = 5;
  }
    break;

  case 383:

/* Line 690 of lalr1.cc  */
#line 2335 "parser/nssis_new.yy"
    {
  (yyval._unsigned_char) = 0;
  }
    break;

  case 384:

/* Line 690 of lalr1.cc  */
#line 2338 "parser/nssis_new.yy"
    {
  (yyval._unsigned_char) = 1;
  }
    break;

  case 385:

/* Line 690 of lalr1.cc  */
#line 2343 "parser/nssis_new.yy"
    { 
  (yyval._bool_expression) = (yysemantic_stack_[(3) - (2)]._bool_expression); 
 }
    break;

  case 386:

/* Line 690 of lalr1.cc  */
#line 2346 "parser/nssis_new.yy"
    { 
  (yyval._bool_expression) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(3) - (2)]._bool_expression));
 }
    break;

  case 387:

/* Line 690 of lalr1.cc  */
#line 2351 "parser/nssis_new.yy"
    { 
  (yyval._bool_expression) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(3) - (2)]._bool_expression));
 }
    break;

  case 388:

/* Line 690 of lalr1.cc  */
#line 2356 "parser/nssis_new.yy"
    { 
  (yyval._bool_expression) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(3) - (2)]._bool_expression));
 }
    break;

  case 389:

/* Line 690 of lalr1.cc  */
#line 2361 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(3) - (1)]._bool_expression)!=NULL && (yysemantic_stack_[(3) - (3)]._bool_expression)!=NULL)
    (yyval._bool_expression) = new bool_expression(1, (yysemantic_stack_[(3) - (1)]._bool_expression), (yysemantic_stack_[(3) - (3)]._bool_expression));
  else
    (yyval._bool_expression) = NULL;
 }
    break;

  case 390:

/* Line 690 of lalr1.cc  */
#line 2367 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(3) - (1)]._bool_expression)!=NULL && (yysemantic_stack_[(3) - (3)]._bool_expression)!=NULL)
    (yyval._bool_expression) = new bool_expression(2, (yysemantic_stack_[(3) - (1)]._bool_expression), (yysemantic_stack_[(3) - (3)]._bool_expression));
  else
    (yyval._bool_expression) = NULL;
 }
    break;

  case 391:

/* Line 690 of lalr1.cc  */
#line 2373 "parser/nssis_new.yy"
    {
  (yyval._bool_expression) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(3) - (1)]._bool_expression));
  USE((yysemantic_stack_[(3) - (3)]._bool_expression));
 }
    break;

  case 392:

/* Line 690 of lalr1.cc  */
#line 2379 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(2) - (2)]._bool_expression)!=NULL)
    (yyval._bool_expression) = new bool_expression(3, (yysemantic_stack_[(2) - (2)]._bool_expression));
  else
    (yyval._bool_expression) = NULL;
 }
    break;

  case 393:

/* Line 690 of lalr1.cc  */
#line 2385 "parser/nssis_new.yy"
    {
  (yyval._bool_expression) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(2) - (2)]._bool_expression));
 }
    break;

  case 394:

/* Line 690 of lalr1.cc  */
#line 2390 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(3) - (1)]._expression)!=NULL && (yysemantic_stack_[(3) - (3)]._expression)!=NULL) {
    logic_expression *expr = new logic_expression((yysemantic_stack_[(3) - (2)]._unsigned_char), (yysemantic_stack_[(3) - (1)]._expression), (yysemantic_stack_[(3) - (3)]._expression));
    (yyval._bool_expression) = new bool_expression(0,  expr);
  } else
    (yyval._bool_expression) = NULL;
 }
    break;

  case 395:

/* Line 690 of lalr1.cc  */
#line 2397 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(3) - (3)].sval)!=NULL) {
    laction *a = new laction();
    variable *v;
    int i = search_string_table((yysemantic_stack_[(3) - (3)].sval));
    if(i>=0) {
      v = new variable((*string_table)[i]);
      free((yysemantic_stack_[(3) - (3)].sval));
    } else {
      v = new variable((yysemantic_stack_[(3) - (3)].sval));
      string_table->push_back((yysemantic_stack_[(3) - (3)].sval));
    }
    logic_expression *expr = new logic_expression(0, a, v);
    (yyval._bool_expression) = new bool_expression(0,  expr);
  } else
    (yyval._bool_expression) = NULL;
 }
    break;

  case 396:

/* Line 690 of lalr1.cc  */
#line 2414 "parser/nssis_new.yy"
    {
  (yyval._bool_expression) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(3) - (3)].sval));
 }
    break;

  case 397:

/* Line 690 of lalr1.cc  */
#line 2419 "parser/nssis_new.yy"
    {
  (yyval._bool_expression) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(3) - (3)].sval));
 }
    break;

  case 398:

/* Line 690 of lalr1.cc  */
#line 2424 "parser/nssis_new.yy"
    {
  (yyval._bool_expression) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(2) - (2)].sval));
 }
    break;

  case 399:

/* Line 690 of lalr1.cc  */
#line 2429 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(5) - (1)].sval)!=NULL && (yysemantic_stack_[(5) - (5)].sval)!=NULL) {
    laction *a;
    int i = search_string_table((yysemantic_stack_[(5) - (1)].sval));
    if(i>=0) {
      a = new laction((*string_table)[i]);
      free((yysemantic_stack_[(5) - (1)].sval));
    } else {
      a = new laction((yysemantic_stack_[(5) - (1)].sval));
      string_table->push_back((yysemantic_stack_[(5) - (1)].sval));
    }
    variable *v;
    int j = search_string_table((yysemantic_stack_[(5) - (5)].sval));
    if(j>=0) {
      if(i>=0)
	v = new variable((*string_table)[i], (*string_table)[j]);
      else
	v = new variable((yysemantic_stack_[(5) - (1)].sval), (*string_table)[j]);
      free((yysemantic_stack_[(5) - (5)].sval));
    } else {
      if(i>=0)
	v = new variable((*string_table)[i], (yysemantic_stack_[(5) - (5)].sval));
      else
	v = new variable((yysemantic_stack_[(5) - (1)].sval), (yysemantic_stack_[(5) - (5)].sval));
      string_table->push_back((yysemantic_stack_[(5) - (5)].sval));
    }
    logic_expression *expr = new logic_expression(0, a, v);
    (yyval._bool_expression) = new bool_expression(0,  expr);
  } else 
    (yyval._bool_expression) = NULL;
 }
    break;

  case 400:

/* Line 690 of lalr1.cc  */
#line 2460 "parser/nssis_new.yy"
    {
  (yyval._bool_expression) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(5) - (1)].sval));
  USE((yysemantic_stack_[(5) - (5)].sval));
 }
    break;

  case 401:

/* Line 690 of lalr1.cc  */
#line 2466 "parser/nssis_new.yy"
    {
  (yyval._bool_expression) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(5) - (1)].sval));
  USE((yysemantic_stack_[(5) - (5)].sval));
 }
    break;

  case 402:

/* Line 690 of lalr1.cc  */
#line 2472 "parser/nssis_new.yy"
    {
  (yyval._bool_expression) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(5) - (1)].sval));
  USE((yysemantic_stack_[(5) - (5)].sval));
 }
    break;

  case 403:

/* Line 690 of lalr1.cc  */
#line 2478 "parser/nssis_new.yy"
    {
  (yyval._bool_expression) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(4) - (1)].sval));
  USE((yysemantic_stack_[(4) - (4)].sval));
 }
    break;

  case 404:

/* Line 690 of lalr1.cc  */
#line 2484 "parser/nssis_new.yy"
    {
  (yyval._bool_expression) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(4) - (1)].sval));
  USE((yysemantic_stack_[(4) - (4)].sval));
 }
    break;

  case 405:

/* Line 690 of lalr1.cc  */
#line 2490 "parser/nssis_new.yy"
    {
  (yyval._bool_expression) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(5) - (1)].sval));
  USE((yysemantic_stack_[(5) - (5)].sval));
 }
    break;

  case 406:

/* Line 690 of lalr1.cc  */
#line 2496 "parser/nssis_new.yy"
    {
  (yyval._bool_expression) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(3) - (1)].sval));
  USE((yysemantic_stack_[(3) - (3)].sval));
 }
    break;

  case 407:

/* Line 690 of lalr1.cc  */
#line 2502 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(5) - (5)].sval)!=NULL) {
    laction *a = new laction((*string_table)[0]);
    variable *v;
    int j = search_string_table((yysemantic_stack_[(5) - (5)].sval));
    if(j>=0) {
      v = new variable((*string_table)[0], (*string_table)[j]);
      free((yysemantic_stack_[(5) - (5)].sval));
    } else { 
      v = new variable((*string_table)[0], (yysemantic_stack_[(5) - (5)].sval));
      string_table->push_back((yysemantic_stack_[(5) - (5)].sval));
    }
    logic_expression *expr = new logic_expression(0, a, v);
    (yyval._bool_expression) = new bool_expression(0,  expr);
  } else
    (yyval._bool_expression) = NULL;
 }
    break;

  case 408:

/* Line 690 of lalr1.cc  */
#line 2519 "parser/nssis_new.yy"
    {
  (yyval._bool_expression) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(5) - (5)].sval));
 }
    break;

  case 409:

/* Line 690 of lalr1.cc  */
#line 2524 "parser/nssis_new.yy"
    {
  (yyval._bool_expression) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(5) - (5)].sval));
 }
    break;

  case 410:

/* Line 690 of lalr1.cc  */
#line 2529 "parser/nssis_new.yy"
    {
  (yyval._bool_expression) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(4) - (4)].sval));
 }
    break;

  case 411:

/* Line 690 of lalr1.cc  */
#line 2534 "parser/nssis_new.yy"
    {
  (yyval._bool_expression) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(4) - (4)].sval));
 }
    break;

  case 412:

/* Line 690 of lalr1.cc  */
#line 2539 "parser/nssis_new.yy"
    {
  (yyval._bool_expression) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(5) - (5)].sval));
 }
    break;

  case 413:

/* Line 690 of lalr1.cc  */
#line 2544 "parser/nssis_new.yy"
    {
  (yyval._bool_expression) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(3) - (3)].sval));
 }
    break;

  case 414:

/* Line 690 of lalr1.cc  */
#line 2549 "parser/nssis_new.yy"
    {
  (yyval._bool_expression) = NULL;
  driver.syntax_error = true;
  }
    break;

  case 415:

/* Line 690 of lalr1.cc  */
#line 2555 "parser/nssis_new.yy"
    {
  (yyval._expression) = (yysemantic_stack_[(1) - (1)]._bool_value);
 }
    break;

  case 416:

/* Line 690 of lalr1.cc  */
#line 2558 "parser/nssis_new.yy"
    {
    int i = search_string_table((yysemantic_stack_[(1) - (1)].sval));
    if(i>=0) {
      (yyval._expression) = new variable((*string_table)[i]);
      free((yysemantic_stack_[(1) - (1)].sval));
    } else {
      (yyval._expression) = new variable((yysemantic_stack_[(1) - (1)].sval)); // can be enumerate value. Will be decided during global syntax checking
      string_table->push_back((yysemantic_stack_[(1) - (1)].sval));
    }
  }
    break;

  case 417:

/* Line 690 of lalr1.cc  */
#line 2568 "parser/nssis_new.yy"
    {
  (yyval._expression) = new int_value((yysemantic_stack_[(1) - (1)].ival));
  }
    break;

  case 418:

/* Line 690 of lalr1.cc  */
#line 2571 "parser/nssis_new.yy"
    {
  (yyval._bool_value) = new bool_value(true);
  }
    break;

  case 419:

/* Line 690 of lalr1.cc  */
#line 2574 "parser/nssis_new.yy"
    {
  (yyval._bool_value) = new bool_value(false);
  }
    break;

  case 420:

/* Line 690 of lalr1.cc  */
#line 2578 "parser/nssis_new.yy"
    {
  (yyval._expression) = (yysemantic_stack_[(1) - (1)]._bool_value);
 }
    break;

  case 421:

/* Line 690 of lalr1.cc  */
#line 2581 "parser/nssis_new.yy"
    {
    int i = search_string_table((yysemantic_stack_[(1) - (1)].sval));
    if(i>=0) {
      (yyval._expression) = new variable((*string_table)[i]);
      free((yysemantic_stack_[(1) - (1)].sval));
    } else {
      (yyval._expression) = new variable((yysemantic_stack_[(1) - (1)].sval)); // can be enumerate value. Will be decided during global syntax checking
      string_table->push_back((yysemantic_stack_[(1) - (1)].sval));
    }
  }
    break;

  case 422:

/* Line 690 of lalr1.cc  */
#line 2591 "parser/nssis_new.yy"
    {
    int i = search_string_table((yysemantic_stack_[(3) - (3)].sval));
    variable *var;
    if(i>=0) {
      var = new variable((*string_table)[0], (*string_table)[i]);
      free((yysemantic_stack_[(3) - (3)].sval));
    } else {
      var = new variable((*string_table)[0], (yysemantic_stack_[(3) - (3)].sval)); 
      string_table->push_back((yysemantic_stack_[(3) - (3)].sval));
    }
    i = search_variable_table(var);
    if(i>=0) {
      (yyval._expression) = (*variable_table)[i];
      delete var;
    } else {
      (yyval._expression) = var;
      variable_table->push_back(var);
    }
  }
    break;

  case 423:

/* Line 690 of lalr1.cc  */
#line 2610 "parser/nssis_new.yy"
    {
  (yyval._expression) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(3) - (3)].sval));
  }
    break;

  case 424:

/* Line 690 of lalr1.cc  */
#line 2615 "parser/nssis_new.yy"
    {
  (yyval._expression) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(3) - (3)].sval));
  }
    break;

  case 425:

/* Line 690 of lalr1.cc  */
#line 2620 "parser/nssis_new.yy"
    {
  (yyval._expression) = new int_value((yysemantic_stack_[(1) - (1)].ival));
  }
    break;

  case 426:

/* Line 690 of lalr1.cc  */
#line 2623 "parser/nssis_new.yy"
    {
  (yyval._expression) = (yysemantic_stack_[(1) - (1)]._bool_value);
 }
    break;

  case 427:

/* Line 690 of lalr1.cc  */
#line 2626 "parser/nssis_new.yy"
    {
    int i = search_string_table((yysemantic_stack_[(1) - (1)].sval));
    if(i>=0) {
      (yyval._expression) = new variable((*string_table)[i]);
      free((yysemantic_stack_[(1) - (1)].sval));
    } else {
      (yyval._expression) = new variable((yysemantic_stack_[(1) - (1)].sval)); // can be enumerate value. Will be decided during global syntax checking
      string_table->push_back((yysemantic_stack_[(1) - (1)].sval));
    }
  }
    break;

  case 428:

/* Line 690 of lalr1.cc  */
#line 2636 "parser/nssis_new.yy"
    {
    int i = search_string_table((yysemantic_stack_[(3) - (1)].sval));
    int j = search_string_table((yysemantic_stack_[(3) - (3)].sval));
    variable *var;
    if(i>=0) {
      if(j>=0) {
	var = new variable((*string_table)[i], (*string_table)[j]);
	free((yysemantic_stack_[(3) - (3)].sval));
      } else {
	var = new variable((*string_table)[i], (yysemantic_stack_[(3) - (3)].sval));
	string_table->push_back((yysemantic_stack_[(3) - (3)].sval));
      }
      free((yysemantic_stack_[(3) - (1)].sval));
    } else {
      if(j>=0) {
	var = new variable((yysemantic_stack_[(3) - (1)].sval), (*string_table)[j]);
	free((yysemantic_stack_[(3) - (3)].sval));
      } else {
	var = new variable((yysemantic_stack_[(3) - (1)].sval), (yysemantic_stack_[(3) - (3)].sval));
	string_table->push_back((yysemantic_stack_[(3) - (3)].sval));
      }
      string_table->push_back((yysemantic_stack_[(3) - (1)].sval));
    }
    i = search_variable_table(var);
    if(i>=0) {
      (yyval._expression) = (*variable_table)[i];
      delete var;
    } else {
      (yyval._expression) = var;
      variable_table->push_back(var);
    }
  }
    break;

  case 429:

/* Line 690 of lalr1.cc  */
#line 2668 "parser/nssis_new.yy"
    {
  (yyval._expression) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(3) - (1)].sval));
  USE((yysemantic_stack_[(3) - (3)].sval));
  }
    break;

  case 430:

/* Line 690 of lalr1.cc  */
#line 2674 "parser/nssis_new.yy"
    {
    int i = search_string_table((yysemantic_stack_[(3) - (3)].sval));
    variable *var;
    if(i>=0) {
      var = new variable((*string_table)[0], (*string_table)[i]);
      free((yysemantic_stack_[(3) - (3)].sval));
    } else {
      var = new variable((*string_table)[0], (yysemantic_stack_[(3) - (3)].sval)); 
      string_table->push_back((yysemantic_stack_[(3) - (3)].sval));
    }
    i = search_variable_table(var);
    if(i>=0) {
      (yyval._expression) = (*variable_table)[i];
      delete var;
    } else {
      (yyval._expression) = var;
      variable_table->push_back(var);
    }
  }
    break;

  case 431:

/* Line 690 of lalr1.cc  */
#line 2693 "parser/nssis_new.yy"
    {
  (yyval._expression) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(3) - (3)].sval));
  }
    break;

  case 432:

/* Line 690 of lalr1.cc  */
#line 2698 "parser/nssis_new.yy"
    {
  (yyval._expression) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(3) - (3)].sval));
  }
    break;

  case 433:

/* Line 690 of lalr1.cc  */
#line 2703 "parser/nssis_new.yy"
    {
  (yyval._expression) = new int_value((yysemantic_stack_[(1) - (1)].ival));
  }
    break;

  case 434:

/* Line 690 of lalr1.cc  */
#line 2707 "parser/nssis_new.yy"
    {
  (yyval._expression) = (yysemantic_stack_[(1) - (1)]._bool_value);
 }
    break;

  case 435:

/* Line 690 of lalr1.cc  */
#line 2710 "parser/nssis_new.yy"
    {
    int i = search_string_table((yysemantic_stack_[(1) - (1)].sval));
    if(i>=0) {
      (yyval._expression) = new enum_value((*string_table)[i]);
      free((yysemantic_stack_[(1) - (1)].sval));
    } else {
      (yyval._expression) = new enum_value((yysemantic_stack_[(1) - (1)].sval)); // can be enumerate value. Will be decided during global syntax checking
      string_table->push_back((yysemantic_stack_[(1) - (1)].sval));
    }
  }
    break;

  case 436:

/* Line 690 of lalr1.cc  */
#line 2720 "parser/nssis_new.yy"
    {
  (yyval._expression) = new int_value((yysemantic_stack_[(1) - (1)].ival));
  }
    break;

  case 437:

/* Line 690 of lalr1.cc  */
#line 2725 "parser/nssis_new.yy"
    {
  (yyval.ival) = 1;
 }
    break;

  case 438:

/* Line 690 of lalr1.cc  */
#line 2728 "parser/nssis_new.yy"
    {
  (yyval.ival) = 1;
 }
    break;

  case 439:

/* Line 690 of lalr1.cc  */
#line 2731 "parser/nssis_new.yy"
    {
  (yyval.ival) = 0;
  driver.syntax_error = true;
 }
    break;

  case 440:

/* Line 690 of lalr1.cc  */
#line 2735 "parser/nssis_new.yy"
    {
  (yyval.ival) = 0;
  driver.syntax_error = true;
 }
    break;

  case 441:

/* Line 690 of lalr1.cc  */
#line 2739 "parser/nssis_new.yy"
    {
  (yyval.ival) = 0;
  driver.syntax_error = true;
  }
    break;

  case 443:

/* Line 690 of lalr1.cc  */
#line 2744 "parser/nssis_new.yy"
    {
  driver.syntax_error = true;
  }
    break;

  case 444:

/* Line 690 of lalr1.cc  */
#line 2748 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(4) - (1)].sval)!=NULL && (yysemantic_stack_[(4) - (3)]._bool_expression)!=NULL) {
    (*is_evaluation)[*(yysemantic_stack_[(4) - (1)].sval)] = (yysemantic_stack_[(4) - (3)]._bool_expression);
    free((yysemantic_stack_[(4) - (1)].sval));
  } 
 }
    break;

  case 445:

/* Line 690 of lalr1.cc  */
#line 2754 "parser/nssis_new.yy"
    {
  driver.syntax_error = true;
  USE((yysemantic_stack_[(4) - (1)].sval));
  USE((yysemantic_stack_[(4) - (3)]._bool_expression));
 }
    break;

  case 446:

/* Line 690 of lalr1.cc  */
#line 2759 "parser/nssis_new.yy"
    {
  driver.syntax_error = true;
  USE((yysemantic_stack_[(4) - (1)].sval));
  USE((yysemantic_stack_[(4) - (3)]._bool_expression));
 }
    break;

  case 447:

/* Line 690 of lalr1.cc  */
#line 2764 "parser/nssis_new.yy"
    {
  driver.syntax_error = true;
  USE((yysemantic_stack_[(4) - (1)].sval));
  USE((yysemantic_stack_[(4) - (3)]._bool_expression));
 }
    break;

  case 448:

/* Line 690 of lalr1.cc  */
#line 2769 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(5) - (2)].sval)!=NULL && (yysemantic_stack_[(5) - (4)]._bool_expression)!=NULL) {
    if(is_evaluation->find(*(yysemantic_stack_[(5) - (2)].sval)) != is_evaluation->end() && options["quiet"] == 0)
      cout << "warning: atomic proposition " << *(yysemantic_stack_[(5) - (2)].sval) << " has already been defined." << endl;
    (*is_evaluation)[*(yysemantic_stack_[(5) - (2)].sval)] = (yysemantic_stack_[(5) - (4)]._bool_expression);
    free((yysemantic_stack_[(5) - (2)].sval));
  }
 }
    break;

  case 449:

/* Line 690 of lalr1.cc  */
#line 2777 "parser/nssis_new.yy"
    {
  driver.syntax_error = true;
  USE((yysemantic_stack_[(5) - (2)].sval));
  USE((yysemantic_stack_[(5) - (4)]._bool_expression));
 }
    break;

  case 450:

/* Line 690 of lalr1.cc  */
#line 2782 "parser/nssis_new.yy"
    {
  driver.syntax_error = true;
  USE((yysemantic_stack_[(5) - (2)].sval));
  USE((yysemantic_stack_[(5) - (4)]._bool_expression));
 }
    break;

  case 451:

/* Line 690 of lalr1.cc  */
#line 2787 "parser/nssis_new.yy"
    {
  driver.syntax_error = true;
  USE((yysemantic_stack_[(5) - (2)].sval));
  USE((yysemantic_stack_[(5) - (4)]._bool_expression));
 }
    break;

  case 452:

/* Line 690 of lalr1.cc  */
#line 2792 "parser/nssis_new.yy"
    {
  driver.syntax_error = true;
  }
    break;

  case 453:

/* Line 690 of lalr1.cc  */
#line 2796 "parser/nssis_new.yy"
    { 
  (yyval._bool_expression) = (yysemantic_stack_[(3) - (2)]._bool_expression); 
 }
    break;

  case 454:

/* Line 690 of lalr1.cc  */
#line 2799 "parser/nssis_new.yy"
    { 
  (yyval._bool_expression) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(3) - (2)]._bool_expression));
 }
    break;

  case 455:

/* Line 690 of lalr1.cc  */
#line 2804 "parser/nssis_new.yy"
    { 
  (yyval._bool_expression) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(3) - (2)]._bool_expression));
 }
    break;

  case 456:

/* Line 690 of lalr1.cc  */
#line 2809 "parser/nssis_new.yy"
    { 
  (yyval._bool_expression) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(3) - (2)]._bool_expression));
 }
    break;

  case 457:

/* Line 690 of lalr1.cc  */
#line 2814 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(3) - (1)]._bool_expression)!=NULL && (yysemantic_stack_[(3) - (3)]._bool_expression)!=NULL)
    (yyval._bool_expression) = new bool_expression(1, (yysemantic_stack_[(3) - (1)]._bool_expression), (yysemantic_stack_[(3) - (3)]._bool_expression));
  else
    (yyval._bool_expression) = NULL;
 }
    break;

  case 458:

/* Line 690 of lalr1.cc  */
#line 2820 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(3) - (1)]._bool_expression)!=NULL && (yysemantic_stack_[(3) - (3)]._bool_expression)!=NULL)
    (yyval._bool_expression) = new bool_expression(2, (yysemantic_stack_[(3) - (1)]._bool_expression), (yysemantic_stack_[(3) - (3)]._bool_expression));
  else
    (yyval._bool_expression) = NULL;
 }
    break;

  case 459:

/* Line 690 of lalr1.cc  */
#line 2826 "parser/nssis_new.yy"
    {
  (yyval._bool_expression) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(3) - (1)]._bool_expression));USE((yysemantic_stack_[(3) - (3)]._bool_expression));
 }
    break;

  case 460:

/* Line 690 of lalr1.cc  */
#line 2831 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(2) - (2)]._bool_expression)!=NULL)
    (yyval._bool_expression) = new bool_expression(3, (yysemantic_stack_[(2) - (2)]._bool_expression));
  else
    (yyval._bool_expression) = NULL;
 }
    break;

  case 461:

/* Line 690 of lalr1.cc  */
#line 2837 "parser/nssis_new.yy"
    {
  (yyval._bool_expression) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(2) - (2)]._bool_expression));
 }
    break;

  case 462:

/* Line 690 of lalr1.cc  */
#line 2842 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(3) - (1)]._expression)!=NULL && (yysemantic_stack_[(3) - (3)]._expression)!=NULL) {
    logic_expression *expr = new logic_expression((yysemantic_stack_[(3) - (2)]._unsigned_char), (yysemantic_stack_[(3) - (1)]._expression), (yysemantic_stack_[(3) - (3)]._expression));
    (yyval._bool_expression) = new bool_expression(0,  expr);
  } else
    (yyval._bool_expression) = NULL;
 }
    break;

  case 463:

/* Line 690 of lalr1.cc  */
#line 2849 "parser/nssis_new.yy"
    {
  (yyval._bool_expression) = NULL;
  driver.syntax_error = true;
  }
    break;

  case 464:

/* Line 690 of lalr1.cc  */
#line 2857 "parser/nssis_new.yy"
    {
  (yyval.ival) = 1;
 }
    break;

  case 465:

/* Line 690 of lalr1.cc  */
#line 2860 "parser/nssis_new.yy"
    {
  (yyval.ival) = 0;
  driver.syntax_error = true;
 }
    break;

  case 466:

/* Line 690 of lalr1.cc  */
#line 2865 "parser/nssis_new.yy"
    {
  (yyval.ival) = 1;
 }
    break;

  case 467:

/* Line 690 of lalr1.cc  */
#line 2868 "parser/nssis_new.yy"
    {
  (yyval.ival) = 0;
  driver.syntax_error = true;
 }
    break;

  case 468:

/* Line 690 of lalr1.cc  */
#line 2872 "parser/nssis_new.yy"
    {
  (yyval.ival) = 0;
  driver.syntax_error = true;
 }
    break;

  case 469:

/* Line 690 of lalr1.cc  */
#line 2876 "parser/nssis_new.yy"
    {
  (yyval.ival) = 0;
  driver.syntax_error = true;
 }
    break;

  case 470:

/* Line 690 of lalr1.cc  */
#line 2880 "parser/nssis_new.yy"
    {
  (yyval.ival) = 0;
  driver.syntax_error = true;
 }
    break;

  case 471:

/* Line 690 of lalr1.cc  */
#line 2884 "parser/nssis_new.yy"
    {
  (yyval.ival) = 0;
  driver.syntax_error = true;
 }
    break;

  case 472:

/* Line 690 of lalr1.cc  */
#line 2888 "parser/nssis_new.yy"
    {
  (yyval.ival) = 0;
  driver.syntax_error = true;
 }
    break;

  case 473:

/* Line 690 of lalr1.cc  */
#line 2892 "parser/nssis_new.yy"
    {
  (yyval.ival) = 0;
  driver.syntax_error = true;
  }
    break;

  case 474:

/* Line 690 of lalr1.cc  */
#line 2896 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(3) - (1)].ival)==1 && (yysemantic_stack_[(3) - (3)].ival)==1)
    is_istates = (yysemantic_stack_[(3) - (2)]._bool_expression); 
 }
    break;

  case 475:

/* Line 690 of lalr1.cc  */
#line 2900 "parser/nssis_new.yy"
    {
  driver.syntax_error = true;
  }
    break;

  case 476:

/* Line 690 of lalr1.cc  */
#line 2904 "parser/nssis_new.yy"
    { 
  (yyval._bool_expression) = (yysemantic_stack_[(3) - (2)]._bool_expression); 
}
    break;

  case 477:

/* Line 690 of lalr1.cc  */
#line 2907 "parser/nssis_new.yy"
    { 
  (yyval._bool_expression) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(3) - (2)]._bool_expression));
 }
    break;

  case 478:

/* Line 690 of lalr1.cc  */
#line 2912 "parser/nssis_new.yy"
    { 
  (yyval._bool_expression) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(3) - (2)]._bool_expression));
 }
    break;

  case 479:

/* Line 690 of lalr1.cc  */
#line 2917 "parser/nssis_new.yy"
    { 
  (yyval._bool_expression) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(3) - (2)]._bool_expression))
 }
    break;

  case 480:

/* Line 690 of lalr1.cc  */
#line 2922 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(3) - (1)]._bool_expression)!=NULL && (yysemantic_stack_[(3) - (3)]._bool_expression)!=NULL)
    (yyval._bool_expression) = new bool_expression(1, (yysemantic_stack_[(3) - (1)]._bool_expression), (yysemantic_stack_[(3) - (3)]._bool_expression));
  else
    (yyval._bool_expression) = NULL;
 }
    break;

  case 481:

/* Line 690 of lalr1.cc  */
#line 2928 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(3) - (1)]._bool_expression)!=NULL && (yysemantic_stack_[(3) - (3)]._bool_expression)!=NULL)
    (yyval._bool_expression) = new bool_expression(2, (yysemantic_stack_[(3) - (1)]._bool_expression), (yysemantic_stack_[(3) - (3)]._bool_expression));
  else
    (yyval._bool_expression) = NULL;
 }
    break;

  case 482:

/* Line 690 of lalr1.cc  */
#line 2934 "parser/nssis_new.yy"
    {
  (yyval._bool_expression) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(3) - (1)]._bool_expression));USE((yysemantic_stack_[(3) - (3)]._bool_expression));
 }
    break;

  case 483:

/* Line 690 of lalr1.cc  */
#line 2939 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(2) - (2)]._bool_expression)!=NULL)
    (yyval._bool_expression) = new bool_expression(3, (yysemantic_stack_[(2) - (2)]._bool_expression));
  else
    (yyval._bool_expression) = NULL;
 }
    break;

  case 484:

/* Line 690 of lalr1.cc  */
#line 2945 "parser/nssis_new.yy"
    {
  (yyval._bool_expression) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(2) - (2)]._bool_expression));
 }
    break;

  case 485:

/* Line 690 of lalr1.cc  */
#line 2950 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(7) - (1)].sval)!=NULL && (yysemantic_stack_[(7) - (3)].sval)!=NULL && (yysemantic_stack_[(7) - (5)].sval)!=NULL && (yysemantic_stack_[(7) - (7)].sval)!=NULL) {
    int i = search_string_table((yysemantic_stack_[(7) - (1)].sval));
    int j = search_string_table((yysemantic_stack_[(7) - (3)].sval));
    variable *v;
    if(i>=0) {
      if(j>=0) {
	v = new variable((*string_table)[i], (*string_table)[j]);
	free((yysemantic_stack_[(7) - (3)].sval));
      } else {
	v = new variable((*string_table)[i], (yysemantic_stack_[(7) - (3)].sval));
	string_table->push_back((yysemantic_stack_[(7) - (3)].sval));
      }
      free((yysemantic_stack_[(7) - (1)].sval));
    } else {
      if(j>=0) {
	v = new variable((yysemantic_stack_[(7) - (1)].sval), (*string_table)[j]);
	free((yysemantic_stack_[(7) - (3)].sval));
      } else {
	v = new variable((yysemantic_stack_[(7) - (1)].sval), (yysemantic_stack_[(7) - (3)].sval));
	string_table->push_back((yysemantic_stack_[(7) - (3)].sval));
      }
      string_table->push_back((yysemantic_stack_[(7) - (1)].sval));
    }
    i = search_variable_table(v);
    if(i>=0) {
      delete v;
      v = (*variable_table)[i];
    } else {
      variable_table->push_back(v);
    }

    i = search_string_table((yysemantic_stack_[(7) - (5)].sval));
    j = search_string_table((yysemantic_stack_[(7) - (7)].sval));
    variable *v1;
    if(i>=0) {
      if(j>=0) {
	v1 = new variable((*string_table)[i], (*string_table)[j]);
	free((yysemantic_stack_[(7) - (7)].sval));
      } else {
	v1 = new variable((*string_table)[i], (yysemantic_stack_[(7) - (7)].sval));
	string_table->push_back((yysemantic_stack_[(7) - (7)].sval));
      }
      free((yysemantic_stack_[(7) - (5)].sval));
    } else {
      if(j>=0) {
	v1 = new variable((yysemantic_stack_[(7) - (5)].sval), (*string_table)[j]);
	free((yysemantic_stack_[(7) - (7)].sval));
      } else {
	v1 = new variable((yysemantic_stack_[(7) - (5)].sval), (yysemantic_stack_[(7) - (7)].sval));
	string_table->push_back((yysemantic_stack_[(7) - (7)].sval));
      }
      string_table->push_back((yysemantic_stack_[(7) - (5)].sval));
    }
    i = search_variable_table(v1);
    if(i>=0) {
      delete v1;
      v1 = (*variable_table)[i];
    } else {
      variable_table->push_back(v1);
    }

    i = search_logic_expression_table1(v, v1);
    if(i>=0) {
      (yyval._bool_expression) = (*logic_expression_table1)[i];
      free((yysemantic_stack_[(7) - (5)].sval));
    } else {
			logic_expression *e = new logic_expression(0, v, v1);
			bool_expression *bexpr = new bool_expression(0, e);
      (yyval._bool_expression) = bexpr;
      logic_expression_table1->push_back(bexpr);
    }    
  } else
    (yyval._bool_expression) = NULL;
 }
    break;

  case 486:

/* Line 690 of lalr1.cc  */
#line 3025 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(7) - (1)].sval)!=NULL && (yysemantic_stack_[(7) - (3)].sval)!=NULL && (yysemantic_stack_[(7) - (7)].sval)!=NULL) {
    int i = search_string_table((yysemantic_stack_[(7) - (1)].sval));
    int j = search_string_table((yysemantic_stack_[(7) - (3)].sval));
    variable *v;
    if(i>=0) {
      if(j>=0) {
	v = new variable((*string_table)[i], (*string_table)[j]);
	free((yysemantic_stack_[(7) - (3)].sval));
      } else {
	v = new variable((*string_table)[i], (yysemantic_stack_[(7) - (3)].sval));
	string_table->push_back((yysemantic_stack_[(7) - (3)].sval));
      }
      free((yysemantic_stack_[(7) - (1)].sval));
    } else {
      if(j>=0) {
	v = new variable((yysemantic_stack_[(7) - (1)].sval), (*string_table)[j]);
	free((yysemantic_stack_[(7) - (3)].sval));
      } else {
	v = new variable((yysemantic_stack_[(7) - (1)].sval), (yysemantic_stack_[(7) - (3)].sval));
	string_table->push_back((yysemantic_stack_[(7) - (3)].sval));
      }
      string_table->push_back((yysemantic_stack_[(7) - (1)].sval));
    }
    i = search_variable_table(v);
    if(i>=0) {
      delete v;
      v = (*variable_table)[i];
    } else {
      variable_table->push_back(v);
    }

    j = search_string_table((yysemantic_stack_[(7) - (7)].sval));
    variable *v1;
    if(j>=0) {
      v1 = new variable((*string_table)[0], (*string_table)[j]);
      free((yysemantic_stack_[(7) - (7)].sval));
    } else {
      v1 = new variable((*string_table)[0], (yysemantic_stack_[(7) - (7)].sval));
      string_table->push_back((yysemantic_stack_[(7) - (7)].sval));
    }
    
    i = search_variable_table(v1);
    if(i>=0) {
      delete v1;
      v1 = (*variable_table)[i];
    } else {
      variable_table->push_back(v1);
    }

    i = search_logic_expression_table1(v, v1);
    if(i>=0) {
      (yyval._bool_expression) = (*logic_expression_table1)[i];
    } else {
			logic_expression *e = new logic_expression(0, v, v1);
			bool_expression *bexpr = new bool_expression(0, e);
      (yyval._bool_expression) = bexpr;
      logic_expression_table1->push_back(bexpr);
    }    
  } else
    (yyval._bool_expression) = NULL;
 }
    break;

  case 487:

/* Line 690 of lalr1.cc  */
#line 3087 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(7) - (3)].sval)!=NULL && (yysemantic_stack_[(7) - (5)].sval)!=NULL && (yysemantic_stack_[(7) - (7)].sval)!=NULL) {
    int j = search_string_table((yysemantic_stack_[(7) - (3)].sval));
    variable *v;
    if(j>=0) {
      v = new variable((*string_table)[0], (*string_table)[j]);
      free((yysemantic_stack_[(7) - (3)].sval));
    } else {
      v = new variable((*string_table)[0], (yysemantic_stack_[(7) - (3)].sval));
      string_table->push_back((yysemantic_stack_[(7) - (3)].sval));
    }
    int i = search_variable_table(v);
    if(i>=0) {
      delete v;
      v = (*variable_table)[i];
    } else {
      variable_table->push_back(v);
    }

    i = search_string_table((yysemantic_stack_[(7) - (5)].sval));
    j = search_string_table((yysemantic_stack_[(7) - (7)].sval));
    variable *v1;
    if(i>=0) {
      if(j>=0) {
	v1 = new variable((*string_table)[i], (*string_table)[j]);
	free((yysemantic_stack_[(7) - (7)].sval));
      } else {
	v1 = new variable((*string_table)[i], (yysemantic_stack_[(7) - (7)].sval));
	string_table->push_back((yysemantic_stack_[(7) - (7)].sval));
      }
      free((yysemantic_stack_[(7) - (5)].sval));
    } else {
      if(j>=0) {
	v1 = new variable((yysemantic_stack_[(7) - (5)].sval), (*string_table)[j]);
	free((yysemantic_stack_[(7) - (7)].sval));
      } else {
	v1 = new variable((yysemantic_stack_[(7) - (5)].sval), (yysemantic_stack_[(7) - (7)].sval));
	string_table->push_back((yysemantic_stack_[(7) - (7)].sval));
      }
      string_table->push_back((yysemantic_stack_[(7) - (5)].sval));
    }
    i = search_variable_table(v1);
    if(i>=0) {
      delete v1;
      v1 = (*variable_table)[i];
    } else {
      variable_table->push_back(v1);
    }

    i = search_logic_expression_table1(v, v1);
    if(i>=0) {
      (yyval._bool_expression) = (*logic_expression_table1)[i];
      free((yysemantic_stack_[(7) - (5)].sval));
    } else {
			logic_expression *e = new logic_expression(0, v, v1);
			bool_expression *bexpr = new bool_expression(0, e);
      (yyval._bool_expression) = bexpr;
      logic_expression_table1->push_back(bexpr);
    }    
  } else
    (yyval._bool_expression) = NULL;
 }
    break;

  case 488:

/* Line 690 of lalr1.cc  */
#line 3149 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(5) - (1)].sval)!=NULL && (yysemantic_stack_[(5) - (3)].sval)!=NULL && (yysemantic_stack_[(5) - (5)]._expression)!=NULL) {
    int i = search_string_table((yysemantic_stack_[(5) - (1)].sval));
    int j = search_string_table((yysemantic_stack_[(5) - (3)].sval));
    variable *v;
    if(i>=0) {
      if(j>=0) {
	v = new variable((*string_table)[i], (*string_table)[j]);
	free((yysemantic_stack_[(5) - (3)].sval));
      } else {
	v = new variable((*string_table)[i], (yysemantic_stack_[(5) - (3)].sval));
	string_table->push_back((yysemantic_stack_[(5) - (3)].sval));
      }
      free((yysemantic_stack_[(5) - (1)].sval));
    } else {
      if(j>=0) {
	v = new variable((yysemantic_stack_[(5) - (1)].sval), (*string_table)[j]);
	free((yysemantic_stack_[(5) - (3)].sval));
      } else {
	v = new variable((yysemantic_stack_[(5) - (1)].sval), (yysemantic_stack_[(5) - (3)].sval));
	string_table->push_back((yysemantic_stack_[(5) - (3)].sval));
      }
      string_table->push_back((yysemantic_stack_[(5) - (1)].sval));
    }
    i = search_variable_table(v);
    if(i>=0) {
      delete v;
      v = (*variable_table)[i];
    } else {
      variable_table->push_back(v);
    }
    i = search_logic_expression_table1(v, (yysemantic_stack_[(5) - (5)]._expression));
    if(i>=0) {
      (yyval._bool_expression) = (*logic_expression_table1)[i];
      free((yysemantic_stack_[(5) - (5)]._expression));
    } else {
			logic_expression *e = new logic_expression(0, v, (yysemantic_stack_[(5) - (5)]._expression));
			bool_expression *bexpr = new bool_expression(0, e);
      (yyval._bool_expression) = bexpr;
      logic_expression_table1->push_back(bexpr);
    }    
  } else
    (yyval._bool_expression) = NULL;
 }
    break;

  case 489:

/* Line 690 of lalr1.cc  */
#line 3193 "parser/nssis_new.yy"
    {
  (yyval._bool_expression) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(5) - (1)].sval));
  USE((yysemantic_stack_[(5) - (3)].sval));
  USE((yysemantic_stack_[(5) - (5)]._expression));
 }
    break;

  case 490:

/* Line 690 of lalr1.cc  */
#line 3200 "parser/nssis_new.yy"
    {
  (yyval._bool_expression) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(5) - (1)].sval));
  USE((yysemantic_stack_[(5) - (3)].sval));
  USE((yysemantic_stack_[(5) - (5)]._expression));
 }
    break;

  case 491:

/* Line 690 of lalr1.cc  */
#line 3207 "parser/nssis_new.yy"
    {
  (yyval._bool_expression) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(5) - (1)].sval));
  USE((yysemantic_stack_[(5) - (3)].sval));
  USE((yysemantic_stack_[(5) - (5)]._expression));
 }
    break;

  case 492:

/* Line 690 of lalr1.cc  */
#line 3214 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(7) - (3)].sval)!=NULL && (yysemantic_stack_[(7) - (7)].sval)!=NULL) {
    int j = search_string_table((yysemantic_stack_[(7) - (3)].sval));
    variable *v;
    if(j>=0) {
      v = new variable((*string_table)[0], (*string_table)[j]);
      free((yysemantic_stack_[(7) - (3)].sval));
    } else {
      v = new variable((*string_table)[0], (yysemantic_stack_[(7) - (3)].sval));
      string_table->push_back((yysemantic_stack_[(7) - (3)].sval));
    }
    int i = search_variable_table(v);
    if(i>=0) {
      delete v;
      v = (*variable_table)[i];
    } else {
      variable_table->push_back(v);
    }

    j = search_string_table((yysemantic_stack_[(7) - (7)].sval));
    variable *v1;
    if(j>=0) {
      v1 = new variable((*string_table)[0], (*string_table)[j]);
      free((yysemantic_stack_[(7) - (7)].sval));
    } else {
      v1 = new variable((*string_table)[0], (yysemantic_stack_[(7) - (7)].sval));
      string_table->push_back((yysemantic_stack_[(7) - (7)].sval));
    }
    i = search_variable_table(v1);
    if(i>=0) {
      delete v1;
      v1 = (*variable_table)[i];
    } else {
      variable_table->push_back(v1);
    }

    i = search_logic_expression_table1(v, v1);
    if(i>=0) {
      (yyval._bool_expression) = (*logic_expression_table1)[i];
    } else {
			logic_expression *e = new logic_expression(0, v, v1);
			bool_expression *bexpr = new bool_expression(0, e);
      (yyval._bool_expression) = bexpr;
      logic_expression_table1->push_back(bexpr);
    }    
  } else
    (yyval._bool_expression) = NULL;
 }
    break;

  case 493:

/* Line 690 of lalr1.cc  */
#line 3262 "parser/nssis_new.yy"
    {	
  if((yysemantic_stack_[(5) - (3)].sval)!=NULL && (yysemantic_stack_[(5) - (5)]._expression)!=NULL) {
    int j = search_string_table((yysemantic_stack_[(5) - (3)].sval));
    variable *v;
    if(j>=0) {
      v = new variable((*string_table)[0], (*string_table)[j]);
      free((yysemantic_stack_[(5) - (3)].sval));
    } else {
      v = new variable((*string_table)[0], (yysemantic_stack_[(5) - (3)].sval));
      string_table->push_back((yysemantic_stack_[(5) - (3)].sval));
    }
    j = search_variable_table(v);
    if(j>=0) {
      delete v;
      v = (*variable_table)[j];
    } else {
      variable_table->push_back(v);
    }
    j = search_logic_expression_table1(v, (yysemantic_stack_[(5) - (5)]._expression));
    if(j>=0) {
      (yyval._bool_expression) = (*logic_expression_table1)[j];
      free((yysemantic_stack_[(5) - (5)]._expression));
    } else {
			logic_expression *e = new logic_expression(0, v, (yysemantic_stack_[(5) - (5)]._expression));
			bool_expression *bexpr = new bool_expression(0, e);
      (yyval._bool_expression) = bexpr;
      logic_expression_table1->push_back(bexpr);
    }    
  } else
    (yyval._bool_expression) = NULL;
 }
    break;

  case 494:

/* Line 690 of lalr1.cc  */
#line 3293 "parser/nssis_new.yy"
    {
  (yyval._bool_expression) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(5) - (3)].sval));
  USE((yysemantic_stack_[(5) - (5)]._expression));
 }
    break;

  case 495:

/* Line 690 of lalr1.cc  */
#line 3299 "parser/nssis_new.yy"
    {
  (yyval._bool_expression) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(5) - (3)].sval));
  USE((yysemantic_stack_[(5) - (5)]._expression));
 }
    break;

  case 496:

/* Line 690 of lalr1.cc  */
#line 3305 "parser/nssis_new.yy"
    {
  (yyval._bool_expression) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(5) - (3)].sval));
  USE((yysemantic_stack_[(5) - (5)]._expression));
 }
    break;

  case 497:

/* Line 690 of lalr1.cc  */
#line 3311 "parser/nssis_new.yy"
    {
  (yyval._bool_expression) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(4) - (2)].sval));
  USE((yysemantic_stack_[(4) - (4)]._expression));
 }
    break;

  case 498:

/* Line 690 of lalr1.cc  */
#line 3317 "parser/nssis_new.yy"
    {
  (yyval._bool_expression) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(5) - (3)].sval));
  USE((yysemantic_stack_[(5) - (5)]._expression));
 }
    break;

  case 499:

/* Line 690 of lalr1.cc  */
#line 3323 "parser/nssis_new.yy"
    {
  (yyval._bool_expression) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(4) - (2)].sval));
  USE((yysemantic_stack_[(4) - (4)]._expression));
 }
    break;

  case 500:

/* Line 690 of lalr1.cc  */
#line 3329 "parser/nssis_new.yy"
    {
  (yyval._bool_expression) = NULL;
  driver.syntax_error = true;
  }
    break;

  case 501:

/* Line 690 of lalr1.cc  */
#line 3336 "parser/nssis_new.yy"
    {
  (yyval.ival) = 1;
 }
    break;

  case 502:

/* Line 690 of lalr1.cc  */
#line 3339 "parser/nssis_new.yy"
    {
  (yyval.ival) = 0;
  driver.syntax_error = true;
 }
    break;

  case 503:

/* Line 690 of lalr1.cc  */
#line 3343 "parser/nssis_new.yy"
    {
  (yyval.ival) = 1;
 }
    break;

  case 504:

/* Line 690 of lalr1.cc  */
#line 3346 "parser/nssis_new.yy"
    {
  (yyval.ival) = 0;
  driver.syntax_error = true;
 }
    break;

  case 505:

/* Line 690 of lalr1.cc  */
#line 3350 "parser/nssis_new.yy"
    {
  (yyval.ival) = 0;
  driver.syntax_error = true;
 }
    break;

  case 506:

/* Line 690 of lalr1.cc  */
#line 3354 "parser/nssis_new.yy"
    {
  (yyval.ival) = 0;
  driver.syntax_error = true;
  }
    break;

  case 509:

/* Line 690 of lalr1.cc  */
#line 3360 "parser/nssis_new.yy"
    {
  driver.syntax_error = true;
  }
    break;

  case 510:

/* Line 690 of lalr1.cc  */
#line 3364 "parser/nssis_new.yy"
    {
  (yyval.ival) = 1;
 }
    break;

  case 511:

/* Line 690 of lalr1.cc  */
#line 3367 "parser/nssis_new.yy"
    {
  (yyval.ival) = 0;
  driver.syntax_error = true;
 }
    break;

  case 512:

/* Line 690 of lalr1.cc  */
#line 3371 "parser/nssis_new.yy"
    {
  (yyval.ival) = 0;
  driver.syntax_error = true;
 }
    break;

  case 513:

/* Line 690 of lalr1.cc  */
#line 3375 "parser/nssis_new.yy"
    {
  (yyval.ival) = 0;
  driver.syntax_error = true;
  }
    break;

  case 514:

/* Line 690 of lalr1.cc  */
#line 3379 "parser/nssis_new.yy"
    {
  (yyval.ival) = 1;
 }
    break;

  case 515:

/* Line 690 of lalr1.cc  */
#line 3382 "parser/nssis_new.yy"
    {
  (yyval.ival) = 0;
  driver.syntax_error = true;
 }
    break;

  case 516:

/* Line 690 of lalr1.cc  */
#line 3386 "parser/nssis_new.yy"
    {
  (yyval.ival) = 0;
  driver.syntax_error = true;
 }
    break;

  case 517:

/* Line 690 of lalr1.cc  */
#line 3390 "parser/nssis_new.yy"
    {
  (yyval.ival) = 0;
  driver.syntax_error = true;
  }
    break;

  case 518:

/* Line 690 of lalr1.cc  */
#line 3394 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(4) - (1)].sval)!=NULL && (yysemantic_stack_[(4) - (2)].ival)==1 && (yysemantic_stack_[(4) - (3)].set_string)!=NULL && (yysemantic_stack_[(4) - (4)].ival)==1) {
    (*is_groups)[*(yysemantic_stack_[(4) - (1)].sval)] = *(yysemantic_stack_[(4) - (3)].set_string);
    free((yysemantic_stack_[(4) - (1)].sval));
  }
 }
    break;

  case 519:

/* Line 690 of lalr1.cc  */
#line 3400 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(5) - (2)].sval)!=NULL && (yysemantic_stack_[(5) - (3)].ival)==1 && (yysemantic_stack_[(5) - (4)].set_string)!=NULL && (yysemantic_stack_[(5) - (5)].ival)==1) {
    if(is_groups->find(*(yysemantic_stack_[(5) - (2)].sval)) != is_groups->end() && options["quiet"] == 0)
      cout << "warning: group " << *(yysemantic_stack_[(5) - (2)].sval) << " already exists." << endl; 
    (*is_groups)[*(yysemantic_stack_[(5) - (2)].sval)] = *(yysemantic_stack_[(5) - (4)].set_string);
    free((yysemantic_stack_[(5) - (2)].sval));
  }
 }
    break;

  case 520:

/* Line 690 of lalr1.cc  */
#line 3408 "parser/nssis_new.yy"
    {
  driver.syntax_error = true;
  }
    break;

  case 521:

/* Line 690 of lalr1.cc  */
#line 3412 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(1) - (1)].sval)!=NULL) {
    (yyval.set_string) = new set<string>;
    (yyval.set_string)->insert(*(yysemantic_stack_[(1) - (1)].sval));
  } else
    (yyval.set_string) = NULL;
 }
    break;

  case 522:

/* Line 690 of lalr1.cc  */
#line 3419 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(3) - (1)].set_string)!=NULL && (yysemantic_stack_[(3) - (3)].sval)!=NULL) {
    pair<set<string>::iterator, bool> ret = (yysemantic_stack_[(3) - (1)].set_string)->insert(*(yysemantic_stack_[(3) - (3)].sval));
    if(!ret.second && options["quiet"] == 0)
      cout << "warning: agent " << *(yysemantic_stack_[(3) - (3)].sval) << " in group definition is redundant." << endl;
    (yyval.set_string) = (yysemantic_stack_[(3) - (1)].set_string);
  } else
    (yyval.set_string) = NULL;
 }
    break;

  case 523:

/* Line 690 of lalr1.cc  */
#line 3428 "parser/nssis_new.yy"
    {
  (yyval.set_string) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(3) - (1)].set_string));USE((yysemantic_stack_[(3) - (3)].sval));
 }
    break;

  case 524:

/* Line 690 of lalr1.cc  */
#line 3433 "parser/nssis_new.yy"
    {
  (yyval.set_string) = NULL;
  driver.syntax_error = true;
  }
    break;

  case 525:

/* Line 690 of lalr1.cc  */
#line 3437 "parser/nssis_new.yy"
    {
  (yyval.sval) = (*string_table)[0];
 }
    break;

  case 526:

/* Line 690 of lalr1.cc  */
#line 3440 "parser/nssis_new.yy"
    {
    int i = search_string_table((yysemantic_stack_[(1) - (1)].sval));
    if(i>=0) {
      (yyval.sval) = (*string_table)[i];
      free((yysemantic_stack_[(1) - (1)].sval));
    } else {
      (yyval.sval) = (yysemantic_stack_[(1) - (1)].sval);
      string_table->push_back((yysemantic_stack_[(1) - (1)].sval));
    }
  }
    break;

  case 527:

/* Line 690 of lalr1.cc  */
#line 3450 "parser/nssis_new.yy"
    {
  (yyval.sval) = NULL;
  driver.syntax_error = true;
  }
    break;

  case 528:

/* Line 690 of lalr1.cc  */
#line 3457 "parser/nssis_new.yy"
    {
  (yyval.ival) = 1;
 }
    break;

  case 529:

/* Line 690 of lalr1.cc  */
#line 3460 "parser/nssis_new.yy"
    {
  (yyval.ival) = 0;
  driver.syntax_error = true;
 }
    break;

  case 530:

/* Line 690 of lalr1.cc  */
#line 3464 "parser/nssis_new.yy"
    {
  (yyval.ival) = 1;
 }
    break;

  case 531:

/* Line 690 of lalr1.cc  */
#line 3467 "parser/nssis_new.yy"
    {
  (yyval.ival) = 0;
  driver.syntax_error = true;
 }
    break;

  case 532:

/* Line 690 of lalr1.cc  */
#line 3471 "parser/nssis_new.yy"
    {
  (yyval.ival) = 0;
  driver.syntax_error = true;
 }
    break;

  case 533:

/* Line 690 of lalr1.cc  */
#line 3475 "parser/nssis_new.yy"
    {
  (yyval.ival) = 0;
  driver.syntax_error = true;
  }
    break;

  case 536:

/* Line 690 of lalr1.cc  */
#line 3482 "parser/nssis_new.yy"
    { 
  if((yysemantic_stack_[(2) - (1)]._fairness_expression)!=NULL)
    is_fairness->push_back((yysemantic_stack_[(2) - (1)]._fairness_expression));
 }
    break;

  case 537:

/* Line 690 of lalr1.cc  */
#line 3486 "parser/nssis_new.yy"
    {
  driver.syntax_error = true;
  USE((yysemantic_stack_[(2) - (1)]._fairness_expression));
 }
    break;

  case 538:

/* Line 690 of lalr1.cc  */
#line 3490 "parser/nssis_new.yy"
    { 
  if((yysemantic_stack_[(3) - (2)]._fairness_expression)!=NULL)
    is_fairness->push_back((yysemantic_stack_[(3) - (2)]._fairness_expression)); 
 }
    break;

  case 539:

/* Line 690 of lalr1.cc  */
#line 3494 "parser/nssis_new.yy"
    {
  driver.syntax_error = true;
  USE((yysemantic_stack_[(3) - (2)]._fairness_expression));
 }
    break;

  case 540:

/* Line 690 of lalr1.cc  */
#line 3498 "parser/nssis_new.yy"
    {
  driver.syntax_error = true;
  }
    break;

  case 541:

/* Line 690 of lalr1.cc  */
#line 3502 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(5) - (2)]._fairness_expression)!=NULL && (yysemantic_stack_[(5) - (4)]._fairness_expression)!=NULL)
    (yyval.dual_fairness_expression) = new pair<fairness_expression *, fairness_expression *>((yysemantic_stack_[(5) - (2)]._fairness_expression), (yysemantic_stack_[(5) - (4)]._fairness_expression));
  else
    (yyval.dual_fairness_expression) = NULL;
 }
    break;

  case 542:

/* Line 690 of lalr1.cc  */
#line 3508 "parser/nssis_new.yy"
    {
  (yyval.dual_fairness_expression) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(5) - (2)]._fairness_expression));USE((yysemantic_stack_[(5) - (4)]._fairness_expression));
 }
    break;

  case 543:

/* Line 690 of lalr1.cc  */
#line 3513 "parser/nssis_new.yy"
    {
  (yyval.dual_fairness_expression) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(5) - (2)]._fairness_expression));USE((yysemantic_stack_[(5) - (4)]._fairness_expression));
 }
    break;

  case 544:

/* Line 690 of lalr1.cc  */
#line 3518 "parser/nssis_new.yy"
    {
  (yyval.dual_fairness_expression) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(5) - (2)]._fairness_expression));USE((yysemantic_stack_[(5) - (4)]._fairness_expression));
 }
    break;

  case 545:

/* Line 690 of lalr1.cc  */
#line 3523 "parser/nssis_new.yy"
    {
  (yyval.dual_fairness_expression) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(5) - (2)]._fairness_expression));USE((yysemantic_stack_[(5) - (4)]._fairness_expression));
 }
    break;

  case 546:

/* Line 690 of lalr1.cc  */
#line 3528 "parser/nssis_new.yy"
    {
  (yyval.dual_fairness_expression) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(5) - (2)]._fairness_expression));USE((yysemantic_stack_[(5) - (4)]._fairness_expression));
 }
    break;

  case 547:

/* Line 690 of lalr1.cc  */
#line 3533 "parser/nssis_new.yy"
    {
  (yyval.dual_fairness_expression) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(5) - (2)]._fairness_expression));USE((yysemantic_stack_[(5) - (4)]._fairness_expression));
 }
    break;

  case 548:

/* Line 690 of lalr1.cc  */
#line 3538 "parser/nssis_new.yy"
    {
  (yyval.dual_fairness_expression) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(5) - (2)]._fairness_expression));USE((yysemantic_stack_[(5) - (4)]._fairness_expression));
 }
    break;

  case 549:

/* Line 690 of lalr1.cc  */
#line 3543 "parser/nssis_new.yy"
    {
    if((yysemantic_stack_[(5) - (2)].sval)!=NULL && (yysemantic_stack_[(5) - (4)]._fairness_expression)!=NULL) {
      int i = search_string_table((yysemantic_stack_[(5) - (2)].sval));
      if(i>=0) {
	(yyval.ID_fairness_expression) = new pair<string *, fairness_expression *>((*string_table)[i], (yysemantic_stack_[(5) - (4)]._fairness_expression));
	free((yysemantic_stack_[(5) - (2)].sval));
      } else {
	(yyval.ID_fairness_expression) = new pair<string *, fairness_expression *>((yysemantic_stack_[(5) - (2)].sval), (yysemantic_stack_[(5) - (4)]._fairness_expression));
	string_table->push_back((yysemantic_stack_[(5) - (2)].sval));
      }
    } else
      (yyval.ID_fairness_expression) = NULL;
 }
    break;

  case 550:

/* Line 690 of lalr1.cc  */
#line 3556 "parser/nssis_new.yy"
    {
  (yyval.ID_fairness_expression) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(5) - (2)].sval));
  USE((yysemantic_stack_[(5) - (4)]._fairness_expression));
 }
    break;

  case 551:

/* Line 690 of lalr1.cc  */
#line 3562 "parser/nssis_new.yy"
    {
  (yyval.ID_fairness_expression) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(5) - (2)].sval));
  USE((yysemantic_stack_[(5) - (4)]._fairness_expression));
 }
    break;

  case 552:

/* Line 690 of lalr1.cc  */
#line 3568 "parser/nssis_new.yy"
    {
  (yyval.ID_fairness_expression) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(5) - (2)].sval));
  USE((yysemantic_stack_[(5) - (4)]._fairness_expression));
 }
    break;

  case 553:

/* Line 690 of lalr1.cc  */
#line 3574 "parser/nssis_new.yy"
    {
  (yyval.ID_fairness_expression) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(5) - (2)].sval));
  USE((yysemantic_stack_[(5) - (4)]._fairness_expression));
 }
    break;

  case 554:

/* Line 690 of lalr1.cc  */
#line 3580 "parser/nssis_new.yy"
    {
  (yyval.ID_fairness_expression) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(5) - (2)].sval));
  USE((yysemantic_stack_[(5) - (4)]._fairness_expression));
 }
    break;

  case 555:

/* Line 690 of lalr1.cc  */
#line 3586 "parser/nssis_new.yy"
    {
  (yyval.ID_fairness_expression) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(5) - (2)].sval));
  USE((yysemantic_stack_[(5) - (4)]._fairness_expression));
 }
    break;

  case 556:

/* Line 690 of lalr1.cc  */
#line 3592 "parser/nssis_new.yy"
    {
  (yyval.ID_fairness_expression) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(5) - (2)].sval));
  USE((yysemantic_stack_[(5) - (4)]._fairness_expression));
 }
    break;

  case 557:

/* Line 690 of lalr1.cc  */
#line 3598 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(5) - (4)]._fairness_expression)!=NULL)
    (yyval.ID_fairness_expression) = new pair<string *, fairness_expression *>((*string_table)[0], (yysemantic_stack_[(5) - (4)]._fairness_expression));
  else
    (yyval.ID_fairness_expression) = NULL;
 }
    break;

  case 558:

/* Line 690 of lalr1.cc  */
#line 3604 "parser/nssis_new.yy"
    {
  (yyval.ID_fairness_expression) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(5) - (4)]._fairness_expression));
 }
    break;

  case 559:

/* Line 690 of lalr1.cc  */
#line 3609 "parser/nssis_new.yy"
    {
  (yyval.ID_fairness_expression) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(5) - (4)]._fairness_expression));
 }
    break;

  case 560:

/* Line 690 of lalr1.cc  */
#line 3614 "parser/nssis_new.yy"
    {
  (yyval.ID_fairness_expression) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(5) - (4)]._fairness_expression));
 }
    break;

  case 561:

/* Line 690 of lalr1.cc  */
#line 3619 "parser/nssis_new.yy"
    {
  (yyval.ID_fairness_expression) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(5) - (4)]._fairness_expression));
 }
    break;

  case 562:

/* Line 690 of lalr1.cc  */
#line 3624 "parser/nssis_new.yy"
    {
  (yyval.ID_fairness_expression) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(5) - (4)]._fairness_expression));
 }
    break;

  case 563:

/* Line 690 of lalr1.cc  */
#line 3629 "parser/nssis_new.yy"
    {
  (yyval.ID_fairness_expression) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(5) - (4)]._fairness_expression));
 }
    break;

  case 564:

/* Line 690 of lalr1.cc  */
#line 3634 "parser/nssis_new.yy"
    {
  (yyval.ID_fairness_expression) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(5) - (4)]._fairness_expression));
 }
    break;

  case 565:

/* Line 690 of lalr1.cc  */
#line 3639 "parser/nssis_new.yy"
    {
    if((yysemantic_stack_[(5) - (2)].sval)!=NULL && (yysemantic_stack_[(5) - (4)]._fairness_expression)!=NULL) {
      int i = search_string_table((yysemantic_stack_[(5) - (2)].sval));
      if(i>=0) {
	(yyval.ID_fairness_expression) = new pair<string *, fairness_expression *>((*string_table)[i], (yysemantic_stack_[(5) - (4)]._fairness_expression));
	free((yysemantic_stack_[(5) - (2)].sval));
      } else {
	(yyval.ID_fairness_expression) = new pair<string *, fairness_expression *>((yysemantic_stack_[(5) - (2)].sval), (yysemantic_stack_[(5) - (4)]._fairness_expression));
	string_table->push_back((yysemantic_stack_[(5) - (2)].sval));
      }
    } else
      (yyval.ID_fairness_expression) = NULL;
 }
    break;

  case 566:

/* Line 690 of lalr1.cc  */
#line 3652 "parser/nssis_new.yy"
    {
  (yyval.ID_fairness_expression) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(5) - (2)].sval));
  USE((yysemantic_stack_[(5) - (4)]._fairness_expression));
 }
    break;

  case 567:

/* Line 690 of lalr1.cc  */
#line 3658 "parser/nssis_new.yy"
    {
  (yyval.ID_fairness_expression) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(5) - (2)].sval));
  USE((yysemantic_stack_[(5) - (4)]._fairness_expression));
 }
    break;

  case 568:

/* Line 690 of lalr1.cc  */
#line 3664 "parser/nssis_new.yy"
    {
  (yyval.ID_fairness_expression) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(5) - (2)].sval));
  USE((yysemantic_stack_[(5) - (4)]._fairness_expression));
 }
    break;

  case 569:

/* Line 690 of lalr1.cc  */
#line 3670 "parser/nssis_new.yy"
    {
  (yyval.ID_fairness_expression) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(5) - (2)].sval));
  USE((yysemantic_stack_[(5) - (4)]._fairness_expression));
 }
    break;

  case 570:

/* Line 690 of lalr1.cc  */
#line 3676 "parser/nssis_new.yy"
    {
  (yyval.ID_fairness_expression) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(5) - (2)].sval));
  USE((yysemantic_stack_[(5) - (4)]._fairness_expression));
 }
    break;

  case 571:

/* Line 690 of lalr1.cc  */
#line 3682 "parser/nssis_new.yy"
    {
  (yyval.ID_fairness_expression) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(5) - (2)].sval));
  USE((yysemantic_stack_[(5) - (4)]._fairness_expression));
 }
    break;

  case 572:

/* Line 690 of lalr1.cc  */
#line 3688 "parser/nssis_new.yy"
    {
  (yyval.ID_fairness_expression) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(5) - (2)].sval));
  USE((yysemantic_stack_[(5) - (4)]._fairness_expression));
 }
    break;

  case 573:

/* Line 690 of lalr1.cc  */
#line 3695 "parser/nssis_new.yy"
    { 
  (yyval._fairness_expression) = (yysemantic_stack_[(3) - (2)]._fairness_expression); 
 }
    break;

  case 574:

/* Line 690 of lalr1.cc  */
#line 3698 "parser/nssis_new.yy"
    { 
  (yyval._fairness_expression) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(3) - (2)]._fairness_expression));
 }
    break;

  case 575:

/* Line 690 of lalr1.cc  */
#line 3703 "parser/nssis_new.yy"
    { 
  (yyval._fairness_expression) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(3) - (2)]._fairness_expression));
 }
    break;

  case 576:

/* Line 690 of lalr1.cc  */
#line 3708 "parser/nssis_new.yy"
    { 
  (yyval._fairness_expression) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(3) - (2)]._fairness_expression));
 }
    break;

  case 577:

/* Line 690 of lalr1.cc  */
#line 3713 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(3) - (1)]._fairness_expression)!=NULL && (yysemantic_stack_[(3) - (3)]._fairness_expression)!=NULL)
    (yyval._fairness_expression) = new fairness_expression(1, (yysemantic_stack_[(3) - (1)]._fairness_expression), (yysemantic_stack_[(3) - (3)]._fairness_expression));
  else
    (yyval._fairness_expression) = NULL;
 }
    break;

  case 578:

/* Line 690 of lalr1.cc  */
#line 3719 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(3) - (1)]._fairness_expression)!=NULL && (yysemantic_stack_[(3) - (3)]._fairness_expression)!=NULL)
    (yyval._fairness_expression) = new fairness_expression(2, (yysemantic_stack_[(3) - (1)]._fairness_expression), (yysemantic_stack_[(3) - (3)]._fairness_expression));
  else
    (yyval._fairness_expression) = NULL;
 }
    break;

  case 579:

/* Line 690 of lalr1.cc  */
#line 3725 "parser/nssis_new.yy"
    {
  (yyval._fairness_expression) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(3) - (1)]._fairness_expression));USE((yysemantic_stack_[(3) - (3)]._fairness_expression));
 }
    break;

  case 580:

/* Line 690 of lalr1.cc  */
#line 3730 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(2) - (2)]._fairness_expression)!=NULL)
    (yyval._fairness_expression) = new fairness_expression(3, (yysemantic_stack_[(2) - (2)]._fairness_expression));
  else
    (yyval._fairness_expression) = NULL;
 }
    break;

  case 581:

/* Line 690 of lalr1.cc  */
#line 3736 "parser/nssis_new.yy"
    {
  (yyval._fairness_expression) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(2) - (2)]._fairness_expression));
 }
    break;

  case 582:

/* Line 690 of lalr1.cc  */
#line 3741 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(3) - (1)]._fairness_expression)!=NULL && (yysemantic_stack_[(3) - (3)]._fairness_expression)!=NULL)
    (yyval._fairness_expression) = new fairness_expression(4, (yysemantic_stack_[(3) - (1)]._fairness_expression), (yysemantic_stack_[(3) - (3)]._fairness_expression));
  else
    (yyval._fairness_expression) = NULL;
 }
    break;

  case 583:

/* Line 690 of lalr1.cc  */
#line 3747 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(2) - (2)]._fairness_expression)!=NULL)
    (yyval._fairness_expression) = new fairness_expression(10, (yysemantic_stack_[(2) - (2)]._fairness_expression));
  else
    (yyval._fairness_expression) = NULL;
 }
    break;

  case 584:

/* Line 690 of lalr1.cc  */
#line 3753 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(2) - (2)]._fairness_expression)!=NULL)
    (yyval._fairness_expression) = new fairness_expression(11, (yysemantic_stack_[(2) - (2)]._fairness_expression));
  else
    (yyval._fairness_expression) = NULL;
  }
    break;

  case 585:

/* Line 690 of lalr1.cc  */
#line 3759 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(2) - (2)]._fairness_expression)!=NULL)
    (yyval._fairness_expression) = new fairness_expression(12, (yysemantic_stack_[(2) - (2)]._fairness_expression));
  else
    (yyval._fairness_expression) = NULL;
 }
    break;

  case 586:

/* Line 690 of lalr1.cc  */
#line 3765 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(2) - (2)]._fairness_expression)!=NULL)
    (yyval._fairness_expression) = new fairness_expression(13, (yysemantic_stack_[(2) - (2)]._fairness_expression));
  else
    (yyval._fairness_expression) = NULL;
 }
    break;

  case 587:

/* Line 690 of lalr1.cc  */
#line 3771 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(2) - (2)]._fairness_expression)!=NULL)
    (yyval._fairness_expression) = new fairness_expression(14, (yysemantic_stack_[(2) - (2)]._fairness_expression));
  else
    (yyval._fairness_expression) = NULL;
 }
    break;

  case 588:

/* Line 690 of lalr1.cc  */
#line 3777 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(2) - (2)]._fairness_expression)!=NULL)
    (yyval._fairness_expression) = new fairness_expression(15, (yysemantic_stack_[(2) - (2)]._fairness_expression));
  else
    (yyval._fairness_expression) = NULL;
 }
    break;

  case 589:

/* Line 690 of lalr1.cc  */
#line 3783 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(2) - (2)].dual_fairness_expression)!=NULL) {
    (yyval._fairness_expression) = new fairness_expression(16, (yysemantic_stack_[(2) - (2)].dual_fairness_expression)->first, (yysemantic_stack_[(2) - (2)].dual_fairness_expression)->second);
    free((yysemantic_stack_[(2) - (2)].dual_fairness_expression));
  }
  else
    (yyval._fairness_expression) = NULL;
 }
    break;

  case 590:

/* Line 690 of lalr1.cc  */
#line 3791 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(2) - (2)].dual_fairness_expression)!=NULL) {
    (yyval._fairness_expression) = new fairness_expression(17, (yysemantic_stack_[(2) - (2)].dual_fairness_expression)->first, (yysemantic_stack_[(2) - (2)].dual_fairness_expression)->second);
    free((yysemantic_stack_[(2) - (2)].dual_fairness_expression));
  }
  else
    (yyval._fairness_expression) = NULL;
 }
    break;

  case 591:

/* Line 690 of lalr1.cc  */
#line 3799 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(2) - (2)].ID_fairness_expression)!=NULL) {
    atomic_proposition *ap = new atomic_proposition((yysemantic_stack_[(2) - (2)].ID_fairness_expression)->first);
    fairness_expression *a = new fairness_expression(ap);
    (yyval._fairness_expression) = new fairness_expression(30, a, (yysemantic_stack_[(2) - (2)].ID_fairness_expression)->second);
    free((yysemantic_stack_[(2) - (2)].ID_fairness_expression));
  } else
    (yyval._fairness_expression) = NULL;
 }
    break;

  case 592:

/* Line 690 of lalr1.cc  */
#line 3808 "parser/nssis_new.yy"
    {
  // Knowledge in a group (everybody knows)
  if((yysemantic_stack_[(2) - (2)].ID_fairness_expression)!=NULL) {
    atomic_proposition *ap = new atomic_proposition((yysemantic_stack_[(2) - (2)].ID_fairness_expression)->first);
    fairness_expression *a = new fairness_expression(ap);
    (yyval._fairness_expression) = new fairness_expression(31, a, (yysemantic_stack_[(2) - (2)].ID_fairness_expression)->second);
    free((yysemantic_stack_[(2) - (2)].ID_fairness_expression));
  } else
    (yyval._fairness_expression) = NULL;
 }
    break;

  case 593:

/* Line 690 of lalr1.cc  */
#line 3818 "parser/nssis_new.yy"
    {
  // Common knowledge in a group
  if((yysemantic_stack_[(2) - (2)].ID_fairness_expression)!=NULL) {
    atomic_proposition *ap = new atomic_proposition((yysemantic_stack_[(2) - (2)].ID_fairness_expression)->first);
    fairness_expression *a = new fairness_expression(ap);
    (yyval._fairness_expression) = new fairness_expression(32, a, (yysemantic_stack_[(2) - (2)].ID_fairness_expression)->second);
    free((yysemantic_stack_[(2) - (2)].ID_fairness_expression));
  } else
    (yyval._fairness_expression) = NULL;
 }
    break;

  case 594:

/* Line 690 of lalr1.cc  */
#line 3828 "parser/nssis_new.yy"
    {
  // deontic operator
  if((yysemantic_stack_[(2) - (2)].ID_fairness_expression)!=NULL) {
    atomic_proposition *ap = new atomic_proposition((yysemantic_stack_[(2) - (2)].ID_fairness_expression)->first);
    fairness_expression *a = new fairness_expression(ap);
    (yyval._fairness_expression) = new fairness_expression(40, a, (yysemantic_stack_[(2) - (2)].ID_fairness_expression)->second);
    free((yysemantic_stack_[(2) - (2)].ID_fairness_expression));
  } else
    (yyval._fairness_expression) = NULL;
 }
    break;

  case 595:

/* Line 690 of lalr1.cc  */
#line 3838 "parser/nssis_new.yy"
    {
  // Distributed knowledge in a group
  if((yysemantic_stack_[(2) - (2)].ID_fairness_expression)!=NULL) {
    atomic_proposition *ap = new atomic_proposition((yysemantic_stack_[(2) - (2)].ID_fairness_expression)->first);
    fairness_expression *a = new fairness_expression(ap);
    (yyval._fairness_expression) = new fairness_expression(42, a, (yysemantic_stack_[(2) - (2)].ID_fairness_expression)->second);
    free((yysemantic_stack_[(2) - (2)].ID_fairness_expression));
  } else
    (yyval._fairness_expression) = NULL;
 }
    break;

  case 596:

/* Line 690 of lalr1.cc  */
#line 3848 "parser/nssis_new.yy"
    { 
  (yyval._fairness_expression) = NULL;
  if((yysemantic_stack_[(2) - (2)].ID_fairness_expression) != NULL)
    free((yysemantic_stack_[(2) - (2)].ID_fairness_expression));
  driver.syntax_error = true;
 }
    break;

  case 597:

/* Line 690 of lalr1.cc  */
#line 3854 "parser/nssis_new.yy"
    { 
  (yyval._fairness_expression) = NULL;
  if((yysemantic_stack_[(2) - (2)].ID_fairness_expression) != NULL)
    free((yysemantic_stack_[(2) - (2)].ID_fairness_expression));
  driver.syntax_error = true;
 }
    break;

  case 598:

/* Line 690 of lalr1.cc  */
#line 3860 "parser/nssis_new.yy"
    {	
  if((yysemantic_stack_[(1) - (1)].sval)!=NULL) {
    int i = search_string_table((yysemantic_stack_[(1) - (1)].sval));
    atomic_proposition *ap;
    if(i>=0) {
      ap = new atomic_proposition((*string_table)[i]);
      free((yysemantic_stack_[(1) - (1)].sval));
    } else {
      ap = new atomic_proposition((yysemantic_stack_[(1) - (1)].sval));
      string_table->push_back((yysemantic_stack_[(1) - (1)].sval));
    }
    (yyval._fairness_expression) = new fairness_expression(ap);
  } else
    (yyval._fairness_expression) = NULL;
  }
    break;

  case 599:

/* Line 690 of lalr1.cc  */
#line 3875 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(3) - (1)].sval)!=NULL) {
    string *newname = new string(*(yysemantic_stack_[(3) - (1)].sval) + ".GreenStates");
    atomic_proposition *ap;
    int i = search_string_table(newname);
    if(i>=0) {
      ap = new atomic_proposition((*string_table)[i]);
      free(newname);
    } else {
      ap = new atomic_proposition(newname);
      string_table->push_back(newname);
    }
    free((yysemantic_stack_[(3) - (1)].sval));
    (yyval._fairness_expression) = new fairness_expression(ap);
  } else
    (yyval._fairness_expression) = NULL;
 }
    break;

  case 600:

/* Line 690 of lalr1.cc  */
#line 3892 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(3) - (1)].sval)!=NULL) {
    string *newname = new string(*(yysemantic_stack_[(3) - (1)].sval) + ".RedStates");
    atomic_proposition *ap;
    int i = search_string_table(newname);
    if(i>=0) {
      ap = new atomic_proposition((*string_table)[i]);
      free(newname);
    } else {
      ap = new atomic_proposition(newname);
      string_table->push_back(newname);
    }
    free((yysemantic_stack_[(3) - (1)].sval));
    (yyval._fairness_expression) = new fairness_expression(ap);
  } else
    (yyval._fairness_expression) = NULL;
 }
    break;

  case 601:

/* Line 690 of lalr1.cc  */
#line 3909 "parser/nssis_new.yy"
    {
    string *newname = new string("Environment.GreenStates");
    atomic_proposition *ap;
    int i = search_string_table(newname);
    if(i>=0) {
      ap = new atomic_proposition((*string_table)[i]);
      free(newname);
    } else {
      ap = new atomic_proposition(newname);
      string_table->push_back(newname);
    }
    (yyval._fairness_expression) = new fairness_expression(ap);
 }
    break;

  case 602:

/* Line 690 of lalr1.cc  */
#line 3922 "parser/nssis_new.yy"
    {
  string *newname = new string("Environment.RedStates");
  atomic_proposition *ap;
  int i = search_string_table(newname);
  if(i>=0) {
    ap = new atomic_proposition((*string_table)[i]);
    free(newname);
  } else {
    ap = new atomic_proposition(newname);
    string_table->push_back(newname);
  }
  (yyval._fairness_expression) = new fairness_expression(ap);
 }
    break;

  case 603:

/* Line 690 of lalr1.cc  */
#line 3935 "parser/nssis_new.yy"
    {
  (yyval._fairness_expression) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(3) - (1)].sval));
 }
    break;

  case 604:

/* Line 690 of lalr1.cc  */
#line 3940 "parser/nssis_new.yy"
    {
  (yyval._fairness_expression) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(3) - (1)].sval));
 }
    break;

  case 605:

/* Line 690 of lalr1.cc  */
#line 3945 "parser/nssis_new.yy"
    {
  (yyval._fairness_expression) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(3) - (1)].sval));
 }
    break;

  case 606:

/* Line 690 of lalr1.cc  */
#line 3950 "parser/nssis_new.yy"
    {
  (yyval._fairness_expression) = NULL;
  driver.syntax_error = true;
  }
    break;

  case 607:

/* Line 690 of lalr1.cc  */
#line 3957 "parser/nssis_new.yy"
    {
  (yyval.ival) = 1;
 }
    break;

  case 608:

/* Line 690 of lalr1.cc  */
#line 3960 "parser/nssis_new.yy"
    {
  (yyval.ival) = 0;
  driver.syntax_error = true;
 }
    break;

  case 609:

/* Line 690 of lalr1.cc  */
#line 3965 "parser/nssis_new.yy"
    {
  (yyval.ival) = 1;
 }
    break;

  case 610:

/* Line 690 of lalr1.cc  */
#line 3968 "parser/nssis_new.yy"
    {
  (yyval.ival) = 0;
  driver.syntax_error = true;
 }
    break;

  case 611:

/* Line 690 of lalr1.cc  */
#line 3972 "parser/nssis_new.yy"
    {
  (yyval.ival) = 0;
  driver.syntax_error = true;
 }
    break;

  case 612:

/* Line 690 of lalr1.cc  */
#line 3976 "parser/nssis_new.yy"
    {
  (yyval.ival) = 0;
  driver.syntax_error = true;
  }
    break;

  case 614:

/* Line 690 of lalr1.cc  */
#line 3982 "parser/nssis_new.yy"
    { 
  if((yysemantic_stack_[(2) - (1)]._modal_formula)!=NULL) {
    is_formulae->push_back(*(yysemantic_stack_[(2) - (1)]._modal_formula));
  }
 }
    break;

  case 615:

/* Line 690 of lalr1.cc  */
#line 3987 "parser/nssis_new.yy"
    {
  driver.syntax_error = true;
  USE((yysemantic_stack_[(2) - (1)]._modal_formula));
 }
    break;

  case 616:

/* Line 690 of lalr1.cc  */
#line 3991 "parser/nssis_new.yy"
    { 
  if((yysemantic_stack_[(3) - (2)]._modal_formula)!=NULL) {
    is_formulae->push_back(*(yysemantic_stack_[(3) - (2)]._modal_formula)); 
  }
 }
    break;

  case 617:

/* Line 690 of lalr1.cc  */
#line 3996 "parser/nssis_new.yy"
    {
  driver.syntax_error = true;
  USE((yysemantic_stack_[(3) - (2)]._modal_formula));
 }
    break;

  case 618:

/* Line 690 of lalr1.cc  */
#line 4000 "parser/nssis_new.yy"
    {
  driver.syntax_error = true;
 }
    break;

  case 619:

/* Line 690 of lalr1.cc  */
#line 4004 "parser/nssis_new.yy"
    {
  int i = search_string_table((yysemantic_stack_[(3) - (2)].sval));
  if(i>=0) {
    (yyval.sval) = (*string_table)[i];
    free((yysemantic_stack_[(3) - (2)].sval));
  } else {
     (yyval.sval) = (yysemantic_stack_[(3) - (2)].sval);
     string_table->push_back((yysemantic_stack_[(3) - (2)].sval));
  }
 }
    break;

  case 620:

/* Line 690 of lalr1.cc  */
#line 4014 "parser/nssis_new.yy"
    {
  (yyval.sval) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(3) - (2)].sval));
 }
    break;

  case 621:

/* Line 690 of lalr1.cc  */
#line 4019 "parser/nssis_new.yy"
    {
  (yyval.sval) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(3) - (2)].sval));
 }
    break;

  case 622:

/* Line 690 of lalr1.cc  */
#line 4024 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(5) - (2)]._modal_formula)!=NULL && (yysemantic_stack_[(5) - (4)]._modal_formula)!=NULL)
    (yyval.dual_modal_formula) = new pair<modal_formula *, modal_formula *>((yysemantic_stack_[(5) - (2)]._modal_formula), (yysemantic_stack_[(5) - (4)]._modal_formula));
  else
    (yyval.dual_modal_formula) = NULL;
 }
    break;

  case 623:

/* Line 690 of lalr1.cc  */
#line 4030 "parser/nssis_new.yy"
    {
  (yyval.dual_modal_formula) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(5) - (2)]._modal_formula));USE((yysemantic_stack_[(5) - (4)]._modal_formula));
 }
    break;

  case 624:

/* Line 690 of lalr1.cc  */
#line 4035 "parser/nssis_new.yy"
    {
  (yyval.dual_modal_formula) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(5) - (2)]._modal_formula));USE((yysemantic_stack_[(5) - (4)]._modal_formula));
 }
    break;

  case 625:

/* Line 690 of lalr1.cc  */
#line 4040 "parser/nssis_new.yy"
    {
  (yyval.dual_modal_formula) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(5) - (2)]._modal_formula));USE((yysemantic_stack_[(5) - (4)]._modal_formula));
 }
    break;

  case 626:

/* Line 690 of lalr1.cc  */
#line 4045 "parser/nssis_new.yy"
    {
  (yyval.dual_modal_formula) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(5) - (2)]._modal_formula));USE((yysemantic_stack_[(5) - (4)]._modal_formula));
 }
    break;

  case 627:

/* Line 690 of lalr1.cc  */
#line 4050 "parser/nssis_new.yy"
    {
  (yyval.dual_modal_formula) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(5) - (2)]._modal_formula));USE((yysemantic_stack_[(5) - (4)]._modal_formula));
 }
    break;

  case 628:

/* Line 690 of lalr1.cc  */
#line 4055 "parser/nssis_new.yy"
    {
  (yyval.dual_modal_formula) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(5) - (2)]._modal_formula));USE((yysemantic_stack_[(5) - (4)]._modal_formula));
 }
    break;

  case 629:

/* Line 690 of lalr1.cc  */
#line 4060 "parser/nssis_new.yy"
    {
  (yyval.dual_modal_formula) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(5) - (2)]._modal_formula));USE((yysemantic_stack_[(5) - (4)]._modal_formula));
 }
    break;

  case 630:

/* Line 690 of lalr1.cc  */
#line 4065 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(5) - (2)]._modal_formula)!=NULL && (yysemantic_stack_[(5) - (4)]._modal_formula)!=NULL)
    (yyval.dual_modal_formula) = new pair<modal_formula *, modal_formula *>((yysemantic_stack_[(5) - (2)]._modal_formula), (yysemantic_stack_[(5) - (4)]._modal_formula));
  else
    (yyval.dual_modal_formula) = NULL;
 }
    break;

  case 631:

/* Line 690 of lalr1.cc  */
#line 4071 "parser/nssis_new.yy"
    {
  (yyval.dual_modal_formula) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(5) - (2)]._modal_formula));USE((yysemantic_stack_[(5) - (4)]._modal_formula));
 }
    break;

  case 632:

/* Line 690 of lalr1.cc  */
#line 4076 "parser/nssis_new.yy"
    {
  (yyval.dual_modal_formula) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(5) - (2)]._modal_formula));USE((yysemantic_stack_[(5) - (4)]._modal_formula));
 }
    break;

  case 633:

/* Line 690 of lalr1.cc  */
#line 4081 "parser/nssis_new.yy"
    {
  (yyval.dual_modal_formula) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(5) - (2)]._modal_formula));USE((yysemantic_stack_[(5) - (4)]._modal_formula));
 }
    break;

  case 634:

/* Line 690 of lalr1.cc  */
#line 4086 "parser/nssis_new.yy"
    {
  (yyval.dual_modal_formula) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(5) - (2)]._modal_formula));USE((yysemantic_stack_[(5) - (4)]._modal_formula));
 }
    break;

  case 635:

/* Line 690 of lalr1.cc  */
#line 4091 "parser/nssis_new.yy"
    {
  (yyval.dual_modal_formula) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(5) - (2)]._modal_formula));USE((yysemantic_stack_[(5) - (4)]._modal_formula));
 }
    break;

  case 636:

/* Line 690 of lalr1.cc  */
#line 4096 "parser/nssis_new.yy"
    {
  (yyval.dual_modal_formula) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(5) - (2)]._modal_formula));USE((yysemantic_stack_[(5) - (4)]._modal_formula));
 }
    break;

  case 637:

/* Line 690 of lalr1.cc  */
#line 4101 "parser/nssis_new.yy"
    {
  (yyval.dual_modal_formula) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(5) - (2)]._modal_formula));USE((yysemantic_stack_[(5) - (4)]._modal_formula));
 }
    break;

  case 638:

/* Line 690 of lalr1.cc  */
#line 4106 "parser/nssis_new.yy"
    {
    if((yysemantic_stack_[(5) - (2)].sval)!=NULL && (yysemantic_stack_[(5) - (4)]._modal_formula)!=NULL) {
      int i = search_string_table((yysemantic_stack_[(5) - (2)].sval));
      if(i>=0) {
	(yyval.ID_modal_formula) = new pair<string *, modal_formula *>((*string_table)[i], (yysemantic_stack_[(5) - (4)]._modal_formula));
	free((yysemantic_stack_[(5) - (2)].sval));
      } else {
	(yyval.ID_modal_formula) = new pair<string *, modal_formula *>((yysemantic_stack_[(5) - (2)].sval), (yysemantic_stack_[(5) - (4)]._modal_formula));
	string_table->push_back((yysemantic_stack_[(5) - (2)].sval));
      }
    } else
    (yyval.ID_modal_formula) = NULL;
 }
    break;

  case 639:

/* Line 690 of lalr1.cc  */
#line 4119 "parser/nssis_new.yy"
    {
  (yyval.ID_modal_formula) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(5) - (2)].sval));
  USE((yysemantic_stack_[(5) - (4)]._modal_formula));
 }
    break;

  case 640:

/* Line 690 of lalr1.cc  */
#line 4125 "parser/nssis_new.yy"
    {
  (yyval.ID_modal_formula) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(5) - (2)].sval));
  USE((yysemantic_stack_[(5) - (4)]._modal_formula));
 }
    break;

  case 641:

/* Line 690 of lalr1.cc  */
#line 4131 "parser/nssis_new.yy"
    {
  (yyval.ID_modal_formula) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(5) - (2)].sval));
  USE((yysemantic_stack_[(5) - (4)]._modal_formula));
 }
    break;

  case 642:

/* Line 690 of lalr1.cc  */
#line 4137 "parser/nssis_new.yy"
    {
  (yyval.ID_modal_formula) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(5) - (2)].sval));
  USE((yysemantic_stack_[(5) - (4)]._modal_formula));
 }
    break;

  case 643:

/* Line 690 of lalr1.cc  */
#line 4143 "parser/nssis_new.yy"
    {
  (yyval.ID_modal_formula) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(5) - (2)].sval));
  USE((yysemantic_stack_[(5) - (4)]._modal_formula));
 }
    break;

  case 644:

/* Line 690 of lalr1.cc  */
#line 4149 "parser/nssis_new.yy"
    {
  (yyval.ID_modal_formula) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(5) - (2)].sval));
  USE((yysemantic_stack_[(5) - (4)]._modal_formula));
 }
    break;

  case 645:

/* Line 690 of lalr1.cc  */
#line 4155 "parser/nssis_new.yy"
    {
  (yyval.ID_modal_formula) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(5) - (2)].sval));
  USE((yysemantic_stack_[(5) - (4)]._modal_formula));
 }
    break;

  case 646:

/* Line 690 of lalr1.cc  */
#line 4161 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(5) - (4)]._modal_formula)!=NULL)
    (yyval.ID_modal_formula) = new pair<string *, modal_formula *>((*string_table)[0], (yysemantic_stack_[(5) - (4)]._modal_formula));
  else
    (yyval.ID_modal_formula) = NULL;
 }
    break;

  case 647:

/* Line 690 of lalr1.cc  */
#line 4167 "parser/nssis_new.yy"
    {
  (yyval.ID_modal_formula) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(5) - (4)]._modal_formula));
 }
    break;

  case 648:

/* Line 690 of lalr1.cc  */
#line 4172 "parser/nssis_new.yy"
    {
  (yyval.ID_modal_formula) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(5) - (4)]._modal_formula));
 }
    break;

  case 649:

/* Line 690 of lalr1.cc  */
#line 4177 "parser/nssis_new.yy"
    {
  (yyval.ID_modal_formula) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(5) - (4)]._modal_formula));
 }
    break;

  case 650:

/* Line 690 of lalr1.cc  */
#line 4182 "parser/nssis_new.yy"
    {
  (yyval.ID_modal_formula) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(5) - (4)]._modal_formula));
 }
    break;

  case 651:

/* Line 690 of lalr1.cc  */
#line 4187 "parser/nssis_new.yy"
    {
  (yyval.ID_modal_formula) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(5) - (4)]._modal_formula));
 }
    break;

  case 652:

/* Line 690 of lalr1.cc  */
#line 4192 "parser/nssis_new.yy"
    {
  (yyval.ID_modal_formula) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(5) - (4)]._modal_formula));
 }
    break;

  case 653:

/* Line 690 of lalr1.cc  */
#line 4197 "parser/nssis_new.yy"
    {
  (yyval.ID_modal_formula) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(5) - (4)]._modal_formula));
 }
    break;

  case 654:

/* Line 690 of lalr1.cc  */
#line 4202 "parser/nssis_new.yy"
    {
    if((yysemantic_stack_[(5) - (2)].sval)!=NULL && (yysemantic_stack_[(5) - (4)]._modal_formula)!=NULL) {
      int i = search_string_table((yysemantic_stack_[(5) - (2)].sval));
      if(i>=0) {
	(yyval.ID_modal_formula) = new pair<string *, modal_formula *>((*string_table)[i], (yysemantic_stack_[(5) - (4)]._modal_formula));
	free((yysemantic_stack_[(5) - (2)].sval));
      } else {
	(yyval.ID_modal_formula) = new pair<string *, modal_formula *>((yysemantic_stack_[(5) - (2)].sval), (yysemantic_stack_[(5) - (4)]._modal_formula));
	string_table->push_back((yysemantic_stack_[(5) - (2)].sval));
      }
    } else
      (yyval.ID_modal_formula) = NULL;
 }
    break;

  case 655:

/* Line 690 of lalr1.cc  */
#line 4215 "parser/nssis_new.yy"
    {
  (yyval.ID_modal_formula) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(5) - (2)].sval));
  USE((yysemantic_stack_[(5) - (4)]._modal_formula));
 }
    break;

  case 656:

/* Line 690 of lalr1.cc  */
#line 4221 "parser/nssis_new.yy"
    {
  (yyval.ID_modal_formula) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(5) - (2)].sval));
  USE((yysemantic_stack_[(5) - (4)]._modal_formula));
 }
    break;

  case 657:

/* Line 690 of lalr1.cc  */
#line 4227 "parser/nssis_new.yy"
    {
  (yyval.ID_modal_formula) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(5) - (2)].sval));
  USE((yysemantic_stack_[(5) - (4)]._modal_formula));
 }
    break;

  case 658:

/* Line 690 of lalr1.cc  */
#line 4233 "parser/nssis_new.yy"
    {
  (yyval.ID_modal_formula) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(5) - (2)].sval));
  USE((yysemantic_stack_[(5) - (4)]._modal_formula));
 }
    break;

  case 659:

/* Line 690 of lalr1.cc  */
#line 4239 "parser/nssis_new.yy"
    {
  (yyval.ID_modal_formula) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(5) - (2)].sval));
  USE((yysemantic_stack_[(5) - (4)]._modal_formula));
 }
    break;

  case 660:

/* Line 690 of lalr1.cc  */
#line 4245 "parser/nssis_new.yy"
    {
  (yyval.ID_modal_formula) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(5) - (2)].sval));
  USE((yysemantic_stack_[(5) - (4)]._modal_formula));
 }
    break;

  case 661:

/* Line 690 of lalr1.cc  */
#line 4251 "parser/nssis_new.yy"
    {
  (yyval.ID_modal_formula) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(5) - (2)].sval));
  USE((yysemantic_stack_[(5) - (4)]._modal_formula));
 }
    break;

  case 662:

/* Line 690 of lalr1.cc  */
#line 4258 "parser/nssis_new.yy"
    { 
  (yyval._modal_formula) = (yysemantic_stack_[(3) - (2)]._modal_formula); 
 }
    break;

  case 663:

/* Line 690 of lalr1.cc  */
#line 4261 "parser/nssis_new.yy"
    { 
  (yyval._modal_formula) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(3) - (2)]._modal_formula));
 }
    break;

  case 664:

/* Line 690 of lalr1.cc  */
#line 4266 "parser/nssis_new.yy"
    { 
  (yyval._modal_formula) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(3) - (2)]._modal_formula));
 }
    break;

  case 665:

/* Line 690 of lalr1.cc  */
#line 4271 "parser/nssis_new.yy"
    { 
  (yyval._modal_formula) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(3) - (2)]._modal_formula));
 }
    break;

  case 666:

/* Line 690 of lalr1.cc  */
#line 4276 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(3) - (1)]._modal_formula)!=NULL && (yysemantic_stack_[(3) - (3)]._modal_formula)!=NULL)
    (yyval._modal_formula) = new modal_formula(1, (yysemantic_stack_[(3) - (1)]._modal_formula), (yysemantic_stack_[(3) - (3)]._modal_formula));
  else
    (yyval._modal_formula) = NULL;
 }
    break;

  case 667:

/* Line 690 of lalr1.cc  */
#line 4282 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(3) - (1)]._modal_formula)!=NULL && (yysemantic_stack_[(3) - (3)]._modal_formula)!=NULL)
    (yyval._modal_formula) = new modal_formula(2, (yysemantic_stack_[(3) - (1)]._modal_formula), (yysemantic_stack_[(3) - (3)]._modal_formula));
  else
    (yyval._modal_formula) = NULL;
 }
    break;

  case 668:

/* Line 690 of lalr1.cc  */
#line 4288 "parser/nssis_new.yy"
    {
  (yyval._modal_formula) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(3) - (1)]._modal_formula));USE((yysemantic_stack_[(3) - (3)]._modal_formula));
 }
    break;

  case 669:

/* Line 690 of lalr1.cc  */
#line 4293 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(2) - (2)]._modal_formula)!=NULL)
    (yyval._modal_formula) = new modal_formula(3, (yysemantic_stack_[(2) - (2)]._modal_formula));
  else
    (yyval._modal_formula) = NULL;
 }
    break;

  case 670:

/* Line 690 of lalr1.cc  */
#line 4299 "parser/nssis_new.yy"
    {
  (yyval._modal_formula) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(2) - (2)]._modal_formula));
 }
    break;

  case 671:

/* Line 690 of lalr1.cc  */
#line 4304 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(3) - (1)]._modal_formula)!=NULL && (yysemantic_stack_[(3) - (3)]._modal_formula)!=NULL)
    (yyval._modal_formula) = new modal_formula(4, (yysemantic_stack_[(3) - (1)]._modal_formula), (yysemantic_stack_[(3) - (3)]._modal_formula));
  else
    (yyval._modal_formula) = NULL;
 }
    break;

  case 672:

/* Line 690 of lalr1.cc  */
#line 4310 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(2) - (2)]._modal_formula)!=NULL)
    (yyval._modal_formula) = new modal_formula(10, (yysemantic_stack_[(2) - (2)]._modal_formula));
  else
    (yyval._modal_formula) = NULL;
 }
    break;

  case 673:

/* Line 690 of lalr1.cc  */
#line 4316 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(2) - (2)]._modal_formula)!=NULL)
    (yyval._modal_formula) = new modal_formula(11, (yysemantic_stack_[(2) - (2)]._modal_formula));
  else
    (yyval._modal_formula) = NULL;
  }
    break;

  case 674:

/* Line 690 of lalr1.cc  */
#line 4322 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(2) - (2)]._modal_formula)!=NULL)
    (yyval._modal_formula) = new modal_formula(12, (yysemantic_stack_[(2) - (2)]._modal_formula));
  else
    (yyval._modal_formula) = NULL;
 }
    break;

  case 675:

/* Line 690 of lalr1.cc  */
#line 4328 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(2) - (2)]._modal_formula)!=NULL)
    (yyval._modal_formula) = new modal_formula(13, (yysemantic_stack_[(2) - (2)]._modal_formula));
  else
    (yyval._modal_formula) = NULL;
 }
    break;

  case 676:

/* Line 690 of lalr1.cc  */
#line 4334 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(2) - (2)]._modal_formula)!=NULL)
    (yyval._modal_formula) = new modal_formula(14, (yysemantic_stack_[(2) - (2)]._modal_formula));
  else
    (yyval._modal_formula) = NULL;
 }
    break;

  case 677:

/* Line 690 of lalr1.cc  */
#line 4340 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(2) - (2)]._modal_formula)!=NULL)
    (yyval._modal_formula) = new modal_formula(15, (yysemantic_stack_[(2) - (2)]._modal_formula));
  else
    (yyval._modal_formula) = NULL;
 }
    break;

  case 678:

/* Line 690 of lalr1.cc  */
#line 4346 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(2) - (2)].dual_modal_formula)!=NULL) {
    (yyval._modal_formula) = new modal_formula(16, (yysemantic_stack_[(2) - (2)].dual_modal_formula)->first, (yysemantic_stack_[(2) - (2)].dual_modal_formula)->second);
    free((yysemantic_stack_[(2) - (2)].dual_modal_formula));
  }
  else
    (yyval._modal_formula) = NULL;
 }
    break;

  case 679:

/* Line 690 of lalr1.cc  */
#line 4354 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(2) - (2)].dual_modal_formula)!=NULL) {
    (yyval._modal_formula) = new modal_formula(17, (yysemantic_stack_[(2) - (2)].dual_modal_formula)->first, (yysemantic_stack_[(2) - (2)].dual_modal_formula)->second);
    free((yysemantic_stack_[(2) - (2)].dual_modal_formula));
  }
  else
    (yyval._modal_formula) = NULL;
 }
    break;

  case 680:

/* Line 690 of lalr1.cc  */
#line 4362 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(2) - (2)].dual_modal_formula)!=NULL) {
    (yyval._modal_formula) = new modal_formula(18, (yysemantic_stack_[(2) - (2)].dual_modal_formula)->first, (yysemantic_stack_[(2) - (2)].dual_modal_formula)->second);
    free((yysemantic_stack_[(2) - (2)].dual_modal_formula));
  }
  else
    (yyval._modal_formula) = NULL;
 }
    break;

  case 681:

/* Line 690 of lalr1.cc  */
#line 4370 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(2) - (2)].dual_modal_formula)!=NULL) {
    (yyval._modal_formula) = new modal_formula(19, (yysemantic_stack_[(2) - (2)].dual_modal_formula)->first, (yysemantic_stack_[(2) - (2)].dual_modal_formula)->second);
    free((yysemantic_stack_[(2) - (2)].dual_modal_formula));
  }
  else
    (yyval._modal_formula) = NULL;
 }
    break;

  case 682:

/* Line 690 of lalr1.cc  */
#line 4378 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(2) - (2)].ID_modal_formula)!=NULL) {
    atomic_proposition *ap = new atomic_proposition((yysemantic_stack_[(2) - (2)].ID_modal_formula)->first);
    modal_formula *a = new modal_formula(ap);
    (yyval._modal_formula) = new modal_formula(30, a, (yysemantic_stack_[(2) - (2)].ID_modal_formula)->second);
    free((yysemantic_stack_[(2) - (2)].ID_modal_formula));
  } else
    (yyval._modal_formula) = NULL;
 }
    break;

  case 683:

/* Line 690 of lalr1.cc  */
#line 4387 "parser/nssis_new.yy"
    {
  // Knowledge in a group (everybody knows)
  if((yysemantic_stack_[(2) - (2)].ID_modal_formula)!=NULL) {
    atomic_proposition *ap = new atomic_proposition((yysemantic_stack_[(2) - (2)].ID_modal_formula)->first);
    modal_formula *a = new modal_formula(ap);
    (yyval._modal_formula) = new modal_formula(31, a, (yysemantic_stack_[(2) - (2)].ID_modal_formula)->second);
    free((yysemantic_stack_[(2) - (2)].ID_modal_formula));
  } else
    (yyval._modal_formula) = NULL;
 }
    break;

  case 684:

/* Line 690 of lalr1.cc  */
#line 4397 "parser/nssis_new.yy"
    {
  // Common knowledge in a group
  if((yysemantic_stack_[(2) - (2)].ID_modal_formula)!=NULL) {
    atomic_proposition *ap = new atomic_proposition((yysemantic_stack_[(2) - (2)].ID_modal_formula)->first);
    modal_formula *a = new modal_formula(ap);
    (yyval._modal_formula) = new modal_formula(32, a, (yysemantic_stack_[(2) - (2)].ID_modal_formula)->second);
    free((yysemantic_stack_[(2) - (2)].ID_modal_formula));
  } else
    (yyval._modal_formula) = NULL;
 }
    break;

  case 685:

/* Line 690 of lalr1.cc  */
#line 4407 "parser/nssis_new.yy"
    {
  // deontic operator
  if((yysemantic_stack_[(2) - (2)].ID_modal_formula)!=NULL) {
    atomic_proposition *ap = new atomic_proposition((yysemantic_stack_[(2) - (2)].ID_modal_formula)->first);
    modal_formula *a = new modal_formula(ap);
    (yyval._modal_formula) = new modal_formula(40, a, (yysemantic_stack_[(2) - (2)].ID_modal_formula)->second);
    free((yysemantic_stack_[(2) - (2)].ID_modal_formula));
  } else
    (yyval._modal_formula) = NULL;
 }
    break;

  case 686:

/* Line 690 of lalr1.cc  */
#line 4417 "parser/nssis_new.yy"
    {
  // Distributed knowledge in a group
  if((yysemantic_stack_[(2) - (2)].ID_modal_formula)!=NULL) {
    atomic_proposition *ap = new atomic_proposition((yysemantic_stack_[(2) - (2)].ID_modal_formula)->first);
    modal_formula *a = new modal_formula(ap);
    (yyval._modal_formula) = new modal_formula(42, a, (yysemantic_stack_[(2) - (2)].ID_modal_formula)->second);
    free((yysemantic_stack_[(2) - (2)].ID_modal_formula));
  } else
    (yyval._modal_formula) = NULL;
 }
    break;

  case 687:

/* Line 690 of lalr1.cc  */
#line 4427 "parser/nssis_new.yy"
    { 
  (yyval._modal_formula) = NULL;
  driver.syntax_error = true;
 }
    break;

  case 688:

/* Line 690 of lalr1.cc  */
#line 4431 "parser/nssis_new.yy"
    { 
  (yyval._modal_formula) = NULL;
  driver.syntax_error = true;
 }
    break;

  case 689:

/* Line 690 of lalr1.cc  */
#line 4435 "parser/nssis_new.yy"
    {
  // ATL X operator
  if((yysemantic_stack_[(3) - (1)].sval)!=NULL && (yysemantic_stack_[(3) - (3)]._modal_formula)!=NULL) {
    atomic_proposition *ap = new atomic_proposition((yysemantic_stack_[(3) - (1)].sval));
    modal_formula *a = new modal_formula(ap);
    (yyval._modal_formula) = new modal_formula(45, a, (yysemantic_stack_[(3) - (3)]._modal_formula));
  } else
    (yyval._modal_formula) = NULL;
 }
    break;

  case 690:

/* Line 690 of lalr1.cc  */
#line 4444 "parser/nssis_new.yy"
    {
  // ATL F operator
  if((yysemantic_stack_[(3) - (1)].sval)!=NULL && (yysemantic_stack_[(3) - (3)]._modal_formula)!=NULL) {
    atomic_proposition *ap = new atomic_proposition((yysemantic_stack_[(3) - (1)].sval));
    modal_formula *a = new modal_formula(ap);
    (yyval._modal_formula) = new modal_formula(46, a, (yysemantic_stack_[(3) - (3)]._modal_formula));
  } else
    (yyval._modal_formula) = NULL;
 }
    break;

  case 691:

/* Line 690 of lalr1.cc  */
#line 4453 "parser/nssis_new.yy"
    {
  // ATL G operator
  if((yysemantic_stack_[(3) - (1)].sval)!=NULL && (yysemantic_stack_[(3) - (3)]._modal_formula)!=NULL) {
    atomic_proposition *ap = new atomic_proposition((yysemantic_stack_[(3) - (1)].sval));
    modal_formula *a = new modal_formula(ap);
    (yyval._modal_formula) = new modal_formula(47, a, (yysemantic_stack_[(3) - (3)]._modal_formula));
  } else
    (yyval._modal_formula) = NULL;
 }
    break;

  case 692:

/* Line 690 of lalr1.cc  */
#line 4462 "parser/nssis_new.yy"
    {
  (yyval._modal_formula) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(3) - (3)]._modal_formula));
 }
    break;

  case 693:

/* Line 690 of lalr1.cc  */
#line 4467 "parser/nssis_new.yy"
    {
  // ATL U operator
  if((yysemantic_stack_[(2) - (1)].sval)!=NULL && (yysemantic_stack_[(2) - (2)].dual_modal_formula)!=NULL) {
    atomic_proposition *ap = new atomic_proposition((yysemantic_stack_[(2) - (1)].sval));
    modal_formula *a = new modal_formula(ap);
    (yyval._modal_formula) = new modal_formula(48, a, (yysemantic_stack_[(2) - (2)].dual_modal_formula)->first, (yysemantic_stack_[(2) - (2)].dual_modal_formula)->second);
    free((yysemantic_stack_[(2) - (2)].dual_modal_formula));
  } else {
    if((yysemantic_stack_[(2) - (2)].dual_modal_formula) != NULL)
       free((yysemantic_stack_[(2) - (2)].dual_modal_formula));
    if((yysemantic_stack_[(2) - (1)].sval) != NULL)
      free((yysemantic_stack_[(2) - (1)].sval));
    (yyval._modal_formula) = NULL;
  }
 }
    break;

  case 694:

/* Line 690 of lalr1.cc  */
#line 4482 "parser/nssis_new.yy"
    {	
  if((yysemantic_stack_[(1) - (1)].sval)!=NULL) {
    atomic_proposition *ap;
    int i = search_string_table((yysemantic_stack_[(1) - (1)].sval));
    if(i>=0) {
      ap = new atomic_proposition((*string_table)[i]);
      free((yysemantic_stack_[(1) - (1)].sval));
    } else {
      ap = new atomic_proposition((yysemantic_stack_[(1) - (1)].sval));
      string_table->push_back((yysemantic_stack_[(1) - (1)].sval));
    }
    (yyval._modal_formula) = new modal_formula(ap);
  } else
    (yyval._modal_formula) = NULL;
  }
    break;

  case 695:

/* Line 690 of lalr1.cc  */
#line 4497 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(3) - (1)].sval)!=NULL) {
    string *newname = new string(*(yysemantic_stack_[(3) - (1)].sval) + ".GreenStates");
    atomic_proposition *ap;
    int i = search_string_table(newname);
    if(i>=0) {
      ap = new atomic_proposition((*string_table)[i]);
      free(newname);
    } else {
      ap = new atomic_proposition(newname);
      string_table->push_back(newname);
    }
    free((yysemantic_stack_[(3) - (1)].sval));
    (yyval._modal_formula) = new modal_formula(ap);
  } else
    (yyval._modal_formula) = NULL;
 }
    break;

  case 696:

/* Line 690 of lalr1.cc  */
#line 4514 "parser/nssis_new.yy"
    {
  if((yysemantic_stack_[(3) - (1)].sval)!=NULL) {
    string *newname = new string(*(yysemantic_stack_[(3) - (1)].sval) + ".RedStates");
    atomic_proposition *ap;
    int i = search_string_table(newname);
    if(i>=0) {
      ap = new atomic_proposition((*string_table)[i]);
      free(newname);
    } else {
      ap = new atomic_proposition(newname);
      string_table->push_back(newname);
    }
    free((yysemantic_stack_[(3) - (1)].sval));
    (yyval._modal_formula) = new modal_formula(ap);
  } else
    (yyval._modal_formula) = NULL;
 }
    break;

  case 697:

/* Line 690 of lalr1.cc  */
#line 4531 "parser/nssis_new.yy"
    {
    string *newname = new string("Environment.GreenStates");
    atomic_proposition *ap;
    int i = search_string_table(newname);
    if(i>=0) {
      ap = new atomic_proposition((*string_table)[i]);
      free(newname);
    } else {
      ap = new atomic_proposition(newname);
      string_table->push_back(newname);
    }
    (yyval._modal_formula) = new modal_formula(ap);
 }
    break;

  case 698:

/* Line 690 of lalr1.cc  */
#line 4544 "parser/nssis_new.yy"
    {
  string *newname = new string("Environment.RedStates");
  atomic_proposition *ap;
  int i = search_string_table(newname);
  if(i>=0) {
    ap = new atomic_proposition((*string_table)[i]);
    free(newname);
  } else {
    ap = new atomic_proposition(newname);
    string_table->push_back(newname);
  }
  (yyval._modal_formula) = new modal_formula(ap);
 }
    break;

  case 699:

/* Line 690 of lalr1.cc  */
#line 4557 "parser/nssis_new.yy"
    {
  (yyval._modal_formula) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(3) - (1)].sval));
 }
    break;

  case 700:

/* Line 690 of lalr1.cc  */
#line 4562 "parser/nssis_new.yy"
    {
  (yyval._modal_formula) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(3) - (1)].sval));
 }
    break;

  case 701:

/* Line 690 of lalr1.cc  */
#line 4567 "parser/nssis_new.yy"
    {
  (yyval._modal_formula) = NULL;
  driver.syntax_error = true;
  USE((yysemantic_stack_[(3) - (1)].sval));
 }
    break;

  case 702:

/* Line 690 of lalr1.cc  */
#line 4572 "parser/nssis_new.yy"
    {
  (yyval._modal_formula) = NULL;
  driver.syntax_error = true;
  }
    break;

  case 703:

/* Line 690 of lalr1.cc  */
#line 4578 "parser/nssis_new.yy"
    {
	(yyval.ival) = 1;
   }
    break;

  case 704:

/* Line 690 of lalr1.cc  */
#line 4581 "parser/nssis_new.yy"
    {
	(yyval.ival) = 0;
	driver.syntax_error = true;
   }
    break;

  case 705:

/* Line 690 of lalr1.cc  */
#line 4585 "parser/nssis_new.yy"
    {
	(yyval.ival) = 1;
   }
    break;

  case 706:

/* Line 690 of lalr1.cc  */
#line 4588 "parser/nssis_new.yy"
    {
	(yyval.ival) = 0;
	driver.syntax_error = true;
   }
    break;

  case 707:

/* Line 690 of lalr1.cc  */
#line 4592 "parser/nssis_new.yy"
    {
	(yyval.ival) = 0;
	driver.syntax_error = true;
   }
    break;

  case 708:

/* Line 690 of lalr1.cc  */
#line 4596 "parser/nssis_new.yy"
    {
	(yyval.ival) = 0;
	driver.syntax_error = true;
	}
    break;

  case 710:

/* Line 690 of lalr1.cc  */
#line 4603 "parser/nssis_new.yy"
    { 
	if((yysemantic_stack_[(2) - (1)]._modal_formula_ast)!=NULL) {
	  is_formulae_ast->push_back(*(yysemantic_stack_[(2) - (1)]._modal_formula_ast));
	}
   }
    break;

  case 711:

/* Line 690 of lalr1.cc  */
#line 4608 "parser/nssis_new.yy"
    {
	driver.syntax_error = true;
	USE((yysemantic_stack_[(2) - (1)]._modal_formula_ast));
   }
    break;

  case 712:

/* Line 690 of lalr1.cc  */
#line 4612 "parser/nssis_new.yy"
    { 
	if((yysemantic_stack_[(3) - (2)]._modal_formula_ast)!=NULL) {
	  is_formulae_ast->push_back(*(yysemantic_stack_[(3) - (2)]._modal_formula_ast)); 
	}
   }
    break;

  case 713:

/* Line 690 of lalr1.cc  */
#line 4617 "parser/nssis_new.yy"
    {
	driver.syntax_error = true;
	USE((yysemantic_stack_[(3) - (2)]._modal_formula_ast));
   }
    break;

  case 714:

/* Line 690 of lalr1.cc  */
#line 4621 "parser/nssis_new.yy"
    {
	driver.syntax_error = true;
	}
    break;

  case 715:

/* Line 690 of lalr1.cc  */
#line 4625 "parser/nssis_new.yy"
    { 
	  int i = search_string_table((yysemantic_stack_[(3) - (2)].sval));
	  if(i>=0) {
		(yyval.sval) = (*string_table)[i];
		free((yysemantic_stack_[(3) - (2)].sval));
	  } else {
		(yyval.sval) = (yysemantic_stack_[(3) - (2)].sval);
		string_table->push_back((yysemantic_stack_[(3) - (2)].sval));
	  }
   }
    break;

  case 716:

/* Line 690 of lalr1.cc  */
#line 4635 "parser/nssis_new.yy"
    {
	(yyval.sval) = NULL;
	driver.syntax_error = true;
	USE((yysemantic_stack_[(3) - (2)].sval));
   }
    break;

  case 717:

/* Line 690 of lalr1.cc  */
#line 4640 "parser/nssis_new.yy"
    {
	(yyval.sval) = NULL;
	driver.syntax_error = true;
	USE((yysemantic_stack_[(3) - (2)].sval));
   }
    break;

  case 718:

/* Line 690 of lalr1.cc  */
#line 4645 "parser/nssis_new.yy"
    {
	if((yysemantic_stack_[(5) - (2)]._modal_formula_ast)!=NULL && (yysemantic_stack_[(5) - (4)]._modal_formula_ast)!=NULL)
	  (yyval.dual_modal_formula_ast) = new pair<modal_formula_ast *, modal_formula_ast *>((yysemantic_stack_[(5) - (2)]._modal_formula_ast), (yysemantic_stack_[(5) - (4)]._modal_formula_ast));
	else
	  (yyval.dual_modal_formula_ast) = NULL;
   }
    break;

  case 719:

/* Line 690 of lalr1.cc  */
#line 4651 "parser/nssis_new.yy"
    {
	(yyval.dual_modal_formula_ast) = NULL;
	driver.syntax_error = true;
	USE((yysemantic_stack_[(5) - (2)]._modal_formula_ast));USE((yysemantic_stack_[(5) - (4)]._modal_formula_ast));
   }
    break;

  case 720:

/* Line 690 of lalr1.cc  */
#line 4656 "parser/nssis_new.yy"
    {
	(yyval.dual_modal_formula_ast) = NULL;
	driver.syntax_error = true;
	USE((yysemantic_stack_[(5) - (2)]._modal_formula_ast));USE((yysemantic_stack_[(5) - (4)]._modal_formula_ast));
   }
    break;

  case 721:

/* Line 690 of lalr1.cc  */
#line 4661 "parser/nssis_new.yy"
    {
	(yyval.dual_modal_formula_ast) = NULL;
	driver.syntax_error = true;
	USE((yysemantic_stack_[(5) - (2)]._modal_formula_ast));USE((yysemantic_stack_[(5) - (4)]._modal_formula_ast));
   }
    break;

  case 722:

/* Line 690 of lalr1.cc  */
#line 4666 "parser/nssis_new.yy"
    {
	(yyval.dual_modal_formula_ast) = NULL;
	driver.syntax_error = true;
	USE((yysemantic_stack_[(5) - (2)]._modal_formula_ast));USE((yysemantic_stack_[(5) - (4)]._modal_formula_ast));
   }
    break;

  case 723:

/* Line 690 of lalr1.cc  */
#line 4671 "parser/nssis_new.yy"
    {
	(yyval.dual_modal_formula_ast) = NULL;
	driver.syntax_error = true;
	USE((yysemantic_stack_[(5) - (2)]._modal_formula_ast));USE((yysemantic_stack_[(5) - (4)]._modal_formula_ast));
   }
    break;

  case 724:

/* Line 690 of lalr1.cc  */
#line 4676 "parser/nssis_new.yy"
    {
	(yyval.dual_modal_formula_ast) = NULL;
	driver.syntax_error = true;
	USE((yysemantic_stack_[(5) - (2)]._modal_formula_ast));USE((yysemantic_stack_[(5) - (4)]._modal_formula_ast));
   }
    break;

  case 725:

/* Line 690 of lalr1.cc  */
#line 4681 "parser/nssis_new.yy"
    {
	(yyval.dual_modal_formula_ast) = NULL;
	driver.syntax_error = true;
	USE((yysemantic_stack_[(5) - (2)]._modal_formula_ast));USE((yysemantic_stack_[(5) - (4)]._modal_formula_ast));
   }
    break;

  case 726:

/* Line 690 of lalr1.cc  */
#line 4686 "parser/nssis_new.yy"
    {
	if((yysemantic_stack_[(5) - (2)]._modal_formula_ast)!=NULL && (yysemantic_stack_[(5) - (4)]._modal_formula_ast)!=NULL)
	  (yyval.dual_modal_formula_ast) = new pair<modal_formula_ast *, modal_formula_ast *>((yysemantic_stack_[(5) - (2)]._modal_formula_ast), (yysemantic_stack_[(5) - (4)]._modal_formula_ast));
	else
	  (yyval.dual_modal_formula_ast) = NULL;
   }
    break;

  case 727:

/* Line 690 of lalr1.cc  */
#line 4692 "parser/nssis_new.yy"
    {
	(yyval.dual_modal_formula_ast) = NULL;
	driver.syntax_error = true;
	USE((yysemantic_stack_[(5) - (2)]._modal_formula_ast));USE((yysemantic_stack_[(5) - (4)]._modal_formula_ast));
   }
    break;

  case 728:

/* Line 690 of lalr1.cc  */
#line 4697 "parser/nssis_new.yy"
    {
	(yyval.dual_modal_formula_ast) = NULL;
	driver.syntax_error = true;
	USE((yysemantic_stack_[(5) - (2)]._modal_formula_ast));USE((yysemantic_stack_[(5) - (4)]._modal_formula_ast));
   }
    break;

  case 729:

/* Line 690 of lalr1.cc  */
#line 4702 "parser/nssis_new.yy"
    {
	(yyval.dual_modal_formula_ast) = NULL;
	driver.syntax_error = true;
	USE((yysemantic_stack_[(5) - (2)]._modal_formula_ast));USE((yysemantic_stack_[(5) - (4)]._modal_formula_ast));
   }
    break;

  case 730:

/* Line 690 of lalr1.cc  */
#line 4707 "parser/nssis_new.yy"
    {
	(yyval.dual_modal_formula_ast) = NULL;
	driver.syntax_error = true;
	USE((yysemantic_stack_[(5) - (2)]._modal_formula_ast));USE((yysemantic_stack_[(5) - (4)]._modal_formula_ast));
   }
    break;

  case 731:

/* Line 690 of lalr1.cc  */
#line 4712 "parser/nssis_new.yy"
    {
	(yyval.dual_modal_formula_ast) = NULL;
	driver.syntax_error = true;
	USE((yysemantic_stack_[(5) - (2)]._modal_formula_ast));USE((yysemantic_stack_[(5) - (4)]._modal_formula_ast));
   }
    break;

  case 732:

/* Line 690 of lalr1.cc  */
#line 4717 "parser/nssis_new.yy"
    {
	(yyval.dual_modal_formula_ast) = NULL;
	driver.syntax_error = true;
	USE((yysemantic_stack_[(5) - (2)]._modal_formula_ast));USE((yysemantic_stack_[(5) - (4)]._modal_formula_ast));
   }
    break;

  case 733:

/* Line 690 of lalr1.cc  */
#line 4722 "parser/nssis_new.yy"
    {
	(yyval.dual_modal_formula_ast) = NULL;
	driver.syntax_error = true;
	USE((yysemantic_stack_[(5) - (2)]._modal_formula_ast));USE((yysemantic_stack_[(5) - (4)]._modal_formula_ast));
   }
    break;

  case 734:

/* Line 690 of lalr1.cc  */
#line 4728 "parser/nssis_new.yy"
    {
	if((yysemantic_stack_[(5) - (2)].sval)!=NULL && (yysemantic_stack_[(5) - (4)]._modal_formula_ast)!=NULL) {
	  int i = search_string_table((yysemantic_stack_[(5) - (2)].sval));
	  if(i>=0) {
	    (yyval.ID_modal_formula_ast) = new pair<string *, modal_formula_ast *>((*string_table)[i], (yysemantic_stack_[(5) - (4)]._modal_formula_ast));
	    free((yysemantic_stack_[(5) - (2)].sval));
	  } else {
	    (yyval.ID_modal_formula_ast) = new pair<string *, modal_formula_ast *>((yysemantic_stack_[(5) - (2)].sval), (yysemantic_stack_[(5) - (4)]._modal_formula_ast));
	    string_table->push_back((yysemantic_stack_[(5) - (2)].sval));
	  }
	} else
	  (yyval.ID_modal_formula_ast) = NULL;
   }
    break;

  case 735:

/* Line 690 of lalr1.cc  */
#line 4741 "parser/nssis_new.yy"
    {
	 (yyval.ID_modal_formula_ast) = NULL;
	 driver.syntax_error = true;
	 USE((yysemantic_stack_[(5) - (2)].sval));
	 USE((yysemantic_stack_[(5) - (4)]._modal_formula_ast));
	}
    break;

  case 736:

/* Line 690 of lalr1.cc  */
#line 4747 "parser/nssis_new.yy"
    {
	 (yyval.ID_modal_formula_ast) = NULL;
	 driver.syntax_error = true;
	 USE((yysemantic_stack_[(5) - (2)].sval));
	 USE((yysemantic_stack_[(5) - (4)]._modal_formula_ast));
    }
    break;

  case 737:

/* Line 690 of lalr1.cc  */
#line 4753 "parser/nssis_new.yy"
    {
	 (yyval.ID_modal_formula_ast) = NULL;
	 driver.syntax_error = true;
	 USE((yysemantic_stack_[(5) - (2)].sval));
	 USE((yysemantic_stack_[(5) - (4)]._modal_formula_ast));
	}
    break;

  case 738:

/* Line 690 of lalr1.cc  */
#line 4759 "parser/nssis_new.yy"
    {
	 (yyval.ID_modal_formula_ast) = NULL;
	 driver.syntax_error = true;
	 USE((yysemantic_stack_[(5) - (2)].sval));
	 USE((yysemantic_stack_[(5) - (4)]._modal_formula_ast));
	}
    break;

  case 739:

/* Line 690 of lalr1.cc  */
#line 4765 "parser/nssis_new.yy"
    {
	 (yyval.ID_modal_formula_ast) = NULL;
	 driver.syntax_error = true;
	 USE((yysemantic_stack_[(5) - (2)].sval));
	 USE((yysemantic_stack_[(5) - (4)]._modal_formula_ast));
	}
    break;

  case 740:

/* Line 690 of lalr1.cc  */
#line 4771 "parser/nssis_new.yy"
    {
	 (yyval.ID_modal_formula_ast) = NULL;
	 driver.syntax_error = true;
	 USE((yysemantic_stack_[(5) - (2)].sval));
	 USE((yysemantic_stack_[(5) - (4)]._modal_formula_ast));
	}
    break;

  case 741:

/* Line 690 of lalr1.cc  */
#line 4777 "parser/nssis_new.yy"
    {
	 (yyval.ID_modal_formula_ast) = NULL;
	 driver.syntax_error = true;
	 USE((yysemantic_stack_[(5) - (2)].sval));
	 USE((yysemantic_stack_[(5) - (4)]._modal_formula_ast));
	}
    break;

  case 742:

/* Line 690 of lalr1.cc  */
#line 4783 "parser/nssis_new.yy"
    {
	 if((yysemantic_stack_[(5) - (4)]._modal_formula_ast)!=NULL)
	   (yyval.ID_modal_formula_ast) = new pair<string *, modal_formula_ast *>((*string_table)[0], (yysemantic_stack_[(5) - (4)]._modal_formula_ast));
	 else
	   (yyval.ID_modal_formula_ast) = NULL;
	}
    break;

  case 743:

/* Line 690 of lalr1.cc  */
#line 4789 "parser/nssis_new.yy"
    {
	 (yyval.ID_modal_formula_ast) = NULL;
	 driver.syntax_error = true;
	 USE((yysemantic_stack_[(5) - (4)]._modal_formula_ast));
	}
    break;

  case 744:

/* Line 690 of lalr1.cc  */
#line 4794 "parser/nssis_new.yy"
    {
	 (yyval.ID_modal_formula_ast) = NULL;
	 driver.syntax_error = true;
	 USE((yysemantic_stack_[(5) - (4)]._modal_formula_ast));
	}
    break;

  case 745:

/* Line 690 of lalr1.cc  */
#line 4799 "parser/nssis_new.yy"
    {
	 (yyval.ID_modal_formula_ast) = NULL;
	 driver.syntax_error = true;
	 USE((yysemantic_stack_[(5) - (4)]._modal_formula_ast));
	}
    break;

  case 746:

/* Line 690 of lalr1.cc  */
#line 4804 "parser/nssis_new.yy"
    {
	 (yyval.ID_modal_formula_ast) = NULL;
	 driver.syntax_error = true;
	 USE((yysemantic_stack_[(5) - (4)]._modal_formula_ast));
	}
    break;

  case 747:

/* Line 690 of lalr1.cc  */
#line 4809 "parser/nssis_new.yy"
    {
	 (yyval.ID_modal_formula_ast) = NULL;
	 driver.syntax_error = true;
	 USE((yysemantic_stack_[(5) - (4)]._modal_formula_ast));
	}
    break;

  case 748:

/* Line 690 of lalr1.cc  */
#line 4814 "parser/nssis_new.yy"
    {
	 (yyval.ID_modal_formula_ast) = NULL;
	 driver.syntax_error = true;
	 USE((yysemantic_stack_[(5) - (4)]._modal_formula_ast));
	}
    break;

  case 749:

/* Line 690 of lalr1.cc  */
#line 4819 "parser/nssis_new.yy"
    {
	 (yyval.ID_modal_formula_ast) = NULL;
	 driver.syntax_error = true;
	 USE((yysemantic_stack_[(5) - (4)]._modal_formula_ast));
	}
    break;

  case 750:

/* Line 690 of lalr1.cc  */
#line 4824 "parser/nssis_new.yy"
    {
	if((yysemantic_stack_[(5) - (2)].sval)!=NULL && (yysemantic_stack_[(5) - (4)]._modal_formula_ast)!=NULL) {
	  int i = search_string_table((yysemantic_stack_[(5) - (2)].sval));
	  if(i>=0) {
	    (yyval.ID_modal_formula_ast) = new pair<string *, modal_formula_ast *>((*string_table)[i], (yysemantic_stack_[(5) - (4)]._modal_formula_ast));
		free((yysemantic_stack_[(5) - (2)].sval));
	  } else {
		(yyval.ID_modal_formula_ast) = new pair<string *, modal_formula_ast *>((yysemantic_stack_[(5) - (2)].sval), (yysemantic_stack_[(5) - (4)]._modal_formula_ast));
		string_table->push_back((yysemantic_stack_[(5) - (2)].sval));
	  }
	} else
	   (yyval.ID_modal_formula_ast) = NULL;
   }
    break;

  case 751:

/* Line 690 of lalr1.cc  */
#line 4837 "parser/nssis_new.yy"
    {
	 (yyval.ID_modal_formula_ast) = NULL;
	 driver.syntax_error = true;
	 USE((yysemantic_stack_[(5) - (2)].sval));
	 USE((yysemantic_stack_[(5) - (4)]._modal_formula_ast));
   }
    break;

  case 752:

/* Line 690 of lalr1.cc  */
#line 4843 "parser/nssis_new.yy"
    {
	 (yyval.ID_modal_formula_ast) = NULL;
	 driver.syntax_error = true;
	 USE((yysemantic_stack_[(5) - (2)].sval));
	 USE((yysemantic_stack_[(5) - (4)]._modal_formula_ast));
   }
    break;

  case 753:

/* Line 690 of lalr1.cc  */
#line 4849 "parser/nssis_new.yy"
    {
	 (yyval.ID_modal_formula_ast) = NULL;
	 driver.syntax_error = true;
	 USE((yysemantic_stack_[(5) - (2)].sval));
	 USE((yysemantic_stack_[(5) - (4)]._modal_formula_ast));
   }
    break;

  case 754:

/* Line 690 of lalr1.cc  */
#line 4855 "parser/nssis_new.yy"
    {
	 (yyval.ID_modal_formula_ast) = NULL;
	 driver.syntax_error = true;
	 USE((yysemantic_stack_[(5) - (2)].sval));
	 USE((yysemantic_stack_[(5) - (4)]._modal_formula_ast));
   }
    break;

  case 755:

/* Line 690 of lalr1.cc  */
#line 4861 "parser/nssis_new.yy"
    {
	 (yyval.ID_modal_formula_ast) = NULL;
	 driver.syntax_error = true;
	 USE((yysemantic_stack_[(5) - (2)].sval));
	 USE((yysemantic_stack_[(5) - (4)]._modal_formula_ast));
   }
    break;

  case 756:

/* Line 690 of lalr1.cc  */
#line 4867 "parser/nssis_new.yy"
    {
	 (yyval.ID_modal_formula_ast) = NULL;
	 driver.syntax_error = true;
	 USE((yysemantic_stack_[(5) - (2)].sval));
	 USE((yysemantic_stack_[(5) - (4)]._modal_formula_ast));
   }
    break;

  case 757:

/* Line 690 of lalr1.cc  */
#line 4873 "parser/nssis_new.yy"
    {
	 (yyval.ID_modal_formula_ast) = NULL;
	 driver.syntax_error = true;
	 USE((yysemantic_stack_[(5) - (2)].sval));
	 USE((yysemantic_stack_[(5) - (4)]._modal_formula_ast));
   }
    break;

  case 758:

/* Line 690 of lalr1.cc  */
#line 4881 "parser/nssis_new.yy"
    { 
	(yyval._modal_formula_ast) = (yysemantic_stack_[(3) - (2)]._modal_formula_ast);
   }
    break;

  case 759:

/* Line 690 of lalr1.cc  */
#line 4884 "parser/nssis_new.yy"
    { 
	(yyval._modal_formula_ast) = NULL;
	driver.syntax_error = true;
	USE((yysemantic_stack_[(3) - (2)]._modal_formula_ast));
   }
    break;

  case 760:

/* Line 690 of lalr1.cc  */
#line 4889 "parser/nssis_new.yy"
    { 
	(yyval._modal_formula_ast) = NULL;
	driver.syntax_error = true;
	USE((yysemantic_stack_[(3) - (2)]._modal_formula_ast));
   }
    break;

  case 761:

/* Line 690 of lalr1.cc  */
#line 4894 "parser/nssis_new.yy"
    { 
	(yyval._modal_formula_ast) = NULL;
	driver.syntax_error = true;
	USE((yysemantic_stack_[(3) - (2)]._modal_formula_ast));
   }
    break;

  case 762:

/* Line 690 of lalr1.cc  */
#line 4899 "parser/nssis_new.yy"
    {
	if((yysemantic_stack_[(3) - (1)]._modal_formula_ast)!=NULL && (yysemantic_stack_[(3) - (3)]._modal_formula_ast)!=NULL)
	  (yyval._modal_formula_ast) = new modal_formula_ast(1, (yysemantic_stack_[(3) - (1)]._modal_formula_ast), (yysemantic_stack_[(3) - (3)]._modal_formula_ast));
	else
	  (yyval._modal_formula_ast) = NULL;
   }
    break;

  case 763:

/* Line 690 of lalr1.cc  */
#line 4905 "parser/nssis_new.yy"
    {
	if((yysemantic_stack_[(3) - (1)]._modal_formula_ast)!=NULL && (yysemantic_stack_[(3) - (3)]._modal_formula_ast)!=NULL)
	  (yyval._modal_formula_ast) = new modal_formula_ast(2, (yysemantic_stack_[(3) - (1)]._modal_formula_ast), (yysemantic_stack_[(3) - (3)]._modal_formula_ast));
	else
	  (yyval._modal_formula_ast) = NULL;
   }
    break;

  case 764:

/* Line 690 of lalr1.cc  */
#line 4911 "parser/nssis_new.yy"
    {
	(yyval._modal_formula_ast) = NULL;
	driver.syntax_error = true;
	USE((yysemantic_stack_[(3) - (1)]._modal_formula_ast));USE((yysemantic_stack_[(3) - (3)]._modal_formula_ast));
   }
    break;

  case 765:

/* Line 690 of lalr1.cc  */
#line 4916 "parser/nssis_new.yy"
    {
	if((yysemantic_stack_[(2) - (2)]._modal_formula_ast)!=NULL)
	  (yyval._modal_formula_ast) = new modal_formula_ast(3, (yysemantic_stack_[(2) - (2)]._modal_formula_ast));
	else
	  (yyval._modal_formula_ast) = NULL;
   }
    break;

  case 766:

/* Line 690 of lalr1.cc  */
#line 4922 "parser/nssis_new.yy"
    {
	(yyval._modal_formula_ast) = NULL;
	driver.syntax_error = true;
	USE((yysemantic_stack_[(2) - (2)]._modal_formula_ast));
   }
    break;

  case 767:

/* Line 690 of lalr1.cc  */
#line 4927 "parser/nssis_new.yy"
    {
	if((yysemantic_stack_[(3) - (1)]._modal_formula_ast)!=NULL && (yysemantic_stack_[(3) - (3)]._modal_formula_ast)!=NULL)
	  (yyval._modal_formula_ast) = new modal_formula_ast(4, (yysemantic_stack_[(3) - (1)]._modal_formula_ast), (yysemantic_stack_[(3) - (3)]._modal_formula_ast));
	else
	  (yyval._modal_formula_ast) = NULL;
   }
    break;

  case 768:

/* Line 690 of lalr1.cc  */
#line 4933 "parser/nssis_new.yy"
    {
	if((yysemantic_stack_[(2) - (2)]._modal_formula_ast)!=NULL)
	  (yyval._modal_formula_ast) = new modal_formula_ast(5, (yysemantic_stack_[(2) - (2)]._modal_formula_ast));
	else
	  (yyval._modal_formula_ast) = NULL;
   }
    break;

  case 769:

/* Line 690 of lalr1.cc  */
#line 4939 "parser/nssis_new.yy"
    {
	if((yysemantic_stack_[(2) - (2)]._modal_formula_ast)!=NULL)
	  (yyval._modal_formula_ast) = new modal_formula_ast(6, (yysemantic_stack_[(2) - (2)]._modal_formula_ast));
	else
	  (yyval._modal_formula_ast) = NULL;
   }
    break;

  case 770:

/* Line 690 of lalr1.cc  */
#line 4945 "parser/nssis_new.yy"
    { 
	if((yysemantic_stack_[(2) - (2)]._modal_formula_ast)!=NULL)
	  (yyval._modal_formula_ast) = new modal_formula_ast(7, (yysemantic_stack_[(2) - (2)]._modal_formula_ast));
	else
	  (yyval._modal_formula_ast) = NULL;
   }
    break;

  case 771:

/* Line 690 of lalr1.cc  */
#line 4951 "parser/nssis_new.yy"
    {
	if((yysemantic_stack_[(1) - (1)].dual_modal_formula_ast)!=NULL) {
	  (yyval._modal_formula_ast) = new modal_formula_ast(8, (yysemantic_stack_[(1) - (1)].dual_modal_formula_ast)->first, (yysemantic_stack_[(1) - (1)].dual_modal_formula_ast)->second);
	  free((yysemantic_stack_[(1) - (1)].dual_modal_formula_ast));
	}
	else
	  (yyval._modal_formula_ast) = NULL;
   }
    break;

  case 772:

/* Line 690 of lalr1.cc  */
#line 4959 "parser/nssis_new.yy"
    {
	if((yysemantic_stack_[(1) - (1)].dual_modal_formula_ast)!=NULL) {
	  (yyval._modal_formula_ast) = new modal_formula_ast(9, (yysemantic_stack_[(1) - (1)].dual_modal_formula_ast)->first, (yysemantic_stack_[(1) - (1)].dual_modal_formula_ast)->second);
	  free((yysemantic_stack_[(1) - (1)].dual_modal_formula_ast));
	}
	else
	  (yyval._modal_formula_ast) = NULL;
   }
    break;

  case 773:

/* Line 690 of lalr1.cc  */
#line 4967 "parser/nssis_new.yy"
    {
	if((yysemantic_stack_[(2) - (2)].ID_modal_formula_ast)!=NULL) {
	  atomic_proposition *ap = new atomic_proposition((yysemantic_stack_[(2) - (2)].ID_modal_formula_ast)->first);
	  modal_formula_ast *a = new modal_formula_ast(ap);
	  (yyval._modal_formula_ast) = new modal_formula_ast(10, a, (yysemantic_stack_[(2) - (2)].ID_modal_formula_ast)->second);
	  free((yysemantic_stack_[(2) - (2)].ID_modal_formula_ast));
	} else
	  (yyval._modal_formula_ast) = NULL;
   }
    break;

  case 774:

/* Line 690 of lalr1.cc  */
#line 4976 "parser/nssis_new.yy"
    {
    // Knowledge in a group (everybody knows)
	if((yysemantic_stack_[(2) - (2)].ID_modal_formula_ast)!=NULL) {
      atomic_proposition *ap = new atomic_proposition((yysemantic_stack_[(2) - (2)].ID_modal_formula_ast)->first);
      modal_formula_ast *a = new modal_formula_ast(ap);
      (yyval._modal_formula_ast) = new modal_formula_ast(11, a, (yysemantic_stack_[(2) - (2)].ID_modal_formula_ast)->second);
      free((yysemantic_stack_[(2) - (2)].ID_modal_formula_ast));
    } else
      (yyval._modal_formula_ast) = NULL;
   }
    break;

  case 775:

/* Line 690 of lalr1.cc  */
#line 4986 "parser/nssis_new.yy"
    {
    // Common knowledge in a group
	if((yysemantic_stack_[(2) - (2)].ID_modal_formula_ast)!=NULL) {
      atomic_proposition *ap = new atomic_proposition((yysemantic_stack_[(2) - (2)].ID_modal_formula_ast)->first);
      modal_formula_ast *a = new modal_formula_ast(ap);
      (yyval._modal_formula_ast) = new modal_formula_ast(12, a, (yysemantic_stack_[(2) - (2)].ID_modal_formula_ast)->second);
      free((yysemantic_stack_[(2) - (2)].ID_modal_formula_ast));
    } else
      (yyval._modal_formula_ast) = NULL;
   }
    break;

  case 776:

/* Line 690 of lalr1.cc  */
#line 4996 "parser/nssis_new.yy"
    {
	// Distributed knowledge in a group
    if((yysemantic_stack_[(2) - (2)].ID_modal_formula_ast)!=NULL) {
      atomic_proposition *ap = new atomic_proposition((yysemantic_stack_[(2) - (2)].ID_modal_formula_ast)->first);
      modal_formula_ast *a = new modal_formula_ast(ap);
      (yyval._modal_formula_ast) = new modal_formula_ast(13, a, (yysemantic_stack_[(2) - (2)].ID_modal_formula_ast)->second);
      free((yysemantic_stack_[(2) - (2)].ID_modal_formula_ast));
    } else
      (yyval._modal_formula_ast) = NULL;
   }
    break;

  case 777:

/* Line 690 of lalr1.cc  */
#line 5006 "parser/nssis_new.yy"
    { 
    (yyval._modal_formula_ast) = NULL;
    driver.syntax_error = true;
   }
    break;

  case 778:

/* Line 690 of lalr1.cc  */
#line 5010 "parser/nssis_new.yy"
    { 
    (yyval._modal_formula_ast) = NULL;
    driver.syntax_error = true;
   }
    break;

  case 779:

/* Line 690 of lalr1.cc  */
#line 5014 "parser/nssis_new.yy"
    {
    if((yysemantic_stack_[(2) - (1)].sval)!=NULL && (yysemantic_stack_[(2) - (2)]._modal_formula_ast)!=NULL) {
	  atomic_proposition *ap = new atomic_proposition((yysemantic_stack_[(2) - (1)].sval));
	  modal_formula_ast *a = new modal_formula_ast(ap);
	  (yyval._modal_formula_ast) = new modal_formula_ast(14, a, (yysemantic_stack_[(2) - (2)]._modal_formula_ast));
	} else {
	  if((yysemantic_stack_[(2) - (2)]._modal_formula_ast)!= NULL)
	  	free((yysemantic_stack_[(2) - (2)]._modal_formula_ast));
	  if((yysemantic_stack_[(2) - (1)].sval)!=NULL)
	  	free((yysemantic_stack_[(2) - (1)].sval));
	  (yyval._modal_formula_ast)=NULL;
	}
   }
    break;

  case 780:

/* Line 690 of lalr1.cc  */
#line 5027 "parser/nssis_new.yy"
    {
	if((yysemantic_stack_[(1) - (1)].sval)!=NULL) {
	  atomic_proposition *ap;
	  int i = search_string_table((yysemantic_stack_[(1) - (1)].sval));
	  if(i>=0) {
		ap = new atomic_proposition((*string_table)[i]);
		free((yysemantic_stack_[(1) - (1)].sval));
	  } else {
		ap = new atomic_proposition((yysemantic_stack_[(1) - (1)].sval));
		string_table->push_back((yysemantic_stack_[(1) - (1)].sval));
	  }
	  (yyval._modal_formula_ast) = new modal_formula_ast(ap);
	} else
	  (yyval._modal_formula_ast) = NULL;
   }
    break;

  case 781:

/* Line 690 of lalr1.cc  */
#line 5042 "parser/nssis_new.yy"
    {
	(yyval._modal_formula_ast) = NULL;
	driver.syntax_error = true;
	}
    break;



/* Line 690 of lalr1.cc  */
#line 10025 "parser/nssis.cc"
	default:
          break;
      }
    /* User semantic actions sometimes alter yychar, and that requires
       that yytoken be updated with the new translation.  We take the
       approach of translating immediately before every use of yytoken.
       One alternative is translating here after every semantic action,
       but that translation would be missed if the semantic action
       invokes YYABORT, YYACCEPT, or YYERROR immediately after altering
       yychar.  In the case of YYABORT or YYACCEPT, an incorrect
       destructor might then be invoked immediately.  In the case of
       YYERROR, subsequent parser actions might lead to an incorrect
       destructor call or verbose syntax error message before the
       lookahead is translated.  */
    YY_SYMBOL_PRINT ("-> $$ =", yyr1_[yyn], &yyval, &yyloc);

    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();

    yysemantic_stack_.push (yyval);
    yylocation_stack_.push (yyloc);

    /* Shift the result of the reduction.  */
    yyn = yyr1_[yyn];
    yystate = yypgoto_[yyn - yyntokens_] + yystate_stack_[0];
    if (0 <= yystate && yystate <= yylast_
	&& yycheck_[yystate] == yystate_stack_[0])
      yystate = yytable_[yystate];
    else
      yystate = yydefgoto_[yyn - yyntokens_];
    goto yynewstate;

  /*------------------------------------.
  | yyerrlab -- here on detecting error |
  `------------------------------------*/
  yyerrlab:
    /* Make sure we have latest lookahead translation.  See comments at
       user semantic actions for why this is necessary.  */
    yytoken = yytranslate_ (yychar);

    /* If not already recovering from an error, report this error.  */
    if (!yyerrstatus_)
      {
	++yynerrs_;
	if (yychar == yyempty_)
	  yytoken = yyempty_;
	error (yylloc, yysyntax_error_ (yystate, yytoken));
      }

    yyerror_range[1] = yylloc;
    if (yyerrstatus_ == 3)
      {
	/* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

	if (yychar <= yyeof_)
	  {
	  /* Return failure if at end of input.  */
	  if (yychar == yyeof_)
	    YYABORT;
	  }
	else
	  {
	    yydestruct_ ("Error: discarding", yytoken, &yylval, &yylloc);
	    yychar = yyempty_;
	  }
      }

    /* Else will try to reuse lookahead token after shifting the error
       token.  */
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:

    /* Pacify compilers like GCC when the user code never invokes
       YYERROR and the label yyerrorlab therefore never appears in user
       code.  */
    if (false)
      goto yyerrorlab;

    yyerror_range[1] = yylocation_stack_[yylen - 1];
    /* Do not reclaim the symbols of the rule which action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    yystate = yystate_stack_[0];
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;	/* Each real token shifted decrements this.  */

    for (;;)
      {
	yyn = yypact_[yystate];
	if (!yy_pact_value_is_default_ (yyn))
	{
	  yyn += yyterror_;
	  if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
	    {
	      yyn = yytable_[yyn];
	      if (0 < yyn)
		break;
	    }
	}

	/* Pop the current state because it cannot handle the error token.  */
	if (yystate_stack_.height () == 1)
	YYABORT;

	yyerror_range[1] = yylocation_stack_[0];
	yydestruct_ ("Error: popping",
		     yystos_[yystate],
		     &yysemantic_stack_[0], &yylocation_stack_[0]);
	yypop_ ();
	yystate = yystate_stack_[0];
	YY_STACK_PRINT ();
      }

    yyerror_range[2] = yylloc;
    // Using YYLLOC is tempting, but would change the location of
    // the lookahead.  YYLOC is available though.
    YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yyloc);

    /* Shift the error token.  */
    YY_SYMBOL_PRINT ("Shifting", yystos_[yyn],
		     &yysemantic_stack_[0], &yylocation_stack_[0]);

    yystate = yyn;
    goto yynewstate;

    /* Accept.  */
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    /* Abort.  */
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (yychar != yyempty_)
      {
        /* Make sure we have latest lookahead translation.  See comments
           at user semantic actions for why this is necessary.  */
        yytoken = yytranslate_ (yychar);
        yydestruct_ ("Cleanup: discarding lookahead", yytoken, &yylval,
                     &yylloc);
      }

    /* Do not reclaim the symbols of the rule which action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (yystate_stack_.height () != 1)
      {
	yydestruct_ ("Cleanup: popping",
		   yystos_[yystate_stack_[0]],
		   &yysemantic_stack_[0],
		   &yylocation_stack_[0]);
	yypop_ ();
      }

    return yyresult;
  }

  // Generate an error message.
  std::string
  mcmas_parser::yysyntax_error_ (int yystate, int yytoken)
  {
    std::string yyres;
    // Number of reported tokens (one for the "unexpected", one per
    // "expected").
    size_t yycount = 0;
    // Its maximum.
    enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
    // Arguments of yyformat.
    char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];

    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yytoken) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yychar.
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state
         merging (from LALR or IELR) and default reductions corrupt the
         expected token list.  However, the list is correct for
         canonical LR with one exception: it will still contain any
         token that will not be accepted due to an error action in a
         later state.
    */
    if (yytoken != yyempty_)
      {
        yyarg[yycount++] = yytname_[yytoken];
        int yyn = yypact_[yystate];
        if (!yy_pact_value_is_default_ (yyn))
          {
            /* Start YYX at -YYN if negative to avoid negative indexes in
               YYCHECK.  In other words, skip the first -YYN actions for
               this state because they are default actions.  */
            int yyxbegin = yyn < 0 ? -yyn : 0;
            /* Stay within bounds of both yycheck and yytname.  */
            int yychecklim = yylast_ - yyn + 1;
            int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
            for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
              if (yycheck_[yyx + yyn] == yyx && yyx != yyterror_
                  && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
                {
                  if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                    {
                      yycount = 1;
                      break;
                    }
                  else
                    yyarg[yycount++] = yytname_[yyx];
                }
          }
      }

    char const* yyformat = 0;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
        YYCASE_(0, YY_("syntax error"));
        YYCASE_(1, YY_("syntax error, unexpected %s"));
        YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    // Argument number.
    size_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += yytnamerr_ (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
  const short int mcmas_parser::yypact_ninf_ = -1104;
  const short int
  mcmas_parser::yypact_[] =
  {
        98,   508,   113,   184,    72,  1949, -1104,   994,  2014,   908,
     209, -1104, -1104, -1104, -1104,  1242, -1104,   532, -1104,   368,
    1022,   137,  2120,   435, -1104,   908,  1049, -1104, -1104,    59,
     485,   994,   591,   677, -1104, -1104, -1104,   727,  1438,   634,
   -1104,   114,  1783,   922,  1111,  1147,  1177,   336,  2354,   362,
     901,   850,   931,   218,  1225,   485, -1104,   918,   413,  1623,
   -1104,   386,  1354,    93, -1104, -1104, -1104, -1104, -1104, -1104,
   -1104, -1104, -1104,   520,   499,   768,  1290, -1104, -1104, -1104,
   -1104, -1104, -1104,   535,   684,  1234, -1104,   624,   671,  6090,
     901,   931,  1225,  1922,   105,   630, -1104,  4282,   931,  1225,
    1804,  1041,  2760, -1104, -1104,  1051,  2760,   128, -1104, -1104,
   -1104, -1104,  1120,  1202,  7243,  6884, -1104,  2336,  7499, -1104,
   -1104, -1104, -1104,  1877,  1225,  1501,   718, -1104, -1104,  1014,
     394,  1277,   790,   821,  1354,  3017,  3017,   871,   555,  1169,
   -1104,  2119,   386,   491,   386,   764,  1226,   569, -1104, -1104,
   -1104, -1104,   672,   610,  5415,   395,  5473,   107,  5847, -1104,
    5373,  1005,   148,  1124,   415,   915, -1104, -1104, -1104, -1104,
   -1104, -1104, -1104, -1104,   327,   398,  1163, -1104,   733, -1104,
   -1104,   688,   931,  1225,  1225,   821, -1104, -1104, -1104,  1362,
   -1104, -1104,  1225,   821,  1062, -1104, -1104,  2951,  7275,  2535,
   -1104, -1104, -1104,  1947,  7975,  2638, -1104,  3201,  1967,   854,
   -1104,  1197, -1104,  1677,  2760,  2760, -1104,  1021,  1021,  1021,
    1021,  1021,  1021,   854, -1104, -1104, -1104, -1104, -1104, -1104,
     854,   854,   854,   854,   854,   821, -1104, -1104, -1104,  1260,
    1251, -1104, -1104, -1104, -1104,  1335,  1622,  1358, -1104,  1311,
   -1104,  1389,  1517,  1385,  1387,   200,  1675,   610,   395,   749,
   -1104,  1839,  3017,   799,  3017,  1214,  7140, -1104,  6036,  7860,
   -1104, -1104,  7531,  7307, -1104, -1104, -1104,  1516,  1518, -1104,
   -1104, -1104,  3017,  3017,  1270,  1098,  2015,  2121,  1447,  1508,
    3265,  1521,  1612,  6820,   386,   386,  1803, -1104,   272,   467,
    1017, -1104,   703,   222,   395,   773, -1104,  3106,   803,  6665,
    1580,  6665,  6665,  6665,  6665,  6665,  6665,  6665,   278,   278,
     396,   816,   816,   396,   816,  7581, -1104,  5499,   758,  1099,
     842, -1104,  4199,  5557,  1643,  1621,  5557,  5557,  5557,  5557,
    5557,  5557,  5557,  1369,  1369,  1500,  1600,  1600,  1500,  1600,
    6236,  5194,   356,  1015, -1104, -1104,  6750,  5941,  1654,  5941,
    1679,  1742,  1742,  1742,  5941,  5941,  5941, -1104,  6730,  5941,
   -1104, -1104,  1375, -1104,  1538, -1104,  1729,  1547,  1701,   630,
    1605,  1542,  1733,   152,  1640,  1583,   737, -1104, -1104,  1016,
     991,  1124,    71, -1104, -1104,  1134,   261,    71,   304, -1104,
     706, -1104, -1104,  1225,   821,   821,  1675,   821,  1675,  2824,
   -1104, -1104, -1104,  2848, -1104,  2302, -1104,  2565, -1104,  2760,
    1967,   723,   734,  3292,  3383,  3474,  2366,  1021,  6916,  6948,
    6980, -1104, -1104, -1104,  7563,  7595,  7627,   776, -1104, -1104,
    1675, -1104, -1104,  2038, -1104,  1678,   332, -1104, -1104,  1745,
     332,  1427, -1104, -1104,  1389,  1800, -1104,  1158,   332, -1104,
   -1104, -1104,   476,   930,   206,  1794, -1104,   554, -1104,  2009,
    1825,  2056, -1104,   395,   955, -1104,  1012, -1104, -1104,  1766,
    5348, -1104,  7659,  3356,  5356,  8004,  2520,  1779,  1784,  3447,
    2073,   852, -1104,  1788,  1796,   852,   852,   852,   852,   852,
     852,  1293,  1293,  1293,  1293,  1293,  1293,  1883,  3017,  3017,
   -1104,  2207, -1104,  1781,  1859,  1885,   360,   714,  2347, -1104,
    3041, -1104,  1228,  1431,   386,  1444,  1445,   521, -1104,  3538,
    3629,  3720,  1844,   650, -1104, -1104, -1104,  1912,  1720,   323,
    1848,  1017, -1104,  1047, -1104, -1104,  4263,  6723, -1104, -1104,
   -1104,  7910, -1104, -1104,  4290,   904,  1472,  7970,  8353,  8354,
    8371,  8384,  8388,  8406,  6665,  6665, -1104, -1104,    64,   102,
   -1104,  1865,  1891, -1104, -1104, -1104, -1104,  1519,   495,  4171,
   -1104,  1421,  5583,  6665,  6665, -1104,  6665, -1104,  3170,  5641,
    5766, -1104, -1104,  2435,  3197,  1776,   118,  1648,  3045,  3053,
    6330,  6424,  6518,  6612,  8054,  5557,  5557, -1104, -1104, -1104,
   -1104,   117,   242, -1104,  1898,  1925, -1104, -1104, -1104, -1104,
    1670,   884,  2117,   101, -1104,  2629,  5557,  5557,  5557,  5557,
    5557, -1104,  5252,  5557,  5557, -1104,  5557,  5279,  5272,  1973,
   -1104, -1104,  8067,  5614,  1413,   513,  8094,   506,   594, -1104,
    1926,  1929, -1104, -1104, -1104,  8107,  8119,  8121,  2644,    56,
   -1104,  3084,  8138,  6800,  5941,  5941, -1104,  5941, -1104, -1104,
   -1104, -1104, -1104, -1104,  1254,  3043,   870,  3043,  1309, -1104,
   -1104, -1104,  1120,  2181,  6130,  7691, -1104, -1104,  7339,  7012,
   -1104, -1104, -1104,  1879,  1640, -1104,  1014,   847,  2997,  1503,
   -1104, -1104, -1104,  1340,  1943, -1104,  1733,  1640, -1104,  1956,
   -1104,  1959,    60,    60, -1104,  1138,    60,    60,   821,  1675,
    1675, -1104,  1675, -1104,  1768,  2001, -1104, -1104, -1104, -1104,
   -1104, -1104,  1287,  1287, -1104,  1287, -1104, -1104, -1104, -1104,
    1805,   854,   990, -1104, -1104,  3067,   206, -1104, -1104, -1104,
    1116, -1104, -1104, -1104, -1104, -1104, -1104,  2888, -1104,  2600,
   -1104,  2437, -1104,  2911, -1104, -1104, -1104,  3017,  2073,   839,
     956, -1104, -1104,  7892,  7924,  7956,  2002, -1104, -1104,  2401,
    1293,  7371,  7403,  7435, -1104, -1104, -1104,  3811,  3902,  3993,
    2271, -1104,  2672, -1104,   714,  1970,  1674, -1104, -1104, -1104,
   -1104, -1104,   714,   714,   714,   600,   714,   714,   714,  1238,
   -1104, -1104, -1104, -1104, -1104, -1104, -1104, -1104, -1104, -1104,
   -1104,  1297, -1104,   323, -1104,   969,  8341,  1069,  5730,  4354,
   -1104,  4381, -1104, -1104, -1104,  6665,  1237,  3135,   249,   383,
     794,   863,   898,   999, -1104, -1104, -1104, -1104, -1104,  5699,
   -1104,  8407,  8424,  8437,  8451,  1119,  5530,  1151,  6183, -1104,
    3261, -1104,  3288, -1104, -1104, -1104, -1104, -1104,  5557,  2855,
    2921,  1184,  1200,  1264,  1299,  1305,  1352, -1104, -1104, -1104,
   -1104, -1104, -1104, -1104, -1104,  5347, -1104,  8150,  3147,  8172,
    8174,  8197,  8201,  8219,  8237,  8241,  1371,  2721,  1376,  1950,
   -1104,  5726, -1104,  5941,  5941,  5793, -1104,  5941,  5941, -1104,
   -1104,  5941,  1378,  1390,  1407,  1428, -1104, -1104, -1104,  6818,
   -1104,  8264,  8266,  8288,  8291,  1498,  1975,  3565,  7996, -1104,
    7467,  4173,  8073,  8025,  1981,  1987,  3656,  1562,  1028, -1104,
   -1104,  2999,  3043,  3043, -1104,  1028,  1028,  1028,  1028,  1028,
    1028,  1585,  1585,  1585,  1585,  1585,  1585,  1503, -1104,  1626,
    2005, -1104,  1389,  1692,  1154,   409,  1837, -1104, -1104,  1640,
    1503, -1104, -1104, -1104, -1104,  1956, -1104, -1104, -1104,  1675,
   -1104, -1104, -1104,  1457,   759,  2004, -1104, -1104, -1104, -1104,
    1044,  2174,  3067,  1529,  3067,  7710,  2336,  2194, -1104, -1104,
    2122,  2767, -1104, -1104, -1104, -1104,  2042,  2043, -1104, -1104,
   -1104, -1104,  2046,  2055, -1104,   338,   819,   493, -1104,  1297,
    6665,  6665,  5387,  6665,  6665,  6665,  5387,  6665,  6665,  6665,
    6665,  6665,  6665,  6665,  6665,  6665,  6665,  6665,  6665,  6665,
    5557,  5557,  5167,  5557,  5557,  5557,  5167,  5557,  5557,  5557,
    5557,  5557,  5557,  5557,  5557,  5557,  5557,  5557,  5557,  5557,
    5557,  5557,  5557,  5557,  5941,  5941,  5941,  5941,  5941,  5941,
    5941,  5941,  8310,  1937,  2221,  2285,  5177,  5435,  5941,  5941,
    5941,  5941,  5941,  5941,  5941,  5941, -1104,  2711, -1104, -1104,
   -1104,  2735, -1104,  2501, -1104,  2238, -1104, -1104, -1104,  3043,
    1562,  1072,  1076,  3747,  3838,  3929,  7757,  7776,  7795,  2959,
   -1104, -1104,  1903,  1585,  7044,  7076,  7108, -1104, -1104, -1104,
    1837,  1697,  1182, -1104, -1104,  1389, -1104,  1398,   332,   647,
     638,  2089,  1379,   612, -1104,  2116,  2069, -1104,  1503,  1837,
   -1104, -1104, -1104, -1104, -1104, -1104,  2049,  7174,  2535,  4020,
    2638,  4175,  2052,  2058,  4084,    84,   110,   854,  3067,  3067,
    3067, -1104,  2072,  2077,  2079,  2088, -1104, -1104, -1104, -1104,
   -1104, -1104, -1104,  5494,  5708,  6249,  6343,  6437,  6531,  6641,
    6658,  1886,  6685,  2482,  6732,  6832,  7309,  7373,  7437,  7517,
    7645,  7831,  7833,  7874,  8459,  8473,  8486,  8500,  8503,  8504,
    8506,  2843,  8526,  8529,  5176,  8530,  8544,  8549,  8559,  8564,
    8579,  8582,  8584,  8594,  8599,  8318,  5261,  8602,  8604,  8617,
    8629,  8635,  8637,  8655,  8659,  5820, -1104,  5887, -1104,  5914,
   -1104,  5981, -1104,  6008, -1104,  6075, -1104,  8660,  8673,  8678,
    8679,  8693,  8713,  8719,  8723,  2867,  3263, -1104, -1104,  1287,
   -1104,  1939,  1028,  1597,  1597,   638,  1127, -1104, -1104, -1104,
   -1104, -1104,  1837, -1104, -1104,  2934, -1104,  2973, -1104, -1104,
   -1104,  2101,  1530, -1104,    34,  1546,  4266,  4111,  4267,  4358,
   -1104, -1104, -1104, -1104,  4445, -1104,  4472, -1104,  4536, -1104,
    4563, -1104,  4627, -1104,  4654, -1104,  4718, -1104,  4745, -1104,
    4809, -1104,  4836, -1104,  4900, -1104,  4927, -1104,  4536, -1104,
    4563, -1104,  4718, -1104,  4745, -1104,  4991, -1104,  5018, -1104,
    5082, -1104,  5109, -1104,  3352, -1104,  3379, -1104,  3443, -1104,
    3470, -1104,  3534, -1104,  3561, -1104,  3625, -1104,  3652, -1104,
    3716, -1104,  3743, -1104,  3807, -1104,  3834, -1104,  3898, -1104,
    3925, -1104,  3443, -1104,  3470, -1104,  3625, -1104,  3652, -1104,
    3989, -1104,  4016, -1104,  4080, -1104,  4107, -1104,  3716, -1104,
    3834, -1104,  6102, -1104,  6169, -1104,  6196, -1104,  6263, -1104,
    6290, -1104,  6357, -1104,  6384, -1104,  6451, -1104,  6196, -1104,
    6263, -1104,  6384, -1104,  6451, -1104,  6478, -1104,  6545, -1104,
    6572, -1104,  6639, -1104, -1104, -1104,  1775,  1732,  1597,   912,
    1581,  1597,  7826,  6130,  2219,  2283, -1104, -1104, -1104,  2110,
    2111,  2114, -1104,  2118,  2132,  2134,  7209,  7996,  4448,  8073,
    4177,   298,   201,  2135,  2139,  4449,   473,  1272,  1028,   670,
    1597,  1597, -1104,  2524, -1104, -1104, -1104, -1104, -1104, -1104,
   -1104,  2775, -1104,  2799, -1104,  2143,  2220,  4539,    37,  1598,
   -1104, -1104,  1597,  2148,  1658, -1104,   358,  1676,  4357,  4540,
    4630,  4631, -1104,  2151,  2152, -1104,  2153,  2158, -1104,  2159,
    2165,  2166, -1104,  2183,  2196, -1104, -1104, -1104, -1104, -1104,
   -1104, -1104, -1104, -1104
  };

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
  const unsigned short int
  mcmas_parser::yydefact_[] =
  {
         0,     6,     0,     0,     0,     0,     2,     0,     0,     0,
       0,   151,    32,    33,    31,     0,     1,    34,     3,    51,
       0,     0,     0,   153,   154,     0,   164,   437,   152,     0,
       0,     0,     0,     0,    49,    50,    48,    55,     0,     0,
      57,     0,   111,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   452,     0,     0,   465,
     464,     0,     0,     0,     4,     5,    53,    54,    52,    59,
      58,    56,   188,     0,   110,   189,     0,    62,    60,    97,
      95,   109,   108,    67,     0,     0,    69,     0,     0,   111,
       0,     0,     0,    74,     0,     0,   104,   111,     0,     0,
       0,     0,     0,   418,   419,     0,     0,     0,   416,    91,
     417,   117,     0,     0,     0,     0,   285,     0,     0,   296,
     299,   289,   415,   191,     0,   195,     0,   201,   197,     0,
     208,     0,     0,     0,     0,     0,     0,   441,     0,     0,
     442,     0,     0,     0,     0,     0,     0,   529,   528,   501,
     607,   703,     0,     0,     0,     0,     0,     0,     0,    30,
      98,     0,     0,     0,     0,     0,   190,   185,   186,   187,
     184,    65,    66,    64,     0,     0,    67,    68,     0,    71,
      70,   110,     0,     0,     0,     0,   100,   101,    99,    86,
     103,   110,     0,     0,     0,   113,    91,     0,     0,     0,
     298,   114,   112,     0,     0,     0,    92,     0,     0,     0,
     297,   115,   116,     0,     0,     0,   122,     0,     0,     0,
       0,     0,     0,     0,   379,   381,   383,   380,   382,   384,
       0,     0,     0,     0,     0,     0,   194,   193,   192,   195,
       0,   196,   206,   207,   205,     0,     0,     0,   216,     0,
     222,     0,     0,   131,     0,     0,     0,     0,     0,     0,
      17,     0,     0,     0,     0,     0,     0,   433,     0,     0,
     324,   327,     0,     0,   351,   426,   355,     0,     0,   439,
     440,   438,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   474,   506,     0,
       0,   508,     0,   529,     0,     0,    24,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   534,     0,     0,   608,
       0,    27,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   704,    28,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   780,     0,     0,
     771,   772,     0,   169,     0,    96,   170,     0,    74,     0,
     111,     0,     0,     0,     0,   176,     0,   180,   178,     0,
      98,     0,    90,    77,    87,     0,     0,    76,     0,    75,
       0,    73,    72,     0,     0,     0,     0,     0,     0,     0,
     257,   287,   301,     0,   256,     0,   286,     0,   300,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   284,   282,   283,     0,     0,     0,     0,   295,   294,
       0,   203,   202,     0,   210,     0,     0,   211,   209,   231,
       0,     0,   213,   223,     0,   212,   215,     0,     0,   129,
     130,   128,   135,     0,     0,     0,   137,     0,   138,     0,
      38,     0,    46,     0,     0,    11,     0,    14,    16,     0,
       0,   326,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   325,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     445,     0,   444,     0,     0,     0,     0,     0,     0,   477,
       0,   476,     0,     0,     0,     0,     0,     0,   470,     0,
       0,     0,   471,     0,   504,   505,   503,   513,     0,     0,
     506,     0,   507,     0,    21,    22,     0,     0,   531,   596,
     597,     0,   532,   530,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   589,   590,     0,     0,
     591,     0,     0,   592,   593,   594,   595,     0,     0,     0,
     535,     0,     0,     0,     0,   536,     0,    25,     0,     0,
       0,   687,   688,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   678,   680,   679,
     681,     0,     0,   682,     0,     0,   683,   684,   685,   686,
       0,     0,     0,     0,   613,     0,     0,     0,     0,     0,
       0,   693,     0,     0,     0,   614,     0,     0,     0,   780,
     777,   778,     0,     0,     0,     0,     0,     0,     0,   773,
       0,     0,   774,   775,   776,     0,     0,     0,     0,     0,
     709,     0,     0,     0,     0,     0,   710,     0,   171,   166,
     167,   168,   165,   106,     0,     0,     0,     0,     0,   421,
     425,   120,     0,     0,     0,     0,   310,   313,     0,     0,
     339,   420,   343,   191,     0,   204,     0,   208,     0,     0,
     175,   174,   173,   176,     0,   177,     0,     0,    93,    85,
      83,     0,     0,     0,    90,     0,     0,     0,     0,     0,
       0,    44,     0,    42,     0,     0,    45,   229,   230,   228,
     245,   242,     0,     0,   214,     0,   133,   134,   132,   146,
       0,     0,   135,   136,   139,     0,     0,    36,    37,    35,
       0,     8,    10,    13,   431,   329,   353,     0,   454,     0,
     328,     0,   352,     0,   453,   432,   430,     0,     0,     0,
       0,   429,   428,     0,     0,     0,     0,   323,   322,     0,
       0,     0,     0,     0,   350,   348,   349,     0,     0,     0,
       0,   449,     0,   448,     0,    94,     0,   436,   434,   499,
     435,   497,     0,     0,     0,     0,     0,     0,     0,     0,
     472,   467,   468,   469,   466,   511,   512,   510,   524,   525,
     526,     0,   521,     0,    19,     0,     0,     0,     0,     0,
     574,     0,   573,   602,   601,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   605,   604,   603,   600,   599,     0,
     538,     0,     0,     0,     0,     0,     0,     0,     0,   621,
       0,   663,     0,   662,   620,   619,   698,   697,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   701,   700,   699,
     696,   695,   610,   611,   609,     0,   616,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     717,     0,   759,     0,     0,     0,   758,     0,     0,   716,
     715,     0,     0,     0,     0,     0,   706,   707,   705,     0,
     712,     0,     0,     0,     0,     0,     0,     0,     0,   312,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   311,
     119,     0,     0,     0,   125,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   199,     0,
       0,   225,     0,     0,   131,     0,     0,   182,   181,     0,
       0,    89,    88,    81,    79,    84,    82,    80,    78,     0,
      40,    43,    41,   235,     0,     0,   241,   240,   236,   143,
       0,     0,     0,     0,     0,     0,     0,     0,   144,     7,
       0,     0,   498,   496,   494,   495,     0,   435,   493,   491,
     489,   490,     0,   435,   488,     0,     0,     0,   518,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   423,     0,   268,   315,
     341,     0,   267,     0,   314,     0,   340,   424,   422,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     309,   308,     0,     0,     0,     0,     0,   338,   336,   337,
       0,     0,     0,   218,   226,     0,   220,     0,     0,   150,
       0,     0,     0,     0,   248,   159,     0,   161,     0,     0,
      39,   233,   244,   234,   232,   243,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   141,     0,     0,     0,     0,   527,   515,   523,   516,
     514,   522,   519,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   722,     0,   719,     0,
     727,     0,   720,     0,   718,     0,   726,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   160,   219,     0,
     150,     0,     0,     0,     0,     0,   135,   246,   249,   157,
     158,   156,     0,   163,   367,     0,   357,     0,   356,   368,
     366,     0,     0,   377,     0,     0,     0,     0,     0,     0,
     492,   487,   486,   485,     0,   561,     0,   558,     0,   553,
       0,   550,     0,   559,     0,   557,     0,   551,     0,   549,
       0,   545,     0,   542,     0,   543,     0,   541,     0,   553,
       0,   550,     0,   551,     0,   549,     0,   569,     0,   566,
       0,   567,     0,   565,     0,   650,     0,   647,     0,   642,
       0,   639,     0,   648,     0,   646,     0,   640,     0,   638,
       0,   626,     0,   623,     0,   631,     0,   624,     0,   622,
       0,   630,     0,   642,     0,   639,     0,   640,     0,   638,
       0,   658,     0,   655,     0,   656,     0,   654,     0,   626,
       0,   624,     0,   746,     0,   743,     0,   738,     0,   735,
       0,   744,     0,   742,     0,   736,     0,   734,     0,   738,
       0,   735,     0,   736,     0,   734,     0,   754,     0,   751,
       0,   752,     0,   750,   238,   147,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   148,   162,   374,     0,
       0,     0,   375,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   252,     0,   251,   376,   371,   372,   373,   370,
     396,     0,   386,     0,   385,     0,     0,   424,     0,     0,
     397,   395,     0,     0,     0,   406,     0,     0,     0,     0,
       0,     0,   410,     0,     0,   411,     0,     0,   403,     0,
       0,     0,   404,     0,     0,   412,   408,   409,   407,   405,
     400,   401,   402,   399
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  mcmas_parser::yypgoto_[] =
  {
     -1104, -1104, -1104,  2268, -1104,  -342, -1104, -1104,  2233,  2244,
   -1104, -1104,  2198, -1104,    16,   -47,  1889,   -51,   -32,   -66,
    2240,  2125,  -126,  -107,   636,  1900, -1104, -1104,  -669,  -466,
    -146, -1104,  1829,  -431, -1103,  2284, -1104, -1034,   599, -1104,
    1908, -1104, -1104,  -135,  -123,   451,  -357,  1915,  -367,  -237,
      94,  -653, -1104, -1104,  -245,  -715,  2059,  1341,  -239,  -437,
    -887, -1104,  1171,   595,  -260,    44,  -173,  1741,   -91,  -188,
    1617,   -84,  -285,  -867,  1020,  -659,  -199,  -428,  1646,  -229,
    -289,  -861,   944,  -165,  -426,  1588,  -737,  -264,  -781, -1104,
      89, -1104, -1104,  -327, -1104, -1104,  2280, -1104,   -77, -1104,
   -1104,  2265,    99, -1104,  2020,  2201,  1795,  1319, -1104,  1528,
    1095, -1104,  2012,   -60, -1104,  2034,  1327,  1459,   455, -1104,
   -1104,   -82, -1104, -1104,  1435,  2010,  1491,  1590,   -69, -1104,
   -1104,  -131, -1104, -1104, -1104, -1104,  1998,  1659,  -120
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  mcmas_parser::yydefgoto_[] =
  {
        -1,     4,     5,     6,     7,   472,     8,    21,    40,    22,
      41,    47,    86,    48,    87,    88,   395,   680,    49,    96,
      50,   163,    51,   111,    52,   382,   112,   682,   255,   466,
     256,   467,   468,   469,  1132,     9,    10,  1137,    11,   164,
     388,   165,   389,    53,   128,    54,   384,   129,   132,   248,
     133,   699,   249,   960,   446,   986,   250,   961,   251,   732,
     966,  1133,  1134,   197,   927,   114,   115,   116,   117,   118,
     119,   120,   684,   685,   686,   687,   268,   269,   270,   271,
     688,   689,   690,   272,   273,   274,  1277,   232,  1469,   121,
     691,   692,   276,   799,    29,   140,    30,    58,   787,    61,
     297,    62,   529,   152,   301,   153,   539,  1018,   302,   821,
     822,   154,   326,   155,   327,   566,   549,   550,   851,   156,
     624,   157,   351,   352,   607,   608,   591,   592,   892,   158,
     660,   159,   368,   369,   370,   371,   640,   641,   921
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const short int mcmas_parser::yytable_ninf_ = -782;
  const short int
  mcmas_parser::yytable_[] =
  {
       110,   743,   450,   260,   498,   212,   241,   458,   997,   199,
     454,   205,   452,   733,   456,   929,   200,   698,   987,   939,
     988,   735,   306,   210,   331,   694,   355,  1251,   383,   190,
     965,   162,   481,   740,   707,   434,   492,   381,   372,   406,
     178,   957,   435,   436,   428,   429,   430,   408,   178,   110,
    1421,   110,   259,  1474,   970,   110,   110,   917,   277,   278,
      56,   795,   480,   484,   721,    95,   723,   773,   774,   775,
    1120,   305,    16,   330,   258,   781,   782,   783,  1106,  1107,
    1108,   110,   838,  1139,   267,   267,  1247,   353,   105,   440,
    1114,  1115,  1116,   304,   160,   -94,   482,   485,   726,     1,
    1271,     2,   883,   199,   918,  1263,   187,   -29,   354,  1422,
     200,  1274,  1475,    45,    13,    37,  1272,   421,   422,   864,
     840,   683,    38,   396,   400,   188,   475,   477,   478,   208,
     161,    14,   865,   162,    57,   871,   109,   209,    37,   839,
     122,   437,  1275,   110,   198,    38,   204,   708,   884,   378,
     103,   104,  1416,   695,   199,   151,   105,   110,   110,  1273,
     146,   200,   110,   110,   110,     3,   110,   110,   110,   110,
     110,   110,   110,   544,   545,   474,   476,   841,   379,   110,
     110,   110,   110,   110,   483,   486,   185,   489,  -154,   122,
     801,   122,   872,   193,   110,   122,   122,   473,   110,   587,
      15,   462,  1458,   108,   109,   513,   514,   739,   463,   464,
     267,   267,    39,   267,   267,   464,   498,   734,   235,   125,
     498,   122,   543,    85,   275,   275,  1106,   127,  1417,   434,
     126,   267,   267,  1459,  1114,  -608,   642,   644,   198,   646,
     286,   287,   428,   290,   655,   656,   657,   383,   661,   662,
    1020,  1262,   198,   204,  1149,  1151,   383,  1154,   719,   720,
     873,   722,   712,   593,   595,   381,   929,   598,   599,   600,
     601,   602,   603,   604,   681,   465,  1098,   404,   405,   564,
    -520,   465,   625,   122,    31,   713,   407,   565,   965,   198,
    1021,   769,   770,   127,  -704,  -704,  -704,   122,   122,   776,
     929,   965,   122,   122,   122,   714,   122,   122,   122,   122,
     122,   122,   122,   673,  1455,   998,  1138,   874,   534,   122,
     122,   122,   122,   122,   818,   482,   485,   698,   392,   421,
    1456,   773,   178,   730,   122,   781,   200,    83,   122,  1166,
     698,   819,   751,   752,    84,   753,  -517,  -520,   393,   969,
     275,   275,   199,   275,   275,   105,   819,   626,   110,   200,
     199,   795,   110,    93,   110,   627,   110,   200,   110,   110,
      94,   275,   275,  1457,  1481,   110,   110,   980,   981,   394,
     982,  1167,   103,   104,  1032,   930,   933,   141,   105,   928,
     932,   750,   110,   530,   531,   142,   329,   568,   820,   397,
     110,  -217,   394,   109,   143,   569,   110,   731,    34,   398,
    1129,    85,   824,   820,   137,   931,   385,   936,  1130,   399,
     948,   138,  1278,  1279,  1033,   144,   105,   386,   628,   629,
     630,   788,   789,  1482,   242,   796,   109,    85,   963,   267,
     267,   929,   150,   151,   267,   267,   267,   267,   267,   267,
     267,   267,   267,   267,   267,   267,   267,   267,   267,   962,
     267,   145,   929,   929,   198,   797,   797,  1002,   535,   965,
     724,   725,  1414,  1415,   109,  1003,  1004,  1005,  1008,  1009,
    1010,  1011,  1014,   736,  1131,  -140,    59,   198,   139,  1463,
     387,  -146,   288,  -146,  1166,   198,   846,   718,   122,    92,
     -61,    99,   122,   124,   122,  1464,   122,   -61,   122,   122,
    -155,   819,   -34,   536,   909,   122,   122,   642,   644,   593,
     595,   166,   810,   642,   896,   593,    12,   910,   847,   848,
      60,   167,   122,   289,  1404,   -47,   869,   870,   642,   481,
     122,   183,   184,   -74,   922,   923,   122,   924,  1465,   192,
      12,  -140,  -153,   593,   171,   742,   280,   887,   888,   889,
     890,   891,   463,   464,   893,   894,   811,   895,   820,   769,
    -502,   383,   979,   958,   -61,   940,  -153,  -502,   -86,   275,
     275,   912,  -608,  -155,   275,   275,   275,   275,   275,   275,
     275,   275,   275,   275,   275,   275,   275,   275,   275,   281,
     275,   795,   698,   482,  -509,   798,   798,  -155,    28,   328,
     -74,   303,   898,  1256,  1000,  1001,  -509,  -509,  1006,   999,
     463,  1130,   103,   104,    28,   176,  1428,  1430,   105,   465,
    1435,   189,    84,   403,    64,    69,   930,  1140,    94,  1250,
     928,  -704,  -704,  -704,  -502,   148,   113,  1130,   930,   933,
     990,   813,  1101,  1102,   996,  -250,  -250,   150,   151,  1470,
    1471,   973,   974,  1109,   948,   977,   978,  1257,   948,   913,
     930,  1407,   179,   298,   928,  1007,   109,    70,  -254,  1408,
     299,  1103,  1104,  1105,    91,   172,    98,  1131,  1409,   -96,
     110,  1249,   103,   104,   110,   814,   -96,   203,   105,    85,
     963,   207,  1410,   173,   540,    85,   267,   716,   267,  1411,
     267,   299,   267,  1131,   180,   795,   267,   267,  1128,   237,
      65,  1125,  -250,  1123,   223,  1126,   182,   252,   267,   267,
     717,    66,  1157,   412,   401,   417,   103,   104,   701,   267,
     678,   267,   105,   797,   418,  1412,   109,   300,   929,   -18,
     354,   797,   797,   797,   797,   797,   797,   797,   797,   582,
    1143,   238,   551,   -96,   555,   291,   557,   558,   559,   560,
     561,   562,   563,   -23,   354,   583,   402,   223,   541,   168,
     702,  1072,   581,  1073,  1074,  1075,  -265,  1076,  1077,   800,
     109,   245,   230,  -265,   231,  1024,   584,   151,   246,   102,
     487,   585,  1144,   230,   552,   231,   292,   586,   423,   424,
     425,   930,   103,   104,  -265,  1101,  -265,   571,   105,  -265,
    1169,   151,   253,  1245,  1246,   572,   247,  1103,   254,   106,
     122,  1103,   930,   930,   122,  1025,   928,   928,   553,  1103,
     495,   488,   -26,   354,   252,   230,   275,   231,   275,   755,
     275,   100,   275,   768,  -221,   420,   275,   275,   101,   102,
     107,   491,  1170,   209,  1034,   108,   109,  1103,   275,   275,
     263,   934,   103,   104,   103,   104,   103,   104,   105,   275,
     105,   275,   105,   798,  1157,   879,  1157,   242,  1248,   106,
     151,   798,   798,   798,   798,   798,   798,   798,   798,  1036,
    1148,  1150,    97,   996,  1035,   831,    43,   200,   496,    26,
     497,    24,   935,  1431,   832,   279,   390,   880,   881,   135,
     107,   583,   265,    75,   107,   108,   109,   266,   109,   108,
     109,   737,   123,   136,    46,    45,    43,   738,    76,  1037,
     110,   110,   584,   110,  1217,  1218,  1219,  1220,  1221,  1222,
    1223,  1224,    27,   586,  1432,   -12,   354,   759,  1237,  1238,
    1239,  1240,  1241,  1242,  1243,  1244,   760,  1406,  1413,  1413,
    1020,  1193,  1194,  1195,  1196,  1197,  1198,  1199,  1200,  1201,
    1202,  1203,  1204,  1205,  1206,  1207,  1208,  1209,  1210,  1211,
    1212,  1213,  1214,  1215,  1216,    19,  -107,   736,    20,  -142,
    1038,   551,   555,   151,   423,  -146,   376,  -146,   423,   551,
    1021,   556,   -15,   354,   423,   239,   632,   703,   537,   836,
     837,   377,   426,    35,  -107,   496,   126,   497,   386,  1100,
     427,   375,   633,   538,   551,   198,   204,   938,   852,   853,
    1039,   854,   201,   103,   104,   223,   676,   -20,   354,   105,
     103,   104,   423,   634,  -145,   240,   105,   704,   635,  -145,
     151,  -145,    36,   194,   636,  -142,  1276,   996,   996,   996,
    1024,   102,   -94,   945,   202,   -94,   -94,  1093,   -94,  -266,
     122,   122,  1089,   122,   103,   104,  1094,   -94,   -94,   -94,
     105,   -94,   -94,   -94,  -443,   151,   108,   109,   678,   516,
    -266,   106,  -266,   679,   109,  -266,   110,   110,   110,   110,
    1025,   556,    77,   230,   517,   231,    -9,   354,   930,   933,
    1040,   211,  1427,  1429,  -155,   380,  1413,   206,   101,    43,
     -94,   -94,   107,   -94,   736,   709,  -255,   108,   196,   975,
     292,   946,  -150,   947,  -150,   946,   710,   947,    79,  1438,
     976,    78,  1044,  1468,  1413,  1413,  1413,    46,  1413,   194,
    1041,   597,  -247,  1438,   151,  1438,  1413,   102,  1413,   727,
     282,  -704,  -704,  -704,   996,   711,   996,  1413,    81,   711,
     103,   104,   171,  1121,   283,  1040,   105,    80,   444,  -212,
    -239,   675,  1045,   597,   459,   -94,   -94,   106,   -94,  -277,
     676,  1054,  -255,   213,   103,   104,   -86,   -94,   -94,   -94,
     105,   -94,   -94,   -94,   110,   490,   110,    82,  -239,   214,
    -277,   677,   445,   491,   926,  1041,   130,   293,   107,   802,
     195,   131,   263,   108,   109,   174,   103,   104,  1028,   795,
     215,  1055,   105,   294,   803,   216,   122,   122,   122,   122,
     -94,   -94,   678,   -94,   583,   925,  1012,   679,   196,  -115,
     103,   104,  -127,   675,   295,  1044,   105,   -94,   -94,   296,
     -94,  -277,   676,  1466,   175,   584,   103,   104,   243,   -94,
     -94,   -94,   105,   -94,   -94,   -94,   586,   195,   983,   266,
     109,   169,  -277,   677,   779,  1029,   926,  -277,  1015,   984,
    1056,   170,   780,   236,  1467,  1045,  1058,    32,    33,  1016,
     937,   263,   451,  1013,   109,   103,   104,   244,   938,   246,
     102,   105,   -94,   -94,   678,   -94,   442,   676,   985,   679,
     196,   103,   104,   103,   104,   441,   443,   105,  1017,   105,
    1057,   444,  -212,  -224,   102,   515,  1059,   247,   -94,   -94,
     106,   -94,  -266,  1060,   122,   147,   122,   103,   104,   449,
     -94,   -94,   -94,   105,   -94,   -94,   -94,  -102,   266,   109,
     605,  -224,  1064,  -266,   106,   445,   663,  1068,   606,  1078,
    1253,   107,   186,   700,   679,   109,   108,   109,   460,   148,
     455,  1080,   664,  1061,  1254,  -102,  1255,   246,   445,   925,
     149,   150,   151,   -94,   -94,   107,   -94,   675,  1082,   727,
     108,   196,  1065,   665,   905,   967,   676,  1069,   666,  1079,
     103,   104,   849,   906,   667,   459,   105,   461,   443,  1084,
     664,  1081,   804,   444,  -212,  -237,   102,   677,   583,    67,
     -94,   -94,    68,   -94,  -266,   806,   808,   805,  1083,   103,
     104,   665,   -94,   -94,   -94,   105,   -94,   -94,   -94,   584,
     807,   809,   667,  -237,   850,  -266,   106,   445,   678,  1085,
     586,   907,   908,   679,   109,  1173,  1174,  1175,  1176,  1177,
    1178,  1179,  1180,  1181,  1182,  1183,  1184,  1185,  1186,  1187,
    1188,  1189,  1190,  1191,  1192,   -94,   -94,   107,   -94,   925,
    1141,   611,   108,   196,   964,   833,   834,   675,   -94,   612,
     254,   -94,   -94,  -204,   -94,  -277,   676,   507,   457,   511,
     103,   104,   522,   -94,   -94,   -94,   105,   -94,   -94,   -94,
    1152,  1419,  1142,   508,   214,   508,  -277,   677,  -277,   668,
     926,  -277,  -204,   674,   236,  1153,  1420,  1423,   671,   669,
     101,   675,   844,   845,   509,   215,   509,   445,   672,   510,
     676,   512,  1424,  1100,   103,   104,   -94,   -94,   678,   -94,
     105,   938,   -94,   679,   196,   -94,   -94,   -94,   -94,   -94,
     676,   677,  1433,   523,   103,   104,  1112,   -94,   -94,   -94,
     105,   -94,   -94,   -94,  1113,  -183,   525,  1434,  1407,  1476,
     -94,   614,   -94,   676,   926,   -94,  1408,   103,   104,   615,
    -121,  -200,   678,   105,  1477,  1409,    72,   679,   109,   103,
     104,    73,   556,   447,  -183,   105,   700,  1121,   448,  1410,
     -94,   -94,   678,   -94,  -227,   675,  1411,   679,   196,   -94,
     -94,   697,   -94,  -277,   676,   191,   131,   570,   103,   104,
     575,   -94,   -94,   -94,   105,   -94,   -94,   -94,  -475,  1479,
     679,   109,  -227,   597,  -277,   677,   445,   678,   926,  -475,
    -475,  -475,  1412,   109,  1480,   806,   470,  1483,   194,   728,
     647,   866,   867,   471,  -435,  -123,   102,   526,   648,   729,
     807,  -435,  1484,  1127,   -94,   -94,   678,   -94,   925,   103,
     104,   679,   196,   877,   878,   105,   675,   -94,   727,   942,
     -94,   -94,  -435,   -94,  -277,   676,   106,  -435,   596,   103,
     104,   816,   -94,   -94,   -94,   105,   -94,   -94,   -94,   645,
     943,   817,   445,  1407,   693,  -277,   677,  -277,    43,   926,
     670,  1408,   -94,   650,   -86,   -94,   -94,   107,  1425,  -414,
    1409,   651,   108,   109,   103,   104,   727,   -94,   -94,   -94,
     105,   -94,   -94,   -94,  1410,   -94,   -94,   678,   -94,   217,
    -414,  1411,   679,   196,   926,  -414,   945,   862,   411,   609,
     573,   574,   790,   576,   -63,  -149,   863,   631,  -105,  -198,
    -149,   -63,  -149,   633,    72,  -191,   218,   219,   508,    73,
     -94,   -94,   678,   -94,   532,   194,   444,  1426,   196,  -115,
     741,   533,  -124,   102,   634,   989,  -105,   -94,   -94,   509,
     -94,  -266,   746,    74,   791,   636,   103,   104,   747,   -94,
     -94,   -94,   105,   -94,   -94,   -94,   613,   195,  1135,   618,
     261,   754,  -266,   106,   946,  1136,   947,  -266,   262,   -94,
     438,   439,   -94,   -94,   765,   -94,  -463,   263,   -63,   766,
     792,   103,   104,   771,   -94,   -94,   -94,   105,   -94,   -94,
     -94,   772,   -94,   -94,   107,   -94,   508,  -463,   264,   108,
     196,   479,  -463,  -198,   261,  -200,   794,  1300,    72,   812,
      72,  -447,   262,    73,   534,    73,  1301,   509,  1117,  1118,
    1119,   263,   793,   583,  1112,   103,   104,   -94,   -94,   265,
     -94,   105,  1113,   -94,   266,   196,   -94,   -94,   -94,   -94,
     -94,   676,   264,   815,   584,   103,   104,  -102,   -94,   -94,
     -94,   105,   -94,   -94,   -94,   586,   616,   617,  1227,   619,
     842,   -94,   186,   -94,  -579,   926,   -94,  1228,   413,  1405,
      17,  1070,     2,   265,   664,  -102,  1255,   414,   266,   109,
    -780,   431,   432,   433,   214,   -86,   843,  -780,   420,  1110,
    1111,   -94,   -94,   875,   -94,   665,   209,   -94,   679,   196,
     -94,   -94,   -94,   -94,   -94,   215,   667,   900,  -780,   103,
     104,  1071,   -94,   -94,   -94,   105,   -94,   -94,   -94,  -780,
     876,   914,   415,   495,   915,   -94,  1122,   -94,  -780,  -780,
     -94,   416,  -462,   246,   675,    23,   518,    24,   968,  -462,
     652,   653,   654,   676,   745,   519,   746,   103,   104,   218,
     219,   971,   294,   105,   972,   -94,   -94,   107,   -94,   194,
    -462,   247,   108,   196,   677,  -462,   708,   102,   -94,   727,
    1086,   -94,   -94,   295,   -94,  -266,  1097,   748,  -484,   749,
     103,   104,  1098,   -94,   -94,   -94,   105,   -94,   -94,   -94,
    1260,   496,  1261,   497,   768,   678,  -266,   106,  -266,  1145,
     679,   109,   491,   -94,  1162,  1163,   -94,   -94,  1164,   -94,
     -94,   263,   784,   785,   786,   103,   104,  1165,   -94,   -94,
     -94,   105,   -94,   -94,   -94,  1252,   -94,   -94,   107,   -94,
    1168,   -94,  1171,   108,   196,   479,   -94,  -612,   588,  1259,
     141,    42,   520,   501,  1264,    43,   589,  1269,   142,  -500,
     334,   521,   756,  1270,  -702,   335,  -500,   143,   294,    44,
      45,   -94,   -94,   265,   -94,   777,   778,  1280,   266,   196,
     502,   503,  1281,    46,  1282,  -702,   336,  -500,   144,   295,
    -702,   284,  -500,  1283,   882,  -612,  -702,   337,   338,   339,
     340,   341,   342,   343,   344,   991,  1418,   345,   346,   347,
     348,   349,   941,   992,   -94,  1445,  1446,   -94,   -94,  1447,
    1146,  -378,   590,  1448,   285,  1158,   103,   104,   942,   -94,
     -94,   -94,   105,   -94,   -94,   -94,   993,  1449,   261,  1450,
    1460,  1159,  -378,   994,  1461,  -446,   262,  -378,  1472,   943,
    1439,  1473,  1229,  1478,   944,   263,  1485,  1486,  1487,   103,
     104,  1230,  1160,  1488,  1489,   105,  1440,  1161,   664,  1112,
    1490,  1491,   -94,   -94,   107,   -94,   264,  1113,  -342,  1147,
     196,  -342,  -342,  -342,  -342,  -342,   676,  1441,  1492,   665,
     103,   104,  1442,  -342,  -342,  -342,   105,  -342,  -342,  -342,
     667,  1493,   261,    18,    71,    63,  -342,   265,  -342,  -451,
     262,  -342,   266,   109,  1443,   177,  1231,   715,    90,   263,
     391,   706,    25,   103,   104,  1232,   744,   705,   696,   105,
    1440,  1124,   664,   426,  1258,    55,  -342,  -342,   453,  -342,
     264,   427,  -288,   679,   109,  -288,  -288,  -288,  -288,  -288,
     134,  1441,   542,   665,   103,   104,  1444,  -288,  -288,  -288,
     105,  -288,  -288,  -288,   667,   257,   823,   223,  1172,   580,
    -288,   265,  -288,  -764,  -764,  -288,   266,   109,   141,   224,
     225,  1019,   226,   567,   610,    89,   142,  -479,   649,    43,
       0,   227,   228,   229,  -479,   143,     0,   426,     0,     0,
    -288,  -288,     0,  -288,    45,   427,   -94,   108,   109,   -94,
     -94,   -94,   -94,   -94,     0,  -479,   144,    46,   103,   104,
    -479,   -94,   -94,   -94,   105,   -94,   -94,   -94,     0,     0,
       0,     0,   779,     0,   -94,   230,   -94,   231,     0,   -94,
     780,   -94,     0,     0,   -94,   -94,     0,   -94,   -94,   263,
       0,     0,   145,   103,   104,     0,   -94,   -94,   -94,   105,
     -94,   -94,   -94,     0,   -94,   -94,   860,   -94,   779,   -94,
       0,   108,   196,   479,   -94,   861,   780,  -354,     0,     0,
    -354,  -354,   633,  -354,  -354,   263,     0,     0,     0,   103,
     104,     0,  -354,  -354,  -354,   105,  -354,  -354,  -354,   -94,
     -94,     0,   -94,   634,     0,  -354,   266,   196,  -670,     0,
    -354,     0,     0,  1304,   636,     0,     0,     0,     0,     0,
       0,     0,  1305,  -670,  -670,     0,     0,     0,     0,   583,
       0,     0,  1100,     0,     0,  -354,  -354,     0,  -354,     0,
     938,  -316,   266,   109,  -316,  -316,  -316,  -316,  -316,   676,
     584,   763,     0,   103,   104,  1407,  -316,  -316,  -316,   105,
     764,   586,  -253,  1408,     0,     0,   223,   508,     0,  -316,
    -579,  -316,  1409,     0,  -316,   412,   103,   104,   224,   225,
       0,   226,   105,     0,     0,     0,  1410,     0,   509,     0,
     227,   228,   229,  1411,     0,     0,   420,     0,     0,  -316,
    -316,   678,  -316,     0,   209,  -302,   679,   109,  -302,  -302,
    -302,  -302,  -302,     0,     0,     0,     0,   103,   104,     0,
    -302,  -302,  -302,   105,   678,     0,     0,     0,     0,  1412,
     109,   768,     0,  -302,   230,  -302,   231,     0,  -302,   491,
    -330,     0,     0,  -330,  -330,     0,  -330,  -330,   263,     0,
       0,     0,   103,   104,     0,  -330,  -330,  -330,   105,     0,
     885,     0,     0,  -302,  -302,   107,  -302,     0,  -330,   417,
     108,   109,     0,  -330,  -708,   637,   633,     0,   418,     0,
       0,   224,   225,   638,   226,     0,     0,   358,     0,     0,
       0,  -781,     0,   227,   228,   229,     0,   634,  -330,  -330,
     265,  -330,   886,   261,     0,   266,   109,     0,   636,     0,
    -450,   262,  -781,   359,     0,     0,     0,  -781,     0,     0,
     263,     0,   916,  -781,   103,   104,     0,     0,     0,     0,
     105,     0,     0,     0,   360,   361,   362,   230,   363,   231,
       0,   264,   925,     0,     0,     0,   364,   365,   366,   639,
     675,  -270,  1066,     0,     0,     0,     0,     0,  -270,   676,
       0,  -780,     0,   103,   104,   900,   925,     0,  -780,   105,
       0,     0,   265,     0,   675,  -269,     0,   266,   109,  -270,
     677,  -270,  -269,   676,  -270,     0,     0,   103,   104,  -780,
       0,   194,  1067,   105,  -780,     0,     0,     0,   761,   102,
    -780,     0,     0,  -269,   677,  -269,  1407,   762,  -269,  -780,
    -780,   678,   103,   104,  1408,  -388,   679,   109,   105,     0,
       0,     0,  -388,  1409,     0,   502,   503,   103,   104,   106,
    1407,     0,     0,   105,     0,   678,     0,  1410,  1408,  -387,
     679,   109,     0,  -388,  1411,     0,  -387,  1409,  -388,     0,
       0,   103,   104,     0,     0,   194,     0,   105,     0,     0,
     107,  1410,     0,   102,  -259,   108,   109,  -387,  1411,     0,
       0,  -259,  -387,     0,  1340,   678,   103,   104,     0,   194,
    1412,   109,   105,  1341,     0,     0,  1048,   102,  -258,     0,
     633,     0,  -259,   106,  -259,  -258,     0,  -259,   951,   678,
     103,   104,   633,     0,  1412,   109,   105,  1090,     0,     0,
       0,   634,     0,     0,     0,     0,  -258,   106,  -258,   261,
       0,  -258,   636,   634,   107,   952,   953,   262,  -456,   108,
     109,  -668,  -668,     0,   636,  -456,   263,     0,     0,     0,
     103,   104,   261,  1049,  1050,     0,   105,     0,   107,     0,
     262,  -455,  1051,   108,   109,     0,  -456,   264,  -455,   263,
       0,  -456,     0,   103,   104,   991,     0,     0,   633,   105,
       0,     0,     0,   992,  -359,     0,     0,     0,     0,  -455,
     264,  -359,   409,     0,  -455,     0,   103,   104,   265,   634,
     945,   410,   105,   266,   109,     0,   993,     0,   214,  -276,
     636,     0,  -359,   994,   991,     0,  -276,  -359,     0,  1052,
    1053,   265,   992,  -358,     0,     0,   266,   109,     0,   215,
    -358,  -264,     0,     0,  -264,   103,   104,  -276,   959,  -276,
     925,   105,  -276,     0,   107,   993,   675,  -126,   675,   995,
     109,  -358,   994,     0,     0,   676,  -358,   676,   261,   103,
     104,   103,   104,     0,     0,   105,   262,   105,   946,     0,
     947,     0,     0,   247,     0,   263,   677,     0,   677,   103,
     104,     0,   141,   107,   925,   105,   868,     0,   995,   109,
     142,  -478,   675,     0,   868,  -669,   264,     0,  -478,   143,
       0,   676,  -669,  -672,     0,   103,   104,   678,   991,   678,
    -672,   105,   679,   109,   679,   109,   992,     0,     0,  -478,
     144,     0,   677,  -669,  -478,   919,     0,   265,  -669,   103,
     104,  -672,   266,   109,  -669,   105,  -672,     0,     0,   993,
       0,   664,  -672,  -669,  -669,     0,   994,   546,     0,     0,
       0,  -672,  -672,   678,  -540,   547,   145,     0,   679,   109,
       0,     0,   665,  -606,   310,     0,     0,   920,     0,     0,
       0,     0,     0,   667,     0,     0,  1030,   107,     0,     0,
       0,   548,   995,   109,  -606,   311,     0,     0,  1063,  -606,
       0,     0,   583,  -533,  -533,  -606,   312,   313,   314,   315,
     316,   317,   318,   319,   633,     0,   320,   321,   322,   323,
     324,   588,     0,   584,     0,     0,     0,     0,     0,   589,
    -702,   325,     0,   334,   586,   634,     0,  -702,   855,     0,
       0,     0,     0,  1031,     0,     0,   636,     0,   588,     0,
       0,     0,   419,     0,     0,  1052,   589,  -702,  -702,   336,
     334,  -263,     0,  -702,  -702,   335,     0,     0,  -263,  -702,
     337,   338,   339,   340,   341,   342,   343,   344,  -702,  -702,
     345,   346,   347,   348,   349,  -702,   336,     0,     0,  -263,
    -702,  -263,     0,     0,  -263,   856,  -702,   337,   338,   339,
     340,   341,   342,   343,   344,  -702,  -702,   345,   346,   347,
     348,   349,   594,     0,  1095,     0,   524,     0,     0,     0,
     333,  -665,   590,  1096,   334,  -483,     0,     0,  -665,   335,
       0,     0,  -483,     0,     0,     0,     0,     0,     0,   594,
       0,   952,   953,   419,     0,     0,     0,   333,  -664,  -665,
     336,   334,  -262,  -483,  -665,  -664,   335,     0,  -483,   214,
    -665,   337,   338,   339,   340,   341,   342,   343,   344,  -665,
    -665,   345,   346,   347,   348,   349,  -664,   336,     0,     0,
     215,  -664,  -262,     0,     0,  -262,   350,  -664,   337,   338,
     339,   340,   341,   342,   343,   344,  -664,  -664,   345,   346,
     347,   348,   349,   594,     0,     0,     0,   757,     0,     0,
       0,   333,  -653,   350,     0,   334,   758,     0,     0,  -653,
     335,     0,     0,   508,     0,     0,     0,     0,     0,     0,
     594,     0,     0,     0,   419,     0,     0,     0,   333,  -651,
    -653,   336,   334,  -260,   509,  -653,  -651,   335,     0,  -461,
    -260,  -653,   337,   338,   339,   340,   341,   342,   343,   344,
    -653,  -653,   345,   346,   347,   348,   349,  -651,   336,     0,
       0,  -260,  -651,  -260,     0,     0,  -260,   350,  -651,   337,
     338,   339,   340,   341,   342,   343,   344,  -651,  -651,   345,
     346,   347,   348,   349,   594,     0,     0,     0,   767,     0,
       0,     0,   333,  -645,   350,     0,   334,  -460,     0,     0,
    -645,   335,     0,     0,  -460,     0,     0,     0,     0,     0,
       0,   594,     0,     0,     0,   419,     0,     0,     0,   333,
    -643,  -645,   336,   334,  -261,  -460,  -645,  -643,   335,     0,
    -460,   214,  -645,   337,   338,   339,   340,   341,   342,   343,
     344,  -645,  -645,   345,   346,   347,   348,   349,  -643,   336,
       0,     0,  -261,  -643,  -261,     0,     0,  -261,   350,  -643,
     337,   338,   339,   340,   341,   342,   343,   344,  -643,  -643,
     345,   346,   347,   348,   349,   594,     0,     0,     0,   524,
       0,     0,     0,   333,  -652,   350,     0,   334,  -482,     0,
       0,  -652,   335,     0,     0,   294,     0,     0,     0,     0,
       0,     0,   594,     0,     0,     0,  1087,     0,     0,     0,
     333,  -649,  -652,   336,   334,  1088,   295,  -652,  -649,   335,
       0,  -482,   942,  -652,   337,   338,   339,   340,   341,   342,
     343,   344,  -652,  -652,   345,   346,   347,   348,   349,  -649,
     336,     0,     0,   943,  -649,  -275,     0,     0,  -275,   350,
    -649,   337,   338,   339,   340,   341,   342,   343,   344,  -649,
    -649,   345,   346,   347,   348,   349,   594,     0,     0,     0,
     524,     0,     0,     0,   333,  -644,   350,     0,   334,  -480,
       0,     0,  -644,   335,     0,     0,  -480,     0,     0,     0,
       0,     0,     0,   594,     0,     0,     0,  1099,     0,     0,
       0,   333,  -641,  -644,   336,   334,  -274,  -480,  -644,  -641,
     335,     0,  -480,  -274,  -644,   337,   338,   339,   340,   341,
     342,   343,   344,  -644,  -644,   345,   346,   347,   348,   349,
    -641,   336,     0,     0,  -274,  -641,  -274,     0,     0,  -274,
     350,  -641,   337,   338,   339,   340,   341,   342,   343,   344,
    -641,  -641,   345,   346,   347,   348,   349,   594,     0,     0,
       0,   524,     0,     0,     0,   333,  -629,   350,     0,   334,
    -481,     0,     0,  -629,   335,     0,     0,   294,     0,     0,
       0,     0,     0,     0,   594,     0,     0,     0,  1099,     0,
       0,     0,   333,  -627,  -629,   336,   334,  -273,  -481,  -629,
    -627,   335,     0,  -481,   942,  -629,   337,   338,   339,   340,
     341,   342,   343,   344,  -629,  -629,   345,   346,   347,   348,
     349,  -627,   336,     0,     0,   943,  -627,  -273,     0,     0,
    -273,   350,  -627,   337,   338,   339,   340,   341,   342,   343,
     344,  -627,  -627,   345,   346,   347,   348,   349,   594,     0,
       0,     0,   767,     0,     0,     0,   333,  -635,   350,     0,
     334,  -459,     0,     0,  -635,   335,     0,     0,   508,     0,
       0,     0,     0,     0,     0,   594,     0,     0,     0,  1099,
       0,     0,     0,   333,  -628,  -635,   336,   334,  -271,   509,
    -635,  -628,   335,     0,  -459,  -271,  -635,   337,   338,   339,
     340,   341,   342,   343,   344,  -635,  -635,   345,   346,   347,
     348,   349,  -628,   336,     0,     0,  -271,  -628,  -271,     0,
       0,  -271,   350,  -628,   337,   338,   339,   340,   341,   342,
     343,   344,  -628,  -628,   345,   346,   347,   348,   349,   594,
       0,     0,     0,   767,     0,     0,     0,   333,  -625,   350,
       0,   334,  -457,     0,     0,  -625,   335,     0,     0,  -457,
       0,     0,     0,     0,     0,     0,   594,     0,     0,     0,
    1099,     0,     0,     0,   333,  -633,  -625,   336,   334,  -272,
    -457,  -625,  -633,   335,     0,  -457,   942,  -625,   337,   338,
     339,   340,   341,   342,   343,   344,  -625,  -625,   345,   346,
     347,   348,   349,  -633,   336,     0,     0,  -272,  -633,  -272,
       0,     0,  -272,   350,  -633,   337,   338,   339,   340,   341,
     342,   343,   344,  -633,  -633,   345,   346,   347,   348,   349,
     594,     0,     0,     0,   767,     0,     0,     0,   333,  -661,
     350,     0,   334,  -458,     0,     0,  -661,   335,     0,     0,
     508,     0,     0,     0,     0,     0,     0,   594,     0,     0,
       0,  1265,     0,     0,     0,   333,  -659,  -661,   336,   334,
    1266,  -458,  -661,  -659,   335,     0,  -458,  1159,  -661,   337,
     338,   339,   340,   341,   342,   343,   344,  -661,  -661,   345,
     346,   347,   348,   349,  -659,   336,     0,     0,  1160,  -659,
       0,     0,     0,  -364,   350,  -659,   337,   338,   339,   340,
     341,   342,   343,   344,  -659,  -659,   345,   346,   347,   348,
     349,   594,     0,     0,     0,  1158,     0,     0,     0,   333,
    -660,   350,     0,   334,  -363,     0,     0,  -660,   335,     0,
       0,  -363,     0,     0,     0,     0,     0,     0,   594,     0,
       0,     0,  1158,     0,     0,     0,   333,  -657,  -660,   336,
     334,  -362,  -363,  -660,  -657,   335,     0,  -363,  1159,  -660,
     337,   338,   339,   340,   341,   342,   343,   344,  -660,  -660,
     345,   346,   347,   348,   349,  -657,   336,     0,     0,  1160,
    -657,     0,     0,     0,  -362,   350,  -657,   337,   338,   339,
     340,   341,   342,   343,   344,  -657,  -657,   345,   346,   347,
     348,   349,   546,     0,  1091,     0,  1267,     0,  1453,     0,
     547,     0,   350,  1092,     0,  1268,     0,  1454,  -606,   310,
     942,     0,  1159,     0,  1440,     0,     0,     0,     0,     0,
     588,     0,     0,     0,     0,     0,   548,  -618,   589,  -606,
     311,   943,   334,  1160,  -606,  1441,  -702,   335,  -533,  -533,
    -606,   312,   313,   314,   315,   316,   317,   318,   319,     0,
       0,   320,   321,   322,   323,   324,     0,  -702,   336,     0,
       0,     0,  -702,     0,     0,     0,   325,     0,  -702,   337,
     338,   339,   340,   341,   342,   343,   344,     0,     0,   345,
     346,   347,   348,   349,   546,     0,     0,   223,  1158,     0,
       0,     0,   547,  -606,   590,     0,  -365,  -360,     0,     0,
    -606,   825,     0,  -365,  -360,     0,     0,  -118,  -198,     0,
       0,   546,     0,    72,  -191,     0,     0,     0,    73,   547,
    -606,  -606,   311,     0,  -365,  -360,  -606,  -606,   310,  -365,
    -360,     0,  -606,   312,   313,   314,   315,   316,   317,   318,
     319,  -606,   191,   320,   321,   322,   323,   324,  -606,   311,
       0,     0,     0,  -606,     0,   230,     0,   231,   826,  -606,
     312,   313,   314,   315,   316,   317,   318,   319,  -606,     0,
     320,   321,   322,   323,   324,   554,     0,     0,   945,  1158,
       0,     0,     0,   309,  -576,   325,     0,  -394,  -361,     0,
       0,  -576,   310,     0,  -394,  1159,     0,     0,     0,     0,
       0,     0,   554,     0,     0,     0,     0,     0,     0,     0,
     309,  -575,  -576,   311,     0,  -394,  -361,  -576,  -575,   310,
    -394,  -361,     0,  -576,   312,   313,   314,   315,   316,   317,
     318,   319,  -576,     0,   320,   321,   322,   323,   324,  -575,
     311,     0,     0,     0,  -575,     0,   946,     0,   947,   325,
    -575,   312,   313,   314,   315,   316,   317,   318,   319,  -575,
       0,   320,   321,   322,   323,   324,   554,     0,     0,  1451,
    1462,     0,     0,     0,   309,  -564,   325,     0,  1452,  -392,
       0,     0,  -564,   310,     0,  1440,  -392,     0,     0,     0,
       0,     0,     0,   554,     0,     0,     0,     0,     0,     0,
       0,   309,  -562,  -564,   311,     0,  1441,  -392,  -564,  -562,
     310,  -393,  -392,     0,  -564,   312,   313,   314,   315,   316,
     317,   318,   319,  -564,     0,   320,   321,   322,   323,   324,
    -562,   311,     0,     0,     0,  -562,     0,     0,     0,     0,
     325,  -562,   312,   313,   314,   315,   316,   317,   318,   319,
    -562,     0,   320,   321,   322,   323,   324,   554,     0,     0,
    -413,  1462,     0,     0,     0,   309,  -556,   325,     0,  -413,
    -391,     0,     0,  -556,   310,     0,  -413,  1440,     0,     0,
       0,     0,     0,     0,   554,     0,     0,     0,     0,     0,
       0,     0,   309,  -554,  -556,   311,     0,  -413,  1441,  -556,
    -554,   310,  -413,  -391,     0,  -556,   312,   313,   314,   315,
     316,   317,   318,   319,  -556,     0,   320,   321,   322,   323,
     324,  -554,   311,     0,     0,     0,  -554,     0,     0,     0,
       0,   325,  -554,   312,   313,   314,   315,   316,   317,   318,
     319,  -554,     0,   320,   321,   322,   323,   324,   554,     0,
       0,  1462,  1462,     0,     0,     0,   309,  -563,   325,     0,
    -389,  -390,     0,     0,  -563,   310,     0,  -389,  1440,     0,
       0,     0,     0,     0,     0,   554,     0,     0,     0,     0,
       0,     0,     0,   309,  -560,  -563,   311,     0,  -389,  -390,
    -563,  -560,   310,  -389,  -390,     0,  -563,   312,   313,   314,
     315,   316,   317,   318,   319,  -563,     0,   320,   321,   322,
     323,   324,  -560,   311,     0,     0,     0,  -560,     0,     0,
       0,     0,   325,  -560,   312,   313,   314,   315,   316,   317,
     318,   319,  -560,     0,   320,   321,   322,   323,   324,   554,
       0,     0,     0,     0,     0,     0,     0,   309,  -555,   325,
       0,     0,     0,     0,     0,  -555,   310,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   554,     0,     0,     0,
       0,     0,     0,     0,   309,  -552,  -555,   311,     0,     0,
       0,  -555,  -552,   310,     0,     0,     0,  -555,   312,   313,
     314,   315,   316,   317,   318,   319,  -555,     0,   320,   321,
     322,   323,   324,  -552,   311,     0,     0,     0,  -552,     0,
       0,     0,     0,   325,  -552,   312,   313,   314,   315,   316,
     317,   318,   319,  -552,     0,   320,   321,   322,   323,   324,
     554,     0,     0,     0,     0,     0,     0,     0,   309,  -548,
     325,     0,     0,     0,     0,     0,  -548,   310,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   554,     0,     0,
       0,     0,     0,     0,     0,   309,  -546,  -548,   311,     0,
       0,     0,  -548,  -546,   310,     0,     0,     0,  -548,   312,
     313,   314,   315,   316,   317,   318,   319,  -548,     0,   320,
     321,   322,   323,   324,  -546,   311,     0,     0,     0,  -546,
       0,     0,     0,     0,   325,  -546,   312,   313,   314,   315,
     316,   317,   318,   319,  -546,     0,   320,   321,   322,   323,
     324,   554,     0,     0,     0,     0,     0,     0,     0,   309,
    -547,   325,     0,     0,     0,     0,     0,  -547,   310,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   554,     0,
       0,     0,     0,     0,     0,     0,   309,  -544,  -547,   311,
       0,     0,     0,  -547,  -544,   310,     0,     0,     0,  -547,
     312,   313,   314,   315,   316,   317,   318,   319,  -547,     0,
     320,   321,   322,   323,   324,  -544,   311,     0,     0,     0,
    -544,     0,     0,     0,     0,   325,  -544,   312,   313,   314,
     315,   316,   317,   318,   319,  -544,     0,   320,   321,   322,
     323,   324,   554,     0,     0,     0,     0,     0,     0,     0,
     309,  -572,   325,     0,     0,     0,     0,     0,  -572,   310,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   554,
       0,     0,     0,     0,     0,     0,     0,   309,  -570,  -572,
     311,     0,     0,     0,  -572,  -570,   310,     0,     0,     0,
    -572,   312,   313,   314,   315,   316,   317,   318,   319,  -572,
       0,   320,   321,   322,   323,   324,  -570,   311,     0,     0,
       0,  -570,     0,     0,     0,     0,   325,  -570,   312,   313,
     314,   315,   316,   317,   318,   319,  -570,     0,   320,   321,
     322,   323,   324,   554,     0,     0,     0,     0,     0,     0,
       0,   309,  -571,   325,     0,     0,     0,     0,     0,  -571,
     310,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     554,     0,     0,     0,     0,     0,     0,     0,   309,  -568,
    -571,   311,     0,     0,     0,  -571,  -568,   310,     0,     0,
       0,  -571,   312,   313,   314,   315,   316,   317,   318,   319,
    -571,     0,   320,   321,   322,   323,   324,  -568,   311,     0,
       0,     0,  -568,     0,     0,     0,     0,   325,  -568,   312,
     313,   314,   315,   316,   317,   318,   319,  -568,   594,   320,
     321,   322,   323,   324,     0,     0,   333,  1346,  1233,     0,
     334,     0,     0,     0,   325,   335,  1347,  1234,     0,     0,
       0,     0,     0,   633,   664,   622,     0,     0,     0,     0,
     877,   878,   623,   333,     0,     0,   336,   334,     0,     0,
       0,     0,   335,     0,   634,   665,     0,   337,   338,   339,
     340,   341,   342,   343,   344,   636,   667,   345,   346,   347,
     348,   349,     0,   336,  -668,  -668,     0,     0,     0,     0,
       0,     0,   350,     0,   337,   338,   339,   340,   341,   342,
     343,   344,     0,   594,   345,   346,   347,   348,   349,     0,
    -615,   333,  1370,     0,     0,   334,     0,     0,     0,   350,
     335,  1371,     0,   643,     0,     0,     0,     0,   633,     0,
     637,   357,     0,     0,     0,   358,     0,     0,   638,  -781,
     898,   336,   358,     0,     0,     0,  -781,   896,     0,   634,
       0,     0,   337,   338,   339,   340,   341,   342,   343,   344,
     636,   359,   345,   346,   347,   348,   349,  -781,   359,  -668,
       0,     0,  -781,     0,     0,     0,     0,   350,  -781,     0,
       0,     0,   360,   361,   362,     0,   363,  -781,  -781,   360,
     361,   362,     0,   363,   364,   365,   366,   899,   594,   495,
       0,   364,   365,   366,   897,  -617,   333,   759,   755,     0,
     334,   224,   225,     0,   226,   335,   760,     0,     0,   224,
     225,     0,   226,   227,   228,   229,     0,     0,  -107,     0,
       0,   227,   228,   229,   373,  -172,   336,     0,   554,   374,
       0,     0,     0,  -179,     0,     0,   309,   337,   338,   339,
     340,   341,   342,   343,   344,   310,  -107,   345,   346,   347,
     348,   349,     0,   375,     0,     0,   307,   496,     0,   497,
     844,   845,   350,   308,   309,   496,   311,   497,     0,     0,
       0,     0,     0,   310,     0,     0,  1235,   312,   313,   314,
     315,   316,   317,   318,   319,  1236,     0,   320,   321,   322,
     323,   324,   664,     0,   311,     0,     0,     0,     0,     0,
       0,     0,   325,     0,     0,   312,   313,   314,   315,   316,
     317,   318,   319,   665,   332,   320,   321,   322,   323,   324,
       0,     0,   333,     0,   667,     0,   334,     0,     0,     0,
     325,   335,     0,     0,     0,  1284,     0,     0,     0,     0,
     579,     0,     0,     0,  1285,     0,     0,   308,   309,     0,
       0,   583,   336,     0,     0,     0,     0,   310,     0,     0,
       0,     0,     0,   337,   338,   339,   340,   341,   342,   343,
     344,  1042,   584,   345,   346,   347,   348,   349,   311,     0,
    -694,     0,     0,   586,   859,     0,     0,  -694,   350,   312,
     313,   314,   315,   316,   317,   318,   319,     0,   594,   320,
     321,   322,   323,   324,     0,     0,   333,     0,  -694,     0,
     334,  1043,   621,  -694,   325,   335,     0,     0,     0,  -694,
       0,     0,     0,     0,   554,     0,     0,     0,  -694,  -694,
       0,  -537,   309,     0,     0,     0,   336,     0,     0,     0,
       0,   310,     0,     0,     0,     0,     0,   337,   338,   339,
     340,   341,   342,   343,   344,   637,     0,   345,   346,   347,
     348,   349,   311,   638,  -781,     0,     0,   358,     0,     0,
       0,  -781,   350,   312,   313,   314,   315,   316,   317,   318,
     319,     0,   594,   320,   321,   322,   323,   324,     0,     0,
     333,     0,  -781,   359,   334,     0,     0,  -781,   325,   857,
       0,     0,     0,  -781,     0,     0,     0,     0,     0,     0,
       0,     0,  -781,  -781,   360,   361,   362,     0,   363,     0,
     336,     0,     0,     0,     0,     0,   364,   365,   366,   639,
       0,   337,   338,   339,   340,   341,   342,   343,   344,     0,
     554,   345,   346,   347,   348,   349,     0,  -539,   309,  1286,
       0,     0,     0,     0,     0,     0,   858,   310,  1287,     0,
       0,     0,     0,     0,     0,   583,     0,   643,     0,     0,
       0,  1026,     0,     0,     0,   357,  -761,     0,   311,   358,
    -598,     0,     0,  -761,     0,     0,   584,  -598,     0,   312,
     313,   314,   315,   316,   317,   318,   319,   586,     0,   320,
     321,   322,   323,   324,  -761,   359,     0,   620,  -598,  -761,
       0,  1027,   578,     0,   325,  -761,  -694,     0,     0,  -598,
     859,     0,     0,  -694,  -761,  -761,   360,   361,   362,     0,
     363,     0,     0,     0,   643,     0,     0,     0,   364,   365,
     366,   367,   357,  -760,  -694,     0,   358,     0,   621,  -694,
    -760,     0,     0,     0,     0,  -694,     0,     0,     0,     0,
       0,   643,     0,     0,  -694,  -694,     0,     0,     0,   357,
    -725,  -760,   359,   358,     0,     0,  -760,  -725,     0,     0,
       0,     0,  -760,     0,     0,     0,     0,     0,   356,     0,
       0,  -760,  -760,   360,   361,   362,   357,   363,  -725,   359,
     358,     0,     0,  -725,     0,   364,   365,   366,   367,  -725,
       0,     0,     0,     0,     0,     0,     0,     0,  -725,  -725,
     360,   361,   362,     0,   363,     0,   359,     0,   643,     0,
       0,     0,   364,   365,   366,   367,   357,  -723,     0,     0,
     358,     0,     0,     0,  -723,     0,     0,   360,   361,   362,
       0,   363,     0,     0,     0,   643,     0,     0,     0,   364,
     365,   366,   367,   357,  -731,  -723,   359,   358,     0,     0,
    -723,  -731,     0,     0,     0,     0,  -723,     0,     0,     0,
       0,     0,   643,     0,     0,  -723,  -723,   360,   361,   362,
     357,   363,  -731,   359,   358,     0,     0,  -731,     0,   364,
     365,   366,   367,  -731,     0,     0,     0,     0,     0,     0,
       0,     0,  -731,  -731,   360,   361,   362,     0,   363,     0,
     359,     0,   643,     0,     0,     0,   364,   365,   366,   367,
     357,  -724,     0,     0,   358,     0,     0,     0,  -724,     0,
       0,   360,   361,   362,     0,   363,     0,     0,     0,   643,
       0,     0,     0,   364,   365,   366,   367,   357,  -721,  -724,
     359,   358,     0,     0,  -724,  -721,     0,     0,     0,     0,
    -724,     0,     0,     0,     0,     0,     0,   495,     0,  -724,
    -724,   360,   361,   362,     0,   363,  -721,   359,     0,   224,
     225,  -721,   226,   364,   365,   366,   367,  -721,     0,     0,
       0,   227,   228,   229,     0,     0,  -721,  -721,   360,   361,
     362,     0,   363,     0,     0,     0,   643,     0,     0,     0,
     364,   365,   366,   367,   357,  -729,     0,     0,   358,     0,
       0,   -98,  -729,     0,     0,  -105,  -198,     0,   -98,     0,
       0,    72,  -191,   643,     0,   496,    73,   497,     0,     0,
       0,   357,  -749,  -729,   359,   358,     0,     0,  -729,  -749,
       0,     0,     0,  -105,  -729,     0,     0,     0,     0,     0,
     181,   945,     0,  -729,  -729,   360,   361,   362,     0,   363,
    -749,   359,     0,   224,   225,  -749,   226,   364,   365,   366,
     367,  -749,     0,     0,     0,   227,   228,   229,     0,     0,
    -749,  -749,   360,   361,   362,   -98,   363,     0,     0,     0,
     643,     0,     0,     0,   364,   365,   366,   367,   357,  -747,
       0,     0,   358,     0,  1046,     0,  -747,     0,     0,     0,
       0,     0,     0,  -694,     0,     0,     0,   643,     0,   946,
    -694,   947,     0,     0,     0,   357,  -741,  -747,   359,   358,
       0,     0,  -747,  -741,     0,     0,     0,     0,  -747,     0,
       0,  -694,     0,     0,  1047,   621,     0,  -747,  -747,   360,
     361,   362,  -694,   363,  -741,   359,     0,   620,     0,  -741,
       0,   364,   365,   366,   367,  -741,  -694,     0,     0,     0,
    1288,     0,     0,  -694,  -741,  -741,   360,   361,   362,  1289,
     363,     0,     0,     0,   643,     0,   583,     0,   364,   365,
     366,   367,   357,  -739,  -694,     0,   358,     0,   621,  -694,
    -739,     0,     0,     0,     0,  -694,     0,   584,     0,     0,
       0,   643,     0,     0,  -694,  -694,     0,     0,   586,   357,
    -748,  -739,   359,   358,     0,     0,  -739,  -748,     0,     0,
       0,     0,  -739,     0,     0,     0,     0,     0,     0,     0,
       0,  -739,  -739,   360,   361,   362,     0,   363,  -748,   359,
       0,   868,     0,  -748,     0,   364,   365,   366,   367,  -748,
    -673,     0,     0,     0,  1290,     0,     0,  -673,  -748,  -748,
     360,   361,   362,  1291,   363,     0,     0,     0,   643,     0,
     583,     0,   364,   365,   366,   367,   357,  -745,  -673,     0,
     358,     0,     0,  -673,  -745,     0,     0,     0,     0,  -673,
       0,   584,     0,     0,     0,   643,     0,     0,  -673,  -673,
       0,     0,   586,   357,  -740,  -745,   359,   358,     0,     0,
    -745,  -740,     0,     0,     0,     0,  -745,     0,     0,     0,
       0,     0,     0,     0,     0,  -745,  -745,   360,   361,   362,
       0,   363,  -740,   359,     0,   868,     0,  -740,     0,   364,
     365,   366,   367,  -740,  -674,     0,     0,     0,  1292,     0,
       0,  -674,  -740,  -740,   360,   361,   362,  1293,   363,     0,
       0,     0,   643,     0,   583,     0,   364,   365,   366,   367,
     357,  -737,  -674,     0,   358,     0,     0,  -674,  -737,     0,
       0,     0,     0,  -674,     0,   584,     0,     0,     0,   643,
       0,     0,  -674,  -674,     0,     0,   586,   357,  -757,  -737,
     359,   358,     0,     0,  -737,  -757,     0,     0,     0,     0,
    -737,     0,     0,     0,     0,     0,     0,     0,     0,  -737,
    -737,   360,   361,   362,     0,   363,  -757,   359,     0,   868,
       0,  -757,     0,   364,   365,   366,   367,  -757,  -675,     0,
       0,     0,  1294,     0,     0,  -675,  -757,  -757,   360,   361,
     362,  1295,   363,     0,     0,     0,   643,     0,   583,     0,
     364,   365,   366,   367,   357,  -755,  -675,     0,   358,     0,
       0,  -675,  -755,     0,     0,     0,     0,  -675,     0,   584,
       0,     0,     0,   643,     0,     0,  -675,  -675,     0,     0,
     586,   357,  -756,  -755,   359,   358,     0,     0,  -755,  -756,
       0,     0,     0,     0,  -755,     0,     0,     0,     0,     0,
       0,     0,     0,  -755,  -755,   360,   361,   362,     0,   363,
    -756,   359,     0,   868,     0,  -756,     0,   364,   365,   366,
     367,  -756,  -676,     0,     0,     0,     0,     0,     0,  -676,
    -756,  -756,   360,   361,   362,     0,   363,     0,     0,     0,
     643,     0,  1296,     0,   364,   365,   366,   367,   357,  -753,
    -676,  1297,   358,     0,     0,  -676,  -753,     0,   583,  1298,
       0,  -676,     0,     0,     0,     0,   554,     0,  1299,     0,
    -676,  -676,     0,     0,   309,   583,     0,  -753,   359,   584,
       0,     0,  -753,   310,     0,     0,  1302,     0,  -753,     0,
     586,     0,     0,     0,     0,  1303,   584,  -753,  -753,   360,
     361,   362,   583,   363,   311,     0,     0,   586,     0,     0,
       0,   364,   365,   366,   367,   312,   313,   314,   315,   316,
     317,   318,   319,   584,   554,   320,   321,   322,   323,   324,
       0,   658,   309,  1306,   586,     0,     0,     0,   659,   357,
     325,   827,  1307,   358,     0,     0,     0,     0,     0,   583,
       0,   637,     0,     0,     0,     0,     0,     0,  -714,   638,
       0,     0,   311,   358,     0,     0,     0,  -781,     0,   359,
     584,     0,     0,   312,   313,   314,   315,   316,   317,   318,
     319,   586,     0,   320,   321,   322,   323,   324,  -781,   359,
     360,   361,   362,  -781,   363,     0,     0,     0,   828,  -781,
       0,   643,   364,   365,   366,   367,     0,     0,  -711,   357,
     360,   361,   362,   358,   363,     0,     0,     0,     0,   643,
       0,   141,   364,   365,   366,   639,  -713,   357,   527,   142,
       0,   358,     0,  1308,     0,     0,     0,     0,   143,   359,
       0,     0,  1309,     0,     0,     0,     0,     0,     0,   583,
       0,     0,     0,     0,     0,  -473,     0,   359,     0,   144,
     360,   361,   362,     0,   363,   528,  -473,  -473,  -473,     0,
     584,     0,   364,   365,   366,   367,     0,     0,   360,   361,
     362,   586,   363,     0,     0,   220,     0,     0,     0,     0,
     364,   365,   366,   367,  -281,   145,     0,  -281,  -281,  -281,
    -281,  -281,     0,     0,     0,     0,     0,     0,     0,  -281,
    -281,  -281,  -281,  -281,   221,   222,     0,   220,     0,     0,
       0,     0,  -281,     0,  -281,     0,  -280,  -281,     0,  -280,
    -280,  -280,  -280,  -280,     0,     0,     0,     0,     0,     0,
       0,  -280,  -280,  -280,  -280,  -280,   221,   222,     0,   220,
       0,     0,  -281,  -281,  -280,  -281,  -280,     0,  -279,  -280,
       0,  -279,  -279,  -279,  -279,  -279,     0,     0,     0,     0,
       0,     0,     0,  -279,  -279,  -279,  -279,  -279,   221,   222,
       0,   220,     0,     0,  -280,  -280,  -279,  -280,  -279,     0,
    -278,  -279,     0,  -278,  -278,  -278,  -278,  -278,     0,     0,
       0,     0,     0,     0,     0,  -278,  -278,  -278,  -278,  -278,
     221,   222,     0,   954,     0,     0,  -279,  -279,  -278,  -279,
    -278,     0,  -335,  -278,     0,  -335,  -335,  -335,  -335,  -335,
       0,     0,     0,     0,     0,     0,     0,  -335,  -335,  -335,
    -335,  -335,   955,   956,     0,   954,     0,     0,  -278,  -278,
    -335,  -278,  -335,     0,  -334,  -335,     0,  -334,  -334,  -334,
    -334,  -334,     0,     0,     0,     0,     0,     0,     0,  -334,
    -334,  -334,  -334,  -334,   955,   956,     0,   954,     0,     0,
    -335,  -335,  -334,  -335,  -334,     0,  -333,  -334,     0,  -333,
    -333,  -333,  -333,  -333,     0,     0,     0,     0,     0,     0,
       0,  -333,  -333,  -333,  -333,  -333,   955,   956,     0,   954,
       0,     0,  -334,  -334,  -333,  -334,  -333,     0,  -332,  -333,
       0,  -332,  -332,  -332,  -332,  -332,     0,     0,     0,     0,
       0,     0,     0,  -332,  -332,  -332,  -332,  -332,   955,   956,
       0,   493,     0,     0,  -333,  -333,  -332,  -333,  -332,     0,
    -427,  -332,     0,  -427,  -427,     0,  -427,  -427,     0,     0,
       0,     0,     0,     0,     0,  -427,  -427,  -427,  -427,  -427,
    -427,  -427,     0,     0,     0,  1155,  -332,  -332,  -427,  -332,
       0,     0,   494,  -427,  -369,     0,     0,  -416,  -416,     0,
    -416,  -369,     0,     0,     0,     0,     0,     0,     0,  -416,
    -416,  -416,  -416,  -416,  -416,  -416,     0,     0,  -427,  -427,
    1436,  -427,  -369,     0,     0,     0,  1156,  -369,     0,  -398,
       0,     0,  -421,  -421,     0,  -421,  -398,     0,     0,     0,
       0,     0,     0,     0,  -421,  -421,  -421,  -421,  -421,  -421,
    -421,     0,  -416,  -416,   217,  -416,     0,  -398,     0,     0,
       0,  1437,  -398,  -303,     0,     0,  -303,  -303,  -303,  -303,
    -303,     0,     0,     0,     0,     0,     0,     0,  -303,  -303,
    -303,   218,   219,     0,     0,     0,   217,  -421,  -421,     0,
    -421,  -303,     0,  -303,     0,   411,  -303,     0,  -303,  -303,
    -303,  -303,  -303,     0,     0,     0,     0,     0,     0,     0,
    -303,  -303,  -303,   218,   219,     0,     0,     0,   504,     0,
    1310,  -303,  -303,  -303,  -303,  -303,     0,  -347,  -303,  1311,
    -347,  -347,     0,  -347,  -347,     0,   583,     0,     0,     0,
       0,     0,  -347,  -347,  -347,  -347,  -347,   505,   506,     0,
     951,     0,     0,  -303,  -303,  -347,  -303,   584,     0,  -317,
    -347,     0,  -317,  -317,  -317,  -317,  -317,     0,   586,     0,
       0,     0,     0,     0,  -317,  -317,  -317,   952,   953,     0,
       0,     0,   504,     0,  1312,  -347,  -347,  -317,  -347,  -317,
       0,  -346,  -317,  1313,  -346,  -346,     0,  -346,  -346,     0,
     583,     0,     0,     0,     0,     0,  -346,  -346,  -346,  -346,
    -346,   505,   506,     0,   504,     0,     0,  -317,  -317,  -346,
    -317,   584,     0,  -345,  -346,     0,  -345,  -345,     0,  -345,
    -345,     0,   586,     0,     0,     0,     0,     0,  -345,  -345,
    -345,  -345,  -345,   505,   506,     0,   504,     0,  1314,  -346,
    -346,  -345,  -346,     0,     0,  -344,  -345,  1315,  -344,  -344,
       0,  -344,  -344,     0,   583,     0,     0,     0,     0,     0,
    -344,  -344,  -344,  -344,  -344,   505,   506,     0,   951,     0,
       0,  -345,  -345,  -344,  -345,   584,     0,  1090,  -344,     0,
    -317,  -317,  -317,  -317,  -317,     0,   586,     0,     0,     0,
       0,     0,  -317,  -317,  -317,   952,   953,     0,     0,     0,
     233,     0,     0,  -344,  -344,  -317,  -344,  -317,     0,  -293,
    -317,     0,  -293,  -293,  -293,  -293,  -293,     0,  1316,     0,
       0,     0,     0,     0,  -293,  -293,  -293,  1317,     0,     0,
       0,     0,   501,     0,   583,  -317,  -317,  -293,  -317,  -293,
       0,  -331,  -293,     0,  -331,  -331,     0,  -331,  -331,     0,
       0,     0,     0,     0,     0,   584,  -331,  -331,  -331,   502,
     503,     0,     0,     0,   233,     0,   586,   234,  -293,  -331,
    -293,     0,     0,  -292,  -331,     0,  -292,  -292,  -292,  -292,
    -292,     0,   577,     0,     0,     0,     0,     0,  -292,  -292,
    -292,  -598,     0,     0,     0,     0,   233,     0,  -598,  -331,
    -331,  -292,  -331,  -292,     0,  -290,  -292,     0,  -290,  -290,
    -290,  -290,  -290,     0,     0,     0,     0,     0,     0,  -598,
    -290,  -290,  -290,   578,  -598,     0,     0,     0,   233,     0,
    -598,   234,  -292,  -290,  -292,  -290,     0,  -291,  -290,  -598,
    -291,  -291,  -291,  -291,  -291,     0,  1318,     0,     0,     0,
       0,     0,  -291,  -291,  -291,  1319,     0,     0,     0,     0,
     501,     0,   583,   234,  -290,  -291,  -290,  -291,     0,   756,
    -291,     0,  -331,  -331,     0,  -331,  -331,     0,     0,     0,
       0,     0,     0,   584,  -331,  -331,  -331,   502,   503,     0,
       0,     0,   949,     0,   586,   234,  -291,  -331,  -291,     0,
       0,  -307,  -331,     0,  -307,  -307,  -307,  -307,  -307,     0,
       0,  1155,     0,     0,     0,     0,  -307,  -307,  -307,     0,
    -416,     0,     0,  -416,  -416,     0,  -416,  -331,  -331,  -307,
    -331,  -307,     0,     0,  -307,  -416,  -416,  -416,  -416,  -416,
    -416,  -416,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1156,     0,     0,     0,     0,     0,   949,   950,
    -307,     0,  -307,     0,     0,     0,     0,  -306,     0,     0,
    -306,  -306,  -306,  -306,  -306,     0,     0,   949,  -416,  -416,
       0,  -416,  -306,  -306,  -306,     0,  -304,     0,     0,  -304,
    -304,  -304,  -304,  -304,     0,  -306,   949,  -306,     0,     0,
    -306,  -304,  -304,  -304,     0,  -305,     0,     0,  -305,  -305,
    -305,  -305,  -305,     0,  -304,     0,  -304,     0,     0,  -304,
    -305,  -305,  -305,     0,     0,   950,  -306,  1436,  -306,     0,
       0,     0,  1320,  -305,  1322,  -305,  -421,     0,  -305,  -421,
    -421,  1321,  -421,  1323,   950,  -304,     0,  -304,   583,     0,
     583,  -421,  -421,  -421,  -421,  -421,  -421,  -421,     0,     0,
       0,   499,     0,   950,  -305,     0,  -305,     0,  1437,   584,
    -321,   584,     0,  -321,  -321,  1324,  -321,  -321,     0,     0,
     586,     0,   586,     0,  1325,  -321,  -321,  -321,     0,     0,
       0,   633,     0,   499,  -421,  -421,     0,  -421,  -321,     0,
       0,     0,  -320,  -321,     0,  -320,  -320,     0,  -320,  -320,
       0,   829,   634,     0,     0,     0,     0,  -320,  -320,  -320,
     830,     0,     0,   636,     0,   499,     0,   583,   500,  -321,
    -320,  -321,     0,     0,  -318,  -320,     0,  -318,  -318,     0,
    -318,  -318,     0,     0,     0,     0,     0,     0,   584,  -318,
    -318,  -318,     0,  -581,     0,     0,     0,   499,     0,   586,
     500,  -320,  -318,  -320,     0,     0,  -319,  -318,  -581,  -319,
    -319,   835,  -319,  -319,     0,     0,   415,     0,     0,     0,
    -580,  -319,  -319,  -319,     0,   416,     0,  -580,  -303,  -303,
       0,  -303,   500,  -318,  -319,  -318,     0,   945,     0,  -319,
    -303,  -303,  -303,   218,   219,   761,  1089,     0,  -580,   224,
     225,     0,   226,  -580,   762,     0,     0,  -331,  -331,  -580,
    -331,   227,   228,   229,   500,  -319,  1095,  -319,  -580,  -331,
    -331,  -331,   502,   503,     0,  1096,     0,     0,  -317,  -317,
       0,  -317,     0,  -303,  -303,     0,  -303,     0,     0,     0,
    -317,  -317,  -317,   952,   953,   868,     0,     0,     0,     0,
       0,     0,     0,     0,  -677,   946,     0,   947,   901,     0,
       0,  -677,  -331,  -331,  1093,  -331,     0,   902,     0,     0,
       0,     0,     0,  1094,   664,     0,   224,   225,     0,   226,
       0,     0,  -677,  -317,  -317,   911,  -317,  -677,   227,   228,
     229,     0,     0,  -677,  -765,   665,     0,     0,   911,     0,
    -766,  -765,  -677,  -677,     0,     0,   667,  -768,     0,     0,
     911,     0,   911,     0,  -768,   903,   904,     0,     0,  -769,
       0,  -770,  -765,     0,     0,     0,  -769,  -765,  -770,   911,
       0,     0,   946,  -765,   947,  -768,     0,     0,  -779,     0,
    -768,  1062,  -765,  -765,     0,   664,  -768,  -769,     0,  -770,
    -692,     0,  -769,     0,  -770,  -768,  -768,   633,  -769,     0,
    -770,     0,     0,   868,     0,   868,   665,  -769,  -769,  -770,
    -770,  -779,  -689,     0,  -690,     0,     0,   667,   634,  -689,
       0,  -690,     0,  -692,     0,     0,  -779,  -779,   868,   636,
       0,     0,   868,     0,     0,     0,     0,  -691,  1049,  -692,
    -689,  -668,  -690,     0,  -691,  -689,     0,  -690,   633,     0,
     868,  -689,     0,  -690,     0,     0,     0,     0,     0,  -666,
    -689,  -689,  -690,  -690,     0,  -691,  -666,     0,   868,   634,
    -691,     0,   868,     0,  -668,     0,  -691,  -667,     0,     0,
     636,  -671,     0,     0,   633,  -691,  -691,  -666,   633,  -668,
    -668,     0,  -666,     0,     0,   911,     0,   911,  -666,     0,
       0,     0,     0,     0,  -764,  -667,  -762,  -666,  -666,   634,
    -667,   664,     0,  -762,  -671,     0,  -667,     0,     0,   911,
     636,     0,   911,     0,     0,  -667,  -667,     0,  -763,  -671,
    -671,  -767,   665,     0,  -762,   664,     0,  -764,   664,  -762,
       0,  1225,     0,   667,     0,  -762,     0,     0,     0,  1368,
    1226,     0,  -764,  -764,  -762,  -762,  -763,   664,  1369,   665,
       0,  -763,     0,     0,  -767,   633,     0,  -763,     0,     0,
     667,     0,  1022,     0,     0,     0,  -763,  -763,   665,  -767,
    -767,  -598,     0,  -764,   835,   835,   634,     0,  -598,   667,
       0,  -668,     0,  -583,  -584,     0,     0,   636,  -764,  -764,
    -583,  -584,   835,     0,     0,     0,  -668,  -668,     0,  -598,
       0,  -585,  1023,   578,  -598,   835,     0,     0,  -585,   835,
    -598,  -583,  -584,     0,  -586,     0,  -583,  -584,  -587,  -598,
       0,  -586,  -583,  -584,     0,  -587,     0,   835,   835,  -585,
       0,  -583,  -584,     0,  -585,     0,  -588,  -579,     0,     0,
    -585,     0,  -586,  -588,   583,   835,  -587,  -586,     0,  -585,
       0,  -587,     0,  -586,  -577,     0,     0,  -587,   835,     0,
       0,  -577,  -586,     0,  -588,   584,  -587,  -578,     0,  -588,
    -579,     0,   835,     0,   583,  -588,   586,     0,     0,     0,
    1326,  -582,  -577,     0,  -588,  -579,     0,  -577,   583,  1327,
       0,     0,     0,  -577,  1328,  -578,   633,     0,     0,     0,
    -578,     0,  -577,  1329,     0,     0,  -578,  1330,     0,   584,
     633,     0,     0,     0,  -582,  -578,  1331,   634,     0,     0,
     586,  1332,     0,   633,  1334,  1336,     0,  1338,   636,  -582,
    1333,   634,     0,  1335,  1337,     0,  1339,   633,     0,     0,
     633,   633,   636,   633,   634,     0,     0,  1342,     0,     0,
    1344,  1348,     0,     0,     0,   636,  1343,     0,   634,  1345,
    1349,   634,   634,   633,   634,  1350,   633,   633,     0,   636,
    1352,     0,   636,   636,  1351,   636,     0,     0,     0,  1353,
    1354,   633,     0,     0,   634,  1356,   633,   634,   634,  1355,
       0,     0,     0,     0,  1357,   636,   633,     0,   636,   636,
    1358,   633,   634,  1360,     0,  1362,     0,   634,     0,  1359,
       0,     0,  1361,   636,  1363,  1364,   633,   634,   636,   633,
    1366,   633,   634,  1372,  1365,  1374,     0,     0,   636,  1367,
       0,   633,  1373,   636,  1375,     0,   633,   634,  1376,   664,
     634,   664,   634,     0,     0,     0,     0,  1377,   636,     0,
    1378,   636,   634,   636,   664,     0,  1380,   634,  1382,  1379,
     665,     0,   665,   636,     0,  1381,   664,  1383,   636,     0,
       0,   667,   664,   667,   664,   665,  1384,     0,     0,     0,
    1386,  1388,     0,     0,     0,  1385,   667,   665,     0,  1387,
    1389,     0,   664,   665,  1390,   665,   664,   664,   667,  1392,
    1394,     0,     0,  1391,   667,     0,   667,     0,  1393,  1395,
     664,     0,     0,   665,  1396,   664,   664,   665,   665,     0,
       0,     0,     0,  1397,   667,     0,     0,     0,   667,   667,
     664,   665,     0,     0,  1398,     0,   665,   665,     0,     0,
    1400,     0,   667,  1399,  1402,     0,     0,   667,   667,  1401,
     664,   665,     0,  1403,     0,     0,   664,     0,     0,     0,
     664,     0,   667,     0,     0,     0,     0,     0,     0,     0,
       0,   665,     0,     0,     0,     0,     0,   665,     0,     0,
       0,   665,   667,     0,     0,     0,     0,     0,   667,     0,
       0,     0,   667
  };

  /* YYCHECK.  */
  const short int
  mcmas_parser::yycheck_[] =
  {
        51,   467,   247,   134,   268,   112,   129,   252,   745,   100,
     249,   102,   249,   450,   251,   674,   100,   384,   733,   678,
     735,   458,   153,   107,   155,   382,   157,  1130,   163,    95,
     699,    63,   261,   464,   391,   223,   265,   163,   158,   185,
      87,   694,   230,   231,   217,   218,   219,   193,    95,   100,
      16,   102,   134,    16,   707,   106,   107,     1,   135,   136,
       1,     1,   261,   262,   406,    49,   408,   495,   496,   497,
     957,   153,     0,   155,   134,   501,   502,   503,   945,   946,
     947,   132,    18,   970,   135,   136,  1120,   156,    28,   235,
     951,   952,   953,   153,     1,    24,   261,   262,   440,     1,
      16,     3,     1,   194,    48,  1139,     1,     0,     1,    75,
     194,     1,    75,    20,     1,     1,    32,   208,   209,     1,
      18,   381,     8,   174,   175,    20,   257,   258,   259,     1,
      37,    18,    14,   165,    75,    18,    76,     9,     1,    75,
      51,   232,    32,   194,   100,     8,   102,    76,    47,     1,
      22,    23,  1255,     1,   245,    48,    28,   208,   209,    75,
      61,   245,   213,   214,   215,    67,   217,   218,   219,   220,
     221,   222,   223,   304,   305,   257,   258,    75,   162,   230,
     231,   232,   233,   234,   261,   262,    92,   264,    75,   100,
     517,   102,    75,    99,   245,   106,   107,   257,   249,   330,
      16,     1,     1,    75,    76,   282,   283,     1,     8,     9,
     261,   262,    75,   264,   265,     9,   480,   454,   124,     1,
     484,   132,   304,    75,   135,   136,  1093,    75,  1262,   417,
      12,   282,   283,    32,  1095,    13,   356,   357,   194,   359,
     141,   142,   415,   144,   364,   365,   366,   382,   368,   369,
       1,  1138,   208,   209,   991,   992,   391,   994,   404,   405,
      18,   407,     1,   332,   333,   391,   925,   336,   337,   338,
     339,   340,   341,   342,   381,    75,    75,   183,   184,     1,
       8,    75,   351,   194,    75,    24,   192,     9,   957,   245,
      41,   490,   491,    75,    72,    73,    74,   208,   209,   498,
     959,   970,   213,   214,   215,     1,   217,   218,   219,   220,
     221,   222,   223,   379,    16,   746,   969,    75,    46,   230,
     231,   232,   233,   234,     1,   490,   491,   694,     1,   420,
      32,   759,   379,     1,   245,   761,   420,     1,   249,     1,
     707,    18,   473,   474,     8,   476,     8,    75,    21,   706,
     261,   262,   443,   264,   265,    28,    18,     1,   409,   443,
     451,     1,   413,     1,   415,     9,   417,   451,   419,   420,
       8,   282,   283,    75,    16,   426,   427,   719,   720,    75,
     722,    43,    22,    23,     1,   674,   675,     1,    28,   674,
     675,   473,   443,   294,   295,     9,     1,     1,    75,     1,
     451,     7,    75,    76,    18,     9,   457,    75,    40,    11,
       1,    75,   543,    75,     1,   675,     1,   677,     9,    21,
     684,     8,  1159,  1160,    41,    39,    28,    12,    72,    73,
      74,   508,   509,    75,    40,    75,    76,    75,   698,   490,
     491,  1100,    47,    48,   495,   496,   497,   498,   499,   500,
     501,   502,   503,   504,   505,   506,   507,   508,   509,   698,
     511,    75,  1121,  1122,   420,   516,   517,   794,     1,  1138,
     426,   427,  1253,  1254,    76,   802,   803,   804,   805,   806,
     807,   808,   809,     7,    75,     9,     1,   443,    75,    16,
      75,    15,     1,    17,     1,   451,     1,   403,   409,    48,
       1,    50,   413,    52,   415,    32,   417,     8,   419,   420,
      75,    18,     4,    46,     1,   426,   427,   637,   638,   588,
     589,     1,     1,   643,    18,   594,    18,    14,    33,    34,
      45,    11,   443,    42,  1249,     3,   605,   606,   658,   768,
     451,    90,    91,     8,   664,   665,   457,   667,    75,    98,
      18,    75,    44,   622,    19,     1,     1,   626,   627,   628,
     629,   630,     8,     9,   633,   634,    45,   636,    75,   768,
       1,   706,   718,   696,    75,   682,    44,     8,    43,   490,
     491,    75,    13,    75,   495,   496,   497,   498,   499,   500,
     501,   502,   503,   504,   505,   506,   507,   508,   509,    44,
     511,     1,   969,   768,    35,   516,   517,    75,     9,   154,
      75,     1,    18,     1,   779,   780,    47,    48,    18,   750,
       8,     9,    22,    23,    25,     1,  1407,  1408,    28,    75,
    1411,     1,     8,   182,    43,     1,   925,   979,     8,     1,
     925,    72,    73,    74,    75,    35,    51,     9,   937,   938,
     741,     1,   937,   938,   745,     8,     9,    47,    48,  1440,
    1441,   712,   713,   948,   928,   716,   717,  1133,   932,    75,
     959,     1,     1,     1,   959,    75,    76,    43,     8,     9,
       8,   941,   942,   943,    48,     1,    50,    75,    18,     1,
     741,  1128,    22,    23,   745,    45,     8,   102,    28,    75,
     960,   106,    32,    19,     1,    75,   757,     1,   759,    39,
     761,     8,   763,    75,    43,     1,   767,   768,   963,     1,
      43,   960,    75,   960,     1,   962,    90,   132,   779,   780,
      24,     4,   996,    10,     1,     1,    22,    23,     1,   790,
      70,   792,    28,   794,    10,    75,    76,    75,  1407,     0,
       1,   802,   803,   804,   805,   806,   807,   808,   809,     1,
       1,    43,   307,    75,   309,     1,   311,   312,   313,   314,
     315,   316,   317,     0,     1,    17,    43,     1,    75,    11,
      43,   901,   327,   903,   904,   905,    10,   907,   908,    75,
      76,     1,    69,    17,    71,     1,    38,    48,     8,     9,
       1,    43,    43,    69,     1,    71,    42,    49,   213,   214,
     215,  1100,    22,    23,    38,  1100,    40,     1,    28,    43,
       1,    48,     1,  1112,  1113,     9,    36,  1087,     7,    39,
     741,  1091,  1121,  1122,   745,    41,  1121,  1122,    35,  1099,
       1,    42,     0,     1,   249,    69,   757,    71,   759,    10,
     761,     1,   763,     1,     7,     1,   767,   768,     8,     9,
      70,     9,    43,     9,     1,    75,    76,  1127,   779,   780,
      18,     1,    22,    23,    22,    23,    22,    23,    28,   790,
      28,   792,    28,   794,  1148,     1,  1150,    40,  1125,    39,
      48,   802,   803,   804,   805,   806,   807,   808,   809,     1,
     991,   992,     1,   994,    41,     1,     5,   991,    69,     1,
      71,     3,    42,     1,    10,    44,     1,    33,    34,     1,
      70,    17,    70,     1,    70,    75,    76,    75,    76,    75,
      76,     1,     1,    15,    33,    20,     5,     7,    16,    41,
     991,   992,    38,   994,  1064,  1065,  1066,  1067,  1068,  1069,
    1070,  1071,    44,    49,    42,     0,     1,     1,  1078,  1079,
    1080,  1081,  1082,  1083,  1084,  1085,    10,  1252,  1253,  1254,
       1,  1040,  1041,  1042,  1043,  1044,  1045,  1046,  1047,  1048,
    1049,  1050,  1051,  1052,  1053,  1054,  1055,  1056,  1057,  1058,
    1059,  1060,  1061,  1062,  1063,     1,     5,     7,     4,     9,
       1,   546,   547,    48,   409,    15,     1,    17,   413,   554,
      41,    42,     0,     1,   419,     1,     1,     1,     1,   564,
     565,    16,     1,     1,    33,    69,    12,    71,    12,     1,
       9,    40,    17,    16,   579,   991,   992,     9,   583,   584,
      41,   586,     1,    22,    23,     1,    18,     0,     1,    28,
      22,    23,   457,    38,    10,    41,    28,    41,    43,    15,
      48,    17,    40,     1,    49,    75,  1157,  1158,  1159,  1160,
       1,     9,    10,     1,    33,    13,    14,     1,    16,    17,
     991,   992,    10,   994,    22,    23,    10,    25,    26,    27,
      28,    29,    30,    31,    45,    48,    75,    76,    70,     1,
      38,    39,    40,    75,    76,    43,  1157,  1158,  1159,  1160,
      41,    42,     1,    69,    16,    71,     0,     1,  1407,  1408,
       1,     1,  1407,  1408,    75,     1,  1411,    76,     8,     5,
      68,    69,    70,    71,     7,     1,     9,    75,    76,     1,
      42,    69,    15,    71,    17,    69,    12,    71,     1,  1413,
      12,    40,     1,  1438,  1439,  1440,  1441,    33,  1443,     1,
      41,    42,     8,  1427,    48,  1429,  1451,     9,  1453,    11,
       1,    72,    73,    74,  1265,    41,  1267,  1462,     1,    41,
      22,    23,    19,     1,    15,     1,    28,    40,     6,     7,
       8,     9,    41,    42,    40,    13,    14,    39,    16,    17,
      18,     1,    75,     1,    22,    23,    43,    25,    26,    27,
      28,    29,    30,    31,  1265,     1,  1267,    40,    36,    17,
      38,    39,    40,     9,    42,    41,     1,     1,    70,     1,
      33,     6,    18,    75,    76,     1,    22,    23,     1,     1,
      38,    41,    28,    17,    16,    43,  1157,  1158,  1159,  1160,
      68,    69,    70,    71,    17,     1,    18,    75,    76,     5,
      22,    23,     8,     9,    38,     1,    28,    13,    14,    43,
      16,    17,    18,     1,    40,    38,    22,    23,     1,    25,
      26,    27,    28,    29,    30,    31,    49,    33,     1,    75,
      76,     1,    38,    39,     1,    58,    42,    43,     1,    12,
       1,    11,     9,    43,    32,    41,     1,    65,    66,    12,
       1,    18,     1,    75,    76,    22,    23,    40,     9,     8,
       9,    28,    68,    69,    70,    71,    75,    18,    41,    75,
      76,    22,    23,    22,    23,    75,     1,    28,    41,    28,
      41,     6,     7,     8,     9,    75,    41,    36,    13,    14,
      39,    16,    17,     1,  1265,     1,  1267,    22,    23,     1,
      25,    26,    27,    28,    29,    30,    31,     5,    75,    76,
       1,    36,     1,    38,    39,    40,     1,     1,     9,     1,
       1,    70,    20,    43,    75,    76,    75,    76,     1,    35,
       1,     1,    17,    41,    15,    33,    17,     8,    40,     1,
      46,    47,    48,    68,    69,    70,    71,     9,     1,    11,
      75,    76,    41,    38,     1,    75,    18,    41,    43,    41,
      22,    23,     1,    10,    49,    40,    28,    40,     1,     1,
      17,    41,     1,     6,     7,     8,     9,    39,    17,     1,
      13,    14,     4,    16,    17,     1,     1,    16,    41,    22,
      23,    38,    25,    26,    27,    28,    29,    30,    31,    38,
      16,    16,    49,    36,    43,    38,    39,    40,    70,    41,
      49,    58,    59,    75,    76,  1020,  1021,  1022,  1023,  1024,
    1025,  1026,  1027,  1028,  1029,  1030,  1031,  1032,  1033,  1034,
    1035,  1036,  1037,  1038,  1039,    68,    69,    70,    71,     1,
      43,     1,    75,    76,     1,    33,    34,     9,    10,     9,
       7,    13,    14,    12,    16,    17,    18,     1,     1,     1,
      22,    23,    75,    25,    26,    27,    28,    29,    30,    31,
       1,     1,    75,    17,    17,    17,    38,    39,    40,     1,
      42,    43,    41,     1,    43,    16,    16,     1,     1,    11,
       8,     9,    33,    34,    38,    38,    38,    40,    11,    43,
      18,    43,    16,     1,    22,    23,    68,    69,    70,    71,
      28,     9,    10,    75,    76,    13,    14,    15,    16,    17,
      18,    39,     1,    75,    22,    23,     1,    25,    26,    27,
      28,    29,    30,    31,     9,    12,    75,    16,     1,     1,
      38,     1,    40,    18,    42,    43,     9,    22,    23,     9,
       5,     6,    70,    28,    16,    18,    11,    75,    76,    22,
      23,    16,    42,     1,    41,    28,    43,     1,     6,    32,
      68,    69,    70,    71,     8,     9,    39,    75,    76,    13,
      14,     1,    16,    17,    18,    40,     6,   320,    22,    23,
     323,    25,    26,    27,    28,    29,    30,    31,    35,     1,
      75,    76,    36,    42,    38,    39,    40,    70,    42,    46,
      47,    48,    75,    76,    16,     1,     1,     1,     1,     1,
       1,    33,    34,     8,    10,     8,     9,    75,     9,    11,
      16,    17,    16,     1,    68,    69,    70,    71,     1,    22,
      23,    75,    76,    33,    34,    28,     9,    10,    11,    17,
      13,    14,    38,    16,    17,    18,    39,    43,    75,    22,
      23,     1,    25,    26,    27,    28,    29,    30,    31,    75,
      38,    11,    40,     1,     1,    38,    39,    40,     5,    42,
      11,     9,    10,     1,    43,    13,    14,    70,    16,    17,
      18,     9,    75,    76,    22,    23,    11,    25,    26,    27,
      28,    29,    30,    31,    32,    68,    69,    70,    71,     1,
      38,    39,    75,    76,    42,    43,     1,     1,    10,   344,
     321,   322,     1,   324,     1,    10,    10,   352,     5,     6,
      15,     8,    17,    17,    11,    12,    28,    29,    17,    16,
      68,    69,    70,    71,     1,     1,     6,    75,    76,     5,
      16,     8,     8,     9,    38,    10,    33,    13,    14,    38,
      16,    17,    17,    40,    43,    49,    22,    23,     3,    25,
      26,    27,    28,    29,    30,    31,   345,    33,     1,   348,
       1,    75,    38,    39,    69,     8,    71,    43,     9,    10,
     233,   234,    13,    14,    75,    16,    17,    18,    75,    75,
       1,    22,    23,    75,    25,    26,    27,    28,    29,    30,
      31,    75,    68,    69,    70,    71,    17,    38,    39,    75,
      76,    42,    43,     6,     1,     6,     1,     1,    11,    45,
      11,     8,     9,    16,    46,    16,    10,    38,   954,   955,
     956,    18,    43,    17,     1,    22,    23,    68,    69,    70,
      71,    28,     9,    10,    75,    76,    13,    14,    15,    16,
      17,    18,    39,    11,    38,    22,    23,     5,    25,    26,
      27,    28,    29,    30,    31,    49,   346,   347,     1,   349,
      75,    38,    20,    40,    58,    42,    43,    10,     1,    10,
       1,     1,     3,    70,    17,    33,    17,    10,    75,    76,
      10,   220,   221,   222,    17,    43,    75,    17,     1,   949,
     950,    68,    69,    75,    71,    38,     9,    10,    75,    76,
      13,    14,    15,    16,    17,    38,    49,    14,    38,    22,
      23,    41,    25,    26,    27,    28,    29,    30,    31,    49,
      75,    75,     1,     1,    75,    38,     1,    40,    58,    59,
      43,    10,    10,     8,     9,     1,     1,     3,    75,    17,
     361,   362,   363,    18,    15,    10,    17,    22,    23,    28,
      29,    75,    17,    28,    75,    68,    69,    70,    71,     1,
      38,    36,    75,    76,    39,    43,    76,     9,    10,    11,
      75,    13,    14,    38,    16,    17,    75,     1,    43,     3,
      22,    23,    75,    25,    26,    27,    28,    29,    30,    31,
       1,    69,     3,    71,     1,    70,    38,    39,    40,    75,
      75,    76,     9,    10,    42,    42,    13,    14,    42,    16,
      17,    18,   504,   505,   506,    22,    23,    42,    25,    26,
      27,    28,    29,    30,    31,    16,    68,    69,    70,    71,
    1015,    38,  1017,    75,    76,    42,    43,     0,     1,     3,
       1,     1,     1,     1,    75,     5,     9,    75,     9,    10,
      13,    10,    10,    75,    17,    18,    17,    18,    17,    19,
      20,    68,    69,    70,    71,   499,   500,    75,    75,    76,
      28,    29,    75,    33,    75,    38,    39,    38,    39,    38,
      43,    42,    43,    75,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,     1,    75,    60,    61,    62,
      63,    64,     1,     9,    10,    75,    75,    13,    14,    75,
      16,    17,    75,    75,    75,     1,    22,    23,    17,    25,
      26,    27,    28,    29,    30,    31,    32,    75,     1,    75,
      75,    17,    38,    39,    75,     8,     9,    43,    75,    38,
       1,     1,     1,    75,    43,    18,    75,    75,    75,    22,
      23,    10,    38,    75,    75,    28,    17,    43,    17,     1,
      75,    75,    68,    69,    70,    71,    39,     9,    10,    75,
      76,    13,    14,    15,    16,    17,    18,    38,    75,    38,
      22,    23,    43,    25,    26,    27,    28,    29,    30,    31,
      49,    75,     1,     5,    41,    31,    38,    70,    40,     8,
       9,    43,    75,    76,     1,    87,     1,   398,    48,    18,
     165,   391,     8,    22,    23,    10,   467,   389,   383,    28,
      17,   960,    17,     1,  1133,    25,    68,    69,   249,    71,
      39,     9,    10,    75,    76,    13,    14,    15,    16,    17,
      55,    38,   302,    38,    22,    23,    43,    25,    26,    27,
      28,    29,    30,    31,    49,   134,   541,     1,  1019,   327,
      38,    70,    40,    58,    59,    43,    75,    76,     1,    13,
      14,   823,    16,   319,   344,     1,     9,    10,   360,     5,
      -1,    25,    26,    27,    17,    18,    -1,     1,    -1,    -1,
      68,    69,    -1,    71,    20,     9,    10,    75,    76,    13,
      14,    15,    16,    17,    -1,    38,    39,    33,    22,    23,
      43,    25,    26,    27,    28,    29,    30,    31,    -1,    -1,
      -1,    -1,     1,    -1,    38,    69,    40,    71,    -1,    43,
       9,    10,    -1,    -1,    13,    14,    -1,    16,    17,    18,
      -1,    -1,    75,    22,    23,    -1,    25,    26,    27,    28,
      29,    30,    31,    -1,    68,    69,     1,    71,     1,    38,
      -1,    75,    76,    42,    43,    10,     9,    10,    -1,    -1,
      13,    14,    17,    16,    17,    18,    -1,    -1,    -1,    22,
      23,    -1,    25,    26,    27,    28,    29,    30,    31,    68,
      69,    -1,    71,    38,    -1,    38,    75,    76,    43,    -1,
      43,    -1,    -1,     1,    49,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    10,    58,    59,    -1,    -1,    -1,    -1,    17,
      -1,    -1,     1,    -1,    -1,    68,    69,    -1,    71,    -1,
       9,    10,    75,    76,    13,    14,    15,    16,    17,    18,
      38,     1,    -1,    22,    23,     1,    25,    26,    27,    28,
      10,    49,     8,     9,    -1,    -1,     1,    17,    -1,    38,
      58,    40,    18,    -1,    43,    10,    22,    23,    13,    14,
      -1,    16,    28,    -1,    -1,    -1,    32,    -1,    38,    -1,
      25,    26,    27,    39,    -1,    -1,     1,    -1,    -1,    68,
      69,    70,    71,    -1,     9,    10,    75,    76,    13,    14,
      15,    16,    17,    -1,    -1,    -1,    -1,    22,    23,    -1,
      25,    26,    27,    28,    70,    -1,    -1,    -1,    -1,    75,
      76,     1,    -1,    38,    69,    40,    71,    -1,    43,     9,
      10,    -1,    -1,    13,    14,    -1,    16,    17,    18,    -1,
      -1,    -1,    22,    23,    -1,    25,    26,    27,    28,    -1,
       1,    -1,    -1,    68,    69,    70,    71,    -1,    38,     1,
      75,    76,    -1,    43,     0,     1,    17,    -1,    10,    -1,
      -1,    13,    14,     9,    16,    -1,    -1,    13,    -1,    -1,
      -1,    17,    -1,    25,    26,    27,    -1,    38,    68,    69,
      70,    71,    43,     1,    -1,    75,    76,    -1,    49,    -1,
       8,     9,    38,    39,    -1,    -1,    -1,    43,    -1,    -1,
      18,    -1,    48,    49,    22,    23,    -1,    -1,    -1,    -1,
      28,    -1,    -1,    -1,    60,    61,    62,    69,    64,    71,
      -1,    39,     1,    -1,    -1,    -1,    72,    73,    74,    75,
       9,    10,     1,    -1,    -1,    -1,    -1,    -1,    17,    18,
      -1,    10,    -1,    22,    23,    14,     1,    -1,    17,    28,
      -1,    -1,    70,    -1,     9,    10,    -1,    75,    76,    38,
      39,    40,    17,    18,    43,    -1,    -1,    22,    23,    38,
      -1,     1,    41,    28,    43,    -1,    -1,    -1,     1,     9,
      49,    -1,    -1,    38,    39,    40,     1,    10,    43,    58,
      59,    70,    22,    23,     9,    10,    75,    76,    28,    -1,
      -1,    -1,    17,    18,    -1,    28,    29,    22,    23,    39,
       1,    -1,    -1,    28,    -1,    70,    -1,    32,     9,    10,
      75,    76,    -1,    38,    39,    -1,    17,    18,    43,    -1,
      -1,    22,    23,    -1,    -1,     1,    -1,    28,    -1,    -1,
      70,    32,    -1,     9,    10,    75,    76,    38,    39,    -1,
      -1,    17,    43,    -1,     1,    70,    22,    23,    -1,     1,
      75,    76,    28,    10,    -1,    -1,     1,     9,    10,    -1,
      17,    -1,    38,    39,    40,    17,    -1,    43,     1,    70,
      22,    23,    17,    -1,    75,    76,    28,    10,    -1,    -1,
      -1,    38,    -1,    -1,    -1,    -1,    38,    39,    40,     1,
      -1,    43,    49,    38,    70,    28,    29,     9,    10,    75,
      76,    58,    59,    -1,    49,    17,    18,    -1,    -1,    -1,
      22,    23,     1,    58,    59,    -1,    28,    -1,    70,    -1,
       9,    10,     1,    75,    76,    -1,    38,    39,    17,    18,
      -1,    43,    -1,    22,    23,     1,    -1,    -1,    17,    28,
      -1,    -1,    -1,     9,    10,    -1,    -1,    -1,    -1,    38,
      39,    17,     1,    -1,    43,    -1,    22,    23,    70,    38,
       1,    10,    28,    75,    76,    -1,    32,    -1,    17,    10,
      49,    -1,    38,    39,     1,    -1,    17,    43,    -1,    58,
      59,    70,     9,    10,    -1,    -1,    75,    76,    -1,    38,
      17,    40,    -1,    -1,    43,    22,    23,    38,     1,    40,
       1,    28,    43,    -1,    70,    32,     9,     8,     9,    75,
      76,    38,    39,    -1,    -1,    18,    43,    18,     1,    22,
      23,    22,    23,    -1,    -1,    28,     9,    28,    69,    -1,
      71,    -1,    -1,    36,    -1,    18,    39,    -1,    39,    22,
      23,    -1,     1,    70,     1,    28,     1,    -1,    75,    76,
       9,    10,     9,    -1,     1,    10,    39,    -1,    17,    18,
      -1,    18,    17,    10,    -1,    22,    23,    70,     1,    70,
      17,    28,    75,    76,    75,    76,     9,    -1,    -1,    38,
      39,    -1,    39,    38,    43,     1,    -1,    70,    43,    22,
      23,    38,    75,    76,    49,    28,    43,    -1,    -1,    32,
      -1,    17,    49,    58,    59,    -1,    39,     1,    -1,    -1,
      -1,    58,    59,    70,     8,     9,    75,    -1,    75,    76,
      -1,    -1,    38,    17,    18,    -1,    -1,    43,    -1,    -1,
      -1,    -1,    -1,    49,    -1,    -1,     1,    70,    -1,    -1,
      -1,    35,    75,    76,    38,    39,    -1,    -1,     1,    43,
      -1,    -1,    17,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    17,    -1,    60,    61,    62,    63,
      64,     1,    -1,    38,    -1,    -1,    -1,    -1,    -1,     9,
      10,    75,    -1,    13,    49,    38,    -1,    17,    18,    -1,
      -1,    -1,    -1,    58,    -1,    -1,    49,    -1,     1,    -1,
      -1,    -1,     1,    -1,    -1,    58,     9,    10,    38,    39,
      13,    10,    -1,    43,    17,    18,    -1,    -1,    17,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    38,    39,    -1,    -1,    38,
      43,    40,    -1,    -1,    43,    75,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,     1,    -1,     1,    -1,     1,    -1,    -1,    -1,
       9,    10,    75,    10,    13,    10,    -1,    -1,    17,    18,
      -1,    -1,    17,    -1,    -1,    -1,    -1,    -1,    -1,     1,
      -1,    28,    29,     1,    -1,    -1,    -1,     9,    10,    38,
      39,    13,    10,    38,    43,    17,    18,    -1,    43,    17,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    38,    39,    -1,    -1,
      38,    43,    40,    -1,    -1,    43,    75,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,     1,    -1,    -1,    -1,     1,    -1,    -1,
      -1,     9,    10,    75,    -1,    13,    10,    -1,    -1,    17,
      18,    -1,    -1,    17,    -1,    -1,    -1,    -1,    -1,    -1,
       1,    -1,    -1,    -1,     1,    -1,    -1,    -1,     9,    10,
      38,    39,    13,    10,    38,    43,    17,    18,    -1,    43,
      17,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    38,    39,    -1,
      -1,    38,    43,    40,    -1,    -1,    43,    75,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,     1,    -1,    -1,    -1,     1,    -1,
      -1,    -1,     9,    10,    75,    -1,    13,    10,    -1,    -1,
      17,    18,    -1,    -1,    17,    -1,    -1,    -1,    -1,    -1,
      -1,     1,    -1,    -1,    -1,     1,    -1,    -1,    -1,     9,
      10,    38,    39,    13,    10,    38,    43,    17,    18,    -1,
      43,    17,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    38,    39,
      -1,    -1,    38,    43,    40,    -1,    -1,    43,    75,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,     1,    -1,    -1,    -1,     1,
      -1,    -1,    -1,     9,    10,    75,    -1,    13,    10,    -1,
      -1,    17,    18,    -1,    -1,    17,    -1,    -1,    -1,    -1,
      -1,    -1,     1,    -1,    -1,    -1,     1,    -1,    -1,    -1,
       9,    10,    38,    39,    13,    10,    38,    43,    17,    18,
      -1,    43,    17,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    38,
      39,    -1,    -1,    38,    43,    40,    -1,    -1,    43,    75,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,     1,    -1,    -1,    -1,
       1,    -1,    -1,    -1,     9,    10,    75,    -1,    13,    10,
      -1,    -1,    17,    18,    -1,    -1,    17,    -1,    -1,    -1,
      -1,    -1,    -1,     1,    -1,    -1,    -1,     1,    -1,    -1,
      -1,     9,    10,    38,    39,    13,    10,    38,    43,    17,
      18,    -1,    43,    17,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      38,    39,    -1,    -1,    38,    43,    40,    -1,    -1,    43,
      75,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,     1,    -1,    -1,
      -1,     1,    -1,    -1,    -1,     9,    10,    75,    -1,    13,
      10,    -1,    -1,    17,    18,    -1,    -1,    17,    -1,    -1,
      -1,    -1,    -1,    -1,     1,    -1,    -1,    -1,     1,    -1,
      -1,    -1,     9,    10,    38,    39,    13,    10,    38,    43,
      17,    18,    -1,    43,    17,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    38,    39,    -1,    -1,    38,    43,    40,    -1,    -1,
      43,    75,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,     1,    -1,
      -1,    -1,     1,    -1,    -1,    -1,     9,    10,    75,    -1,
      13,    10,    -1,    -1,    17,    18,    -1,    -1,    17,    -1,
      -1,    -1,    -1,    -1,    -1,     1,    -1,    -1,    -1,     1,
      -1,    -1,    -1,     9,    10,    38,    39,    13,    10,    38,
      43,    17,    18,    -1,    43,    17,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    38,    39,    -1,    -1,    38,    43,    40,    -1,
      -1,    43,    75,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,     1,
      -1,    -1,    -1,     1,    -1,    -1,    -1,     9,    10,    75,
      -1,    13,    10,    -1,    -1,    17,    18,    -1,    -1,    17,
      -1,    -1,    -1,    -1,    -1,    -1,     1,    -1,    -1,    -1,
       1,    -1,    -1,    -1,     9,    10,    38,    39,    13,    10,
      38,    43,    17,    18,    -1,    43,    17,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    38,    39,    -1,    -1,    38,    43,    40,
      -1,    -1,    43,    75,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
       1,    -1,    -1,    -1,     1,    -1,    -1,    -1,     9,    10,
      75,    -1,    13,    10,    -1,    -1,    17,    18,    -1,    -1,
      17,    -1,    -1,    -1,    -1,    -1,    -1,     1,    -1,    -1,
      -1,     1,    -1,    -1,    -1,     9,    10,    38,    39,    13,
      10,    38,    43,    17,    18,    -1,    43,    17,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    38,    39,    -1,    -1,    38,    43,
      -1,    -1,    -1,    43,    75,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,     1,    -1,    -1,    -1,     1,    -1,    -1,    -1,     9,
      10,    75,    -1,    13,    10,    -1,    -1,    17,    18,    -1,
      -1,    17,    -1,    -1,    -1,    -1,    -1,    -1,     1,    -1,
      -1,    -1,     1,    -1,    -1,    -1,     9,    10,    38,    39,
      13,    10,    38,    43,    17,    18,    -1,    43,    17,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    38,    39,    -1,    -1,    38,
      43,    -1,    -1,    -1,    43,    75,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,     1,    -1,     1,    -1,     1,    -1,     1,    -1,
       9,    -1,    75,    10,    -1,    10,    -1,    10,    17,    18,
      17,    -1,    17,    -1,    17,    -1,    -1,    -1,    -1,    -1,
       1,    -1,    -1,    -1,    -1,    -1,    35,     8,     9,    38,
      39,    38,    13,    38,    43,    38,    17,    18,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    -1,
      -1,    60,    61,    62,    63,    64,    -1,    38,    39,    -1,
      -1,    -1,    43,    -1,    -1,    -1,    75,    -1,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    -1,    -1,    60,
      61,    62,    63,    64,     1,    -1,    -1,     1,     1,    -1,
      -1,    -1,     9,    10,    75,    -1,    10,    10,    -1,    -1,
      17,    18,    -1,    17,    17,    -1,    -1,     5,     6,    -1,
      -1,     1,    -1,    11,    12,    -1,    -1,    -1,    16,     9,
      10,    38,    39,    -1,    38,    38,    43,    17,    18,    43,
      43,    -1,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    40,    60,    61,    62,    63,    64,    38,    39,
      -1,    -1,    -1,    43,    -1,    69,    -1,    71,    75,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    -1,
      60,    61,    62,    63,    64,     1,    -1,    -1,     1,     1,
      -1,    -1,    -1,     9,    10,    75,    -1,    10,    10,    -1,
      -1,    17,    18,    -1,    17,    17,    -1,    -1,    -1,    -1,
      -1,    -1,     1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       9,    10,    38,    39,    -1,    38,    38,    43,    17,    18,
      43,    43,    -1,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    -1,    60,    61,    62,    63,    64,    38,
      39,    -1,    -1,    -1,    43,    -1,    69,    -1,    71,    75,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      -1,    60,    61,    62,    63,    64,     1,    -1,    -1,     1,
       1,    -1,    -1,    -1,     9,    10,    75,    -1,    10,    10,
      -1,    -1,    17,    18,    -1,    17,    17,    -1,    -1,    -1,
      -1,    -1,    -1,     1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     9,    10,    38,    39,    -1,    38,    38,    43,    17,
      18,    43,    43,    -1,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    -1,    60,    61,    62,    63,    64,
      38,    39,    -1,    -1,    -1,    43,    -1,    -1,    -1,    -1,
      75,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    -1,    60,    61,    62,    63,    64,     1,    -1,    -1,
       1,     1,    -1,    -1,    -1,     9,    10,    75,    -1,    10,
      10,    -1,    -1,    17,    18,    -1,    17,    17,    -1,    -1,
      -1,    -1,    -1,    -1,     1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     9,    10,    38,    39,    -1,    38,    38,    43,
      17,    18,    43,    43,    -1,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    -1,    60,    61,    62,    63,
      64,    38,    39,    -1,    -1,    -1,    43,    -1,    -1,    -1,
      -1,    75,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    -1,    60,    61,    62,    63,    64,     1,    -1,
      -1,     1,     1,    -1,    -1,    -1,     9,    10,    75,    -1,
      10,    10,    -1,    -1,    17,    18,    -1,    17,    17,    -1,
      -1,    -1,    -1,    -1,    -1,     1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     9,    10,    38,    39,    -1,    38,    38,
      43,    17,    18,    43,    43,    -1,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    -1,    60,    61,    62,
      63,    64,    38,    39,    -1,    -1,    -1,    43,    -1,    -1,
      -1,    -1,    75,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    -1,    60,    61,    62,    63,    64,     1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     9,    10,    75,
      -1,    -1,    -1,    -1,    -1,    17,    18,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     9,    10,    38,    39,    -1,    -1,
      -1,    43,    17,    18,    -1,    -1,    -1,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    -1,    60,    61,
      62,    63,    64,    38,    39,    -1,    -1,    -1,    43,    -1,
      -1,    -1,    -1,    75,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    -1,    60,    61,    62,    63,    64,
       1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     9,    10,
      75,    -1,    -1,    -1,    -1,    -1,    17,    18,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     9,    10,    38,    39,    -1,
      -1,    -1,    43,    17,    18,    -1,    -1,    -1,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    -1,    60,
      61,    62,    63,    64,    38,    39,    -1,    -1,    -1,    43,
      -1,    -1,    -1,    -1,    75,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    -1,    60,    61,    62,    63,
      64,     1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     9,
      10,    75,    -1,    -1,    -1,    -1,    -1,    17,    18,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     9,    10,    38,    39,
      -1,    -1,    -1,    43,    17,    18,    -1,    -1,    -1,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    -1,
      60,    61,    62,    63,    64,    38,    39,    -1,    -1,    -1,
      43,    -1,    -1,    -1,    -1,    75,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    -1,    60,    61,    62,
      63,    64,     1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       9,    10,    75,    -1,    -1,    -1,    -1,    -1,    17,    18,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     9,    10,    38,
      39,    -1,    -1,    -1,    43,    17,    18,    -1,    -1,    -1,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      -1,    60,    61,    62,    63,    64,    38,    39,    -1,    -1,
      -1,    43,    -1,    -1,    -1,    -1,    75,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    -1,    60,    61,
      62,    63,    64,     1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     9,    10,    75,    -1,    -1,    -1,    -1,    -1,    17,
      18,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     9,    10,
      38,    39,    -1,    -1,    -1,    43,    17,    18,    -1,    -1,
      -1,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    -1,    60,    61,    62,    63,    64,    38,    39,    -1,
      -1,    -1,    43,    -1,    -1,    -1,    -1,    75,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,     1,    60,
      61,    62,    63,    64,    -1,    -1,     9,     1,     1,    -1,
      13,    -1,    -1,    -1,    75,    18,    10,    10,    -1,    -1,
      -1,    -1,    -1,    17,    17,     1,    -1,    -1,    -1,    -1,
      33,    34,     8,     9,    -1,    -1,    39,    13,    -1,    -1,
      -1,    -1,    18,    -1,    38,    38,    -1,    50,    51,    52,
      53,    54,    55,    56,    57,    49,    49,    60,    61,    62,
      63,    64,    -1,    39,    58,    59,    -1,    -1,    -1,    -1,
      -1,    -1,    75,    -1,    50,    51,    52,    53,    54,    55,
      56,    57,    -1,     1,    60,    61,    62,    63,    64,    -1,
       8,     9,     1,    -1,    -1,    13,    -1,    -1,    -1,    75,
      18,    10,    -1,     1,    -1,    -1,    -1,    -1,    17,    -1,
       1,     9,    -1,    -1,    -1,    13,    -1,    -1,     9,    10,
      18,    39,    13,    -1,    -1,    -1,    17,    18,    -1,    38,
      -1,    -1,    50,    51,    52,    53,    54,    55,    56,    57,
      49,    39,    60,    61,    62,    63,    64,    38,    39,    58,
      -1,    -1,    43,    -1,    -1,    -1,    -1,    75,    49,    -1,
      -1,    -1,    60,    61,    62,    -1,    64,    58,    59,    60,
      61,    62,    -1,    64,    72,    73,    74,    75,     1,     1,
      -1,    72,    73,    74,    75,     8,     9,     1,    10,    -1,
      13,    13,    14,    -1,    16,    18,    10,    -1,    -1,    13,
      14,    -1,    16,    25,    26,    27,    -1,    -1,     5,    -1,
      -1,    25,    26,    27,    11,    12,    39,    -1,     1,    16,
      -1,    -1,    -1,    20,    -1,    -1,     9,    50,    51,    52,
      53,    54,    55,    56,    57,    18,    33,    60,    61,    62,
      63,    64,    -1,    40,    -1,    -1,     1,    69,    -1,    71,
      33,    34,    75,     8,     9,    69,    39,    71,    -1,    -1,
      -1,    -1,    -1,    18,    -1,    -1,     1,    50,    51,    52,
      53,    54,    55,    56,    57,    10,    -1,    60,    61,    62,
      63,    64,    17,    -1,    39,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    75,    -1,    -1,    50,    51,    52,    53,    54,
      55,    56,    57,    38,     1,    60,    61,    62,    63,    64,
      -1,    -1,     9,    -1,    49,    -1,    13,    -1,    -1,    -1,
      75,    18,    -1,    -1,    -1,     1,    -1,    -1,    -1,    -1,
       1,    -1,    -1,    -1,    10,    -1,    -1,     8,     9,    -1,
      -1,    17,    39,    -1,    -1,    -1,    -1,    18,    -1,    -1,
      -1,    -1,    -1,    50,    51,    52,    53,    54,    55,    56,
      57,     1,    38,    60,    61,    62,    63,    64,    39,    -1,
      10,    -1,    -1,    49,    14,    -1,    -1,    17,    75,    50,
      51,    52,    53,    54,    55,    56,    57,    -1,     1,    60,
      61,    62,    63,    64,    -1,    -1,     9,    -1,    38,    -1,
      13,    41,    42,    43,    75,    18,    -1,    -1,    -1,    49,
      -1,    -1,    -1,    -1,     1,    -1,    -1,    -1,    58,    59,
      -1,     8,     9,    -1,    -1,    -1,    39,    -1,    -1,    -1,
      -1,    18,    -1,    -1,    -1,    -1,    -1,    50,    51,    52,
      53,    54,    55,    56,    57,     1,    -1,    60,    61,    62,
      63,    64,    39,     9,    10,    -1,    -1,    13,    -1,    -1,
      -1,    17,    75,    50,    51,    52,    53,    54,    55,    56,
      57,    -1,     1,    60,    61,    62,    63,    64,    -1,    -1,
       9,    -1,    38,    39,    13,    -1,    -1,    43,    75,    18,
      -1,    -1,    -1,    49,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    58,    59,    60,    61,    62,    -1,    64,    -1,
      39,    -1,    -1,    -1,    -1,    -1,    72,    73,    74,    75,
      -1,    50,    51,    52,    53,    54,    55,    56,    57,    -1,
       1,    60,    61,    62,    63,    64,    -1,     8,     9,     1,
      -1,    -1,    -1,    -1,    -1,    -1,    75,    18,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    -1,     1,    -1,    -1,
      -1,     1,    -1,    -1,    -1,     9,    10,    -1,    39,    13,
      10,    -1,    -1,    17,    -1,    -1,    38,    17,    -1,    50,
      51,    52,    53,    54,    55,    56,    57,    49,    -1,    60,
      61,    62,    63,    64,    38,    39,    -1,     1,    38,    43,
      -1,    41,    42,    -1,    75,    49,    10,    -1,    -1,    49,
      14,    -1,    -1,    17,    58,    59,    60,    61,    62,    -1,
      64,    -1,    -1,    -1,     1,    -1,    -1,    -1,    72,    73,
      74,    75,     9,    10,    38,    -1,    13,    -1,    42,    43,
      17,    -1,    -1,    -1,    -1,    49,    -1,    -1,    -1,    -1,
      -1,     1,    -1,    -1,    58,    59,    -1,    -1,    -1,     9,
      10,    38,    39,    13,    -1,    -1,    43,    17,    -1,    -1,
      -1,    -1,    49,    -1,    -1,    -1,    -1,    -1,     1,    -1,
      -1,    58,    59,    60,    61,    62,     9,    64,    38,    39,
      13,    -1,    -1,    43,    -1,    72,    73,    74,    75,    49,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    58,    59,
      60,    61,    62,    -1,    64,    -1,    39,    -1,     1,    -1,
      -1,    -1,    72,    73,    74,    75,     9,    10,    -1,    -1,
      13,    -1,    -1,    -1,    17,    -1,    -1,    60,    61,    62,
      -1,    64,    -1,    -1,    -1,     1,    -1,    -1,    -1,    72,
      73,    74,    75,     9,    10,    38,    39,    13,    -1,    -1,
      43,    17,    -1,    -1,    -1,    -1,    49,    -1,    -1,    -1,
      -1,    -1,     1,    -1,    -1,    58,    59,    60,    61,    62,
       9,    64,    38,    39,    13,    -1,    -1,    43,    -1,    72,
      73,    74,    75,    49,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    58,    59,    60,    61,    62,    -1,    64,    -1,
      39,    -1,     1,    -1,    -1,    -1,    72,    73,    74,    75,
       9,    10,    -1,    -1,    13,    -1,    -1,    -1,    17,    -1,
      -1,    60,    61,    62,    -1,    64,    -1,    -1,    -1,     1,
      -1,    -1,    -1,    72,    73,    74,    75,     9,    10,    38,
      39,    13,    -1,    -1,    43,    17,    -1,    -1,    -1,    -1,
      49,    -1,    -1,    -1,    -1,    -1,    -1,     1,    -1,    58,
      59,    60,    61,    62,    -1,    64,    38,    39,    -1,    13,
      14,    43,    16,    72,    73,    74,    75,    49,    -1,    -1,
      -1,    25,    26,    27,    -1,    -1,    58,    59,    60,    61,
      62,    -1,    64,    -1,    -1,    -1,     1,    -1,    -1,    -1,
      72,    73,    74,    75,     9,    10,    -1,    -1,    13,    -1,
      -1,     1,    17,    -1,    -1,     5,     6,    -1,     8,    -1,
      -1,    11,    12,     1,    -1,    69,    16,    71,    -1,    -1,
      -1,     9,    10,    38,    39,    13,    -1,    -1,    43,    17,
      -1,    -1,    -1,    33,    49,    -1,    -1,    -1,    -1,    -1,
      40,     1,    -1,    58,    59,    60,    61,    62,    -1,    64,
      38,    39,    -1,    13,    14,    43,    16,    72,    73,    74,
      75,    49,    -1,    -1,    -1,    25,    26,    27,    -1,    -1,
      58,    59,    60,    61,    62,    75,    64,    -1,    -1,    -1,
       1,    -1,    -1,    -1,    72,    73,    74,    75,     9,    10,
      -1,    -1,    13,    -1,     1,    -1,    17,    -1,    -1,    -1,
      -1,    -1,    -1,    10,    -1,    -1,    -1,     1,    -1,    69,
      17,    71,    -1,    -1,    -1,     9,    10,    38,    39,    13,
      -1,    -1,    43,    17,    -1,    -1,    -1,    -1,    49,    -1,
      -1,    38,    -1,    -1,    41,    42,    -1,    58,    59,    60,
      61,    62,    49,    64,    38,    39,    -1,     1,    -1,    43,
      -1,    72,    73,    74,    75,    49,    10,    -1,    -1,    -1,
       1,    -1,    -1,    17,    58,    59,    60,    61,    62,    10,
      64,    -1,    -1,    -1,     1,    -1,    17,    -1,    72,    73,
      74,    75,     9,    10,    38,    -1,    13,    -1,    42,    43,
      17,    -1,    -1,    -1,    -1,    49,    -1,    38,    -1,    -1,
      -1,     1,    -1,    -1,    58,    59,    -1,    -1,    49,     9,
      10,    38,    39,    13,    -1,    -1,    43,    17,    -1,    -1,
      -1,    -1,    49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    58,    59,    60,    61,    62,    -1,    64,    38,    39,
      -1,     1,    -1,    43,    -1,    72,    73,    74,    75,    49,
      10,    -1,    -1,    -1,     1,    -1,    -1,    17,    58,    59,
      60,    61,    62,    10,    64,    -1,    -1,    -1,     1,    -1,
      17,    -1,    72,    73,    74,    75,     9,    10,    38,    -1,
      13,    -1,    -1,    43,    17,    -1,    -1,    -1,    -1,    49,
      -1,    38,    -1,    -1,    -1,     1,    -1,    -1,    58,    59,
      -1,    -1,    49,     9,    10,    38,    39,    13,    -1,    -1,
      43,    17,    -1,    -1,    -1,    -1,    49,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    58,    59,    60,    61,    62,
      -1,    64,    38,    39,    -1,     1,    -1,    43,    -1,    72,
      73,    74,    75,    49,    10,    -1,    -1,    -1,     1,    -1,
      -1,    17,    58,    59,    60,    61,    62,    10,    64,    -1,
      -1,    -1,     1,    -1,    17,    -1,    72,    73,    74,    75,
       9,    10,    38,    -1,    13,    -1,    -1,    43,    17,    -1,
      -1,    -1,    -1,    49,    -1,    38,    -1,    -1,    -1,     1,
      -1,    -1,    58,    59,    -1,    -1,    49,     9,    10,    38,
      39,    13,    -1,    -1,    43,    17,    -1,    -1,    -1,    -1,
      49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    58,
      59,    60,    61,    62,    -1,    64,    38,    39,    -1,     1,
      -1,    43,    -1,    72,    73,    74,    75,    49,    10,    -1,
      -1,    -1,     1,    -1,    -1,    17,    58,    59,    60,    61,
      62,    10,    64,    -1,    -1,    -1,     1,    -1,    17,    -1,
      72,    73,    74,    75,     9,    10,    38,    -1,    13,    -1,
      -1,    43,    17,    -1,    -1,    -1,    -1,    49,    -1,    38,
      -1,    -1,    -1,     1,    -1,    -1,    58,    59,    -1,    -1,
      49,     9,    10,    38,    39,    13,    -1,    -1,    43,    17,
      -1,    -1,    -1,    -1,    49,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    58,    59,    60,    61,    62,    -1,    64,
      38,    39,    -1,     1,    -1,    43,    -1,    72,    73,    74,
      75,    49,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      58,    59,    60,    61,    62,    -1,    64,    -1,    -1,    -1,
       1,    -1,     1,    -1,    72,    73,    74,    75,     9,    10,
      38,    10,    13,    -1,    -1,    43,    17,    -1,    17,     1,
      -1,    49,    -1,    -1,    -1,    -1,     1,    -1,    10,    -1,
      58,    59,    -1,    -1,     9,    17,    -1,    38,    39,    38,
      -1,    -1,    43,    18,    -1,    -1,     1,    -1,    49,    -1,
      49,    -1,    -1,    -1,    -1,    10,    38,    58,    59,    60,
      61,    62,    17,    64,    39,    -1,    -1,    49,    -1,    -1,
      -1,    72,    73,    74,    75,    50,    51,    52,    53,    54,
      55,    56,    57,    38,     1,    60,    61,    62,    63,    64,
      -1,     1,     9,     1,    49,    -1,    -1,    -1,     8,     9,
      75,    18,    10,    13,    -1,    -1,    -1,    -1,    -1,    17,
      -1,     1,    -1,    -1,    -1,    -1,    -1,    -1,     8,     9,
      -1,    -1,    39,    13,    -1,    -1,    -1,    17,    -1,    39,
      38,    -1,    -1,    50,    51,    52,    53,    54,    55,    56,
      57,    49,    -1,    60,    61,    62,    63,    64,    38,    39,
      60,    61,    62,    43,    64,    -1,    -1,    -1,    75,    49,
      -1,     1,    72,    73,    74,    75,    -1,    -1,     8,     9,
      60,    61,    62,    13,    64,    -1,    -1,    -1,    -1,     1,
      -1,     1,    72,    73,    74,    75,     8,     9,     8,     9,
      -1,    13,    -1,     1,    -1,    -1,    -1,    -1,    18,    39,
      -1,    -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      -1,    -1,    -1,    -1,    -1,    35,    -1,    39,    -1,    39,
      60,    61,    62,    -1,    64,    45,    46,    47,    48,    -1,
      38,    -1,    72,    73,    74,    75,    -1,    -1,    60,    61,
      62,    49,    64,    -1,    -1,     1,    -1,    -1,    -1,    -1,
      72,    73,    74,    75,    10,    75,    -1,    13,    14,    15,
      16,    17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    25,
      26,    27,    28,    29,    30,    31,    -1,     1,    -1,    -1,
      -1,    -1,    38,    -1,    40,    -1,    10,    43,    -1,    13,
      14,    15,    16,    17,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    25,    26,    27,    28,    29,    30,    31,    -1,     1,
      -1,    -1,    68,    69,    38,    71,    40,    -1,    10,    43,
      -1,    13,    14,    15,    16,    17,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    25,    26,    27,    28,    29,    30,    31,
      -1,     1,    -1,    -1,    68,    69,    38,    71,    40,    -1,
      10,    43,    -1,    13,    14,    15,    16,    17,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    25,    26,    27,    28,    29,
      30,    31,    -1,     1,    -1,    -1,    68,    69,    38,    71,
      40,    -1,    10,    43,    -1,    13,    14,    15,    16,    17,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    25,    26,    27,
      28,    29,    30,    31,    -1,     1,    -1,    -1,    68,    69,
      38,    71,    40,    -1,    10,    43,    -1,    13,    14,    15,
      16,    17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    25,
      26,    27,    28,    29,    30,    31,    -1,     1,    -1,    -1,
      68,    69,    38,    71,    40,    -1,    10,    43,    -1,    13,
      14,    15,    16,    17,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    25,    26,    27,    28,    29,    30,    31,    -1,     1,
      -1,    -1,    68,    69,    38,    71,    40,    -1,    10,    43,
      -1,    13,    14,    15,    16,    17,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    25,    26,    27,    28,    29,    30,    31,
      -1,     1,    -1,    -1,    68,    69,    38,    71,    40,    -1,
      10,    43,    -1,    13,    14,    -1,    16,    17,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    25,    26,    27,    28,    29,
      30,    31,    -1,    -1,    -1,     1,    68,    69,    38,    71,
      -1,    -1,    42,    43,    10,    -1,    -1,    13,    14,    -1,
      16,    17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    25,
      26,    27,    28,    29,    30,    31,    -1,    -1,    68,    69,
       1,    71,    38,    -1,    -1,    -1,    42,    43,    -1,    10,
      -1,    -1,    13,    14,    -1,    16,    17,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    25,    26,    27,    28,    29,    30,
      31,    -1,    68,    69,     1,    71,    -1,    38,    -1,    -1,
      -1,    42,    43,    10,    -1,    -1,    13,    14,    15,    16,
      17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    25,    26,
      27,    28,    29,    -1,    -1,    -1,     1,    68,    69,    -1,
      71,    38,    -1,    40,    -1,    10,    43,    -1,    13,    14,
      15,    16,    17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      25,    26,    27,    28,    29,    -1,    -1,    -1,     1,    -1,
       1,    68,    69,    38,    71,    40,    -1,    10,    43,    10,
      13,    14,    -1,    16,    17,    -1,    17,    -1,    -1,    -1,
      -1,    -1,    25,    26,    27,    28,    29,    30,    31,    -1,
       1,    -1,    -1,    68,    69,    38,    71,    38,    -1,    10,
      43,    -1,    13,    14,    15,    16,    17,    -1,    49,    -1,
      -1,    -1,    -1,    -1,    25,    26,    27,    28,    29,    -1,
      -1,    -1,     1,    -1,     1,    68,    69,    38,    71,    40,
      -1,    10,    43,    10,    13,    14,    -1,    16,    17,    -1,
      17,    -1,    -1,    -1,    -1,    -1,    25,    26,    27,    28,
      29,    30,    31,    -1,     1,    -1,    -1,    68,    69,    38,
      71,    38,    -1,    10,    43,    -1,    13,    14,    -1,    16,
      17,    -1,    49,    -1,    -1,    -1,    -1,    -1,    25,    26,
      27,    28,    29,    30,    31,    -1,     1,    -1,     1,    68,
      69,    38,    71,    -1,    -1,    10,    43,    10,    13,    14,
      -1,    16,    17,    -1,    17,    -1,    -1,    -1,    -1,    -1,
      25,    26,    27,    28,    29,    30,    31,    -1,     1,    -1,
      -1,    68,    69,    38,    71,    38,    -1,    10,    43,    -1,
      13,    14,    15,    16,    17,    -1,    49,    -1,    -1,    -1,
      -1,    -1,    25,    26,    27,    28,    29,    -1,    -1,    -1,
       1,    -1,    -1,    68,    69,    38,    71,    40,    -1,    10,
      43,    -1,    13,    14,    15,    16,    17,    -1,     1,    -1,
      -1,    -1,    -1,    -1,    25,    26,    27,    10,    -1,    -1,
      -1,    -1,     1,    -1,    17,    68,    69,    38,    71,    40,
      -1,    10,    43,    -1,    13,    14,    -1,    16,    17,    -1,
      -1,    -1,    -1,    -1,    -1,    38,    25,    26,    27,    28,
      29,    -1,    -1,    -1,     1,    -1,    49,    68,    69,    38,
      71,    -1,    -1,    10,    43,    -1,    13,    14,    15,    16,
      17,    -1,     1,    -1,    -1,    -1,    -1,    -1,    25,    26,
      27,    10,    -1,    -1,    -1,    -1,     1,    -1,    17,    68,
      69,    38,    71,    40,    -1,    10,    43,    -1,    13,    14,
      15,    16,    17,    -1,    -1,    -1,    -1,    -1,    -1,    38,
      25,    26,    27,    42,    43,    -1,    -1,    -1,     1,    -1,
      49,    68,    69,    38,    71,    40,    -1,    10,    43,    58,
      13,    14,    15,    16,    17,    -1,     1,    -1,    -1,    -1,
      -1,    -1,    25,    26,    27,    10,    -1,    -1,    -1,    -1,
       1,    -1,    17,    68,    69,    38,    71,    40,    -1,    10,
      43,    -1,    13,    14,    -1,    16,    17,    -1,    -1,    -1,
      -1,    -1,    -1,    38,    25,    26,    27,    28,    29,    -1,
      -1,    -1,     1,    -1,    49,    68,    69,    38,    71,    -1,
      -1,    10,    43,    -1,    13,    14,    15,    16,    17,    -1,
      -1,     1,    -1,    -1,    -1,    -1,    25,    26,    27,    -1,
      10,    -1,    -1,    13,    14,    -1,    16,    68,    69,    38,
      71,    40,    -1,    -1,    43,    25,    26,    27,    28,    29,
      30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    42,    -1,    -1,    -1,    -1,    -1,     1,    68,
      69,    -1,    71,    -1,    -1,    -1,    -1,    10,    -1,    -1,
      13,    14,    15,    16,    17,    -1,    -1,     1,    68,    69,
      -1,    71,    25,    26,    27,    -1,    10,    -1,    -1,    13,
      14,    15,    16,    17,    -1,    38,     1,    40,    -1,    -1,
      43,    25,    26,    27,    -1,    10,    -1,    -1,    13,    14,
      15,    16,    17,    -1,    38,    -1,    40,    -1,    -1,    43,
      25,    26,    27,    -1,    -1,    68,    69,     1,    71,    -1,
      -1,    -1,     1,    38,     1,    40,    10,    -1,    43,    13,
      14,    10,    16,    10,    68,    69,    -1,    71,    17,    -1,
      17,    25,    26,    27,    28,    29,    30,    31,    -1,    -1,
      -1,     1,    -1,    68,    69,    -1,    71,    -1,    42,    38,
      10,    38,    -1,    13,    14,     1,    16,    17,    -1,    -1,
      49,    -1,    49,    -1,    10,    25,    26,    27,    -1,    -1,
      -1,    17,    -1,     1,    68,    69,    -1,    71,    38,    -1,
      -1,    -1,    10,    43,    -1,    13,    14,    -1,    16,    17,
      -1,     1,    38,    -1,    -1,    -1,    -1,    25,    26,    27,
      10,    -1,    -1,    49,    -1,     1,    -1,    17,    68,    69,
      38,    71,    -1,    -1,    10,    43,    -1,    13,    14,    -1,
      16,    17,    -1,    -1,    -1,    -1,    -1,    -1,    38,    25,
      26,    27,    -1,    43,    -1,    -1,    -1,     1,    -1,    49,
      68,    69,    38,    71,    -1,    -1,    10,    43,    58,    13,
      14,     1,    16,    17,    -1,    -1,     1,    -1,    -1,    -1,
      10,    25,    26,    27,    -1,    10,    -1,    17,    13,    14,
      -1,    16,    68,    69,    38,    71,    -1,     1,    -1,    43,
      25,    26,    27,    28,    29,     1,    10,    -1,    38,    13,
      14,    -1,    16,    43,    10,    -1,    -1,    13,    14,    49,
      16,    25,    26,    27,    68,    69,     1,    71,    58,    25,
      26,    27,    28,    29,    -1,    10,    -1,    -1,    13,    14,
      -1,    16,    -1,    68,    69,    -1,    71,    -1,    -1,    -1,
      25,    26,    27,    28,    29,     1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    10,    69,    -1,    71,     1,    -1,
      -1,    17,    68,    69,     1,    71,    -1,    10,    -1,    -1,
      -1,    -1,    -1,    10,    17,    -1,    13,    14,    -1,    16,
      -1,    -1,    38,    68,    69,     1,    71,    43,    25,    26,
      27,    -1,    -1,    49,    10,    38,    -1,    -1,     1,    -1,
      43,    17,    58,    59,    -1,    -1,    49,    10,    -1,    -1,
       1,    -1,     1,    -1,    17,    58,    59,    -1,    -1,    10,
      -1,    10,    38,    -1,    -1,    -1,    17,    43,    17,     1,
      -1,    -1,    69,    49,    71,    38,    -1,    -1,    10,    -1,
      43,     1,    58,    59,    -1,    17,    49,    38,    -1,    38,
      10,    -1,    43,    -1,    43,    58,    59,    17,    49,    -1,
      49,    -1,    -1,     1,    -1,     1,    38,    58,    59,    58,
      59,    43,    10,    -1,    10,    -1,    -1,    49,    38,    17,
      -1,    17,    -1,    43,    -1,    -1,    58,    59,     1,    49,
      -1,    -1,     1,    -1,    -1,    -1,    -1,    10,    58,    59,
      38,    10,    38,    -1,    17,    43,    -1,    43,    17,    -1,
       1,    49,    -1,    49,    -1,    -1,    -1,    -1,    -1,    10,
      58,    59,    58,    59,    -1,    38,    17,    -1,     1,    38,
      43,    -1,     1,    -1,    43,    -1,    49,    10,    -1,    -1,
      49,    10,    -1,    -1,    17,    58,    59,    38,    17,    58,
      59,    -1,    43,    -1,    -1,     1,    -1,     1,    49,    -1,
      -1,    -1,    -1,    -1,    10,    38,    10,    58,    59,    38,
      43,    17,    -1,    17,    43,    -1,    49,    -1,    -1,     1,
      49,    -1,     1,    -1,    -1,    58,    59,    -1,    10,    58,
      59,    10,    38,    -1,    38,    17,    -1,    43,    17,    43,
      -1,     1,    -1,    49,    -1,    49,    -1,    -1,    -1,     1,
      10,    -1,    58,    59,    58,    59,    38,    17,    10,    38,
      -1,    43,    -1,    -1,    43,    17,    -1,    49,    -1,    -1,
      49,    -1,     1,    -1,    -1,    -1,    58,    59,    38,    58,
      59,    10,    -1,    43,     1,     1,    38,    -1,    17,    49,
      -1,    43,    -1,    10,    10,    -1,    -1,    49,    58,    59,
      17,    17,     1,    -1,    -1,    -1,    58,    59,    -1,    38,
      -1,    10,    41,    42,    43,     1,    -1,    -1,    17,     1,
      49,    38,    38,    -1,    10,    -1,    43,    43,    10,    58,
      -1,    17,    49,    49,    -1,    17,    -1,     1,     1,    38,
      -1,    58,    58,    -1,    43,    -1,    10,    10,    -1,    -1,
      49,    -1,    38,    17,    17,     1,    38,    43,    -1,    58,
      -1,    43,    -1,    49,    10,    -1,    -1,    49,     1,    -1,
      -1,    17,    58,    -1,    38,    38,    58,    10,    -1,    43,
      43,    -1,     1,    -1,    17,    49,    49,    -1,    -1,    -1,
       1,    10,    38,    -1,    58,    58,    -1,    43,    17,    10,
      -1,    -1,    -1,    49,     1,    38,    17,    -1,    -1,    -1,
      43,    -1,    58,    10,    -1,    -1,    49,     1,    -1,    38,
      17,    -1,    -1,    -1,    43,    58,    10,    38,    -1,    -1,
      49,     1,    -1,    17,     1,     1,    -1,     1,    49,    58,
      10,    38,    -1,    10,    10,    -1,    10,    17,    -1,    -1,
      17,    17,    49,    17,    38,    -1,    -1,     1,    -1,    -1,
       1,     1,    -1,    -1,    -1,    49,    10,    -1,    38,    10,
      10,    38,    38,    17,    38,     1,    17,    17,    -1,    49,
       1,    -1,    49,    49,    10,    49,    -1,    -1,    -1,    10,
       1,    17,    -1,    -1,    38,     1,    17,    38,    38,    10,
      -1,    -1,    -1,    -1,    10,    49,    17,    -1,    49,    49,
       1,    17,    38,     1,    -1,     1,    -1,    38,    -1,    10,
      -1,    -1,    10,    49,    10,     1,    17,    38,    49,    17,
       1,    17,    38,     1,    10,     1,    -1,    -1,    49,    10,
      -1,    17,    10,    49,    10,    -1,    17,    38,     1,    17,
      38,    17,    38,    -1,    -1,    -1,    -1,    10,    49,    -1,
       1,    49,    38,    49,    17,    -1,     1,    38,     1,    10,
      38,    -1,    38,    49,    -1,    10,    17,    10,    49,    -1,
      -1,    49,    17,    49,    17,    38,     1,    -1,    -1,    -1,
       1,     1,    -1,    -1,    -1,    10,    49,    38,    -1,    10,
      10,    -1,    17,    38,     1,    38,    17,    17,    49,     1,
       1,    -1,    -1,    10,    49,    -1,    49,    -1,    10,    10,
      17,    -1,    -1,    38,     1,    17,    17,    38,    38,    -1,
      -1,    -1,    -1,    10,    49,    -1,    -1,    -1,    49,    49,
      17,    38,    -1,    -1,     1,    -1,    38,    38,    -1,    -1,
       1,    -1,    49,    10,     1,    -1,    -1,    49,    49,    10,
      17,    38,    -1,    10,    -1,    -1,    17,    -1,    -1,    -1,
      17,    -1,    49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    38,    -1,    -1,    -1,    -1,    -1,    38,    -1,    -1,
      -1,    38,    49,    -1,    -1,    -1,    -1,    -1,    49,    -1,
      -1,    -1,    49
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned char
  mcmas_parser::yystos_[] =
  {
         0,     1,     3,    67,    78,    79,    80,    81,    83,   112,
     113,   115,    18,     1,    18,    16,     0,     1,    80,     1,
       4,    84,    86,     1,     3,   112,     1,    44,   115,   171,
     173,    75,    65,    66,    40,     1,    40,     1,     8,    75,
      85,    87,     1,     5,    19,    20,    33,    88,    90,    95,
      97,    99,   101,   120,   122,   173,     1,    75,   174,     1,
      45,   176,   178,    86,    43,    43,     4,     1,     4,     1,
      43,    85,    11,    16,    40,     1,    16,     1,    40,     1,
      40,     1,    40,     1,     8,    75,    89,    91,    92,     1,
      97,   101,   122,     1,     8,    91,    96,     1,   101,   122,
       1,     8,     9,    22,    23,    28,    39,    70,    75,    76,
      94,   100,   103,   140,   142,   143,   144,   145,   146,   147,
     148,   166,   167,     1,   122,     1,    12,    75,   121,   124,
       1,     6,   125,   127,   178,     1,    15,     1,     8,    75,
     172,     1,     9,    18,    39,    75,   179,     1,    35,    46,
      47,    48,   180,   182,   188,   190,   196,   198,   206,   208,
       1,    37,    95,    98,   116,   118,     1,    11,    11,     1,
      11,    19,     1,    19,     1,    40,     1,    89,    92,     1,
      43,    40,   101,   122,   122,   127,    20,     1,    20,     1,
      96,    40,   122,   127,     1,    33,    76,   140,   142,   145,
     148,     1,    33,   140,   142,   145,    76,   140,     1,     9,
     148,     1,   100,     1,    17,    38,    43,     1,    28,    29,
       1,    30,    31,     1,    13,    14,    16,    25,    26,    27,
      69,    71,   164,     1,    68,   127,    43,     1,    43,     1,
      41,   121,    40,     1,    40,     1,     8,    36,   126,   129,
     133,   135,   140,     1,     7,   105,   107,   182,   190,   198,
     208,     1,     9,    18,    39,    70,    75,    94,   153,   154,
     155,   156,   160,   161,   162,   167,   169,   175,   175,    44,
       1,    44,     1,    15,    42,    75,   179,   179,     1,    42,
     179,     1,    42,     1,    17,    38,    43,   177,     1,     8,
      75,   181,   185,     1,   190,   198,   208,     1,     8,     9,
      18,    39,    50,    51,    52,    53,    54,    55,    56,    57,
      60,    61,    62,    63,    64,    75,   189,   191,   195,     1,
     198,   208,     1,     9,    13,    18,    39,    50,    51,    52,
      53,    54,    55,    56,    57,    60,    61,    62,    63,    64,
      75,   199,   200,   205,     1,   208,     1,     9,    13,    39,
      60,    61,    62,    64,    72,    73,    74,    75,   209,   210,
     211,   212,   215,    11,    16,    40,     1,    16,     1,    91,
       1,    99,   102,   120,   123,     1,    12,    75,   117,   119,
       1,    98,     1,    21,    75,    93,    94,     1,    11,    21,
      94,     1,    43,   122,   127,   127,   107,   127,   107,     1,
      10,    10,    10,     1,    10,     1,    10,     1,    10,     1,
       1,   145,   145,   140,   140,   140,     1,     9,   143,   143,
     143,   144,   144,   144,   146,   146,   146,   145,   147,   147,
     107,    75,    75,     1,     6,    40,   131,     1,     6,     1,
     131,     1,   126,   133,   135,     1,   126,     1,   131,    40,
       1,    40,     1,     8,     9,    75,   106,   108,   109,   110,
       1,     8,    82,   190,   198,   208,   198,   208,   208,    42,
     153,   156,   160,   175,   153,   160,   175,     1,    42,   175,
       1,     9,   156,     1,    42,     1,    69,    71,   164,     1,
      68,     1,    28,    29,     1,    30,    31,     1,    17,    38,
      43,     1,    43,   175,   175,    75,     1,    16,     1,    10,
       1,    10,    75,    75,     1,    75,    75,     8,    45,   179,
     179,   179,     1,     8,    46,     1,    46,     1,    16,   183,
       1,    75,   181,   198,   208,   208,     1,     9,    35,   193,
     194,   195,     1,    35,     1,   195,    42,   195,   195,   195,
     195,   195,   195,   195,     1,     9,   192,   192,     1,     9,
     193,     1,     9,   194,   194,   193,   194,     1,    42,     1,
     189,   195,     1,    17,    38,    43,    49,   208,     1,     9,
      75,   203,   204,   205,     1,   205,    75,    42,   205,   205,
     205,   205,   205,   205,   205,     1,     9,   201,   202,   201,
     202,     1,     9,   203,     1,     9,   204,   204,   203,   204,
       1,    42,     1,     8,   197,   205,     1,     9,    72,    73,
      74,   201,     1,    17,    38,    43,    49,     1,     9,    75,
     213,   214,   215,     1,   215,    75,   215,     1,     9,   213,
       1,     9,   214,   214,   214,   215,   215,   215,     1,     8,
     207,   215,   215,     1,    17,    38,    43,    49,     1,    11,
      11,     1,    11,    96,     1,     9,    18,    39,    70,    75,
      94,   100,   104,   141,   149,   150,   151,   152,   157,   158,
     159,   167,   168,     1,   123,     1,   124,     1,   125,   128,
      43,     1,    43,     1,    41,   117,   102,   123,    76,     1,
      12,    41,     1,    24,     1,    93,     1,    24,   127,   107,
     107,    82,   107,    82,   142,   142,    82,    11,     1,    11,
       1,    75,   136,   136,   126,   136,     7,     1,     7,     1,
     110,    16,     1,   106,   109,    15,    17,     3,     1,     3,
     198,   208,   208,   208,    75,    10,    10,     1,    10,     1,
      10,     1,    10,     1,    10,    75,    75,     1,     1,   153,
     153,    75,    75,   154,   154,   154,   153,   155,   155,     1,
       9,   161,   161,   161,   162,   162,   162,   175,   175,   175,
       1,    43,     1,    43,     1,     1,    75,    94,   167,   170,
      75,   170,     1,    16,     1,    16,     1,    16,     1,    16,
       1,    45,    45,     1,    45,    11,     1,    11,     1,    18,
      75,   186,   187,   183,   208,    18,    75,    18,    75,     1,
      10,     1,    10,    33,    34,     1,   195,   195,    18,    75,
      18,    75,    75,    75,    33,    34,     1,    33,    34,     1,
      43,   195,   195,   195,   195,    18,    75,    18,    75,    14,
       1,    10,     1,    10,     1,    14,    33,    34,     1,   205,
     205,    18,    75,    18,    75,    75,    75,    33,    34,     1,
      33,    34,    47,     1,    47,     1,    43,   205,   205,   205,
     205,   205,   205,   205,   205,   205,    18,    75,    18,    75,
      14,     1,    10,    58,    59,     1,    10,    58,    59,     1,
      14,     1,    75,    75,    75,    75,    48,     1,    48,     1,
      43,   215,   215,   215,   215,     1,    42,   141,   149,   152,
     157,   141,   149,   157,     1,    42,   141,     1,     9,   152,
     100,     1,    17,    38,    43,     1,    69,    71,   164,     1,
      68,     1,    28,    29,     1,    30,    31,   128,   121,     1,
     130,   134,   135,   141,     1,   105,   137,    75,    75,   123,
     128,    75,    75,    94,    94,     1,    12,    94,    94,   107,
      82,    82,    82,     1,    12,    41,   132,   132,   132,    10,
     145,     1,     9,    32,    39,    75,   145,   163,   110,   208,
     160,   160,   170,   170,   170,   170,    18,    75,   170,   170,
     170,   170,    18,    75,   170,     1,    12,    41,   184,   186,
       1,    41,     1,    41,     1,    41,     1,    41,     1,    58,
       1,    58,     1,    41,     1,    41,     1,    41,     1,    41,
       1,    41,     1,    41,     1,    41,     1,    41,     1,    58,
      59,     1,    58,    59,     1,    41,     1,    41,     1,    41,
       1,    41,     1,     1,     1,    41,     1,    41,     1,    41,
       1,    41,   215,   215,   215,   215,   215,   215,     1,    41,
       1,    41,     1,    41,     1,    41,    75,     1,    10,    10,
      10,     1,    10,     1,    10,     1,    10,    75,    75,     1,
       1,   149,   149,   141,   141,   141,   150,   150,   150,   149,
     151,   151,     1,     9,   158,   158,   158,   159,   159,   159,
     137,     1,     1,   126,   134,   135,   126,     1,   131,     1,
       9,    75,   111,   138,   139,     1,     8,   114,   128,   137,
      82,    43,    75,     1,    43,    75,    16,    75,   145,   163,
     145,   163,     1,    16,   163,     1,    42,   164,     1,    17,
      38,    43,    42,    42,    42,    42,     1,    43,   187,     1,
      43,   187,   184,   195,   195,   195,   195,   195,   195,   195,
     195,   195,   195,   195,   195,   195,   195,   195,   195,   195,
     195,   195,   195,   205,   205,   205,   205,   205,   205,   205,
     205,   205,   205,   205,   205,   205,   205,   205,   205,   205,
     205,   205,   205,   205,   205,   205,   205,   215,   215,   215,
     215,   215,   215,   215,   215,     1,    10,     1,    10,     1,
      10,     1,    10,     1,    10,     1,    10,   215,   215,   215,
     215,   215,   215,   215,   215,   157,   157,   114,   126,   136,
       1,   111,    16,     1,    15,    17,     1,   106,   139,     3,
       1,     3,   137,   114,    75,     1,    10,     1,    10,    75,
      75,    16,    32,    75,     1,    32,   145,   163,   163,   163,
      75,    75,    75,    75,     1,    10,     1,    10,     1,    10,
       1,    10,     1,    10,     1,    10,     1,    10,     1,    10,
       1,    10,     1,    10,     1,    10,     1,    10,     1,    10,
       1,    10,     1,    10,     1,    10,     1,    10,     1,    10,
       1,    10,     1,    10,     1,    10,     1,    10,     1,    10,
       1,    10,     1,    10,     1,    10,     1,    10,     1,    10,
       1,    10,     1,    10,     1,    10,     1,    10,     1,    10,
       1,    10,     1,    10,     1,    10,     1,    10,     1,    10,
       1,    10,     1,    10,     1,    10,     1,    10,     1,    10,
       1,    10,     1,    10,     1,    10,     1,    10,     1,    10,
       1,    10,     1,    10,     1,    10,     1,    10,     1,    10,
       1,    10,     1,    10,     1,    10,     1,    10,     1,    10,
       1,    10,     1,    10,   132,    10,   149,     1,     9,    18,
      32,    39,    75,   149,   165,   165,   111,   114,    75,     1,
      16,    16,    75,     1,    16,    16,    75,   149,   165,   149,
     165,     1,    42,     1,    16,   165,     1,    42,   164,     1,
      17,    38,    43,     1,    43,    75,    75,    75,    75,    75,
      75,     1,    10,     1,    10,    16,    32,    75,     1,    32,
      75,    75,     1,    16,    32,    75,     1,    32,   149,   165,
     165,   165,    75,     1,    16,    75,     1,    16,    75,     1,
      16,    16,    75,     1,    16,    75,    75,    75,    75,    75,
      75,    75,    75,    75
  };

#if YYDEBUG
  /* TOKEN_NUMBER_[YYLEX-NUM] -- Internal symbol number corresponding
     to YYLEX-NUM.  */
  const unsigned short int
  mcmas_parser::yytoken_number_[] =
  {
         0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned char
  mcmas_parser::yyr1_[] =
  {
         0,    77,    78,    78,    79,    79,    79,    80,    80,    80,
      80,    80,    80,    80,    80,    80,    80,    80,    80,    80,
      80,    80,    80,    80,    80,    80,    80,    80,    80,    80,
      80,    81,    81,    81,    81,    82,    82,    82,    82,    83,
      83,    83,    83,    83,    83,    83,    83,    83,    84,    84,
      84,    84,    85,    85,    85,    85,    86,    86,    87,    87,
      88,    88,    88,    88,    89,    89,    89,    89,    90,    90,
      91,    91,    91,    91,    91,    92,    92,    92,    92,    92,
      92,    92,    92,    92,    92,    92,    92,    93,    93,    93,
      93,    94,    94,    94,    94,    95,    95,    95,    95,    96,
      96,    96,    96,    97,    97,    97,    98,    98,    99,    99,
      99,    99,   100,   100,   100,   100,   101,   101,   101,   102,
     102,   102,   103,   103,   103,   104,   104,   104,   105,   105,
     105,   105,   106,   106,   106,   106,   107,   107,   108,   108,
     108,   109,   109,   110,   110,   110,   110,   111,   111,   111,
     111,   112,   112,   112,   113,   113,   114,   114,   114,   114,
     115,   115,   115,   115,   115,   116,   116,   116,   116,   116,
     116,   116,   116,   117,   117,   117,   117,   118,   118,   118,
     119,   119,   119,   119,   120,   120,   120,   120,   120,   120,
     120,   120,   121,   121,   121,   121,   122,   122,   122,   123,
     123,   124,   124,   124,   124,   125,   125,   125,   125,   126,
     126,   126,   126,   127,   127,   127,   127,   127,   128,   128,
     128,   128,   129,   129,   129,   130,   130,   130,   131,   131,
     131,   131,   132,   132,   132,   132,   133,   133,   134,   134,
     135,   135,   136,   136,   136,   136,   137,   137,   138,   138,
     138,   139,   139,   139,   139,   139,   140,   140,   140,   140,
     140,   140,   140,   140,   140,   140,   140,   141,   141,   141,
     141,   141,   141,   141,   141,   141,   141,   141,   142,   142,
     142,   142,   143,   143,   143,   143,   144,   144,   144,   144,
     145,   145,   145,   145,   146,   146,   146,   147,   147,   147,
     148,   148,   148,   148,   149,   149,   149,   149,   150,   150,
     150,   151,   151,   151,   152,   152,   152,   152,   153,   153,
     153,   153,   154,   154,   154,   155,   155,   155,   156,   156,
     156,   156,   157,   157,   157,   157,   158,   158,   158,   158,
     159,   159,   159,   159,   160,   160,   160,   160,   161,   161,
     161,   161,   162,   162,   162,   162,   163,   163,   163,   163,
     163,   163,   163,   163,   163,   163,   163,   163,   163,   163,
     163,   163,   163,   163,   163,   163,   163,   163,   163,   164,
     164,   164,   164,   164,   164,   165,   165,   165,   165,   165,
     165,   165,   165,   165,   165,   165,   165,   165,   165,   165,
     165,   165,   165,   165,   165,   165,   165,   165,   165,   165,
     165,   165,   165,   165,   165,   166,   166,   166,   167,   167,
     168,   168,   168,   168,   168,   168,   169,   169,   169,   169,
     169,   169,   169,   169,   170,   170,   170,   171,   172,   172,
     172,   172,   173,   173,   174,   174,   174,   174,   174,   174,
     174,   174,   174,   175,   175,   175,   175,   175,   175,   175,
     175,   175,   175,   175,   176,   176,   177,   177,   177,   177,
     177,   177,   177,   177,   178,   178,   179,   179,   179,   179,
     179,   179,   179,   179,   179,   179,   179,   179,   179,   179,
     179,   179,   179,   179,   179,   179,   179,   179,   179,   179,
     179,   180,   180,   181,   181,   181,   181,   182,   182,   182,
     183,   183,   183,   183,   184,   184,   184,   184,   185,   185,
     185,   186,   186,   186,   186,   187,   187,   187,   188,   188,
     189,   189,   189,   189,   190,   190,   191,   191,   191,   191,
     191,   192,   192,   192,   192,   192,   192,   192,   192,   193,
     193,   193,   193,   193,   193,   193,   193,   193,   193,   193,
     193,   193,   193,   193,   193,   194,   194,   194,   194,   194,
     194,   194,   194,   195,   195,   195,   195,   195,   195,   195,
     195,   195,   195,   195,   195,   195,   195,   195,   195,   195,
     195,   195,   195,   195,   195,   195,   195,   195,   195,   195,
     195,   195,   195,   195,   195,   195,   195,   196,   196,   197,
     197,   197,   197,   198,   199,   199,   199,   199,   199,   200,
     200,   200,   201,   201,   201,   201,   201,   201,   201,   201,
     202,   202,   202,   202,   202,   202,   202,   202,   203,   203,
     203,   203,   203,   203,   203,   203,   203,   203,   203,   203,
     203,   203,   203,   203,   204,   204,   204,   204,   204,   204,
     204,   204,   205,   205,   205,   205,   205,   205,   205,   205,
     205,   205,   205,   205,   205,   205,   205,   205,   205,   205,
     205,   205,   205,   205,   205,   205,   205,   205,   205,   205,
     205,   205,   205,   205,   205,   205,   205,   205,   205,   205,
     205,   205,   205,   206,   206,   207,   207,   207,   207,   208,
     209,   209,   209,   209,   209,   210,   210,   210,   211,   211,
     211,   211,   211,   211,   211,   211,   212,   212,   212,   212,
     212,   212,   212,   212,   213,   213,   213,   213,   213,   213,
     213,   213,   213,   213,   213,   213,   213,   213,   213,   213,
     214,   214,   214,   214,   214,   214,   214,   214,   215,   215,
     215,   215,   215,   215,   215,   215,   215,   215,   215,   215,
     215,   215,   215,   215,   215,   215,   215,   215,   215,   215,
     215,   215
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  mcmas_parser::yyr2_[] =
  {
         0,     2,     1,     2,     4,     4,     1,     8,     7,     7,
       7,     6,     6,     7,     6,     6,     6,     5,     5,     7,
       6,     6,     6,     5,     5,     6,     5,     5,     5,     4,
       4,     2,     2,     2,     1,     2,     2,     2,     1,     9,
       8,     8,     7,     8,     7,     7,     6,     1,     2,     2,
       2,     1,     2,     2,     2,     1,     3,     2,     2,     2,
       2,     2,     2,     1,     2,     2,     2,     1,     3,     2,
       2,     2,     3,     3,     1,     3,     3,     3,     5,     5,
       5,     5,     5,     4,     5,     4,     1,     1,     3,     3,
       1,     1,     2,     2,     1,     2,     2,     2,     1,     2,
       2,     2,     1,     3,     2,     1,     3,     1,     2,     2,
       2,     1,     2,     2,     2,     1,     3,     2,     1,     3,
       2,     1,     2,     2,     1,     2,     2,     1,     2,     2,
       2,     1,     2,     2,     2,     1,     3,     2,     1,     2,
       1,     4,     1,     3,     3,     3,     1,     3,     3,     3,
       1,     1,     2,     1,     1,     1,     2,     2,     2,     1,
       9,     8,    10,     9,     1,     3,     3,     3,     3,     2,
       2,     3,     1,     2,     2,     2,     1,     3,     2,     1,
       1,     3,     3,     1,     3,     3,     3,     3,     2,     2,
       3,     1,     2,     2,     2,     1,     3,     2,     1,     3,
       1,     1,     3,     3,     1,     2,     2,     2,     1,     2,
       2,     2,     1,     3,     4,     3,     2,     1,     3,     4,
       3,     1,     1,     2,     1,     1,     2,     1,     2,     2,
       2,     1,     2,     2,     2,     1,     4,     1,     4,     1,
       4,     4,     1,     3,     3,     1,     3,     1,     1,     2,
       1,     4,     4,     4,     4,     1,     3,     3,     3,     3,
       3,     3,     3,     2,     2,     3,     1,     3,     3,     3,
       3,     3,     3,     3,     2,     2,     3,     1,     3,     3,
       3,     1,     3,     3,     3,     1,     3,     3,     3,     1,
       3,     3,     3,     1,     3,     3,     1,     2,     2,     1,
       3,     3,     3,     1,     3,     3,     3,     1,     3,     3,
       1,     2,     2,     1,     3,     3,     3,     1,     3,     3,
       3,     1,     3,     3,     1,     2,     2,     1,     3,     3,
       3,     1,     3,     3,     3,     1,     3,     3,     3,     1,
       3,     3,     3,     1,     3,     3,     3,     1,     3,     3,
       3,     1,     3,     3,     3,     1,     3,     3,     3,     3,
       3,     3,     3,     2,     2,     3,     3,     3,     3,     2,
       5,     5,     5,     5,     4,     4,     5,     3,     1,     1,
       1,     1,     1,     1,     1,     3,     3,     3,     3,     3,
       3,     3,     2,     2,     3,     3,     3,     3,     2,     5,
       5,     5,     5,     4,     4,     5,     3,     5,     5,     5,
       4,     4,     5,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     3,     3,     1,     1,     1,     3,     3,
       3,     3,     3,     1,     1,     1,     1,     1,     2,     2,
       2,     1,     3,     1,     4,     4,     4,     4,     5,     5,
       5,     5,     1,     3,     3,     3,     3,     3,     3,     3,
       2,     2,     3,     1,     1,     1,     3,     3,     3,     3,
       2,     2,     3,     1,     3,     1,     3,     3,     3,     3,
       3,     3,     3,     2,     2,     7,     7,     7,     5,     5,
       5,     5,     7,     5,     5,     5,     5,     4,     5,     4,
       1,     1,     1,     2,     2,     2,     1,     3,     2,     1,
       2,     2,     2,     1,     2,     2,     2,     1,     4,     5,
       1,     1,     3,     3,     1,     1,     1,     1,     1,     1,
       2,     2,     2,     1,     2,     3,     2,     2,     3,     3,
       1,     5,     5,     5,     5,     5,     5,     5,     5,     5,
       5,     5,     5,     5,     5,     5,     5,     5,     5,     5,
       5,     5,     5,     5,     5,     5,     5,     5,     5,     5,
       5,     5,     5,     3,     3,     3,     3,     3,     3,     3,
       2,     2,     3,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     1,     3,
       3,     3,     3,     3,     3,     3,     1,     1,     1,     2,
       2,     2,     1,     3,     2,     2,     3,     3,     1,     3,
       3,     3,     5,     5,     5,     5,     5,     5,     5,     5,
       5,     5,     5,     5,     5,     5,     5,     5,     5,     5,
       5,     5,     5,     5,     5,     5,     5,     5,     5,     5,
       5,     5,     5,     5,     5,     5,     5,     5,     5,     5,
       5,     5,     3,     3,     3,     3,     3,     3,     3,     2,
       2,     3,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     3,
       3,     3,     3,     2,     1,     3,     3,     3,     3,     3,
       3,     3,     1,     1,     1,     2,     2,     2,     1,     3,
       2,     2,     3,     3,     1,     3,     3,     3,     5,     5,
       5,     5,     5,     5,     5,     5,     5,     5,     5,     5,
       5,     5,     5,     5,     5,     5,     5,     5,     5,     5,
       5,     5,     5,     5,     5,     5,     5,     5,     5,     5,
       5,     5,     5,     5,     5,     5,     5,     5,     3,     3,
       3,     3,     3,     3,     3,     2,     2,     3,     2,     2,
       2,     1,     1,     2,     2,     2,     2,     2,     2,     2,
       1,     1
  };

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
  /* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
     First, the terminals, then, starting at \a yyntokens_, nonterminals.  */
  const char*
  const mcmas_parser::yytname_[] =
  {
    "\"end of file\"", "error", "$undefined", "AGENT", "STRTYPE", "ACTIONS",
  "PROTOCOL", "EVOLUTION", "END", "LB", "RB", "LCB", "RCB", "LT", "GT",
  "IF", "EQ", "AND", "ENVIRONMENT", "OBSVARS", "VARS", "BOOLEAN", "BTRUE",
  "BFALSE", "TO", "LE", "GE", "NEQ", "MINUS", "PLUS", "TIMES", "DIVIDE",
  "ACTION", "REDSTATES", "GREENSTATES", "FAIRNESS", "OTHER", "LOBSVARS",
  "OR", "NOT", "COLON", "COMMA", "DOT", "SEMICOLON", "EVALUATION",
  "INITSTATES", "GROUPS", "FORMULAE", "FORMULAE_AST", "IMPLIES", "AG",
  "EG", "AX", "EX", "AF", "EF", "A", "E", "UNTIL", "RELEASE", "K", "GK",
  "GCK", "O", "DK", "MULTIASSIGNMENT", "SINGLEASSIGNMENT", "SEMANTICS",
  "BITAND", "BITOR", "BITNOT", "BITXOR", "X", "F", "G", "\"identifier\"",
  "\"number\"", "$accept", "eis", "semantics", "is", "envprefix",
  "envsuffix", "environment", "strtypeprefix", "strtypesuffix",
  "strtypedef", "strtypename", "obsprefix", "obssuffix", "obsvardef",
  "varidlist", "onevardef", "enumlist", "integer", "varprefix",
  "varsuffix", "envardef", "vardef", "redprefix", "redsuffix", "enreddef",
  "reddef", "enrboolcond", "rboolcond", "evprefix", "evsuffix", "envevdef",
  "envevdeflist", "envevline", "boolresult", "boolresult1", "agents",
  "agprefix", "agsuffix", "agent", "lobsprefix", "lobssuffix",
  "lobsvarsdef", "lobsvaridlist", "actprefix", "actsuffix", "enactiondef",
  "actiondef", "actionidlist", "protprefix", "protsuffix", "enprotdef",
  "protdef", "enprotdeflist", "protdeflist", "plprefix", "plsuffix",
  "enprotline", "protline", "otherbranch", "enabledidlist", "evdef",
  "evdeflist", "evline", "enlboolcond", "lboolcond", "expr1", "term1",
  "element1", "expr4", "term4", "factor4", "element4", "expr5", "term5",
  "factor5", "element5", "expr6", "term6", "factor6", "element6", "expr2",
  "term2", "element2", "expr3", "term3", "element3", "eboolcond",
  "logicop", "gboolcond", "varvalue1", "boolvalue", "varvalue2",
  "varvalue3", "varvalue4", "evaprefix", "evasuffix", "evaluation",
  "evalist", "evaboolcond", "iniprefix", "inisuffix", "istates",
  "isboolcond", "groupprefix", "groupsuffix", "groups", "gplprefix",
  "gplsufffix", "groupdeflist", "namelist", "agentname", "fairprefix",
  "fairsuffix", "fairness", "fformlist", "untilprefixfair",
  "epistemicprefixfair", "gepistemicprefixfair", "fformula", "forprefix",
  "forsuffix", "formulae", "formlist", "atlprefix", "untilprefix",
  "releaseprefix", "epistemicprefix", "gepistemicprefix", "formula",
  "forastprefix", "forastsuffix", "formulae_ast", "formastlist",
  "atlstrprefix", "untilastprefix", "releaseastprefix",
  "epistemicprefix_ast", "gepistemicprefix_ast", "formula_ast", 0
  };
#endif

#if YYDEBUG
  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const mcmas_parser::rhs_number_type
  mcmas_parser::yyrhs_[] =
  {
        78,     0,    -1,    80,    -1,    79,    80,    -1,    67,    16,
      65,    43,    -1,    67,    16,    66,    43,    -1,     1,    -1,
      83,   112,   173,   178,   182,   190,   198,   208,    -1,    83,
     112,   173,   178,   182,   190,   208,    -1,    83,   112,   173,
     178,   182,   190,   198,    -1,    83,   112,   173,   178,   182,
     198,   208,    -1,    83,   112,   173,   178,   182,   208,    -1,
      83,   112,   173,   178,   182,   198,    -1,    83,   112,   173,
     178,   190,   198,   208,    -1,    83,   112,   173,   178,   190,
     208,    -1,    83,   112,   173,   178,   190,   198,    -1,    83,
     112,   173,   178,   198,   208,    -1,    83,   112,   173,   178,
     208,    -1,    83,   112,   173,   178,   198,    -1,   112,   173,
     178,   182,   190,   198,   208,    -1,   112,   173,   178,   182,
     190,   198,    -1,   112,   173,   178,   182,   190,   208,    -1,
     112,   173,   178,   182,   198,   208,    -1,   112,   173,   178,
     182,   198,    -1,   112,   173,   178,   182,   208,    -1,   112,
     173,   178,   190,   198,   208,    -1,   112,   173,   178,   190,
     198,    -1,   112,   173,   178,   190,   208,    -1,   112,   173,
     178,   198,   208,    -1,   112,   173,   178,   198,    -1,   112,
     173,   178,   208,    -1,     3,    18,    -1,     1,    18,    -1,
       3,     1,    -1,     1,    -1,     8,     3,    -1,     1,     3,
      -1,     8,     1,    -1,     1,    -1,    81,    86,    90,    97,
     101,   122,   127,   107,    82,    -1,    81,    86,    90,    97,
     122,   127,   107,    82,    -1,    81,    86,    97,   101,   122,
     127,   107,    82,    -1,    81,    86,    97,   122,   127,   107,
      82,    -1,    81,    86,    90,   101,   122,   127,   107,    82,
      -1,    81,    86,    90,   122,   127,   107,    82,    -1,    81,
      86,   101,   122,   127,   107,    82,    -1,    81,    86,   122,
     127,   107,    82,    -1,     1,    -1,     4,    40,    -1,     1,
      40,    -1,     4,     1,    -1,     1,    -1,     8,     4,    -1,
       1,     4,    -1,     8,     1,    -1,     1,    -1,    84,    87,
      85,    -1,    84,    85,    -1,    75,    43,    -1,    75,     1,
      -1,    19,    40,    -1,     1,    40,    -1,    19,     1,    -1,
       1,    -1,     8,    19,    -1,     1,    19,    -1,     8,     1,
      -1,     1,    -1,    88,    91,    89,    -1,    88,    89,    -1,
      92,    43,    -1,    92,     1,    -1,    91,    92,    43,    -1,
      91,    92,     1,    -1,     1,    -1,    75,    40,    21,    -1,
      75,    40,     1,    -1,    75,     1,    21,    -1,    75,    40,
      94,    24,    94,    -1,    75,     1,    94,    24,    94,    -1,
      75,    40,    94,     1,    94,    -1,    75,     1,    94,     1,
      94,    -1,    75,    40,    11,    93,    12,    -1,    75,     1,
      93,    12,    -1,    75,    40,    11,    93,     1,    -1,    75,
       1,    93,     1,    -1,     1,    -1,    75,    -1,    93,    41,
      75,    -1,    93,     1,    75,    -1,     1,    -1,    76,    -1,
      28,    76,    -1,     1,    76,    -1,     1,    -1,    20,    40,
      -1,     1,    40,    -1,    20,     1,    -1,     1,    -1,     8,
      20,    -1,     1,    20,    -1,     8,     1,    -1,     1,    -1,
      95,    91,    96,    -1,    95,    96,    -1,     1,    -1,    95,
      91,    96,    -1,     1,    -1,    33,    40,    -1,    33,     1,
      -1,     1,    40,    -1,     1,    -1,     8,    33,    -1,     1,
      33,    -1,     8,     1,    -1,     1,    -1,    99,   103,   100,
      -1,    99,   100,    -1,     1,    -1,    99,   104,   100,    -1,
      99,   100,    -1,     1,    -1,   140,    43,    -1,   140,     1,
      -1,     1,    -1,   141,    43,    -1,   141,     1,    -1,     1,
      -1,     7,    40,    -1,     1,    40,    -1,     7,     1,    -1,
       1,    -1,     8,     7,    -1,     1,     7,    -1,     8,     1,
      -1,     1,    -1,   105,   108,   106,    -1,   105,   106,    -1,
     109,    -1,   108,   109,    -1,     1,    -1,   110,    15,   163,
      43,    -1,     1,    -1,     9,   110,    10,    -1,   110,    17,
     110,    -1,    75,    16,   145,    -1,     1,    -1,     9,   111,
      10,    -1,   111,    17,   111,    -1,    75,    16,   149,    -1,
       1,    -1,   115,    -1,   112,   115,    -1,     1,    -1,     3,
      -1,     1,    -1,     8,     3,    -1,     1,     3,    -1,     8,
       1,    -1,     1,    -1,   113,    75,    86,    98,   102,   123,
     128,   137,   114,    -1,   113,    75,    86,    98,   123,   128,
     137,   114,    -1,   113,    75,    86,   118,    98,   102,   123,
     128,   137,   114,    -1,   113,    75,    86,   118,    98,   123,
     128,   137,   114,    -1,     1,    -1,    37,    16,    11,    -1,
       1,    16,    11,    -1,    37,     1,    11,    -1,    37,    16,
       1,    -1,     1,    11,    -1,    37,     1,    -1,     1,    16,
       1,    -1,     1,    -1,    12,    43,    -1,    12,     1,    -1,
       1,    43,    -1,     1,    -1,   116,   119,   117,    -1,   116,
     117,    -1,     1,    -1,    75,    -1,   119,    41,    75,    -1,
     119,     1,    75,    -1,     1,    -1,     5,    16,    11,    -1,
       1,    16,    11,    -1,     5,     1,    11,    -1,     5,    16,
       1,    -1,     1,    11,    -1,     5,     1,    -1,     1,    16,
       1,    -1,     1,    -1,    12,    43,    -1,    12,     1,    -1,
       1,    43,    -1,     1,    -1,   120,   124,   121,    -1,   120,
     121,    -1,     1,    -1,   120,   124,   121,    -1,     1,    -1,
      75,    -1,   124,    41,    75,    -1,   124,     1,    75,    -1,
       1,    -1,     6,    40,    -1,     1,    40,    -1,     6,     1,
      -1,     1,    -1,     8,     6,    -1,     1,     6,    -1,     8,
       1,    -1,     1,    -1,   125,   129,   126,    -1,   125,   129,
     135,   126,    -1,   125,   135,   126,    -1,   125,   126,    -1,
       1,    -1,   125,   130,   126,    -1,   125,   130,   135,   126,
      -1,   125,   135,   126,    -1,     1,    -1,   133,    -1,   129,
     133,    -1,     1,    -1,   134,    -1,   130,   134,    -1,     1,
      -1,    40,    11,    -1,     1,    11,    -1,    40,     1,    -1,
       1,    -1,    12,    43,    -1,     1,    43,    -1,    12,     1,
      -1,     1,    -1,   140,   131,   136,   132,    -1,     1,    -1,
     141,   131,   136,   132,    -1,     1,    -1,    36,   131,   136,
     132,    -1,     1,   131,   136,   132,    -1,    75,    -1,   136,
      41,    75,    -1,   136,     1,    75,    -1,     1,    -1,   105,
     138,   106,    -1,     1,    -1,   139,    -1,   138,   139,    -1,
       1,    -1,   111,    15,   165,    43,    -1,   111,     1,   165,
      43,    -1,   111,    15,   165,     1,    -1,   111,     1,   165,
       1,    -1,     1,    -1,     9,   140,    10,    -1,     1,   140,
      10,    -1,     9,   140,     1,    -1,     1,   140,     1,    -1,
     140,    17,   140,    -1,   140,    38,   140,    -1,   140,     1,
     140,    -1,    39,   140,    -1,     1,   140,    -1,   145,   164,
     145,    -1,     1,    -1,     9,   141,    10,    -1,     1,   141,
      10,    -1,     9,   141,     1,    -1,     1,   141,     1,    -1,
     141,    17,   141,    -1,   141,    38,   141,    -1,   141,     1,
     141,    -1,    39,   141,    -1,     1,   141,    -1,   149,   164,
     149,    -1,     1,    -1,   142,    29,   143,    -1,   142,    28,
     143,    -1,   142,     1,   143,    -1,   143,    -1,   143,    30,
     144,    -1,   143,    31,   144,    -1,   143,     1,   144,    -1,
     144,    -1,     9,   142,    10,    -1,     1,   142,    10,    -1,
       9,   142,     1,    -1,   166,    -1,   145,    69,   146,    -1,
     145,    71,   146,    -1,   145,     1,   146,    -1,   146,    -1,
     146,    68,   147,    -1,   146,     1,   147,    -1,   147,    -1,
      70,   148,    -1,     1,   148,    -1,   148,    -1,     9,   145,
      10,    -1,     1,   145,    10,    -1,     9,   145,     1,    -1,
     142,    -1,   149,    69,   150,    -1,   149,    71,   150,    -1,
     149,     1,   150,    -1,   150,    -1,   150,    68,   151,    -1,
     150,     1,   151,    -1,   151,    -1,    70,   152,    -1,     1,
     152,    -1,   152,    -1,     9,   149,    10,    -1,     1,   149,
      10,    -1,     9,   149,     1,    -1,   157,    -1,   153,    69,
     154,    -1,   153,    71,   154,    -1,   153,     1,   154,    -1,
     154,    -1,   154,    68,   155,    -1,   154,     1,   155,    -1,
     155,    -1,    70,   156,    -1,     1,   156,    -1,   156,    -1,
       9,   153,    10,    -1,     1,   153,    10,    -1,     9,   153,
       1,    -1,   160,    -1,   157,    29,   158,    -1,   157,    28,
     158,    -1,   157,     1,   158,    -1,   158,    -1,   158,    30,
     159,    -1,   158,    31,   159,    -1,   158,     1,   159,    -1,
     159,    -1,     9,   157,    10,    -1,     1,   157,    10,    -1,
       9,   157,     1,    -1,   168,    -1,   160,    29,   161,    -1,
     160,    28,   161,    -1,   160,     1,   161,    -1,   161,    -1,
     161,    30,   162,    -1,   161,    31,   162,    -1,   161,     1,
     162,    -1,   162,    -1,     9,   160,    10,    -1,     1,   160,
      10,    -1,     9,   160,     1,    -1,   169,    -1,     9,   163,
      10,    -1,     1,   163,    10,    -1,     9,   163,     1,    -1,
       1,   163,     1,    -1,   163,    17,   163,    -1,   163,    38,
     163,    -1,   163,     1,   163,    -1,    39,   163,    -1,     1,
     163,    -1,   145,   164,   145,    -1,    32,    16,    75,    -1,
       1,    16,    75,    -1,    32,     1,    75,    -1,     1,    75,
      -1,    75,    42,    32,    16,    75,    -1,    75,     1,    32,
      16,    75,    -1,    75,    42,     1,    16,    75,    -1,    75,
      42,    32,     1,    75,    -1,    75,     1,    16,    75,    -1,
      75,    42,     1,    75,    -1,    75,     1,    32,     1,    75,
      -1,    75,     1,    75,    -1,     1,    -1,    13,    -1,    25,
      -1,    14,    -1,    26,    -1,    16,    -1,    27,    -1,     9,
     165,    10,    -1,     1,   165,    10,    -1,     9,   165,     1,
      -1,     1,   165,     1,    -1,   165,    17,   165,    -1,   165,
      38,   165,    -1,   165,     1,   165,    -1,    39,   165,    -1,
       1,   165,    -1,   149,   164,   149,    -1,    32,    16,    75,
      -1,     1,    16,    75,    -1,    32,     1,    75,    -1,     1,
      75,    -1,    75,    42,    32,    16,    75,    -1,    75,     1,
      32,    16,    75,    -1,    75,    42,     1,    16,    75,    -1,
      75,    42,    32,     1,    75,    -1,    75,     1,    16,    75,
      -1,    75,    42,     1,    75,    -1,    75,     1,    32,     1,
      75,    -1,    75,     1,    75,    -1,    18,    42,    32,    16,
      75,    -1,    18,    42,     1,    16,    75,    -1,    18,    42,
      32,     1,    75,    -1,    18,     1,    16,    75,    -1,    18,
      42,     1,    75,    -1,    18,     1,    32,     1,    75,    -1,
      18,     1,    75,    -1,     1,    -1,   167,    -1,    75,    -1,
      94,    -1,    22,    -1,    23,    -1,   167,    -1,    75,    -1,
      18,    42,    75,    -1,     1,    42,    75,    -1,    18,     1,
      75,    -1,    94,    -1,   167,    -1,    75,    -1,    75,    42,
      75,    -1,    75,     1,    75,    -1,    18,    42,    75,    -1,
       1,    42,    75,    -1,    18,     1,    75,    -1,    94,    -1,
     167,    -1,    75,    -1,    94,    -1,    44,    -1,     8,    44,
      -1,     1,    44,    -1,     8,     1,    -1,     1,    -1,   171,
     174,   172,    -1,     1,    -1,    75,    15,   175,    43,    -1,
      75,     1,   175,    43,    -1,    75,    15,   175,     1,    -1,
      75,     1,   175,     1,    -1,   174,    75,    15,   175,    43,
      -1,   174,    75,     1,   175,    43,    -1,   174,    75,    15,
     175,     1,    -1,   174,    75,     1,   175,     1,    -1,     1,
      -1,     9,   175,    10,    -1,     1,   175,    10,    -1,     9,
     175,     1,    -1,     1,   175,     1,    -1,   175,    17,   175,
      -1,   175,    38,   175,    -1,   175,     1,   175,    -1,    39,
     175,    -1,     1,   175,    -1,   153,   164,   153,    -1,     1,
      -1,    45,    -1,     1,    -1,    43,     8,    45,    -1,     1,
       8,    45,    -1,    43,     1,    45,    -1,    43,     8,     1,
      -1,     1,    45,    -1,    43,     1,    -1,     1,     8,     1,
      -1,     1,    -1,   176,   179,   177,    -1,     1,    -1,     9,
     179,    10,    -1,     1,   179,    10,    -1,     9,   179,     1,
      -1,     1,   179,     1,    -1,   179,    17,   179,    -1,   179,
      38,   179,    -1,   179,     1,   179,    -1,    39,   179,    -1,
       1,   179,    -1,    75,    42,    75,    16,    75,    42,    75,
      -1,    75,    42,    75,    16,    18,    42,    75,    -1,    18,
      42,    75,    16,    75,    42,    75,    -1,    75,    42,    75,
      16,   170,    -1,    75,     1,    75,    16,   170,    -1,    75,
      42,    75,     1,   170,    -1,    75,     1,    75,     1,   170,
      -1,    18,    42,    75,    16,    18,    42,    75,    -1,    18,
      42,    75,    16,   170,    -1,    18,     1,    75,    16,   170,
      -1,    18,    42,    75,     1,   170,    -1,    18,     1,    75,
       1,   170,    -1,     1,    75,    16,   170,    -1,     1,    42,
      75,     1,   170,    -1,     1,    75,     1,   170,    -1,     1,
      -1,    46,    -1,     1,    -1,     8,    46,    -1,     1,    46,
      -1,     8,     1,    -1,     1,    -1,   180,   185,   181,    -1,
     180,   181,    -1,     1,    -1,    16,    11,    -1,     1,    11,
      -1,    16,     1,    -1,     1,    -1,    12,    43,    -1,     1,
      43,    -1,    12,     1,    -1,     1,    -1,    75,   183,   186,
     184,    -1,   185,    75,   183,   186,   184,    -1,     1,    -1,
     187,    -1,   186,    41,   187,    -1,   186,     1,   187,    -1,
       1,    -1,    18,    -1,    75,    -1,     1,    -1,    35,    -1,
       1,    -1,     8,    35,    -1,     1,    35,    -1,     8,     1,
      -1,     1,    -1,   188,   189,    -1,   188,   191,   189,    -1,
     195,    43,    -1,   195,     1,    -1,   191,   195,    43,    -1,
     191,   195,     1,    -1,     1,    -1,     9,   195,    58,   195,
      10,    -1,     1,   195,    58,   195,    10,    -1,     9,   195,
       1,   195,    10,    -1,     9,   195,    58,   195,     1,    -1,
       1,   195,     1,   195,    10,    -1,     1,   195,    58,   195,
       1,    -1,     9,   195,     1,   195,     1,    -1,     1,   195,
       1,   195,     1,    -1,     9,    75,    41,   195,    10,    -1,
       1,    75,    41,   195,    10,    -1,     9,    75,     1,   195,
      10,    -1,     9,    75,    41,   195,     1,    -1,     1,    75,
       1,   195,    10,    -1,     1,    75,    41,   195,     1,    -1,
       9,    75,     1,   195,     1,    -1,     1,    75,     1,   195,
       1,    -1,     9,    18,    41,   195,    10,    -1,     1,    18,
      41,   195,    10,    -1,     9,    18,     1,   195,    10,    -1,
       9,    18,    41,   195,     1,    -1,     1,    18,     1,   195,
      10,    -1,     1,    18,    41,   195,     1,    -1,     9,    18,
       1,   195,     1,    -1,     1,    18,     1,   195,     1,    -1,
       9,    75,    41,   195,    10,    -1,     1,    75,    41,   195,
      10,    -1,     9,    75,     1,   195,    10,    -1,     9,    75,
      41,   195,     1,    -1,     1,    75,     1,   195,    10,    -1,
       1,    75,    41,   195,     1,    -1,     9,    75,     1,   195,
       1,    -1,     1,    75,     1,   195,     1,    -1,     9,   195,
      10,    -1,     1,   195,    10,    -1,     9,   195,     1,    -1,
       1,   195,     1,    -1,   195,    17,   195,    -1,   195,    38,
     195,    -1,   195,     1,   195,    -1,    39,   195,    -1,     1,
     195,    -1,   195,    49,   195,    -1,    50,   195,    -1,    51,
     195,    -1,    52,   195,    -1,    53,   195,    -1,    54,   195,
      -1,    55,   195,    -1,    56,   192,    -1,    57,   192,    -1,
      60,   193,    -1,    61,   194,    -1,    62,   194,    -1,    63,
     193,    -1,    64,   194,    -1,     1,   193,    -1,     1,   194,
      -1,    75,    -1,    75,    42,    34,    -1,    75,    42,    33,
      -1,    18,    42,    34,    -1,    18,    42,    33,    -1,    75,
      42,     1,    -1,    75,     1,    34,    -1,    75,     1,    33,
      -1,     1,    -1,    47,    -1,     1,    -1,     8,    47,    -1,
       1,    47,    -1,     8,     1,    -1,     1,    -1,   196,   199,
     197,    -1,   205,    43,    -1,   205,     1,    -1,   199,   205,
      43,    -1,   199,   205,     1,    -1,     1,    -1,    13,    75,
      14,    -1,    13,    75,     1,    -1,     1,    75,    14,    -1,
       9,   205,    58,   205,    10,    -1,     1,   205,    58,   205,
      10,    -1,     9,   205,     1,   205,    10,    -1,     9,   205,
      58,   205,     1,    -1,     1,   205,     1,   205,    10,    -1,
       1,   205,    58,   205,     1,    -1,     9,   205,     1,   205,
       1,    -1,     1,   205,     1,   205,     1,    -1,     9,   205,
      59,   205,    10,    -1,     1,   205,    59,   205,    10,    -1,
       9,   205,     1,   205,    10,    -1,     9,   205,    59,   205,
       1,    -1,     1,   205,     1,   205,    10,    -1,     1,   205,
      59,   205,     1,    -1,     9,   205,     1,   205,     1,    -1,
       1,   205,     1,   205,     1,    -1,     9,    75,    41,   205,
      10,    -1,     1,    75,    41,   205,    10,    -1,     9,    75,
       1,   205,    10,    -1,     9,    75,    41,   205,     1,    -1,
       1,    75,     1,   205,    10,    -1,     1,    75,    41,   205,
       1,    -1,     9,    75,     1,   205,     1,    -1,     1,    75,
       1,   205,     1,    -1,     9,    18,    41,   205,    10,    -1,
       1,    18,    41,   205,    10,    -1,     9,    18,     1,   205,
      10,    -1,     9,    18,    41,   205,     1,    -1,     1,    18,
       1,   205,    10,    -1,     1,    18,    41,   205,     1,    -1,
       9,    18,     1,   205,     1,    -1,     1,    18,     1,   205,
       1,    -1,     9,    75,    41,   205,    10,    -1,     1,    75,
      41,   205,    10,    -1,     9,    75,     1,   205,    10,    -1,
       9,    75,    41,   205,     1,    -1,     1,    75,     1,   205,
      10,    -1,     1,    75,    41,   205,     1,    -1,     9,    75,
       1,   205,     1,    -1,     1,    75,     1,   205,     1,    -1,
       9,   205,    10,    -1,     1,   205,    10,    -1,     9,   205,
       1,    -1,     1,   205,     1,    -1,   205,    17,   205,    -1,
     205,    38,   205,    -1,   205,     1,   205,    -1,    39,   205,
      -1,     1,   205,    -1,   205,    49,   205,    -1,    50,   205,
      -1,    51,   205,    -1,    52,   205,    -1,    53,   205,    -1,
      54,   205,    -1,    55,   205,    -1,    56,   201,    -1,    57,
     201,    -1,    56,   202,    -1,    57,   202,    -1,    60,   203,
      -1,    61,   204,    -1,    62,   204,    -1,    63,   203,    -1,
      64,   204,    -1,     1,   203,    -1,     1,   204,    -1,   200,
      72,   205,    -1,   200,    73,   205,    -1,   200,    74,   205,
      -1,   200,     1,   205,    -1,   200,   201,    -1,    75,    -1,
      75,    42,    34,    -1,    75,    42,    33,    -1,    18,    42,
      34,    -1,    18,    42,    33,    -1,    75,    42,     1,    -1,
      75,     1,    34,    -1,    75,     1,    33,    -1,     1,    -1,
      48,    -1,     1,    -1,     8,    48,    -1,     1,    48,    -1,
       8,     1,    -1,     1,    -1,   206,   209,   207,    -1,   215,
      43,    -1,   215,     1,    -1,   209,   215,    43,    -1,   209,
     215,     1,    -1,     1,    -1,    13,    75,    14,    -1,    13,
      75,     1,    -1,     1,    75,    14,    -1,     9,   215,    58,
     215,    10,    -1,     1,   215,    58,   215,    10,    -1,     9,
     215,     1,   215,    10,    -1,     9,   215,    58,   215,     1,
      -1,     1,   215,     1,   215,    10,    -1,     1,   215,    58,
     215,     1,    -1,     9,   215,     1,   215,     1,    -1,     1,
     215,     1,   215,     1,    -1,     9,   215,    59,   215,    10,
      -1,     1,   215,    59,   215,    10,    -1,     9,   215,     1,
     215,    10,    -1,     9,   215,    59,   215,     1,    -1,     1,
     215,     1,   215,    10,    -1,     1,   215,    59,   215,     1,
      -1,     9,   215,     1,   215,     1,    -1,     1,   215,     1,
     215,     1,    -1,     9,    75,    41,   215,    10,    -1,     1,
      75,    41,   215,    10,    -1,     9,    75,     1,   215,    10,
      -1,     9,    75,    41,   215,     1,    -1,     1,    75,     1,
     215,    10,    -1,     1,    75,    41,   215,     1,    -1,     9,
      75,     1,   215,     1,    -1,     1,    75,     1,   215,     1,
      -1,     9,    18,    41,   215,    10,    -1,     1,    18,    41,
     215,    10,    -1,     9,    18,     1,   215,    10,    -1,     9,
      18,    41,   215,     1,    -1,     1,    18,     1,   215,    10,
      -1,     1,    18,    41,   215,     1,    -1,     9,    18,     1,
     215,     1,    -1,     1,    18,     1,   215,     1,    -1,     9,
      75,    41,   215,    10,    -1,     1,    75,    41,   215,    10,
      -1,     9,    75,     1,   215,    10,    -1,     9,    75,    41,
     215,     1,    -1,     1,    75,     1,   215,    10,    -1,     1,
      75,    41,   215,     1,    -1,     9,    75,     1,   215,     1,
      -1,     1,    75,     1,   215,     1,    -1,     9,   215,    10,
      -1,     1,   215,    10,    -1,     9,   215,     1,    -1,     1,
     215,     1,    -1,   215,    17,   215,    -1,   215,    38,   215,
      -1,   215,     1,   215,    -1,    39,   215,    -1,     1,   215,
      -1,   215,    49,   215,    -1,    72,   215,    -1,    73,   215,
      -1,    74,   215,    -1,   211,    -1,   212,    -1,    60,   213,
      -1,    61,   214,    -1,    62,   214,    -1,    64,   214,    -1,
       1,   213,    -1,     1,   214,    -1,   210,   215,    -1,    75,
      -1,     1,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  mcmas_parser::yyprhs_[] =
  {
         0,     0,     3,     5,     8,    13,    18,    20,    29,    37,
      45,    53,    60,    67,    75,    82,    89,    96,   102,   108,
     116,   123,   130,   137,   143,   149,   156,   162,   168,   174,
     179,   184,   187,   190,   193,   195,   198,   201,   204,   206,
     216,   225,   234,   242,   251,   259,   267,   274,   276,   279,
     282,   285,   287,   290,   293,   296,   298,   302,   305,   308,
     311,   314,   317,   320,   322,   325,   328,   331,   333,   337,
     340,   343,   346,   350,   354,   356,   360,   364,   368,   374,
     380,   386,   392,   398,   403,   409,   414,   416,   418,   422,
     426,   428,   430,   433,   436,   438,   441,   444,   447,   449,
     452,   455,   458,   460,   464,   467,   469,   473,   475,   478,
     481,   484,   486,   489,   492,   495,   497,   501,   504,   506,
     510,   513,   515,   518,   521,   523,   526,   529,   531,   534,
     537,   540,   542,   545,   548,   551,   553,   557,   560,   562,
     565,   567,   572,   574,   578,   582,   586,   588,   592,   596,
     600,   602,   604,   607,   609,   611,   613,   616,   619,   622,
     624,   634,   643,   654,   664,   666,   670,   674,   678,   682,
     685,   688,   692,   694,   697,   700,   703,   705,   709,   712,
     714,   716,   720,   724,   726,   730,   734,   738,   742,   745,
     748,   752,   754,   757,   760,   763,   765,   769,   772,   774,
     778,   780,   782,   786,   790,   792,   795,   798,   801,   803,
     806,   809,   812,   814,   818,   823,   827,   830,   832,   836,
     841,   845,   847,   849,   852,   854,   856,   859,   861,   864,
     867,   870,   872,   875,   878,   881,   883,   888,   890,   895,
     897,   902,   907,   909,   913,   917,   919,   923,   925,   927,
     930,   932,   937,   942,   947,   952,   954,   958,   962,   966,
     970,   974,   978,   982,   985,   988,   992,   994,   998,  1002,
    1006,  1010,  1014,  1018,  1022,  1025,  1028,  1032,  1034,  1038,
    1042,  1046,  1048,  1052,  1056,  1060,  1062,  1066,  1070,  1074,
    1076,  1080,  1084,  1088,  1090,  1094,  1098,  1100,  1103,  1106,
    1108,  1112,  1116,  1120,  1122,  1126,  1130,  1134,  1136,  1140,
    1144,  1146,  1149,  1152,  1154,  1158,  1162,  1166,  1168,  1172,
    1176,  1180,  1182,  1186,  1190,  1192,  1195,  1198,  1200,  1204,
    1208,  1212,  1214,  1218,  1222,  1226,  1228,  1232,  1236,  1240,
    1242,  1246,  1250,  1254,  1256,  1260,  1264,  1268,  1270,  1274,
    1278,  1282,  1284,  1288,  1292,  1296,  1298,  1302,  1306,  1310,
    1314,  1318,  1322,  1326,  1329,  1332,  1336,  1340,  1344,  1348,
    1351,  1357,  1363,  1369,  1375,  1380,  1385,  1391,  1395,  1397,
    1399,  1401,  1403,  1405,  1407,  1409,  1413,  1417,  1421,  1425,
    1429,  1433,  1437,  1440,  1443,  1447,  1451,  1455,  1459,  1462,
    1468,  1474,  1480,  1486,  1491,  1496,  1502,  1506,  1512,  1518,
    1524,  1529,  1534,  1540,  1544,  1546,  1548,  1550,  1552,  1554,
    1556,  1558,  1560,  1564,  1568,  1572,  1574,  1576,  1578,  1582,
    1586,  1590,  1594,  1598,  1600,  1602,  1604,  1606,  1608,  1611,
    1614,  1617,  1619,  1623,  1625,  1630,  1635,  1640,  1645,  1651,
    1657,  1663,  1669,  1671,  1675,  1679,  1683,  1687,  1691,  1695,
    1699,  1702,  1705,  1709,  1711,  1713,  1715,  1719,  1723,  1727,
    1731,  1734,  1737,  1741,  1743,  1747,  1749,  1753,  1757,  1761,
    1765,  1769,  1773,  1777,  1780,  1783,  1791,  1799,  1807,  1813,
    1819,  1825,  1831,  1839,  1845,  1851,  1857,  1863,  1868,  1874,
    1879,  1881,  1883,  1885,  1888,  1891,  1894,  1896,  1900,  1903,
    1905,  1908,  1911,  1914,  1916,  1919,  1922,  1925,  1927,  1932,
    1938,  1940,  1942,  1946,  1950,  1952,  1954,  1956,  1958,  1960,
    1962,  1965,  1968,  1971,  1973,  1976,  1980,  1983,  1986,  1990,
    1994,  1996,  2002,  2008,  2014,  2020,  2026,  2032,  2038,  2044,
    2050,  2056,  2062,  2068,  2074,  2080,  2086,  2092,  2098,  2104,
    2110,  2116,  2122,  2128,  2134,  2140,  2146,  2152,  2158,  2164,
    2170,  2176,  2182,  2188,  2192,  2196,  2200,  2204,  2208,  2212,
    2216,  2219,  2222,  2226,  2229,  2232,  2235,  2238,  2241,  2244,
    2247,  2250,  2253,  2256,  2259,  2262,  2265,  2268,  2271,  2273,
    2277,  2281,  2285,  2289,  2293,  2297,  2301,  2303,  2305,  2307,
    2310,  2313,  2316,  2318,  2322,  2325,  2328,  2332,  2336,  2338,
    2342,  2346,  2350,  2356,  2362,  2368,  2374,  2380,  2386,  2392,
    2398,  2404,  2410,  2416,  2422,  2428,  2434,  2440,  2446,  2452,
    2458,  2464,  2470,  2476,  2482,  2488,  2494,  2500,  2506,  2512,
    2518,  2524,  2530,  2536,  2542,  2548,  2554,  2560,  2566,  2572,
    2578,  2584,  2590,  2594,  2598,  2602,  2606,  2610,  2614,  2618,
    2621,  2624,  2628,  2631,  2634,  2637,  2640,  2643,  2646,  2649,
    2652,  2655,  2658,  2661,  2664,  2667,  2670,  2673,  2676,  2679,
    2683,  2687,  2691,  2695,  2698,  2700,  2704,  2708,  2712,  2716,
    2720,  2724,  2728,  2730,  2732,  2734,  2737,  2740,  2743,  2745,
    2749,  2752,  2755,  2759,  2763,  2765,  2769,  2773,  2777,  2783,
    2789,  2795,  2801,  2807,  2813,  2819,  2825,  2831,  2837,  2843,
    2849,  2855,  2861,  2867,  2873,  2879,  2885,  2891,  2897,  2903,
    2909,  2915,  2921,  2927,  2933,  2939,  2945,  2951,  2957,  2963,
    2969,  2975,  2981,  2987,  2993,  2999,  3005,  3011,  3017,  3021,
    3025,  3029,  3033,  3037,  3041,  3045,  3048,  3051,  3055,  3058,
    3061,  3064,  3066,  3068,  3071,  3074,  3077,  3080,  3083,  3086,
    3089,  3091
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  mcmas_parser::yyrline_[] =
  {
         0,   295,   295,   296,   299,   302,   305,   309,   310,   311,
     312,   313,   314,   315,   316,   317,   318,   319,   320,   321,
     328,   335,   342,   349,   356,   363,   370,   377,   384,   391,
     398,   408,   411,   415,   419,   423,   426,   430,   434,   439,
     446,   453,   460,   467,   474,   481,   489,   497,   503,   506,
     510,   514,   518,   521,   525,   529,   534,   540,   543,   558,
     566,   569,   573,   577,   581,   584,   588,   592,   596,   602,
     610,   620,   625,   638,   644,   649,   662,   667,   672,   688,
     693,   698,   703,   716,   722,   728,   734,   738,   746,   757,
     763,   767,   770,   773,   777,   783,   786,   790,   794,   798,
     801,   805,   809,   813,   819,   827,   833,   839,   845,   848,
     852,   856,   860,   863,   867,   871,   876,   882,   885,   890,
     896,   899,   904,   907,   912,   917,   920,   925,   932,   935,
     939,   943,   947,   950,   954,   958,   962,   968,   974,   981,
     988,   992,   998,  1002,  1005,  1014,  1030,  1035,  1038,  1047,
    1063,  1068,  1074,  1084,  1088,  1091,  1095,  1098,  1102,  1106,
    1111,  1125,  1139,  1153,  1167,  1173,  1176,  1180,  1184,  1188,
    1192,  1196,  1200,  1204,  1207,  1211,  1215,  1219,  1225,  1228,
    1232,  1248,  1264,  1270,  1277,  1280,  1284,  1288,  1292,  1296,
    1300,  1304,  1308,  1311,  1315,  1319,  1323,  1329,  1335,  1341,
    1347,  1351,  1359,  1369,  1375,  1382,  1385,  1389,  1393,  1397,
    1400,  1404,  1408,  1413,  1419,  1427,  1435,  1441,  1447,  1453,
    1461,  1469,  1474,  1481,  1488,  1493,  1500,  1507,  1512,  1515,
    1519,  1523,  1527,  1530,  1534,  1538,  1542,  1548,  1553,  1559,
    1564,  1570,  1576,  1584,  1594,  1600,  1607,  1613,  1617,  1624,
    1631,  1636,  1642,  1648,  1654,  1660,  1665,  1668,  1673,  1678,
    1683,  1689,  1695,  1701,  1707,  1712,  1719,  1724,  1727,  1732,
    1737,  1742,  1748,  1754,  1760,  1766,  1771,  1778,  1783,  1789,
    1795,  1800,  1803,  1809,  1815,  1820,  1823,  1826,  1831,  1836,
    1840,  1846,  1852,  1857,  1860,  1866,  1871,  1874,  1880,  1885,
    1888,  1891,  1896,  1901,  1905,  1911,  1917,  1922,  1925,  1931,
    1936,  1939,  1945,  1950,  1953,  1956,  1961,  1966,  1970,  1976,
    1982,  1987,  1990,  1996,  2001,  2004,  2010,  2015,  2018,  2021,
    2026,  2031,  2035,  2041,  2047,  2052,  2055,  2061,  2067,  2072,
    2075,  2078,  2083,  2088,  2091,  2097,  2103,  2108,  2111,  2117,
    2123,  2128,  2131,  2134,  2139,  2144,  2150,  2153,  2158,  2163,
    2168,  2174,  2180,  2186,  2192,  2197,  2204,  2221,  2226,  2231,
    2236,  2276,  2282,  2288,  2294,  2300,  2306,  2312,  2318,  2323,
    2326,  2329,  2332,  2335,  2338,  2343,  2346,  2351,  2356,  2361,
    2367,  2373,  2379,  2385,  2390,  2397,  2414,  2419,  2424,  2429,
    2460,  2466,  2472,  2478,  2484,  2490,  2496,  2502,  2519,  2524,
    2529,  2534,  2539,  2544,  2549,  2555,  2558,  2568,  2571,  2574,
    2578,  2581,  2591,  2610,  2615,  2620,  2623,  2626,  2636,  2668,
    2674,  2693,  2698,  2703,  2707,  2710,  2720,  2725,  2728,  2731,
    2735,  2739,  2743,  2744,  2748,  2754,  2759,  2764,  2769,  2777,
    2782,  2787,  2792,  2796,  2799,  2804,  2809,  2814,  2820,  2826,
    2831,  2837,  2842,  2849,  2857,  2860,  2865,  2868,  2872,  2876,
    2880,  2884,  2888,  2892,  2896,  2900,  2904,  2907,  2912,  2917,
    2922,  2928,  2934,  2939,  2945,  2950,  3025,  3087,  3149,  3193,
    3200,  3207,  3214,  3262,  3293,  3299,  3305,  3311,  3317,  3323,
    3329,  3336,  3339,  3343,  3346,  3350,  3354,  3358,  3359,  3360,
    3364,  3367,  3371,  3375,  3379,  3382,  3386,  3390,  3394,  3400,
    3408,  3412,  3419,  3428,  3433,  3437,  3440,  3450,  3457,  3460,
    3464,  3467,  3471,  3475,  3479,  3480,  3482,  3486,  3490,  3494,
    3498,  3502,  3508,  3513,  3518,  3523,  3528,  3533,  3538,  3543,
    3556,  3562,  3568,  3574,  3580,  3586,  3592,  3598,  3604,  3609,
    3614,  3619,  3624,  3629,  3634,  3639,  3652,  3658,  3664,  3670,
    3676,  3682,  3688,  3695,  3698,  3703,  3708,  3713,  3719,  3725,
    3730,  3736,  3741,  3747,  3753,  3759,  3765,  3771,  3777,  3783,
    3791,  3799,  3808,  3818,  3828,  3838,  3848,  3854,  3860,  3875,
    3892,  3909,  3922,  3935,  3940,  3945,  3950,  3957,  3960,  3965,
    3968,  3972,  3976,  3980,  3982,  3987,  3991,  3996,  4000,  4004,
    4014,  4019,  4024,  4030,  4035,  4040,  4045,  4050,  4055,  4060,
    4065,  4071,  4076,  4081,  4086,  4091,  4096,  4101,  4106,  4119,
    4125,  4131,  4137,  4143,  4149,  4155,  4161,  4167,  4172,  4177,
    4182,  4187,  4192,  4197,  4202,  4215,  4221,  4227,  4233,  4239,
    4245,  4251,  4258,  4261,  4266,  4271,  4276,  4282,  4288,  4293,
    4299,  4304,  4310,  4316,  4322,  4328,  4334,  4340,  4346,  4354,
    4362,  4370,  4378,  4387,  4397,  4407,  4417,  4427,  4431,  4435,
    4444,  4453,  4462,  4467,  4482,  4497,  4514,  4531,  4544,  4557,
    4562,  4567,  4572,  4578,  4581,  4585,  4588,  4592,  4596,  4600,
    4603,  4608,  4612,  4617,  4621,  4625,  4635,  4640,  4645,  4651,
    4656,  4661,  4666,  4671,  4676,  4681,  4686,  4692,  4697,  4702,
    4707,  4712,  4717,  4722,  4728,  4741,  4747,  4753,  4759,  4765,
    4771,  4777,  4783,  4789,  4794,  4799,  4804,  4809,  4814,  4819,
    4824,  4837,  4843,  4849,  4855,  4861,  4867,  4873,  4881,  4884,
    4889,  4894,  4899,  4905,  4911,  4916,  4922,  4927,  4933,  4939,
    4945,  4951,  4959,  4967,  4976,  4986,  4996,  5006,  5010,  5014,
    5027,  5042
  };

  // Print the state stack on the debug stream.
  void
  mcmas_parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (state_stack_type::const_iterator i = yystate_stack_.begin ();
	 i != yystate_stack_.end (); ++i)
      *yycdebug_ << ' ' << *i;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  mcmas_parser::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    /* Print the symbols being reduced, and their result.  */
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
	       << " (line " << yylno << "):" << std::endl;
    /* The symbols being reduced.  */
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
		       yyrhs_[yyprhs_[yyrule] + yyi],
		       &(yysemantic_stack_[(yynrhs) - (yyi + 1)]),
		       &(yylocation_stack_[(yynrhs) - (yyi + 1)]));
  }
#endif // YYDEBUG

  /* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
  mcmas_parser::token_number_type
  mcmas_parser::yytranslate_ (int t)
  {
    static
    const token_number_type
    translate_table[] =
    {
           0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int mcmas_parser::yyeof_ = 0;
  const int mcmas_parser::yylast_ = 8772;
  const int mcmas_parser::yynnts_ = 139;
  const int mcmas_parser::yyempty_ = -2;
  const int mcmas_parser::yyfinal_ = 16;
  const int mcmas_parser::yyterror_ = 1;
  const int mcmas_parser::yyerrcode_ = 256;
  const int mcmas_parser::yyntokens_ = 77;

  const unsigned int mcmas_parser::yyuser_token_number_max_ = 331;
  const mcmas_parser::token_number_type mcmas_parser::yyundef_token_ = 2;


} // yy

/* Line 1136 of lalr1.cc  */
#line 13397 "parser/nssis.cc"


/* Line 1138 of lalr1.cc  */
#line 5047 "parser/nssis_new.yy"

void
yy::mcmas_parser::error (const yy::mcmas_parser::location_type& l,
                          const std::string& m)
{
  driver.error (l, m);
}

