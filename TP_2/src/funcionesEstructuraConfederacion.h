/*
 * funcionesEstructuraConfederacion.h
 *
 *  Created on: 20 oct. 2022
 *      Author: leand
 */
#include "utn.h"

#ifndef FUNCIONESESTRUCTURACONFEDERACION_H_

typedef struct{
	int idConfederacion;
	char nombre[50];
	char region[50];
	int anioCreacion;
	short IsEmpty;
}eConfederacion;

#define FUNCIONESESTRUCTURACONFEDERACION_H_

/**
 * \fn int InicializacionStructConfederaciones(eConfederacion[], int)
 * \brief Recibe por parametro la estructura, dentro de la misma
 *  el estado IsEmpty lo inicializa en 0
 *
 * \param confederacion Struct Confederacion
 * \param tamConfederacion Tamaño de La struct Confederacion
 * \return Devuelve 1 en caso exitoso o 0 en caso de fallo
 */
int InicializacionStructConfederaciones(eConfederacion confederacion[],int tamConfederacion);

//int BuscarStructIndiceIsEmptyConfederacion(eConfederacion confederacion[],int tamConfederacion,int* indice);

/**
 * \fn int BuscarStructIndiceLLENOConfederacion(eConfederacion[], int)
 * \brief  Verifica que el parametro IsEmpty sea 1 que significa que existen datos guardados, retorno 1 en caso de
 * existir datos o 0 en caso de no existir ningun dato
 *
 * \param confederacion Struct Confederacion
 * \param tamConfederacion Tamaño de La struct Confederacion
 * \return Devuelve 1 en caso exitoso o 0 en caso de fallo
 */
int BuscarStructIndiceLLENOConfederacion(eConfederacion confederacion[],int tamConfederacion);

//int BuscarIdConfederacion(eConfederacion confederacion[],int tamConfederacion,int* idConfederacion);

/**
 * \fn int AltaStructConfederacion(eConfederacion[], int, int*)
 * \brief Funcion principal en el main de confederacion, dentro de la misma se ejecuta la logica de alta, pidiendo al usuario
 * el ingreso de los datos que se piden y guardandolos en la struct confederacion
 *
 * \param confederacion Struct Confederacion
 * \param tamConfederacion  Tamaño de La struct Confederacion
 * \param idAutoincremental
 * \return Devuelve 1 en caso exitoso o 0 en caso de fallo
 */
int AltaStructConfederacion(eConfederacion confederacion[],int tamConfederacion,int* idAutoincremental);

/**
 * \fn int BajaStructConfederacion(eConfederacion[], int)
 * \brief Funcion principal en el main de confederacion, dentro de la misma le muestra al usuario una lista de las
 * conferaciones, despues de ello se le pide que ingrese la ID de la confederacion que desea dar de baja
 *
 * \param confederacion Struct Confederacion
 * \param tamConfederacion Tamaño de La struct Confederacion
 * \return Devuelve 1 en caso exitoso o 0 en caso de fallo
 */
int BajaStructConfederacion(eConfederacion confederacion[],int tamConfederacion);

/**
 * \fn int ModificacionStructConfederacion(eConfederacion[], int)
 * \brief Funcion principal en el main de confederacion, dentro de la misma muestra al usuario una lista de las
 * confederaciones, despues de ello se le pide que ingrese la Id de la confederacion que desea modificar, al ingresar
 * una id valida mostrara un menu de opciones con las diferentes opciones que se pueden modificar
 *
 * \param confederacion Struct Confederacion
 * \param tamConfederacion Tamaño de La struct Confederacion
 * \return Devuelve 1 en caso exitoso o 0 en caso de fallo
 */
int ModificacionStructConfederacion(eConfederacion confederacion[],int tamConfederacion);

/**
 * \fn void MostrarStructConfederaciones(eConfederacion[], int)
 * \brief Muestra una lista de los datos que contiene dentro la struct confederacion
 *
 * \param confederacion Struct Confederacion
 * \param tamConfederacion Tamaño de La struct Confederacion
 */
void MostrarStructConfederaciones(eConfederacion confederacion[],int tamConfederacion);



#endif /* FUNCIONESESTRUCTURACONFEDERACION_H_ */
