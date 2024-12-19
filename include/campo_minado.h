#ifndef CAMPO_MINADO_H
#define CAMPO_MINADO_H

// Estrutura de dados responsável pelo tabuleiro
typedef enum{
    ABERTO,
    FECHADO,
    MARCADO
} Estado;

struct campo{
    Estado estado;
    int bomba;
    int ao_redor;
};
typedef struct campo Campo;

// Estrutura de dados do jogador
struct jogador{
    int jogadas;
    int x;
    int y;
};
typedef struct jogador Jogador;

// Funções referentes ao tabuleiro
Campo **alocar_tabuleiro(int linha, int coluna);
void exibir_tabuleiro(Campo **tabuleiro, int linha, int coluna);
void limpar_tabuleiro(Campo **tabuleiro, int coluna);

// Funções referentes às bombas
void distribuir_bombas(Campo **tabuleiro, int linha, int coluna, int quantidade, int jx, int jy);
void atualizar_ao_redor(Campo **tabuleiro, int linha, int coluna);
void revelar_bombas(Campo **tabuleiro, int linha, int coluna);
void atualiza_local(Campo **tabuleiro, int linha, int coluna, int x, int y);

// Funções referentes a lógica do jogo


#endif