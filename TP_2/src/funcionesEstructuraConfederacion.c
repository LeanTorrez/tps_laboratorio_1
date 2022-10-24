/*
 * funcionesEstructuraConfederacion.c
 *
 *  Created on: 20 oct. 2022
 *      Author: leand
 */
#include "funcionesEstructuraConfederacion.h"

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

int BuscarStructIndiceIsEmptyConfederacion(eConfederacion confederacion[],int tamConfederacion,int* indice){
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

int BuscarIdConfederacion(eConfederacion confederacion[],int tamConfederacion,int* idConfederacion){
	int retorno=0;
	int IdAbuscar;
	if(tamConfederacion > 0){
		utn_getNumeroINT(&IdAbuscar,"Ingrese la ID de la confederacion\n","Ingrese una ID valida\n",1,3000,10);
		for(int i=0;i<tamConfederacion;i++){
			if(confederacion[i].idConfederacion == IdAbuscar){
				*idConfederacion = i;
				retorno = 1;
				break;
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

