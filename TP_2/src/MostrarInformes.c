/*
 * MostrarInformes.c
 *
 *  Created on: 22 oct. 2022
 *      Author: leand
 */

#include "MostrarInformes.h"

int MostrarInformes(eJugador jugador[],int tamJugador,eConfederacion confederacion[],int tamConfederacion){
	int retorno=0;
	int opcionesInformes;

	//ContadorTotalDeJugadore
	int contadorTotalJugadores=0;

	//Opcion 3 Total, Promedio Salarios y superan ese promedio
	float acumulador=0;
	float promedio;
	int contadorSuperanPromedio=0;

	//Opcion 4 Confederacion con mayor acumulado de años
	short acumuladorAniosCONMEBOL=0;
	short acumuladorAniosUEFA=0;
	short acumuladorAniosAFC=0;
	short acumuladorAniosCONCACAF=0;
	short acumuladorAniosCAF=0;
	short acumuladorAniosOFC=0;
	char auxAniosContrato[20];
	short auxAnios;

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



	if(tamJugador > 0 && tamConfederacion > 0){
		utn_getNumeroINT(&opcionesInformes,"1.Lista de Jugadores Alfabeticamente\n2.Lista de Jugadores Por Confederacion\n3.Total y Promedio de los salarios de los jugadores\n4.Informe de la confederacion con mayor cantidad de años de contrato\n5.Informe de porcentaje de jugadores por confederacion\n6.Informe cual es la Region con mas Jugadores\n","Error/ Eliga una opcion valida (1 al 6)\n",1,6,20);

		//Funcion para el uso de la opcion 3 y 5
		ContadorJugadoresTotal(jugador, tamJugador,&contadorTotalJugadores);

		//Funciones para el uso de la Opcion 5 y 6
		ContadorConfederacionJugadores(jugador,tamJugador,100,&contadorJugadorCONMEBOL);
		ContadorConfederacionJugadores(jugador,tamJugador,101,&contadorJugadorUEFA);
		ContadorConfederacionJugadores(jugador,tamJugador,102,&contadorJugadorAFC);
		ContadorConfederacionJugadores(jugador,tamJugador,103,&contadorJugadorCAF);
		ContadorConfederacionJugadores(jugador,tamJugador,104,&contadorJugadorCONCACAF);
		ContadorConfederacionJugadores(jugador,tamJugador,105,&contadorJugadorOFC);

		switch(opcionesInformes){
		case 1:
			printf("------------------->Lista de Jugadores Alfabeticamente<-------------------\n");
			OrdenamientoStructJugadorConfederacionNombre(jugador, tamJugador, confederacion, tamConfederacion);
			MostrarStructJugador(jugador,tamJugador,confederacion,tamConfederacion);
			break;
		case 2:
			printf("------------------->Lista de Jugadores Por Confederacion<-------------------\n");
			MostrarJugadoresOrdenadosConfederacion(jugador,tamJugador,confederacion,tamConfederacion,100);
			MostrarJugadoresOrdenadosConfederacion(jugador,tamJugador,confederacion,tamConfederacion,101);
			MostrarJugadoresOrdenadosConfederacion(jugador,tamJugador,confederacion,tamConfederacion,102);
			MostrarJugadoresOrdenadosConfederacion(jugador,tamJugador,confederacion,tamConfederacion,103);
			MostrarJugadoresOrdenadosConfederacion(jugador,tamJugador,confederacion,tamConfederacion,104);
			MostrarJugadoresOrdenadosConfederacion(jugador,tamJugador,confederacion,tamConfederacion,105);
			break;
		case 3:
			printf("------------------->Total y Promedio de los salarios de los jugadores<-------------------\n");
			AcumuladorSalarioStructJugador(jugador, tamJugador,&acumulador);

			promedio = CalcularPromedio(acumulador,contadorTotalJugadores);

			if(JugadorSalarioSuperanPromedio(jugador, tamJugador,promedio,&contadorSuperanPromedio) == 1){
				printf("Los Salarios Acumulados de los jugadores es de %.2f, y el promedio del mismo es de %.2f\n"
						"La cantidad de jugadores que superan este promedio es de %d",acumulador,promedio,contadorSuperanPromedio);
			}else{
				printf("Los Salarios Acumulados de los jugadores es de %.2f, y el promedio del mismo es de %.2f\n"
										"No existen jugadores que superen este promedio",acumulador,promedio);
			}

			break;
		case 4:
			printf("------------------->Informe de la confederacion con mayor cantidad de años de contrato<-------------------\n");

			ConfederacionConMasAniosContrato(jugador, tamJugador,100,&acumuladorAniosCONMEBOL);
			ConfederacionConMasAniosContrato(jugador, tamJugador,101,&acumuladorAniosUEFA);
			ConfederacionConMasAniosContrato(jugador, tamJugador,102,&acumuladorAniosAFC);
			ConfederacionConMasAniosContrato(jugador, tamJugador,103,&acumuladorAniosCAF);
			ConfederacionConMasAniosContrato(jugador, tamJugador,104,&acumuladorAniosCONCACAF);
			ConfederacionConMasAniosContrato(jugador, tamJugador,105,&acumuladorAniosOFC);

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

			break;
		case 5:
			printf("------------------->Informe de porcentaje de jugadores por confederacion<-------------------\n");
			porcentajeCONMEBOL = CalcularPorcentaje(contadorJugadorCONMEBOL,contadorTotalJugadores);
			porcentajeUEFA = CalcularPorcentaje(contadorJugadorUEFA,contadorTotalJugadores);
			porcentajeAFC = CalcularPorcentaje(contadorJugadorAFC,contadorTotalJugadores);
			porcentajeCAF = CalcularPorcentaje(contadorJugadorCAF,contadorTotalJugadores);
			porcentajeCONCACAF = CalcularPorcentaje(contadorJugadorCONCACAF,contadorTotalJugadores);
			porcentajeOFC = CalcularPorcentaje(contadorJugadorOFC,contadorTotalJugadores);

			printf("Porcentaje  CONMEBOL  %.2f\n"
				   "Porcentaje  UEFA      %.2f\n"
				   "Porcentaje  OFC       %.2f\n"
				   "Porcentaje  CONCACAF  %.2f\n"
				   "Porcentaje  CAF       %.2f\n"
				   "Porcentaje  AFC       %.2f\n",porcentajeCONMEBOL,porcentajeUEFA,porcentajeOFC,
				   	   	   	   	   	   	   	   	  porcentajeCONCACAF,porcentajeCAF,porcentajeAFC);

			break;
		case 6:
			printf("------------------->Informe cual es la Region con mas Jugadores<-------------------\n");

			if(contadorJugadorCONMEBOL > contadorJugadorUEFA && contadorJugadorCONMEBOL > contadorJugadorOFC && contadorJugadorCONMEBOL > contadorJugadorCONCACAF && contadorJugadorCONMEBOL > contadorJugadorCAF && contadorJugadorCONMEBOL > contadorJugadorAFC){
				printf("\nLa Region con mas jugadores es SUDAMERICA con CONMEBOL");
				MostrarJugadoresOrdenadosConfederacion(jugador,tamJugador,confederacion,tamConfederacion,100);

			}else{
				if(contadorJugadorUEFA > contadorJugadorOFC && contadorJugadorUEFA > contadorJugadorCONCACAF && contadorJugadorUEFA > contadorJugadorCAF && contadorJugadorUEFA > contadorJugadorAFC){
					printf("\nLa Region con mas jugadores es EUROPA con UEFA");
					MostrarJugadoresOrdenadosConfederacion(jugador,tamJugador,confederacion,tamConfederacion,101);

				}else{
					if(contadorJugadorOFC > contadorJugadorCONCACAF && contadorJugadorOFC > contadorJugadorCAF && contadorJugadorOFC > contadorJugadorAFC){
						printf("\nLa Region con mas jugadores es OCEANIA con la OFC");
						MostrarJugadoresOrdenadosConfederacion(jugador,tamJugador,confederacion,tamConfederacion,105);

					}else{
						if(contadorJugadorCONCACAF > contadorJugadorCAF && contadorJugadorCONCACAF > contadorJugadorAFC){
							printf("\nLa Region con mas jugadores es NORTE Y CENTRO AMERICA con CONCACAF");
							MostrarJugadoresOrdenadosConfederacion(jugador,tamJugador,confederacion,tamConfederacion,104);

						}else{
							if(contadorJugadorCAF > contadorJugadorAFC){
								printf("\nLa Region con mas jugadores es AFRICA con CAF");
								MostrarJugadoresOrdenadosConfederacion(jugador,tamJugador,confederacion,tamConfederacion,103);

							}else{
								printf("\nLa Region con mas jugadores es ASIA con la AFC");
								MostrarJugadoresOrdenadosConfederacion(jugador,tamJugador,confederacion,tamConfederacion,102);

							}
						}
					}
				}
			}

			break;
		}
	}
	return retorno;
}

