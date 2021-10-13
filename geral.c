#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "jogador.h"
#include "palavras.h"
#include "geral.h"

void exibemenu()
{
    printf("MENU:\n   1 - Nova Partida\n   2 - Ranking\n   3 - Sair do jogo\n  Opção: ");
}

void exibeforca(int fc)
{
    int i, j;

    char forcas[7][8][9] = {
        {
            {' ', ' ', ' ', ' ', '_', '_', '_', ' ', ' '},
            {' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' '},
            {' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' '},
            {' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' '},
            {' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' '},
            {' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' '},
            {' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' '},
            {'_', '_', '_', '|', '_', '_', '_', '_', '_'}
        }, 

        {
            {' ', ' ', ' ', ' ', '_', '_', '_', ' ', ' '},
            {' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' '},
            {' ', ' ', ' ', '|', ' ', ' ', ' ', 'O', ' '},
            {' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' '},
            {' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' '},
            {' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' '},
            {' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' '},
            {'_', '_', '_', '|', '_', '_', '_', '_', '_'}
        },

        {
            {' ', ' ', ' ', ' ', '_', '_', '_', ' ', ' '},
            {' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' '},
            {' ', ' ', ' ', '|', ' ', ' ', ' ', 'O', ' '},
            {' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' '},
            {' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' '},
            {' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' '},
            {' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' '},
            {'_', '_', '_', '|', '_', '_', '_', '_', '_'}
        },

        {
            {' ', ' ', ' ', ' ', '_', '_', '_', ' ', ' '},
            {' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' '},
            {' ', ' ', ' ', '|', ' ', ' ', ' ', 'O', ' '},
            {' ', ' ', ' ', '|', ' ', ' ', '/', '|', ' '},
            {' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' '},
            {' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' '},
            {' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' '},
            {'_', '_', '_', '|', '_', '_', '_', '_', '_'}
        },

        {
            {' ', ' ', ' ', ' ', '_', '_', '_', ' ', ' '},
            {' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' '},
            {' ', ' ', ' ', '|', ' ', ' ', ' ', 'O', ' '},
            {' ', ' ', ' ', '|', ' ', ' ', '/', '|', '\\'},
            {' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' '},
            {' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' '},
            {' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' '},
            {'_', '_', '_', '|', '_', '_', '_', '_', '_'}
        },

        {
            {' ', ' ', ' ', ' ', '_', '_', '_', ' ', ' '},
            {' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' '},
            {' ', ' ', ' ', '|', ' ', ' ', ' ', 'O', ' '},
            {' ', ' ', ' ', '|', ' ', ' ', '/', '|', '\\'},
            {' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' '},
            {' ', ' ', ' ', '|', ' ', ' ', '/', ' ', ' '},
            {' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' '},
            {'_', '_', '_', '|', '_', '_', '_', '_', '_'}
        },

        {
            {' ', ' ', ' ', ' ', '_', '_', '_', ' ', ' '},
            {' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' '},
            {' ', ' ', ' ', '|', ' ', ' ', ' ', 'O', ' '},
            {' ', ' ', ' ', '|', ' ', ' ', '/', '|', '\\'},
            {' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' '},
            {' ', ' ', ' ', '|', ' ', ' ', '/', ' ', '\\'},
            {' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' '},
            {'_', '_', '_', '|', '_', '_', '_', '_', '_'}
        }
    };  

    for(i=0; i<8; i++)
    {
      for(j=0; j<9; j++)
        printf("%c", forcas[fc][i][j]); // ou eu posso printar string né

      putchar('\n');
    }
}

void iniciatentativas(char *tentativas, int tamtent)
{
    for(int i=0; i<tamtent; i++) 
        tentativas[i]=' ';

}

void exibetentativas(char *tentativas)
{
   for(int i=0; i<6; i++)
   {
      printf("%c", toupper(tentativas[i]));
   } 
   putchar('\n');
}

int verificatentativa(char tentativa, char *palavra)
{
    int i;
    for(i=0; palavra[i]!='\0'; i++)
        if(tolower(tentativa)==tolower(palavra[i]))
            return 1;

    return 0;
}

void erro()
{
    printf("Não foi possível abrir o arquivo de palavras. Tente novamente mais tarde\n");
    exit(1);
}

void learquivo(FILE *arqpalavras, int *pnpalavras, Palavra *palavras)
{
     fscanf(arqpalavras, "%d", pnpalavras);

      for(int i=0; i<*pnpalavras; i++)
      {
          fscanf(arqpalavras, "%s", palavras[i].palavra);
          fscanf(arqpalavras, "%*c");
          fscanf(arqpalavras, "%[^\n]", palavras[i].dica);
          fscanf(arqpalavras, "%*c");
      }
}

void interfaceJogo(Jogador *jogadores, Palavra *palavras, char *palcod, int tamp, int *indice, char *tentativas, int i, int j, int fc)
{
    printf("Vez de %s\n", jogadores[j].nome);
    exibeforca(fc);
    printf("Palavra: ");
    exibepalcod(palcod, tamp); 
    printf("Dica: %s\n", palavras[indice[i]].dica);
    printf("Tentativas: ");
    exibetentativas(tentativas);
    printf("Escolha uma letra: ");
    
}

void ranking(Jogador *jogadores, int njogadores)
{
    int desordenado=1, aux, i, aux2;
    char straux[50];

    while(desordenado!=0)
    {
      desordenado=0;
      for(i=0; i<njogadores-1; i++)
      {
         if(jogadores[i].pontuacao>jogadores[i+1].pontuacao)
         {
            aux=jogadores[i].pontuacao;
            jogadores[i].pontuacao=jogadores[i+1].pontuacao;
            jogadores[i+1].pontuacao=aux;
          

            strcpy(straux, jogadores[i].nome);
            strcpy(jogadores[i].nome, jogadores[i+1].nome);
            strcpy(jogadores[i+1].nome, straux);
            
            desordenado=1;
        }
      }
    }

    printf("\n  RANKING\n\n");

    for(i=0, aux2=njogadores-1; i<njogadores; i++, aux2--)
        {
            printf("%d - %s\n - %d pontos\n", i+1, jogadores[aux2].nome, jogadores[aux2].pontuacao);
        }

      printf("\nENTER para retornar ao MENU");
      getchar();
      getchar();
}

