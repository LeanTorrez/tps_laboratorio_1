/*
 * CalcularX.c
 *
 *  Created on: 4 sep. 2022
 *      Author: leand
 */

#include "CalcularX.h"

int CalcularSumarEntero(int num1, int num2,int num3){
	int resultado;
	resultado = num1 + num2 + num3;
	return resultado;
}

float CalcularSumarFloat(float num1,float num2,float num3){
	float resultado;
	resultado = num1 + num2 + num3;
	return resultado;
}

float CalcularPorcentaje(int numeroPorcentaje, int contadorTotal){
	float resultado;
	resultado = ((float) numeroPorcentaje * 100) / contadorTotal;
	return resultado;
}

float CalcularMultiplicar(float num1,float num2){
	float resultado;
	resultado = num1 * num2;
	return resultado;
}
