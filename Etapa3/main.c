
extern TREE* ast_tree;


FILE* open_file(char* path)
{
	FILE* file;
	file = fopen(path,"w");
	if(file == NULL)
	{
		fprintf(stderr,"ERROR: Couldn't open %s\n",path);
		exit(1);
  }
  return file;
}


int main(int argc, char** argv)
{

  if(argc < 3)
  {
    fprintf(stderr, "Erro, faltao argumentos! Indique o nome do arquivo a ser lido e o nome do arquivo de saída");
    exit(99);
  }

  FILE* file = fopen(argv[1],"r");
	if(file == NULL)
	{
    fprintf(stderr, "Erro, ao ler arquivo!");
    exit(99);
	}
	else
	{
		yyin = file;
	}

  initMe();

  while(isRunning())
  {
    yyparse();
    printf("Token detectado: %d ---- Linha: %d\n", token, getLineNumber());
  }

  char* decompiled_tree = decompile(open_file(argv[2]), ast_tree, 0);
  hash_table_print();
  //Se chegou aqui é porque a sintasse está correta
  printf("Sintaxe correta!\n");
  exit(0);
}
