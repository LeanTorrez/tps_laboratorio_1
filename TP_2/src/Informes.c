/*
 * MostrarInformes.c
 *
 *  Created on: 22 oct. 2022
 *      Author: leand
 */

#include "Informes.h"

/**
 * \fn int inf_contadorJugadoresTotales(eJugador[], int, int*)
 * \brief Cuenta la cantidad de jugadores activos que se encuentran en al struct, y los suma
 * al contador que entra por referencia
 *
 * \param jugador Parametro para Struct Jugador
 * \param tamJugador El tamaño de Struct Jugador
 * \param contadorJugadoresTotales Puntero al contador que sumara la cantidad de jugadores
 * \return Retorna 1 en caso exitoso, 0 en caso de error en el programa
 */
static int inf_contadorJugadoresTotales(eJugador jugadores[],int tamJugador,int* contadorJugadoresTotales);

/**
 * \fn int inf_acumuladorSalarioJugadores(eJugador[], int, float*)
 * \brief Acumula los salarios de los jugadores activos en Struct jugador
 *
 * \param jugador Parametro para Struct Jugador
 * \param tamJugador El tamaño de Struct Jugador
 * \param acumuladorSalario Puntero a la variable que acumulara los salarios
 * \return 1 en caso exitoso, 0 en caso de error en el programa
 */
static int inf_acumuladorSalarioJugadores(eJugador jugadores[],int tamJugador,float* acumuladorSalario);

/**
 * \fn int inf_jugadoresSuperanPromedioSalarios(eJugador[], int, float, int*)
 * \brief Itera dentro de la struct jugador, dentro los jugadores activos comparara el promedio de salarios, que entra por parametro , y si supera el mismo
 * se lo sumara al contador
 *
 * \param jugador Parametro para Struct Jugador
 * \param tamJugador El tamaño de Struct Jugador
 * \param promedioSalario El promedio que entra por valor para ser comparado
 * \param contadorJugadoresSuperanPromedio Puntero a la variable que sumara en caso de encontrar un jugadores que supere el mismo
 * \return 1 en caso exitoso, 0 en caso de error en el programa
 */
static int inf_jugadoresSuperanPromedioSalarios(eJugador jugadores[],int tamJugador,float promedioSalario,int* contadorJugadoresSuperanPromedio);

/**
 * fn int inf_confederacionConMasAniosContrato(eJugador[], int, int, short*)
 * \brief Compara por la id de la confederacion que entra por parametro, y acumula la cantidad de años de contrato que tenga la misma
 * confederacion que ingreso por id
 *
 * \param jugador Parametro para Struct Jugador
 * \param tamJugador El tamaño de Struct Jugador
 * \param IdConfederacion Id de la confederacion que desea obtener los datos de los años de contratos
 * \param acumuladorAnios Puntero a la variable que acumulara los años de contrato
 * \return 1 en caso exitoso, 0 en caso de error en el programa
 */
static int inf_confederacionConMasAniosContrato(eJugador jugadores[],int tamJugador,int IdConfederacion,short* acumuladorAnios);

/**
 * \fn int inf_contadorJugadoresPorConfederacion(eJugador[], int, int, int*)
 * \brief Ingresa por valor la id de la confederacion que desea saber cuantos jugadores hay en la misma
 *
 * \param jugador Parametro para Struct Jugador
 * \param tamJugador El tamaño de Struct Jugador
 * \param idConfederacion Id de la confederacion que se usara como busqueda
 * \param contadorJugadoresConfederacion Puntero a la variable contador que sumara los jugadores en caso de haberlos
 * \return 1 en caso exitoso, 0 en caso de error en el programa
 */
static int inf_contadorJugadoresPorConfederacion(eJugador jugadores[],int tamJugador,int idConfederacion,int* contadorJugadoresConfederacion);

/**
 * \fn int  inf_nombreConfederacion(eConfederacion[], int, int, char*)
 * \brief Pasa por parametro la id de la confedereracion y guarda el nombre de la misma en la variable pasada por referencia
 *
 *
 * \param confederacion Parametro para Struct Confederacion
 * \param tamConfederacion El tamaño de Struct Confdederacion
 * \param IdAbuscar Id de la confederacion que desea obtener el indice
 * \param pNombre Puntero adonde se guarda el nombre de la confederacion
 * \return 1 en caso exitoso, 0 en caso de error en el programa
 */
