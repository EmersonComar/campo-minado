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

void exibir_tabuleiro(Campo **tabuleiro, int linhas, int colunas){
    printf(CYAN "\n    ");
    for (int j = 0; j < colunas; j++) {
        printf("%2d ", j + 1);
    }
    printf("\n");

    for (int i = 0; i < linhas; i++) {
        printf(CYAN " %2d " RESET, i + 1);
        for (int j = 0; j < colunas; j++) {
            if (tabuleiro[i][j].estado == ABERTO) {
                if (tabuleiro[i][j].bomba) {
                    printf(RED " X " RESET);
                } else {
                    printf(GREEN " %d " RESET, tabuleiro[i][j].ao_redor);
                }
            } else {
                printf(" # ");
            }
        }
        printf("\n");
    }
    printf("\n");
}


void limpar_tabuleiro(Campo **tabuleiro, int coluna){
    if(tabuleiro == NULL) return;

    for(int i=0; i<coluna; i++)
        free(tabuleiro[i]);

    free(tabuleiro);
}

void atualiza_local(Campo **tabuleiro, int linha, int coluna, int x, int y){

    if(x < 0 || x >= linha || y < 0 || y >= coluna){
        return;
    }

    if(tabuleiro[x][y].estado == ABERTO)
        return;

    tabuleiro[x][y].estado = ABERTO;

    if(tabuleiro[x][y].ao_redor > 0)
        return;

    for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
            if (dx != 0 || dy != 0) { 
                atualiza_local(tabuleiro, linha, coluna, x + dx, y + dy);
            }
        }
    }
}

int estado_aberto(Campo **tabuleiro, int linha, int coluna){
    int count=0;
    for(int i=0; i<linha; i++)
        for(int j=0; j<coluna; j++)
            if(tabuleiro[i][j].estado == ABERTO)
                count++;

    
    return count;
}

void exibir_boas_vindas() {
    printf(CYAN "=================================\n");
    printf("       Bem-vindo ao Campo Minado!\n");
    printf("   Abra todos os campos sem bombas\n");
    printf("=================================\n" RESET);
}