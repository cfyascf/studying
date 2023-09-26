#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    char string[50], *stringcopy;
    int tamanho;

    printf("Insira uma string: ");
    scanf("%s", string);
    getchar();

    tamanho = strlen(string);
    printf("STRING: %s - sizeof: %d // strlen: %d\n", string, sizeof(string), tamanho);

    stringcopy = strdup(string);

    printf("STRINGCOPY: %s - sizeof: %d // strlen: %d\n", stringcopy, sizeof(stringcopy), strlen(stringcopy));

    free(stringcopy);
    return 0;
}