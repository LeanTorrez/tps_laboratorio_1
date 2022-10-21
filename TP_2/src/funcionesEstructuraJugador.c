/*
 * funcionesEstructuraJugador.c
 *
 *  Created on: 12 oct. 2022
 *      Author: leand
 */
#include "funcionesEstructuraJugador.h"

int InicializacionStructJugadores(eJugador jugador[],int tamJugador){
	int retorno = 0;
	if(tamJugador>0){
		for(int i=0;i<tamJugador;i++){
				jugador[i].isEmpty = 0;
		}
		retorno=1;
	}
	return retorno;
}

int BuscarStructIndiceIsEmpty(eJugador jugador[],int tamJugador,int* indice){
	int retorno=0;
	if(tamJugador > 0){
		for(int i=0;i<tamJugador;i++){
			if(jugador[i].isEmpty == 0){
				*indice = i;
				retorno = 1;
				break;
			}
		}
	}
	return retorno;
}

int BuscarStructIndiceLLENO(eJugador jugador[],int tamJugador){
	int retorno=0;
	if(tamJugador > 0){
		for(int i=0;i<tamJugador;i++){
			if(jugador[i].isEmpty == 1){
				retorno = 1;
				break;
			}
		}
	}

	return retorno;
}

int AltaStructJugador(eJugador jugador[],int tamJugador,eConfederacion confederacion[],int tamConfederacion,int* idAutoincremental){
	int retorno=0;
	int indiceVacio;
	int opcionPosicionJugador=0;
	char auxJugadorPosicion[50];
	if(tamJugador > 0){
		if(BuscarStructIndiceIsEmpty(jugador,tamJugador,&indiceVacio)==1){
			//ID autoincremental
			jugador[indiceVacio].idJugador = *idAutoincremental;
			//Nombre
			utn_getString(jugador[indiceVacio].nombre,sizeof(jugador[indiceVacio].nombre),"Ingrese el nombre del jugador","Error, Asegurese de ingresar algo",20);
			//Posicion Jugador
			utn_getNumeroINT(&opcionPosicionJugador,"1.Delantero\n2.MedioCampista\n3.Defensor\n4.Arquero\nIngrese el numero de las siguiente posiciones","Error/ Reingrese el numero",1,4,20);
			switch(opcionPosicionJugador){
			case 1:
				strcpy(auxJugadorPosicion,"Delantero");
				break;
			case 2:
				strcpy(auxJugadorPosicion,"Mediocampista");
				break;
			case 3:
				strcpy(auxJugadorPosicion,"Defensor");
				break;
			case 4:
				strcpy(auxJugadorPosicion,"Arquero");
				break;
			}

			strcpy(jugador[indiceVacio].posicion,auxJugadorPosicion);
			//Numero Camiseta
			utn_getNumeroShort(&jugador[indiceVacio].numeroCamiseta,"Ingrese el numero de camiseta","Error/ La camiseta no puedo ser menor a 1 y mayor a 99",1,99,20);
			//Confederacion
			MostrarStructConfederaciones(confederacion,tamConfederacion);
			utn_getNumeroINT(&jugador[indiceVacio].idConfederacion,"Ingrese la ID de la confederacion del jugador","Error/ Ingrese una ID valida",100,105,20);
			//Salario
			utn_getNumeroFLOAT(&jugador[indiceVacio].salario,"Ingrese el Salario del jugador","Error/ El salario no puede ser menor a 1",1,100000000,20),
			//Años De Contrato
			utn_getNumeroShort(&jugador[indiceVacio].aniosContrato,"Ingrese los Años de contrato del jugador","Error/ No puede ser menor a 1 y mayor 20",1,20,20);
			//IsEmpty
			jugador[indiceVacio].isEmpty = 1;

			*idAutoincremental = +1;


			retorno = 1;
		}

	}
	return retorno;
}
