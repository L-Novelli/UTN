/**
 ============================================================================
 Name        :
 Author      : Lautaro Ezequiel Novelli
 Version     :
 Copyright   : 
 Description : 		Una empresa importadora que comercializa productos Apple, decide registrar de sus productos los siguientes datos:
					idProducto (numerico)
					descripcion (alfanumérico)
					nacionalidad (numérico, por el momento utilizaremos un define: EEUU - CHINA - OTRO)
					tipo (numérico, por el momento utilizaremos un define: IPHONE -MAC - IPAD - ACCESORIOS)
					precio (numérico decimal)
					Realizar un programa que permita interactuar con un menú de usuarios con las siguientes opciones:
					ALTA Producto: Se ingresan los datos de UN solo producto. Siempre y cuando haya espacio disponible en el array.
					BAJA Producto: A partir del ingreso del ID. Si existe el producto desaparece de la lista, dejando espacio disponible para un nuevo producto.
					MODIFICACIÓN Producto: A partir del ingreso del ID. Si existe se podrá modificar el precio o el tipo.
					LISTADO Productos.
					LISTADO ordenado por precio.
					LISTADO ordenado por descripción.
					Agregar los siguientes informes:
					El/los  productos más caros.
					Precio promedio por tipo de producto.

 ============================================================================
 **/


#include <stdio.h>
#include <stdlib.h>
#include "proto_sheet.h"

#define SIZE 10


int main()
{
	int op_menu;
	char keep_going;
	int data_value = 0;
	int id = 1000;

	Register producto[SIZE];
	start_up(producto, SIZE);
//	data_intake(producto, TAM);
//	muestra_data(producto, TAM);

	setbuf(stdout, NULL);

	keep_going = 's';
do
{

	op_menu = menu();

	switch(op_menu)
	{
		case 1:
			data_intake(producto, SIZE, &id);
			data_value = 1;
			break;

		 case 2:
			 product_mod(producto, SIZE);
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
			keep_going = 'n';
			break;
	}


}while(keep_going == 's');

	return EXIT_SUCCESS;
}






























































