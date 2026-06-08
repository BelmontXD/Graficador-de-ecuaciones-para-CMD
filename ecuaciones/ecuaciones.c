#include <stdio.h>
//#include "../lib_memoria/memorias_dinamicas.c"



typedef struct {
    float a, b;
    int desde, hasta, cantidad;

    int matriz_filas, matriz_columnas;
    float **matriz;

} primer_grado;



typedef struct {
    float a, b, c;
    int desde, hasta, cantidad;

    int matriz_filas, matriz_columnas;
    float **matriz;

} segundo_grado;


typedef struct {
    float a, b, c, d;
    int desde, hasta, cantidad;

    int matriz_filas, matriz_columnas;
    float **matriz;

} tercer_grado;

int indices_iguales(int desde, int hasta){
    printf("ERROR: Indices de iteracion iguales... retornando cero");

    return 0;
}

primer_grado ecuacion_primer_grado(float a, float b, int desde, int hasta){
    primer_grado eq;

    eq.a = a;
	eq.b = b;
    eq.desde = desde;
	eq.hasta = hasta;
    eq.cantidad = eq.hasta - eq.desde + 1;
    eq.matriz_filas = eq.cantidad;
    eq.matriz_columnas = 2;

    eq.matriz = crear_matriz_float(eq.matriz_filas, eq.matriz_columnas);

    int i = 0;
	for (int x = eq.desde; x<=eq.hasta; x++){

		eq.matriz[i][1] = (eq.a * x) + (eq.b);
		eq.matriz[i][0] = x;
		i++;
	}

    //imprimir_matriz_float(eq.matriz, eq.cantidad, 2);   
    
    return eq;
}

segundo_grado ecuacion_segundo_grado(float a, float b, float c, int desde, int hasta){
    segundo_grado eq;

    eq.a = a;
	eq.b = b;
	eq.c = c;
    eq.desde = desde;
	eq.hasta = hasta;
    eq.cantidad = eq.hasta - eq.desde + 1;
    eq.matriz_filas = eq.cantidad;
    eq.matriz_columnas = 2;

    eq.matriz = crear_matriz_float(eq.matriz_filas, eq.matriz_columnas);

    int i = 0;
	for (int x = eq.desde; x<=eq.hasta; x++){

		eq.matriz[i][1] = ( eq.a * (x*x)) + (eq.b*x) + eq.c;
		eq.matriz[i][0] = x;
		i++;
	}

    //imprimir_matriz_float(eq.matriz, eq.cantidad, 2);   
    
    return eq;
}



tercer_grado ecuacion_tercer_grado(float a, float b, float c, float d, int desde, int hasta){
    tercer_grado eq;

    eq.a = a;
	eq.b = b;
	eq.c = c;
    eq.d = d;
    eq.desde = desde;
	eq.hasta = hasta;
    //if (eq.hasta )

    eq.cantidad = eq.hasta - eq.desde + 1;
    eq.matriz_filas = eq.cantidad;
    eq.matriz_columnas = 2;

    eq.matriz = crear_matriz_float(eq.matriz_filas, eq.matriz_columnas);

    int i = 0;
	for (int x = eq.desde; x<=eq.hasta; x++){

		eq.matriz[i][1] = ( eq.a * (x*x*x)) + (eq.b * (x*x)) + (eq.c * x) + eq.d;
		eq.matriz[i][0] = x;
		i++;
	}

    //imprimir_matriz_float(eq.matriz, eq.cantidad, 2);   
    
    return eq;
}
