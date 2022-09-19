/*
 * UTNinputs.c
 *
 *  Created on: 15 sep. 2022
 *      Author: leand
 */
#include "UTNinputs.h"
#include <ctype.h>
/**
 * \fn int utn_getNumeroINT(int*, char*, char*, int, int, int)
 * \brief Pide un numero entero y verifica que el numero que se ingresa sea un numero entre los limites
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
int utn_getNumeroINT(int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos){
	int retorno;
	int numero;
	printf(mensaje);
	while(reintentos > 0){
		if(scanf("%d",&numero)==1){
			if(numero > minimo && numero < maximo){
				break;
			}
		}
		fflush(stdin);
		reintentos--;
		printf(mensajeError);
	}
	if(reintentos == 0){
		retorno = -1;
	}else{
		retorno = 0;
		*pResultado = numero;
	}
	return retorno;
}

/**
 * \fn float utn_getNumeroFLOAT(float*, char*, char*, float, float, int)
 * \brief Pide un numero float y verifica que el numero que se ingresa sea un numero entre los limites
 * y que el mismo no sea un caracter
 * \param pResultado puntero a la variable donde se guardara el numero
 * \param mensaje mensaje que el usuaria podra ver
 * \param mensajeError mensaje que el usuaria podra ver en caso de error
 * \param minimo El minimo del numero a ser devuelto
 * \param maximo El maximo del numero a ser devuelto
 * \param reintentos la cantidad de veces que el usuario puede fallar el ingreso del numero
 * \return devuelve -1 en caso de fallar la carga o 0 en caso de guardar el numero con exito
 */
float utn_getNumeroFLOAT(float* pResultado,char* mensaje,char* mensajeError,float minimo,float maximo,int reintentos){
	int retorno;
	float numero;
	printf(mensaje);
	while(reintentos > 0){
		if(scanf("%f",&numero)==1){
			if(numero > minimo && numero < maximo){
				break;
			}
		}
		fflush(stdin);
		reintentos--;
		printf(mensajeError);
	}
	if(reintentos == 0){
		retorno = -1;
	}else{
		retorno = 0;
		*pResultado = numero;
	}
	return retorno;
}

/**
 * \fn char ConfirmarChar(char[], char[], char, char)
 * \brief Verifica que el caracter sea uno de los dos que se pide
 *
 * \param mensaje mensaje para el usuario
 * \param mensajeError en caso de error el mensaje al usuario
 * \param validacion1 el primer caracter a validar
 * \param validacion2 el segundo caracter a validar
 * \return
 */
char ConfirmarChar(char mensaje[],char mensajeError[],char validacion1,char validacion2){
	char letra;
	printf(mensaje);
	fflush(stdin);
	scanf("%c",&letra);
	letra = toupper(letra);
	while(letra != validacion1 && letra != validacion2){
		printf(mensajeError);
		fflush(stdin);
		scanf("%c",&letra);
		letra = toupper(letra);
	}
	return letra;
}
