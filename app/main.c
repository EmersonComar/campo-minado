#include "campo_minado.h"

int main(void){
    Campo **tabuleiro;

    tabuleiro = criar_tabuleiro();
    exibir_tabuleiro(tabuleiro);

    limpar_tabuleiro(tabuleiro);
    return 0;
}