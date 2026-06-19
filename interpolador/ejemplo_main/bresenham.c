#include <stdio.h> 
#include <math.h>

void line_tst(int x0, int y0, int x1, int y1) {
    puts("Separador de coordenadas...");
    int dx = x1 - x0, dy = y1 - y0, err = dx / 2, y = y0;
    for (int x = x0; x <= x1; x++) {
        printf("x: %d, y:%d\n", x, y);
        //buffer[y, x];
        err -= dy;
        if (err < 0) { 
            y++; 
            err += dx; 
        }
    }
}

// Versión alternativa con bucle for (solo para casos donde dx >= dy)
void line_simple(int x0, int y0, int x1, int y1) {
    int dx = x1 - x0;
    int dy = y1 - y0;
    
    // Caso 1: Pendiente entre 0 y 1 (dx >= dy)
    if (dx >= dy) {
        int err = dx / 2;
        int y = y0;
        for (int x = x0; x <= x1; x++) {
            printf("x: %d, y:%d\n", x, y);
            err -= dy;
            if (err < 0) {
                y++;
                err += dx;
            }
        }
    }
    // Caso 2: Pendiente > 1 (dy > dx) - Línea más vertical
    else {
        int err = dy / 2;
        int x = x0;
        for (int y = y0; y <= y1; y++) {
            printf("x: %d, y:%d\n", x, y);
            err -= dx;
            if (err < 0) {
                x++;
                err += dy;
            }
        }
    }
}



int main(){
    line_simple(9, 46+42, 10, 50+42);
    return 0;
}