#include "semantic.h"
#include "hash.h"
#include "tree.h"
#include "y.tab.h"
#include <string.h>

struct fun_node *list = 0;

void semanticSetTypes(TREE *node)
{
    int i;

    if (!node) return;

    if (node->type == TREE_DECLARATION_SCALAR)
    {
        if (node->symbol->type != TK_IDENTIFIER)
        {
            fprintf(stderr, "Semantic ERROR: identifier %s already declared. Line: %d \n", node->symbol->text, node->line);
            found_semantic_err = 1; //set flag semantic err
        }
        else
        {
            node->symbol->type = SYMBOL_VAR;
            if (node->son[0]->type == TREE_KW_BYTE) { node->symbol->datatype = DATATYPE_BYTE; }
            if (node->son[0]->type == TREE_KW_SHORT) { node->symbol->datatype = DATATYPE_SHORT; }
            if (node->son[0]->type == TREE_KW_LONG) { node->symbol->datatype = DATATYPE_LONG; }
            if (node->son[0]->type == TREE_KW_FLOAT) { node->symbol->datatype = DATATYPE_FLOAT; }
            if (node->son[0]->type == TREE_KW_DOUBLE) { node->symbol->datatype = DATATYPE_DOUBLE; }
        }
    }

    if (node->type == TREE_DECLARATION_VECTOR)
    {
        if (node->symbol->type != TK_IDENTIFIER)
        {
            fprintf(stderr, "Semantic ERROR: identifier %s already declared. Line: %d \n", node->symbol->text, node->line);
            found_semantic_err = 1; //set flag semantic err
        }
        else
        {
            node->symbol->type = SYMBOL_VEC;
            if (node->son[0]->type == TREE_KW_BYTE) { node->symbol->datatype = DATATYPE_BYTE; }
            if (node->son[0]->type == TREE_KW_SHORT) { node->symbol->datatype = DATATYPE_SHORT; }
            if (node->son[0]->type == TREE_KW_LONG) { node->symbol->datatype = DATATYPE_LONG; }
            if (node->son[0]->type == TREE_KW_FLOAT) { node->symbol->datatype = DATATYPE_FLOAT; }
            if (node->son[0]->type == TREE_KW_DOUBLE) { node->symbol->datatype = DATATYPE_DOUBLE; }
        }
    }

    if (node->type == TREE_FUNCTION)
    {
        if (node->symbol->type != TK_IDENTIFIER)
        {
            fprintf(stderr, "Semantic ERROR: identifier %s already declared. Line: %d \n", node->symbol->text, node->line);
            found_semantic_err = 1; //set flag semantic err
        }
        else
        {
            node->symbol->type = SYMBOL_FUN;
            node->functionArgs = countSons(node->son[1]); //needed to check with function call later
            list = funlist_insert(node->symbol->text, node->functionArgs, list); //insert declaration on list
            if (node->son[0]->type == TREE_KW_BYTE) { node->symbol->datatype = DATATYPE_BYTE; }
            if (node->son[0]->type == TREE_KW_SHORT) { node->symbol->datatype = DATATYPE_SHORT; }
            if (node->son[0]->type == TREE_KW_LONG) { node->symbol->datatype = DATATYPE_LONG; }
            if (node->son[0]->type == TREE_KW_FLOAT) { node->symbol->datatype = DATATYPE_FLOAT; }
            if (node->son[0]->type == TREE_KW_DOUBLE) { node->symbol->datatype = DATATYPE_DOUBLE; }
        }
    }

    //recursion on the entire tree
    for (i=0; i<MAX_SONS; ++i)
        semanticSetTypes(node->son[i]);
}


void semanticCheckUndeclared() 
{
    hashCheckUndeclared();
}


