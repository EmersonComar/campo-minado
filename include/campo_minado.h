/// @file campo_minado.h
/// @brief Funções referentes ao tabuleiro e ao jogador do jogo Campo Minado
/// @author Emerson
/// @date 2024-12-19


#ifndef CAMPO_MINADO_H
#define CAMPO_MINADO_H

/// @brief Cores para exibição do tabuleiro
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define CYAN "\033[36m"


/// @brief  Enumeração para o estado do campo
typedef enum{
    ABERTO,         //< Campo aberto
    FECHADO,        //< Campo fechado
} Estado;

/// @brief Estrutura de dados do campo
struct campo{
    Estado estado;  //< Estado do campo
    int bomba;      //< Indica se o campo possui bomba
    int ao_redor;   //< Quantidade de bombas ao redor do campo
};
typedef struct campo Campo;

/// @brief Estrutura de dados do jogador
struct jogador{
    int jogadas;  //< Quantidade de jogadas
    int x;        //< Coordenada x do jogador
    int y;        //< Coordenada y do jogador
};
typedef struct jogador Jogador;

// Funções referentes ao jogador
Campo **alocar_tabuleiro(int linha, int coluna);
void exibir_tabuleiro(Campo **tabuleiro, int linha, int coluna);
void limpar_tabuleiro(Campo **tabuleiro, int coluna);
void exibir_boas_vindas();

// Funções referentes ao tabuleiro
void distribuir_bombas(Campo **tabuleiro, int linha, int coluna, int quantidade, int jx, int jy);
void atualizar_ao_redor(Campo **tabuleiro, int linha, int coluna);
void revelar_bombas(Campo **tabuleiro, int linha, int coluna);
void atualiza_local(Campo **tabuleiro, int linha, int coluna, int x, int y);
int estado_aberto(Campo **tabuleiro, int linha, int coluna);


#endif