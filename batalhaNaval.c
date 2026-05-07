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
    const int tamanhoHabilidade = 5;

    int tabuleiro[10][10];

    int navioHorizontal[3] = {3, 3, 3};
    int navioVertical[3] = {3, 3, 3};
    int navioDiagonalPrincipal[3] = {3, 3, 3};
    int navioDiagonalSecundaria[3] = {3, 3, 3};

    int cone[5][5];
    int cruz[5][5];
    int octaedro[5][5];

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

    // Pontos de origem das habilidades no tabuleiro
    int origemConeLinha = 1;
    int origemConeColuna = 1;

    int origemCruzLinha = 4;
    int origemCruzColuna = 4;

    int origemOctaedroLinha = 7;
    int origemOctaedroColuna = 7;

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

    if (posicaoValida == 1) {
        // Posiciona o navio horizontal copiando os valores do vetor para a matriz
        for (posicao = 0; posicao < tamanhoNavio; posicao++) {
            if (tabuleiro[linhaNavioHorizontal][colunaNavioHorizontal + posicao] == 0) {
                tabuleiro[linhaNavioHorizontal][colunaNavioHorizontal + posicao] = navioHorizontal[posicao];
            } else {
                posicaoValida = 0;
            }
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

        // Cria as matrizes das habilidades usando loops aninhados e condicionais.
        for (linha = 0; linha < tamanhoHabilidade; linha++) {
            for (coluna = 0; coluna < tamanhoHabilidade; coluna++) {
                // Inicializa todas as posições como não afetadas
                cone[linha][coluna] = 0;
                cruz[linha][coluna] = 0;
                octaedro[linha][coluna] = 0;

                // Habilidade Cone:
                // A área começa no topo central e aumenta para baixo.
                if (coluna >= 2 - linha && coluna <= 2 + linha) {
                    cone[linha][coluna] = 1;
                }

                // Habilidade Cruz:
                // Afeta a linha central e a coluna central.
                if (linha == 2 || coluna == 2) {
                    cruz[linha][coluna] = 1;
                }

                // Habilidade Octaedro:
                // Forma um losango usando a distância do centro.
                if ((linha - 2) * (linha - 2) + (coluna - 2) * (coluna - 2) <= 4) {
                    if (linha == 2 || coluna == 2 || 
                        (linha == 1 && coluna >= 1 && coluna <= 3) ||
                        (linha == 3 && coluna >= 1 && coluna <= 3)) {
                        octaedro[linha][coluna] = 1;
                    }
                }
            }
        }

        // Sobrepõe a habilidade Cone ao tabuleiro.
        // O valor 5 representa uma área atingida pela habilidade.
        for (linha = 0; linha < tamanhoHabilidade; linha++) {
            for (coluna = 0; coluna < tamanhoHabilidade; coluna++) {
                int linhaTabuleiro = origemConeLinha + linha - 2;
                int colunaTabuleiro = origemConeColuna + coluna - 2;

                if (cone[linha][coluna] == 1 &&
                    linhaTabuleiro >= 0 && linhaTabuleiro < tamanhoTabuleiro &&
                    colunaTabuleiro >= 0 && colunaTabuleiro < tamanhoTabuleiro) {

                    if (tabuleiro[linhaTabuleiro][colunaTabuleiro] == 0) {
                        tabuleiro[linhaTabuleiro][colunaTabuleiro] = 5;
                    }
                }
            }
        }

        // Sobrepõe a habilidade Cruz ao tabuleiro.
        for (linha = 0; linha < tamanhoHabilidade; linha++) {
            for (coluna = 0; coluna < tamanhoHabilidade; coluna++) {
                int linhaTabuleiro = origemCruzLinha + linha - 2;
                int colunaTabuleiro = origemCruzColuna + coluna - 2;

                if (cruz[linha][coluna] == 1 &&
                    linhaTabuleiro >= 0 && linhaTabuleiro < tamanhoTabuleiro &&
                    colunaTabuleiro >= 0 && colunaTabuleiro < tamanhoTabuleiro) {

                    if (tabuleiro[linhaTabuleiro][colunaTabuleiro] == 0) {
                        tabuleiro[linhaTabuleiro][colunaTabuleiro] = 5;
                    }
                }
            }
        }

        // Sobrepõe a habilidade Octaedro ao tabuleiro.
        for (linha = 0; linha < tamanhoHabilidade; linha++) {
            for (coluna = 0; coluna < tamanhoHabilidade; coluna++) {
                int linhaTabuleiro = origemOctaedroLinha + linha - 2;
                int colunaTabuleiro = origemOctaedroColuna + coluna - 2;

                if (octaedro[linha][coluna] == 1 &&
                    linhaTabuleiro >= 0 && linhaTabuleiro < tamanhoTabuleiro &&
                    colunaTabuleiro >= 0 && colunaTabuleiro < tamanhoTabuleiro) {

                    if (tabuleiro[linhaTabuleiro][colunaTabuleiro] == 0) {
                        tabuleiro[linhaTabuleiro][colunaTabuleiro] = 5;
                    }
                }
            }
        }

        if (posicaoValida == 1) {
            printf("Tabuleiro com Navios e Habilidades:\n\n");

            // Exibe o tabuleiro completo usando loops aninhados.
            // 0 representa água, 3 representa navio e 5 representa área afetada.
            for (linha = 0; linha < tamanhoTabuleiro; linha++) {
                for (coluna = 0; coluna < tamanhoTabuleiro; coluna++) {
                    printf("%d ", tabuleiro[linha][coluna]);
                }
                printf("\n");
            }

            printf("\nMatriz da Habilidade Cone:\n");
            for (linha = 0; linha < tamanhoHabilidade; linha++) {
                for (coluna = 0; coluna < tamanhoHabilidade; coluna++) {
                    printf("%d ", cone[linha][coluna]);
                }
                printf("\n");
            }

            printf("\nMatriz da Habilidade Cruz:\n");
            for (linha = 0; linha < tamanhoHabilidade; linha++) {
                for (coluna = 0; coluna < tamanhoHabilidade; coluna++) {
                    printf("%d ", cruz[linha][coluna]);
                }
                printf("\n");
            }

            printf("\nMatriz da Habilidade Octaedro:\n");
            for (linha = 0; linha < tamanhoHabilidade; linha++) {
                for (coluna = 0; coluna < tamanhoHabilidade; coluna++) {
                    printf("%d ", octaedro[linha][coluna]);
                }
                printf("\n");
            }
        } else {
            printf("Erro: os navios se sobrepoem.\n");
        }
    } else {
        printf("Erro: posicionamento invalido dos navios.\n");
    }

    return 0;
}