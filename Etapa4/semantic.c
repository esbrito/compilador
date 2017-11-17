#include "semantic.h"
#include "hash.h"
#include "tree.h"
#include "y.tab.h"

void semanticSetTypes(TREE *node) {
    int i;

    if (!node) return;

    if (node->type == TREE_DECLARATION_SCALAR)
    {
        if (node->symbol->type != TK_IDENTIFIER)
        {
            fprintf(stderr, "Semantic ERROR: identifier %s already declared\n", node->symbol->text);
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
            fprintf(stderr, "Semantic ERROR: identifier %s already declared\n", node->symbol->text);
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
            fprintf(stderr, "Semantic ERROR: identifier %s already declared\n", node->symbol->text);
            found_semantic_err = 1; //set flag semantic err
        }
        else
        {
            node->symbol->type = SYMBOL_FUN;
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


void semanticCheckUndeclared() {
    hashCheckUndeclared();
}


void semanticCheckUsage();
