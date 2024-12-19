/// @file bombas.c
/// @brief Funções referentes às bombas
/// @author Emerson
/// @date 2024-12-19

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "campo_minado.h"

/// @brief Função responsável por distribuir as bombas no tabuleiro
/// @param tabuleiro Matriz de Campo
/// @param linha Quantidade de linhas do tabuleiro
/// @param coluna Quantidade de colunas do tabuleiro
/// @param quantidade Quantidade de bombas a serem distribuídas
/// @param jx Coordenada x do jogador
/// @param jy Coordenada y do jogador
/// @details A função distribui as bombas no tabuleiro de forma aleatória, garantindo que não haja bombas na posição do jogador
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

/// @brief Função responsável por atualizar a quantidade de bombas ao redor de cada campo
/// @param tabuleiro Matriz de Campo
/// @param linha Quantidade de linhas do tabuleiro
/// @param coluna Quantidade de colunas do tabuleiro
/// @details A função percorre o tabuleiro e atualiza a quantidade de bombas ao redor de cada campo
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

/// @brief Função responsável por revelar todas as bombas no tabuleiro
/// @param tabuleiro Matriz de Campo
/// @param linha Quantidade de linhas do tabuleiro
/// @param coluna Quantidade de colunas do tabuleiro
void revelar_bombas(Campo **tabuleiro, int linha, int coluna){
    for(int i=0; i<linha; i++){
        for(int c=0; c<coluna; c++){
            if(tabuleiro[i][c].bomba){
                tabuleiro[i][c].estado = ABERTO;
            }
        }
    }
}