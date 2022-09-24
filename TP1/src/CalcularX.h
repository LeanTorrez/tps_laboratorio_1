/*
 * CalcularX.h
 *
 *  Created on: 4 sep. 2022
 *      Author: leand
 */

#ifndef CALCULARX_H_
#define CALCULARX_H_
#include <stdio.h>

/**
 * \fn int CalcularSumarEntero(int, int, int)
 * \brief suma los tres numero que entran por parametro
 *
 * \param num1 primer numero
 * \param num2 segundo numero
 * \param num3 tercer numero
 * \return devuelve un resultado entero
 */
int CalcularSumarEntero(int num1, int num2,int num3);

/**
 * \fn float CalcularSumarFloat(float, float, float)
 * \brief suma los tres numeros flotantes que entran por parametro
 *
 * \param num1 primer numero
 * \param num2 segundo numero
 * \param num3 tercer numero
 * \return devuelve un resultado float
 */
float CalcularSumarFloat(float num1,float num2,float num3);

/**
 * \fn float CalcularPorcentaje(int, int)
 * \brief recibe dos numeros por parametro; el primero se multiplica por 100, y el resultado se lo divide por el segundo parametro
 *
 * \param numeroPorcentaje el numero que se quiere obtener el porcentaje
 * \param contadorTotal el numero por el cual se necesita dividir para obtener el porcentaje
 * \return devuelve el porcentaje como float
 */
float CalcularPorcentaje(int numeroPorcentaje,int contadorTotal);

/**
 * \fn float CalcularPromedio(int, int)
 * \brief Ingresa dos numero de los cuales uno de ellos sera el acumalador que sera el divisor, por el cual sera divido con
 * contadorTotal que sera el dividendo
 *
 * \param acumulador El parametro que sera divisor
 * \param contadorTotal El parametro que sera el dividendo
 * \return devuelve el resultado del promedio
 */
float CalcularPromedio(int acumulador,int contadorTotal);

/**
 * \fn float CalcularMultiplicar(float, float)
 * \brief recibe dos numeros los cuales los multiplica entre si
 *
 * \param num1 primer numero
 * \param num2 segundo numero
 * \return devuelve el resultado de multiplicacion
 */
float CalcularMultiplicar(float num1,float num2);

#endif /* CALCULARX_H_ */
