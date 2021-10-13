#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include "jogador.h"
#include "palavras.h"
#include "geral.h"

// Verifica se o valor gerado aleatoriamente já existe no vetor.
int verificador(int *v, int valor, int npalavraspartida)
{
    int i;
    for(i=0; i<npalavraspartida; i++)
        if(v[i]==valor)
            return 1;

    return 0;
}

// Gera valores aleatórios não repetidos
void geradoraleatorio(int *v, int limite, int npalavraspartida)
{
  
    int valor;

    for(int i=0; i<npalavraspartida; i++)
    {
        if(i!=0)
        {
            valor=rand()%limite;
            if(verificador(v, valor, limite)==1)
                while(verificador(v, valor, limite)==1) // Enquanto o valor aleatório já existir no vetor
                    valor=rand()%limite;
            v[i]=valor;
        }
        else
        {
            v[i] = rand()%limite;
        }
    }

}

void criapalcod(char *palcod, int tam)
{
  int i;
  for(i=0; i<tam; i++)
  {
    palcod[i]='_';
  }
}

void exibepalcod(char *palcod, int tam)
{
  int i;

  for(i=0; i<tam; i++)
    printf("%c", toupper(palcod[i]));
  putchar('\n');
}

void modpalcod(char *palcod, char *palavra, char tentativa)
{
  for(int i=0; palavra[i]!='\0'; i++)
    if(tolower(palavra[i])==tolower(tentativa))
        palcod[i]=toupper(tentativa);
}

int verificapalcod(char *palcod, char *palavra)
{
  for(int i=0; palavra[i]!='\0'; i++)
  {
    if(toupper(palcod[i])!=toupper(palavra[i]))
      return 1;
  }

  return 0; 
}

int ndeocorrencias(char tentativa, char *palavra)
{
  int j=0;
  for(int i=0; palavra[i]!='\0'; i++)
    if(toupper(palavra[i])==toupper(tentativa))
      j++;

  return j;
}

void qtpalavras(int npalavras)
{
  printf("Foram encontradas %d palavras.\n", npalavras);
  printf("Quantas palavras deseja para esta partida ? Escolha uma quantidade de 1 a %d\n", npalavras);
}

void lenpalpart(int *pnpalavraspartida, int npalavras)
{
  scanf("%d", pnpalavraspartida);
      
  while( (*pnpalavraspartida<1) || (*pnpalavraspartida>npalavras) )
  {
    printf("Quantidade  inválida, tente novamente.\n");
    scanf("%d", pnpalavraspartida);
  }
}
