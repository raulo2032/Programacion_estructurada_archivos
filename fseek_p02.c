#include <stdio.h>
#define N 3
struct autos{
    int cilindrada;
    char combustible;
    float vel_max;
};
void ingresar (const char*, int);
void imprimir(const char*, int);
int cant_autos (const char *);

void ingresar(const char *file, int n) {
    struct autos aux;
    FILE *f = fopen(file, "wb");
    
    if (f == NULL) {
        printf("Error al abrir el archivo %s\n", file);
        return;
    }
    
    for (int i = 0; i < n; i++) {
        printf("\nIngrese cilindrada motor auto %i:", i+1);
        scanf("%d", &aux.cilindrada);
        while (getchar() != '\n');
        
        printf("\nIngrese combustible N/O auto %i:", i+1);
        scanf(" %c", &aux.combustible);
        while (getchar() != '\n');
        
        printf("\nIngrese velocidad máxima auto %i:", i+1);
        scanf("%f", &aux.vel_max);
        while (getchar() != '\n');
        
        fwrite(&aux, sizeof(aux), 1, f);
    }
    
    fclose(f);
}
void imprimir(const char *file, int n){

    struct autos aux;
    FILE *f;
    f = fopen(file, "rb");
    if (f == NULL)  { printf("Error al abrir el archivo %s\n", file); return ;}
    fseek(f, (n-1) * sizeof(aux), SEEK_SET);
    fread(&aux, sizeof(aux), 1, f);
    printf("\nAuto nro %d\nCilindrada: %dcc\nCombustible: %c\nVelocidad maxima: %.02fkm/h max", n, aux.cilindrada, aux.combustible, aux.vel_max);
        fclose(f);
}

int cant_autos (const char *file){
    FILE *f;
    int cant;
    f = fopen(file, "rb");
    if (f == NULL)  printf("Error al abrir el archivo %s\n", file);
    fseek(f, 0, SEEK_END);
    cant = ftell(f) / sizeof(struct autos);
    fclose(f);

    return cant;
}

int main(){

    const char *nom_archivo = "autos.dat";
    int cant, pos;
    printf("Ingrese cantidad de autos a registrar\n");
    scanf("%d", &cant);
    ingresar(nom_archivo, cant);
    printf("Ingrese nro auto a leer (1 -%d)\n", cant_autos(nom_archivo));
    scanf("%d", &pos);
    imprimir(nom_archivo, pos);
    cant_autos(nom_archivo);


    
}
