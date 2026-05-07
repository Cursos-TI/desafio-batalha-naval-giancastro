#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

    const int tamanhoTabuleiro = 10;
    const int tamanhoNavio = 3;

    int tabuleiro[10][10];
    int navioHorizontal[3] = {3, 3, 3};
    int navioVertical[3] = {3, 3, 3};
    int navioDiagonalPrincipal[3] = {3, 3, 3};
    int navioDiagonalSecundaria[3] = {3, 3, 3};

    int linha;
    int coluna;
    int posicao;
    int posicaoValida = 1;

    // Coordenadas iniciais dos navios
    int linhaNavioHorizontal = 2;
    int colunaNavioHorizontal = 1;

    int linhaNavioVertical = 5;
    int colunaNavioVertical = 6;

    int linhaDiagonalPrincipal = 0;
    int colunaDiagonalPrincipal = 7;

    int linhaDiagonalSecundaria = 6;
    int colunaDiagonalSecundaria = 2;

    // Inicializa o tabuleiro com 0, representando água
    for (linha = 0; linha < tamanhoTabuleiro; linha++) {
        for (coluna = 0; coluna < tamanhoTabuleiro; coluna++) {
            tabuleiro[linha][coluna] = 0;
        }
    }

    // Valida se o navio horizontal cabe dentro do tabuleiro
    if (colunaNavioHorizontal + tamanhoNavio > tamanhoTabuleiro) {
        posicaoValida = 0;
    }

    // Valida se o navio vertical cabe dentro do tabuleiro
    if (linhaNavioVertical + tamanhoNavio > tamanhoTabuleiro) {
        posicaoValida = 0;
    }

    // Valida se o navio diagonal principal cabe dentro do tabuleiro
    if (linhaDiagonalPrincipal + tamanhoNavio > tamanhoTabuleiro ||
        colunaDiagonalPrincipal + tamanhoNavio > tamanhoTabuleiro) {
        posicaoValida = 0;
    }

    // Valida se o navio diagonal secundária cabe dentro do tabuleiro
    if (linhaDiagonalSecundaria + tamanhoNavio > tamanhoTabuleiro ||
        colunaDiagonalSecundaria - tamanhoNavio + 1 < 0) {
        posicaoValida = 0;
    }

    // Valida se o navio horizontal não irá se sobrepor a outro navio
    for (posicao = 0; posicao < tamanhoNavio; posicao++) {
        if (tabuleiro[linhaNavioHorizontal][colunaNavioHorizontal + posicao] != 0) {
            posicaoValida = 0;
        }
    }

    // Valida se o navio vertical não irá se sobrepor a outro navio
    for (posicao = 0; posicao < tamanhoNavio; posicao++) {
        if (tabuleiro[linhaNavioVertical + posicao][colunaNavioVertical] != 0) {
            posicaoValida = 0;
        }
    }

    // Como o tabuleiro ainda está vazio, os próximos testes ajudam a manter a lógica organizada.
    // A sobreposição real também será conferida antes de posicionar cada navio.
    if (posicaoValida == 1) {
        // Posiciona o navio horizontal copiando os valores do vetor para a matriz
        for (posicao = 0; posicao < tamanhoNavio; posicao++) {
            tabuleiro[linhaNavioHorizontal][colunaNavioHorizontal + posicao] = navioHorizontal[posicao];
        }

        // Posiciona o navio vertical copiando os valores do vetor para a matriz
        for (posicao = 0; posicao < tamanhoNavio; posicao++) {
            if (tabuleiro[linhaNavioVertical + posicao][colunaNavioVertical] == 0) {
                tabuleiro[linhaNavioVertical + posicao][colunaNavioVertical] = navioVertical[posicao];
            } else {
                posicaoValida = 0;
            }
        }

        // Posiciona o primeiro navio diagonal.
        // Neste caso, linha e coluna aumentam ao mesmo tempo.
        for (posicao = 0; posicao < tamanhoNavio; posicao++) {
            if (tabuleiro[linhaDiagonalPrincipal + posicao][colunaDiagonalPrincipal + posicao] == 0) {
                tabuleiro[linhaDiagonalPrincipal + posicao][colunaDiagonalPrincipal + posicao] = navioDiagonalPrincipal[posicao];
            } else {
                posicaoValida = 0;
            }
        }

        // Posiciona o segundo navio diagonal.
        // Neste caso, a linha aumenta e a coluna diminui.
        for (posicao = 0; posicao < tamanhoNavio; posicao++) {
            if (tabuleiro[linhaDiagonalSecundaria + posicao][colunaDiagonalSecundaria - posicao] == 0) {
                tabuleiro[linhaDiagonalSecundaria + posicao][colunaDiagonalSecundaria - posicao] = navioDiagonalSecundaria[posicao];
            } else {
                posicaoValida = 0;
            }
        }

        if (posicaoValida == 1) {
            printf("Coordenadas do Navio Horizontal:\n");
            for (posicao = 0; posicao < tamanhoNavio; posicao++) {
                printf("Linha: %d, Coluna: %d\n", linhaNavioHorizontal, colunaNavioHorizontal + posicao);
            }

            printf("\n");

            printf("Coordenadas do Navio Vertical:\n");
            for (posicao = 0; posicao < tamanhoNavio; posicao++) {
                printf("Linha: %d, Coluna: %d\n", linhaNavioVertical + posicao, colunaNavioVertical);
            }

            printf("\n");

            printf("Coordenadas do Navio Diagonal Principal:\n");
            for (posicao = 0; posicao < tamanhoNavio; posicao++) {
                printf("Linha: %d, Coluna: %d\n", linhaDiagonalPrincipal + posicao, colunaDiagonalPrincipal + posicao);
            }

            printf("\n");

            printf("Coordenadas do Navio Diagonal Secundaria:\n");
            for (posicao = 0; posicao < tamanhoNavio; posicao++) {
                printf("Linha: %d, Coluna: %d\n", linhaDiagonalSecundaria + posicao, colunaDiagonalSecundaria - posicao);
            }

            printf("\nTabuleiro:\n");

            // Exibe o tabuleiro completo usando loops aninhados
            for (linha = 0; linha < tamanhoTabuleiro; linha++) {
                for (coluna = 0; coluna < tamanhoTabuleiro; coluna++) {
                    printf("%d ", tabuleiro[linha][coluna]);
                }
                printf("\n");
            }
        } else {
            printf("Erro: os navios se sobrepoem.\n");
        }
    } else {
        printf("Erro: posicionamento invalido dos navios.\n");
    }

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    return 0;
}