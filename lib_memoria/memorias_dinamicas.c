#include <stdio.h>
#include <stdlib.h>

void imprimir_matriz_float(float **matriz, int filas, int columnas){
    
    for (int i = 0; i < filas; i++){
        printf("F#%d: ", i);
        for (int j = 0; j < columnas; j++){
            printf("%d. [%f] ", i, matriz[i][j]);
        }
        puts("");
    }
}

// Función para liberar la matriz
void liberar_matriz(float **matriz, int filas) {
    if (matriz == NULL) return;
    
    for (int i = 0; i < filas; i++) {
        free(matriz[i]);
    }
    free(matriz);
}

float** crear_matriz_float(int filas, int columnas){

    // 1. Asignar memoria para los punteros a filas
    float **matriz = (float**)calloc(filas, sizeof(float*));

    if (matriz == NULL) { //Esto si o se pudo asignar memoria dinamica
        printf("Error: No se pudo asignar memoria para el arreglo bidimencional\n");
        return NULL;
    }


    // 2. Asignar memoria para cada columna
    for (int i = 0; i < filas; i++) {
        matriz[i] = (float*)calloc(columnas, sizeof(float));
        if (matriz[i] == NULL) {
            // Liberar memoria ya asignada en caso de error
            for (int j = 0; j < i; j++) {
                free(matriz[j]);
            }
            free(matriz);
            return NULL;
        }
    }

    return matriz;
}