/*
============================================================================
 * lib.c
 *
 *  Created on: May 15, 2021
 *  Author: Slayer
 *
 *  TP2
============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "lib.h"
#include <string.h>


#define EMPTY 0
#define BUSY 1


int menu()
{
    int option;

    printf("\n1. Take Data");
    printf("\n2. Employee modification.");
    printf("\n3. Employee delete.");
    printf("\n4. Show employee(s).");
    printf("\n5. Exit program...\n");

    scanf("%d", &option);

    return option;
}



void hardcoding(Sector datos[], int *id2, int S)
{
	char auxSector[3][25] = {"IT", "RRHH", "Concierge"};
    int i;

    for(i = 0; i < S; i ++)
    {
    	datos[i].idSector = *id2;
        strcpy(datos[i].sector, auxSector[i]);
        (*id2) ++;
    }
}



void start_up(Employee list[], int size)
{
	int i;

	for(i = 0; i < size; i ++)
		{
			list[i].isEmpty = EMPTY;
		}
}

int void_search(Employee list[], int size)
{
	int i;
	int aux;

	aux = -1;

	for(i = 0; i < size; i ++)
		{
			if(list[i].isEmpty == EMPTY)
				{
					aux = i;
					break;
				}
		}
	return aux;
}

int data_intake(Employee list[], int size, int* id, Sector datos[],int S)
{
	int index;
	int check = 0;

	if(list != NULL && size > 0)
	{
		index = void_search(list, size);

		if(index != -1)
		{
			printf("The ID of the employee is: %d \n", *id);
			printf("\nEnter the name: \n");
			fflush(stdin);
			gets(list[index].name); // gets = scanf, only for strings.
			printf("\nEnter the last name \n");
			gets(list[index].last_name);
			printf("\nEnter the salary: \n");
			scanf("%f", &list[index].salary);

			hardPrint(datos, S);
			printf("Ingrese id de servicio: ");
			scanf("%d", &list[index].id);

			list[index].isEmpty = BUSY;
			list[index].id = *id;
			(*id) ++;
			check = 1;
		}
		else
		{
			printf("There is no more free space.\n");
		}
	}
	return check;
}

int data_print(Employee list[], int size)
{
	int i;
	int flag;
	flag = 0;

	for(i = 0; i < size; i ++)
	{
		if(list[i].isEmpty == BUSY)
		{
			data_print_s(list[i]);
			flag =1;
		}
	}

	if(flag == 0)
	{
		printf("There is no Employee!");
	}
	return 0;
}

int data_print_s(Employee list)
{
		printf("<================================>");
		printf("\nID: %d", list.id);
		printf("\nName: %s", list.name);
		printf("\nLast name: %s", list.last_name);
		printf("\nSalary: %f", list.salary);
		printf("\nSector: %d \n", list.sector);
		printf("<================================> \n");

	return 0;
}

int data_delete(Employee list[], int size)
{
	int id;
	int aux;

	data_print(list, size);

	printf("Enter the ID of the employee you want to delete: \n");
	scanf("%d", &id);

	aux = id_search(list, size, id);

	if(aux != -1)
	{
		list[aux].isEmpty = EMPTY;
	}
	return aux;
}
int hardPrint(Sector datos[], int size)
{
	int i;
	int flag;
	flag = 0;

		for(i = 0; i < size; i ++)
		{
			hardPrintS(datos[i]);
			flag = 1;
		}
	return flag;
}

void hardPrintS(Sector datos)
{
	printf("<================================>");
	printf("\nID: %d", datos.idSector);
	printf("\nSector: %s \n", datos.sector);
	printf("<================================> \n");
}


int id_search(Employee list[], int size, int id)
{
	int i;
	int aux;
	aux = -1;

	for(i = 0; i < size; i ++)
	{
		if(list[i].isEmpty == BUSY && id == list[i].id)
		{
			aux = i;
			break;
		}
	}
	return aux;
}

int employee_mod(Employee list[], Sector datos[], int size, int S)
{
	int id;
	int index;
	char confirmation[8];

	Employee newer;

	data_print(list, size);

	printf("Enter the ID of the employee you want to modify: \n");
	scanf("%d", &id);

	index = id_search(list, size, id);

	if(index != -1)
	{
		data_print_s(list[index]);
		printf("is this one? (yes / no)");
		scanf("%s", confirmation);

		if(stricmp(confirmation, "yes") == 0)
		{
			newer = list[index];
			switch(mod_menu())
			{
				case 1:
					printf("Enter the new Name: \n");
					scanf("%s", newer.name);
					break;

				case 2:
					printf("Enter the last name");
					scanf("%s", newer.last_name);
					break;

				case 3:
					printf("Enter the salary");
					scanf("%f", &newer.salary);
					break;

				case 4:
					printf("Enter the new sector");
					scanf("%d", &newer.sector);
					break;
			}

			list[index] = newer;

		}

	}

	return index;
}

int mod_menu()
{
	int option;

	printf("\n1. Name modification.");
	printf("\n2. Last name modification.");
    printf("\n3. Salary modification.");
    printf("\n4. Sector modification.");
    printf("\n5. Exit . . .");

    scanf("%d", &option);

    return option;
}


void alphabeticalSorting(Employee list[], int size)
{
	int x;
	int y;
	Employee aux;

	for(x = 0; x < size - 1; x ++)
	{
		for(y = x + 1; y < size; y ++)
		{
			if( strcmp(list[x].name, list[y].name ) > 0)
			{
				aux = list[x];
				list[x] = list[x + 1];
				list[x] = aux;
			}
		}
	}
}
