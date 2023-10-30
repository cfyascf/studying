#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// training data
    float train[5][2] = {
        {0, 0},
        {1, 2},
        {2, 4},
        {3, 6},
        {4, 8},
    };

//gets the amount of elements on train
#define TRAIN_COUNT sizeof(train) / sizeof(train[0])

//gives a random number from 0 to 1
float rand_float(){
    return (float) rand() / (float) RAND_MAX;
}

//  how badly does my model perform?
float cost(float w, float b){
    float result = 0.0f;
    for(int i = 0; i < TRAIN_COUNT; i++){
        float x = train[i][0];

        // y is the result coming from the input * the parameter
        float y = x * w + b; 

        // distance between expected and actual
        float d = y - train[i][1];
        result += (d * d);
    }

    return result /= TRAIN_COUNT;
}

int main(){

    srand(time(NULL));

    // random number from 0 to 10 
    float w = rand_float() * 10.0f;
    float b = rand_float() * 5.0f;
    float eps = 1e-3;
    float rate = 1e-3;
    

    printf("%f\n", cost(w, b));

    for(int i = 0; i < 500; i++){
    // finite difference
    float dw = (cost(w + eps, b) - cost(w, b)) / eps;
    float db = (cost(w, b + eps) - cost(w, b)) / eps;
    w -= rate * dw;
    b -= rate * db;
    printf("%f, %f, %f\n", cost(w, b), w, b);
    }

    printf("%f", w);

    return 0;
}