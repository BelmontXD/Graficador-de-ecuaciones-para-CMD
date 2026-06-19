// Bresenham's line algorithm (1962)
// draws a line using only integer arithmetic

void line(char** buffer, int x0, int y0, int x1, int y1) {
    //puts("Separador de coordenadas...");
    //puts("Interpolar:");
    //printf("\t- Desde: %d, %d\n", x0, y0);
    //printf("\t- Hasta: %d, %d\n", x1, y1);

    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx = (x0 < x1) ? 1 : -1;
    int sy = (y0 < y1) ? 1 : -1;
    int err = dx - dy;
    int x = x0, y = y0;
    
    while (1) {
        //printf("x: %d, y:%d\n", x, y);
        buffer[y][x] = 219;
        if (x == x1 && y == y1) break;
        
        int e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy;
            x += sx;
        }
        if (e2 < dx) {
            err += dx;
            y += sy;
        }
    }

    //puts("Fin");
}


