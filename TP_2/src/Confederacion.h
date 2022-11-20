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
 * \fn int confe_inicializacionStruct(eConfederacion[], int)
 * \brief Recibe por parametro la estructura, dentro de la misma
 *  el estado IsEmpty lo inicializa en 0
 *
 * \param confederacion Struct Confederacion
 * \param tamConfederacion Tamaño de La struct Confederacion
 * \return Devuelve 1 en caso exitoso o 0 en caso de fallo
 */
int confe_inicializacionStruct(eConfederacion confederaciones[],int tamConfederacion);

/**
 * \fn int confe_buscarIndiceLlENO(eConfederacion[], int)
 * \brief  Verifica que el parametro IsEmpty sea 1 que significa que existen datos guardados, retorno 1 en caso de
 * existir datos o 0 en caso de no existir ningun dato
 *
 * \param confederacion Struct Confederacion
 * \param tamConfederacion Tamaño de La struct Confederacion
 * \return Devuelve 1 en caso exitoso o 0 en caso de fallo
 */
int confe_buscarIndiceLlENO(eConfederacion confederaciones[],int tamConfederacion);

/**
 * \fn int confe_alta(eConfederacion[], int, int*)
 * \brief Funcion principal en el main de confederacion, dentro de la misma se ejecuta la logica de alta, pidiendo al usuario
 * el ingreso de los datos que se piden y guardandolos en la struct confederacion
 *
 * \param confederacion Struct Confederacion
 * \param tamConfederacion  Tamaño de La struct Confederacion
 * \param idAutoincremental
 * \return Devuelve 1 en caso exitoso o 0 en caso de fallo
 */
int confe_alta(eConfederacion confederaciones[],int tamConfederacion,int* idAutoincremental);

/**
 * \fn int confe_baja(eConfederacion[], int)
 * \brief Funcion principal en el main de confederacion, dentro de la misma le muestra al usuario una lista de las
 * conferaciones, despues de ello se le pide que ingrese la ID de la confederacion que desea dar de baja
 *
 * \param confederacion Struct Confederacion
 * \param tamConfederacion Tamaño de La struct Confederacion
 * \return Devuelve 1 en caso exitoso o 0 en caso de fallo
 */
int confe_baja(eConfederacion confederaciones[],int tamConfederacion);

/**
 * \fn int confe_modificacion(eConfederacion[], int)
 * \brief Funcion principal en el main de confederacion, dentro de la misma muestra al usuario una lista de las
 * confederaciones, despues de ello se le pide que ingrese la Id de la confederacion que desea modificar, al ingresar
 * una id valida mostrara un menu de opciones con las diferentes opciones que se pueden modificar
 *
 * \param confederacion Struct Confederacion
 * \param tamConfederacion Tamaño de La struct Confederacion
 * \return Devuelve 1 en caso exitoso o 0 en caso de fallo
 */
int confe_modificacion(eConfederacion confederaciones[],int tamConfederacion);

/**
 * \fn void confe_mostrar(eConfederacion[], int)
 * \brief Muestra una lista de los datos que contiene dentro la struct confederacion
 *
 * \param confederacion Struct Confederacion
 * \param tamConfederacion Tamaño de La struct Confederacion
 */
void confe_mostrar(eConfederacion confederaciones[],int tamConfederacion);

/**
 * \fn int confe_buscarId(eConfederacion[], int, int, int*)
 * \brief Busca el indice de una confederacion en base a su id
 *
 * \param confederaciones struct confederacion
 * \param tamConfederacion Tamaño de La struct Confederacion
 * \param idConfederacion id de la confederaciona buscar
 * \param pIdConfederacion puntero adonde se guardara el indice de la confederacion en cuestion
 * \return Devuelve 1 en caso exitoso o 0 en caso de fallo
 */
int confe_buscarId(eConfederacion confederaciones[],int tamConfederacion,int idConfederacion,int* pIdConfederacion);


#endif /* FUNCIONESESTRUCTURACONFEDERACION_H_ */
