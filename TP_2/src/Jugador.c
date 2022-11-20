/*
 * funcionesEstructuraJugador.c
 *
 *  Created on: 12 oct. 2022
 *      Author: leand
 */
#include "Jugador.h"
/**
 * \fn int jug_buscarId(eJugador[], int, int*)
 * \brief Le pide al usuario que ingrese la id del jugador que quiere buscar, en caso de encontrarla la guardara
 * en el puntero que viene por parametro, en caso de no existir esa id, la funcion devuelve 0
 *
 * \param jugador Struct Jugador
 * \param tamJugador Tamaño de La struct Jugador
 * \param idJugador Puntero a la variable adonde se guardara el indice, en caso de existir
 * \return Devuelve 1 en caso exitoso o 0 en caso de fallo
 */
static int jug_buscarId(eJugador jugadores[],int tamJugador,int idBuscar,int* pIndiceJugador);

/**
 * \fn int jug_buscarIndiceIsEmpty(eJugador[], int, int*)
 * \brief Dentro de la misma se buscar el estado IsEmpty ,para la struct jugador, mas proximo que su numero sea 0 y devuelve el indice
 * por puntero a la variable que entra por parametro
 *
 * \param jugador Struct Jugador
 * \param tamJugador  Tamaño de La struct Jugador
 * \param indice Puntero a la variable adonde se guardara el indice que se encontro, si es que existe
 * \return Devuelve 1 en caso exitoso o 0 en caso de fallo
 */
static int jug_buscarIndiceIsEmpty(eJugador jugadores[],int tamJugador,int* indice);

static int jug_posicion(char* pPosicion){
	int retorno = 0;
	int flagPosicion = 0;
	char auxPosicion[50];

	do{
		if(utn_getDescripcion(auxPosicion,sizeof(auxPosicion),
				"Escriba una de las siguientes opciones\n "
			    "Delantero, Arquero, Defensor, Mediocampista\n","Error/ Por favor ingrese algo\n",20) == 0)
		{

			if(stricmp(auxPosicion,"Delantero") == 0 || stricmp(auxPosicion,"Arquero") == 0 || stricmp(auxPosicion,"Defensor") == 0 || stricmp(auxPosicion,"Mediocampista") == 0){
				retorno = 1;
				strcpy(pPosicion,auxPosicion);
				break;
			}
		}
		printf("Asegure de ingresar una de las siguientes Delantero, Arquero, Defensor o Mediocampista\n");
	}while(flagPosicion == 0);

	return retorno;
}

int jug_inicializacionStruct(eJugador jugadores[],int tamJugador){
	int retorno = 0;
	if(tamJugador>0){
		for(int i=0;i<tamJugador;i++){
			jugadores[i].isEmpty = 0;
		}
		retorno=1;
	}
	return retorno;
}

static int jug_buscarIndiceIsEmpty(eJugador jugadores[],int tamJugador,int* indice){
	int retorno=0;
	if(tamJugador > 0){
		for(int i=0;i<tamJugador;i++){
			if(jugadores[i].isEmpty == 0){
				*indice = i;
				retorno = 1;
				break;
			}
		}
	}
	return retorno;
}

int jug_buscarIndiceLleno(eJugador jugadores[],int tamJugador){
	int retorno=0;
	if(tamJugador > 0){
		for(int i=0;i<tamJugador;i++){
			if(jugadores[i].isEmpty == 1){
				retorno = 1;
				break;
			}
		}
	}

	return retorno;
}

static int jug_buscarId(eJugador jugadores[],int tamJugador,int idBuscar,int* pIndiceJugador){
	int retorno=0;
	if(tamJugador > 0){

		for(int i=0;i<tamJugador;i++){
			if(jugadores[i].isEmpty == 1){
				if(jugadores[i].idJugador == idBuscar){
					*pIndiceJugador = i;
					retorno = 1;
					break;
				}
			}
		}
	}
	return retorno;
}

