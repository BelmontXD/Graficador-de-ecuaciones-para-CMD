#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <math.h>
#include "./interpolador/interpolador.c"
//#include <math.h>

float maximo_numero(float arreglo[][2], int cantidad)
{
	float maximo = arreglo[0][1];

	for (int i=0; i<cantidad; i++){
		if(arreglo[i][1] > maximo){
			maximo = arreglo[i][1];
		}
	}
	return maximo;
}



int main (){

	//Debo poner memoria dinammica
	float n1, n2, n3, formula;
	int desde, hasta, cantidad;

	n1 = 2;
	n2 = 9;
	n3 = 10;

	desde = -13;
	hasta = 10;
	cantidad = hasta - desde + 1;


	printf("Cantidad del array: %d \n", cantidad);

	

	float arreglo[cantidad][2]; //y | x     <--------- QUEDÉ AQUÍ, HAY QUE AVERIGUAR COMO MANEJAR MATRICES 2D


	
	int i = 0;
	for (int x = desde; x<=hasta; x++){

		arreglo[i][1] = ( n1 * (x*x)) + (n2*x) + n3;
		arreglo[i][0] = x;
		i++;
	}

	//Se busca el numero mas grande del arreglo
	int max = (int)maximo_numero(arreglo, cantidad);
	printf("\nMaximo numero: %d\n", max);


	//Se imprimen los valores del arreglo
	i = 0;
	puts("  x  | y ");
	/*for (int x = desde; x<=hasta; x++){
		printf("%d. [ %d , %f ]\n", i, x, arreglo[i]);
		i++;
	}*/

	for (int i = 0; i<cantidad; i++){
		printf("%d. [ %d , %f ] \n", i, (int)arreglo[i][0], arreglo[i][1]);
	}



	//DibuJAR ARREGLO

	/*for (int i=0; i< cantidad; i++){
		printf("%.1f ", arreglo[i]);
	}*/
	
	puts("");
	

	//Creamos el buffer de la grafica para ser impresa
	char buffer[max][cantidad];

	
	//Limpieza de datos basura
	for (int y= 0; y<max; y++){
		for (int x= 0; x<cantidad; x++){
			buffer[y][x] = ' ';					
		}
	}
	
	

	
	//Llenando Buffer:

	
	for (int i=0; i<cantidad; i++){
		int elemento = round(arreglo[i][1])-1;
		buffer[elemento][i] = 219;
		//printf("Posicion en x: %d [%d] -> %f]\n", i, (int)arreglo[i][1], arreglo[i][1]);

		
	}


	//Interpolar valores: //y1: 120 y y2: 91:
	

	for (int i=0; i<cantidad; i++){

		if (i+1 > cantidad){
			break;
		}
		else{
			float x1 = arreglo[i][0];
			float y1 = arreglo[i][1];
			
			float x2 = arreglo[i+1][0];
			float y2 = arreglo[i+1][1];

						

			int cant_intervalos = abs((int)((y1-y2)-1));


			//printf("Valores -> x1: %.1f, y1: %.1f | x2: %.1f, y2: %.1f\n", x1, y1, x2, y2);

			float *sub_lista_interpolados = interpolador('y', cant_intervalos, x1, y1, x2, y2);


			//printf("Cantidad de intervalos: %d\n", cant_intervalos);
			//printf("%d. Sub lista interpolados entre: y1: %d y y2: %d:\n", i, (int)y1, (int)y2);
			for (int j = 0; j<cant_intervalos; j++){
				//printf("y[%d]: %.3f", j, sub_lista_interpolados[j] );

				int elemento = round(sub_lista_interpolados[j])-1;

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
		for (int x = 0; x<cantidad-1; x++){
			printf("%c%c", buffer[y][x], buffer[y][x]);
		}
		puts("");
	}

	return 0;
}
