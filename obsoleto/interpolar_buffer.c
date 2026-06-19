//Interpolar valores de la figura (Obsoleto, por el uso del algoritmo de bresenham):
	/*
	// Es decir, si no es un circulo
	int comodin_x;
	if (cantidad_h != cantidad_v){
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


				//printf("Valores -> x1: %.1f, y1: %.1f | x2: %.1f, y2: %.1f\n", x1, y1, x2, y2);

				float *sub_lista_interpolados = interpolador('y', cant_intervalos, x1, y1, x2, y2);


				//printf("Cantidad_h de intervalos: %d\n", cant_intervalos);
				//printf("%d. Sub lista interpolados entre: y1: %d y y2: %d:\n", i, (int)y1, (int)y2);
				for (int j = 0; j<cant_intervalos; j++){
					//printf("y[%d]: %.3f", j, sub_lista_interpolados[j] );

					int elemento = abs((round(sub_lista_interpolados[j])+min_y)-1);
					// 		int elemento = (round(arreglo[i][1])+min)-1;
					//printf("Elemento: %d\n", elemento);


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
	}else{
		for (int i=0; i<ecuacion.matriz_filas; i++){
			if (i+2 > ecuacion.matriz_filas){
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
				float *sub_lista_interpolados_x = interpolador('x', cant_intervalos, x1, y1, x2, y2);


				//printf("Cantidad_h de intervalos: %d\n", cant_intervalos);
				//printf("%d. Sub lista interpolados entre: y1: %d y y2: %d:\n", i, (int)y1, (int)y2);
				for (int j = 0; j<cant_intervalos; j++){
					printf("y[%d]: %.3f\n", j, sub_lista_interpolados_x[j] );

					int elemento = abs((round(sub_lista_interpolados[j])+min_y));
					int elemento2 = abs((round(sub_lista_interpolados_x[j])+min_x));
					// 		int elemento = (round(arreglo[i][1])+min)-1;
					//printf("Elemento: %d\n", elemento);


					buffer[elemento][elemento2] = 219; //Aquí llenamos el buffer
					printf(" <-- Elemento puesto en matriz ( %d , %d )\n", elemento, elemento2);
				}
				
				
				
				//puts("--------------------------------");
				//getch();
				free(sub_lista_interpolados);
				sub_lista_interpolados = NULL;


				//printf("Posicion en x: %d [%d] -> %f]\n", i, (int)arreglo[i][1], arreglo[i][1]);
			}
		}	

	}*/ 