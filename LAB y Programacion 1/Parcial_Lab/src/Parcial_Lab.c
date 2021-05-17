/*
 ============================================================================
 Name        : Parcial_Lab.c
 Author      : Lautaro Ezequiel Novelli
 Version     :
 Copyright   : 
 Description :
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include "lib.h"
#define SIZE 10
#define S 4

int main(void)
{
	int id = 20000;
	int idT = 1;
	int op_menu;
	char keep_going;
	int data_value = 0;

	Servicio service[S];
	Trabajo producto[SIZE];
	start_up(producto, SIZE);
	hardcoding(service, &id, S);

	setbuf(stdout, NULL);

		keep_going = 's';
	do
	{

		op_menu = menu();

		switch(op_menu)
		{
			case 1:
				data_intake(producto, SIZE, &idT, service, S);
				data_value = 1;
				break;

			 case 2:
				 product_mod(producto, service, SIZE, S);
				 break;

			 case 3:
				 data_delete(producto, SIZE);
				 break;

			 case 4:
				if(data_value == 1)
				{
					data_print(producto, SIZE);
				}
				else
				{
					printf("\nE R R O R !  Invalid data.\n");
				}

				break;

			 case 5:
				 total(producto, service, SIZE, S);
				 break;

			case 6:
				keep_going = 'n';
				break;
		}

	}while(keep_going == 's');

		return EXIT_SUCCESS;
}
