/*
 * MostrarInformes.h
 *
 *  Created on: 22 oct. 2022
 *      Author: leand
 */
#include "funcionesEstructuraJugador.h"

#ifndef MOSTRARINFORMES_H_
#define MOSTRARINFORMES_H_

/**
 * \fn int MostrarInformes(eJugador[], int, eConfederacion[], int)
 * \brief Funcion principal que esta en main, Dentro de la misma esta toda la logica usada para la muestra
 * de informes con sus respectivas funciones.
 *
 * \param jugador Parametro para Struct Jugador
 * \param tamJugador El tamaño de Struct Jugador
 * \param confederacion Parametro para Struct Confederacion
 * \param tamConfederacion El tamaño de Struct Confdederacion
 * \return Retorna 1 en caso exitoso, 0 en caso de error en el programa
 */
int MostrarInformes(eJugador jugador[],int tamJugador,eConfederacion confederacion[],int tamConfederacion);

/**
 * \fn void OrdenamientoStructJugadorConfederacionNombre(eJugador[], int, eConfederacion[], int)
 * \brief Ordena la Struct Jugadores por medio de burbujeo, teniendo como parametro primero el nombre de la confederacion
 * y por segundo parametro el nombre del jugador
 *
 * \param jugador Parametro para Struct Jugador
 * \param tamJugador El tamaño de Struct Jugador
 * \param confederacion Parametro para Struct Confederacion
 * \param tamConfederacion El tamaño de Struct Confdederacion
 */
void OrdenamientoStructJugadorConfederacionNombre(eJugador jugador[],int tamJugador,eConfederacion confederacion[],int tamConfederacion);

/**
 * \fn int MostrarJugadoresOrdenadosConfederacion(eJugador[], int, eConfederacion[], int, int)
 * \brief Muestra los jugadores en base a la ID que se ingresa como parametro, y lo imprime en pantalla
 *
 * \param jugador Parametro para Struct Jugador
 * \param tamJugador El tamaño de Struct Jugador
 * \param confederacion Parametro para Struct Confederacion
 * \param tamConfederacion El tamaño de Struct Confdederacion
 * \param IdConfederacion Id de la confederacion que desea mostrar por Pantalla
 * \return Retorna 1 en caso exitoso, 0 en caso de error en el programa
 */
int MostrarJugadoresOrdenadosConfederacion(eJugador jugador[],int tamJugador,eConfederacion confederacion[],int tamConfederacion,int IdConfederacion);

/**
 * \fn float CalcularPorcentaje(int, int)
 * \brief  Calcula el porcentaje de los numeros que entrar por parametros, siendo el primero multlipicado por 100
 * y divido por el segundo parametro
 *
 * \param numeroPorcentaje Numero al cual se desea sacar el porcentaje
 * \param contadorTotal El numero por el cual se dividira el Numero que desea saber el porcentaje
 * \return Devuelve el numero en float
 */
float CalcularPorcentaje(int numeroPorcentaje, int contadorTotal);

/**
 * \fn float CalcularPromedio(float, int)
 * \brief Calcula el promedio de los numero que entrar por parametro, siendo el primer parametro se divide por el segundo
 *
 * \param acumulador La acumulacion de los numeros que se desea saber el promedio
 * \param contadorTotal El contador por el cual se dividira el numero acumulado
 * \return Devuelve el numero en float
 */
float CalcularPromedio(float acumulador,int contadorTotal);

#endif /* MOSTRARINFORMES_H_ */
