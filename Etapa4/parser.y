%{
	#include <stdlib.h>
	#include <stdio.h>
	#include <string.h>
	#include "tree.h"
	#include "semantic.h"
    int yylex();
	int yyerror(char *message);
	int getLineNumber();

	TREE* ast_tree;

	%}

	%union {
		TREE* tree;
		HASH_NODE *symbol;
	}

	%token KW_BYTE
	%token KW_SHORT
	%token KW_LONG
	%token KW_FLOAT
	%token KW_DOUBLE
	%token KW_IF
	%token KW_THEN
	%token KW_ELSE
	%token KW_WHILE
	%token KW_FOR
	%token KW_READ
	%token KW_RETURN
	%token KW_PRINT
	%token OPERATOR_LE
	%token OPERATOR_GE
	%token OPERATOR_EQ
	%token OPERATOR_NE
	%token OPERATOR_AND
	%token OPERATOR_OR
	%token<symbol> TK_IDENTIFIER
	%token<symbol> LIT_INTEGER
	%token<symbol> LIT_REAL
	%token<symbol> LIT_CHAR
	%token<symbol> LIT_STRING
	%token TOKEN_ERROR

	%type<tree> exp
	%type<tree> cmd
	%type<tree> else
	%type<tree> elem
	%type<tree> restoElem
	%type<tree> printables
	%type<tree> initialValueTypes
	%type<tree> types
	%type<tree> params
	%type<tree> vectorInit
	%type<tree> block
	%type<tree> cmdblock
	%type<tree> restoCmd
	%type<tree> param
	%type<tree> declarations
	%type<tree> restoParam
	%type<tree> declarationsList
	%type<tree> initialValueTypesVector





	%left '<' '>'  '!' OPERATOR_LE  OPERATOR_GE OPERATOR_EQ OPERATOR_NE OPERATOR_AND OPERATOR_OR
	%left '+' '-'
	%left '*' '/'

	%%
	program: declarationsList 
    {
        ast_tree = tree_create(TREE_PROGRAM, 0, $1 ,0 ,0,0);tree_print($1, 0);
        semanticSetTypes($1);
        semanticCheckUndeclared();
        semanticCheckUsage($1);
        semanticCheckOperands($1);
    }
	;

	declarationsList: declarations declarationsList {$$ = tree_create(DECLARATIONS, 0, $1 ,$2 ,0, 0);$$->line = getLineNumber();}|
	 {$$ = 0;}
	;

	declarations:
	TK_IDENTIFIER  ':' types '=' initialValueTypes ';'  {$$ = tree_create(TREE_DECLARATION_SCALAR, $1,$3, $5 ,0 ,0);$$->line = getLineNumber();} |
	TK_IDENTIFIER  ':' types '[' LIT_INTEGER ']' vectorInit   ';' {$$ = tree_create(TREE_DECLARATION_VECTOR,$1,$3, tree_create(TREE_DECLARATION_VECTOR_NUMBER,$5,0,0,0,0),$7, 0);$$->line = getLineNumber();}|
	'(' types ')' TK_IDENTIFIER '(' params ')' block  {$$ = tree_create(TREE_FUNCTION, $4,$2, $6 ,$8 ,0);$$->line = getLineNumber();}
	;


	cmd:
	TK_IDENTIFIER '=' exp {$$ = tree_create(TREE_ASSIGN, $1, $3 ,0 ,0 ,0); $$->line = getLineNumber();$$->line = getLineNumber();}|
	TK_IDENTIFIER '[' exp ']' '=' exp {$$ = tree_create(TREE_ASSIGN_VECTOR, $1, tree_create(TREE_VECTOR_VALUES_POSITION, 0, $3 ,0 ,0 ,0) ,$6 ,0 ,0);$$->line = getLineNumber();}|
	KW_IF '(' exp ')' KW_THEN cmd else {$$ = tree_create(TREE_IF, 0, $3 ,$6 ,$7 ,0);$$->line = getLineNumber();}|
	KW_WHILE '(' exp ')' cmd {$$ = tree_create(TREE_WHILE, 0, $3 ,$5 ,0 ,0);$$->line = getLineNumber();}|
	KW_PRINT printables {$$ = tree_create(TREE_PRINT, 0, $2 ,0 ,0 ,0);$$->line = getLineNumber();}|
	KW_READ '>' TK_IDENTIFIER {$$ = tree_create(TREE_READ, $3, 0 ,0 ,0 ,0);$$->line = getLineNumber();}|
	KW_RETURN exp {$$ = tree_create(TREE_RETURN, 0, $2 ,0 ,0 ,0);$$->line = getLineNumber();}| 
	block {$$ = $1;}|
	{$$ = 0;}
	;

	// else
	else: KW_ELSE cmd {$$ = tree_create(TREE_ELSE, 0, $2 ,0 ,0 ,0);$$->line = getLineNumber();}| 
	{$$ = 0;}
	;


	// Declaracao de expressoes
	exp:
	TK_IDENTIFIER {$$ = tree_create(TREE_SYMBOL, $1, 0 ,0 ,0 ,0);$$->line = getLineNumber();}|
	TK_IDENTIFIER '[' exp ']' {$$ = tree_create(TREE_VECTOR, $1, $3 ,0 ,0 ,0);$$->line = getLineNumber();}|
	TK_IDENTIFIER '(' params ')' {$$ = tree_create(TREE_FUNCTION_CALL, $1, $3 ,0, 0,0);$$->line = getLineNumber();}|
	LIT_INTEGER {$$ = tree_create(TREE_SYMBOL, $1, 0 ,0 ,0 ,0);$$->line = getLineNumber();}|
	LIT_REAL {$$ = tree_create(TREE_SYMBOL, $1, 0 ,0 ,0 ,0);$$->line = getLineNumber();}|
	LIT_CHAR {$$ = tree_create(TREE_SYMBOL, $1, 0 ,0 ,0 ,0);$$->line = getLineNumber();}|
	exp '+' exp {$$ = tree_create(TREE_ADD, 0,$1, $3 ,0 ,0);$$->line = getLineNumber();}|
	exp '-' exp {$$ = tree_create(TREE_SUB, 0,$1, $3 ,0 ,0);$$->line = getLineNumber();}|
	exp '*' exp {$$ = tree_create(TREE_MUL, 0,$1, $3 ,0 ,0);$$->line = getLineNumber();}|
	exp '/' exp {$$ = tree_create(TREE_DIV, 0,$1, $3 ,0 ,0);$$->line = getLineNumber();}|
	exp '<' exp {$$ = tree_create(TREE_LESS, 0,$1, $3 ,0 ,0);$$->line = getLineNumber();}|
	exp '>' exp {$$ = tree_create(TREE_GREATER, 0,$1, $3 ,0 ,0);$$->line = getLineNumber();}|
	exp '!' exp {$$ = tree_create(TREE_NOT, 0,$1, $3 ,0 ,0);$$->line = getLineNumber();}|
	exp OPERATOR_LE exp {$$ = tree_create(TREE_LE,0, $1, $3 ,0 ,0 );$$->line = getLineNumber();}|
	exp OPERATOR_GE exp {$$ = tree_create(TREE_GE, 0,$1, $3 ,0 ,0);$$->line = getLineNumber();}|
	exp OPERATOR_EQ exp {$$ = tree_create(TREE_EQ, 0,$1, $3 ,0 ,0);$$->line = getLineNumber();}|
	exp OPERATOR_NE exp {$$ = tree_create(TREE_NE,0, $1, $3 ,0 ,0);$$->line = getLineNumber();}|
	exp OPERATOR_AND exp {$$ = tree_create(TREE_AND,0,$1, $3 ,0 ,0);$$->line = getLineNumber();}|
	exp OPERATOR_OR exp {$$ = tree_create(TREE_OR, 0,$1, $3 ,0 ,0);$$->line = getLineNumber();}|
	'(' exp ')' {$$ = tree_create(TREE_PAR, 0, $2, 0,0,0);$$->line = getLineNumber();}
	;

	// Lista de elementos do print
	printables: elem restoElem {$$ = tree_create(TREE_PRINTABLE, 0, $1 ,$2 ,0 ,0);$$->line = getLineNumber();}
	;

	elem: LIT_STRING {$$ = tree_create(TREE_SYMBOL, $1,0,0 ,0 ,0);$$->line = getLineNumber();}| 
	exp {$$ = $1;}
	;

	restoElem: ',' elem restoElem {$$ = tree_create(TREE_PRINTABLE, 0, $2 ,$3 ,0 ,0);$$->line = getLineNumber();}| 
	{$$ = 0;}
	;

	initialValueTypes: LIT_INTEGER {$$ = tree_create(TREE_DECLARATION_SYMBOL, $1,0,0 ,0 ,0);$$->line = getLineNumber();}| 
	LIT_REAL {$$ = tree_create(TREE_DECLARATION_SYMBOL, $1,0,0 ,0 ,0);$$->line = getLineNumber();}| 
	LIT_CHAR {$$ = tree_create(TREE_DECLARATION_SYMBOL, $1,0,0 ,0 ,0);$$->line = getLineNumber();}
	;

	initialValueTypesVector: LIT_INTEGER {$$ = tree_create(TREE_DECLARATION_SYMBOL_VECTOR, $1,0,0 ,0 ,0);$$->line = getLineNumber();}| 
	LIT_REAL {$$ = tree_create(TREE_DECLARATION_SYMBOL_VECTOR, $1,0,0 ,0 ,0);$$->line = getLineNumber();}| 
	LIT_CHAR {$$ = tree_create(TREE_DECLARATION_SYMBOL_VECTOR, $1,0,0 ,0 ,0);$$->line = getLineNumber();}
	;


	vectorInit: initialValueTypesVector vectorInit {$$ = tree_create(TREE_VECTOR_VALUES, 0, $1 ,$2 ,0 ,0);$$->line = getLineNumber();}|
	{$$ = 0;} /*empty*/
	;

	
	types:
	KW_BYTE {$$ = tree_create(TREE_KW_BYTE, 0,0,0 ,0 ,0);$$->line = getLineNumber();}| 
	KW_SHORT {$$ = tree_create(TREE_KW_SHORT, 0,0,0 ,0 ,0);$$->line = getLineNumber();}| 
	KW_LONG {$$ = tree_create(TREE_KW_LONG, 0,0,0 ,0 ,0);$$->line = getLineNumber();}|
	KW_FLOAT {$$ = tree_create(TREE_KW_FLOAT, 0,0,0 ,0 ,0);$$->line = getLineNumber();}|
	KW_DOUBLE {$$ = tree_create(TREE_KW_DOUBLE, 0,0,0 ,0 ,0);$$->line = getLineNumber();}
	;

	// lista de parametros para declaracao
	params: param restoParam {$$ = tree_create(TREE_PARAMS, 0,$1, $2 ,0 ,0);$$->line = getLineNumber();}|
	{$$ = 0;}/*empty*/
	;

	// param pode receber tipo ou não, depende se for usado na declaracao ou chamada da
	// funcao. na chamada tbm recebe literais
	param:
	TK_IDENTIFIER ':' types {$$ = tree_create(TREE_PARAM, $1,$3,0 ,0 ,0);$$->line = getLineNumber();}|
	exp {$$ = $1;}
	;

	restoParam: ',' param restoParam {$$ = tree_create(TREE_PARAMS, 0,$2, $3 ,0 ,0);$$->line = getLineNumber();}| 
	{$$ = 0;}/*empty*/
	;

	// bloco de comandos
	block:
	'{' cmdblock '}' {$$ = $2; }
	;

	cmdblock: cmd restoCmd {$$ = tree_create(TREE_CMD_BLOCK, 0,$1, $2 ,0 ,0);$$->line = getLineNumber();}
	;

	restoCmd: ';' cmd restoCmd {$$ = tree_create(TREE_CMD_LIST, 0,$2, $3 ,0 ,0);$$->line = getLineNumber();}| 
	{$$ = 0;}
	;

	%%

	int yyerror(char *message)
	{
		fprintf(stderr, "Erro -> %s na linha %d\n",message,getLineNumber());
		exit(3);
	}
