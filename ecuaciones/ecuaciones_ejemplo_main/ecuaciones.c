#include <stdio.h>
#include "../lib_memoria/memorias_dinamicas.c"




typedef struct {
    float a, b, c;
    int desde, hasta, cantidad;
    float **matriz;

} struct_segundo_grado;


int main(){
    struct_segundo_grado eq;

    eq.a = 2;
	eq.b = 9;
	eq.c = 10;
    eq.desde = -13;
	eq.hasta = 10;
    eq.cantidad = eq.hasta - eq.desde + 1;

    eq.matriz = crear_matriz_float(eq.cantidad, 2);

    imprimir_matriz_float(eq.matriz, eq.cantidad, 2);   
    

    liberar_matriz(eq.matriz, eq.cantidad);
    return 0;
}