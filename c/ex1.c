#include <stdio.h>

int main(){

    int *vetor;

    vetor = (int *) malloc(5 * sizeof(int));

    for(int i = 0; i < 5; i++){
        printf("Insira um valor para um array: ");
        scanf("%d", &vetor[i]);
    }

    printf("Array inserido:\n");
    for(int i = 0; i < 5; i++){
        printf(" %d |", vetor[i]);
    }

    free(*vetor);

    printf("Array inserido:\n");
    for(int i = 0; i < 5; i++){
        printf(" %d |", vetor[i]);
    }


    return 0;
}