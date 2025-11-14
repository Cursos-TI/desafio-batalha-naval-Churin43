#include <stdio.h>

#define TAM 10      // tamanho do tabuleiro (10x10)
#define NAVIO 3     // tamanho dos navios (3 posições)
#define AGUA 0      //representa água
#define NAV 3       // navio no tabuleiro

int main() {

    int tabuleiro[TAM][TAM];


    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    int linhaH = 2;
    int colunaH = 4;


    int linhaV = 5;
    int colunaV = 1;


    int validoH = (colunaH + NAVIO <= TAM); // limite horizontal
    int validoV = (linhaV + NAVIO <= TAM);  //  limite vertical

    if (!validoH || !validoV) {
        printf("Erro: Navio fora dos limites do tabuleiro.\n");
        return 1; 
    }


    int sobrepoe = 0;


    for (int i = 0; i < NAVIO; i++) {
        if (tabuleiro[linhaH][colunaH + i] == NAV)
            sobrepoe = 1;
    }


    for (int i = 0; i < NAVIO; i++) {
        if (tabuleiro[linhaV + i][colunaV] == NAV)
            sobrepoe = 1;
    }

    if (sobrepoe) {
        printf("Erro: Navios se sobrepõem.\n");
        return 1;
    }


    for (int i = 0; i < NAVIO; i++) {
        tabuleiro[linhaH][colunaH + i] = NAV;
    }

    for (int i = 0; i < NAVIO; i++) {
        tabuleiro[linhaV + i][colunaV] = NAV;
    }


    printf("\nTABULEIRO\n");

    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
