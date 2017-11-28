#ifndef GENCO_HEADER
#define GENCO_HEADER
#include "hash.h"
#include "tree.h"

#define TAC_SYMBOL 1
#define TAC_ADD 2
#define TAC_MUL 3
#define TAC_DIV 4
#define TAC_SUB 5
#define TAC_ASS 6
#define TAC_JZ 7
#define TAC_LABEL 8

typedef struct tac
{
    int type;
    HASH_NODE* res;
    HASH_NODE* op1;
    HASH_NODE* op2;
    struct tac* prev;
    struct tac* next;
} TAC;

TAC* tac_create(int type, HASH_NODE* res, HASH_NODE* op1,  HASH_NODE* op2);
TAC* tac_generator(TREE* node);
TAC* tac_join(TAC* l1, TAC* l2);
void tac_print_back(TAC* tac);
void tac_print_single(TAC* tac);
TAC* make_if_then(TAC* code0, TAC* code1);


#endif
