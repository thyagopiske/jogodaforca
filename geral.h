void exibemenu();
void exibeforca(int fc);
int verificatentativa(char tentativa, char *palavra);
void iniciatentativas(char *tentativas, int tamtent);
void exibetentativas(char *tentativas);
void erro();
void learquivo(FILE *arqpalavras, int *pnpalavras, Palavra *palavras);
void interfaceJogo(Jogador *jogadores, Palavra *palavras, char *palcod, int tamp, int *indice, char *tentativas, int i, int j, int fc);
void ranking(Jogador *jogadores, int njogadores);

    