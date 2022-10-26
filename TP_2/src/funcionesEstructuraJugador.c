/*
 * funcionesEstructuraJugador.c
 *
 *  Created on: 12 oct. 2022
 *      Author: leand
 */
#include "funcionesEstructuraJugador.h"
/**
 * \fn int BuscarIDJugador(eJugador[], int, int*)
 * \brief Le pide al usuario que ingrese la id del jugador que quiere buscar, en caso de encontrarla la guardara
 * en el puntero que viene por parametro, en caso de no existir esa id, la funcion devuelve 0
 *
 * \param jugador Struct Jugador
 * \param tamJugador Tamaño de La struct Jugador
 * \param idJugador Puntero a la variable adonde se guardara el indice, en caso de existir
 * \return Devuelve 1 en caso exitoso o 0 en caso de fallo
 */
static int BuscarIDJugador(eJugador jugador[],int tamJugador,int* idJugador);

/**
 * \fn int BuscarStructIndiceIsEmpty(eJugador[], int, int*)
 * \brief Dentro de la misma se buscar el estado IsEmpty ,para la struct jugador, mas proximo que su numero sea 0 y devuelve el indice
 * por puntero a la variable que entra por parametro
 *
 * \param jugador Struct Jugador
 * \param tamJugador  Tamaño de La struct Jugador
 * \param indice Puntero a la variable adonde se guardara el indice que se encontro, si es que existe
 * \return Devuelve 1 en caso exitoso o 0 en caso de fallo
 */
static int BuscarStructIndiceIsEmpty(eJugador jugador[],int tamJugador,int* indice);

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

static int BuscarStructIndiceIsEmpty(eJugador jugador[],int tamJugador,int* indice){
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

static int BuscarIDJugador(eJugador jugador[],int tamJugador,int* idJugador){
	int retorno=0;
	int IdAbuscar;
	if(tamJugador > 0){
		utn_getNumeroINT(&IdAbuscar,"Ingrese la ID del Jugador\n","Ingrese una ID valida\n",1,3000,10);
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
			utn_getNumeroINT(&opcionPosicionJugador,"1.Delantero\n2.MedioCampista\n3.Defensor\n4.Arquero\nIngrese el numero de las siguiente posiciones\n","Error/ Reingrese el numero\n",1,4,20);
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
			utn_getNumeroShort(&jugador[indiceVacio].numeroCamiseta,"Ingrese el numero de camiseta\n","Error/ La camiseta no puedo ser menor a 1 y mayor a 99\n",1,99,20);
			//Confederacion
			MostrarStructConfederaciones(confederacion,tamConfederacion);
			utn_getNumeroINT(&jugador[indiceVacio].idConfederacion,"Ingrese la ID de la confederacion del jugador\n","Error/ Ingrese una ID valida\n",100,105,20);
			//Salario
			utn_getNumeroFLOAT(&jugador[indiceVacio].salario,"Ingrese el Salario del jugador\n","Error/ El salario no puede ser menor a 1\n",1,100000000,20);
			//Años De Contrato
			utn_getNumeroShort(&jugador[indiceVacio].aniosContrato,"Ingrese los Años de contrato del jugador\n","Error/ No puede ser menor a 1 y mayor 20\n",1,20,20);
			//IsEmpty
			jugador[indiceVacio].isEmpty = 1;

			*idAutoincremental += 1;


			retorno = 1;
		}

	}
	return retorno;
}

int BajaStructJugador(eJugador jugador[],int tamJugador,eConfederacion confederacion[],int tamConfederacion){
	int retorno=0;
	int IdJugador;
	if(tamJugador > 0){
		OrdenarStructJugadorID(jugador,tamJugador);
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
		OrdenarStructJugadorID(jugador,tamJugador);
		MostrarStructJugador(jugador, tamJugador, confederacion, tamConfederacion);
		if(BuscarIDJugador(jugador, tamJugador,&IdJugador)==1){

			utn_getNumeroINT(&opcionesModificarJugador,"\n1.Nombre\n2.Posicion\n3.Numero de Camiseta\n4.ID Confederacion\n5.Salario\n6.Años de contrato\n"
					 	 	 	 	 	 	 	 	   "Ingresa el numero de la opcion que quiera Modificar\n","Error/ Ingrese una opcion valida\n",1,6,20);
			switch(opcionesModificarJugador){
			case 1:
				//Nombre
				utn_getString(jugador[IdJugador].nombre,sizeof(jugador[IdJugador].nombre),"Ingrese el nombre del jugador\n","Error, Asegurese de ingresar algo\n",20);
				break;
			case 2:
				//Posicion Jugador
				utn_getNumeroINT(&opcionPosicionJugador,"1.Delantero\n2.MedioCampista\n3.Defensor\n4.Arquero\nIngrese el numero de las siguiente posiciones\n","Error/ Reingrese una opcion valida\n",1,4,20);
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
				utn_getNumeroShort(&jugador[IdJugador].numeroCamiseta,"Ingrese el numero de camiseta\n","Error/ La camiseta no puedo ser menor a 1 y mayor a 99\n",1,99,20);
				break;
			case 4:
				//Confederacion
				MostrarStructConfederaciones(confederacion,tamConfederacion);
				utn_getNumeroINT(&jugador[IdJugador].idConfederacion,"Ingrese la ID de la confederacion del jugador\n","Error/ Ingrese una ID valida\n",100,105,20);
				break;
			case 5:
				//Salario
				utn_getNumeroFLOAT(&jugador[IdJugador].salario,"Ingrese el Salario del jugador\n","Error/ El salario no puede ser menor a 1\n",1,100000000,20);
				break;
			case 6:
				//Años De Contrato
				utn_getNumeroShort(&jugador[IdJugador].aniosContrato,"Ingrese los Años de contrato del jugador\n","Error/ No puede ser menor a 1 y mayor 20\n",1,20,20);
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
		printf("|====================================================================================================================================|\n"
			   "|  ID  |             Nombre             |       Posicion       |    Num. camiseta   |  Confederacion  |  Salario   |Años de Contrato |\n"
			   "|====================================================================================================================================|\n");
		for(int i=0;i<tamJugador;i++){
			if(jugador[i].isEmpty == 1){
				for(int a=0;a<tamConfederacion;a++){
					if(jugador[i].idConfederacion == confederacion[a].idConfederacion){
						auxIdConfederacion = a;
						break;
					}
				}
				printf("| %-4d | %-30s | %-20s | %-16hi   | %-15s | %-10.2f | %-15hi |\n",
												   jugador[i].idJugador,
												   jugador[i].nombre,
												   jugador[i].posicion,
												   jugador[i].numeroCamiseta,
												   confederacion[auxIdConfederacion].nombre,
												   jugador[i].salario,
												   jugador[i].aniosContrato);
			}

		}
		printf("|====================================================================================================================================|\n");
	}

}
