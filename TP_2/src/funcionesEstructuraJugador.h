/*
 * funcionesEstructuraJugador.h
 *
 *  Created on: 12 oct. 2022
 *      Author: leand
 */
#include "funcionesEstructuraConfederacion.h"

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
 * \fn int InicializacionStructJugadores(eJugador[], int)
 * \brief Recibe por parametro la estructura, dentro de la misma
 * el estado IsEmpty lo inicializa en 0
 *
 * \param jugador Struct Jugador
 * \param tamJugador Tamaño de La struct Jugador
 * \return Devuelve 1 en caso exitoso o 0 en caso de fallo
 */
int InicializacionStructJugadores(eJugador jugador[],int tamJugador);

//int BuscarStructIndiceIsEmpty(eJugador jugador[],int tamJugador,int* indice);

/**
 * \fn int BuscarStructIndiceLLENO(eJugador[], int)
 * \brief Verifica que el parametro IsEmpty sea 1 que significa que existen datos guardados, retorno 1 en caso de
 * existir datos o 0 en caso de no existir ningun dato
 *
 * \param jugador Struct Jugador
 * \param tamJugador Tamaño de La struct Jugador
 * \return Devuelve 1 en caso exitoso o 0 en caso de fallo
 */
int BuscarStructIndiceLLENO(eJugador jugador[],int tamJugador);

//int BuscarIDJugador(eJugador jugador[],int tamJugador,int* idJugador);

/**
 * \fn int AltaStructJugador(eJugador[], int, eConfederacion[], int, int*)
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
int AltaStructJugador(eJugador jugador[],int tamJugador,eConfederacion confederacion[],int tamConfederacion,int* idAutoincremental);

/**
 * \fn int BajaStructJugador(eJugador[], int, eConfederacion[], int)
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
int BajaStructJugador(eJugador jugador[],int tamJugador,eConfederacion confederacion[],int tamConfederacion);

/**
 * \fn int ModificacionStructJugador(eJugador[], int, eConfederacion[], int)
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
int ModificacionStructJugador(eJugador jugador[],int tamJugador,eConfederacion confederacion[],int tamConfederacion);

/**
 * \fn void OrdenarStructJugadorID(eJugador[], int)
 * \brief Ordenado el listado de jugadores en forma ascendente en base a la id del jugador
 *
 * \param jugador Struct Jugador
 * \param tamJugador Tamaño de La struct Jugador
 */
void OrdenarStructJugadorID(eJugador jugador[],int tamJugador);

/**
 * \fn void MostrarStructJugador(eJugador[], int, eConfederacion[], int)
 * \brief Muestra una lista con los datos que contiene la struct jugador
 *
 * \param jugador Struct Jugador
 * \param tamJugador Tamaño de La struct Jugador
 * \param confederacionStruct Confederacion, Es Necesaria para mostrar la confederacion
 * al usuario
 * \param tamConfederacion Tamaño de La struct Confederacion
 */
void MostrarStructJugador(eJugador jugador[],int tamJugador,eConfederacion confederacion[],int tamConfederacion);

#endif /* FUNCIONESESTRUCTURAJUGADOR_H_ */
