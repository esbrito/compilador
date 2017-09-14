

typedef struct hash_node
{
  int type;
  char* text;
  struct hash_node* next;
} HASH_NODE;


void hashAddress(char *text);
HASH_NODE* hashInsert(int type, char *text);
void hashTablePrint(void);
HASH_NODE* hashFind( char *text);
