/*
 * lib.c
 *
 *  Created on: May 13, 2021
 *      Author: Slayer
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"
#include <time.h>
#define EMPTY 0
#define BUSY 1

void hardcoding(Servicio lista[], int *id2, int S)
{
	char auxDesc[4][25] = {"Limpieza", "Parche", "Centrado", "Cadena"};
	int auxPrecio[4] = {250, 300, 400, 350};
    int i;

    for(i = 0; i < S; i ++)
    {
    	lista[i].id = *id2;
        strcpy(lista[i].description, auxDesc[i]);
        lista[i].precio = auxPrecio[i];
        (*id2) ++;
    }
}

int menu()
{
    int option;

    printf("\n1. Take Data");
    printf("\n2. Product modification.");
    printf("\n3. Product delete.");
    printf("\n4. Show product(s).");
    printf("\n5. Exit program...\n");

    scanf("%d", &option);

    return option;
}

void start_up(Trabajo list[], int size)
{
	int i;

	for(i = 0; i < size; i ++)
		{
			list[i].isEmpty = EMPTY;
		}
}

int void_search(Trabajo list[], int size)
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

int data_intake(Trabajo product[], int size, int* id, Servicio lista[], int S)
{
	int index;
	int check = 0;


	if(product != NULL && size > 0)
	{
		index = void_search(product, size);

		if(index != -1)
		{
			printf("El ID es: %d \n", *id);
			printf("\nIngrese el rodado: \n");
			scanf("%d", &product[index].rodado);
			printf("\nIngrese la marca:  \n");
			fflush(stdin);
			gets(product[index].marca);
			hardPrint(lista, S);
			printf("Ingrese id de servicio: ");
			scanf("%d", &product[index].idS);




			product[index].isEmpty = BUSY;
			product[index].id2 = *id;
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

int data_print(Trabajo product[], int size)
{
	int i;
	int flag;
	flag = 0;

	for(i = 0; i < size; i ++)
	{
		if(product[i].isEmpty == BUSY)
		{
			data_print_s(product[i]);
			flag =1;
		}
	}

	if(flag == 0)
	{
		printf("There is no products!");
	}
	return 0;
}

int data_print_s(Trabajo product)
{
		printf("<================================>");
		printf("\nID: %d", product.id2);
		printf("\nMarca: %s \n", product.marca);
		printf("\nRodado: %d \n", product.rodado);
		printf("<================================> \n");

	return 0;
}

int hardPrint(Servicio lista[], int size)
{
	int i;
	int flag;
	flag = 0;

		for(i = 0; i < size; i ++)
		{
			hardPrintS(lista[i]);
			flag = 1;
		}
	return flag;
}

void hardPrintS(Servicio lista)
{
	printf("<================================>");
	printf("\nID: %d", lista.id);
	printf("\nMarca: %s \n", lista.description);
	printf("\nRodado: %d \n", lista.precio);
	printf("<================================> \n");
}

int data_delete(Trabajo product[], int size)
{
	int id;
	int aux;

	data_print(product, size);

	printf("Enter the ID of the product you want to delete: \n");
	scanf("%d", &id);

	aux = id_search(product, size, id);

	if(aux != -1)
	{
		product[aux].isEmpty = EMPTY;
	}
	return aux;
}

int id_search(Trabajo product[], int size, int id)
{
	int i;
	int aux;
	aux = -1;

	for(i = 0; i < size; i ++)
	{
			aux = i;
			break;
	}
	return aux;
}

int product_mod(Trabajo product[], Servicio lista[], int size, int S)
{
	int id;
	int index;
	char confirmation[8];

	Trabajo newerT;
	Servicio newerS;

	data_print(product, size);

	printf("Enter the ID of the product you want to modify: \n");
	scanf("%d", &id);

	index = id_search(product, size, id);

	if(index != -1)
	{
		data_print_s(product[index]);
		printf("is this one? (yes / no)");
		scanf("%s", confirmation);

		if(stricmp(confirmation,"yes") == 0)
		{
			newerT = product[index];
			newerS = lista[index];
			switch(mod_menu())
			{
				case 1:
					printf("Ingrese el nuevo servicio:  \n");
					scanf("%[^\n]", newerS.description);
					break;

				case 2:
					printf("Ingrese el nuevo rodado: \n");
					scanf("%d", &newerT.rodado);
					break;

			}

			product[index] = newerT;
			lista[index] = newerS;

		}
	}
	return index;
}

int mod_menu()
{
	int option;

	printf("\n1. Nuevo servicio.");
	printf("\n2. Nuevo rodado");

    scanf("%d", &option);

    return option;
}
int total(Trabajo product[], Servicio lista[], int size, int S)
{
	int total = 0;
	int i;
	int j;

	for(i = 0; i < size; i ++)
	{
		for(j = 0; j < S; j ++)
		{
			if(product[i].idS == lista[j].id)
			{
				total += lista[j].precio;
			}
		}
	}

	printf("el total es: %d", total);


	return 0;
}







