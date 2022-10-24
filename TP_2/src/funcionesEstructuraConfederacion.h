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

int InicializacionStructConfederaciones(eConfederacion confederacion[],int tamConfederacion);

int BuscarStructIndiceIsEmptyConfederacion(eConfederacion confederacion[],int tamConfederacion,int* indice);

int BuscarStructIndiceLLENOConfederacion(eConfederacion confederacion[],int tamConfederacion);

int BuscarIdConfederacion(eConfederacion confederacion[],int tamConfederacion,int* idConfederacion);


int AltaStructConfederacion(eConfederacion confederacion[],int tamConfederacion,int* idAutoincremental);

int BajaStructConfederacion(eConfederacion confederacion[],int tamConfederacion);

int ModificacionStructConfederacion(eConfederacion confederacion[],int tamConfederacion);


void MostrarStructConfederaciones(eConfederacion confederacion[],int tamConfederacion);



#endif /* FUNCIONESESTRUCTURACONFEDERACION_H_ */
