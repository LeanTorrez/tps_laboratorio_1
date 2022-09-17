/*
 ============================================================================
 Name        : TP1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "InputOutputDatos.h"
#include "CalcularX.h"
#define SELECCION 22
//
//CAMBIAR LOS COSTOS A FLOAT Y LA FUNCION QUE TAMBIEN DE FLOAT
//
int main(void) {
	setbuf(stdout,NULL);
	int opcion;
	int opcionesCostos;
	//opcion 1
	float costoHospedaje=250000;
	float costoComida=150000;
	float costoTransporte=100000;
	//opcion 2
	//Contador para las posiciones de los jugadores
	int contadorDelanteros=4;
	int contadorArqueros=2;
	int contadorMediocampistas=8;
	int contadorDefensores=8;
	//Contador Total de los jugadores ingresados hasta ahora
	int contadorJugadores=22;
	//Contador de las federaciones
	int contadorCONMEBOL=2;
	int contadroUEFA=8;
	int contadorOFC=2;
	int contadorCONCACAF=6;
	int contadorCAF=4;
	int contadorAFC=0;
	//Arrays de los datos pedidos
	int camisetaJugador[SELECCION];//El tp no la pide usar en nada.
	int confederacionJugador[SELECCION];
	int posicionJugador[SELECCION];
	//Opcion 3
	float costoMantenimiento=0;
	float aumentoMantenimiento=0;
	float netoMantenimiento;

	float porcentajeCONMEBOL=0;
	float porcentajeUEFA=0;
	float porcentajeOFC=0;
	float porcentajeCONCACAF=0;
	float porcentajeCAF=0;
	float porcentajeAFC=0;



	do{
		printf("\n                 Menu Principal               \n");
		printf("1.Ingreso de los Costos de Mantenimiento\n"
				"  Costo De Hospedaje ---> %.2f\n"
				"  Costo De Comida ------> %.2f\n"
				"  Costo De Transporte --> %.2f\n",
				costoHospedaje,costoComida,costoTransporte);
		printf("2.Carga de Jugadores \n"
				"  Arqueros -------------> %d\n"
				"  Defensores -----------> %d\n"
				"  Mediocampistas -------> %d\n"
				"  Delanteros -----------> %d\n",
				contadorArqueros,contadorDefensores,contadorMediocampistas,contadorDelanteros);
		printf("3.Realizar todos los calculos\n"
				"4.Informar todos los resultados\n"
				"5.Salir\n");
		opcion = NumeroIngresadoEntero("\nIngrese la opcion que quiera ver: ");
		switch(opcion){
		case 1:
			printf("1.Costo de Hospedaje\n2.Costo De Comida\n3.Costo De Transporte\n");
			opcionesCostos = NumeroIngresadoVerificar("Ingrese el numero de la opcion","ERROR/ Reingrese el numero de la opcion (1,2,3)",1,3);
			switch(opcionesCostos){
			case 1:
				costoHospedaje = NumeroIngresadoPositivoFloat("Ingrese el costo de Hospedaje","ERROR/ El costo no puede ser negativo");
				break;

			case 2:
				costoComida = NumeroIngresadoPositivoFloat("Ingrese el costo de Comida","ERROR/ El costo no puede ser negativo");
				break;

			case 3:
				costoTransporte = NumeroIngresadoPositivoFloat("Ingrese el costo de Transporte","ERROR/ El costo no puede ser negativo");
				break;
			}
			break;
		case 2:
			if(contadorJugadores != SELECCION){

				do{
					posicionJugador[contadorJugadores] = NumeroIngresadoVerificar("Ingrese el numero de la posicion\n1.Arquero\n2.Defensor\n3.Mediocampista\n4.Delantero","Error/Vuelva ingresar la el numero de al opcion: ",1,4);

					if((posicionJugador[contadorJugadores] == 1) && (contadorArqueros == 2)){
						printf("\nSe han ingresado la maxima cantidad de Arqueros...Regresando al MENU\n");
						break;
					}else{
						if((posicionJugador[contadorJugadores] == 2) && (contadorDefensores == 8)){
							printf("\nSe han ingresado la maxima cantidad de Defensores...Regresando al MENU\n");
							break;
						}else{
							if((posicionJugador[contadorJugadores] == 3) && (contadorMediocampistas == 8)){
								printf("\nSe han ingresado la maxima cantidad de Mediocampistas...Regresando al MENU\n");
								break;
							}else{
								if((posicionJugador[contadorJugadores] == 4) && (contadorDelanteros == 4)){
									printf("\nSe han ingresado la maxima cantidad de Delanteros...Regresando al MENU\n");
									break;
								}
							}
						}
					}

					camisetaJugador[contadorJugadores] = NumeroIngresadoPositivoEntero("Ingrese el numero de camiseta: ","Error/ Vuelva a ingresar el numero de camiseta: ");
					confederacionJugador[contadorJugadores] = NumeroIngresadoVerificar("Ingrese el numero de la confederacion\n1.CONMEBOL\n2.UEFA\n3.OFC\n4.CONCACAF\n5.CAF\n6.AFC","Error/ Opcion invalida, vuelva a escribir el numero: ",1,6);

					switch(confederacionJugador[contadorJugadores]){
					case 1:
						contadorCONMEBOL++;
						break;
					case 2:
						contadroUEFA++;
						break;
					case 3:
						contadorOFC++;
						break;
					case 4:
						contadorCONCACAF++;
						break;
					case 5:
						contadorCAF++;
						break;
					case 6:
						contadorAFC++;
						break;
					}

					switch(posicionJugador[contadorJugadores]){
					case 1:
						contadorArqueros++;
						break;
					case 2:
						contadorDefensores++;
						break;
					case 3:
						contadorMediocampistas++;
						break;
					case 4:
						contadorDelanteros++;
						break;
					}

					contadorJugadores++;
					if(contadorJugadores == SELECCION){
						break;
					}
				}while((Confirmar())=='S');

			}else{
				printf("Ya se ingresaron todos los jugadores posibles.");
			}

			break;
		case 3:
			if(costoHospedaje == 0 || costoComida == 0 || costoTransporte == 0){
				printf("Para hacer el calculo es necesario rellenar la OPCION 1...");
			}else{
				if(contadorArqueros != 2 && contadorDefensores != 8 && contadorDelanteros != 4 && contadorMediocampistas != 8){
					printf("Para hacer el calculo es necesario rellenar toda la OPCION 2...");
				}
				else{
					//Calculo Mantenimiento
					costoMantenimiento = CalcularSumarFloat(costoComida,costoHospedaje,costoTransporte);
					//Porcentajes confederaciones
					porcentajeCONMEBOL = CalcularPorcentaje(contadorCONMEBOL,contadorJugadores);
					porcentajeUEFA = CalcularPorcentaje(contadroUEFA,contadorJugadores);
					porcentajeOFC = CalcularPorcentaje(contadorOFC,contadorJugadores);
					porcentajeCONCACAF = CalcularPorcentaje(contadorCONCACAF,contadorJugadores);
					porcentajeCAF = CalcularPorcentaje(contadorCAF,contadorJugadores);
					porcentajeAFC = CalcularPorcentaje(contadorAFC,contadorJugadores);

					//En caso de que UEFA tenga la mayor cantidad de jugadores
					if(porcentajeUEFA > porcentajeCONMEBOL && porcentajeUEFA > porcentajeOFC && porcentajeUEFA > porcentajeCONCACAF && porcentajeUEFA > porcentajeCAF && porcentajeUEFA > porcentajeAFC ){
						aumentoMantenimiento = CalcularMultiplicar(costoMantenimiento,0.35);
						netoMantenimiento = CalcularSumarFloat(costoMantenimiento,aumentoMantenimiento,0);
					}
				}
			}
			break;
		case 4:
			if(costoMantenimiento == 0){
				printf("Para mostrar los datos es necesaria la OPCION 3...");
			}else{
				printf("\n                 INFORMAR LOS RESULTADOS               \n"
						"Porcentaje CONMEBOL  %.2f\n"
						"Porcentaje UEFA      %.2f\n"
						"Porcentaje OFC       %.2f\n"
						"Porcentaje CONCACAF  %.2f\n"
						"Porcentaje CAF       %.2f\n"
						"Porcentaje AFC       %.2f\n",
						porcentajeCONMEBOL,porcentajeUEFA,porcentajeOFC,
						porcentajeCONCACAF,porcentajeCAF,porcentajeAFC);

				if(aumentoMantenimiento == 0){
					printf("El costo de mantenimiento de la seleccion es de %.2f",costoMantenimiento);
				}else{
					printf("El costo del mantenimiento era de $%.2f, pero recibio un aumento de $%.2f\nSu nuevo costo es $%.2f\n",costoMantenimiento,aumentoMantenimiento,netoMantenimiento);
				}
			}
			break;
		}
	}while(opcion!=5);
	return EXIT_SUCCESS;
}