void semanticCheckUsage(TREE *node)
{
    int i;

    if (!node) return;

    // check assignment left-hand side 
    if (node->type == TREE_ASSIGN)
    {
        if (node->symbol->type != SYMBOL_VAR)
        {
            fprintf(stderr, "Semantic ERROR: identifier %s must be a scalar. Line %d \n", node->symbol->text, node->line);
            found_semantic_err = 1;
        }
    }
    
     // check assignment left-hand side 
    if (node->type == TREE_ASSIGN_VECTOR)
    {
        if (node->symbol->type != SYMBOL_VEC)
        {
            fprintf(stderr, "Semantic ERROR: identifier %s must be a vector. Line %d \n", node->symbol->text, node->line);
            found_semantic_err = 1;
        }
    }

    /* POSSIVELMENTE ERRADO - o lado direito nao necesseriamente sera uma variavel, pode
     * ser variavel, posicao de vetor, chamada de funcao, etc
     **/
    // check assignement right-hand side
    if (node->type == TREE_SYMBOL)
    {
        if (node->symbol->type != SYMBOL_VAR && node->symbol->type != TREE_VECTOR && node->symbol->type != TREE_FUNCTION_CALL && node->symbol->type != LIT_REAL && node->symbol->type != LIT_CHAR && node->symbol->type != LIT_INTEGER)
        {
            fprintf(stderr, "Semantic ERROR: identifier %s must be a scalar. Line %d\n", node->symbol->text, node->line);
            found_semantic_err = 1;
        }
    }

    if (node->type == TREE_FUNCTION_CALL)
    {
        if (node->symbol->type != SYMBOL_FUN)
        {
            fprintf(stderr, "Semantic ERROR: identifier %s must be a function. Line %d\n", node->symbol->text, node->line);
            found_semantic_err = 1;
        }
    }
    
    if (node->type == TREE_VECTOR)
    {
        if (node->symbol->type != SYMBOL_VEC)
        {
            fprintf(stderr, "Semantic ERROR: identifier %s must be a vector. Line %d\n", node->symbol->text, node->line);
            found_semantic_err = 1;
        }
    }
    
    // testa o condicional do if e do while
    if (node->type == TREE_IF || node->type == TREE_WHILE)
    {
        if ( !isConditional(node->son[0]->type) )
        {
            fprintf(stderr, "Semantic ERROR: testing expression must be a conditional. Line %d\n", node->line);
            found_semantic_err = 1;
        }
    }
    
    if (node->type == TREE_READ)
    {
        if (node->symbol->type != SYMBOL_VAR)
        {
            fprintf(stderr, "Semantic ERROR: identifier %s must be a scalar. Line %d\n", node->symbol->text, node->line);
            found_semantic_err = 1;
        }
    }

    // recursion on the rest of the tree
    for (i=0; i<MAX_SONS; ++i)
        semanticCheckUsage(node->son[i]);
}

void semanticCheckOperands(TREE *node)
{
    int i;

    if (!node) return;

    // check arithmetic operators 
    if ( isArithmetic(node->type) ) 
    {
        //check first operand
        if ( isConditional(node->son[0]->type) || isLogic(node->son[0]->type) ) 
        {
            fprintf(stderr, "Semantic ERROR: opreand cannot be a conditional or logic expression. Line %d\n", node->line);
            found_semantic_err = 1;
        }
        
        //check second operand
        if ( isConditional(node->son[1]->type) || isLogic(node->son[1]->type) ) 
        {
            fprintf(stderr, "Semantic ERROR: opreand cannot be a conditional or logic expression. Line %d\n", node->line);
            found_semantic_err = 1;
        }
    }
    
    // check number of parameters on function calls
    if (node->type == TREE_FUNCTION_CALL)
    {
        struct fun_node *decl = funlist_find(node->symbol->text, list);
        if (decl != 0) //fails if func was not declared
        {
            if (decl->args > countSons(node->son[0]))
            {
                fprintf(stderr, "Semantic ERROR: function call %s has too few args. Line %d\n", node->symbol->text, node->line);
                found_semantic_err = 1;
            }
            if (decl->args < countSons(node->son[0]))
            {
                fprintf(stderr, "Semantic ERROR: function call %s has too many args. Line %d\n", node->symbol->text, node->line);
                found_semantic_err = 1;
            }
        }
    }

    // check assign datatype consistency
    if (node->type == TREE_ASSIGN)
    {
        if (isDatatypeInt(node->symbol->datatype) && isFloat(node->son[0]))
        {
            fprintf(stderr, "Semantic ERROR: assigning non-integer value to a integer variable. Line %d\n", node->line);
            found_semantic_err = 1;
        }
        
        if (isDatatypeFloat(node->symbol->datatype) && isInteger(node->son[0]))
        {
            fprintf(stderr, "Semantic ERROR: assigning non-float value to a float variable. Line %d\n", node->line);
            found_semantic_err = 1;
        }
    }

    // recursion on the rest of the tree
    for (i=0; i<MAX_SONS; ++i)
        semanticCheckOperands(node->son[i]);
}

