#include <stdio.h>
#include <stdlib.h>  // Para a função abs()

#define TAMANHO 10
#define TAMANHO_NAVIO 3
#define TAMANHO_HABILIDADE 5

// Função para criar matriz de habilidade CONE
void criarCone(int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    int i, j;
    for (i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (j = 0; j < TAMANHO_HABILIDADE; j++) {
            // Forma de cone simples
            if (i == 0 && j == 2) {
                habilidade[i][j] = 1;  // Topo
            }
            else if (i == 1 && j >= 1 && j <= 3) {
                habilidade[i][j] = 1;
            }
            else if (i == 2 && j >= 0 && j <= 4) {
                habilidade[i][j] = 1;
            }
            else if (i == 3 && j >= 1 && j <= 3) {
                habilidade[i][j] = 1;
            }
            else if (i == 4 && j == 2) {
                habilidade[i][j] = 1;  // Base
            }
            else {
                habilidade[i][j] = 0;
            }
        }
    }
}

// Função para criar matriz de habilidade CRUZ
void criarCruz(int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    int i, j;
    for (i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (j = 0; j < TAMANHO_HABILIDADE; j++) {
            // Cruz: linha do meio + coluna do meio
            if (i == 2 || j == 2) {
                habilidade[i][j] = 1;
            } else {
                habilidade[i][j] = 0;
            }
        }
    }
}

// Função para criar matriz de habilidade OCTAEDRO (losango)
void criarOctaedro(int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    int i, j;
    int centro = 2;  // Centro para matriz 5x5
    
    for (i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (j = 0; j < TAMANHO_HABILIDADE; j++) {
            // Forma de losango
            int dist_vertical = abs(i - centro);
            int dist_horizontal = abs(j - centro);
            
            if (dist_vertical + dist_horizontal <= 2) {
                habilidade[i][j] = 1;
            } else {
                habilidade[i][j] = 0;
            }
        }
    }
}

// Função para aplicar habilidade no tabuleiro
void aplicarHabilidade(int tabuleiro[TAMANHO][TAMANHO], 
                      int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE], 
                      int linha_centro, int coluna_centro) {
    int i, j;
    int offset = TAMANHO_HABILIDADE / 2;  // 2 para matriz 5x5
    
    for (i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (j = 0; j < TAMANHO_HABILIDADE; j++) {
            int tab_linha = linha_centro - offset + i;
            int tab_coluna = coluna_centro - offset + j;
            
            // Verificar limites do tabuleiro
            if (tab_linha >= 0 && tab_linha < TAMANHO && 
                tab_coluna >= 0 && tab_coluna < TAMANHO) {
                // Só marca como habilidade se for água (0)
                // Para não sobrepor navios existentes
                if (habilidade[i][j] == 1 && tabuleiro[tab_linha][tab_coluna] == 0) {
                    tabuleiro[tab_linha][tab_coluna] = 5;
                }
            }
        }
    }
}

// Função para exibir matriz de habilidade
void exibirHabilidade(int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE], char* nome) {
    printf("%s:\n", nome);
    int i, j;
    for (i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (j = 0; j < TAMANHO_HABILIDADE; j++) {
            printf("%d ", habilidade[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    int tabuleiro[TAMANHO][TAMANHO];
    int cone[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int cruz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int octaedro[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int i, j;
    
    // Inicializar tabuleiro com água (0)
    for (i = 0; i < TAMANHO; i++) {
        for (j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = 0;
        }
    }
    
    // Posicionar navios (mantendo do nível anterior)
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
    
    // Criar habilidades
    criarCone(cone);
    criarCruz(cruz);
    criarOctaedro(octaedro);
    
    // Exibir matrizes de habilidades
    printf("=== MATRIZES DE HABILIDADE ===\n\n");
    exibirHabilidade(cone, "CONE");
    exibirHabilidade(cruz, "CRUZ");
    exibirHabilidade(octaedro, "OCTAEDRO");
    
    // Aplicar habilidades em posições que não sobreponham navios
    aplicarHabilidade(tabuleiro, cone, 8, 8);      // Cone no canto inferior direito
    aplicarHabilidade(tabuleiro, cruz, 3, 3);      // Cruz no centro
    aplicarHabilidade(tabuleiro, octaedro, 5, 5);  // Octaedro no meio
    
    // Ex