static int inf_nombreConfederacion(eConfederacion confederaciones[],int tamConfederacion,int IdAbuscar,char* pNombre);

/**
 * \fn int inf_menuTotalpromedioSalario(eJugador[], int)
 * \brief	hace los calculos pertienentes para el promedio del jugador y si alguno supera el mismo
 *
 * \param jugadores Parametro para Struct Jugador
 * \param tamJugador El tamaño de Struct Jugador
 * \return 1 en caso exitoso, 0 en caso de error en el programa
 */
static int inf_menuTotalpromedioSalario(eJugador jugadores[],int tamJugador);

/**
 * \fn float inf_calcularPorcentaje(int, int)
 * \brief  Calcula el porcentaje de los numeros que entrar por parametros, siendo el primero multlipicado por 100
 * y divido por el segundo parametro
 *
 * \param numeroPorcentaje Numero al cual se desea sacar el porcentaje
 * \param contadorTotal El numero por el cual se dividira el Numero que desea saber el porcentaje
 * \return Devuelve el numero en float
 */
static float inf_calcularPorcentaje(int numeroPorcentaje, int contadorTotal);

/**
 * \fn float inf_calcularPromedio(float, int)
 * \brief Calcula el promedio de los numero que entrar por parametro, siendo el primer parametro se divide por el segundo
 *
 * \param acumulador La acumulacion de los numeros que se desea saber el promedio
 * \param contadorTotal El contador por el cual se dividira el numero acumulado
 * \return Devuelve el numero en float
 */
static float inf_calcularPromedio(float acumulador,int contadorTotal);

/**
 * \fn int inf_menuJugadoresPorConfederacion(eJugador[], int, eConfederacion[], int)
 * \brief logica a la hora de mostrar los jugadores de cada confederacion
 *
 * \param jugadores  Parametro para Struct jugador
 * \param tamJugador El tamaño de Struct jugador
 * \param confederaciones Parametro para Struct Confederacion
 * \param tamConfederacion El tamaño de Struct Confdederacion
 * \return 1 en caso exitoso, 0 en caso de error en el programa
 */
static int inf_menuJugadoresPorConfederacion(eJugador jugadores[],int tamJugador,eConfederacion confederaciones[],int tamConfederacion);

/**
 * \fn int inf_menuConfederacionMayorAniosContrato(eJugador[], int)
 * \brief obtiene los datos de cada confederacion en años de contrato y compara el cual tiene el mayor
 *
 * \param jugadores Parametro para Struct jugador
 * \param tamJugador El tamaño de Struct jugador
 * \return 1 en caso exitoso, 0 en caso de error en el programa
 */
static int inf_menuConfederacionMayorAniosContrato(eJugador jugadores[],int tamJugador);

/**
 * \fn int inf_menuPorcentajesConfederacion(eJugador[], int)
 * \brief Obtiene la cantidad total de jugadores y cuantos en cada confederacion existen y
 * hace los calculos en base a esa informacion
 *
 * \param jugadores Parametro para Struct jugador
 * \param tamJugador El tamaño de Struct jugador
 * \return 1 en caso exitoso, 0 en caso de error en el programa
 */
static int inf_menuPorcentajesConfederacion(eJugador jugadores[],int tamJugador);

/**
 * \fn int inf_menuRegionMasJugadores(eJugador[], int, eConfederacion[], int)
 * \brief Cuenta la cantidad de jugadores de cada confederacion y los compara entre si
 * para saber cual tiene la mayor cantidad
 *
 * \param jugadores Parametro para Struct jugador
 * \param tamJugador El tamaño de Struct jugador
 * \param confederaciones Parametro para Struct confederacion
 * \param tamConfederacion El tamaño de Struct confederacion
 * \return 1 en caso exitoso, 0 en caso de error en el programa
 */
static int inf_menuRegionMasJugadores(eJugador jugadores[],int tamJugador,eConfederacion confederaciones[],int tamConfederacion);


