/**

Ejercicio 8-1:
Crear la estructura Jugador (nombre, goles metidos, partidos jugados, promedio de goles).
Crear una función que permita cargar los datos de un jugador y otra que los muestre.
Una tercera función calculará el promedio de goles.

**/


#include <stdio.h>
#define J 3

// declaracion de estructura
typedef struct
{
    char nombre[20];
    int goles_metidos;
    int partidos_jugados;
    float promedio_goles;
}eJugador;

// declaracion de funciones
eJugador take_data();
void show_data(eJugador);
float promedio(int, int);


int main()
{
    setbuf(stdout,NULL);
    eJugador miJugador;
    float prom;

    miJugador=take_data();
    show_data(miJugador);
    prom=promedio(miJugador.goles_metidos,miJugador.partidos_jugados); //llamado a la funcion mediante variable igualda concatenada con "." con respecctiva variable de la funcion llamada
    printf("PROM %.2f",prom);
    return 0;
}

eJugador take_data()
{
    eJugador data;

    printf("Ingrese nombre: ");
    scanf("%[^\n]", &data.nombre); //asignacion del valor recibido a la variable "eJugador data" en el vector nombre
    printf("Ingrese la cantidad de goles: ");
    fflush(stdin);
    scanf("%d", &data.goles_metidos);//asignacion del valor recibido a la variable "eJugador data" en el vector goles
    printf("Ingrese la cantidad de partidos jugados: ");
    scanf("%d", &data.partidos_jugados);//asignacion del valor recibido a la variable "eJugador data" en el vector partidos


    return data;
}

void show_data(eJugador data)
{
    float promedio_goles;
    data.promedio_goles = promedio(data.goles_metidos, data.partidos_jugados);

    printf("El jugador ingresado se llama %s, metio %d goles en %d partidos con un promedio de %.2f",  data.nombre,
																									   data.goles_metidos,
																									   data.partidos_jugados,
																									   data.promedio_goles);
}

float promedio(int goles, int partidos)
{
    float pr;

    pr = goles / partidos;

    return pr;
}
