# Campo Minado

## Descrição

Este projeto é uma implementação do jogo Campo Minado em C. O objetivo do jogo é descobrir todas as células de um tabuleiro que não contêm bombas, sem acionar nenhuma bomba. O jogador pode marcar células que acredita conterem bombas para evitar acioná-las.

## Funcionalidades

- Distribuição aleatória de bombas no tabuleiro.
- Garantia de que a posição inicial do jogador não contém uma bomba.
- Atualização das células ao redor das bombas para indicar o número de bombas adjacentes.
- Interface de texto para interação com o jogador.

## Estrutura do Projeto

- `bombas.c`: Contém as funções responsáveis pela distribuição das bombas e atualização das células ao redor.
- `campo_minado.h`: Arquivo de cabeçalho com as definições das estruturas e funções utilizadas no projeto.
- `main.c`: Função principal que inicializa o jogo e gerencia a interação com o jogador.
- `README.md`: Este arquivo, contendo a apresentação do projeto.

## Como Compilar

Para compilar o projeto, você pode usar o `make`. Abra um terminal na pasta do projeto e execute o seguinte comando:

```bash
make
make run
```

## Contribuição

Se você deseja contribuir com o projeto, sinta-se à vontade para abrir issues ou enviar pull requests no repositório do GitHub.

## Licença

Este projeto está licenciado sob a licença GPLv3.
