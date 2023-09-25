#include <stdio.h>

int calculaPotencia(int num, int exp){
    if(exp == 0){
        return 1;
    }

    return num * calculaPotencia(num, exp - 1);
}

void recebeDados(int *num, int *exp){
    printf("Insira um numero de base: ");
    scanf("%d", num);

    printf("Insira um numero de expoente: ");
    scanf("%d", exp);
}

void mostraResultado(int num, int exp){
    int resultado;
    resultado = calculaPotencia(num, exp);
    printf("%d elevado a %d eh %d\n", num, exp, resultado);
}

int main(){

    int num, exp;

    printf("\n--- CALCULADORA DE POTENCIA ---\n");
    printf("\n");

    while(1){
    recebeDados(&num, &exp);
    mostraResultado(num, exp);
    printf("\n");
    }

    return 0;
}