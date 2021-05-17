/**
 =======================================================================================================================================================================================================
 Name        : Ejercicio 10-3:
 Author      : Lautaro Ezequiel Novelli
 Version     :
 Copyright   : 
 Description : 	Una empresa importadora que comercializa productos Apple, decide registrar de sus productos los siguientes datos:
						idProducto (numerico)
						descripcion (alfanumérico)
						nacionalidad (numérico, por el momento utilizaremos un define: EEUU - CHINA - OTRO)
						tipo (numérico)
						precio (numérico decimal)

				Agregar la estructura etipoProducto, que definirá los siguientes campos:
						idTipo (numérico)
						descripcionTipo(alfanumérico)


				Realizar un programa que permita interactuar con un menú de usuarios con las siguientes opciones:
					ALTA Producto:
						Se ingresan los datos de UN solo producto. Siempre y cuando haya espacio disponible en el array.
						Al momento de dar de alta el producto, el usuario podrá elegir el tipo de producto, de una lista que se le desplegará en pantalla.
					BAJA Producto:
						A partir del ingreso del ID. Si existe el producto desaparece de la lista, dejando espacio disponible para un nuevo producto.
					MODIFICACIÓN Producto:
						A partir del ingreso del ID. Si existe se podrá modificar el precio o el tipo. Si modifica el tipo de producto, se utilizara el mismo criterio que para dar de alta.
						LISTADO Productos.
						LISTADO ordenado por precio.
						LISTADO ordenado por descripción.

				Agregar los siguientes informes:
						El/los  productos más caros.
						Precio promedio por tipo de producto. Se deberá mostrar la descripción del tipo y a continuación el precio promedio.
						Se agregan los siguientes listados:
						El listado de todos los productos con la descripción del tipo.
						Por cada tipo la lista de productos.

 ======================================================================================================================================================================================================
 **/


#include <stdio.h>
#include <stdlib.h>
#define X
#define Z
#define Y


typedef struct
{
	int nacionalidad;
	char origen[15];
}origen;

typedef struct
{
	int type;
	char desc[15];

}product_type;

typedef struct
{
	int producto;
	char descripcion[15];
	int nacionalidad;
	int type;
	float precio;
	int isEmpty;

}registro;





void inicio (registro lista[], int tam);
int busqueda(registro lsita[], int tam);
registro data_intake();

int main(void)
{
	setbuf(stdout, NULL);
	int i;
	int load;
	registro producto[X];
	product_type Tipo_Producto[Z] = {{1000. "iPhone"}, {1001, "iPad"}, {1002, "Mac"}, {1003, "Accesorios"}};
	origen nacionalidad[Y] = {{1, "U.S"}, {2, "China"}, {3, "Otro"}};

	start(producto, X);



	show_data(produtco, X, Tipo_Producto, Z, nacionalidad, Y);

	return EXIT_SUCCESS;
}


void inicio(registro lista[], int tam)
{
	int i;

	for(i = 0; i < tam, i ++)
		{
			lista[i].isEmpty = EMPTY;
		}
}

int busqueda_vacio(registro lista[], int tam)
{
	int i;
	int x = -1;

	for(lista[i].isEmpty == EMPTY)
	{
		x = 1;
		break;
	}
	return x;
}

registro data_intake()
{
	registro producto;

	printf("ingrese el ID del producto: ");
	scanf("%d", &producto.producto);
	printf("ingrese la descripcion: ");
	fflush(stdin);
	scanf("%[^\n]", &producto.descripcion);
	printf("ingrese el origen del producto: (1 = U.S; 2 = China; 3 = Otro) ");
	scanf("%d", &producto.nacionalidad);
	printf("ingrese el tipo del producto: ");
	scanf("%d", &producto.type);
	printf("ingrese el precio del producto: ");
	scanf("%f", &producto.precio);

	producto.isEmpty = BUSY;

	return producto;
}



