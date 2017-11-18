#include "hash.h"
#include "tree.h"
#include "y.tab.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

HASH_NODE *hash_table[HASH_SIZE];

void initMe() {
    int i;
    for (i=0 ; i < HASH_SIZE ; i++) { hash_table[i] = 0; }
}


HASH_NODE* hash_insert(int type, char *text)
{
    HASH_NODE *node;
    int address;
    node = hash_find(text);
    if (node)
    {
        return node;
    }
    else
    {
	address = hash_address(text);
        node = (HASH_NODE *)calloc(1, sizeof(HASH_NODE));
        node->type = type;
        node->text = calloc(strlen(text) + 1, sizeof(1));
        strcpy(node->text, text);
        node->next = hash_table[address];
        hash_table[address] = node;
        return node;
    }
}

void hash_table_print(void)
{
    int i = 0;
    HASH_NODE *node;
    for (i = 0; i < HASH_SIZE; ++i)
    {
        for (node = hash_table[i]; node; node = node->next)
        {
	    printf("Tabela na posição %d possui o valor %s\n", i, node->text);
        }
    }
}

HASH_NODE* hash_find(char *text)
{
    HASH_NODE *node;
    int address;

    address = hash_address(text);
    for (node = hash_table[address]; node; node = node->next)
    {
        if (!(strcmp(text, node->text)))
        {
            return node;
        }
    }
    return 0;
}

int hash_address(char *text)
{
    int i = 0;
    int address = 1;
    for (i = 0; i < strlen(text); ++i)
    {
        address = ((address * text[i]) % HASH_SIZE) + 1;
    }
    
    return address - 1;
}

void hashCheckUndeclared()
{
    int i;
    HASH_NODE *node;
    for (i = 0; i < HASH_SIZE; ++i)
    {
        for (node = hash_table[i]; node; node = node->next)
        {
            if (node->type == TK_IDENTIFIER)
            {
                fprintf(stderr, "Semantic ERROR: symbol %s not declared\n", node->text);
                found_semantic_err = 1; //set flag semantic err
            }
        }
    }
}
