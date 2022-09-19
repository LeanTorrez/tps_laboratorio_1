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
 * \brief Ingresa tres numeros enteros que quiere sumar
 *
 * \param num1 ingreso de los numero a subar
 * \param num2 ingreso de los numero a subar
 * \param num3 ingreso de los numero a subar
 * \return devuelve el resultado de la suma como entero
 */
int CalcularSumarEntero(int num1, int num2,int num3);

/**
 * \fn float CalcularSumarFloat(float, float, float)
 * \brief Ingresa tres numeros float que quiere sumar
 *
 * \param num1 ingreso de los numero a subar
 * \param num2 ingreso de los numero a subar
 * \param num3 ingreso de los numero a subar
 * \return devuelve el resultadod de la suma como float
 */
float CalcularSumarFloat(float num1,float num2,float num3);

/**
 * \fn float CalcularPorcentaje(int, int)
 * \brief ingresa dos numero de los cuales el primer parametro se lo multiplica por 100
 * 		  y despues se lo divide por el segundo parametro
 *
 * \param numeroPorcentaje El numero que desea sacar el porcentaje
 * \param contadorTotal El numero al cual se dividira el resultado del numeroPorcentaje
 * \return devuelve el un float que sera el indicativo del porcentaje.
 */
float CalcularPorcentaje(int numeroPorcentaje,int contadorTotal);

float CalcularMultiplicar(float num1,float num2);

#endif /* CALCULARX_H_ */
