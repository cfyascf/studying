#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// or gate
    float train[][3] = {
        {0, 0, 0},
        {1, 0, 1},
        {0, 1, 1},
        {1, 1, 1},
    };

//gets the amount of elements on train
#define TRAIN_COUNT sizeof(train) / sizeof(train[0])

//gives a random number from 0 to 1
float rand_float(){
    return (float) rand() / (float) RAND_MAX;
}

//  how badly does my model perform?
float cost(float w1, float w2){
    float result = 0.0f;
    for(int i = 0; i < TRAIN_COUNT; i++){
        float x1 = train[i][0];
        float x2 = train[i][1];

        // y is the result coming from the input * the parameter
        float y = x1 * w1 + x2 * w2; 

        // distance between expected and actual
        float d = y - train[i][2];
        result += (d * d);
    }

    return result /= TRAIN_COUNT;
}

int main(){

    srand(time(NULL));
    // srand(69); 
    float eps = 1e-3;
    float rate = 1e-2;
    float w1 = rand_float();
    float w2 = rand_float();

    for(int i = 0; i < 1000; i++){
        float c = cost(w1, w2);

        printf("w1: %f / w2: %f / c: %f\n", w1, w2, c);

        float dw1 = (cost(w1 + eps, w2) - c) / eps;
        float dw2 = (cost(w1, w2 + eps) - c) / eps;

        dw1 -= rate * dw1;
        dw2 -= rate * dw2;
    }

    return 0;
}