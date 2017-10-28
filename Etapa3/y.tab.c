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
    0,   17,   17,   15,   15,   15,    2,    2,    2,    2,
    2,    2,    2,    2,    2,    3,    3,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    6,    4,    4,
    5,    5,    7,    7,    7,   10,   10,    8,    8,    8,
    8,    8,    9,    9,   14,   14,   16,   16,   11,   12,
   13,   13,
};
static const YYINT yylen[] = {                            2,
    1,    2,    0,    6,    8,    8,    3,    6,    7,    5,
    2,    3,    2,    1,    0,    2,    0,    1,    4,    4,
    1,    1,    1,    3,    3,    3,    3,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    3,    2,    1,    1,
    3,    0,    1,    1,    1,    2,    0,    1,    1,    1,
    1,    1,    2,    0,    3,    1,    3,    0,    3,    2,
    3,    0,
};
static const YYINT yydefred[] = {                         0,
    0,    0,    0,    0,    1,    0,   48,   49,   50,   51,
   52,    0,    2,    0,    0,    0,    0,    0,   43,   44,
   45,    0,    0,    0,    4,    0,    0,   21,   22,   23,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   53,   46,    5,   55,
    0,    0,   37,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   26,   27,    0,    6,    0,   19,
   20,    0,    0,    0,    0,    0,    0,    0,   14,    0,
   57,    0,    0,    0,    0,   39,    0,    0,   11,    0,
    0,    0,   60,   59,    0,    0,   12,    0,   38,    0,
    0,    0,    0,    0,    0,    0,   61,    0,   10,   41,
    0,    0,    0,    0,    9,   16,
};
static const YYINT yydgoto[] = {                          3,
   32,   88,  125,   98,  109,   99,   35,   12,   33,   36,
   89,   90,  103,   34,    4,   57,    5,
};
static const YYINT yysindex[] = {                        28,
  -41,  -42,    0,   28,    0,  -42,    0,    0,    0,    0,
    0,  -23,    0,  -54, -272, -157, -249,   12,    0,    0,
    0,   -4,  -30,   62,    0, -157,   58,    0,    0,    0,
   75,  423,   35,   36, -157,   20,  -42,   75,   62,  -37,
   24,   75,   75,   75,   75,   75,   75,   75,   75,   75,
   75,   75,   75,   75,  -36,   62,    0,    0,    0,    0,
  164,   49,    0,  127,  127,  127,  127,  127,  127,  127,
  127,  127,  -27,  -27,    0,    0,  -73,    0,   36,    0,
    0,   60,   63,   51,   75,    4,   32,   65,    0,  -14,
    0,   75,   75, -151,  423,    0,  423,   84,    0,   75,
   75,  -73,    0,    0,  187,  383,    0,    4,    0,  423,
  407,   65, -129,  -73,   84,   76,    0,  -73,    0,    0,
   75, -128,  423,  -73,    0,    0,
};
static const YYINT yyrindex[] = {                       138,
    0,    0,    0,  138,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  100,    0,   87,  -11,    0,    0,    0,
    0,  -39,    0,  107,   87,    0,    0,    0,  100,  -33,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   15,   37,   50,   73,   85,   98,  120,
  140,  272,  -20,    2,    0,    0,  -53,    0,  107,    0,
    0,    0,    0,    0,    0,    0,    0,   25,    0,    0,
    0,    0,    0,    0,  -21,    0,  -43,  -18,    0,    0,
    0,  -53,    0,    0,    0,    0,    0,    0,    0,   -6,
    0,   25,    0,   29,  -18,    0,    0,   29,    0,    0,
    0,  -40,   42,   29,    0,    0,
};
static const YYINT yygindex[] = {                         0,
  463,   69,    0,   43,   40,    0,  136,   52,  117,  124,
  108,    0,   53,  112,    0,   97,  173,
};
#define YYTABLESIZE 698
static const YYINT yytable[] = {                         18,
   40,   56,   39,   18,   56,   15,   16,   18,   18,   18,
   18,   18,   24,   18,   53,   40,    6,   15,   17,   54,
   24,   18,   24,   24,   24,   18,   18,   23,   18,   18,
   18,   18,   18,   18,   25,   18,   17,   13,   24,   24,
   42,   24,   25,   31,   25,   25,   25,   31,   18,   77,
   18,   24,    7,   38,   25,   31,   50,   14,   31,   18,
   25,   25,   26,   25,   63,   53,   51,    2,   52,   32,
   54,   15,   24,   31,   31,   55,   31,   32,   59,   56,
   32,   40,   33,   48,   17,   49,   77,   15,   60,   81,
   33,   18,  100,   33,   25,   32,   32,   39,   32,   92,
    8,   31,   93,   13,   24,   34,   42,   31,   33,   33,
  104,   33,   94,   34,   31,   37,   34,   35,    7,   19,
   20,   21,  101,  102,  107,   35,   25,  108,   35,   32,
   36,   34,   34,  118,   34,  124,  121,    3,   36,   31,
   54,   36,   33,   35,   35,   47,   35,   58,   38,   62,
  115,   22,   28,   15,  120,   62,   36,   36,   58,   36,
   28,   32,   78,   28,  117,   34,    8,   79,   53,   51,
  112,   52,   29,   54,   33,   91,   13,   35,   28,   28,
   29,   28,  119,   29,    0,    0,  122,    0,   82,    0,
   36,   83,  126,   84,   85,   86,   50,   34,   29,   29,
    0,   29,   87,    0,    0,   53,   51,    0,   52,   35,
   54,    0,   28,    0,    7,    8,    9,   10,   11,   50,
   40,    0,   36,   48,    0,   49,    0,  113,   53,   51,
   18,   52,   29,   54,    0,    0,   18,   18,   18,   18,
   18,   18,   13,   24,   28,   42,   48,    0,   49,   24,
   24,   24,   24,   24,   24,    0,   80,    7,   18,   18,
   18,   18,   18,   18,   29,   25,    0,    0,    0,    0,
    0,   25,   25,   25,   25,   25,   25,    0,   31,   40,
   28,   29,   30,   96,   31,   31,   31,   31,   31,   31,
    0,    0,   15,   42,   43,   44,   45,   46,   47,    0,
   32,    0,    0,    1,   30,    8,   32,   32,   32,   32,
   32,   32,   30,   33,    0,   30,    0,    0,    0,   33,
   33,   33,   33,   33,   33,    0,    0,    0,    0,    0,
   30,   30,    0,   30,    0,    0,   34,   27,   28,   29,
   30,    0,   34,   34,   34,   34,   34,   34,   35,    0,
   40,   28,   29,   30,   35,   35,   35,   35,   35,   35,
    0,   36,    0,    0,   30,    0,    0,   36,   36,   36,
   36,   36,   36,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   28,    0,    0,    0,    0,    0,   28,
   28,   28,   28,   28,   28,    0,   30,    0,    0,    0,
    0,    0,    0,   29,    0,    0,    0,    0,    0,   29,
   29,   29,   29,   29,   29,   50,    0,    0,    0,    0,
    0,    0,    0,  114,   53,   51,    0,   52,    0,   54,
    0,    0,    0,   42,   43,   44,   45,   46,   47,   50,
    0,    0,   48,    0,   49,    0,    0,    0,   53,   51,
    0,   52,    0,   54,    0,   50,   42,   43,   44,   45,
   46,   47,    0,    0,   53,   51,   48,   52,   49,   54,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   48,    0,   49,    0,    0,    0,    0,    0,
    0,    0,    0,   41,    0,    0,    0,    0,    0,  116,
   61,    0,    0,    0,   64,   65,   66,   67,   68,   69,
   70,   71,   72,   73,   74,   75,   76,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   30,    0,    0,    0,    0,
    0,   30,   30,   30,   30,   30,   30,   95,   97,    0,
    0,    0,    0,    0,  105,  106,    0,    0,    0,    0,
    0,    0,  110,  111,    0,    0,    0,    0,    0,    0,
   97,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  123,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   42,   43,   44,   45,   46,   47,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   42,   43,   44,   45,
   46,   47,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   42,   43,   44,   45,   46,   47,
};
static const YYINT yycheck[] = {                         33,
   44,   41,   40,  276,   44,   59,   61,   41,   42,   43,
   44,   45,   33,   47,   42,   59,   58,   41,   59,   47,
   41,   33,   43,   44,   45,   59,   60,  277,   62,   41,
   42,   43,   44,   45,   33,   47,   91,   59,   59,   60,
   59,   62,   41,   40,   43,   44,   45,   33,   60,  123,
   62,   40,   59,   91,   59,   41,   33,    6,   44,   93,
   59,   60,   93,   62,   41,   42,   43,   40,   45,   33,
   47,  125,   93,   59,   60,   41,   62,   41,   59,   44,
   44,  125,   33,   60,  125,   62,  123,   59,   37,   41,
   41,  125,   61,   44,   93,   59,   60,   40,   62,   40,
   59,   40,   40,  125,  125,   33,  125,   93,   59,   60,
  125,   62,   62,   41,   40,   58,   44,   33,  125,  277,
  278,  279,   91,   59,  276,   41,  125,   44,   44,   93,
   33,   59,   60,  263,   62,  264,   61,    0,   41,  125,
   41,   44,   93,   59,   60,   59,   62,   41,   91,  125,
  108,   16,   33,  125,  115,   39,   59,   60,   35,   62,
   41,  125,   55,   44,  112,   93,  125,   56,   42,   43,
  102,   45,   33,   47,  125,   79,    4,   93,   59,   60,
   41,   62,  114,   44,   -1,   -1,  118,   -1,  262,   -1,
   93,  265,  124,  267,  268,  269,   33,  125,   59,   60,
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
   -1,   -1,   -1,   31,   -1,   -1,   -1,   -1,   -1,   93,
   38,   -1,   -1,   -1,   42,   43,   44,   45,   46,   47,
   48,   49,   50,   51,   52,   53,   54,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  264,   -1,   -1,   -1,   -1,
   -1,  270,  271,  272,  273,  274,  275,   85,   86,   -1,
   -1,   -1,   -1,   -1,   92,   93,   -1,   -1,   -1,   -1,
   -1,   -1,  100,  101,   -1,   -1,   -1,   -1,   -1,   -1,
  108,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  121,   -1,   -1,   -1,   -1,   -1,   -1,
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
#define YYUNDFTOKEN 301
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
"LIT_CHAR","LIT_STRING","TOKEN_ERROR",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
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
"vectorInit : initialValueTypes vectorInit",
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
#line 178 "parser.y"

	int yyerror(char *message)
	{
		fprintf(stderr, "Erro -> %s na linha %d\n",message,getLineNumber());
		exit(3);
	}
#line 450 "y.tab.c"

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
case 2:
#line 68 "parser.y"
	{tree_print(yystack.l_mark[-1].tree, 0);}
break;
case 4:
#line 72 "parser.y"
	{yyval.tree = tree_create(TREE_DECLARATION_SCALAR, yystack.l_mark[-5].symbol,yystack.l_mark[-3].tree, yystack.l_mark[-1].tree ,0 ,0);}
break;
case 5:
#line 73 "parser.y"
	{yyval.tree = tree_create(TREE_DECLARATION_VECTOR, yystack.l_mark[-7].symbol,yystack.l_mark[-5].tree, yystack.l_mark[-1].tree ,0 ,0);}
break;
case 6:
#line 74 "parser.y"
	{yyval.tree = tree_create(TREE_FUNCTION, yystack.l_mark[-4].symbol,yystack.l_mark[-6].tree, yystack.l_mark[-2].tree ,yystack.l_mark[0].tree ,0);}
break;
case 7:
#line 79 "parser.y"
	{yyval.tree = tree_create(TREE_ASSIGN, yystack.l_mark[-2].symbol, yystack.l_mark[0].tree ,0 ,0 ,0);}
break;
case 8:
#line 80 "parser.y"
	{yyval.tree = tree_create(TREE_ASSIGN_VECTOR, yystack.l_mark[-5].symbol, yystack.l_mark[-3].tree ,yystack.l_mark[0].tree ,0 ,0);}
break;
case 9:
#line 81 "parser.y"
	{yyval.tree = tree_create(TREE_IF, 0, yystack.l_mark[-4].tree ,yystack.l_mark[-1].tree ,yystack.l_mark[0].tree ,0);}
break;
case 10:
#line 82 "parser.y"
	{yyval.tree = tree_create(TREE_WHILE, 0, yystack.l_mark[-2].tree ,yystack.l_mark[0].tree ,0 ,0);}
break;
case 11:
#line 83 "parser.y"
	{yyval.tree = yystack.l_mark[0].tree;}
break;
case 12:
#line 84 "parser.y"
	{yyval.tree = tree_create(TREE_READ, yystack.l_mark[0].symbol, 0 ,0 ,0 ,0);}
break;
case 13:
#line 85 "parser.y"
	{yyval.tree = tree_create(TREE_RETURN, 0, yystack.l_mark[0].tree ,0 ,0 ,0);}
break;
case 14:
#line 86 "parser.y"
	{yyval.tree = yystack.l_mark[0].tree;}
break;
case 15:
#line 87 "parser.y"
	{yyval.tree = 0;}
break;
case 16:
#line 91 "parser.y"
	{yyval.tree = tree_create(TREE_ELSE, 0, yystack.l_mark[0].tree ,0 ,0 ,0);}
break;
case 17:
#line 92 "parser.y"
	{yyval.tree = 0;}
break;
case 18:
#line 98 "parser.y"
	{yyval.tree = tree_create(TREE_SYMBOL, yystack.l_mark[0].symbol, 0 ,0 ,0 ,0);}
break;
case 19:
#line 99 "parser.y"
	{yyval.tree = tree_create(TREE_SYMBOL, yystack.l_mark[-3].symbol, yystack.l_mark[-1].tree ,0 ,0 ,0);}
break;
case 20:
#line 100 "parser.y"
	{yyval.tree = tree_create(TREE_FUNCTION_CALL, yystack.l_mark[-3].symbol, yystack.l_mark[-1].tree ,0, 0,0);}
break;
case 21:
#line 101 "parser.y"
	{yyval.tree = tree_create(TREE_SYMBOL, yystack.l_mark[0].symbol, 0 ,0 ,0 ,0);}
break;
case 22:
#line 102 "parser.y"
	{yyval.tree = tree_create(TREE_SYMBOL, yystack.l_mark[0].symbol, 0 ,0 ,0 ,0);}
break;
case 23:
#line 103 "parser.y"
	{yyval.tree = tree_create(TREE_SYMBOL, yystack.l_mark[0].symbol, 0 ,0 ,0 ,0);}
break;
case 24:
#line 104 "parser.y"
	{yyval.tree = tree_create(TREE_ADD, 0,yystack.l_mark[-2].tree, yystack.l_mark[0].tree ,0 ,0);}
break;
case 25:
#line 105 "parser.y"
	{yyval.tree = tree_create(TREE_SUB, 0,yystack.l_mark[-2].tree, yystack.l_mark[0].tree ,0 ,0);}
break;
case 26:
#line 106 "parser.y"
	{yyval.tree = tree_create(TREE_MUL, 0,yystack.l_mark[-2].tree, yystack.l_mark[0].tree ,0 ,0);}
break;
case 27:
#line 107 "parser.y"
	{yyval.tree = tree_create(TREE_DIV, 0,yystack.l_mark[-2].tree, yystack.l_mark[0].tree ,0 ,0);}
break;
case 28:
#line 108 "parser.y"
	{yyval.tree = tree_create(TREE_LESS, 0,yystack.l_mark[-2].tree, yystack.l_mark[0].tree ,0 ,0);}
break;
case 29:
#line 109 "parser.y"
	{yyval.tree = tree_create(TREE_GREATER, 0,yystack.l_mark[-2].tree, yystack.l_mark[0].tree ,0 ,0);}
break;
case 30:
#line 110 "parser.y"
	{yyval.tree = tree_create(TREE_NOT, 0,yystack.l_mark[-2].tree, yystack.l_mark[0].tree ,0 ,0);}
break;
case 31:
#line 111 "parser.y"
	{yyval.tree = tree_create(TREE_LE,0, yystack.l_mark[-2].tree, yystack.l_mark[0].tree ,0 ,0 );}
break;
case 32:
#line 112 "parser.y"
	{yyval.tree = tree_create(TREE_GE, 0,yystack.l_mark[-2].tree, yystack.l_mark[0].tree ,0 ,0);}
break;
case 33:
#line 113 "parser.y"
	{yyval.tree = tree_create(TREE_EQ, 0,yystack.l_mark[-2].tree, yystack.l_mark[0].tree ,0 ,0);}
break;
case 34:
#line 114 "parser.y"
	{yyval.tree = tree_create(TREE_NE,0, yystack.l_mark[-2].tree, yystack.l_mark[0].tree ,0 ,0);}
break;
case 35:
#line 115 "parser.y"
	{yyval.tree = tree_create(TREE_AND,0,yystack.l_mark[-2].tree, yystack.l_mark[0].tree ,0 ,0);}
break;
case 36:
#line 116 "parser.y"
	{yyval.tree = tree_create(TREE_OR, 0,yystack.l_mark[-2].tree, yystack.l_mark[0].tree ,0 ,0);}
break;
case 37:
#line 117 "parser.y"
	{yyval.tree = yystack.l_mark[-1].tree;}
break;
case 38:
#line 121 "parser.y"
	{yyval.tree = tree_create(TREE_PRINT, 0, yystack.l_mark[-1].tree ,yystack.l_mark[0].tree ,0 ,0);}
break;
case 39:
#line 124 "parser.y"
	{yyval.tree = tree_create(TREE_SYMBOL, yystack.l_mark[0].symbol,0,0 ,0 ,0);}
break;
case 40:
#line 125 "parser.y"
	{yyval.tree = yystack.l_mark[0].tree;}
break;
case 41:
#line 128 "parser.y"
	{yyval.tree = tree_create(TREE_PRINT, 0, yystack.l_mark[-1].tree ,yystack.l_mark[0].tree ,0 ,0);}
break;
case 42:
#line 129 "parser.y"
	{yyval.tree = 0;}
break;
case 43:
#line 132 "parser.y"
	{yyval.tree = tree_create(TREE_SYMBOL, yystack.l_mark[0].symbol,0,0 ,0 ,0);}
break;
case 44:
#line 133 "parser.y"
	{yyval.tree = tree_create(TREE_SYMBOL, yystack.l_mark[0].symbol,0,0 ,0 ,0);}
break;
case 45:
#line 134 "parser.y"
	{yyval.tree = tree_create(TREE_SYMBOL, yystack.l_mark[0].symbol,0,0 ,0 ,0);}
break;
case 46:
#line 137 "parser.y"
	{yyval.tree = tree_create(TREE_VECTOR_VALUES, 0, yystack.l_mark[-1].tree ,yystack.l_mark[0].tree ,0 ,0);}
break;
case 47:
#line 138 "parser.y"
	{yyval.tree = 0;}
break;
case 48:
#line 143 "parser.y"
	{yyval.tree = tree_create(TREE_KW_BYTE, 0,0,0 ,0 ,0);}
break;
case 49:
#line 144 "parser.y"
	{yyval.tree = tree_create(TREE_KW_SHORT, 0,0,0 ,0 ,0);}
break;
case 50:
#line 145 "parser.y"
	{yyval.tree = tree_create(TREE_KW_LONG, 0,0,0 ,0 ,0);}
break;
case 51:
#line 146 "parser.y"
	{yyval.tree = tree_create(TREE_KW_FLOAT, 0,0,0 ,0 ,0);}
break;
case 52:
#line 147 "parser.y"
	{yyval.tree = tree_create(TREE_KW_DOUBLE, 0,0,0 ,0 ,0);}
break;
case 53:
#line 151 "parser.y"
	{yyval.tree = tree_create(TREE_PARAMS, 0,yystack.l_mark[-1].tree, yystack.l_mark[0].tree ,0 ,0);}
break;
case 54:
#line 151 "parser.y"
	{yyval.tree = 0;}
break;
case 55:
#line 157 "parser.y"
	{yyval.tree = tree_create(TREE_PARAM, yystack.l_mark[-2].symbol,yystack.l_mark[0].tree,0 ,0 ,0);}
break;
case 56:
#line 158 "parser.y"
	{yyval.tree = yystack.l_mark[0].tree;}
break;
case 57:
#line 161 "parser.y"
	{yyval.tree = yystack.l_mark[-1].tree;}
break;
case 58:
#line 162 "parser.y"
	{yyval.tree = 0;}
break;
case 59:
#line 167 "parser.y"
	{yyval.tree = yystack.l_mark[-1].tree; }
break;
case 60:
#line 170 "parser.y"
	{yyval.tree = tree_create(TREE_CMD_BLOCK, 0,yystack.l_mark[-1].tree, yystack.l_mark[0].tree ,0 ,0);}
break;
case 61:
#line 173 "parser.y"
	{yyval.tree = tree_create(TREE_CMD_LIST, 0,yystack.l_mark[-1].tree, yystack.l_mark[0].tree ,0 ,0);}
break;
case 62:
#line 174 "parser.y"
	{yyval.tree = 0;}
break;
#line 892 "y.tab.c"
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
