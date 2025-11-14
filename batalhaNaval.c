#include <stdio.h>

#define TAM 10
#define NAVIO 3
#define AGUA 0
#define NAV 3
#define HAB 5

int posicao_livre(int tab[TAM][TAM], int coords[3][2]) {
    for (int i = 0; i < NAVIO; i++) {
        int lin = coords[i][0];
        int col = coords[i][1];
        if (tab[lin][col] == NAV) return 0;
    }
    return 1;
}

void posicionar(int tab[TAM][TAM], int coords[3][2]) {
    for (int i = 0; i < NAVIO; i++) {
        int lin = coords[i][0];
        int col = coords[i][1];
        tab[lin][col] = NAV;
    }
}

void aplicar_habilidade(int tab[TAM][TAM], int hab[5][5], int centroL, int centroC) {

    int offset = 5 / 2;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {

            if (hab[i][j] == 1) {
                int lin = centroL + (i - offset);
                int col = centroC + (j - offset);

                if (lin >= 0 && lin < TAM && col >= 0 && col < TAM) {
                    if (tab[lin][col] != NAV)
                        tab[lin][col] = HAB;
                }
            }
        }
    }
}

int main() {

    int tab[TAM][TAM];

    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            tab[i][j] = AGUA;

    int navio1[3][2] = { {2,1}, {2,2}, {2,3} };
    int navio2[3][2] = { {5,4}, {6,4}, {7,4} };
    int navio3[3][2] = { {1,1}, {2,2}, {3,3} };
    int navio4[3][2] = { {8,1}, {7,2}, {6,3} };

    int *navios[4] = { (int*)navio1, (int*)navio2, (int*)navio3, (int*)navio4 };

    for (int n = 0; n < 4; n++) {
        int (*nav)[2] = (int (*)[2])navios[n];

        if (!posicao_livre(tab, nav)) {
            printf("Erro: sobreposição de navios!\n");
            return 1;
        }

        posicionar(tab, nav);
    }

    int cone[5][5];
    int cruz[5][5];
    int octaedro[5][5];

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (j >= 2 - i && j <= 2 + i)
                cone[i][j] = 1;
            else
                cone[i][j] = 0;
        }
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (i == 2 || j == 2)
                cruz[i][j] = 1;
            else
                cruz[i][j] = 0;
        }
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int dist = abs(i - 2) + abs(j - 2);

            if (dist <= 2)
                octaedro[i][j] = 1;
            else
                octaedro[i][j] = 0;
        }
    }

    int centroConeL = 4, centroConeC = 4;
    int centroCruzL = 7, centroCruzC = 7;
    int centroOctL  = 1, centroOctC  = 8;

    aplicar_habilidade(tab, cone, centroConeL, centroConeC);
    aplicar_habilidade(tab, cruz, centroCruzL, centroCruzC);
    aplicar_habilidade(tab, octaedro, centroOctL, centroOctC);

    printf("\n TABULEIRO FINAL \n");

    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {

            if (tab[i][j] == AGUA) printf("0 ");
            else if (tab[i][j] == NAV) printf("3 ");
            else if (tab[i][j] == HAB) printf("5 ");
        }
        printf("\n");
    }

    return 0;
}
