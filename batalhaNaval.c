#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = 0; // 0 = água
        }
    }
}

int podePosicionarHorizontal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    if (coluna + TAMANHO_NAVIO > TAMANHO_TABULEIRO) return 0;
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linha][coluna + i] != 0) return 0;
    }
    return 1;
}

int podePosicionarVertical(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    if (linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO) return 0;
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linha + i][coluna] != 0) return 0;
    }
    return 1;
}

int podePosicionarDiagonalPrincipal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    if (linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO || coluna + TAMANHO_NAVIO > TAMANHO_TABULEIRO) return 0;
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linha + i][coluna + i] != 0) return 0;
    }
    return 1;
}

int podePosicionarDiagonalSecundaria(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    if (linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO || coluna - (TAMANHO_NAVIO - 1) < 0) return 0;
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linha + i][coluna - i] != 0) return 0;
    }
    return 1;
}

void posicionarNavioHorizontal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha][coluna + i] = 3;
    }
}

void posicionarNavioVertical(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha + i][coluna] = 3;
    }
}

void posicionarNavioDiagonalPrincipal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha + i][coluna + i] = 3;
    }
}

void posicionarNavioDiagonalSecundaria(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha + i][coluna - i] = 3;
    }
}

void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("\nTABULEIRO:\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    inicializarTabuleiro(tabuleiro);

    // Coordenadas dos navios
    int linhaH = 2, colunaH = 4;
    int linhaV = 5, colunaV = 1;
    int linhaDP = 0, colunaDP = 0; // Diagonal principal
    int linhaDS = 0, colunaDS = 9; // Diagonal secundária

    // Posicionar navio horizontal
    if (podePosicionarHorizontal(tabuleiro, linhaH, colunaH)) {
        posicionarNavioHorizontal(tabuleiro, linhaH, colunaH);
    } else {
        printf("Erro ao posicionar navio horizontal.\n");
    }

    // Posicionar navio vertical
    if (podePosicionarVertical(tabuleiro, linhaV, colunaV)) {
        posicionarNavioVertical(tabuleiro, linhaV, colunaV);
    } else {
        printf("Erro ao posicionar navio vertical.\n");
    }

    // Posicionar navio diagonal principal
    if (podePosicionarDiagonalPrincipal(tabuleiro, linhaDP, colunaDP)) {
        posicionarNavioDiagonalPrincipal(tabuleiro, linhaDP, colunaDP);
    } else {
        printf("Erro ao posicionar navio diagonal principal.\n");
    }

    // Posicionar navio diagonal secundária
    if (podePosicionarDiagonalSecundaria(tabuleiro, linhaDS, colunaDS)) {
        posicionarNavioDiagonalSecundaria(tabuleiro, linhaDS, colunaDS);
    } else {
        printf("Erro ao posicionar navio diagonal secundária.\n");
    }

    exibirTabuleiro(tabuleiro);

    return 0;
}
