#include <stdio.h>
#include "trigonometricas.c"

int main (){

    float radio = 6;

    for (int teta = 0; teta <= 11; teta++){
        printf("X = %f  -   ", radio * coseno[teta]);
        printf("Y = %f\n", radio * seno[teta]);
    }

    return 0;
}