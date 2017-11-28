/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20140715

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "parser.y"
	#include <stdlib.h>
	#include <stdio.h>
	#include <string.h>
	#include "tree.h"
	#include "semantic.h"
	#include "genco.h"
    int yylex();
	int yyerror(char *message);
	int getLineNumber();

	TREE* ast_tree;

	
#line 16 "parser.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
		TREE* tree;
		HASH_NODE *symbol;
	} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 47 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define KW_BYTE 257
#define KW_SHORT 258
#define KW_LONG 259
#define KW_FLOAT 260
#define KW_DOUBLE 261
#define KW_IF 262
#define KW_THEN 263
#define KW_ELSE 264
#define KW_WHILE 265
#define KW_FOR 266
#define KW_READ 267
#define KW_RETURN 268
#define KW_PRINT 269
#define OPERATOR_LE 270
#define OPERATOR_GE 271
#define OPERATOR_EQ 272
#define OPERATOR_NE 273
#define OPERATOR_AND 274
#define OPERATOR_OR 275
#define TK_IDENTIFIER 276
#define LIT_INTEGER 277
#define LIT_REAL 278
#define LIT_CHAR 279
#define LIT_STRING 280
#define TOKEN_ERROR 281
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,   17,   17,   15,   15,   15,    2,    2,    2,    2,
    2,    2,    2,    2,    2,    3,    3,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    6,    4,    4,
    5,    5,    7,    7,    7,   18,   18,   18,   10,   10,
    8,    8,    8,    8,    8,    9,    9,   14,   14,   16,
   16,   11,   12,   13,   13,
};
static const YYINT yylen[] = {                            2,
    1,    2,    0,    6,    8,    8,    3,    6,    7,    5,
    2,    3,    2,    1,    0,    2,    0,    1,    4,    4,
    1,    1,    1,    3,    3,    3,    3,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    3,    2,    1,    1,
    3,    0,    1,    1,    1,    1,    1,    1,    2,    0,
    1,    1,    1,    1,    1,    2,    0,    3,    1,    3,
    0,    3,    2,    3,    0,
};
static const YYINT yydefred[] = {                         0,
    0,    0,    0,    0,    1,    0,   51,   52,   53,   54,
   55,    0,    2,    0,    0,    0,    0,    0,   43,   44,
   45,    0,    0,    0,    4,    0,    0,   21,   22,   23,
    0,    0,    0,    0,   46,   47,   48,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   56,
    5,   49,   58,    0,    0,   37,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   26,   27,    0,
    6,    0,   19,   20,    0,    0,    0,    0,    0,    0,
    0,   14,    0,   60,    0,    0,    0,    0,   39,    0,
    0,   11,    0,    0,    0,   63,   62,    0,    0,   12,
    0,   38,    0,    0,    0,    0,    0,    0,    0,   64,
    0,   10,   41,    0,    0,    0,    0,    9,   16,
};
static const YYINT yydgoto[] = {                          3,
   32,   91,  128,  101,  112,  102,   22,   12,   33,   38,
   92,   93,  106,   34,    4,   60,    5,   39,
};
static const YYINT yysindex[] = {                        28,
  -41,  -42,    0,   28,    0,  -42,    0,    0,    0,    0,
    0,  -13,    0,  -54, -272, -157, -222,   18,    0,    0,
    0,   17,  -30,   62,    0, -141,   58,    0,    0,    0,
   75,  423,   38,   36,    0,    0,    0,   30, -141,  -42,
   75,   62,  -37,   24,   75,   75,   75,   75,   75,   75,
   75,   75,   75,   75,   75,   75,   75,  -36,   62,    0,
    0,    0,    0,  164,   49,    0,  127,  127,  127,  127,
  127,  127,  127,  127,  127,  -27,  -27,    0,    0,  -73,
    0,   36,    0,    0,   60,   63,   51,   75,    4,   32,
   52,    0,   -1,    0,   75,   75, -151,  423,    0,  423,
   84,    0,   75,   75,  -73,    0,    0,  187,  383,    0,
    4,    0,  423,  407,   52, -129,  -73,   84,   80,    0,
  -73,    0,    0,   75, -118,  423,  -73,    0,    0,
};
static const YYINT yyrindex[] = {                       148,
    0,    0,    0,  148,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  109,    0,   92,  -11,    0,    0,    0,
    0,  -39,    0,  111,    0,    0,    0,    0,   92,    0,
    0,  109,  -33,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   15,   37,   50,   73,
   85,   98,  120,  140,  272,  -20,    2,    0,    0,  -53,
    0,  111,    0,    0,    0,    0,    0,    0,    0,    0,
   31,    0,    0,    0,    0,    0,    0,  -21,    0,  -43,
  -18,    0,    0,    0,  -53,    0,    0,    0,    0,    0,
    0,    0,   -6,    0,   31,    0,   29,  -18,    0,    0,
   29,    0,    0,    0,  -40,   42,   29,    0,    0,
};
static const YYINT yygindex[] = {                         0,
  460,   66,    0,   44,   41,    0,    0,   12,  121,  126,
  110,    0,   61,  118,    0,  103,  182,    0,
};
#define YYTABLESIZE 698
static const YYINT yytable[] = {                         18,
   40,   59,   42,   18,   59,   15,   16,   18,   18,   18,
   18,   18,   24,   18,   56,   40,    6,   14,   17,   57,
   24,   18,   24,   24,   24,   18,   18,   15,   18,   18,
   18,   18,   18,   18,   25,   18,   17,   13,   24,   24,
   42,   24,   25,   31,   25,   25,   25,   31,   18,   80,
   18,   63,    7,   41,   23,   31,   53,   24,   31,   18,
   25,   25,   26,   25,   66,   56,   54,    2,   55,   32,
   57,   15,   24,   31,   31,   25,   31,   32,   58,   59,
   32,   40,   33,   51,   17,   52,   80,   15,   61,   84,
   33,   18,  103,   33,   25,   32,   32,   42,   32,   95,
    8,   31,   96,   13,   24,   34,   42,   31,   33,   33,
  105,   33,   97,   34,   31,   40,   34,   35,    7,   19,
   20,   21,  104,  107,  110,   35,   25,  111,   35,   32,
   36,   34,   34,  121,   34,   35,   36,   37,   36,   31,
  124,   36,   33,   35,   35,  127,   35,    3,   41,   57,
   50,   61,   28,   15,  118,   65,   36,   36,  123,   36,
   28,   32,   65,   28,   62,   34,    8,   81,   56,   54,
  115,   55,   29,   57,   33,  120,   82,   35,   28,   28,
   29,   28,  122,   29,   94,   13,  125,    0,   85,    0,
   36,   86,  129,   87,   88,   89,   53,   34,   29,   29,
    0,   29,   90,    0,    0,   56,   54,    0,   55,   35,
   57,    0,   28,    0,    7,    8,    9,   10,   11,   53,
   40,    0,   36,   51,    0,   52,    0,  116,   56,   54,
   18,   55,   29,   57,    0,    0,   18,   18,   18,   18,
   18,   18,   13,   24,   28,   42,   51,    0,   52,   24,
   24,   24,   24,   24,   24,    0,   83,    7,   18,   18,
   18,   18,   18,   18,   29,   25,    0,    0,    0,    0,
    0,   25,   25,   25,   25,   25,   25,    0,   31,   43,
   28,   29,   30,   99,   31,   31,   31,   31,   31,   31,
    0,    0,   15,   45,   46,   47,   48,   49,   50,    0,
   32,    0,    0,    1,   30,    8,   32,   32,   32,   32,
   32,   32,   30,   33,    0,   30,    0,    0,    0,   33,
   33,   33,   33,   33,   33,    0,    0,    0,    0,    0,
   30,   30,    0,   30,    0,    0,   34,   27,   28,   29,
   30,    0,   34,   34,   34,   34,   34,   34,   35,    0,
   43,   28,   29,   30,   35,   35,   35,   35,   35,   35,
    0,   36,    0,    0,   30,    0,    0,   36,   36,   36,
   36,   36,   36,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   28,    0,    0,    0,    0,    0,   28,
   28,   28,   28,   28,   28,    0,   30,    0,    0,    0,
    0,    0,    0,   29,    0,    0,    0,    0,    0,   29,
   29,   29,   29,   29,   29,   53,    0,    0,    0,    0,
    0,    0,    0,  117,   56,   54,    0,   55,    0,   57,
    0,    0,    0,   45,   46,   47,   48,   49,   50,   53,
    0,    0,   51,    0,   52,    0,    0,    0,   56,   54,
    0,   55,    0,   57,    0,   53,   45,   46,   47,   48,
   49,   50,    0,    0,   56,   54,   51,   55,   52,   57,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   51,    0,   52,    0,    0,    0,    0,    0,
   44,    0,    0,    0,    0,    0,    0,    0,    0,  119,
   64,    0,    0,    0,   67,   68,   69,   70,   71,   72,
   73,   74,   75,   76,   77,   78,   79,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   30,    0,    0,    0,    0,
    0,   30,   30,   30,   30,   30,   30,   98,  100,    0,
    0,    0,    0,    0,  108,  109,    0,    0,    0,    0,
    0,    0,  113,  114,    0,    0,    0,    0,    0,    0,
  100,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  126,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   45,   46,   47,   48,   49,   50,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   45,   46,   47,   48,
   49,   50,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   45,   46,   47,   48,   49,   50,
};
static const YYINT yycheck[] = {                         33,
   44,   41,   40,  276,   44,   59,   61,   41,   42,   43,
   44,   45,   33,   47,   42,   59,   58,    6,   59,   47,
   41,   33,   43,   44,   45,   59,   60,   41,   62,   41,
   42,   43,   44,   45,   33,   47,   91,   59,   59,   60,
   59,   62,   41,   40,   43,   44,   45,   33,   60,  123,
   62,   40,   59,   91,  277,   41,   33,   40,   44,   93,
   59,   60,   93,   62,   41,   42,   43,   40,   45,   33,
   47,  125,   93,   59,   60,   59,   62,   41,   41,   44,
   44,  125,   33,   60,  125,   62,  123,   59,   59,   41,
   41,  125,   61,   44,   93,   59,   60,   40,   62,   40,
   59,   40,   40,  125,  125,   33,  125,   93,   59,   60,
   59,   62,   62,   41,   40,   58,   44,   33,  125,  277,
  278,  279,   91,  125,  276,   41,  125,   44,   44,   93,
   33,   59,   60,  263,   62,  277,  278,  279,   41,  125,
   61,   44,   93,   59,   60,  264,   62,    0,   91,   41,
   59,   41,   33,  125,  111,  125,   59,   60,  118,   62,
   41,  125,   42,   44,   39,   93,  125,   58,   42,   43,
  105,   45,   33,   47,  125,  115,   59,   93,   59,   60,
   41,   62,  117,   44,   82,    4,  121,   -1,  262,   -1,
   93,  265,  127,  267,  268,  269,   33,  125,   59,   60,
   -1,   62,  276,   -1,   -1,   42,   43,   -1,   45,  125,
   47,   -1,   93,   -1,  257,  258,  259,  260,  261,   33,
  264,   -1,  125,   60,   -1,   62,   -1,   41,   42,   43,
  264,   45,   93,   47,   -1,   -1,  270,  271,  272,  273,
  274,  275,  264,  264,  125,  264,   60,   -1,   62,  270,
  271,  272,  273,  274,  275,   -1,   93,  264,  270,  271,
  272,  273,  274,  275,  125,  264,   -1,   -1,   -1,   -1,
   -1,  270,  271,  272,  273,  274,  275,   -1,  264,  276,
  277,  278,  279,  280,  270,  271,  272,  273,  274,  275,
   -1,   -1,  264,  270,  271,  272,  273,  274,  275,   -1,
  264,   -1,   -1,  276,   33,  264,  270,  271,  272,  273,
  274,  275,   41,  264,   -1,   44,   -1,   -1,   -1,  270,
  271,  272,  273,  274,  275,   -1,   -1,   -1,   -1,   -1,
   59,   60,   -1,   62,   -1,   -1,  264,  276,  277,  278,
  279,   -1,  270,  271,  272,  273,  274,  275,  264,   -1,
  276,  277,  278,  279,  270,  271,  272,  273,  274,  275,
   -1,  264,   -1,   -1,   93,   -1,   -1,  270,  271,  272,
  273,  274,  275,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  264,   -1,   -1,   -1,   -1,   -1,  270,
  271,  272,  273,  274,  275,   -1,  125,   -1,   -1,   -1,
   -1,   -1,   -1,  264,   -1,   -1,   -1,   -1,   -1,  270,
  271,  272,  273,  274,  275,   33,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   41,   42,   43,   -1,   45,   -1,   47,
   -1,   -1,   -1,  270,  271,  272,  273,  274,  275,   33,
   -1,   -1,   60,   -1,   62,   -1,   -1,   -1,   42,   43,
   -1,   45,   -1,   47,   -1,   33,  270,  271,  272,  273,
  274,  275,   -1,   -1,   42,   43,   60,   45,   62,   47,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   60,   -1,   62,   -1,   -1,   -1,   -1,   -1,
   31,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   93,
   41,   -1,   -1,   -1,   45,   46,   47,   48,   49,   50,
   51,   52,   53,   54,   55,   56,   57,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  264,   -1,   -1,   -1,   -1,
   -1,  270,  271,  272,  273,  274,  275,   88,   89,   -1,
   -1,   -1,   -1,   -1,   95,   96,   -1,   -1,   -1,   -1,
   -1,   -1,  103,  104,   -1,   -1,   -1,   -1,   -1,   -1,
  111,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  124,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  270,  271,  272,  273,  274,  275,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  270,  271,  272,  273,
  274,  275,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  270,  271,  272,  273,  274,  275,
};
#define YYFINAL 3
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 281
#define YYUNDFTOKEN 302
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"'!'",0,0,0,0,0,0,"'('","')'","'*'","'+'","','","'-'",0,"'/'",0,0,0,0,0,0,0,0,0,
0,"':'","';'","'<'","'='","'>'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,"'['",0,"']'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"'{'",0,"'}'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"KW_BYTE","KW_SHORT","KW_LONG","KW_FLOAT",
"KW_DOUBLE","KW_IF","KW_THEN","KW_ELSE","KW_WHILE","KW_FOR","KW_READ",
"KW_RETURN","KW_PRINT","OPERATOR_LE","OPERATOR_GE","OPERATOR_EQ","OPERATOR_NE",
"OPERATOR_AND","OPERATOR_OR","TK_IDENTIFIER","LIT_INTEGER","LIT_REAL",
"LIT_CHAR","LIT_STRING","TOKEN_ERROR",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : program",
"program : declarationsList",
"declarationsList : declarations declarationsList",
"declarationsList :",
"declarations : TK_IDENTIFIER ':' types '=' initialValueTypes ';'",
"declarations : TK_IDENTIFIER ':' types '[' LIT_INTEGER ']' vectorInit ';'",
"declarations : '(' types ')' TK_IDENTIFIER '(' params ')' block",
"cmd : TK_IDENTIFIER '=' exp",
"cmd : TK_IDENTIFIER '[' exp ']' '=' exp",
"cmd : KW_IF '(' exp ')' KW_THEN cmd else",
"cmd : KW_WHILE '(' exp ')' cmd",
"cmd : KW_PRINT printables",
"cmd : KW_READ '>' TK_IDENTIFIER",
"cmd : KW_RETURN exp",
"cmd : block",
"cmd :",
"else : KW_ELSE cmd",
"else :",
"exp : TK_IDENTIFIER",
"exp : TK_IDENTIFIER '[' exp ']'",
"exp : TK_IDENTIFIER '(' params ')'",
"exp : LIT_INTEGER",
"exp : LIT_REAL",
"exp : LIT_CHAR",
"exp : exp '+' exp",
"exp : exp '-' exp",
"exp : exp '*' exp",
"exp : exp '/' exp",
"exp : exp '<' exp",
"exp : exp '>' exp",
"exp : exp '!' exp",
"exp : exp OPERATOR_LE exp",
"exp : exp OPERATOR_GE exp",
"exp : exp OPERATOR_EQ exp",
"exp : exp OPERATOR_NE exp",
"exp : exp OPERATOR_AND exp",
"exp : exp OPERATOR_OR exp",
"exp : '(' exp ')'",
"printables : elem restoElem",
"elem : LIT_STRING",
"elem : exp",
"restoElem : ',' elem restoElem",
"restoElem :",
"initialValueTypes : LIT_INTEGER",
"initialValueTypes : LIT_REAL",
"initialValueTypes : LIT_CHAR",
"initialValueTypesVector : LIT_INTEGER",
"initialValueTypesVector : LIT_REAL",
"initialValueTypesVector : LIT_CHAR",
"vectorInit : initialValueTypesVector vectorInit",
"vectorInit :",
"types : KW_BYTE",
"types : KW_SHORT",
"types : KW_LONG",
"types : KW_FLOAT",
"types : KW_DOUBLE",
"params : param restoParam",
"params :",
"param : TK_IDENTIFIER ':' types",
"param : exp",
"restoParam : ',' param restoParam",
"restoParam :",
"block : '{' cmdblock '}'",
"cmdblock : cmd restoCmd",
"restoCmd : ';' cmd restoCmd",
"restoCmd :",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 204 "parser.y"

	int yyerror(char *message)
	{
		fprintf(stderr, "Erro -> %s na linha %d\n",message,getLineNumber());
		exit(3);
	}
