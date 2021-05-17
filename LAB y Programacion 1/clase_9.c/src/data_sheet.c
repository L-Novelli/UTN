/*
 * data_sheet.c
 *
 *  Created on: May 6, 2021
 *      Author: Slayer
 */
#include <stdio.h>
#include <stdlib.h>
#include "proto_sheet.h"
#include <string.h>

#define iPhone 4
#define Mac 5
#define iPad 6
#define AddOns 7
#define BUSY -1
#define EMPTY 0


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

void start_up(Register list[], int size)
{
	int i;

	for(i = 0; i < size; i ++)
		{
			list[i].isEmpty = EMPTY;
		}
}

int void_search(Register list[], int size)
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

int data_intake(Register product[], int size, int* id)
{
	int index;
	int check = 0;

	if(product != NULL && size > 0)
	{
		index = void_search(product, size);

		if(index != -1)
		{
			printf("The ID of the product is: %d \n", *id);
			printf("\nEnter the product description: \n");
			fflush(stdin);
			gets(product[index].description); // gets = scanf, only for strings.
			printf("\nEnter the product origin: (1 = U.S; 2 = China; 3 = Other) \n");
			scanf("%d", &product[index].origin);
			if(product[index].origin != 1 && product[index].origin != 2 && product[index].origin != 3)
			{
				printf("\a\nThe selected option is invalid, please enter one of the following options: (1 = U.S; 2 = China; 3 = Other) \n");
				scanf("%d", &product[index].origin);
			}
			printf("\nEnter the product type: (4 =IPHONE, 5 = MAC, 6 = IPAD, 7 = ADD ONs)\n");
			scanf("%d", &product[index].type);
			if(product[index].type != 4 && product[index].type != 5 && product[index].type != 6 && product[index].type != 7)
			{
				printf("\a\nThe selected option is invalid, please enter one of the following options: (4 =IPHONE, 5 = MAC, 6 = IPAD, 7 = ADD ONs) \n");
				scanf("%d", &product[index].type);
			}
			printf("\nEnter the price of the product: \n");
			scanf("%d", &product[index].p_price);
			product[index].isEmpty = BUSY;
			product[index].Product = *id;
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

int data_print(Register product[], int size)
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

int data_print_s(Register product)
{
		printf("<================================>");
		printf("\nID: %d", product.Product);
		printf("\nDescription: %s", product.description);
		printf("\nOrigin: %d", product.origin);
		printf("\nType: %d", product.type);
		printf("\nPrice: %d \n", product.p_price);
		printf("<================================> \n");

	return 0;
}

int data_delete(Register product[], int size)
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

int id_search(Register product[], int size, int id)
{
	int i;
	int aux;
	aux = -1;

	for(i = 0; i < size; i ++)
	{
		if(product[i].isEmpty == BUSY && id == product[i].Product)
		{
			aux = i;
			break;
		}
	}
	return aux;
}

int product_mod(Register product[], int size)
{
	int id;
	int index;
	char confirmation[8];

	Register newer;

	data_print(product, size);

	printf("Enter the ID of the product you want to modify: \n");
	scanf("%d", &id);

	index = id_search(product, size, id);

	if(index != -1)
	{
		data_print_s(product[index]);
		printf("is this one you lil' piece of shit? (yes / no)");
		scanf("%[^\n]", confirmation);

		if(stricmp(confirmation,"yes") == 0)
		{
			newer = product[index];
			switch(mod_menu())
			{
				case 1:
					printf("Enter the new description: \n");
					scanf("%[^\n]", newer.description);
					break;

				case 2:
					printf("Enter the new origin");
					scanf("%d", &newer.origin);
					break;

				case 3:
					printf("Enter the new type");
					scanf("%d", &newer.type);
					break;

				case 4:
					printf("Enter the new price");
					scanf("%d", &newer.p_price);
					break;
			}

			product[index] = newer;

		}

	}

	return index;
}

int mod_menu()
{
	int option;

	printf("\n1. Description modification.");
	printf("\n2. Origin modification.");
    printf("\n3. Type modification.");
    printf("\n4. Price modification.");
    printf("\n5. Exit . . .");

    scanf("%d", &option);

    return option;
}
