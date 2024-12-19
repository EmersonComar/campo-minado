#include <stdio.h>
#include <stdlib.h>
#include "campo_minado.h"

#define LIN 10
#define COL 10
#define QTD 5

int main(void) {
    Campo **tabuleiro;
    Jogador jogador = {1, 0, 0};
    int bomba_descoberta = 0;
    int campos_abertos = 0;
    int campos_sem_bombas = (LIN * COL) - QTD;

    exibir_boas_vindas();

    tabuleiro = alocar_tabuleiro(LIN, COL);

    while (!bomba_descoberta && campos_abertos != campos_sem_bombas) {
        printf(GREEN "Jogada [%d]\n" RESET, jogador.jogadas);
        exibir_tabuleiro(tabuleiro, LIN, COL);
        printf(YELLOW "Digite as coordenadas (linha coluna): " RESET);
        scanf("%d %d", &jogador.x, &jogador.y);

        jogador.x--;
        jogador.y--;

        if (jogador.x > (LIN - 1) || jogador.y > (COL - 1) || jogador.x < 0 || jogador.y < 0) {
            printf(RED "\n-- Coordenadas inválidas. Tente novamente. --\n\n" RESET);
            continue;
        }

        if (tabuleiro[jogador.x][jogador.y].estado == ABERTO) {
            printf(RED "\n-- Local já descoberto. Tente novamente. --\n\n" RESET);
            continue;
        }

        if (tabuleiro[jogador.x][jogador.y].bomba) {
            revelar_bombas(tabuleiro, LIN, COL);
            exibir_tabuleiro(tabuleiro, LIN, COL);
            printf(RED "\n-- Você perdeu! Bombas reveladas! --\n\n" RESET);
            bomba_descoberta = 1;
            break;
        }

        if (jogador.jogadas == 1) {
            distribuir_bombas(tabuleiro, LIN, COL, QTD, jogador.x, jogador.y);
            atualizar_ao_redor(tabuleiro, LIN, COL);
        }

        atualiza_local(tabuleiro, LIN, COL, jogador.x, jogador.y);
        campos_abertos = estado_aberto(tabuleiro, LIN, COL);
        jogador.jogadas++;
    }

    if (campos_abertos == campos_sem_bombas) {
        revelar_bombas(tabuleiro, LIN, COL);
        exibir_tabuleiro(tabuleiro, LIN, COL);
        printf(GREEN "\n-- Parabéns! Você ganhou! --\n\n" RESET);
    }

    limpar_tabuleiro(tabuleiro, COL);
    return 0;
}
