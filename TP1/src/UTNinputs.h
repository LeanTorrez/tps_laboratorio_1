/*
 * UTNinputs.h
 *
 *  Created on: 15 sep. 2022
 *      Author: leand
 */

#ifndef UTNINPUTS_H_
#define UTNINPUTS_H_
#include <stdio.h>
#include <stdlib.h>

int utn_getNumeroINT(int* pResultado,
		char* mensaje,
		char* mensajeError,
		int minimo,int maximo,
		int reintentos);

float utn_getNumeroFLOAT(float* pResultado,
		char* mensaje,
		char* mensajeError,
		float minimo,float maximo,
		int reintentos);

char ConfirmarChar(char mensaje[],
		char mensajeError[],
		char validacion1,
		char validacion2);

#endif /* UTNINPUTS_H_ */
