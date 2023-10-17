#include <stdio.h>
#include <stdlib.h>

typedef struct Carro_t{
    char modelo[50];
    char fabricante[50];
    char cor[50];
    int ano;
    float valor;
} Carro;

void recebeDados(Carro *veiculo, int qtd, FILE * list){

    for(int i = 0; i < qtd; i++){

        printf("\n / Veiculo %i / \n", i + 1);

        printf("Modelo: ");
        scanf(" %s", veiculo[i].modelo);

        printf("Fabricante: ");
        scanf(" %s", veiculo[i].fabricante);

        printf("Cor: ");
        scanf(" %s", veiculo[i].cor);

        printf("Ano: ");
        scanf("%d", &veiculo[i].ano);

        printf("Valor: ");
        scanf("%f", &veiculo[i].valor);

        fprintf(list, "\n / Veiculo %i / \n", i + 1);
        fprintf(list, "Modelo: %s\n", veiculo[i].modelo);
        fprintf(list, "Fabricante: %s\n", veiculo[i].fabricante);
        fprintf(list, "Cor: %s\n", veiculo[i].cor);
        fprintf(list, "Ano: %d\n", veiculo[i].ano);
        fprintf(list, "Valor: %f\n", veiculo[i].valor);
    }
}

void mostraDados(FILE * list){
    rewind(list);

    char buffer[100];
    while (fgets(buffer, sizeof(buffer), list) != NULL) {
        printf("%s", buffer);
    }
}


int main(){

    FILE * list;

    int qtd = 0;

    printf("Insira a quantidade de veiculos que deseja registrar: ");
    scanf("%d", &qtd);

    Carro *veiculo = (Carro *) malloc(qtd * sizeof(Carro));

    list = fopen("list.txt", "a+");

    if (list == NULL){
        printf("Problemas na abertura do arquivo\n");
        return;
    }

    recebeDados(veiculo, qtd, list);
    mostraDados(list);

    fclose(list);
    free(veiculo);

    return 0;
}