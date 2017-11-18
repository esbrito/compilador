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

#endif /* semantic_h */
