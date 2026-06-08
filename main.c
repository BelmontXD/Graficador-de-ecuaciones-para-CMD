#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <math.h>


#include "./interpolador/interpolador.c"
#include "./lib_memoria/memorias_dinamicas.c"
#include "./ecuaciones/ecuaciones.c"


float maximo_numero(float** arreglo, int cantidad)
{
	float maximo = arreglo[0][1];

	for (int i=0; i<cantidad; i++){	
		if(arreglo[i][1] > maximo){
			maximo = arreglo[i][1];
		}
	}
	return maximo;
}

float minimo_numero(float** arreglo, int cantidad)
{
	float minimo = arreglo[0][1];

	for (int i=0; i<cantidad; i++){
		if(arreglo[i][1] < minimo){
			minimo = arreglo[i][1];
		}
	}
	return minimo;
}



int main (){

	//Debo poner memoria dinammica
	//float n1, n2, n3, formula;
	//int desde, hasta, cantidad;
//
	//n1 = 2;
	//n2 = 9;
	//n3 = 10;
//
	//desde = -13;
	//hasta = 10;
	//cantidad = hasta - desde + 1;


	//primer_grado ecuacion = ecuacion_primer_grado(4, 10, -13, 10);
	//segundo_grado ecuacion = ecuacion_segundo_grado(2, 9, 10, -13, 10);
	tercer_grado ecuacion = ecuacion_tercer_grado(2, 3, -11, 6, -5, 5);
	float **arreglo = ecuacion.matriz; // Puntero a la matriz de la ecuacion

	imprimir_matriz_float(arreglo, ecuacion.matriz_filas,  ecuacion.matriz_columnas);
	
	int cantidad = ecuacion.cantidad;
	
	printf("Cantidad: %d", ecuacion.cantidad);



	//Se busca el numero mas grande del arreglo
	int max = abs((int)round(maximo_numero(arreglo, ecuacion.cantidad)));
	int min = abs((int)round(minimo_numero(arreglo, ecuacion.cantidad)));

	


	printf("\nMaximo numero: %d\n", max);
	printf("\nMinimo numero: %d\n", min);


	//Se imprimen los valores del arreglo
	int i = 0;
	puts("  x  | y ");
	
	for (int i = 0; i<ecuacion.cantidad; i++){
		printf("%d. [ %d , %f ] \n", i, (int)arreglo[i][0], arreglo[i][1]);
	}
	
	puts("");
	

	//Creamos el buffer de la grafica para ser impresa
	//char buffer[max][cantidad];
	char **buffer = crear_matriz_char(max+min, cantidad); // Ahora funciona con memoria dinamica

	printf("Se supone que se creo el buffer max: %d cantidad: %d\n", max, cantidad);
	
	
	//Limpieza de datos basura
	for (int y= 0; y<max; y++){
		for (int x= 0; x<cantidad; x++){
			buffer[y][x] = ' ';					
		}
	}


	
	//Llenando Buffer:

	
	for (int i=0; i<cantidad; i++){
		int elemento = (round(arreglo[i][1])+min)-1;

		if (elemento < 0) {
			elemento = 0;
		}

		//printf("Elemento: %d\n", elemento);
		buffer[elemento][i] = 219;
		//printf("Elemento impreso: %c\n", buffer[elemento][i]);
		//printf("Posicion en x: %d [%d] -> %f]\n", i, (int)arreglo[i][1], arreglo[i][1]);

		
	}

	


	
	//Interpolar valores: //y1: 120 y y2: 91:
	
	
	for (int i=0; i<ecuacion.cantidad; i++){
		if (i+2 > ecuacion.cantidad){
			break;
		}
		else{

			float x1 = arreglo[i][0];
			float y1 = arreglo[i][1];
			
			float x2 = arreglo[i+1][0];
			float y2 = arreglo[i+1][1];

						

			int cant_intervalos = abs((int)((y1-y2)-1));


			printf("Valores -> x1: %.1f, y1: %.1f | x2: %.1f, y2: %.1f\n", x1, y1, x2, y2);

			float *sub_lista_interpolados = interpolador('y', cant_intervalos, x1, y1, x2, y2);


			printf("Cantidad de intervalos: %d\n", cant_intervalos);
			printf("%d. Sub lista interpolados entre: y1: %d y y2: %d:\n", i, (int)y1, (int)y2);
			for (int j = 0; j<cant_intervalos; j++){
				//printf("y[%d]: %.3f", j, sub_lista_interpolados[j] );

				int elemento = abs((round(sub_lista_interpolados[j])+min)-1);
				// 		int elemento = (round(arreglo[i][1])+min)-1;
				printf("Elemento: %d\n", elemento);


				buffer[elemento][i] = 219; //Aquí llenamos el buffer
				//printf(" <-- Elemento puesto en matriz ( %d , %d )\n", (int)sub_lista_interpolados[j], i);
			}
			//puts("--------------------------------");
			//getch();
			free(sub_lista_interpolados);
			sub_lista_interpolados = NULL;


			//printf("Posicion en x: %d [%d] -> %f]\n", i, (int)arreglo[i][1], arreglo[i][1]);
		}
	}	
	
	//Graficador:
	char max_str[50];
	sprintf(max_str, "%d", max);
	for (int y = max-1; y >=0; y--){
	
		printf("%0*d.   ", strlen(max_str),y);
		for (int x = 0; x<ecuacion.cantidad-1; x++){
			printf("%c%c", buffer[y][x], buffer[y][x]);
		}
		puts("");
	}

	liberar_matriz(arreglo, ecuacion.matriz_filas);
	liberar_matriz_char(buffer, max);

	return 0;
}
