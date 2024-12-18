#ifndef CAMPO_MINADO_H
#define CAMPO_MINADO_H

typedef enum{
    ABERTO,
    FECHADO
} Local;

typedef enum{
    POSSUI,
    NAO_POSSUI
} Bomba;

struct campo{
    Local estado;
    Bomba valor;
};
typedef struct campo Campo;

// Funções referentes ao tabuleiro
Campo **criar_tabuleiro();
int exibir_tabuleiro(Campo **tabuleiro);
void limpar_tabuleiro(Campo **tabueiro);

#endif