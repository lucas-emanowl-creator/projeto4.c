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
    
    // Posicionar navio horizontal (linha 2, coluna 1)
    for (j = 1; j < 1 + TAMANHO_NAVIO; j++) {
        tabuleiro[2][j] = 3;
    }
    
    // Posicionar navio vertical (linha 5, coluna 5)
    for (i = 5; i < 5 + TAMANHO_NAVIO; i++) {
        tabuleiro[i][5] = 3;
    }
    
    // Exibir tabuleiro
    printf("=== BATALHA NAVAL - NIVEL NOVATO ===\n\n");
    printf("Legenda: 0=Agua, 3=Navio\n\n");
    
    for (i = 0; i < TAMANHO; i++) {
        for (j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}