int inf_menu(eJugador jugadores[],int tamJugador,eConfederacion confederaciones[],int tamConfederacion){
	int retorno=0;
	int opcionesInformes;
	if(tamJugador > 0 && tamConfederacion > 0){
		if(utn_getNumeroINT(&opcionesInformes,
				"1.Lista de Jugadores Alfabeticamente\n"
				"2.Lista de Jugadores Por Confederacion\n"
				"3.Total y Promedio de los salarios de los jugadores\n"
				"4.Informe de la confederacion con mayor cantidad de años de contrato\n"
				"5.Informe de porcentaje de jugadores por confederacion\n"
				"6.Informe cual es la Region con mas Jugadores\n",
				"Error/ Eliga una opcion valida (1 al 6)\n",1,6,20)==0)
		{
			opcionesInformes = 0;
			printf("Se superaron los reintentos regresando al menu\n");
		}

		switch(opcionesInformes){
		case 1:
			printf("------------------->Lista de Jugadores Alfabeticamente<-------------------\n");
			inf_ordenamientoJugadorPorConfederacion(jugadores, tamJugador, confederaciones, tamConfederacion);
			jug_mostrar(jugadores, tamJugador, confederaciones, tamConfederacion);
			retorno=1;
			break;
		case 2:
			printf("------------------->Lista de Jugadores Por Confederacion<-------------------\n");
			if(inf_menuJugadoresPorConfederacion(jugadores, tamJugador, confederaciones, tamConfederacion)==0){
				printf("Error al mostrar las listas... regresando al menu\n");
			}
			retorno=1;
			break;
		case 3:
			printf("------------------->Total y Promedio de los salarios de los jugadores<-------------------\n");
			if(inf_menuTotalpromedioSalario(jugadores, tamJugador)==0){
				printf("Error al mostrar los mostar los promedios... regresando al menu\n");
			}
			retorno=1;
			break;
		case 4:
			printf("------------------->Informe de la confederacion con mayor cantidad de años de contrato<-------------------\n");
			if(inf_menuConfederacionMayorAniosContrato(jugadores, tamJugador)==0){
				printf("Error al mostrar los resultados ... regresando al menu\n");
			}
			retorno=1;
			break;
		case 5:
			printf("------------------->Informe de porcentaje de jugadores por confederacion<-------------------\n");
			if(inf_menuPorcentajesConfederacion(jugadores, tamJugador)==0){
				printf("Error al mostrar los resultados ... regresando al menu\n");
			}
			retorno=1;
			break;
		case 6:
			printf("------------------->Informe cual es la Region con mas Jugadores<-------------------\n");
			if(inf_menuRegionMasJugadores(jugadores, tamJugador, confederaciones, tamConfederacion)==0){
				printf("Error al mostrar los resultados ... regresando al menu\n");
			}
			retorno=1;
			break;
		}
	}
	return retorno;
}

static int inf_contadorJugadoresTotales(eJugador jugadores[],int tamJugador,int* contadorJugadoresTotales){
	int retorno=0;
	if(tamJugador>0){
		for(int i=0;i<tamJugador;i++){
			if(jugadores[i].isEmpty == 1){
				*contadorJugadoresTotales += 1;
				retorno=1;
			}
		}
	}
	return retorno;
}

int inf_ordenamientoJugadorPorConfederacion(eJugador jugadores[],int tamJugador,eConfederacion confederaciones[],int tamConfederacion){
	int retorno=0;
	char AuxNombreConfederacionI[50];
	char AuxNombreConfederacionJ[50];
//	eJugador auxiliar;

	for(int i=0;i<tamJugador-1;i++){

		if(jugadores[i].isEmpty == 1){

			for(int j=i+1;j<tamJugador;j++){

				if(jugadores[j].isEmpty == 1){

					inf_nombreConfederacion(confederaciones, tamConfederacion,jugadores[i].idConfederacion,AuxNombreConfederacionI);
					inf_nombreConfederacion(confederaciones, tamConfederacion,jugadores[j].idConfederacion,AuxNombreConfederacionJ);

					if(stricmp(AuxNombreConfederacionI,AuxNombreConfederacionJ)>0){
						jug_swap(&jugadores[i],&jugadores[j]);
						retorno=1;
					}else{
						if(stricmp(AuxNombreConfederacionI,AuxNombreConfederacionJ)==0){
							if(stricmp(jugadores[i].nombre,jugadores[j].nombre)>0){
								jug_swap(&jugadores[i],&jugadores[j]);
								retorno=1;
							}
						}
					}
				}
			}
		}
	}
	return retorno;
}

