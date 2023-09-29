#include <stdio.h>
#include <stdlib.h>

// Desenvolva um programa que calcule a soma de duas matrizes M x N de números reais (double). 
// A implementação deste programa deve considerar as dimensões fornecida pelo usuário.

int main(){

    double **matrizA, **matrizB;
    int colunas = 0, linhas = 0;

    printf("Insira o numero de colunas das matrizes: ");
    scanf("%d", &colunas);

    printf("Insira o numero de linhas das matrizes: ");
    scanf("%d", &linhas);


    printf("Insira valores para a matrizA:\n");
    matrizA = (double **) malloc (linhas * sizeof(double*));

    for(int i = 0; i < linhas; i++){
        matrizA[i] = (double *) malloc (colunas * sizeof(double));

        for(int j = 0; j < colunas; j++){
            scanf("%d", &matrizA[i][j]);
        }
    }

    printf("Insira valores para a matrizB:\n");
    matrizB = (double **) malloc (linhas * sizeof(double*));

    for(int i = 0; i < linhas; i++){
        matrizB[i] = (double *) malloc (colunas * sizeof(double));

        for(int j = 0; j < colunas; j++){
            scanf("%d", &matrizB[i][j]);
        }
    }


    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            printf(" %d |", matrizA[i][j]);
        }
        printf("\n");
    }

    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            printf(" %d |", matrizB[i][j]);
        }
        printf("\n");
    }

    

    return 0;
}