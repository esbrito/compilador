%{
	#include <stdlib.h>
	#include <stdio.h>
	#include <string.h>
	#include "hash.h"
	int yylex();
	int yyerror(char *message);
	int getLineNumber();
	%}



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
	%token TK_IDENTIFIER
	%token LIT_INTEGER
	%token LIT_REAL
	%token LIT_CHAR
	%token LIT_STRING
	%token TOKEN_ERROR

	%left '<' '>'  '!' OPERATOR_LE  OPERATOR_GE OPERATOR_EQ OPERATOR_NE OPERATOR_AND OPERATOR_OR
	%left '+' '-'
	%left '*' '/'

	%%
	program: declarationsList
	;

	declarationsList: declarations declarationsList |
	;

	declarations:
	TK_IDENTIFIER  ':' globalVars |
	'(' function
	;

	cmd:
	TK_IDENTIFIER atrib |
	KW_IF '(' exp ')' KW_THEN cmd else |
	KW_WHILE '(' exp ')' cmd |
	KW_PRINT printables |
	KW_READ '>' TK_IDENTIFIER |
	KW_RETURN exp | // falha na linha 35 do exemplo original por causa do return x
	block |
	;

	// else
	// falha na linha 27 do exemplo.lang original por causa do 'then else'
	else: KW_ELSE cmd | ;

	// Atribuicoes
	atrib:
	'=' exp | '[' exp ']' '=' exp
	;

	// Declaracao de expressoes
	exp:
	TK_IDENTIFIER |
	TK_IDENTIFIER '[' exp ']' |
	TK_IDENTIFIER '(' params ')' |
	LIT_INTEGER |
	LIT_REAL |
	LIT_CHAR |
	exp '+' exp |
	exp '-' exp |
	exp '*' exp |
	exp '/' exp |
	exp '<' exp |
	exp '>' exp |
	exp '!' exp |
	exp OPERATOR_LE exp |
	exp OPERATOR_GE exp |
	exp OPERATOR_EQ exp |
	exp OPERATOR_NE exp |
	exp OPERATOR_AND exp |
	exp OPERATOR_OR exp |
	'(' exp ')'
	;

	// Lista de elementos do print
	printables: elem restoElem
	;

	elem: LIT_STRING | exp
	;

	restoElem: ',' elem restoElem |
	;

	//Declaração de variáveis globais
	globalVars:
	scalarType ';' | vectorType ';'
	;

	scalarType:
	types '=' initialValueTypes
	;

	vectorType:
	types '[' LIT_INTEGER ']' vectorInit
	;

	initialValueTypes: LIT_INTEGER | LIT_REAL| LIT_CHAR
	;

	vectorInit: initialValueTypes vectorInit | /*empty*/
	;

	function:
	types ')' TK_IDENTIFIER '(' params ')' block
	;

	types:
	KW_BYTE | KW_SHORT | KW_LONG | KW_FLOAT | KW_DOUBLE
	;

	// lista de parametros para declaracao
	params: param restoParam | /*empty*/
	;

	// param pode receber tipo ou não, depende se for usado na declaracao ou chamada da
	// funcao. na chamada tbm recebe literais
	param:
	TK_IDENTIFIER ':' types |
	exp
	;

	restoParam: ',' param restoParam | /*empty*/
	;

	// bloco de comandos
	block:
	'{' cmdblock '}'
	;

	cmdblock: cmd restoCmd
	;

	restoCmd: ';' cmd restoCmd |
	;

	%%

	int yyerror(char *message)
	{
		fprintf(stderr, "Erro -> %s na linha %d\n",message,getLineNumber());
		exit(3);
	}