static int inf_menuRegionMasJugadores(eJugador jugadores[],int tamJugador,eConfederacion confederaciones[],int tamConfederacion){
	int retorno = 0;

	int contadorJugadorCONMEBOL=0;
	int contadorJugadorUEFA=0;
	int contadorJugadorAFC=0;
	int contadorJugadorCONCACAF=0;
	int contadorJugadorCAF=0;
	int contadorJugadorOFC=0;

	int auxIdConfederacion = 0;
	if(tamConfederacion > 0 && tamJugador > 0){

		inf_contadorJugadoresPorConfederacion(jugadores, tamJugador, 100,&contadorJugadorCONMEBOL);
		inf_contadorJugadoresPorConfederacion(jugadores, tamJugador, 101,&contadorJugadorUEFA);
		inf_contadorJugadoresPorConfederacion(jugadores, tamJugador, 102,&contadorJugadorAFC);
		inf_contadorJugadoresPorConfederacion(jugadores, tamJugador, 103,&contadorJugadorCAF);
		inf_contadorJugadoresPorConfederacion(jugadores, tamJugador, 104,&contadorJugadorCONCACAF);
		inf_contadorJugadoresPorConfederacion(jugadores, tamJugador, 105,&contadorJugadorOFC);

		if(contadorJugadorCONMEBOL > contadorJugadorUEFA && contadorJugadorCONMEBOL > contadorJugadorOFC && contadorJugadorCONMEBOL > contadorJugadorCONCACAF && contadorJugadorCONMEBOL > contadorJugadorCAF && contadorJugadorCONMEBOL > contadorJugadorAFC){
			printf("\nLa Region con mas jugadores es SUDAMERICA con CONMEBOL");
			auxIdConfederacion = 100;

		}else{
			if(contadorJugadorUEFA > contadorJugadorOFC && contadorJugadorUEFA > contadorJugadorCONCACAF && contadorJugadorUEFA > contadorJugadorCAF && contadorJugadorUEFA > contadorJugadorAFC){
				printf("\nLa Region con mas jugadores es EUROPA con UEFA");
				auxIdConfederacion = 101;

			}else{
				if(contadorJugadorOFC > contadorJugadorCONCACAF && contadorJugadorOFC > contadorJugadorCAF && contadorJugadorOFC > contadorJugadorAFC){
					printf("\nLa Region con mas jugadores es OCEANIA con la OFC");
					auxIdConfederacion = 105;

				}else{
					if(contadorJugadorCONCACAF > contadorJugadorCAF && contadorJugadorCONCACAF > contadorJugadorAFC){
						printf("\nLa Region con mas jugadores es NORTE Y CENTRO AMERICA con CONCACAF");
						auxIdConfederacion = 104;

					}else{
						if(contadorJugadorCAF > contadorJugadorAFC){
							printf("\nLa Region con mas jugadores es AFRICA con CAF");
							auxIdConfederacion = 103;

						}else{
							printf("\nLa Region con mas jugadores es ASIA con la AFC");
							auxIdConfederacion = 102;
						}
					}
				}
			}
		}
		if(auxIdConfederacion != 0){
			inf_mostrarJugadoresPorConfederacion(jugadores, tamJugador, confederaciones, tamConfederacion, auxIdConfederacion);
		}
		retorno=1;
	}
	return retorno;
}
static int inf_menuPorcentajesConfederacion(eJugador jugadores[],int tamJugador){
	int retorno = 0;
	int contadorJugadoresTotales=0;
	//Opcion 5 y 6
	int contadorJugadorCONMEBOL=0;
	int contadorJugadorUEFA=0;
	int contadorJugadorAFC=0;
	int contadorJugadorCONCACAF=0;
	int contadorJugadorCAF=0;
	int contadorJugadorOFC=0;

	//Opcion 5
	float porcentajeCONMEBOL;
	float porcentajeUEFA;
	float porcentajeAFC;
	float porcentajeCONCACAF;
	float porcentajeCAF;
	float porcentajeOFC;

	if(tamJugador > 0){
		inf_contadorJugadoresTotales(jugadores, tamJugador,&contadorJugadoresTotales);
		//No utilizo retorno porque pueden no existir jugadores en esa seleccion
		inf_contadorJugadoresPorConfederacion(jugadores, tamJugador, 100,&contadorJugadorCONMEBOL);
		inf_contadorJugadoresPorConfederacion(jugadores, tamJugador, 101,&contadorJugadorUEFA);
		inf_contadorJugadoresPorConfederacion(jugadores, tamJugador, 102,&contadorJugadorAFC);
		inf_contadorJugadoresPorConfederacion(jugadores, tamJugador, 103,&contadorJugadorCAF);
		inf_contadorJugadoresPorConfederacion(jugadores, tamJugador, 104,&contadorJugadorCONCACAF);
		inf_contadorJugadoresPorConfederacion(jugadores, tamJugador, 105,&contadorJugadorOFC);

		porcentajeCONMEBOL = inf_calcularPorcentaje(contadorJugadorCONMEBOL,contadorJugadoresTotales);
		porcentajeUEFA = inf_calcularPorcentaje(contadorJugadorCONMEBOL,contadorJugadoresTotales);
		porcentajeAFC = inf_calcularPorcentaje(contadorJugadorAFC,contadorJugadoresTotales);
		porcentajeCONCACAF = inf_calcularPorcentaje(contadorJugadorCONCACAF,contadorJugadoresTotales);
		porcentajeCAF = inf_calcularPorcentaje(contadorJugadorCAF,contadorJugadoresTotales);
		porcentajeOFC = inf_calcularPorcentaje(contadorJugadorOFC,contadorJugadoresTotales);

		printf("Porcentaje  CONMEBOL  %.2f\n"
						   "Porcentaje  UEFA      %.2f\n"
						   "Porcentaje  OFC       %.2f\n"
						   "Porcentaje  CONCACAF  %.2f\n"
						   "Porcentaje  CAF       %.2f\n"
						   "Porcentaje  AFC       %.2f\n",porcentajeCONMEBOL,porcentajeUEFA,porcentajeOFC,
						   	   	   	   	   	   	   	   	  porcentajeCONCACAF,porcentajeCAF,porcentajeAFC);
		retorno=1;
	}
	return retorno;
}

