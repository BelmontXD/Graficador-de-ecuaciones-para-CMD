//Interpolador

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

float *secuencia(int n, float a, float b){  //N es la cantidad de puntos a buscar, a el punto 1 en x, y b el punto 2 en x
	
	float *lista = malloc(n * sizeof(float));

	if (lista == NULL) {
        return NULL;
    }
	
	float valor = a;
	
	float tam_saltos = (b-a)/(n+1);
	
	//puts("### Secuencia ###");

	//printf("Tamanio saltos: %.1f\n", tam_saltos);
		
	for (int i=0; i<n; i++){
		valor = valor + tam_saltos;
		lista[i] = valor;
		//printf("x%d: %.3f || Valor real: %.3f.\n", i+1, lista[i], valor);
	}

	//puts("Presione tecla para continuar....");
	//getch();

	return lista;
}

float *interpolador(char eje, int cant_intervalos, float x1, float y1, float x2, float y2){
	
	float formula;
	
	/*
	puts("\n---------------------------------------");
	printf("- Coordenada 1: (%.1f , %.1f)\n", x1, y1);
	printf("- Coordenada 2: (%.1f , %.1f)\n", x2, y2);
	printf("\nCantidad de intervalos: %d\n", cant_intervalos);
	puts("---------------------------------------\n");
	*/
	
	float *lista_intermedios;
	float *lista_interpolados = malloc(cant_intervalos * sizeof(float));
	

	switch (eje) {

		case 'x'://Para buscar valores en eje x  <---- Quede aquí, tengo que buscar que valores tengo que exportar

			lista_intermedios = secuencia(cant_intervalos, y2, y1); 
			//puts("------ Calculo de interpolacion con los intervalos------\n");
			for (int i = 0; i<cant_intervalos; i++){
				formula = x1 + ((lista_intermedios[i]-y1)*(x2-x1)/(y2-y1));
				lista_interpolados[i] = formula;
				//printf("y%d = %.1f -> x%d = %.1f\n", i+1, lista_intermedios[i], i+1, formula);
			}
			getch(); 
			break;
		case 'y': // Buscar valores y
			lista_intermedios = secuencia(cant_intervalos, x1, x2); 
			puts("------ Calculo de interpolacion con los intervalos------\n");
			for (int i = 0; i<cant_intervalos; i++){
				formula = y1 + ((lista_intermedios[i]-x1)*(y2-y1)/(x2-x1));
				lista_interpolados[i] = formula;
				printf("x%d = %.1f -> y%d = %.1f\n", i+1, lista_intermedios[i], i+1, formula);
			}
			break;
		default:
			printf("Invalido...");
	}  
	
	free(lista_intermedios);
	lista_intermedios = NULL;
	return lista_interpolados;
}