#line 458 "y.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    YYINT *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return YYENOMEM;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    YYERROR_CALL("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 1:
#line 76 "parser.y"
	{
        ast_tree = tree_create(TREE_PROGRAM, 0, yystack.l_mark[0].tree ,0 ,0,0);tree_print(yystack.l_mark[0].tree, 0);
        semanticSetTypes(yystack.l_mark[0].tree);
        semanticCheckUndeclared();
        semanticCheckUsage(yystack.l_mark[0].tree);
        semanticCheckOperands(yystack.l_mark[0].tree);
				tac_print_back(tac_generator(yystack.l_mark[0].tree));
    }
break;
case 2:
#line 86 "parser.y"
	{yyval.tree = tree_create(DECLARATIONS, 0, yystack.l_mark[-1].tree ,yystack.l_mark[0].tree ,0, 0);yyval.tree->line = getLineNumber();}
break;
case 3:
#line 87 "parser.y"
	{yyval.tree = 0;}
break;
case 4:
#line 91 "parser.y"
	{yyval.tree = tree_create(TREE_DECLARATION_SCALAR, yystack.l_mark[-5].symbol,yystack.l_mark[-3].tree, yystack.l_mark[-1].tree ,0 ,0);yyval.tree->line = getLineNumber();}
break;
case 5:
#line 92 "parser.y"
	{yyval.tree = tree_create(TREE_DECLARATION_VECTOR,yystack.l_mark[-7].symbol,yystack.l_mark[-5].tree, tree_create(TREE_DECLARATION_VECTOR_NUMBER,yystack.l_mark[-3].symbol,0,0,0,0),yystack.l_mark[-1].tree, 0);yyval.tree->line = getLineNumber();}
