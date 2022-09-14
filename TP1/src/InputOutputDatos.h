/*
 * InputOutputDatos.h
 *
 *  Created on: 31 ago. 2022
 *      Author: leand
 */

#ifndef INPUTOUTPUTDATOS_H_
#define INPUTOUTPUTDATOS_H_
#include <stdio.h>

char Confirmar();

int NumeroIngresadoEntero(char mensaje[]);

float NumeroIngresadoFloat(char mensaje[]);

int NumeroIngresadoPositivoEntero(char mensaje[],char mensajeError[]);

float NumeroIngresadoPositivoFloat(char mensaje[],char mensajeError[]);

int NumeroIngresadoVerificar(char mensaje[],char mensajeError[],int minimo,int maximo);


#endif /* INPUTOUTPUTDATOS_H_ */
