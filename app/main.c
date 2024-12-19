#include <stdio.h>
#include "campo_minado.h"

#define LIN 10
#define COL 10
#define QTD 10

int main(void){
    Campo **tabuleiro;
    Jogador jogador = {1,0,0};
    int bomba_descoberta = 0;

    tabuleiro = alocar_tabuleiro(LIN, COL);
    while(!bomba_descoberta){

        exibir_tabuleiro(tabuleiro, LIN, COL);
        printf("Jogada [%d]. Coordenadas(x, y): ", jogador.jogadas);
        scanf("%d %d", &jogador.x, &jogador.y);
        
        jogador.x--;
        jogador.y--;

        if(jogador.x  > (LIN - 1) || jogador.y > (COL - 1)){
            printf("\n--Valor não possível. Jogue novamente--\n\n");
            continue;
        }

        if(tabuleiro[jogador.x][jogador.y].estado == ABERTO){
            printf("\n--Local já descoberto. Jogue novamente--\n\n");
            continue;
        }

        if(tabuleiro[jogador.x][jogador.y].bomba){
            revelar_bombas(tabuleiro, LIN, COL);
            exibir_tabuleiro(tabuleiro, LIN, COL);
            printf("\n--Perdeu: bombas reveladas--\n\n");
            break;
        }

        if(jogador.jogadas == 1){
            distribuir_bombas(tabuleiro, LIN, COL, QTD, jogador.x, jogador.y);
            atualizar_ao_redor(tabuleiro, LIN, COL);
        }

        atualiza_local(tabuleiro, LIN, COL, jogador.x, jogador.y);
        jogador.jogadas++;
    }


    limpar_tabuleiro(tabuleiro, COL);
    return 0;
}