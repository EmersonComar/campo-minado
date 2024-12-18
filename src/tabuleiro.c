#include <stdio.h>
#include <stdlib.h>
#include "campo_minado.h"

Campo **alocar_tabuleiro(int linha, int coluna){
    Campo **tabuleiro = (Campo **) malloc(linha * sizeof(Campo*));
    if(tabuleiro == NULL){
        perror("Erro: Falha ao alocar memória para a criação do Tabuleiro\n");
        exit(EXIT_FAILURE);
    }

    for(int i=0; i<coluna; i++){
        tabuleiro[i] = (Campo*) malloc(coluna * sizeof(Campo));
        if(tabuleiro[i] == NULL){
            perror("Erro: Falha ao criar linhas do tabuleiro\n");
            exit(EXIT_FAILURE);
        }
        for(int j=0; j<coluna; j++){
            tabuleiro[i][j].ao_redor = 0;
            tabuleiro[i][j].bomba = 0;
            tabuleiro[i][j].estado = FECHADO;
        }
    }
    return tabuleiro;
}

void exibir_tabuleiro(Campo **tabuleiro, int linha, int coluna){
    printf("\t");
    for(int i=0; i<coluna; i++){
        printf("%d ", i+1);
    }
    printf("\n");

    for(int i=0; i<linha; i++){
        printf("%d\t", i+1);
        for(int j=0; j<coluna; j++){
            if(tabuleiro[i][j].estado == FECHADO){
                printf("~ ");
            } else{
                if(tabuleiro[i][j].bomba){
                    printf("%d ", tabuleiro[i][j].ao_redor);
                } else{
                    printf("  ");
                }
            }
        }

        printf("\n");
    }
}


void limpar_tabuleiro(Campo **tabuleiro, int coluna){
    if(tabuleiro == NULL) return;

    for(int i=0; i<coluna; i++)
        free(tabuleiro[i]);

    free(tabuleiro);
}