break;
case 6:
#line 93 "parser.y"
	{yyval.tree = tree_create(TREE_FUNCTION, yystack.l_mark[-4].symbol,yystack.l_mark[-6].tree, yystack.l_mark[-2].tree ,yystack.l_mark[0].tree ,0);yyval.tree->line = yystack.l_mark[-6].tree->line;}
break;
case 7:
#line 98 "parser.y"
	{yyval.tree = tree_create(TREE_ASSIGN, yystack.l_mark[-2].symbol, yystack.l_mark[0].tree ,0 ,0 ,0); yyval.tree->line = getLineNumber();yyval.tree->line = getLineNumber();}
break;
case 8:
#line 99 "parser.y"
	{yyval.tree = tree_create(TREE_ASSIGN_VECTOR, yystack.l_mark[-5].symbol, tree_create(TREE_VECTOR_VALUES_POSITION, 0, yystack.l_mark[-3].tree ,0 ,0 ,0) ,yystack.l_mark[0].tree ,0 ,0);yyval.tree->line = getLineNumber();}
break;
case 9:
#line 100 "parser.y"
	{yyval.tree = tree_create(TREE_IF, 0, yystack.l_mark[-4].tree ,yystack.l_mark[-1].tree ,yystack.l_mark[0].tree ,0);yyval.tree->line = yystack.l_mark[-4].tree->line;}
