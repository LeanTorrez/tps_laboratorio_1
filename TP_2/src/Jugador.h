/*
 * funcionesEstructuraJugador.h
 *
 *  Created on: 12 oct. 2022
 *      Author: leand
 */
#include "Confederacion.h"

#ifndef FUNCIONESESTRUCTURAJUGADOR_H_

typedef struct{
	int idJugador;
	char nombre[50];
	char posicion[50];
	short numeroCamiseta;
	int idConfederacion;
	float salario;
	short aniosContrato;
	short isEmpty;
}eJugador;

#define FUNCIONESESTRUCTURAJUGADOR_H_

/**
 * \fn int jug_inicializacionStruct(eJugador[], int)
 * \brief Recibe por parametro la estructura, dentro de la misma
 * el estado IsEmpty lo inicializa en 0
 *
 * \param jugador Struct Jugador
 * \param tamJugador Tamaño de La struct Jugador
 * \return Devuelve 1 en caso exitoso o 0 en caso de fallo
 */
int jug_inicializacionStruct(eJugador jugadores[],int tamJugador);

/**
 * \fn int jug_buscarIndiceLleno(eJugador[], int)
 * \brief Verifica que el parametro IsEmpty sea 1 que significa que existen datos guardados, retorno 1 en caso de
 * existir datos o 0 en caso de no existir ningun dato
 *
 * \param jugador Struct Jugador
 * \param tamJugador Tamaño de La struct Jugador
 * \return Devuelve 1 en caso exitoso o 0 en caso de fallo
 */
int jug_buscarIndiceLleno(eJugador jugadores[],int tamJugador);

/**
 * \fn int jug_alta(eJugador[], int, eConfederacion[], int, int*)
 * \brief Funcion principal en el main de Jugador, dentro de la misma se ejecuta la logica de alta, pidiendo al usuario
 * el ingreso de los datos que se piden y guardandolos en la struct jugador
 *
 * \param jugador Struct Jugador
 * \param tamJugador Tamaño de La struct Jugador
 * \param confederacion Struct Confederacion, Es Necesaria para mostrar la struct confederacion
 * al usuario
 * \param tamConfederacion Tamaño de La struct Confederacion
 * \param idAutoincremental Puntero a la variable autoincremental, esta misma le asignara el id a cada uno de los
 * jugadores
 * \return Devuelve 1 en caso exitoso o 0 en caso de fallo
 */
int jug_alta(eJugador jugadores[],int tamJugador,eConfederacion confederaciones[],int tamConfederacion,int* idAutoincremental);

/**
 * \fn int jug_baja(eJugador[], int, eConfederacion[], int)
 * \brief Funcion principal en el main de Jugador, dentro de la misma muestra al usuario una lista de los
 * jugadores, despues de ello se le pide que ingrese la Id del jugador que desea dar de baja, en caso de existir esa id
 * al parametro IsEmpty su valor pasara de 1 a 0
 *
 * \param jugador Struct Jugador
 * \param tamJugador Tamaño de La struct Jugador
 * \param confederacion Struct Confederacion, Es Necesaria para mostrar la struct confederacion
 * al usuario
 * \param tamConfederacion Tamaño de La struct Confederacion
 * \return Devuelve 1 en caso exitoso o 0 en caso de fallo
 */
int jug_baja(eJugador jugadores[],int tamJugador,eConfederacion confederaciones[],int tamConfederacion);

/**
 * \fn int jug_modificacion(eJugador[], int, eConfederacion[], int)
 * \brief Funcion principal en el main de jugadores, dentro de la misma muestra al usuario una lista de los jugadores,
 *  despues de ello se le pide que ingrese la Id del jugador que desea modificar, al ingresar
 * una id valida mostrara un menu de opciones con las diferentes opciones que se pueden modificar
 *
 * \param jugador Struct Jugador
 * \param tamJugador Tamaño de La struct Jugador
 * \param confederacion Struct Confederacion, Es Necesaria para mostrar la struct confederacion
 * al usuario
 * \param tamConfederacion Tamaño de La struct Confederacion
 * \return Devuelve 1 en caso exitoso o 0 en caso de fallo
 */
int jug_modificacion(eJugador jugadores[],int tamJugador,eConfederacion confederaciones[],int tamConfederacion);

/**
 * \fn void jug_ordenarPorId(eJugador[], int)
 * \brief Ordenado el listado de jugadores en forma ascendente en base a la id del jugador
 *
 * \param jugador Struct Jugador
 * \param tamJugador Tamaño de La struct Jugador
 */
void jug_ordenarPorId(eJugador jugadores[],int tamJugador);

/**
 * \fn void jug_mostrar(eJugador[], int, eConfederacion[], int)
 * \brief Muestra una lista con los datos que contiene la struct jugador
 *
 * \param jugador Struct Jugador
 * \param tamJugador Tamaño de La struct Jugador
 * \param confederacionStruct Confederacion, Es Necesaria para mostrar la confederacion
 * al usuario
 * \param tamConfederacion Tamaño de La struct Confederacion
 */
void jug_mostrar(eJugador jugadores[],int tamJugador,eConfederacion confederaciones[],int tamConfederacion);

/**
 * \fn int jug_mostrarUnJugador(eJugador[], int, eConfederacion[], int)
 * \brief muestra por consola a un solo jugador
 *
 * \param jugador jugador que se debera mostrar
 * \param indiceJug indice del jugador que se mostrara
 * \param confederaciones Struct de confederacion para generar relacion
 * \param tamConfe tamaño struct jugador
 * \return Devuelve 1 en caso exitoso o 0 en caso de fallo
 */
int jug_mostrarUnJugador(eJugador jugador[],int indiceJug,eConfederacion confederaciones[],int tamConfe);

/**
 * \fn int jug_swap(eJugador*, eJugador*)
 * \brief pasa por puntero los jugadores a los cuales se le cambiara de lugar en la estructura
 *
 * \param jugadorUno primer jugador
 * \param jugadorDos segundo jugador
 * \return Devuelve 1 en caso exitoso o 0 en caso de fallo
 */
int jug_swap(eJugador* jugadorUno,eJugador* jugadorDos);

#endif /* FUNCIONESESTRUCTURAJUGADOR_H_ */
