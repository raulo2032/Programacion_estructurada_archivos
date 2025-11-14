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

void corte_control(char *nombre_archivo){
    FILE *archivo = fopen(nombre_archivo, "r");
    if (!archivo) return;

    jugador jugador_actual;
    char equipo_actual[LONG_CADENA];
    float total_equipo;
    int cantidad_equipo;

    printf("-----Reporte de puntuacion de jugadores AGRUPADOS por equipo-----\n");
    printf("%-8s %-10s %-15s %-10s\n", "Numero", "Equipo", "Posicion", "Puntuacion");

    // Lectura inicial
    fscanf(archivo, "%d %s %s %f",
           &jugador_actual.numero,
           jugador_actual.equipo,
           jugador_actual.posicion,
           &jugador_actual.puntuacion);

    while (!feof(archivo)) {

        strcpy(equipo_actual, jugador_actual.equipo);
        total_equipo = 0;
        cantidad_equipo = 0;

        // while del grupo
        while (!feof(archivo) &&
               strcmp(equipo_actual, jugador_actual.equipo) == 0)
        {
            printf("%-8d %-10s %-15s %-10.2f\n",
                   jugador_actual.numero,
                   jugador_actual.equipo,
                   jugador_actual.posicion,
                   jugador_actual.puntuacion);

            total_equipo += jugador_actual.puntuacion;
            cantidad_equipo++;

            // leer siguiente
            fscanf(archivo, "%d %s %s %f",
                   &jugador_actual.numero,
                   jugador_actual.equipo,
                   jugador_actual.posicion,
                   &jugador_actual.puntuacion);
        }

        // cuando salgo, jugador_actual pertenece al SIGUIENTE equipo
        printf("Promedio del equipo %s:\t%.2f\n\n",
               equipo_actual,  // 👈 este es el correcto
               total_equipo / cantidad_equipo);
    }

    fclose(archivo);
}

int main(void) {

    printf("Hello, world!\n");
    corte_control("puntuaciones.txt");
    return 0;
}