break;
case 10:
#line 101 "parser.y"
	{yyval.tree = tree_create(TREE_WHILE, 0, yystack.l_mark[-2].tree ,yystack.l_mark[0].tree ,0 ,0);yyval.tree->line = yystack.l_mark[-2].tree->line;}
break;
case 11:
#line 102 "parser.y"
	{yyval.tree = tree_create(TREE_PRINT, 0, yystack.l_mark[0].tree ,0 ,0 ,0);yyval.tree->line = getLineNumber();}
break;
case 12:
#line 103 "parser.y"
	{yyval.tree = tree_create(TREE_READ, yystack.l_mark[0].symbol, 0 ,0 ,0 ,0);yyval.tree->line = getLineNumber();}
break;
case 13:
#line 104 "parser.y"
	{yyval.tree = tree_create(TREE_RETURN, 0, yystack.l_mark[0].tree ,0 ,0 ,0);yyval.tree->line = getLineNumber();}
break;
case 14:
#line 105 "parser.y"
	{yyval.tree = yystack.l_mark[0].tree;}
break;
case 15:
#line 106 "parser.y"
	{yyval.tree = 0;}
break;
case 16:
#line 110 "parser.y"
	{yyval.tree = tree_create(TREE_ELSE, 0, yystack.l_mark[0].tree ,0 ,0 ,0);yyval.tree->line = getLineNumber();}
