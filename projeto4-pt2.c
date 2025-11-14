#include <stdio.h>

#define TAMANHO 10
#define TAMANHO_NAVIO 3

int main() {
    int tabuleiro[TAMANHO][TAMANHO];
    int i, j;
    
    // Inicializar tabuleiro com água (0)
    for (i = 0; i < TAMANHO; i++) {
        for (j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = 0;
        }
    }
    
    // Navio 1: Horizontal (linha 1, coluna 1)
    for (j = 1; j < 1 + TAMANHO_NAVIO; j++) {
        tabuleiro[1][j] = 3;
    }
    
    // Navio 2: Vertical (linha 4, coluna 4)
    for (i = 4; i < 4 + TAMANHO_NAVIO; i++) {
        tabuleiro[i][4] = 3;
    }
    
    // Navio 3: Diagonal ↘ (linha 7, coluna 1)
    for (i = 0; i < TAMANHO_NAVIO; i++) {
        if (7 + i < TAMANHO && 1 + i < TAMANHO) {
            tabuleiro[7 + i][1 + i] = 3;
        }
    }
    
    // Navio 4: Diagonal ↙ (linha 2, coluna 7)
    for (i = 0; i < TAMANHO_NAVIO; i++) {
        if (2 + i < TAMANHO && 7 - i >= 0) {
            tabuleiro[2 + i][7 - i] = 3;
        }
    }
    
    // Exibir tabuleiro
    printf("=== BATALHA NAVAL - NIVEL AVENTUREIRO ===\n\n");
    printf("Legenda: 0=Agua, 3=Navio\n\n");
    
    for (i = 0; i < TAMANHO; i++) {
        for (j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}