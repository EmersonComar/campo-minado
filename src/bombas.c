#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "campo_minado.h"

void distribuir_bombas(Campo **tabuleiro, int linha, int coluna, int quantidade, int jx, int jy){
    srand(time(NULL));

    printf("Validando coordenadas das bombas:\n");

    int i=0;
    while (i < quantidade){
        int x = (int) rand() % (linha);
        int y = (int) rand() % (coluna);

        if(jx == x && jy == y) continue;

        if(!tabuleiro[x][y].bomba){
            tabuleiro[x][y].bomba = 1;
            i++;
        }

    }
}

void atualizar_ao_redor(Campo **tabuleiro, int linha, int coluna){
    for(int l=0; l<linha; l++){
        for(int c=0; c<coluna; c++){
            if(tabuleiro[l][c].bomba){
                tabuleiro[l][c].ao_redor = -1;
                continue;
            }


            int contagem=0;
            for(int i=-1; i<=1; i++){
                for(int j=-1; j<=1; j++){
                    if(i == 0 && j == 0) continue;

                    int vizinho_l = i + l;
                    int vizinho_c = j + c;

                    if(vizinho_l >= 0 && vizinho_l < linha && vizinho_c >= 0 && vizinho_c < coluna){
                        if(tabuleiro[vizinho_l][vizinho_c].bomba){
                            contagem++;
                        }
                    }
                }
            }
            tabuleiro[l][c].ao_redor = contagem;
        }
    }
}

void revelar_bombas(Campo **tabuleiro, int linha, int coluna){
    for(int i=0; i<linha; i++){
        for(int c=0; c<coluna; c++){
            if(tabuleiro[i][c].bomba){
                tabuleiro[i][c].estado = ABERTO;
            }
        }
    }
}