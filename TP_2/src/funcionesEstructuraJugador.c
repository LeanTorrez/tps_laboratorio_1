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

int BuscarIDJugador(eJugador jugador[],int tamJugador,int* idJugador){
	int retorno=0;
	int IdAbuscar;
	if(tamJugador > 0){
		utn_getNumeroINT(&IdAbuscar,"Ingrese la ID del Jugador","Ingrese una ID valida",1,3000,10);
		for(int i=0;i<tamJugador;i++){
			if(jugador[i].idJugador == IdAbuscar){
				*idJugador = i;
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
			utn_getNumeroFLOAT(&jugador[indiceVacio].salario,"Ingrese el Salario del jugador","Error/ El salario no puede ser menor a 1",1,100000000,20);
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

int BajaStructJugador(eJugador jugador[],int tamJugador,eConfederacion confederacion[],int tamConfederacion){
	int retorno=0;
	int IdJugador;
	if(tamJugador > 0){
		MostrarStructJugador(jugador, tamJugador, confederacion, tamConfederacion);
		if(BuscarIDJugador(jugador, tamJugador,&IdJugador)==1){
			jugador[IdJugador].isEmpty = 0;
			retorno=1;
		}
	}
	return retorno;
}

int ModificacionStructJugador(eJugador jugador[],int tamJugador,eConfederacion confederacion[],int tamConfederacion){
	int retorno=0;
	int IdJugador;

	int opcionPosicionJugador=0;
	char auxJugadorPosicion[50];
	int opcionesModificarJugador=0;
	if(tamJugador > 0){
		MostrarStructJugador(jugador, tamJugador, confederacion, tamConfederacion);
		if(BuscarIDJugador(jugador, tamJugador,&IdJugador)==1){

			utn_getNumeroINT(&opcionesModificarJugador,"\n1.Nombre\n2.Posicion\n3.Numero de Camiseta\n4.ID Confederacion\n5.Salario\n6.Años de contrato\n"
					 	 	 	 	 	 	 	 	   "Ingresa el numero de la opcion que quiera Modificar","Error/ Ingrese una opcion valida",1,6,20);
			switch(opcionesModificarJugador){
			case 1:
				//Nombre
				utn_getString(jugador[IdJugador].nombre,sizeof(jugador[IdJugador].nombre),"Ingrese el nombre del jugador","Error, Asegurese de ingresar algo",20);
				break;
			case 2:
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

				strcpy(jugador[IdJugador].posicion,auxJugadorPosicion);
				break;
			case 3:
				//Numero Camiseta
				utn_getNumeroShort(&jugador[IdJugador].numeroCamiseta,"Ingrese el numero de camiseta","Error/ La camiseta no puedo ser menor a 1 y mayor a 99",1,99,20);
				break;
			case 4:
				//Confederacion
				MostrarStructConfederaciones(confederacion,tamConfederacion);
				utn_getNumeroINT(&jugador[IdJugador].idConfederacion,"Ingrese la ID de la confederacion del jugador","Error/ Ingrese una ID valida",100,105,20);
				break;
			case 5:
				//Salario
				utn_getNumeroFLOAT(&jugador[IdJugador].salario,"Ingrese el Salario del jugador","Error/ El salario no puede ser menor a 1",1,100000000,20);
				break;
			case 6:
				//Años De Contrato
				utn_getNumeroShort(&jugador[IdJugador].aniosContrato,"Ingrese los Años de contrato del jugador","Error/ No puede ser menor a 1 y mayor 20",1,20,20);
				break;
			}
			retorno = 1;
		}
	}
	return retorno;
}
void OrdenarStructJugadorID(eJugador jugador[],int tamJugador){
	eJugador aux;
	if(tamJugador > 0){
		for(int i=0;i<tamJugador -1;i++){
			for(int j=i+1;j<tamJugador;j++){

				if(jugador[i].isEmpty == 1){
					if(jugador[i].idJugador > jugador[j].idJugador){
						aux = jugador[i];
						jugador[i]= jugador[j];
						jugador[j]= aux;
					}
				}
			}
		}
	}
}

void MostrarStructJugador(eJugador jugador[],int tamJugador,eConfederacion confederacion[],int tamConfederacion){
	int auxIdConfederacion;
	if(tamJugador > 0 && tamConfederacion > 0){
		OrdenarStructJugadorID(jugador,tamJugador);
		printf("|ID   |\tNombre\t|\tPosicion\t|Num. camiseta|\tConfederacion\t|\tSalario\t|\tAños de Contraro\t|");
		for(int i=0;i<tamJugador;i++){
			if(jugador[i].isEmpty == 1){
				for(int a=0;a<tamConfederacion;a++){
					if(jugador[i].idConfederacion == confederacion[a].idConfederacion){
						auxIdConfederacion = a;
						break;
					}
				}
				printf("\n|%d|%s     |%s    |%hi   |%s    |%.f    |%hi   |",
												   jugador[i].idJugador,
												   jugador[i].nombre,
												   jugador[i].posicion,
												   jugador[i].numeroCamiseta,
												   confederacion[auxIdConfederacion].nombre,
												   jugador[i].salario,
												   jugador[i].aniosContrato);
			}

		}
	}

}