int jug_alta(eJugador jugadores[],int tamJugador,eConfederacion confederaciones[],int tamConfederacion,int* idAutoincremental){
	int retorno=0;
	int indiceVacio=-1;

	//auxiliares en caso de error en el ingreso de datos
	char auxNombre[50];
	char auxPosicion[50];
	short auxNumeroCamiseta;
	int auxIdConfederacion;
	float auxSalario;
	short auxAniosContrato;
	if(tamJugador > 0){

		if(jug_buscarIndiceIsEmpty(jugadores,tamJugador,&indiceVacio)==1){

			if(utn_getDescripcion(auxNombre,sizeof(auxNombre),"Ingrese el nombre del jugador\n","Error, Asegurese de ingresar algo\n",20)==0 &&
			   jug_posicion(auxPosicion) == 1 &&
			   utn_getNumeroShort(&auxNumeroCamiseta,"Ingrese el numero de camiseta\n","Error/ La camiseta no puedo ser menor a 1 y mayor a 99\n",1,99,20)==1 &&
			   utn_getNumeroFLOAT(&auxSalario,"Ingrese el Salario del jugador\n","Error/ El salario no puede ser menor a 1\n",1,100000000,20)== 1 &&
			   utn_getNumeroShort(&auxAniosContrato,"Ingrese los Años de contrato del jugador\n","Error/ No puede ser menor a 1 y mayor 20\n",1,20,20)==1)
			{
				confe_mostrar(confederaciones,tamConfederacion);
				if(utn_getNumeroINT(&auxIdConfederacion,"Ingrese la ID de la confederacion del jugador\n","Error/ Ingrese una ID valida\n",100,105,20)==1){

					jugadores[indiceVacio].idJugador = *idAutoincremental;

					strcpy(jugadores[indiceVacio].nombre,auxNombre);
					strcpy(jugadores[indiceVacio].posicion,auxPosicion);
					jugadores[indiceVacio].numeroCamiseta = auxNumeroCamiseta;
					jugadores[indiceVacio].salario = auxSalario;
					jugadores[indiceVacio].aniosContrato = auxAniosContrato;
					jugadores[indiceVacio].idConfederacion = auxIdConfederacion;
					jugadores[indiceVacio].isEmpty = 1;

					*idAutoincremental += 1;
					retorno = 1;
				}
			}
		}

	}
	return retorno;
}

int jug_baja(eJugador jugadores[],int tamJugador,eConfederacion confederaciones[],int tamConfederacion){
	int retorno=0;
	int idJugador=-1;
	int indiceJugador;
	if(tamJugador > 0){
		jug_ordenarPorId(jugadores,tamJugador);
		jug_mostrar(jugadores, tamJugador, confederaciones, tamConfederacion);
		if(utn_getNumeroINT(&idJugador,"Ingrese la ID del Jugador\n","Ingrese una ID valida\n",1,3000,10)==1){
			if(jug_buscarId(jugadores, tamJugador,idJugador,&indiceJugador)==1){
				jugadores[indiceJugador].isEmpty = 0;
				retorno=1;
			}
		}
	}
	return retorno;
}

