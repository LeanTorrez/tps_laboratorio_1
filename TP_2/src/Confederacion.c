/*
 * funcionesEstructuraConfederacion.c
 *
 *  Created on: 20 oct. 2022
 *      Author: leand
 */
#include "Confederacion.h"

/**
 * \fn int confe_buscarIndiceIsEmpty(eConfederacion[], int, int*)
 * \brief  Dentro de la misma se buscar el estado IsEmpty ,para la struct Confederacion, mas proximo que su numero sea 0 y devuelve el indice
 * por puntero a la variable que entra por parametro
 *
 * \param confederacion Struct Confederacion
 * \param tamConfederacion Tamaño de La struct Confederacion
 * \param indice Puntero a la variable adonde se guardara el indice que se encontro, si es que existe
 * \return Devuelve 1 en caso exitoso o 0 en caso de fallo
 */
static int confe_buscarIndiceIsEmpty(eConfederacion confederaciones[],int tamConfederacion,int* indice);

int confe_inicializacionStruct(eConfederacion confederaciones[],int tamConfederacion){
	int retorno = 0;
	if(tamConfederacion>0){
		for(int i=0;i<tamConfederacion;i++){
			confederaciones[i].IsEmpty = 0;
			retorno=1;
		}
	}
	return retorno;
}

static int confe_buscarIndiceIsEmpty(eConfederacion confederaciones[],int tamConfederacion,int* indice){
	int retorno=0;
	if(tamConfederacion > 0){
		for(int i=0;i<tamConfederacion;i++){
			if(confederaciones[i].IsEmpty == 0){
				*indice = i;
				retorno = 1;
				break;
			}
		}
	}
	return retorno;
}

int confe_buscarIndiceLlENO(eConfederacion confederaciones[],int tamConfederacion){
	int retorno=0;
	if(tamConfederacion > 0){
		for(int i=0;i<tamConfederacion;i++){
			if(confederaciones[i].IsEmpty == 1){
				retorno = 1;
				break;
			}
		}
	}

	return retorno;
}

int confe_buscarId(eConfederacion confederaciones[],int tamConfederacion,int idConfederacion,int* pIdConfederacion){
	int retorno=0;
	if(tamConfederacion > 0){

		for(int i=0;i<tamConfederacion;i++){
			if(confederaciones[i].IsEmpty == 1){
				if(confederaciones[i].idConfederacion == idConfederacion){
					*pIdConfederacion = i;
					retorno = 1;
					break;
				}
			}
		}
	}
	return retorno;
}

int confe_alta(eConfederacion confederaciones[],int tamConfederacion,int* idAutoincremental){
	int retorno=0;
	int indiceVacio;

	//auxiliares para el ingreso de datos
	char auxNombre[50];
	char auxRegion[50];
	int auxAnioCreacion;
	if(tamConfederacion > 0){
		if(confe_buscarIndiceIsEmpty(confederaciones, tamConfederacion,&indiceVacio)==1){

			if(utn_getDescripcion(auxNombre,sizeof(auxNombre),"Ingrese el nombre de la confederacion\n","Error/ Asegurese de ingresar algo\n",20)==0 &&
			   utn_getDescripcion(auxRegion,sizeof(auxRegion),"Ingrese el nombre de la region\n","Error/ Asegurese de ingresar algo\n",20)==0 &&
			   utn_getNumeroINT(&auxAnioCreacion,"Ingrese el año de creacion de la confederacion\n","Error/ La misma no puede superar el año 2022\n",1,2022,20)==1)
			{
				confederaciones[indiceVacio].idConfederacion = *idAutoincremental;

				strcpy(confederaciones[indiceVacio].nombre,auxNombre);
				strcpy(confederaciones[indiceVacio].region,auxRegion);
				confederaciones[indiceVacio].anioCreacion = auxAnioCreacion;

				confederaciones[indiceVacio].IsEmpty = 1;
				*idAutoincremental += 1;
				retorno=1;
			}
		}
	}
	return retorno;
}

int confe_baja(eConfederacion confederaciones[],int tamConfederacion){
	int retorno=0;
	int idConfederacion;
	int indiceConfederacion;

	if(tamConfederacion > 0){
		confe_mostrar(confederaciones, tamConfederacion);
		if(utn_getNumeroINT(&idConfederacion,"Ingrese la ID de la confederacion\n","Ingrese una ID valida\n",1,3000,10)==1){
			if(confe_buscarId(confederaciones, tamConfederacion,idConfederacion,&indiceConfederacion)==1){
				confederaciones[idConfederacion].IsEmpty = 0;
				retorno=1;
			}
		}
	}
	return retorno;
}

int confe_modificacion(eConfederacion confederaciones[],int tamConfederacion){
	int retorno=0;
	int idConfederacion;
	int indiceConfederacion;
	int opcionesModificarConfederacion=0;

	//auxiliares para el ingreso de datos
	char auxNombre[50];
	char auxRegion[50];
	int auxAnioCreacion;

	if(tamConfederacion > 0){
		confe_mostrar(confederaciones, tamConfederacion);
		if(utn_getNumeroINT(&idConfederacion,"Ingrese la ID de la confederacion\n","Ingrese una ID valida\n",1,3000,10)==1){

			if(confe_buscarId(confederaciones, tamConfederacion,idConfederacion,&indiceConfederacion)==1){

				if(utn_getNumeroINT(&opcionesModificarConfederacion,"\n1.Nombre\n2.Region\n3.Año de Creacion\n"
														   "Ingresa el numero de la opcion que quiera Modificar\n","Error/ Ingrese una opcion valida\n",1,6,20)==1){

					switch(opcionesModificarConfederacion){
					case 1:
						if(utn_getDescripcion(auxNombre,sizeof(auxNombre),"Ingrese el nombre de la confederacion\n","Error/ Asegurese de ingresar algo\n",20)==0){
							strcpy(confederaciones[indiceConfederacion].nombre,auxNombre);
							retorno = 1;
						}
						break;
					case 2:
						if(utn_getDescripcion(auxRegion,sizeof(auxRegion),"Ingrese el nombre de la region\n","Error/ Asegurese de ingresar algo\n",20)==0){
							strcpy(confederaciones[indiceConfederacion].region,auxRegion);
							retorno = 1;
						}
						break;
					case 3:
						if(utn_getNumeroINT(&auxAnioCreacion,"Ingrese el año de creacion de la confederacion\n","Error/ La misma no puede superar el año 2022\n",1,2022,20)==1){
							confederaciones[indiceConfederacion].anioCreacion = auxAnioCreacion;
							retorno = 1;
						}
						break;
					}
				}
			}
		}
	}
	return retorno;
}


void confe_mostrar(eConfederacion confederaciones[],int tamConfederacion){
	printf("-------------------->Lista De Confederaciones<-------------------\n"
		   "|======================================================================================|\n"
		   "| %-5s | %-30s | %-25s | %-15s |\n"
		   "|======================================================================================|\n","ID","Nombre","Region","Año de creacion");
	for(int i = 0;i<tamConfederacion;i++){
			printf("| %-5d | %-30s | %-25s | %-15d |\n",
					confederaciones[i].idConfederacion,
											confederaciones[i].nombre,
											confederaciones[i].region,
											confederaciones[i].anioCreacion);
	}
	printf("|======================================================================================|\n");
}