int ContadorJugadoresTotal(eJugador jugador[],int tamJugador,int* contadorJugadoresTotales){
	int retorno=0;
	if(tamJugador>0){
		for(int i=0;i<tamJugador;i++){
			if(jugador[i].isEmpty == 1){
				*contadorJugadoresTotales += 1;
				retorno=1;
			}
		}
	}
	return retorno;
}
int BuscarIndiceComparacion(eConfederacion confederacion[],int tamConfederacion,int IdAbuscar,int* pIndice){
	int retorno=0;
	for(int i=0;tamConfederacion;i++){
		if(confederacion[i].idConfederacion == IdAbuscar ){
			*pIndice = i;
			retorno=1;
			break;
		}
	}
	return retorno;
}


void OrdenamientoStructJugadorConfederacionNombre(eJugador jugador[],int tamJugador,eConfederacion confederacion[],int tamConfederacion){
	int auxiliarDeConfederacionI;
	int auxiliarDeConfederacionJ;
	eJugador auxiliar;
	for(int i=0;i<tamJugador -1;i++){

		for(int j=i+1;j<tamJugador;j++){
			//Estas dos funciones me devuelven el Indice de la confederacion para poder hacer la comparacion de mejor manera
			BuscarIndiceComparacion(confederacion, tamConfederacion,jugador[i].idConfederacion,&auxiliarDeConfederacionI);
			BuscarIndiceComparacion(confederacion, tamConfederacion,jugador[j].idConfederacion,&auxiliarDeConfederacionJ);

			if(stricmp(confederacion[auxiliarDeConfederacionI].nombre,confederacion[auxiliarDeConfederacionJ].nombre)>0){
				auxiliar = jugador[i];
				jugador[i] = jugador[j];
				jugador[j] = auxiliar;
			}else{
				if(stricmp(confederacion[auxiliarDeConfederacionI].nombre,confederacion[auxiliarDeConfederacionJ].nombre)==0){
					if(stricmp(jugador[i].nombre,jugador[j].nombre)>0){
						auxiliar = jugador[i];
						jugador[i] = jugador[j];
						jugador[j] = auxiliar;
					}
				}
			}

		}
	}
}

