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

/**
 * \fn int utn_getNumeroINT(int*, char*, char*, int, int, int)
 * \brief Pide un numero entero y verifica que el numero que se ingresa sea un numero entre los limites
 *  y que el mismo no sea un caracter
 *
 * \param pResultado puntero a la variable donde se guardara el numero
 * \param mensaje mensaje que el usuaria podra ver
 * \param mensajeError mensaje que el usuaria podra ver en caso de error
 * \param minimo El minimo del numero a ser devuelto
 * \param maximo El maximo del numero a ser devuelto
 * \param reintentos la cantidad de veces que el usuario puede fallar el ingreso del numero
 * \return devuelve -1 en caso de fallar la carga o 0 en caso de guardar el numero con exito
 */
int utn_getNumeroINT(int* pResultado,
		char* mensaje,
		char* mensajeError,
		int minimo,int maximo,
		int reintentos);

/**
 * \fn int utn_getNumeroFLOAT(float*, char*, char*, float, float, int)
 * \brief Pide un numero float y verifica que el numero que se ingresa sea un numero entre los limites
 * y que el mismo no sea un caracter
 *
 * \param pResultado puntero a la variable donde se guardara el numero
 * \param mensaje mensaje que el usuaria podra ver
 * \param mensajeError mensaje que el usuaria podra ver en caso de error
 * \param minimo El minimo del numero a ser devuelto
 * \param maximo El maximo del numero a ser devuelto
 * \param reintentos la cantidad de veces que el usuario puede fallar el ingreso del numero
 * \return devuelve -1 en caso de fallar la carga o 0 en caso de guardar el numero con exito
 */
int utn_getNumeroFLOAT(float* pResultado,
		char* mensaje,
		char* mensajeError,
		float minimo,float maximo,
		int reintentos);

/**
 * \fn char ConfirmarChar(char[], char[], char, char)
 * \brief Verifica que el caracter sea uno de los dos que se pide
 *
 * \param mensaje mensaje para el usuario
 * \param mensajeError  en caso de error el mensaje al usuario
 * \param validacion1 el primer caracter a validar
 * \param validacion2 el segundo caracter a validar
 * \return retorna el caracter entre los dos caracteres posibles que entrar por parametro
 */
char ConfirmarChar(char mensaje[],
		char mensajeError[],
		char validacion1,
		char validacion2);

#endif /* UTNINPUTS_H_ */
