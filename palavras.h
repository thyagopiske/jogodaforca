typedef struct{
  char palavra[50];
  char dica[50];
}Palavra;

int verificador(int *v, int valor, int npalavraspartida);
void geradoraleatorio(int *v, int limite, int npalavraspartida);
void criapalcod(char *palcod, int tam);
void exibepalcod(char *palcod, int tam);
void modpalcod(char *palcod, char *palavra, char tentativa);
int verificapalcod(char *palcod, char *palavra);
int ndeocorrencias(char tentativa, char *palavra);
void qtpalavras(int npalavras);
void lenpalpart(int *pnpalavraspartida, int npalavras);
//void cadastraPalavra();




