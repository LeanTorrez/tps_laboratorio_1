/*
 * utn.c
 *
 *  Created on: 29 sep. 2022
 *      Author: leand
 */

#include "utn.h"


static int esDescripcion(char* cadena,int longitud);
static int getDescripcion(char* pResultado, int longitud);

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
 * excepcion del - (negativo), en este caso es un numero Int.
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
 * \fn int getShort(short*)
 * \brief crea un buffer adonde se verificara si la cadena de numeros sea en numero y no letras signos, a
 * excepcion del - (negativo), en este caso es un numero Short.
 *
 * \param pResultado Puntero adonde se guarda la cadena en caso exitoso
 * \return 1 en caso de exito, 0 en caso de error
 */
static int getShort(short* pResultado){
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

/**
 * \brief Obtiene un string valido como descripcion
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero flotante y -1 (ERROR) si no
 *
 */
static int getDescripcion(char* pResultado, int longitud)
{
    int retorno=-1;
    char buffer[4096];

    if(pResultado != NULL)
    {
    	if(	getString(buffer,sizeof(buffer))==0 &&
    		esDescripcion(buffer,sizeof(buffer))==1 &&
			strnlen(buffer,sizeof(buffer))<longitud)
    	{
    		strncpy(pResultado,buffer,longitud);
			retorno = 0;
		}
    }
    return retorno;
}

/**
 * \brief Verifica si la cadena ingresada es una descripcion valida
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (verdadero) si la cadena es valida y 0 (falso) si no lo es
 *
 */
static int esDescripcion(char* cadena,int longitud)
{
	int i=0;
	int retorno = -1;
	if(cadena != NULL && longitud > 0)
	{
		if(!(strlen(cadena) == 0 && cadena[0] == '\0'))
		{
			retorno =1;
			for(i=0 ; cadena[i] != '\0' && i < longitud; i++)
			{
				if(cadena[i] != ' ' && (cadena[i] < 'A' || cadena[i] > 'Z' ) && (cadena[i] < 'a' || cadena[i] > 'z' ))
				{
					retorno = 0;
					break;
				}
			}
		}
	}
	return retorno;
}

int utn_getDescripcion(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos)
{
	char bufferString[4096];
	int retorno = -1;
	while(reintentos>=0)
	{
		reintentos--;
		printf(mensaje);
		if(getDescripcion(bufferString,sizeof(bufferString)) == 0 && strnlen(bufferString,sizeof(bufferString)) < longitud )
		{
			strncpy(pResultado,bufferString,longitud);
			retorno = 0;
			break;
		}
		printf(mensajeError);
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

int utn_getNumeroShort(short* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos){
	int retorno = 0;
	short bufferShort;
	printf(mensaje);
	while(reintentos > 0){
		if(getShort(&bufferShort)==1){
			if(bufferShort >= minimo && bufferShort <= maximo){
				*pResultado = bufferShort;
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
	fflush(stdin);
	return letra;
}
