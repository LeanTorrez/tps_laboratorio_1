/*
 * MostrarInformes.h
 *
 *  Created on: 22 oct. 2022
 *      Author: leand
 */
#include "funcionesEstructuraJugador.h"

#ifndef MOSTRARINFORMES_H_
#define MOSTRARINFORMES_H_

int MostrarInformes(eJugador jugador[],int tamJugador,eConfederacion confederacion[],int tamConfederacion);

int ContadorJugadoresTotal(eJugador jugador[],int tamJugador,int* contadorJugadoresTotales);

int BuscarIndiceComparacion(eConfederacion confederacion[],int tamConfederacion,int IdAbuscar,int* pIndice);

void OrdenamientoStructJugadorConfederacionNombre(eJugador jugador[],int tamJugador,eConfederacion confederacion[],int tamConfederacion);

int MostrarJugadoresOrdenadosConfederacion(eJugador jugador[],int tamJugador,eConfederacion confederacion[],int tamConfederacion,int IdConfederacion);

int AcumuladorSalarioStructJugador(eJugador jugador[],int tamJugador,float* acumuladorSalario);

int JugadorSalarioSuperanPromedio(eJugador jugador[],int tamJugador,float promedioSalario,int* contadorJugadoresSuperanPromedio);

int ConfederacionConMasAniosContrato(eJugador jugador[],int tamJugador,int IdConfederacion,short* acumuladorAnios);

int ContadorConfederacionJugadores(eJugador jugador[],int tamJugador,int idConfederacion,int* contadorJugadoresConfederacion);

float CalcularPorcentaje(int numeroPorcentaje, int contadorTotal);

float CalcularPromedio(float acumulador,int contadorTotal);

#endif /* MOSTRARINFORMES_H_ */