/* AUX FUNCTIONS */

int isDatatypeInt(int type)
{
    if (type==DATATYPE_BYTE||type==DATATYPE_SHORT||type==DATATYPE_LONG)
        return 1;
    return 0;
}

int isDatatypeFloat(int type)
{
    if (type==DATATYPE_FLOAT||type==DATATYPE_DOUBLE)
        return 1;
    return 0;
}

int isInteger(TREE *node)
{
    if (!node) return 0;
    
    // test for literals and variables
    if (node->type == TREE_SYMBOL)
    {
        if (isDatatypeInt(node->symbol->datatype))
            return 1;
    }

    // test for vector
    if (node->type == TREE_VECTOR)
    {
        if (isDatatypeInt(node->symbol->datatype))
            return 1;
    }

    // test for function calls
    if (node->type == TREE_FUNCTION_CALL)
    {
        if (isDatatypeInt(node->symbol->datatype))
            return 1;
    }

    // test for arithmetic operators
    if (isArithmetic(node->type))
    {
        int left, right;
        left = isInteger(node->son[0]);
        right = isInteger(node->son[1]);
        if (left && right) // both operands need to be int for the exp be int
            return 1;
    }

    // test for parenthesis
    if (node->type == TREE_PAR)
        isInteger(node->son[0]);

    return 0;
}

int isFloat(TREE *node)
{
    if (!node) return 0;
    
    // test for literals and variables
    if (node->type == TREE_SYMBOL)
    {
        if (isDatatypeFloat(node->symbol->datatype))
            return 1;
    }

    // test for vector
    if (node->type == TREE_VECTOR)
    {
        if (isDatatypeFloat(node->symbol->datatype))
            return 1;
    }

    // test for function calls
    if (node->type == TREE_FUNCTION_CALL)
    {
        if (isDatatypeFloat(node->symbol->datatype))
            return 1;
    }

    // test for arithmetic operators
    if (isArithmetic(node->type))
    {
        int left, right;
        left = isInteger(node->son[0]);
        right = isInteger(node->son[1]);
        if (left || right) // if only one operand is float, exp is float
            return 1;
    }
    
    // test for parenthesis
    if (node->type == TREE_PAR)
        isFloat(node->son[0]);

    return 0; 
}

int countSons(TREE *node)
{
    if (!node) return 0; // no args
    if (node->son[1] == 0)
        return 1;
    return 1 + countSons(node->son[1]);
}

int isConditional(int type)
{
    if (type==TREE_LESS||type==TREE_GREATER||type==TREE_EQ||type==TREE_NE||type==TREE_LE||type==TREE_GE)
        return 1;
    return 0;
}

int isLogic(int type)
{
    if (type==TREE_NOT||type==TREE_AND||type==TREE_OR)
        return 1;
    return 0;
}

int isArithmetic(int type)
{
    if (type==TREE_ADD||type==TREE_SUB||type==TREE_MUL||type==TREE_DIV)
        return 1;
    return 0;
}

/* END OF AUX FUNCTIONS */

/* FUNC LIST */

struct fun_node *funlist_insert(char *text, int args, struct fun_node *list)
{
    struct fun_node *new;
    new = (struct fun_node*)calloc(1, sizeof(struct fun_node));
    new->text = calloc(strlen(text)+1, sizeof(1));
    strcpy(new->text, text);
    new->args = args;
    new->next = list;
    
    return new;
}

struct fun_node *funlist_find(char *text, struct fun_node *list)
{
    struct fun_node *current = list;

    while (current)
    {
        if(!strcmp(current->text, text))
            return current;
        current = current->next;
    }
    return 0;
}

/* END OF FUNC LIST */
