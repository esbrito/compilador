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
#define TREE_ASSIGN 15
#define TREE_IF 16
#define TREE_WHILE 17
#define TREE_PRINT 18
#define TREE_READ 19
#define TREE_RETURN 20
#define TREE_ELSE 21
#define TREE_DECLARATION_SCALAR 22
#define TREE_DECLARATION_VECTOR 23
#define TREE_FUNCTION 24
#define TREE_KW_BYTE 25
#define TREE_KW_SHORT 26
#define TREE_KW_LONG 27
#define TREE_KW_FLOAT 28
#define TREE_KW_DOUBLE 29
#define TREE_PARAMS 30
#define TREE_CMD_LIST 31
#define TREE_ASSIGN_VECTOR 32
#define TREE_FUNCTION_CALL 33
#define TREE_PARAM 34
#define TREE_VECTOR_VALUES 35
#define TREE_CMD_BLOCK 36
#define PROGRAM 37
#define DECLARATIONS 38










typedef struct tree_node
{
    int type;
    HASH_NODE *symbol;
    struct tree_node *son[MAX_SONS];
} TREE;

TREE *tree_create(int type, HASH_NODE *symbol, TREE *s0, TREE *s1, TREE *s2, TREE *s3);
void tree_print(TREE *node, int level);
char* decompile(FILE* file, TREE *node, int level);