static int inf_menuJugadoresPorConfederacion(eJugador jugadores[],int tamJugador,eConfederacion confederaciones[],int tamConfederacion){
	int retorno = 0;
	if(tamJugador > 0 && tamConfederacion > 0){

		if(inf_mostrarJugadoresPorConfederacion(jugadores, tamJugador, confederaciones, tamConfederacion,100)==0){
			printf("|                                        NO HAY NINGUN JUGADOR QUE PERTENEZCA A CONMEBOL                                             |\n"
				   "|====================================================================================================================================|\n");
		}
		if(inf_mostrarJugadoresPorConfederacion(jugadores, tamJugador, confederaciones, tamConfederacion,101)==0){
			printf("|                                        NO HAY NINGUN JUGADOR QUE PERTENEZCA A LA UEFA                                              |\n"
				   "|====================================================================================================================================|\n");
		}
		if(inf_mostrarJugadoresPorConfederacion(jugadores, tamJugador, confederaciones, tamConfederacion,102)==0){
			printf("|                                        NO HAY NINGUN JUGADOR QUE PERTENEZCA A LA AFC                                               |\n"
				   "|====================================================================================================================================|\n");
		}
		if(inf_mostrarJugadoresPorConfederacion(jugadores, tamJugador, confederaciones, tamConfederacion,103)==0){
			printf("|                                        NO HAY NINGUN JUGADOR QUE PERTENEZCA A CAF                                                  |\n"
				   "|====================================================================================================================================|\n");
		}
		if(inf_mostrarJugadoresPorConfederacion(jugadores, tamJugador, confederaciones, tamConfederacion,104)==0){
			printf("|                                        NO HAY NINGUN JUGADOR QUE PERTENEZCA A LA CONCACAF                                          |\n"
				   "|====================================================================================================================================|\n");
		}
		if(inf_mostrarJugadoresPorConfederacion(jugadores, tamJugador, confederaciones, tamConfederacion,105)==0){
			printf("|                                        NO HAY NINGUN JUGADOR QUE PERTENEZCA A LA OFC                                               |\n"
				   "|====================================================================================================================================|\n");
		}
		retorno = 1;
	}
	return retorno;
}

