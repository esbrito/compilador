#ifndef semantic_h
#define semantic_h

#include <stdio.h>
#include "hash.h"
#include "tree.h"

void semanticSetTypes(TREE *node);
void semanticCheckUndeclared();
void semanticCheckUsage(TREE *node);
void semanticCheckOperands(TREE *node);

/* AUXILIAR FUNC */
int isConditional(int type);
int isArithmetic(int type);
int isLogic(int type);
int countSons(TREE *node);

/* FUNCTION ARGS LINKED LIST */
struct fun_node {
    char *text;
    int args;
    struct fun_node *next;
};

struct fun_node* funlist_insert(char *text, int args, struct fun_node *list);
struct fun_node* funlist_find(char *text, struct fun_node *list);

#endif /* semantic_h */
