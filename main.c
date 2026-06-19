#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <math.h>


//#include "./trigonometria/trigonometricas.h"
#include "./interpolador/interpolador.c"
#include "./interpolador/bresenham.c"
#include "./lib_memoria/memorias_dinamicas.c"
#include "./ecuaciones/ecuaciones.c"

struct_ecuacion menu(){
	
	int opcion = 0;
	struct_ecuacion ecuacion;

	while (1){
		system("cls");
		puts("####  GRAFICADOR PARA CMD  ####\n");
		puts("Figuras a graficar:");
		puts("\t(1). Ecuacion de 1er grado y = mx + b (/)");
		puts("\t(2). Ecuacion de 2do grado ax^2 + bx + c = 0 (U)");
		puts("\t(3). Ecuacion de 3er grado ax^3 + bx^2 + cx + d (S)"); 
		puts("\t(4). Circulo"); 

		printf("\nEscoje tu opcion (del 1 al 4): ");
		scanf("%d", &opcion);
		if (opcion >= 1 && opcion <= 4){
			switch (opcion) {

				case 1:
					puts("Ecuacion de 1er grado escogida!");
					ecuacion = crear_ecuacion(1, 4, 10, 0, 0, -13, 10);
					
					break;
				case 2:
					puts("Ecuacion de 2do grado escogida!");
					ecuacion = crear_ecuacion(2, 2, 9, 10, 0, -13, 10);
					break;
				case 3:
					puts("Ecuacion de 3er grado escogida!");
					ecuacion = crear_ecuacion(3, 2, 3, -11, 6, -5, 5);
					break;
				case 4:
					puts("Circulo!");
					ecuacion = crear_circulo(0, 0, 20);
					break;

			}

			//printf("Seleccion: %d\n", opcion);
			break;
		} else {
			puts("Opcion errada... \nPresione una tecla para continuar");
			getch();
		}
	}
	return ecuacion;
}


float maximo_numero(float** arreglo, int cantidad_h, int columna)
{
	float maximo = arreglo[0][columna];

	for (int i=0; i<cantidad_h; i++){	
		if(arreglo[i][columna] > maximo){
			maximo = arreglo[i][columna];
		}
	}
	return maximo;
}

float minimo_numero(float** arreglo, int cantidad_h, int columna)
{

	//puts("Funcion numero minimo");
	float minimo = arreglo[0][columna];
	
	for (int i=0; i<cantidad_h; i++){
		//printf("Evaluando numero: %f\n", arreglo[i][1]);
		if(arreglo[i][columna] < minimo){
			minimo = arreglo[i][columna];
			//printf("Minimo actual: %f\n", minimo);
		}
	}
	return minimo;
}



int main (){

	struct_ecuacion ecuacion = menu();
	float **arreglo = ecuacion.matriz; // Puntero a la matriz de la ecuacion

	imprimir_matriz_float(arreglo, ecuacion.matriz_filas,  ecuacion.matriz_columnas);
	
	int cantidad_h = ecuacion.cantidad;
	
	//printf("Cantidad_h: %d", ecuacion.cantidad_h);



	//Se busca el numero mas grande del arreglo
	int max_x = abs((int)round(maximo_numero(arreglo, ecuacion.matriz_filas, 0)));
	int min_x = abs((int)round(minimo_numero(arreglo, ecuacion.matriz_filas, 0)));
	int max_y = abs((int)round(maximo_numero(arreglo, ecuacion.matriz_filas, 1)));
	int min_y = abs((int)round(minimo_numero(arreglo, ecuacion.matriz_filas, 1)));

	int cantidad_v = max_y+min_y;

	//printf("\nMaximo numero en valores x: %d\n", max_x);
	//printf("\nMinimo numero en valores x: %d\n", min_x);

	//printf("\nMaximo numero en valores y: %d\n", max_y);
	//printf("\nMinimo numero en valores y: %d\n", min_y);

	//printf("Cantidad_h x: %d\n", cantidad_h);


	int i = 0;

	//Creamos el buffer de la grafica para ser impresa
	//char buffer[max][cantidad_h];
	if (cantidad_h == cantidad_v){
		cantidad_h++;
		cantidad_v++;
	}
	char **buffer = crear_matriz_char(cantidad_v, cantidad_h); // Ahora funciona con memoria dinamica

	//printf("Se supone que se creo el buffer cantidad_v: %d cantidad_h: %d\n", cantidad_v, cantidad_h);
	
	
	//Limpieza de datos basura
	for (int y= 0; y<cantidad_v; y++){
		for (int x= 0; x<cantidad_h; x++){
			buffer[y][x] = ' ';					
		}
	}


	
	//Llenando Buffer y union de coordenadas:

		
	for (int i=0; i<ecuacion.matriz_filas; i++){

		if (i+2 > ecuacion.matriz_filas){
			break;
		} else {

			int elemento_x = (round(arreglo[i][0])+min_x);
			int elemento_y = (round(arreglo[i][1])+min_y);
			int elemento_x2 = (round(arreglo[i+1][0])+min_x);
			int elemento_y2 = (round(arreglo[i+1][1])+min_y);

			if (cantidad_h != cantidad_v){
				elemento_x--;
				elemento_y--;

			}

			if (elemento_x < 0) {
				elemento_x = 0;
			}

			if (elemento_y < 0) {
				elemento_y = 0;
			}

			

			//printf("(%d) Elemento: %d\n", i, elemento);
			//buffer[elemento_y][elemento_x] = 219;

			

			if (cantidad_h != cantidad_v){
				elemento_x2--;
				elemento_y2--;
			}

			if (elemento_x2 < 0) {
				elemento_x2 = 0;
			}

			if (elemento_y2 < 0) {
				elemento_y2 = 0;
			}


			//printf("%d.\n", i);
			line(buffer, elemento_x, elemento_y, elemento_x2, elemento_y2);
		}


		//printf("\t Elemento impreso: %c\n", buffer[elemento][i]);
		//printf("\tSe ingreso a la posicion (%d, %d) el valor -> %c]\n", i, elemento, buffer[elemento][i]);

		
	}

	//Interpolador


	
	
	//Graficador:
	char max_str[50];
	sprintf(max_str, "%d", cantidad_v);
	for (int y = cantidad_v-1; y >=0; y--){
	
		printf("%0*d.   ", strlen(max_str),y);
		for (int x = 0; x<cantidad_h; x++){
			printf("%c%c", buffer[y][x], buffer[y][x]);
		}
		puts("");
	}

	liberar_matriz(arreglo, ecuacion.matriz_filas);
	liberar_matriz_char(buffer, cantidad_v);


	puts("\n\nPresione una tecla para cerrar...");
	getch();
	return 0;
}
