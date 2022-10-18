/*
 * utn.c
 *
 *  Created on: 29 sep. 2022
 *      Author: leand
 */

#include "utn.h"

/**
 * \fn int myGets(char*, int)
 * \brief Verifica que la cadena de caracteres no sea NULA y que no supere el maximo de caracteres pedidos
 * a su vez al final de la cadena se reemplaza \-n por \-0 para marca el final de la cadena
 *
 * \param cadena la cadena que desea verificar
 * \param longitud la longitud de la cadena que desea verificar que no sobrepase
 * \return 1 en caso de exito, 0 en caso de error
 */
static int myGets(char* cadena, int longitud){
	int retorno=0;
	if(cadena != NULL && longitud >0 && fgets(cadena,longitud,stdin)==cadena){
		fflush(stdin);
		if(cadena[strlen(cadena)-1] == '\n'){
			cadena[strlen(cadena)-1] = '\0';
		}
		retorno = 1;
	}
	return retorno;
}

/**
 * \fn int getString(char*, int)
 * \brief crea un buffer de la cadena pedida y verifica los con myGets y en caso de ser exitoso se copia la cadena
 * al puntero de la variable
 *
 * \param pString Puntero a la cadena adonde se guarda en caso exitoso
 * \param tamString El tamaño que tiene la variable pString
 * \return 1 en caso de exito, 0 en caso de error
 */
static int getString(char* pString, int tamString){
	int retorno = 0;
	char buffer[tamString];
	if(myGets(buffer,sizeof(buffer))==1){
		strcpy(pString,buffer);
		retorno=1;
	}
	return retorno;
}

/**
 * \fn int esNumerica(char*)
 * \brief Ingresa un cadena y se verifica que contenga numeros y no caracteres, obviando en caso que el mismo
 * sea un numero negativo
 *
 * \param cadena la cadena de caracteres que debera contener numero para ser verificada
 * \return 1 en caso de exito, 0 en caso de error
 */
static int esNumerica(char* cadena){
	int i;
	int retorno = 1;

	if(cadena[0] == '-'){
		i = 1;
	}else{
		i = 0;
	}

	for(;cadena[i] != '\0';i++){
		if(cadena[i] < '0' || cadena[i] > '9' ){
			retorno = 0;
			break;
		}
	}
	return retorno;
}

/**
 * \fn int getInt(int*)
 * \brief crea un buffer adonde se verificara si la cadena de numeros sea en numero y no letras signos, a
 * excepcion del - (negativo)
 *
 * \param pResultado Puntero adonde se guarda la cadena en caso exitoso
 * \return 1 en caso de exito, 0 en caso de error
 */
static int getInt(int* pResultado){
	int retorno = 0;
	char buffer[64];
	myGets(buffer,sizeof(buffer));
	if(esNumerica(buffer)){
		*pResultado = atoi(buffer);
		retorno=1;
	}
	return retorno;
}

/**
 * \fn int esNumericaFloat(char*)
 * \brief Ingresa un cadena y se verifica que contenga numeros y no caracteres, obviando en caso que el mismo
 * sea un numero negativo, agregando ademas que el mismo contenga un '.' para verificar si es numero float
 *
 * \param cadena la cadena de caracteres que debera contener numero para ser verificada
 * \return 1 en caso de exito, 0 en caso de error
 */
static int esNumericaFloat(char* cadena){
	int i;
	int retorno = 1;
	int flagPunto = 1;

	if(cadena[0] == '-'){
		i = 1;
	}else{
		i = 0;
	}

	for(;cadena[i] != '\0';i++){
		if(cadena[i] == '.' && cadena[i+1] != '\0'){
			if(flagPunto){
				flagPunto = 0;
			}else{
				retorno = 0;
				break;
			}
		}else{
			if(cadena[i] < '0' || cadena[i] > '9' ){
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

/**
 * \fn int getFloat(float*)
 * \brief  crea un buffer adonde se verificara si la cadena de numeros sea en numero y no letras signos, a
 * excepcion del '-' (negativo) y el '.'
 *
 * \param pResultado Puntero adonde se guarda la cadena en caso exitoso
 * \return 1 en caso de exito, 0 en caso de error
 */
static int getFloat(float* pResultado){
	int retorno = 0;
	char buffer[64];
	myGets(buffer,sizeof(buffer));
	if(esNumericaFloat(buffer)){
		*pResultado = atof(buffer);
		retorno=1;
	}
	return retorno;
}

int utn_getNumeroINT(int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos){
	int retorno = 0;
	int bufferInt;
	printf(mensaje);
	while(reintentos > 0){
		if(getInt(&bufferInt)==1){
			if(bufferInt >= minimo && bufferInt <= maximo){
				*pResultado = bufferInt;
				retorno = 1;
				break;
			}
		}
		reintentos--;
		printf(mensajeError);
	}
	return retorno;
}

int utn_getString(char* pString,int tamString,char* mensaje, char* mensajeError,int reintentos){
	int retorno = 0;
	char bufferString[tamString];
	printf(mensaje);
	while(reintentos > 0){
		if(getString(bufferString,tamString)==1){
			strcpy(pString,bufferString);
			retorno = 1;
			break;
		}
		reintentos--;
		printf(mensajeError);
	}
	return retorno;
}

int utn_getNumeroFLOAT(float* pResultado,char* mensaje,char* mensajeError,float minimo,float maximo,int reintentos){
	int retorno = 0;
	float bufferFloat;
	printf(mensaje);
	while(reintentos > 0){
		if(getFloat(&bufferFloat)==1){
			if(bufferFloat >= minimo && bufferFloat <= maximo){
				*pResultado = bufferFloat;
				retorno = 1;
				break;
			}
		}
		reintentos--;
		printf(mensajeError);
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
