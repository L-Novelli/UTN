#ifndef FUNCIONES_H_
#define FUNCIONES_H_

	float numero1(void);
/**
 * @fn float numero1(void);
 * @brief Función para pedir el segundo valor de operando
 *
 * @return Devuelve el valor del segundo operando
 */
	float numero2(void);
/**
 * @fn float numero2(void);
 * @brief Función que suma dos flotantes
 *
 * @param float a Primer número flotante
 * @param float b Segundo número flotante
 * @return float suma Devuelve el valor de la suma entre dos flotantes
 */
	float sumar(float num1, float num2);
/**
 * @fn sumar(float num1, float num2);
 * @brief Función que suma dos flotantes
 *
 * @param float a Primer número flotante
 * @param float b Segundo número flotante
 * @return float suma Devuelve el valor de la suma entre dos flotantes
 */
	float restar(float num1, float num2);
/**
 * @fn float restar(float num1, float num2);
 * @brief Función que resta dos flotantes
 *
 * @param float a Primer número flotante
 * @param float b Segundo número flotante
 * @return float resta Devuelve el valor de la resta entre dos flotantes
 */
	float dividir(float num1, float num2);

/**
 * @fn float dividir(float num1, float num2);
 * @brief Función que divide dos flotantes
 *
 * @param float a Primer número flotante
 * @param float b Segundo número flotante
 * @return float division Devuelve el valor de la division entre dos flotantes
 */
	float multiplicar(float num1, float num2);
/**
 * @fn float multiplicar(float num1, float num2);
 * @brief Función que multiplica dos flotantes
 *
 * @param float a Primer número flotante
 * @param float b Segundo número flotante
 * @return float multiplicación Devuelve el valor de la multiplicación entre dos flotantes
 */

 unsigned long int Factorial(int);

/**
 * @fn unsigned long int Factorial(int)
 * @brief Función que busca el factorial de un numero entero
 *
 * @param int a Número entero
 * @return unsigned long int Devuelve el valor del factorial del número entero
 */
	int menu(void);
/**
 * @fn int Menu(float, float)
 * @brief Menu principal interactivo
 *
 * @param float x Recibe un número mediante parámetros
 * @param float y Recibe un número mediante parámetros
 * @return int Retorna una opción del 1 al 5 para el switch
 */

#endif /* FUNCIONES_H_ */
