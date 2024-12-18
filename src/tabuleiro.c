#include <stdio.h>
#include <stdlib.h>
#include "campo_minado.h"

#define LIN 10
#define COL 10

Campo **criar_tabuleiro(){
    Campo **tabuleiro;
    tabuleiro = (Campo**) malloc(LIN * sizeof(Campo*));

    if(tabuleiro == NULL){
        perror("Erro: Falha ao alocar memória para o tabuleiro\n");
        exit(1);
    }

    for(int i = 0; i < COL; i++){
        tabuleiro[i] = (Campo*) malloc(COL * sizeof(Campo));
        if(tabuleiro[i] == NULL){
            perror("Erro: Falha ao alocar memória para o tabuleiro\n");
            exit(1);
        }
    }

    for(int i = 0; i < LIN; i++){
        for(int j=0; j < COL; j++){
            tabuleiro[i][j].estado = FECHADO;
            tabuleiro[i][j].valor = NAO_POSSUI;
        }
    }

    return tabuleiro;
}

int exibir_tabuleiro(Campo **tabuleiro){
    if(tabuleiro == NULL){
        perror("Erro: Tabuleiro não alocado\n");
        return 0;
    }

    printf("\t");
    for(int i = 0; i < LIN; i++){
        printf("%d  ", i+1);
    }
    printf("\n");
    for(int i = 0; i < LIN; i++){
        printf("%d\t", i+1);
        for(int j = 0; j < COL; j++){
            if(tabuleiro[i][j].estado == FECHADO){
                printf("~  ");
            }else {
                printf("   ");
            }
        }
        printf("\n");
    }

    return 1;
}

void limpar_tabuleiro(Campo **tabueiro){
    if(tabueiro == NULL) return;

    for(int i = 0; i < COL; i++)
        free(tabueiro[i]);
    
    free(tabueiro);
}