break;
case 17:
#line 111 "parser.y"
	{yyval.tree = 0;}
break;
case 18:
#line 117 "parser.y"
	{yyval.tree = tree_create(TREE_SYMBOL, yystack.l_mark[0].symbol, 0 ,0 ,0 ,0);yyval.tree->line = getLineNumber();}
break;
case 19:
#line 118 "parser.y"
	{yyval.tree = tree_create(TREE_VECTOR, yystack.l_mark[-3].symbol, yystack.l_mark[-1].tree ,0 ,0 ,0);yyval.tree->line = getLineNumber();}
break;
case 20:
#line 119 "parser.y"
	{yyval.tree = tree_create(TREE_FUNCTION_CALL, yystack.l_mark[-3].symbol, yystack.l_mark[-1].tree ,0, 0,0);yyval.tree->line = getLineNumber();}
break;
case 21:
#line 120 "parser.y"
	{yyval.tree = tree_create(TREE_SYMBOL, yystack.l_mark[0].symbol, 0 ,0 ,0 ,0);yyval.tree->line = getLineNumber();}
break;
case 22:
#line 121 "parser.y"
	{yyval.tree = tree_create(TREE_SYMBOL, yystack.l_mark[0].symbol, 0 ,0 ,0 ,0);yyval.tree->line = getLineNumber();}