int jug_modificacion(eJugador jugadores[],int tamJugador,eConfederacion confederaciones[],int tamConfederacion){
	int retorno=0;
	int idJugador;
	int indiceJugador;
	int opcionesModificarJugador=0;

	//auxiliares en caso de error en el ingreso de datos
	char auxNombre[50];
	char auxPosicion[50];
	short auxNumeroCamiseta;
	int auxIdConfederacion;
	float auxSalario;
	short auxAniosContrato;
	if(tamJugador > 0){

		jug_ordenarPorId(jugadores,tamJugador);
		jug_mostrar(jugadores, tamJugador, confederaciones, tamConfederacion);

		if(utn_getNumeroINT(&idJugador,"Ingrese la ID del Jugador\n","Ingrese una ID valida\n",1,3000,10)==1){

			if(jug_buscarId(jugadores, tamJugador,idJugador,&indiceJugador)==1){

				if(utn_getNumeroINT(&opcionesModificarJugador,"\n1.Nombre\n2.Posicion\n3.Numero de Camiseta\n4.ID Confederacion\n5.Salario\n6.Años de contrato\n"
														   "Ingresa el numero de la opcion que quiera Modificar\n","Error/ Ingrese una opcion valida\n",1,6,20)==1)
				{

					switch(opcionesModificarJugador){
					case 1:
						if(utn_getDescripcion(auxNombre,sizeof(auxNombre),"Ingrese el nombre del jugador\n","Error, Asegurese de ingresar algo\n",20)==0){
							strcpy(jugadores[indiceJugador].nombre,auxNombre);
							retorno = 1;
						}
						break;
					case 2:
						if(jug_posicion(auxPosicion) == 1){
							strcpy(jugadores[indiceJugador].posicion,auxPosicion);
							retorno = 1;
						}
						break;
					case 3:
						if(utn_getNumeroShort(&auxNumeroCamiseta,"Ingrese el numero de camiseta\n","Error/ La camiseta no puedo ser menor a 1 y mayor a 99\n",1,99,20)==1){
							jugadores[indiceJugador].numeroCamiseta = auxNumeroCamiseta;
							retorno = 1;
						}
						break;
					case 4:
						confe_mostrar(confederaciones,tamConfederacion);
						if(utn_getNumeroINT(&auxIdConfederacion,"Ingrese la ID de la confederacion del jugador\n","Error/ Ingrese una ID valida\n",100,105,20)==1){
							jugadores[indiceJugador].idConfederacion = auxIdConfederacion;
							retorno = 1;
						}
						break;
					case 5:
						if(utn_getNumeroFLOAT(&auxSalario,"Ingrese el Salario del jugador\n","Error/ El salario no puede ser menor a 1\n",1,100000000,20)== 1){
							jugadores[indiceJugador].salario = auxSalario;
							retorno = 1;
						}
						break;
					case 6:
						if(utn_getNumeroShort(&auxAniosContrato,"Ingrese los Años de contrato del jugador\n","Error/ No puede ser menor a 1 y mayor 20\n",1,20,20)==1){
							jugadores[indiceJugador].aniosContrato = auxAniosContrato;
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
void jug_ordenarPorId(eJugador jugadores[],int tamJugador){
	if(tamJugador > 0){
		for(int i=0;i<tamJugador -1;i++){

			for(int j=i+1;j<tamJugador;j++){

				if(jugadores[i].isEmpty == 1){
					if(jugadores[i].idJugador > jugadores[j].idJugador){
						if(jug_swap(&jugadores[i],&jugadores[j])==0){
							break;
						}
					}
				}
			}
		}
	}
}

void jug_mostrar(eJugador jugadores[],int tamJugador,eConfederacion confederaciones[],int tamConfederacion){
	if(tamJugador > 0 && tamConfederacion > 0){

		printf("|====================================================================================================================================|\n"
			   "|  ID  |             Nombre             |       Posicion       |    Num. camiseta   |  Confederacion  |  Salario   |Años de Contrato |\n"
			   "|====================================================================================================================================|\n");
		for(int i=0;i<tamJugador;i++){
				if(jugadores[i].isEmpty == 1){
					jug_mostrarUnJugador(jugadores, i, confederaciones, tamConfederacion);
				}
		}
		printf("|====================================================================================================================================|\n");
	}
}

int jug_mostrarUnJugador(eJugador jugador[],int indiceJug,eConfederacion confederaciones[],int tamConfe){
	int retorno = 0;
	int pIndiceConf;
	if(tamConfe > 0){

		if(confe_buscarId(confederaciones, tamConfe,jugador[indiceJug].idConfederacion,&pIndiceConf)==1){

			printf("| %-4d | %-30s | %-20s | %-16hi   | %-15s | %-10.2f | %-15hi |\n",
									jugador[indiceJug].idJugador,
									jugador[indiceJug].nombre,
									jugador[indiceJug].posicion,
									jugador[indiceJug].numeroCamiseta,
									confederaciones[pIndiceConf].nombre,
									jugador[indiceJug].salario,
									jugador[indiceJug].aniosContrato);
			retorno = 1;

		}
	}
	return retorno;
}

int jug_swap(eJugador* jugadorUno,eJugador* jugadorDos){
	int retorno=0;
	eJugador aux;
	if(jugadorUno != NULL && jugadorDos != NULL)
	{
		aux = *jugadorUno;
		*jugadorUno = *jugadorDos;
		*jugadorDos = aux;
		retorno = 1;
	}
	return retorno;
}


