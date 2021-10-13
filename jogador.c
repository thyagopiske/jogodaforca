#include <stdio.h>
#include "jogador.h"
#include "palavras.h"
#include "geral.h"

void cadastraJogador(Jogador *jogadores, int *pnjogadores)
{
    printf("Quantos jogadores serão cadastrados ?");
    scanf("%d", pnjogadores);
    
    for(int i=0; i<*pnjogadores; i++){
        printf("Informe o nome do %dº jogador: ", i+1);
        scanf("%s", jogadores[i].nome);
        jogadores[i].pontuacao=0;
  }
}