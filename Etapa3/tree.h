#include "hash.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX_SONS 4
#define TREE_SYMBOL 1
#define TREE_ADD 2
#define TREE_SUB 3
#define TREE_MUL 4
#define TREE_DIV 5
#define TREE_LESS 6
#define TREE_GREATER 7
#define TREE_NOT 8
#define TREE_LE 9
#define TREE_GE 10
#define TREE_EQ 11
#define TREE_NE 12
#define TREE_AND 13
#define TREE_OR 14

typedef struct tree_node
{
    int type;
    HASH_NODE *symbol;
    struct tree_node *son[MAX_SONS];
} TREE;

TREE *tree_create(int type, HASH_NODE *symbol, TREE *s0, TREE *s1, TREE *s2, TREE *s3);
void tree_print(TREE *node, int level);
