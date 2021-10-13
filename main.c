#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "jogador.h"
#include "palavras.h"
#include "geral.h"

int main()
{
  srand(time(NULL));

  int opcao, npalavras, npalavraspartida, njogadores;
  int *pnpalavraspartida=&npalavraspartida, *pnpalavras=&npalavras, *pnjogadores=&njogadores;
  int i, j;
  char tentativa;
  Palavra palavras[50];
  Jogador jogadores[50];
  
  cadastraJogador(jogadores, pnjogadores);    

while(1)
{
  exibemenu();

  scanf("%d", &opcao);
  if(opcao==3) break;

  if(opcao==2)
  {
    ranking(jogadores, njogadores); // Cria e exibe o ranking
  }
    
  if(opcao==1)
  {
    printf("Começa agora uma nova partida !\n");

    FILE *arqpalavras = fopen("palavras.txt", "r");
    if(arqpalavras==NULL){
      erro(); // Imprime uma mensagem de erro
    }
    else
    {
      learquivo(arqpalavras, pnpalavras, palavras);
      qtpalavras(npalavras); // Armazena a quantidade de palavras presentes no arquivo em npalavras
      lenpalpart(pnpalavraspartida, npalavras); // Armazena a quantidade de palavras da partida em npalavraspartida

      int indice[npalavraspartida];
      geradoraleatorio(indice, npalavras, npalavraspartida); // Escolhe aleatoriamente as palavras que serão usadas na partida

      for(i=0; i<npalavraspartida; i++) //LOOP DO JOGO
      {
        int fc=0, t=0, aux=0, tamp = strlen(palavras[indice[i]].palavra);
        char tentativas[6], palcod[tamp];
        
        iniciatentativas(tentativas, 6); // Coloca espaço em todos os caracteres do vetor tentativas
        criapalcod(palcod, tamp); // Cria a palavra codificada
    
        while(aux==0)
        { 

          for(j=0; j<njogadores; j++)
          {
            getchar();
            
            //Exibe o jogo em si
            interfaceJogo(jogadores, palavras, palcod, tamp, indice, tentativas, i, j, fc);        
            scanf("%c", &tentativa);
    

            if(verificatentativa(tentativa, palavras[indice[i]].palavra)==0) // Se o jogador errou
            {
              fc++;
              if(fc==6) // Se a forca estiver completa
              {
                aux++;
                break;
              }
              tentativas[t++]=toupper(tentativa);
              
            }
            else // Se o jogador acertou
            {
              jogadores[j].pontuacao+=10*ndeocorrencias(tentativa, palavras[indice[i]].palavra); // Atualiza pontuação
              modpalcod(palcod, palavras[indice[i]].palavra, tentativa); //Substitui os caracteres certos na palavra codificada 
              if(verificapalcod(palcod, palavras[indice[i]].palavra)==0) // Se a palavra estiver completa
              {
                aux++;
                break;
              }

            }
          }
        }
      }

      fclose(arqpalavras);
    }
  }

}
  return 0;
}
