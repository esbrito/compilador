#ifndef semantic_h
#define semantic_h

#include <stdio.h>
#include "hash.h"
#include "tree.h"

void semanticSetTypes(TREE *node);
void semanticCheckUndeclared();
void semanticCheckUsage();
void semanticCheckOperands();

#endif /* semantic_h */