break;
case 23:
#line 122 "parser.y"
	{yyval.tree = tree_create(TREE_SYMBOL, yystack.l_mark[0].symbol, 0 ,0 ,0 ,0);yyval.tree->line = getLineNumber();}
break;
case 24:
#line 123 "parser.y"
	{yyval.tree = tree_create(TREE_ADD, 0,yystack.l_mark[-2].tree, yystack.l_mark[0].tree ,0 ,0);yyval.tree->line = getLineNumber();}
break;
case 25:
#line 124 "parser.y"
	{yyval.tree = tree_create(TREE_SUB, 0,yystack.l_mark[-2].tree, yystack.l_mark[0].tree ,0 ,0);yyval.tree->line = getLineNumber();}
break;
case 26:
#line 125 "parser.y"
	{yyval.tree = tree_create(TREE_MUL, 0,yystack.l_mark[-2].tree, yystack.l_mark[0].tree ,0 ,0);yyval.tree->line = getLineNumber();}
break;
case 27:
#line 126 "parser.y"
	{yyval.tree = tree_create(TREE_DIV, 0,yystack.l_mark[-2].tree, yystack.l_mark[0].tree ,0 ,0);yyval.tree->line = getLineNumber();}
break;
case 28:
#line 127 "parser.y"
	{yyval.tree = tree_create(TREE_LESS, 0,yystack.l_mark[-2].tree, yystack.l_mark[0].tree ,0 ,0);yyval.tree->line = getLineNumber();}
