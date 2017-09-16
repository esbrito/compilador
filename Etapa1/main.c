int main(int argc, char** argv)
{

  if(argc < 2)
  {
    fprintf(stderr, "Erro, falta 1 argumento! Indique o nome do arquivo a ser lido");
    exit(0);
  }

  FILE* file = fopen(argv[1],"r");
	if(file == NULL)
	{
    fprintf(stderr, "Erro, ao ler arquivo!");
    exit(1);
	}
	else
	{
		yyin = file;
	}

  initMe();

  while(running)
  {
    token = yylex();
    if(!running)
    {
      break;
    }
    printf("Token detectado: %d ---- Linha: %d\n", token, getLineNumber());
  }
  hash_table_print();
  return 1;
}