static int inf_menuTotalpromedioSalario(eJugador jugadores[],int tamJugador){
	int retorno = 0;
	//Opcion 3 Total, Promedio Salarios y superan ese promedio
	int contadorJugadores = 0;
	float acumulador = 0;
	float promedio;
	int contadorSuperanPromedio = 0;

	if(tamJugador > 0){

		if(inf_acumuladorSalarioJugadores(jugadores, tamJugador, &acumulador)==1 &&
		   inf_contadorJugadoresTotales(jugadores, tamJugador,&contadorJugadores)==1)
		{
			promedio = inf_calcularPromedio(acumulador, contadorJugadores);

			if(inf_jugadoresSuperanPromedioSalarios(jugadores, tamJugador,promedio,&contadorSuperanPromedio)==1){
				printf("Los Salarios Acumulados de los jugadores es de %.2f, y el promedio del mismo es de %.2f\n"
						"La cantidad de jugadores que superan este promedio es de %d",acumulador,promedio,contadorSuperanPromedio);
				retorno = 1;
			}else{
				printf("Los Salarios Acumulados de los jugadores es de %.2f, y el promedio del mismo es de %.2f\n"
						"No existen jugadores que superen este promedio",acumulador,promedio);
				retorno = 1;
			}
		}
	}
	return retorno;
}

static int inf_menuConfederacionMayorAniosContrato(eJugador jugadores[],int tamJugador){
	int retorno = 0;
	//Opcion 4 Confederacion con mayor acumulado de años
	short acumuladorAniosCONMEBOL=0;
	short acumuladorAniosUEFA=0;
	short acumuladorAniosAFC=0;
	short acumuladorAniosCONCACAF=0;
	short acumuladorAniosCAF=0;
	short acumuladorAniosOFC=0;
	char auxAniosContrato[20];
	short auxAnios;

	if(tamJugador > 0){
		//No utilizo retorno porque pueden no existir jugadores en esa seleccion
		inf_confederacionConMasAniosContrato(jugadores, tamJugador,100,&acumuladorAniosCONMEBOL);
		inf_confederacionConMasAniosContrato(jugadores, tamJugador,101,&acumuladorAniosUEFA);
		inf_confederacionConMasAniosContrato(jugadores, tamJugador,102,&acumuladorAniosAFC);
		inf_confederacionConMasAniosContrato(jugadores, tamJugador,103,&acumuladorAniosCAF);
		inf_confederacionConMasAniosContrato(jugadores, tamJugador,104,&acumuladorAniosCONCACAF);
		inf_confederacionConMasAniosContrato(jugadores, tamJugador,105,&acumuladorAniosOFC);

		if(acumuladorAniosCONMEBOL > acumuladorAniosUEFA && acumuladorAniosCONMEBOL > acumuladorAniosAFC && acumuladorAniosCONMEBOL > acumuladorAniosCAF && acumuladorAniosCONMEBOL > acumuladorAniosCONCACAF && acumuladorAniosCONMEBOL > acumuladorAniosOFC){
			strcpy(auxAniosContrato,"CONMEBOL");
			auxAnios = acumuladorAniosCONMEBOL;

		}else{
			if(acumuladorAniosUEFA > acumuladorAniosAFC && acumuladorAniosUEFA > acumuladorAniosCAF && acumuladorAniosUEFA > acumuladorAniosCONCACAF && acumuladorAniosUEFA > acumuladorAniosOFC){
				strcpy(auxAniosContrato,"UEFA");
				auxAnios = acumuladorAniosUEFA;

			}else{
				if(acumuladorAniosAFC > acumuladorAniosCAF && acumuladorAniosAFC > acumuladorAniosCONCACAF && acumuladorAniosAFC > acumuladorAniosOFC){
					strcpy(auxAniosContrato,"AFC");
					auxAnios = acumuladorAniosAFC;

				}else{
					if(acumuladorAniosCAF > acumuladorAniosCONCACAF && acumuladorAniosCAF > acumuladorAniosOFC){
						strcpy(auxAniosContrato,"CAF");
						auxAnios = acumuladorAniosCAF;

					}else{
						if(acumuladorAniosCONCACAF > acumuladorAniosOFC){
							strcpy(auxAniosContrato,"CONCACAF");
							auxAnios = acumuladorAniosCONCACAF;

						}else{
							strcpy(auxAniosContrato,"OFC");
							auxAnios = acumuladorAniosOFC;

						}
					}
				}
			}
		}
		printf("La confederacion con mas años en contrato es la %s, y el total de años que tiene es %hi\n",auxAniosContrato,auxAnios);
		retorno=1;
	}
	return retorno;
}

