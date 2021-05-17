#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"


int menu(void)
{
    int opcion;
    printf("\n1. Ingresar 1er operando");
    printf("\n2. Ingresar 2do operando");
    printf("\n3. Calcular todas las operaciones");
    printf("\n4. Informar resultados");
    printf("\n5. Salir \n¿Qué operación desea realizar?: ");


    scanf("%d", &opcion);

    return opcion;
}


float numero1(void)
{
	float num1;
	printf ("Ingrese un operador \n");
	scanf ("%f", &num1);

	return num1;
}

float numero2(void)
{
	float num2;
	printf("Ingrese un operador \n");
	scanf("%f", &num2);

	return num2;
}

float sumar(float num1, float num2)
{
    float restultado_S;
    restultado_S = (float) num1 + num2;

    return restultado_S;
}

float restar(float num1, float num2)
{
	float resultado_R;
	resultado_R = (float) num1 - num2;

    return resultado_R;
}

float dividir(float num1, float num2)
{
	float resultado_D;
	resultado_D = (float) num1 / num2;

	   return resultado_D;
}

float multiplicar(float num1, float num2)
{
	float resultado_M;
	resultado_M = (float) num1 * num2;

    return resultado_M;
}



unsigned long int Factorial(int);
{
	unsigned long int fac;

	if(a==1||a==0)
	{
		fac=1;
	}
	else
	{
		fac= a*Factorial(a-1);
	}

	return fac;
}
	
