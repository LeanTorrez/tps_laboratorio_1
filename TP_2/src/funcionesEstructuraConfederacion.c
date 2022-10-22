/*
 * funcionesEstructuraConfederacion.c
 *
 *  Created on: 20 oct. 2022
 *      Author: leand
 */
#include "funcionesEstructuraConfederacion.h"

void MostrarStructConfederaciones(eConfederacion confederacion[],int tamConfederacion){
	printf("\n-------------------->Lista De Confederaciones<-------------------\n"
		   "|ID   |\tNombre   |\t    Region\t\t|Año De Creacion|\n"
		   "|---------------------------------------------------------------|\n");
	for(int i = 0;i<tamConfederacion;i++){
			printf("|%d  |\t%s |\t %s |     %d      |\n",
											confederacion[i].idConfederacion,
											confederacion[i].nombre,
											confederacion[i].region,
											confederacion[i].anioCreacion);
	}
}

