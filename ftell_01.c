#include <stdio.h>
int main(){
    FILE *f;
    f = fopen("mi_archivo.txt", "r");
    if (f == NULL){
        printf("Error al abrir el archivo\n");
        return 1;
    }
    fseek(f, 0, SEEK_END);
    printf("Tamaño del archivo: %ld\n", ftell(f));
}