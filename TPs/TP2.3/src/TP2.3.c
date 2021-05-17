/*
 ============================================================================
 Name        : TP2.c
 Author      : Lautaro Ezequiel Novelli
 Version     : Beta 0.5
 Copyright   : yesn't
 Description : TP2
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "lib.h"
#define SIZE 1000
#define S 3

int main()
{

	int id = 20000;
	int idT = 0001;
	int op_menu;
	char keep_going;
	int data_value = 0;

	Employee service[SIZE];
	Sector datos[S];
	start_up(service, SIZE);
	hardcoding(datos, &idT, S);

	setbuf(stdout, NULL);

	keep_going = 's';

	do
	{

		op_menu = menu();

		switch(op_menu)
		{
			case 1:
				data_intake(service, SIZE, &id, datos, S);
				data_value = 1;
				break;

			 case 2:
				 employee_mod(service, datos, SIZE, S);
				 break;

			 case 3:
				 data_delete(service, SIZE);
				 break;

			 case 4:
				if(data_value == 1)
				{
					data_print(service, SIZE);
				}
				else
				{
					printf("\nE R R O R !  Invalid data.\n");
				}

				break;

			 case 5:
				 alphabeticalSorting(service, SIZE);
				 break;

			case 6:
				keep_going = 'n';
				break;
		}

	}while(keep_going == 's');

		return EXIT_SUCCESS;
}
