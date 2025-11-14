#include <stdio.h>

#define TAM 10      // tamanho do tabuleiro 10x10
#define NAVIO 3     // tamanho dos navios (3 posições)
#define AGUA 0      //  água
#define NAV 3       // navio

int posicao_livre(int tab[TAM][TAM], int coords[3][2]) {
    for (int i = 0; i < NAVIO; i++) {
        int lin = coords[i][0];
        int col = coords[i][1];

        if (tab[lin][col] == NAV) {
            return 0; // posição ocupada -> não pode
        }
    }
    return 1; // todas livres
}


void posicionar(int tab[TAM][TAM], int coords[3][2]) {
    for (int i = 0; i < NAVIO; i++) {
        int lin = coords[i][0];
        int col = coords[i][1];
        tab[lin][col] = NAV;
    }
}

int main() {

    int tabuleiro[TAM][TAM];


    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }


    int navio1[3][2] = {
        {2, 1}, {2, 2}, {2, 3}
    };

    int navio2[3][2] = {
        {5, 4}, {6, 4}, {7, 4}
    };

    int navio3[3][2] = {
        {1, 1}, {2, 2}, {3, 3}
    };


    int navio4[3][2] = {
        {8, 1}, {7, 2}, {6, 3}
    };


    int *navios[4] = { (int*)navio1, (int*)navio2, (int*)navio3, (int*)navio4 };

    for (int n = 0; n < 4; n++) {
        int (*nav)[2] = (int (*)[2])navios[n];

        for (int i = 0; i < NAVIO; i++) {
            int lin = nav[i][0];
            int col = nav[i][1];

            if (lin < 0 || lin >= TAM || col < 0 || col >= TAM) {
                printf("Erro: coordenadas invalidas no navio %d\n", n+1);
                return 1;
            }
        }

        if (!posicao_livre(tabuleiro, nav)) {
            printf("Erro: sobreposicao detectada no navio %d\n", n+1);
            return 1;
        }

        posicionar(tabuleiro, nav);
    }


    printf("\nTABULEIRO FINAL\n");

    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
