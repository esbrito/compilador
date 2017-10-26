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
	int yylex();
	int yyerror(char *message);
	int getLineNumber();
	
#line 11 "parser.y"
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
#line 42 "y.tab.c"

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
    0,    2,    2,    3,    3,    6,    6,    6,    6,    6,
    6,    6,    6,    8,    8,    7,    7,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    9,   12,   12,
   13,   13,    4,    4,   14,   15,   17,   17,   17,   18,
   18,    5,   16,   16,   16,   16,   16,   11,   11,   19,
   19,   20,   20,   10,   21,   22,   22,
};
static const YYINT yylen[] = {                            2,
    1,    2,    0,    3,    2,    2,    7,    5,    2,    3,
    2,    1,    0,    2,    0,    2,    5,    1,    4,    4,
    1,    1,    1,    3,    3,    3,    3,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    3,    2,    1,    1,
    3,    0,    2,    2,    3,    5,    1,    1,    1,    2,
    0,    7,    1,    1,    1,    1,    1,    2,    0,    3,
    1,    3,    0,    3,    2,    3,    0,
};
static const YYINT yydefred[] = {                         0,
    0,    0,    0,    1,    0,    0,   53,   54,   55,   56,
   57,    5,    0,    2,    4,    0,    0,    0,    0,   43,
   44,    0,    0,    0,   47,   48,   49,   45,    0,    0,
    0,    0,   21,   22,   23,    0,    0,    0,    0,    0,
   46,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   58,   50,   60,    0,    0,   37,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   26,   27,
    0,   52,    0,   20,   19,    0,    0,    0,    0,    0,
    0,    0,   12,    0,   62,    0,    0,    0,    0,   39,
    0,    9,    0,    0,    0,    6,    0,   65,   64,    0,
    0,   10,    0,   38,    0,    0,    0,    0,    0,    0,
    0,   66,    0,    8,   41,    0,    0,    0,    0,    7,
   14,
};
static const YYINT yydgoto[] = {                          3,
   37,    4,    5,   15,   12,   92,  106,  130,  102,   93,
   38,  103,  114,   16,   17,   13,   40,   41,   39,   62,
   94,  108,
};
static const YYINT yysindex[] = {                        28,
  -41,  -42,    0,    0,   28,  -42,    0,    0,    0,    0,
    0,    0,  -23,    0,    0,  -55,  -31,  -54, -224,    0,
    0, -141, -222,   18,    0,    0,    0,    0,  -30,   62,
 -141,   58,    0,    0,    0,   75,  423,   35,   36, -141,
    0,  -42,   62,   75,  -37,   24,   75,   75,   75,   75,
   75,   75,   75,   75,   75,   75,   75,   75,   75,  -44,
   62,    0,    0,    0,   48,  164,    0,  127,  127,  127,
  127,  127,  127,  127,  127,  127,  -27,  -27,    0,    0,
  -73,    0,   36,    0,    0,   53,   60,   41,   75,    4,
   59,   31,    0,  -14,    0,   75,   75, -163,  423,    0,
  423,    0,   77,   75,   75,    0,  -73,    0,    0,  187,
  383,    0,    4,    0,  423,  407,   31, -139,  -73,   77,
   61,    0,  -73,    0,    0,   75, -136,  423,  -73,    0,
    0,
};
static const YYINT yyrindex[] = {                       125,
    0,    0,    0,    0,  125,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   93,
   82,  -11,    0,    0,    0,    0,  -39,    0,  105,   82,
    0,    0,   93,    0,  -33,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   15,   37,   50,
   73,   85,   98,  120,  140,  272,  -20,    2,    0,    0,
  -53,    0,  105,    0,    0,    0,    0,    0,    0,    0,
    0,   23,    0,    0,    0,    0,    0,    0,  -21,    0,
  -43,    0,  -18,    0,    0,    0,  -53,    0,    0,    0,
    0,    0,    0,    0,   -6,    0,   23,    0,   29,  -18,
    0,    0,   29,    0,    0,    0,  -40,   42,   29,    0,
    0,
};
static const YYINT yygindex[] = {                         0,
  459,  146,    0,    0,    0,   64,    0,    0,    0,   92,
  112,   43,   39,    0,    0,   81,  141,  128,  104,   94,
    0,   68,
};
#define YYTABLESIZE 698
static const YYINT yytable[] = {                         18,
   40,   61,   43,   20,   61,   13,   22,   18,   18,   18,
   18,   18,   24,   18,   58,   40,    6,   19,   15,   59,
   24,   18,   24,   24,   24,   18,   18,   21,   18,   18,
   18,   18,   18,   18,   25,   18,   23,   11,   24,   24,
   42,   24,   25,   36,   25,   25,   25,   31,   18,   81,
   18,   24,   16,   44,   29,   31,   55,   30,   31,   18,
   25,   25,   31,   25,   67,   58,   56,    2,   57,   32,
   59,   13,   24,   31,   31,   60,   31,   32,   81,   61,
   32,   40,   33,   53,   15,   54,   18,   13,   84,  107,
   33,   18,   96,   33,   25,   32,   32,   43,   32,   97,
   17,   36,   98,   11,   24,   34,   42,   31,   33,   33,
  109,   33,  112,   34,   36,   42,   34,   35,   16,  104,
  113,  126,   64,  123,    3,   35,   25,  129,   35,   32,
   36,   34,   34,   59,   34,   25,   26,   27,   36,   31,
   51,   36,   33,   35,   35,   63,   35,   67,   44,  105,
   14,   82,   28,   13,   65,  120,   36,   36,  125,   36,
   28,   32,   28,   28,   83,   34,   17,   63,   58,   56,
  117,   57,   29,   59,   33,    0,   95,   35,   28,   28,
   29,   28,  124,   29,  122,    0,  127,    0,   86,    0,
   36,   87,  131,   88,   89,   90,   55,   34,   29,   29,
    0,   29,   91,    0,    0,   58,   56,    0,   57,   35,
   59,    0,   28,    0,    7,    8,    9,   10,   11,   55,
   40,    0,   36,   53,    0,   54,    0,  118,   58,   56,
   18,   57,   29,   59,    0,    0,   18,   18,   18,   18,
   18,   18,   11,   24,   28,   42,   53,    0,   54,   24,
   24,   24,   24,   24,   24,    0,   85,   16,   18,   18,
   18,   18,   18,   18,   29,   25,    0,    0,    0,    0,
    0,   25,   25,   25,   25,   25,   25,    0,   31,   45,
   33,   34,   35,  100,   31,   31,   31,   31,   31,   31,
    0,    0,   13,   47,   48,   49,   50,   51,   52,    0,
   32,    0,    0,    1,   30,   17,   32,   32,   32,   32,
   32,   32,   30,   33,    0,   30,    0,    0,    0,   33,
   33,   33,   33,   33,   33,    0,    0,    0,    0,    0,
   30,   30,    0,   30,    0,    0,   34,   32,   33,   34,
   35,    0,   34,   34,   34,   34,   34,   34,   35,    0,
   45,   33,   34,   35,   35,   35,   35,   35,   35,   35,
    0,   36,    0,    0,   30,    0,    0,   36,   36,   36,
   36,   36,   36,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   28,    0,    0,    0,    0,    0,   28,
   28,   28,   28,   28,   28,    0,   30,    0,    0,    0,
    0,    0,    0,   29,    0,    0,    0,    0,    0,   29,
   29,   29,   29,   29,   29,   55,    0,    0,    0,    0,
    0,    0,    0,  119,   58,   56,    0,   57,    0,   59,
    0,    0,    0,   47,   48,   49,   50,   51,   52,   55,
    0,    0,   53,    0,   54,    0,    0,    0,   58,   56,
    0,   57,    0,   59,    0,   55,   47,   48,   49,   50,
   51,   52,    0,    0,   58,   56,   53,   57,   54,   59,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   53,    0,   54,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   46,    0,    0,    0,    0,  121,
    0,    0,   66,    0,    0,   68,   69,   70,   71,   72,
   73,   74,   75,   76,   77,   78,   79,   80,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   30,    0,    0,    0,    0,
    0,   30,   30,   30,   30,   30,   30,   99,  101,    0,
    0,    0,    0,    0,  110,  111,    0,    0,    0,    0,
    0,    0,  115,  116,    0,    0,    0,    0,    0,    0,
    0,  101,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  128,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   47,   48,   49,   50,   51,   52,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   47,   48,   49,   50,
   51,   52,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   47,   48,   49,   50,   51,   52,
};
static const YYINT yycheck[] = {                         33,
   44,   41,   40,   59,   44,   59,   61,   41,   42,   43,
   44,   45,   33,   47,   42,   59,   58,   41,   59,   47,
   41,   33,   43,   44,   45,   59,   60,   59,   62,   41,
   42,   43,   44,   45,   33,   47,   91,   59,   59,   60,
   59,   62,   41,   40,   43,   44,   45,   33,   60,  123,
   62,  276,   59,   91,  277,   41,   33,   40,   44,   93,
   59,   60,   93,   62,   41,   42,   43,   40,   45,   33,
   47,  125,   93,   59,   60,   41,   62,   41,  123,   44,
   44,  125,   33,   60,  125,   62,    6,   59,   41,   59,
   41,  125,   40,   44,   93,   59,   60,   40,   62,   40,
   59,   40,   62,  125,  125,   33,  125,   93,   59,   60,
  125,   62,  276,   41,   40,   58,   44,   33,  125,   61,
   44,   61,   42,  263,    0,   41,  125,  264,   44,   93,
   33,   59,   60,   41,   62,  277,  278,  279,   41,  125,
   59,   44,   93,   59,   60,   41,   62,  125,   91,   91,
    5,   60,   33,  125,   43,  113,   59,   60,  120,   62,
   41,  125,   22,   44,   61,   93,  125,   40,   42,   43,
  107,   45,   33,   47,  125,   -1,   83,   93,   59,   60,
   41,   62,  119,   44,  117,   -1,  123,   -1,  262,   -1,
   93,  265,  129,  267,  268,  269,   33,  125,   59,   60,
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
   -1,   -1,   -1,   -1,   36,   -1,   -1,   -1,   -1,   93,
   -1,   -1,   44,   -1,   -1,   47,   48,   49,   50,   51,
   52,   53,   54,   55,   56,   57,   58,   59,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  264,   -1,   -1,   -1,   -1,
   -1,  270,  271,  272,  273,  274,  275,   89,   90,   -1,
   -1,   -1,   -1,   -1,   96,   97,   -1,   -1,   -1,   -1,
   -1,   -1,  104,  105,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  113,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  126,   -1,   -1,   -1,   -1,   -1,
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
#define YYUNDFTOKEN 306
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
"LIT_CHAR","LIT_STRING","TOKEN_ERROR",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : program",
"program : declarationsList",
"declarationsList : declarations declarationsList",
"declarationsList :",
"declarations : TK_IDENTIFIER ':' globalVars",
"declarations : '(' function",
"cmd : TK_IDENTIFIER atrib",
"cmd : KW_IF '(' exp ')' KW_THEN cmd else",
"cmd : KW_WHILE '(' exp ')' cmd",
"cmd : KW_PRINT printables",
"cmd : KW_READ '>' TK_IDENTIFIER",
"cmd : KW_RETURN exp",
"cmd : block",
"cmd :",
"else : KW_ELSE cmd",
"else :",
"atrib : '=' exp",
"atrib : '[' exp ']' '=' exp",
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
"globalVars : scalarType ';'",
"globalVars : vectorType ';'",
"scalarType : types '=' initialValueTypes",
"vectorType : types '[' LIT_INTEGER ']' vectorInit",
"initialValueTypes : LIT_INTEGER",
"initialValueTypes : LIT_REAL",
"initialValueTypes : LIT_CHAR",
"vectorInit : initialValueTypes vectorInit",
"vectorInit :",
"function : types ')' TK_IDENTIFIER '(' params ')' block",
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
#line 173 "parser.y"

	int yyerror(char *message)
	{
		fprintf(stderr, "Erro -> %s na linha %d\n",message,getLineNumber());
		exit(3);
	}
#line 460 "y.tab.c"

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
case 8:
#line 70 "parser.y"
	{tree_print(yystack.l_mark[-2].tree);}
break;
case 18:
#line 88 "parser.y"
	{yyval.tree = tree_create(TREE_SYMBOL, yystack.l_mark[0].symbol, 0 ,0 ,0 ,0);}
break;
case 19:
#line 89 "parser.y"
	{yyval.tree = tree_create(TREE_SYMBOL, yystack.l_mark[-3].symbol, yystack.l_mark[-1].tree ,0 ,0 ,0);}
break;
case 20:
#line 90 "parser.y"
	{yyval.tree = tree_create(TREE_SYMBOL, yystack.l_mark[-3].symbol, 0 ,0 ,0 ,0);}
break;
case 21:
#line 91 "parser.y"
	{yyval.tree = tree_create(TREE_SYMBOL, yystack.l_mark[0].symbol, 0 ,0 ,0 ,0);}
break;
case 22:
#line 92 "parser.y"
	{yyval.tree = tree_create(TREE_SYMBOL, yystack.l_mark[0].symbol, 0 ,0 ,0 ,0);}
break;
case 23:
#line 93 "parser.y"
	{yyval.tree = tree_create(TREE_SYMBOL, yystack.l_mark[0].symbol, 0 ,0 ,0 ,0);}
break;
case 24:
#line 94 "parser.y"
	{yyval.tree = tree_create(TREE_SYMBOL, 0,yystack.l_mark[-2].tree, yystack.l_mark[0].tree ,0 ,0);}
break;
case 25:
#line 95 "parser.y"
	{yyval.tree = tree_create(TREE_SYMBOL, 0,yystack.l_mark[-2].tree, yystack.l_mark[0].tree ,0 ,0);}
break;
case 26:
#line 96 "parser.y"
	{yyval.tree = tree_create(TREE_SYMBOL, 0,yystack.l_mark[-2].tree, yystack.l_mark[0].tree ,0 ,0);}
break;
case 27:
#line 97 "parser.y"
	{yyval.tree = tree_create(TREE_SYMBOL, 0,yystack.l_mark[-2].tree, yystack.l_mark[0].tree ,0 ,0);}
break;
case 28:
#line 98 "parser.y"
	{yyval.tree = tree_create(TREE_SYMBOL, 0,yystack.l_mark[-2].tree, yystack.l_mark[0].tree ,0 ,0);}
break;
case 29:
#line 99 "parser.y"
	{yyval.tree = tree_create(TREE_SYMBOL, 0,yystack.l_mark[-2].tree, yystack.l_mark[0].tree ,0 ,0);}
break;
case 30:
#line 100 "parser.y"
	{yyval.tree = tree_create(TREE_SYMBOL, 0,yystack.l_mark[-2].tree, yystack.l_mark[0].tree ,0 ,0);}
break;
case 31:
#line 101 "parser.y"
	{yyval.tree = tree_create(TREE_SYMBOL,0, yystack.l_mark[-2].tree, yystack.l_mark[0].tree ,0 ,0 );}
break;
case 32:
#line 102 "parser.y"
	{yyval.tree = tree_create(TREE_SYMBOL, 0,yystack.l_mark[-2].tree, yystack.l_mark[0].tree ,0 ,0);}
break;
case 33:
#line 103 "parser.y"
	{yyval.tree = tree_create(TREE_SYMBOL, 0,yystack.l_mark[-2].tree, yystack.l_mark[0].tree ,0 ,0);}
break;
case 34:
#line 104 "parser.y"
	{yyval.tree = tree_create(TREE_SYMBOL,0, yystack.l_mark[-2].tree, yystack.l_mark[0].tree ,0 ,0);}
break;
case 35:
#line 105 "parser.y"
	{yyval.tree = tree_create(TREE_SYMBOL,0,yystack.l_mark[-2].tree, yystack.l_mark[0].tree ,0 ,0);}
break;
case 36:
#line 106 "parser.y"
	{yyval.tree = tree_create(TREE_SYMBOL, 0,yystack.l_mark[-2].tree, yystack.l_mark[0].tree ,0 ,0);}
break;
case 37:
#line 107 "parser.y"
	{yyval.tree = yystack.l_mark[-1].tree;}
break;
#line 746 "y.tab.c"
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
