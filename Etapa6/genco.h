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
#define TAC_INPUT 9
#define TAC_VECREAD 10
#define TAC_LESS 11
#define TAC_GREATER 12
#define TAC_NOT 13
#define TAC_LE 14
#define TAC_GE 15
#define TAC_EQ 16
#define TAC_NE 17
#define TAC_AND 18
#define TAC_OR 19
#define TAC_VECWRITE 20
#define TAC_OUTPUT 21
#define TAC_BEGINFUN 22
#define TAC_ENDFUN 23
#define TAC_JMP 24
#define TAC_ARG 25
#define TAC_FUNCALL 26
#define TAC_RETURN 27

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
TAC* make_if_then_else(TAC* code0, TAC* code1, TAC* code2);
TAC* make_while(TAC* code0, TAC* code1);
TAC* make_funcall(TAC* params);
TAC* reverse(TAC* tac);

#endif
