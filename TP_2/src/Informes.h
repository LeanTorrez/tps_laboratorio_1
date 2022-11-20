/*
 * MostrarInformes.h
 *
 *  Created on: 22 oct. 2022
 *      Author: leand
 */
#include "Jugador.h"

#ifndef MOSTRARINFORMES_H_
#define MOSTRARINFORMES_H_


/**
 * \fn int inf_menu(eJugador[], int, eConfederacion[], int)
 * \brief Funcion principal que esta en main, Dentro de la misma esta toda la logica usada para la muestra
 * de informes con sus respectivas funciones.
 *
 * \param jugador Parametro para Struct Jugador
 * \param tamJugador El tamaño de Struct Jugador
 * \param confederacion Parametro para Struct Confederacion
 * \param tamConfederacion El tamaño de Struct Confdederacion
 * \return Retorna 1 en caso exitoso, 0 en caso de error en el programa
 */
int inf_menu(eJugador jugadores[],int tamJugador,eConfederacion confederaciones[],int tamConfederacion);

/**
 * \fn int inf_ordenamientoJugadorPorConfederacion(eJugador[], int, eConfederacion[], int)
 * \brief Ordena la Struct Jugadores por medio de burbujeo, teniendo como parametro primero el nombre de la confederacion
 * y por segundo parametro el nombre del jugador
 *
 * \param jugador Parametro para Struct Jugador
 * \param tamJugador El tamaño de Struct Jugador
 * \param confederacion Parametro para Struct Confederacion
 * \param tamConfederacion El tamaño de Struct Confdederacion
 */
int inf_ordenamientoJugadorPorConfederacion(eJugador jugadores[],int tamJugador,eConfederacion confederaciones[],int tamConfederacion);

/**
 * \fn int inf_mostrarJugadoresPorConfederacion(eJugador[], int, eConfederacion[], int, int)
 * \brief Muestra los jugadores en base a la ID que se ingresa como parametro, y lo imprime en pantalla
 *
 * \param jugador Parametro para Struct Jugador
 * \param tamJugador El tamaño de Struct Jugador
 * \param confederacion Parametro para Struct Confederacion
 * \param tamConfederacion El tamaño de Struct Confdederacion
 * \param IdConfederacion Id de la confederacion que desea mostrar por Pantalla
 * \return Retorna 1 en caso exitoso, 0 en caso de error en el programa
 */
int inf_mostrarJugadoresPorConfederacion(eJugador jugadores[],int tamJugador,eConfederacion confederaciones[],int tamConfederacion,int IdConfederacion);

#endif /* MOSTRARINFORMES_H_ */
