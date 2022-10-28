/*
 * funcionesEstructuraConfederacion.c
 *
 *  Created on: 20 oct. 2022
 *      Author: leand
 */
#include "funcionesEstructuraConfederacion.h"

/**
 * \fn int BuscarStructIndiceIsEmptyConfederacion(eConfederacion[], int, int*)
 * \brief  Dentro de la misma se buscar el estado IsEmpty ,para la struct Confederacion, mas proximo que su numero sea 0 y devuelve el indice
 * por puntero a la variable que entra por parametro
 *
 * \param confederacion Struct Confederacion
 * \param tamConfederacion Tamaño de La struct Confederacion
 * \param indice Puntero a la variable adonde se guardara el indice que se encontro, si es que existe
 * \return Devuelve 1 en caso exitoso o 0 en caso de fallo
 */
static int BuscarStructIndiceIsEmptyConfederacion(eConfederacion confederacion[],int tamConfederacion,int* indice);

/**
 * \fn int BuscarIdConfederacion(eConfederacion[], int, int*)
 * \brief Le pide al usuario que ingrese la id de la confederacion que quiere buscar, en caso de encontrarla la guardara
 * en el puntero que viene por parametro, en caso de no existir esa id, la funcion devuelve 0
 *
 * \param confederacion Struct Confederacion
 * \param tamConfederacion Tamaño de La struct Confederacion
 * \param idConfederacion Puntero a la variable adonde se guardara el indice, en caso de existir
 * \return Devuelve 1 en caso exitoso o 0 en caso de fallo
 */
static int BuscarIdConfederacion(eConfederacion confederacion[],int tamConfederacion,int* idConfederacion);

int InicializacionStructConfederaciones(eConfederacion confederacion[],int tamConfederacion){
	int retorno = 0;
	if(tamConfederacion>0){
		for(int i=0;i<tamConfederacion;i++){
				confederacion[i].IsEmpty = 0;
		}
		retorno=1;
	}
	return retorno;
}

static int BuscarStructIndiceIsEmptyConfederacion(eConfederacion confederacion[],int tamConfederacion,int* indice){
	int retorno=0;
	if(tamConfederacion > 0){
		for(int i=0;i<tamConfederacion;i++){
			if(confederacion[i].IsEmpty == 0){
				*indice = i;
				retorno = 1;
				break;
			}
		}
	}
	return retorno;
}

int BuscarStructIndiceLLENOConfederacion(eConfederacion confederacion[],int tamConfederacion){
	int retorno=0;
	if(tamConfederacion > 0){
		for(int i=0;i<tamConfederacion;i++){
			if(confederacion[i].IsEmpty == 1){
				retorno = 1;
				break;
			}
		}
	}

	return retorno;
}

static int BuscarIdConfederacion(eConfederacion confederacion[],int tamConfederacion,int* idConfederacion){
	int retorno=0;
	int IdAbuscar;
	if(tamConfederacion > 0){
		utn_getNumeroINT(&IdAbuscar,"Ingrese la ID de la confederacion\n","Ingrese una ID valida\n",1,3000,10);
		for(int i=0;i<tamConfederacion;i++){
			if(confederacion[i].IsEmpty == 1){
				if(confederacion[i].idConfederacion == IdAbuscar){
					*idConfederacion = i;
					retorno = 1;
					break;
				}
			}
		}
	}
	return retorno;
}

int AltaStructConfederacion(eConfederacion confederacion[],int tamConfederacion,int* idAutoincremental){
	int retorno=0;
	int indiceVacio;
	if(tamConfederacion > 0){
		if(BuscarStructIndiceIsEmptyConfederacion(confederacion, tamConfederacion,&indiceVacio)==1){
			//ID autoincremental
			confederacion[indiceVacio].idConfederacion = *idAutoincremental;
			//Nombre
			utn_getString(confederacion[indiceVacio].nombre,sizeof(confederacion[indiceVacio].nombre),"Ingrese el nombre de la confederacion\n","Error/ Asegurese de ingresar algo\n",20);
			//Region
			utn_getString(confederacion[indiceVacio].region,sizeof(confederacion[indiceVacio].region),"Ingrese el nombre de la region\n","Error/ Asegurese de ingresar algo\n",20);
			//Año de creacion
			utn_getNumeroINT(&confederacion[indiceVacio].anioCreacion,"Ingrese el año de creacion de la confederacion\n","Error/ La misma no puede superar el año 2022",1,2022,20);
			//Is empty Estado
			confederacion[indiceVacio].IsEmpty = 1;
			retorno=1;
			*idAutoincremental += 1;
		}
	}
	return retorno;
}

int BajaStructConfederacion(eConfederacion confederacion[],int tamConfederacion){
	int retorno=0;
	int idConfederacion;
	if(tamConfederacion > 0){
		MostrarStructConfederaciones(confederacion, tamConfederacion);
		if(BuscarIdConfederacion(confederacion, tamConfederacion,&idConfederacion)==1){
			confederacion[idConfederacion].IsEmpty = 0;
			retorno=1;
		}
	}
	return retorno;
}

int ModificacionStructConfederacion(eConfederacion confederacion[],int tamConfederacion){
	int retorno=0;
	int IdConfederacion;

	int opcionesModificarConfederacion=0;
	if(tamConfederacion > 0){
		MostrarStructConfederaciones(confederacion, tamConfederacion);
		if(BuscarIdConfederacion(confederacion, tamConfederacion,&IdConfederacion)==1){
			utn_getNumeroINT(&opcionesModificarConfederacion,"\n1.Nombre\n2.Region\n3.Año de Creacion\n"
													   "Ingresa el numero de la opcion que quiera Modificar\n","Error/ Ingrese una opcion valida\n",1,6,20);
			switch(opcionesModificarConfederacion){
			case 1:
				//Nombre
				utn_getString(confederacion[IdConfederacion].nombre,sizeof(confederacion[IdConfederacion].nombre),"Ingrese el nombre de la confederacion\n","Error/ Asegurese de ingresar algo\n",20);
				break;
			case 2:
				//Region
				utn_getString(confederacion[IdConfederacion].region,sizeof(confederacion[IdConfederacion].region),"Ingrese el nombre de la region\n","Error/ Asegurese de ingresar algo\n",20);
				break;
			case 3:
				//Año de creacion
				utn_getNumeroINT(&confederacion[IdConfederacion].anioCreacion,"Ingrese el año de creacion de la confederacion\n","Error/ La misma no puede superar el año 2022",1,2022,20);
				break;
			}
			retorno = 1;
		}
	}
	return retorno;
}


void MostrarStructConfederaciones(eConfederacion confederacion[],int tamConfederacion){
	printf("-------------------->Lista De Confederaciones<-------------------\n"
		   "|======================================================================================|\n"
		   "| %-5s | %-30s | %-25s | %-15s |\n"
		   "|======================================================================================|\n","ID","Nombre","Region","Año de creacion");
	for(int i = 0;i<tamConfederacion;i++){
			printf("| %-5d | %-30s | %-25s | %-15d |\n",
											confederacion[i].idConfederacion,
											confederacion[i].nombre,
											confederacion[i].region,
											confederacion[i].anioCreacion);
	}
	printf("|======================================================================================|\n");
}

