#include <stdio.h>
#include <stdlib.h>

void imprimir_matriz_float(float **matriz, int filas, int columnas){
    puts("\n(X , Y)\n");
    for (int i = 0; i < filas; i++){
        for (int j = 0; j < columnas; j++){
            printf("(%d , %d) [%f] ", j, i, matriz[i][j]);
        }
        puts("");
    }
}


void imprimir_matriz_char(char **matriz, int filas, int columnas){
    puts("\n(X , Y)\n");
    for (int i = 0; i < filas; i++){
        for (int j = 0; j < columnas; j++){
            printf("(%d , %d) [%c] ", j, i, matriz[i][j]);
        }
        puts("");
    }
}

// Función para liberar la matriz
void liberar_matriz(float **matriz, int filas) {
    puts("Proceso de limpiado");
    if (matriz == NULL) return;
    
    for (int i = 0; i < filas; i++) {
        free(matriz[i]);
    }
    free(matriz);

    puts("Memoria liberada");
}

void liberar_matriz_char(char **matriz, int filas) {
    puts("Proceso de limpiado");
    if (matriz == NULL) return;
    
    for (int i = 0; i < filas; i++) {
        free(matriz[i]);
    }
    free(matriz);

    puts("Memoria char liberada");
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



char** crear_matriz_char(int filas, int columnas){

    // 1. Asignar memoria para los punteros a filas
    char **matriz = (char**)calloc(filas, sizeof(char*));
    
    if (matriz == NULL) { //Esto si o se pudo asignar memoria dinamica
        printf("Error: No se pudo asignar memoria para el arreglo bidimencional\n");
        return NULL;
    }


    // 2. Asignar memoria para cada columna
    for (int i = 0; i < filas; i++) {
        matriz[i] = (char*)calloc(columnas, sizeof(char));
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