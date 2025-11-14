/* Queremos ver total de puntos realizado por equipos, en el archivo puntuaciones.txt*/

#include    <stdio.h>
#include    <stdlib.h>
#include    <string.h>

#define     LONG_CADENA 32

typedef struct{
    int numero;
    char equipo[LONG_CADENA];
    char posicion[LONG_CADENA];
    float puntuacion;
} jugador;

void corte_control( char *nombre_archivo){
    FILE * archivo;
    archivo = fopen(nombre_archivo, "r");
    char equipo_actual[LONG_CADENA];
    int cantidad_equipo;            // cantidad de jugadores
    float total_equipo;             // cantidad de puntaje

    /* para ver el regustro que me recupera del archivo, lo podemos hacer de dos maneras
        Una manera, una variable para cada atributo de la estructura
        otra, una variable tipo jugador con el registro entero*/

    jugador jugador_actual;
    printf("-----Reporte de puntuacion de jugadores AGRUPADOS por equipo-----\n");
    printf("%-8s %-10s %-15s %-10s\n", "Numero", "Equipo", "Posicion", "Puntuacion");
    
    
    fscanf(archivo, "%d %s %s %f", &jugador_actual.numero, jugador_actual.equipo, jugador_actual.posicion, &jugador_actual.puntuacion);

    while(!feof(archivo)){
        strcpy(equipo_actual, jugador_actual.equipo);
        total_equipo = 0;
        cantidad_equipo = 0;        /*cantidad de jugadores de cada equipo*/

        // Inicializamos la variables y ahora implementamos el while del corte de control
        while(!feof(archivo) && strcmp(equipo_actual, jugador_actual.equipo) == 0){     /* este es el corte de control*/
            printf("%-8d %-10s %-15s %-10.2f\n", jugador_actual.numero, jugador_actual.equipo, jugador_actual.posicion, jugador_actual.puntuacion);
            total_equipo += jugador_actual.puntuacion;
            cantidad_equipo ++;

            fscanf(archivo, "%d %s %s %f", &jugador_actual.numero, jugador_actual.equipo, 
                                            jugador_actual.posicion, &jugador_actual.puntuacion);

        }      /* saliendo de este while, pero no del siguiente*/

        printf("Promedio del equipo %s:\t%.2f\n\n", equipo_actual, total_equipo/cantidad_equipo);
        
    }
    fclose(archivo);
}

int main(void) {

    printf("Hello, world!\n");
    corte_control("puntuaciones.txt");
    return 0;
}