#include "campo_minado.h"

#define LIN 10
#define COL 10
#define QTD 10

int main(void){
    Campo **tabuleiro;

    tabuleiro = alocar_tabuleiro(LIN, COL);
    distribuir_bombas(tabuleiro, LIN, COL, QTD);
    atualizar_ao_redor(tabuleiro, LIN, COL);
    exibir_tabuleiro(tabuleiro, LIN, COL);


    limpar_tabuleiro(tabuleiro, COL);
    return 0;
}