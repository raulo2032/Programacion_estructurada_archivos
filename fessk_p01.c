#include <stdio.h>
#include <ctype.h>
int main(){

    FILE *f; /* Puntero al archivo */
    char caracter;
    f = fopen("mi_archivo.txt", "r+");      // Se abre el archivo para lectura y escritura 
    
    if (f == NULL){
        printf("Error! No pudo abrirse el archivo!");
        return 1;
    }
    while ((caracter = getc(f)) != EOF){ // Se lee todo el archivo y se lo muestra en pantalla.* /
    
        caracter =  toupper(caracter);     /* Se convierte el carácter a mayúsculas. */
        fseek(f, -1, SEEK_CUR);         /* Se mueve el puntero a registro una posición hacia atrás */
        putc(caracter, f);                  /* Se escribe el carácter en mayúsculas. Esta escritura también avanza el puntero.*/
        fflush(f); 
    }
    fseek(f, 0, SEEK_SET);   /* Se lleva el puntero a la primera posición. */
    while ((car = getc(f)) != EOF){ /* Se lee todo el archivo y se lo muestra en pantalla. */
        printf("%c", caracter);
    }
    printf("\n");
    fclose(f);
    return 0;
}