int inf_mostrarJugadoresPorConfederacion(eJugador jugadores[],int tamJugador,eConfederacion confederaciones[],int tamConfederacion,int idConfederacion){
	int retorno=0;
	//int auxConfederacion;
	if(tamJugador > 0 && tamConfederacion > 0){
		printf("\n\n|====================================================================================================================================|\n"
					   "|  ID  |             Nombre             |       Posicion       |    Num. camiseta   |  Confederacion  |  Salario   |Años de Contrato |\n"
					   "|====================================================================================================================================|\n");
		for(int i=0;i<tamJugador;i++){

			if(jugadores[i].idConfederacion == idConfederacion){
				jug_mostrarUnJugador(jugadores, i, confederaciones, tamConfederacion);
				retorno=1;
			}
		}
		printf("|====================================================================================================================================|\n");
	}
	return retorno;
}

static int inf_acumuladorSalarioJugadores(eJugador jugadores[],int tamJugador,float* acumuladorSalario){
	int retorno=0;
	if(tamJugador>0){
		for(int i=0;i<tamJugador;i++){
			if(jugadores[i].isEmpty == 1){
				*acumuladorSalario = *acumuladorSalario + jugadores[i].salario;
				retorno=1;
			}
		}
	}
	return retorno;
}

static int inf_jugadoresSuperanPromedioSalarios(eJugador jugadores[],int tamJugador,float promedioSalario,int* contadorJugadoresSuperanPromedio){
	int retorno=0;
	if(tamJugador>0){
		for(int i=0;i<tamJugador;i++){
			if(jugadores[i].isEmpty == 1){
				if(jugadores[i].salario > promedioSalario){
					*contadorJugadoresSuperanPromedio += 1;
					retorno=1;
				}
			}
		}
	}
	return retorno;
}

static int inf_confederacionConMasAniosContrato(eJugador jugadores[],int tamJugador,int IdConfederacion,short* acumuladorAnios){
	int retorno=0;
	if(tamJugador>0){
		for(int i=0;i<tamJugador;i++){
			if(jugadores[i].isEmpty == 1 ){
				if(jugadores[i].idConfederacion == IdConfederacion){
					*acumuladorAnios = *acumuladorAnios + jugadores[i].aniosContrato;
					retorno=1;
				}
			}
		}
	}
	return retorno;
}

static int inf_contadorJugadoresPorConfederacion(eJugador jugadores[],int tamJugador,int idConfederacion,int* contadorJugadoresConfederacion){
	int retorno=0;
	if(tamJugador>0){
		for(int i=0;i<tamJugador;i++){
			if(jugadores[i].isEmpty == 1 ){
				if(jugadores[i].idConfederacion == idConfederacion){
					*contadorJugadoresConfederacion += 1;
					retorno=1;
				}
			}
		}
	}
	return retorno;
}

static int inf_nombreConfederacion(eConfederacion confederaciones[],int tamConfederacion,int IdAbuscar,char* pNombre){
	int retorno=0;
	for(int i=0;tamConfederacion;i++){
		if(confederaciones[i].IsEmpty == 1){
			if(confederaciones[i].idConfederacion == IdAbuscar ){
				strcpy(pNombre,confederaciones[i].nombre);
				retorno=1;
				break;
			}
		}
	}
	return retorno;
}


static float inf_calcularPorcentaje(int numeroPorcentaje, int contadorTotal){
	float resultado;
	resultado = ((float) numeroPorcentaje * 100) / contadorTotal;
	return resultado;
}

static float inf_calcularPromedio(float acumulador,int contadorTotal){
	float resultado;
	resultado = acumulador / (float) contadorTotal;
	return resultado;
}
