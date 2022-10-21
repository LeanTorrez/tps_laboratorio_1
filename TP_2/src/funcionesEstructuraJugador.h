/*
 * funcionesEstructuraJugador.h
 *
 *  Created on: 12 oct. 2022
 *      Author: leand
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
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

int InicializacionStructJugadores(eJugador jugador[],int tamJugador);

int BuscarStructIndiceIsEmpty(eJugador jugador[],int tamJugador,int* indice);

int BuscarStructIndiceLLENO(eJugador jugador[],int tamJugador);

int AltaStructJugador(eJugador jugador[],int tamJugador,eConfederacion confederacion[],int tamConfederacion,int* idAutoincremental);

#endif /* FUNCIONESESTRUCTURAJUGADOR_H_ */
