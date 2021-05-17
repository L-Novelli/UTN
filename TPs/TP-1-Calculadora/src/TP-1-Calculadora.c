/*
 ============================================================================
 Name        : TP-1-Calculadora.c
 Author      : Lautaro Ezequiel Novelli
============================================================================
 *
 * 1. Ingresar 1er operando (A=x)
 * 2. Ingresar 2do operando (B=y)
 * 3. Calcular todas las operaciones
 *    a) Calcular la suma (A+B)
 *    b) Calcular la resta (A-B)
 *    c) Calcular la division (A/B)
 *    d) Calcular la multiplicacion (AB)
 *    e) Calcular el factorial (A!)
 * 4. Informar resultados
 *    a) “El resultado de A+B es: r”
 *    b) “El resultado de A-B es: r”
 *    c) “El resultado de A/B es: r” o “No es posible dividir por cero”
 *    d) “El resultado de AB es: r”
 *    e) “El factorial de A es: r1 y El factorial de B es: r2”
 * 5. Salir
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define REALIZADO 1
#define NO_REALIZADO 0


int main (void)
{
	float operando1;
	float operando2;
	int seleccion;
	float suma;
	float resta;
	float division;
	float multip;
	unsigned long int factorA;
	unsigned long int factorB;
	float flagNum1;
	float flagNum2;
	char respuesta;

	respuesta = 's';

	setbuf(stdout, NULL);


	do
	{
		seleccion = menu();

		switch (seleccion)
		{

			case 1:
				operando1 = numero1();
				flagNum1 = REALIZADO;
				break;

			case 2:
				operando2 = numero2();
				flagNum2 = REALIZADO;
				break;

			case 3:
				if (flagNum2 == REALIZADO && flagNum1 == REALIZADO)
				{
					suma = sumar(operando1, operando2);
					resta = restar(operando1,operando2);
					division = dividir(operando1,operando2);
					multip = multiplicar(operando1,operando2);
					factorA=Factorial(operando1);
					factorB=Factorial(operando2);
					printf(" < <  C A R G A N D O   R E S U L T A D O S  > >");

				}
				else
				{
					printf("ERROR! Debe ingresar el segundo numero antes \n");
				}
				break;


			case 4:

					printf ("la suma de %.2f + %.2f es : %.2f", operando1, operando2, suma);
					printf ("\nla resta de %.2f - %.2f es: %.2f ", operando1, operando2, resta);
					printf ("\nla division de %.2f / %.2f es: %.2f ", operando1, operando2, division);
					printf ("\nla multiplicacion entre %f x %f es: %.2f ", operando1, operando2, multip);
					printf("\nEl factorial de %d! es: %ld y El factorial de %d! es: %ld\n",(int)operando1,factorA,(int)operando2,factorB);	
				break;

			case 5:
				printf("ご利用いただきありがとうございます。");
				respuesta = 'n';
				break;
			}
	}
	while(respuesta == 's');

	return 0;

}
