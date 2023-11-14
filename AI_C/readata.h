#ifndef READATA_H
#define READATA_H

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

    // reset file position
    fseek(file, 0, SEEK_SET);

    // filling data
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

#endif