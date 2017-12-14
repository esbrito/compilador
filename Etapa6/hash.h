#include "tree.h"
#ifndef hash_h
#define hash_h

#define HASH_SIZE 1000

#define SYMBOL_VAR 1
#define SYMBOL_VEC 2
#define SYMBOL_FUN 3

#define DATATYPE_BYTE 1
#define DATATYPE_SHORT 2
#define DATATYPE_LONG 3
#define DATATYPE_FLOAT 4
#define DATATYPE_DOUBLE 5

#define SYMBOL_LABEL 6

typedef struct hash_node
{
  int type;
  char* text;
  int datatype;
  struct hash_node* next;
  struct tree_node *tree;
} HASH_NODE;


int hash_address(char *text);
HASH_NODE* hash_insert(int type, char *text);
void hash_table_print(void);
HASH_NODE* hash_find( char *text);
void hashCheckUndeclared();
void initMe();
HASH_NODE* make_temp(void);
HASH_NODE* make_label(void);
HASH_NODE** get_hash_table(void);

#endif /* hash_h */
