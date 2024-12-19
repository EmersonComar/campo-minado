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

// Funções referentes ao tabuleiro
Campo **alocar_tabuleiro(int linha, int coluna);
void exibir_tabuleiro(Campo **tabuleiro, int linha, int coluna);
void limpar_tabuleiro(Campo **tabuleiro, int coluna);

// Funções referentes às bombas
void distribuir_bombas(Campo **tabuleiro, int linha, int coluna, int quantidade);
void atualizar_ao_redor(Campo **tabuleiro, int linha, int coluna);


#endif