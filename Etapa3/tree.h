#include "hash.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX_SONS 4
#define TREE_SYMBOL 1
#define TREE_ADD 2
#define TREE_MUL 3

typedef struct tree_node
{
    int type;
    HASH_NODE *symbol;
    struct tree_node *son[MAX_SONS];
} TREE;

TREE *tree_create(int type, HASH_NODE *symbol, TREE *s0, TREE *s1, TREE *s2, TREE *s3);
void tree_print(TREE *node);