//Interpolador

#include <stdio.h>
#include <stdlib.h>

float *secuencia(int n, float a, float b){  //N es la cantidad de puntos a buscar, a el punto 1 en x, y b el punto 2 en x
	
	float *lista = malloc(n * sizeof(float));

	if (lista == NULL) {
        return NULL;
    }
	
	float valor = a;
	
	float tam_saltos = (b-a)/(n+1);
	
	//printf("Tamanio saltos: %.1f\n", tam_saltos);
		
	for (int i=0; i<n; i++){
		valor = valor + tam_saltos;
		lista[i] = valor;
		printf("x%d: %.3f || Valor real: %.3f.\n", i+1, lista[i], valor);
	}

	return lista;
}

int main(){
	
	float x, x1, y1, x2, y2, formula;
	
	
	x1 = 10;
	y1 = 100;
	
	x2 = 20;
	y2 = 200;
	
	int cant_secuencia = 10;
	puts("\n---------------------------------------");
	printf("- Coordenada 1: (%.1f , %.1f)\n", x1, y1);
	printf("- Coordenada 2: (%.1f , %.1f)\n", x2, y2);
	printf("\nCantidad de intervalos: %d\n", cant_secuencia);
	puts("---------------------------------------\n");

	


	float *lista_intermedios = secuencia(cant_secuencia, x1, x2); 
	float *lista_interpolados = malloc(cant_secuencia * sizeof(float));
	
	puts("------ Calculo de interpolacion con los intervalos------\n");
	for (int i = 0; i<cant_secuencia; i++){
		formula = y1 + ((lista_intermedios[i]-x1)*(y2-y1)/(x2-x1));
		lista_interpolados[i] = formula;
		printf("x%d = %.1f -> y%d = %.1f\n", i+1, lista_intermedios[i], i+1, formula);
	}
	
	
	free(lista_intermedios);
	free(lista_interpolados);
	lista_intermedios = NULL;
	lista_interpolados = NULL;
	return 0;
}