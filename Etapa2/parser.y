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

	%%
	program: cmdl
	;

	cmdl: cmd  cmdl  | /*empty*/
	;

	cmd: TK_IDENTIFIER  ':' globalVars
	;

	//Declaração de variáveis globais
	globalVars:
	   KW_BYTE '=' initialValueTypes ';' | KW_BYTE '[' LIT_INTEGER ']' vectorInit ';'  |
	   KW_SHORT '=' initialValueTypes ';' |  KW_SHORT '[' LIT_INTEGER ']' vectorInit ';'  |
	   KW_LONG '=' initialValueTypes ';' |  KW_LONG '[' LIT_INTEGER ']' vectorInit ';'  |
	   KW_FLOAT '=' initialValueTypes ';' |  KW_FLOAT '[' LIT_INTEGER ']' vectorInit ';'  |
	   KW_DOUBLE '=' initialValueTypes ';' | KW_DOUBLE '[' LIT_INTEGER ']' vectorInit ';'
	;

	initialValueTypes: LIT_INTEGER | LIT_REAL| LIT_CHAR
	;


	vectorInit: initialValueTypes vectorInit | /*empty*/
	;

	%%

	int yyerror(char *message)
	{
		fprintf(stderr, "Erro -> %s na linha %d\n",message,getLineNumber());
		exit(3);
	}
