#include <stdio.h>

// Nível Novato - Movimentação das Peças
// Declaração de variáveis constantes para a movimentação
#define MAX_TABULEIRO 8  // Tabuleiro de xadrez 8x8

// Função para imprimir o tabuleiro (para visualização)
void imprimirTabuleiro(char tabuleiro[MAX_TABULEIRO][MAX_TABULEIRO]) {
    for (int i = 0; i < MAX_TABULEIRO; i++) {
        for (int j = 0; j < MAX_TABULEIRO; j++) {
            printf("%c ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Implementação de Movimentação do Bispo (diagonal)
void moverBispo(int x, int y, char tabuleiro[MAX_TABULEIRO][MAX_TABULEIRO]) {
    printf("\nMovimentando o Bispo a partir de (%d, %d)\n", x, y);

    // Movimentação do Bispo nas 4 diagonais
    for (int i = 1; i < MAX_TABULEIRO; i++) {
        // Diagonal superior esquerda
        if (x - i >= 0 && y - i >= 0) tabuleiro[x - i][y - i] = 'B';

        // Diagonal superior direita
        if (x - i >= 0 && y + i < MAX_TABULEIRO) tabuleiro[x - i][y + i] = 'B';

        // Diagonal inferior esquerda
        if (x + i < MAX_TABULEIRO && y - i >= 0) tabuleiro[x + i][y - i] = 'B';

        // Diagonal inferior direita
        if (x + i < MAX_TABULEIRO && y + i < MAX_TABULEIRO) tabuleiro[x + i][y + i] = 'B';
    }
}

// Implementação de Movimentação da Torre (vertical e horizontal)
void moverTorre(int x, int y, char tabuleiro[MAX_TABULEIRO][MAX_TABULEIRO]) {
    printf("\nMovimentando a Torre a partir de (%d, %d)\n", x, y);

    // Movimentação da Torre para cima
    for (int i = x - 1; i >= 0; i--) tabuleiro[i][y] = 'T';

    // Movimentação da Torre para baixo
    for (int i = x + 1; i < MAX_TABULEIRO; i++) tabuleiro[i][y] = 'T';

    // Movimentação da Torre para a esquerda
    for (int i = y - 1; i >= 0; i--) tabuleiro[x][i] = 'T';

    // Movimentação da Torre para a direita
    for (int i = y + 1; i < MAX_TABULEIRO; i++) tabuleiro[x][i] = 'T';
}

// Implementação de Movimentação da Rainha (combinando Torre e Bispo)
void moverRainha(int x, int y, char tabuleiro[MAX_TABULEIRO][MAX_TABULEIRO]) {
    printf("\nMovimentando a Rainha a partir de (%d, %d)\n", x, y);

    // Movimentação como Torre
    moverTorre(x, y, tabuleiro);

    // Movimentação como Bispo
    moverBispo(x, y, tabuleiro);
}

// Nível Aventureiro - Movimentação do Cavalo
void moverCavalo(int x, int y, char tabuleiro[MAX_TABULEIRO][MAX_TABULEIRO]) {
    printf("\nMovimentando o Cavalo a partir de (%d, %d)\n", x, y);

    // Movimentação do Cavalo em L
    int movimentos[8][2] = {
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1},
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1}
    };

    for (int i = 0; i < 8; i++) {
        int novoX = x + movimentos[i][0];
        int novoY = y + movimentos[i][1];
        if (novoX >= 0 && novoX < MAX_TABULEIRO && novoY >= 0 && novoY < MAX_TABULEIRO) {
            tabuleiro[novoX][novoY] = 'C';
        }
    }
}

// Função principal
int main() {
    char tabuleiro[MAX_TABULEIRO][MAX_TABULEIRO];

    // Inicializa o tabuleiro com '.' para representar as casas vazias
    for (int i = 0; i < MAX_TABULEIRO; i++) {
        for (int j = 0; j < MAX_TABULEIRO; j++) {
            tabuleiro[i][j] = '.';
        }
    }

    // Definindo posições iniciais
    int xBispo = 4, yBispo = 4; // Exemplo: Bispo na posição (4, 4)
    int xTorre = 2, yTorre = 3;  // Exemplo: Torre na posição (2, 3)
    int xRainha = 6, yRainha = 6; // Exemplo: Rainha na posição (6, 6)
    int xCavalo = 1, yCavalo = 1; // Exemplo: Cavalo na posição (1, 1)

    // Movimentando as peças
    moverBispo(xBispo, yBispo, tabuleiro);
    moverTorre(xTorre, yTorre, tabuleiro);
    moverRainha(xRainha, yRainha, tabuleiro);
    moverCavalo(xCavalo, yCavalo, tabuleiro);

    // Imprimir tabuleiro após movimentações
    imprimirTabuleiro(tabuleiro);

    return 0;
}