int MostrarJugadoresOrdenadosConfederacion(eJugador jugador[],int tamJugador,eConfederacion confederacion[],int tamConfederacion,int IdConfederacion){
	int retorno=0;
	int auxConfederacion;
	if(tamJugador>0 && tamConfederacion){
		BuscarIndiceComparacion(confederacion, tamConfederacion,IdConfederacion,&auxConfederacion);
		printf("\n\n %55s \n"
				"|================================================================================================================|\n"
				"|   ID  |            Nombre              |       Posicion       | Num. de Camiseta |  Salario  | Años De contrato|\n"
				"|================================================================================================================|\n",confederacion[auxConfederacion].nombre);

		for(int i=0;i<tamJugador;i++){

			if(jugador[i].idConfederacion == IdConfederacion){
				printf("| %-5d | %-30s | %-20s | %-16hi | %-10.2f| %-15hi |\n",jugador[i].idJugador,
												  jugador[i].nombre,
												  jugador[i].posicion,
												  jugador[i].numeroCamiseta,
												  jugador[i].salario,
												  jugador[i].aniosContrato);
				retorno=1;
			}
		}
		printf("|================================================================================================================|\n");
	}
	return retorno;
}

int AcumuladorSalarioStructJugador(eJugador jugador[],int tamJugador,float* acumuladorSalario){
	int retorno=0;
	if(tamJugador>0){
		for(int i=0;i<tamJugador;i++){
			if(jugador[i].isEmpty == 1){
				*acumuladorSalario = *acumuladorSalario + jugador[i].salario;
				retorno=1;
			}
		}
	}
	return retorno;
}

int JugadorSalarioSuperanPromedio(eJugador jugador[],int tamJugador,float promedioSalario,int* contadorJugadoresSuperanPromedio){
	int retorno=0;
	if(tamJugador>0){
		for(int i=0;i<tamJugador;i++){
			if(jugador[i].isEmpty == 1){
				if(jugador[i].salario > promedioSalario){
					*contadorJugadoresSuperanPromedio += 1;
					retorno=1;
				}
			}
		}
	}
	return retorno;
}

int ConfederacionConMasAniosContrato(eJugador jugador[],int tamJugador,int IdConfederacion,short* acumuladorAnios){
	int retorno=0;
	if(tamJugador>0){
		for(int i=0;i<tamJugador;i++){
			if(jugador[i].isEmpty == 1 ){
				if(jugador[i].idConfederacion == IdConfederacion){
					*acumuladorAnios = *acumuladorAnios + jugador[i].aniosContrato;
					retorno=1;
				}
			}
		}
	}
	return retorno;
}

int ContadorConfederacionJugadores(eJugador jugador[],int tamJugador,int idConfederacion,int* contadorJugadoresConfederacion){
	int retorno=0;
	if(tamJugador>0){
		for(int i=0;i<tamJugador;i++){
			if(jugador[i].isEmpty == 1 ){
				if(jugador[i].idConfederacion == idConfederacion){
					*contadorJugadoresConfederacion += 1;
					retorno=1;
				}
			}
		}
	}
	return retorno;
}

float CalcularPorcentaje(int numeroPorcentaje, int contadorTotal){
	float resultado;
	resultado = ((float) numeroPorcentaje * 100) / contadorTotal;
	return resultado;
}

float CalcularPromedio(float acumulador,int contadorTotal){
	float resultado;
	resultado = acumulador / (float) contadorTotal;
	return resultado;
}
