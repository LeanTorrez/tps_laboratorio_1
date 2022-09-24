/*
 * UTNinputs.c
 *
 *  Created on: 15 sep. 2022
 *      Author: leand
 */
#include "UTNinputs.h"
#include <ctype.h>

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

int utn_getNumeroFLOAT(float* pResultado,char* mensaje,char* mensajeError,float minimo,float maximo,int reintentos){
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
