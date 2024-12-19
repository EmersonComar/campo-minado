/// @file campo_minado.h
/// @brief Funções referentes ao tabuleiro e ao jogador do jogo Campo Minado
/// @author Emerson
/// @date 2024-12-19

#ifndef CAMPO_MINADO_H
#define CAMPO_MINADO_H

#define RESET "\033[0m" ///< Reseta a cor do texto
#define RED "\033[31m" ///< Cor vermelha
#define GREEN "\033[32m" ///< Cor verde
#define YELLOW "\033[33m" ///< Cor amarela
#define CYAN "\033[36m" ///< Cor ciano

/// @brief Enumeração para o estado do campo
typedef enum{
    ABERTO,         ///< Campo aberto
    FECHADO,        ///< Campo fechado
} Estado;

struct campo{
    Estado estado;  ///< Estado do campo
    int bomba;      ///< Indica se o campo possui bomba
    int ao_redor;   ///< Quantidade de bombas ao redor do campo
};

/// @struct jogador
/// @brief Estrutura do campo do tabuleiro
typedef struct campo Campo;

struct jogador{
    int jogadas;  ///< Quantidade de jogadas
    int x;        ///< Coordenada x do jogador
    int y;        ///< Coordenada y do jogador
};

/// @struct jogador
/// @brief Estrutura do campo do tabuleiro
typedef struct jogador Jogador;

/// @brief Aloca memória para o tabuleiro
/// @param linha Quantidade máxima de linhas
/// @param coluna Quantidade máxima de colunas
/// @return Ponteiro para o tabuleiro alocado
/// @details A função aloca memória para o tabuleiro
Campo **alocar_tabuleiro(int linha, int coluna);

/// @brief Exibe o tabuleiro
/// @param tabuleiro Ponteiro para o tabuleiro
/// @param linha Quantidade de linhas do tabuleiro
/// @param coluna Quantidade de colunas do tabuleiro
/// @details A função exibe o tabuleiro
void exibir_tabuleiro(Campo **tabuleiro, int linha, int coluna);

/// @brief Limpa o tabuleiro
/// @param tabuleiro Ponteiro para o tabuleiro
/// @param coluna Quantidade de colunas do tabuleiro
/// @details A função limpa o tabuleiro
void limpar_tabuleiro(Campo **tabuleiro, int coluna);

/// @brief Exibe as boas vindas
/// @details A função exibe as boas vindas
void exibir_boas_vindas();


/// @brief Distribuir bombas no tabuleiro
/// @param tabuleiro Ponteiro para o tabuleiro
/// @param linha Quantidade de linhas do tabuleiro
/// @param coluna Quantidade de colunas do tabuleiro
/// @param quantidade Quantidade de bombas a serem distribuídas
/// @param jx Coordenada x do jogador
/// @param jy Coordenada y do jogador
/// @details A função distribui bombas aleatoriamente no tabuleiro
void distribuir_bombas(Campo **tabuleiro, int linha, int coluna, int quantidade, int jx, int jy);

/// @brief Atualiza a quantidade de bombas ao redor de cada campo
/// @param tabuleiro Ponteiro para o tabuleiro
/// @param linha Quantidade de linhas do tabuleiro
/// @param coluna Quantidade de colunas do tabuleiro
/// @details A função atualiza a quantidade de bombas ao redor de cada campo
void atualizar_ao_redor(Campo **tabuleiro, int linha, int coluna);


/// @brief Revela as bombas no tabuleiro
/// @param tabuleiro Ponteiro para o tabuleiro
/// @param linha Quantidade de linhas do tabuleiro
/// @param coluna Quantidade de colunas do tabuleiro
/// @details A função revela as bombas no tabuleiro
void revelar_bombas(Campo **tabuleiro, int linha, int coluna);

/// @brief Atualiza a posição do jogador
/// @param tabuleiro Ponteiro para o tabuleiro
/// @param linha Quantidade de linhas do tabuleiro
/// @param coluna Quantidade de colunas do tabuleiro
/// @param x Coordenada x do jogador
/// @param y Coordenada y do jogador
/// @details A função atualiza a posição do jogador
void atualiza_local(Campo **tabuleiro, int linha, int coluna, int x, int y);

/// @brief Verifica se o campo está aberto
/// @param tabuleiro Ponteiro para o tabuleiro
/// @param linha Coordenada x do campo
/// @param coluna Coordenada y do campo
/// @return 1 se o campo está aberto e 0 caso contrário
/// @details A função verifica se o campo está aberto
int estado_aberto(Campo **tabuleiro, int linha, int coluna);


#endif