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
}eConfederacion;

#define FUNCIONESESTRUCTURACONFEDERACION_H_

void MostrarStructConfederaciones(eConfederacion confederacion[],int tamConfederacion);



#endif /* FUNCIONESESTRUCTURACONFEDERACION_H_ */