break;
case 29:
#line 128 "parser.y"
	{yyval.tree = tree_create(TREE_GREATER, 0,yystack.l_mark[-2].tree, yystack.l_mark[0].tree ,0 ,0);yyval.tree->line = getLineNumber();}
break;
case 30:
#line 129 "parser.y"
	{yyval.tree = tree_create(TREE_NOT, 0,yystack.l_mark[-2].tree, yystack.l_mark[0].tree ,0 ,0);yyval.tree->line = getLineNumber();}
break;
case 31:
#line 130 "parser.y"
	{yyval.tree = tree_create(TREE_LE,0, yystack.l_mark[-2].tree, yystack.l_mark[0].tree ,0 ,0 );yyval.tree->line = getLineNumber();}
break;
case 32:
#line 131 "parser.y"
	{yyval.tree = tree_create(TREE_GE, 0,yystack.l_mark[-2].tree, yystack.l_mark[0].tree ,0 ,0);yyval.tree->line = getLineNumber();}
break;
case 33:
#line 132 "parser.y"
	{yyval.tree = tree_create(TREE_EQ, 0,yystack.l_mark[-2].tree, yystack.l_mark[0].tree ,0 ,0);yyval.tree->line = getLineNumber();}
break;
case 34:
#line 133 "parser.y"
	{yyval.tree = tree_create(TREE_NE,0, yystack.l_mark[-2].tree, yystack.l_mark[0].tree ,0 ,0);yyval.tree->line = getLineNumber();}
break;
case 35:
#line 134 "parser.y"
	{yyval.tree = tree_create(TREE_AND,0,yystack.l_mark[-2].tree, yystack.l_mark[0].tree ,0 ,0);yyval.tree->line = getLineNumber();}
break;
case 36:
#line 135 "parser.y"
	{yyval.tree = tree_create(TREE_OR, 0,yystack.l_mark[-2].tree, yystack.l_mark[0].tree ,0 ,0);yyval.tree->line = getLineNumber();}
break;
case 37:
#line 136 "parser.y"
	{yyval.tree = tree_create(TREE_PAR, 0, yystack.l_mark[-1].tree, 0,0,0);yyval.tree->line = getLineNumber();}
break;
case 38:
#line 140 "parser.y"
	{yyval.tree = tree_create(TREE_PRINTABLE, 0, yystack.l_mark[-1].tree ,yystack.l_mark[0].tree ,0 ,0);yyval.tree->line = getLineNumber();}
break;
case 39:
#line 143 "parser.y"
	{yyval.tree = tree_create(TREE_SYMBOL, yystack.l_mark[0].symbol,0,0 ,0 ,0);yyval.tree->line = getLineNumber();}
break;
case 40:
#line 144 "parser.y"
	{yyval.tree = yystack.l_mark[0].tree;}
break;
case 41:
#line 147 "parser.y"
	{yyval.tree = tree_create(TREE_PRINTABLE, 0, yystack.l_mark[-1].tree ,yystack.l_mark[0].tree ,0 ,0);yyval.tree->line = getLineNumber();}
break;
case 42:
#line 148 "parser.y"
	{yyval.tree = 0;}
break;
case 43:
#line 151 "parser.y"
	{yyval.tree = tree_create(TREE_DECLARATION_SYMBOL, yystack.l_mark[0].symbol,0,0 ,0 ,0);yyval.tree->line = getLineNumber();}
break;
case 44:
#line 152 "parser.y"
	{yyval.tree = tree_create(TREE_DECLARATION_SYMBOL, yystack.l_mark[0].symbol,0,0 ,0 ,0);yyval.tree->line = getLineNumber();}
break;
case 45:
#line 153 "parser.y"
	{yyval.tree = tree_create(TREE_DECLARATION_SYMBOL, yystack.l_mark[0].symbol,0,0 ,0 ,0);yyval.tree->line = getLineNumber();}
