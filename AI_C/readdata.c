#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cols = 785;

void read_data(FILE *file, int ***data, int *num_lines) {
    char line[100];

    // conta qtd linhas
    while (fgets(line, sizeof(line), file)) {
        (*num_lines)++;
    }
    fseek(file, 0, SEEK_SET);

    *data = (int **)malloc(*num_lines * sizeof(int *));
    for (int i = 0; i < *num_lines; i++) {
        (*data)[i] = (int *)malloc(cols * sizeof(int));
    }

    // filling array data
    int i = 0;
    while (fgets(line, sizeof(line), file)) {
        char *token = strtok(line, ",");
        int j = 0;

        while (token != NULL && j < cols) {
            (*data)[i][j] = atoi(token);
            token = strtok(NULL, ",");
            j++;
        }
        i++;
    }
}

int main() {
    FILE *file = fopen("mnist_train.csv", "r+");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo\n");
        return 1;
    }

    int num_lines = 0;
    int **data = NULL;

    read_data(file, &data, &num_lines);

    fclose(file);

    // Para imprimir o conteúdo da matriz (apenas para fins de teste)
    for (int i = 0; i < 10; i++) {
        printf("%d ", data[i][0]);
    }

    // Libera a memória alocada para a matriz
    for (int i = 0; i < num_lines; i++) {
        free(data[i]);
    }
    free(data);

    return 0;
}
