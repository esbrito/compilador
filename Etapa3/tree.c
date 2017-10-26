#include "tree.h"
TREE *tree_create(int type, HASH_NODE *symbol, TREE *s0, TREE *s1, TREE *s2, TREE *s3)
{
    TREE *new;
    new = (TREE *)calloc(1, sizeof(TREE));
    new->type = type;
    new->symbol = symbol;
    new->son[0] = s0;
    new->son[1] = s1;
    new->son[2] = s2;
    new->son[3] = s3;
}

void tree_print(TREE *node)
{
    if (node)
    {
        fprintf(stderr, "TREE(");
        switch (node->type)
        {
        case TREE_ADD:
            fprintf(stderr, "SOMA\n");
            break;
        default:
            fprintf(stderr, "UNKOWN\n");
            break;
        }
    // TODO printar os filhos

    }
}