break;
case 46:
#line 156 "parser.y"
	{yyval.tree = tree_create(TREE_DECLARATION_SYMBOL_VECTOR, yystack.l_mark[0].symbol,0,0 ,0 ,0);yyval.tree->line = getLineNumber();}
break;
case 47:
#line 157 "parser.y"
	{yyval.tree = tree_create(TREE_DECLARATION_SYMBOL_VECTOR, yystack.l_mark[0].symbol,0,0 ,0 ,0);yyval.tree->line = getLineNumber();}
break;
case 48:
#line 158 "parser.y"
	{yyval.tree = tree_create(TREE_DECLARATION_SYMBOL_VECTOR, yystack.l_mark[0].symbol,0,0 ,0 ,0);yyval.tree->line = getLineNumber();}
break;
case 49:
#line 162 "parser.y"
	{yyval.tree = tree_create(TREE_VECTOR_VALUES, 0, yystack.l_mark[-1].tree ,yystack.l_mark[0].tree ,0 ,0);yyval.tree->line = getLineNumber();}
break;
case 50:
#line 163 "parser.y"
	{yyval.tree = 0;}
break;
case 51:
#line 168 "parser.y"
	{yyval.tree = tree_create(TREE_KW_BYTE, 0,0,0 ,0 ,0);yyval.tree->line = getLineNumber();}
break;
case 52:
#line 169 "parser.y"
	{yyval.tree = tree_create(TREE_KW_SHORT, 0,0,0 ,0 ,0);yyval.tree->line = getLineNumber();}
break;
case 53:
#line 170 "parser.y"
	{yyval.tree = tree_create(TREE_KW_LONG, 0,0,0 ,0 ,0);yyval.tree->line = getLineNumber();}
break;
case 54:
#line 171 "parser.y"
	{yyval.tree = tree_create(TREE_KW_FLOAT, 0,0,0 ,0 ,0);yyval.tree->line = getLineNumber();}
break;
case 55:
#line 172 "parser.y"
	{yyval.tree = tree_create(TREE_KW_DOUBLE, 0,0,0 ,0 ,0);yyval.tree->line = getLineNumber();}
break;
case 56:
#line 176 "parser.y"
	{yyval.tree = tree_create(TREE_PARAMS, 0,yystack.l_mark[-1].tree, yystack.l_mark[0].tree ,0 ,0);yyval.tree->line = getLineNumber();}
break;
case 57:
#line 177 "parser.y"
	{yyval.tree = 0;}
break;
case 58:
#line 183 "parser.y"
	{yyval.tree = tree_create(TREE_PARAM, yystack.l_mark[-2].symbol,yystack.l_mark[0].tree,0 ,0 ,0);yyval.tree->line = getLineNumber();}
break;
case 59:
#line 184 "parser.y"
	{yyval.tree = yystack.l_mark[0].tree;}
break;
case 60:
#line 187 "parser.y"
	{yyval.tree = tree_create(TREE_PARAMS, 0,yystack.l_mark[-1].tree, yystack.l_mark[0].tree ,0 ,0);yyval.tree->line = getLineNumber();}
break;
case 61:
#line 188 "parser.y"
	{yyval.tree = 0;}
break;
case 62:
#line 193 "parser.y"
	{yyval.tree = yystack.l_mark[-1].tree; }
break;
case 63:
#line 196 "parser.y"
	{yyval.tree = tree_create(TREE_CMD_BLOCK, 0,yystack.l_mark[-1].tree, yystack.l_mark[0].tree ,0 ,0);yyval.tree->line = getLineNumber();}
break;
case 64:
#line 199 "parser.y"
	{yyval.tree = tree_create(TREE_CMD_LIST, 0,yystack.l_mark[-1].tree, yystack.l_mark[0].tree ,0 ,0);yyval.tree->line = getLineNumber();}
break;
case 65:
#line 200 "parser.y"
	{yyval.tree = 0;}
break;
#line 927 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                yys = yyname[YYTRANSLATE(yychar)];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    YYERROR_CALL("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
