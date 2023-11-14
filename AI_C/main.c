#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readata.h>

#define INPUT_SIZE 784
#define TRAIN_COUNT_DELTA 100
#define TRAIN_COUNT_BPP 100

typedef struct Neuron_t{
    float weight;
    float dweight;
    float error;
    float bias;
    float output;
    float input[INPUT_SIZE];
} Neuron;

int neurons_in = 72;
int neurons_hn = 16;
int neurons_out = 9;

Neuron *layer_1 = malloc(neurons_in * sizeof(Neuron));
Neuron *layer_2 = malloc(neurons_hn * sizeof(Neuron));
Neuron *layer_3 = malloc(neurons_hn * sizeof(Neuron));
Neuron *layer_4 = malloc(neurons_out * sizeof(Neuron));

float reLU(double x) {
    return (x > 0) ? x : 0;
}

float rand_float() {
  return (float)rand() / (float)RAND_MAX;
}

void initializeLayer(Neuron *layer, int num_neurons){
    for(int i = 0; i < num_neurons; i++){
        layer[i].weight = rand_float();
        layer[i].bias = rand_float();
        layer[i].dweight = 0.0;
    }
}

void setInputInLayer(Neuron *layer, int num_neurons, int image, int data[][INPUT_SIZE]){
    for(int i = 0; i < num_neurons; i++){
        for(int j = 1; j < INPUT_SIZE; j++){
            layer[i].input[j] = data[image][j];
        }
    }
}

void setInputHnLayer(Neuron *layer, Neuron *layer_2, int num_neurons, int num_neurons2){
    for(int i = 0; i < num_neurons; i++){
        for(int j = 0; j < num_neurons2; j++){
            layer[i].input[j] = layer_2[j].output;
        }
    }
}

void feedForward(Neuron *layer, int num_neurons){
    for(int i = 0; i < num_neurons; i++){
        double weightedSum = layer[i].bias;

        for(int j = 0; j < INPUT_SIZE; j++){
            weightedSum += layer[i].input[j] * layer[i].weight;
        }
        layer[i].output = reLU(weightedSum);
    }
}

float costLayer(Neuron *layer, int num_neurons, int image, int data[][INPUT_SIZE]) {
    double expected_output = data[image][0];
    double final_cost = 0.0;

    for(int i = 0; i < num_neurons; i++){
        double final_cost += expected_output - layer[i].output;
    }

    final_cost /= num_neurons;

  return final_cost * final_cost;
}

float costOverall(int image, int data){
    double cost1 = costFunctionLayer(layer_1, neurons_in, image, data);
    double cost2 = costFunctionLayer(layer_2, neurons_hn, image, data);
    double cost3 = costFunctionLayer(layer_3, neurons_hn, image, data);
    double cost4 = costFunctionLayer(layer_4, neurons_out, image, data);

    return (cost1 + cost2 + cost3 + cost4) / 4;
}

void backpropagation(int image, int data[][INPUT_SIZE]){
    double rate = 1e-6;
    double eps = 1e-6;
    float expected_output = data[image][0];

    for(int i = 0; i < TRAIN_COUNT_DELTA; i++){

        // calculatin deltas
        for(int j = 0; j < neurons_in; j++){
            layer_1[j].error = expected_output - layer_1[j].output;
            layer_1[j].dweight = -layer_1[j].error * reLU(layer_1[j].output) * (1.0 - reLU(layer_1[j].output));
        }

        for(int j = 0; j < neurons_hn; j++){
            layer_2[j].error = layer_1[j].dweight - layer_2[j].weight;
            layer_2[j].dweight = layer_2[j].error * (1.0 + layer_2[j].output) * (1.0 - layer_2[j].output);
        }

        for(int j = 0; j < neurons_hn; j++){
            layer_3[j].error = layer_2[j].dweight - layer_3[j].weight;
            layer_3[j].dweight = layer_3[j].error * (1.0 + layer_3[j].output) * (1.0 - layer_3[j].output);
        }

        for(int j = 0; j < neurons_out; j++){
            layer_4[j].error = expected_output - layer_4[j].output;
            layer_4[j].dweight = -layer_4[j].error * reLU(layer_4[j].output) * (1.0 - reLU(layer_4[j].output));
        }

        // aplying deltas
        for(int j = 0; j < neurons_in; j++){
            layer_1[j].weight += layer_1[j].dweight * rate;
        }

        for(int j = 0; j < neurons_hn; j++){
            layer_2[j].weight += layer_2[j].dweight * rate;
        }

        for(int j = 0; j < neurons_hn; j++){
            layer_3[j].weight += layer_3[j].dweight * rate;
        }

        for(int j = 0; j < neurons_out; j++){
            layer_4[j].weight += layer_4[j].dweight * rate;
        }
    }
}

int main(void){

    // gettin data
    FILE * file;
    file = fopen("mnist_train.csv", "r");
    if(file == NULL){
        printf("Error opening file\\\n");
        return 1;
    }

    int **data = NULL;
    int num_lines = 0;

    read_data(file, &data, &num_lines);
    fclose(file);

    // ai
    initializeLayer(layer_1, neurons_in);
    initializeLayer(layer_2, neurons_hn);
    initializeLayer(layer_3, neurons_hn);   
    initializeLayer(layer_4, neurons_out);

    for(int image = 0; image < 1; image++){

        setInputInLayer(layer_1, neurons_in, data, image);
        setInputHnLayer(layer_2, layer_1, neurons_hn, neurons_in);
        setInputHnLayer(layer_3, layer_2, neurons_hn, neurons_hn);
        setInputHnLayer(layer_4, layer_3, neurons_hn, neurons_out);

        for(int i = 0; i < TRAIN_COUNT_BPP; i++){
            feedForward(layer_1, neurons_in);
            feedForward(layer_2, neurons_hn);
            feedForward(layer_3, neurons_hn);
            feedForward(layer_3, neurons_out);

            backpropagation(image, data);

            printf("Cost: %lld\n", costOverall(image, data));
        }

        for(int i = 0; i < neurons_hn; i++){
            printf("%d_NEURON %f\n", i + 1, layer_4[i].output);
        }
    }

    return 0;
}