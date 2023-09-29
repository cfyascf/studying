#include <stdio.h>
#include <stdlib.h>

// Desenvolva um programa que calcule a soma de duas matrizes M x N de números reais (double). 
// A implementação deste programa deve considerar as dimensões fornecida pelo usuário.


void lerTamanho(int * linhas, int * colunas){
    printf("Insira o numero de linhas das matrizes: ");
    scanf("%d", linhas);

    printf("Insira o numero de colunas das matrizes: ");
    scanf("%d", colunas);
}

int main(){

    double **matrizA, **matrizB, **matrizSoma;
    int linhas = 0, colunas = 0;

    lerTamanho(&linhas, &colunas);

    printf("Insira valores para a matrizA:\n");
    matrizA = (double **) malloc (colunas * sizeof(double*));

    for(int i = 0; i < colunas; i++){
        matrizA[i] = (double *) malloc (linhas * sizeof(double));

        for(int j = 0; j < linhas; j++){
            scanf("%lf", &matrizA[i][j]);
        }
    }

    printf("Insira valores para a matrizB:\n");
    matrizB = (double **) malloc (colunas * sizeof(double*));

    for(int i = 0; i < colunas; i++){
        matrizB[i] = (double *) malloc (linhas * sizeof(double));

        for(int j = 0; j < linhas; j++){
            scanf("%lf", &matrizB[i][j]);
        }
    }

    ////////////////////////

    matrizSoma = (double **) malloc (colunas * sizeof(double*));

    for(int i = 0; i < colunas; i++){
        matrizSoma[i] = (double *) malloc (linhas * sizeof(double));

        for(int j = 0; j < linhas; j++){
            matrizSoma[i][j] = matrizA[i][j] + matrizB[i][j];
        }
    }

    printf("\n");
    printf("\n");

    printf("MatrizA\n");
    for(int i = 0; i < colunas; i++){
        for(int j = 0; j < linhas; j++){
            printf(" %lf |", matrizA[i][j]);
        }
        printf("\n");
    }

    printf("\n");
    printf("\n");

    printf("MatrizB\n");
    for(int i = 0; i < colunas; i++){
        for(int j = 0; j < linhas; j++){
            printf(" %lf |", matrizB[i][j]);
        }
        printf("\n");
    }

    printf("\n");
    printf("\n");

    printf("Matriz soma das matrizes:\n");
    for(int i = 0; i < colunas; i++){
        for(int j = 0; j < linhas; j++){
            printf(" %lf |", matrizSoma[i][j]);
        }
        printf("\n");
    }


    for(int i = 0; i < colunas; i++){
        free(matrizA[i]);
        free(matrizB[i]);
    }

    free(matrizA);
    free(matrizB);
    
    

    return 0;
}