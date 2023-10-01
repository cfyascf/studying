#include <stdio.h>
#include <stdlib.h>
#define QTD 2

struct pessoa{
    char nome[50];
    int idade;
};

int main(){

    struct pessoa *p = (struct pessoa * ) malloc (QTD * sizeof(struct pessoa));

    for(int i = 0; i < QTD; i++){
        printf("Insira nome de p%d: ", i+1);
        scanf(" %s", p[i].nome);

        printf("Insira idade de p%d: ", i+1);
        scanf("%d", &p[i].idade);
    }

    for(int i = 0; i < QTD; i++){
        printf("p%d nome: %s\n", i+1, p[i].nome);

        printf("p%d idade: %d\n", i+1, p[i].idade);
    }

    return 0;
}