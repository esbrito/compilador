
%{


#include <stdio.h>
#include "tokens.h"
#include "hash.h"

int getLineNumber(void);

int running = 1;
int token;
int line_number = 1;


%}


%%

"byte"						{return KW_BYTE;}
"short"						{return KW_SHORT;}						
"long"						{return KW_LONG;}
"float"						{return KW_FLOAT;}
"double"					{return KW_DOUBLE;}
"if"						{return KW_IF;}
"then"						{return KW_THEN;}
"else"						{return KW_ELSE;}
"while"						{return KW_WHILE;}
"for"						{return KW_FOR;}
"read"						{return KW_READ;}
"print"						{return KW_PRINT;}
"return"					{return KW_RETURN;}
"\n"						{line_number++;}
"<="						{return OPERATOR_LE;}
">="						{return OPERATOR_GE;}
"=="						{return OPERATOR_EQ;}
"!="						{return OPERATOR_NE;}
"&&"						{return OPERATOR_AND;}
"||"						{return OPERATOR_OR;}
[a-zA-Z_][a-zA-Z0-9_ ]+[a-zA-Z0-9_]*		{hash_insert(TK_IDENTIFIER, yytext); return TK_IDENTIFIER;}
[-,;:()\[\]{}+*/<>=!&$#]    {return (int)yytext[0];}
.							{return TOKEN_ERROR;}

%%

void initMe()
{

}

#include "main.c"

int yywrap()
{
	running = 0;
	return 1;
}



int getLineNumber()
{
	return line_number;
}
