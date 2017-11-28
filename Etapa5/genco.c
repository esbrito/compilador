
#include "genco.h"


TAC* tac_create(int type, HASH_NODE* res, HASH_NODE* op1,  HASH_NODE* op2)
{
  TAC* new;
  new = (TAC*) calloc(1, sizeof(TAC));
  new->type = type;
  new->res = res;
  new->op1 = op1;
  new->op2 = op2;
  new->prev = 0;
  new->next = 0;
  return new;
}

TAC* tac_join(TAC* l1, TAC* l2)
{
  TAC* tac = l2;
  if(!l1) return l2;
  if(!l2) return l1;
  while(tac->prev)
  {
    tac = tac->prev;
  }
  tac->prev = l1;
  return l2;
}

void tac_print_back(TAC* last)
{
  TAC* tac;
  for (tac = last; tac; tac = tac->prev)
  {
    tac_print_single(tac);
  }
}
void tac_print_single(TAC* tac)
{
  if(!tac) return;
  if(tac->type == TAC_SYMBOL) return;
  fprintf(stderr,"TAC(");
  switch (tac->type)
  {
    case TAC_ADD: fprintf(stderr, "TAC_ADD" ); break;
    case TAC_MUL: fprintf(stderr, "TAC_MUL" ); break;
    case TAC_SUB: fprintf(stderr, "TAC_SUB" ); break;
    case TAC_DIV: fprintf(stderr, "TAC_DIV" ); break;
    case TAC_ASS: fprintf(stderr, "TAC_ASS" ); break;
    case TAC_LABEL: fprintf(stderr, "TAC_LABEL" ); break;
    case TAC_INPUT: fprintf(stderr, "TAC_INPUT" ); break;
    case TAC_VECREAD: fprintf(stderr, "TAC_VECREAD" ); break;
    case TAC_JZ: fprintf(stderr, "TAC_JZ" ); break;
    default:  fprintf(stderr, "UNKOWN" ); break;
  }

  if(tac->res) fprintf(stderr, ",%s", tac->res->text); else fprintf(stderr, ",null");
  if(tac->op1) fprintf(stderr, ",%s", tac->op1->text); else fprintf(stderr, ",null");
  if(tac->op2) fprintf(stderr, ",%s", tac->op2->text); else fprintf(stderr, ",null");
  fprintf(stderr, ")\n");
}

TAC* tac_generator(TREE* node)
{
  int i;
  TAC* code[MAX_SONS];
  if(!node) return 0;

  //Gerando filhos
  for(i=0; i < MAX_SONS ; ++i)
  {
    code[i] = tac_generator(node->son[i]);
  }

  switch (node->type) {
    case TREE_SYMBOL: return tac_create(TAC_SYMBOL, node->symbol,0,0); break;
    case TREE_ADD: return tac_join(tac_join(code[0], code[1]), tac_create(TAC_ADD,  make_temp() ,code[0]?code[0]->res:0,code[1]?code[1]->res:0)); break;
    case TREE_MUL: return tac_join(tac_join(code[0], code[1]), tac_create(TAC_MUL,  make_temp() ,code[0]?code[0]->res:0,code[1]?code[1]->res:0)); break;
    case TREE_DIV: return tac_join(tac_join(code[0], code[1]), tac_create(TAC_DIV,  make_temp() ,code[0]?code[0]->res:0,code[1]?code[1]->res:0)); break;
    case TREE_SUB: return tac_join(tac_join(code[0], code[1]), tac_create(TAC_SUB,  make_temp() ,code[0]?code[0]->res:0,code[1]?code[1]->res:0)); break;
    case TREE_ASSIGN: return tac_join(code[0],tac_create(TAC_ASS,  node->symbol ,code[0]?code[0]->res:0,0)); break;
    case TREE_READ: return tac_join(code[0],tac_create(TAC_INPUT,  node->symbol ,code[0]?code[0]->res:0,0)); break;
    case TREE_VECTOR: return tac_join(code[0],tac_create(TAC_VECREAD,   make_temp() ,node->symbol,code[0]?code[0]->res:0)); break;
    case TREE_IF: return make_if_then(code[0],code[1]); break;
  }
  return tac_join(tac_join(tac_join(code[0], code[1]),code[2]),code[3]);
}

TAC* make_if_then(TAC* code0, TAC* code1)
{
  TAC *new_jump_tac = 0;
  TAC *new_label_tac = 0;
  HASH_NODE* new_label = 0;

  new_label = make_label();

  new_jump_tac = tac_create(TAC_JZ, new_label, code0?code0->res:0, 0);
  new_label_tac = tac_create(TAC_LABEL,new_label, 0, 0);
  return tac_join(tac_join(tac_join(code0, new_jump_tac), code1), new_label_tac);
}
