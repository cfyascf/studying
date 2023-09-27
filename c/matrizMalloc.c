#include <stdio.h>
#include <stdlib.h>
#define TAMANHO 3

int main(){

    int **p;

    printf("Insira valores para uma matriz 3x3:\n");
    p = (int **) malloc (TAMANHO * sizeof(int) );

    for(int i = 0; i < TAMANHO; i++){
        p[i] = (int * ) malloc (TAMANHO * sizeof(int));

        for(int j = 0; j < TAMANHO; j++){
            scanf("%d", &p[i][j]);
        }
    }

    for(int i = 0; i < TAMANHO; i++){
        for(int j = 0; j < TAMANHO; j++){
            printf(" %d |", p[i][j]);
        }
        printf("\n");
    }

    return 0;
}