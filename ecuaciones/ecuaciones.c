#include <stdio.h>
#include "./trigonometria/trigonometricas.c"

//#include "../lib_memoria/memorias_dinamicas.c"



typedef struct {
    float a, b, c, d;
    int desde, hasta, cantidad;

    int matriz_filas, matriz_columnas;
    float **matriz;

} struct_ecuacion;


struct_ecuacion crear_ecuacion(int tipo, float a, float b, float c, float d, int desde, int hasta){
    struct_ecuacion eq;
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
    switch (tipo) {

        case 1: //Primer grado
            
            for (int x = eq.desde; x<=eq.hasta; x++){

                eq.matriz[i][1] = (eq.a * x) + (eq.b);
                eq.matriz[i][0] = x;
                i++;
            }
            break;
        case 2: //Segundo grado

            for (int x = eq.desde; x<=eq.hasta; x++){

                eq.matriz[i][1] = ( eq.a * (x*x)) + (eq.b*x) + eq.c;
                eq.matriz[i][0] = x;
                i++;
            }

            break;
        case 3: //Tercer grado

            for (int x = eq.desde; x<=eq.hasta; x++){

                eq.matriz[i][1] = ( eq.a * (x*x*x)) + (eq.b * (x*x)) + (eq.c * x) + eq.d;
                eq.matriz[i][0] = x;
                i++;
            }
            break;

        case 4: // Circulo

            //float radio = eq.hasta;
            //puts("Imprimiendo....");

            for (int teta = 0; teta < eq.cantidad; teta++){
                //printf("X = %f  -   ", eq.hasta * coseno[teta]);
                //printf("Y = %f\n", eq.hasta * seno[teta]);

                eq.matriz[i][1] = eq.hasta * seno[teta];
                eq.matriz[i][0] = eq.hasta * coseno[teta];

                
                //printf("X = %f  -   ", eq.matriz[i][1]);
                //printf("Y = %f\n", eq.matriz[i][0]);

            }
            
            //puts("\n(X , Y)\n");
            for (int i = 0; i < eq.matriz_filas; i++){
                //printf("X = %f  -   ", eq.matriz[i][1]);
                //printf("Y = %f\n", eq.matriz[i][0]);
                puts("");
            }


            imprimir_matriz_float(eq.matriz, eq.matriz_filas,  eq.matriz_columnas);
            break;

        default:
            puts("Este error no debe ocurrir, debe ser un error de digitacion incorrecto...");

    }

    
    //imprimir_matriz_float(eq.matriz, eq.cantidad, 2);   
    
    return eq;
}

struct_ecuacion crear_circulo(float h, float k, float r){
    struct_ecuacion fg;
    fg.a = h;
	fg.b = k;
    fg.c = r;


    fg.desde = fg.c * -1;
    fg.hasta = fg.c;
    
    fg.cantidad = (int)(fg.hasta - fg.desde);
    printf("Cantidad de coordenadas actuales del circulo: %d\n", fg.cantidad);
    fg.matriz_columnas = 2;
    fg.matriz_filas = CANTIDAD_TRIGONOMETRICAS*4;

    fg.matriz = crear_matriz_float(fg.matriz_filas, fg.matriz_columnas);
    

    // 1. Se calcula el primer 4to con los valores predefinidos de senos y cosenos
    int i = 0;
    for (int teta = 0; teta < CANTIDAD_TRIGONOMETRICAS; teta++){
        //printf("X = %f  -   ", eq.hasta * coseno[teta]);
        //printf("Y = %f\n", eq.hasta * seno[teta]);

        fg.matriz[i][0] = fg.c * coseno[teta]; //x
        fg.matriz[i][1] = fg.c * seno[teta]; //y

        
        //printf("X = %f  -   ", fg.matriz[i][0]);
        //printf("Y = %f\n", fg.matriz[i][1]);

        i++;
    }

    
    // 2. Se invierten los valores en el cuarto izquierdo superior
    int j = i-1;
    for (int teta = 0; teta < CANTIDAD_TRIGONOMETRICAS; teta++){
        //printf("X = %f  -   ", eq.hasta * coseno[teta]);
        //printf("Y = %f\n", eq.hasta * seno[teta]);

        fg.matriz[i][0] = (fg.matriz[j][0])*-1; //x
        fg.matriz[i][1] = fg.matriz[j][1]; //y

        
        //printf("X = %f  -   ", fg.matriz[i][0]);
        //printf("Y = %f\n", fg.matriz[i][1]);

        i++;
        j--;
    }

    // 3. Se invierten los valores en el cuarto izquierdo inferior
    j = 0;
    for (int teta = 0; teta < CANTIDAD_TRIGONOMETRICAS; teta++){
        //printf("X = %f  -   ", eq.hasta * coseno[teta]);
        //printf("Y = %f\n", eq.hasta * seno[teta]);

        fg.matriz[i][0] = (fg.matriz[j][0])*-1; //x
        fg.matriz[i][1] = (fg.matriz[j][1])*-1; //y

        
        //printf("X = %f  -   ", fg.matriz[i][0]);
        //printf("Y = %f\n", fg.matriz[i][1]);

        i++;
        j++;
    }

    // 4. Se invierten los valores en el cuarto derecho inferior
    j = CANTIDAD_TRIGONOMETRICAS;
    for (int teta = 0; teta < CANTIDAD_TRIGONOMETRICAS; teta++){
        //printf("X = %f  -   ", eq.hasta * coseno[teta]);
        //printf("Y = %f\n", eq.hasta * seno[teta]);

        fg.matriz[i][0] = (fg.matriz[j][0])*-1; //x
        fg.matriz[i][1] = (fg.matriz[j][1])*-1; //y

        
        7/printf("X = %f  -   ", fg.matriz[i][0]);
        7/printf("Y = %f\n", fg.matriz[i][1]);

        i++;
        j++;
    }
    i=0;j=0;

    return fg;
}




int indices_iguales(int desde, int hasta){
    printf("ERROR: Indices de iteracion iguales... retornando cero");

    return 0;
}
