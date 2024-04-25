#include <stdio.h>

#define TAMANHO_TABULEIRO 8

typedef enum {
    PEAO,
    BISPO,
    CAVALO,
    TORRE,
    RAINHA,
    REI
} TipoPeca;

typedef enum {
    PRETO,
    BRANCO
} CorPeca;

void inicializarTabuleiro(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    // Inicializa o tabuleiro com espaços vazios
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = 'X';
        }
    }
}

void adicionarPeca(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], TipoPeca tipo, CorPeca cor, int coluna, int linha) {
    char prefixo = (cor == BRANCO) ? 'B' : 'P';
    char peca;
    
    switch (tipo) {
        case PEAO:
            peca = 'P';
            break;
        case BISPO:
            peca = 'B';
            break;
        case CAVALO:
            peca = 'C';
            break;
        case TORRE:
            peca = 'T';
            break;
        case RAINHA:
            peca = 'D'; // D de "Dama" para o equivalente à Rainha
            break;
        case REI:
            peca = 'R';
            break;
    }
    
    tabuleiro[linha][coluna] = prefixo;
    tabuleiro[linha][coluna + 1] = peca;
}

void imprimirTabuleiro(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("   a b c d e f g h\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%d ", 8 - i);
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%c ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    inicializarTabuleiro(tabuleiro);
    
    // Adiciona peças pretas
    adicionarPeca(tabuleiro, REI, PRETO, 4, 0); // Rei preto em uma casa preta
    adicionarPeca(tabuleiro, RAINHA, PRETO, 3, 0);
    adicionarPeca(tabuleiro, TORRE, PRETO, 0, 0);
    adicionarPeca(tabuleiro, TORRE, PRETO, 7, 0);
    adicionarPeca(tabuleiro, CAVALO, PRETO, 1, 0);
    adicionarPeca(tabuleiro, CAVALO, PRETO, 6, 0);
    adicionarPeca(tabuleiro, BISPO, PRETO, 2, 0);
    adicionarPeca(tabuleiro, BISPO, PRETO, 5, 0);
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        adicionarPeca(tabuleiro, PEAO, PRETO, i, 1);
    }
    
    // Adiciona peças brancas
    adicionarPeca(tabuleiro, REI, BRANCO, 4, 7); // Rei branco em uma casa branca
    adicionarPeca(tabuleiro, RAINHA, BRANCO, 3, 7);
    adicionarPeca(tabuleiro, TORRE, BRANCO, 0, 7);
    adicionarPeca(tabuleiro, TORRE, BRANCO, 7, 7);
    adicionarPeca(tabuleiro, CAVALO, BRANCO, 1, 7);
    adicionarPeca(tabuleiro, CAVALO, BRANCO, 6, 7);
    adicionarPeca(tabuleiro, BISPO, BRANCO, 2, 7);
    adicionarPeca(tabuleiro, BISPO, BRANCO, 5, 7);
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        adicionarPeca(tabuleiro, PEAO, BRANCO, i, 6);
    }
    
    imprimirTabuleiro(tabuleiro);
    
    return 0;
}
