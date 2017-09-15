
#define HASH_SIZE 1000
typedef struct hash_node
{
  int type;
  char* text;
  struct hash_node* next;
} HASH_NODE;


int hash_address(char *text);
HASH_NODE* hash_insert(int type, char *text);
void hash_table_print(void);
HASH_NODE* hash_find( char *text);
