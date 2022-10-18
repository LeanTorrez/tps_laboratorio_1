/*
 * utn.h
 *
 *  Created on: 29 sep. 2022
 *      Author: leand
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#ifndef UTN_H_
#define UTN_H_

/**
 * \fn int utn_getString(char*, int, char*, char*, int)
 * \brief Pide al usuario ingresar un texto
 *
 * \param pString Puntero a la ubicacion de la variable adonde se guardara el texto ingresado
 * \param tamString El tamaño que tiene como maximo el string que se ingresa
 * \param mensaje El mensaje que vera el usuario a la hora de ingresar los datos
 * \param mensajeError El mensaje en caso que no ingrese nada o que exceda el maximo de caracteres
 * \param reintentos La cantidad de reintentos que tiene el usuario para ingresar el texto
 * \return 1 en caso de exito, 0 en caso de fallo
 */
int utn_getString(char* pString,
		int tamString,
		char* mensaje,
		char* mensajeError,
		int reintentos);

/**
 * \fn int utn_getNumeroINT(int*, char*, char*, int, int, int)
 * \brief Pide al usuario ingresar un numero entre los numero pedidos
 *
 * \param pResultado Puntero a la ubicacion de la variable adonde se guardara el numero entero ingresado
 * \param mensaje mensaje que vera el usuario a la hora de ingresar los datos
 * \param mensajeError Mensaje de error en caso que el usuario ingrese algun dato erroneo
 * \param minimo el minimo que tiene que ser el numero pedido
 * \param maximo el maximo que tiene que ser el numero pedido
 * \param reintentos La cantidad de reintentos que tiene el usuario para ingresar el numero
 * \return 1 en caso de exito, 0 en caso de fallo
 */
int utn_getNumeroINT(int* pResultado,
		char* mensaje,
		char* mensajeError,
		int minimo,int maximo,
		int reintentos);

/**
 * \fn int utn_getNumeroFLOAT(float*, char*, char*, float, float, int)
 * \brief Pide al usuario ingresar un numero entro los pedidos, a diferencia de getnumeroInt en este caso acepta
 * numero Float
 *
 * \param pResultado Puntero a la ubicacion de la variable adonde se guardara el numero Float ingresado
 * \param mensaje mensaje que vera el usuario a la hora de ingresar los datos
 * \param mensajeError Mensaje de error en caso que el usuario ingrese algun dato erroneo
 * \param minimo el minimo que tiene que ser el numero pedido
 * \param maximo el maximo que tiene que ser el numero pedido
 * \param reintentos La cantidad de reintentos que tiene el usuario para ingresar el numero
 * \return 1 en caso de exito, 0 en caso de fallo
 */
int utn_getNumeroFLOAT(float* pResultado,
		char* mensaje,
		char* mensajeError,
		float minimo,float maximo,
		int reintentos);

/**
 * \fn char ConfirmarChar(char[], char[], char, char)
 * \brief Pide un caracter al usuario entre los dos que se piden a valirdar
 *
 * \param mensaje  mensaje que vera el usuario a la hora de ingresar los datos
 * \param mensajeError Mensaje de error en caso que el usuario ingrese algun dato erroneo
 * \param validacion1 El primer caracter que se validara al caracter ingresado
 * \param validacion2 El segundo caracter que se validara al caracter ingresado
 * \return Devuelve el caracter que ingreso el usuario, siendo unicamente uno de los dos que se validaron
 */
char ConfirmarChar(char mensaje[],
		char mensajeError[],
		char validacion1,
		char validacion2);

#endif /* UTN_H_ */
