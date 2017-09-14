
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
