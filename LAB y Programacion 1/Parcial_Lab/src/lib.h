/*
 * lib.h
 *
 *  Created on: May 13, 2021
 *      Author: Slayer
 */
#ifndef LIB_H_
#define LIB_H_

typedef struct
{
	int id;
	char description[25];
	int precio;

}Servicio;

typedef struct
{
	int id2;
	char marca[69];
	int rodado;
	Servicio id;
	int idS;
	int isEmpty;

}Trabajo;

void hardcoding(Servicio lista[], int *id2, int S);
int menu();
void start_up(Trabajo list[], int size);
int void_search(Trabajo list[], int size);
int data_intake(Trabajo product[], int size, int* id, Servicio lista[], int S);
int data_print(Trabajo product[], int size);
int data_print_s(Trabajo product);
int hardPrint(Servicio lista[], int size);
void hardPrintS(Servicio lista);
int data_delete(Trabajo product[], int size);
int id_search(Trabajo product[], int size, int id);
int product_mod(Trabajo product[], Servicio lista[], int size, int S);
int mod_menu();
int total(Trabajo product[], Servicio lista[], int size, int S);
#endif /* LIB_H_ */
