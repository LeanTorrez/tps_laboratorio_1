/*
 * funcionesEstructuraJugador.h
 *
 *  Created on: 12 oct. 2022
 *      Author: leand
 */

#ifndef FUNCIONESESTRUCTURAJUGADOR_H_

typedef struct{
	int idConfederacion;
	char nombre[50];
	char region[50];
	int anioCreacion;
}eConfederacion;

typedef struct{
	int idJugador;
	char nombre[50];
	char posicion[50];
	short int numeroCamiseta;
	int idConfederacion;
	float salario;
	short int aniosContrato;
	short int isEmpty;
}eJugador;
#define FUNCIONESESTRUCTURAJUGADOR_H_

int InicializacionStructJugadores(eJugador jugador,int tamJugador);

int BuscarStructIndiceIsEmpty(eJugador jugador,int tamJugador,int* indice);

int BuscarStructIndiceLLENO(eJugador jugador,int tamJugador);

#endif /* FUNCIONESESTRUCTURAJUGADOR_H_ */
