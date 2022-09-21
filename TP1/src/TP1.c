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
#include "CalcularX.h"
#include "UTNinputs.h"
#include <unistd.h> //biblioteca para la funcion sleep();
#define SELECCION 22

int main(void) {
	setbuf(stdout,NULL);
	int opcion;
	int opcionesCostos;
	int retornoFunciones;
	//OPCION 1
	float costoHospedaje=0;
	float costoComida=0;
	float costoTransporte=0;
	//OPCION 2
	//Contador para las posiciones de los jugadores
	int contadorDelanteros=0;
	int contadorArqueros=0;
	int contadorMediocampistas=0;
	int contadorDefensores=0;
	//Contador Total de los jugadores ingresados hasta ahora
	int contadorJugadores=0;
	//Contador de las federaciones
	int contadorCONMEBOL=0;
	int contadroUEFA=0;
	int contadorOFC=0;
	int contadorCONCACAF=0;
	int contadorCAF=0;
	int contadorAFC=0;
	//Los datos pedidos
	int camisetaJugador;
	int confederacionJugador;
	int posicionJugador;
	//OPCION 3
	float costoMantenimiento=0;
	float aumentoMantenimiento=0;
	float netoMantenimiento;

	float promedioCONMEBOL=0;
	float promedioUEFA=0;
	float promedioOFC=0;
	float promedioCONCACAF=0;
	float promedioCAF=0;
	float promedioAFC=0;

	//VARIABLE PARA QUE LAS CAMISETAS DE LOS JUGADORES NO DE WARNING
	int acumuladorCamisetas = 0;
	//

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

		retornoFunciones = utn_getNumeroINT(&opcion,"Ingrese la opcion que quiera ver(1,2,3,4,5)\n","Error/ Ingrese la opcion nuevamente(1,2,3,4,5)\n",0,6,15);
		if(retornoFunciones == -1){
			printf("Se reintento todas las veces posibles... se ingresa Opcion 2 por default.\n");
			opcion = 2;
		}
		switch(opcion){
		case 1:
			printf("             MENU DE COSTOS\n"
					"1.Costo de Hospedaje\n"
					"2.Costo De Comida\n"
					"3.Costo De Transporte\n");

			retornoFunciones = utn_getNumeroINT(&opcionesCostos,"Ingrese la opcion que quiera ver: \n","Error/ Ingrese la opcion nuevamente\n",0,4,15);
			if(retornoFunciones == -1){
				printf("Se reintento todas las veces posibles...Regresando al MENU.\n");
				break;
			}

			switch(opcionesCostos){
			case 1:
				retornoFunciones = utn_getNumeroFLOAT(&costoHospedaje,"Ingrese el costo de Hospedaje\n","ERROR/ El costo no puede ser negativo\n",0,1000000,15);
				if(retornoFunciones == -1){
					printf("Se reintento todas las veces posibles...Regresando al MENU.\n");
					costoHospedaje = 0;
				}
				break;

			case 2:
				retornoFunciones = utn_getNumeroFLOAT(&costoComida,"Ingrese el costo de Comida\n","ERROR/ El costo no puede ser negativo\n",0,1000000,15);
				if(retornoFunciones == -1){
					printf("Se reintento todas las veces posibles...Regresando al MENU.\n");
					costoComida = 0;
				}
				break;

			case 3:
				retornoFunciones = utn_getNumeroFLOAT(&costoTransporte,"Ingrese el costo de Transporte\n","ERROR/ El costo no puede ser negativo\n",0,1000000,15);
				if(retornoFunciones == -1){
					printf("Se reintento todas las veces posibles...Regresando al MENU.\n");
					costoTransporte = 0;
				}

				break;
			}
			break;
		case 2:
			printf("            INGRESO DE JUGADORES\n");
			if(contadorJugadores != SELECCION){

				do{

					do{
						retornoFunciones = utn_getNumeroINT(&posicionJugador,"Ingrese el numero de la posicion(1,2,3,4)\n1.Arquero\n2.Defensor\n3.Mediocampista\n4.Delantero\n","Error/Vuelva ingresar la el numero la posicion (1,2,3,4) \n",0,5,15);
					}while(retornoFunciones == -1);

					if((posicionJugador == 1) && (contadorArqueros == 2)){
						printf("Se han ingresado la maxima cantidad de Arqueros...Regresando al MENU\n");
						break;
					}else{
						if((posicionJugador == 2) && (contadorDefensores == 8)){
							printf("Se han ingresado la maxima cantidad de Defensores...Regresando al MENU\n");
							break;
						}else{
							if((posicionJugador == 3) && (contadorMediocampistas == 8)){
								printf("Se han ingresado la maxima cantidad de Mediocampistas...Regresando al MENU\n");
								break;
							}else{
								if((posicionJugador == 4) && (contadorDelanteros == 4)){
									printf("Se han ingresado la maxima cantidad de Delanteros...Regresando al MENU\n");
									break;
								}
							}
						}
					}

					do{
						retornoFunciones = utn_getNumeroINT(&camisetaJugador,"Ingrese el numero de camiseta\n","Error/ Opcion invalida, la misma no puede ser menor a 1 o mayor 100\n",0,101,15);
					}while(retornoFunciones == -1);

					do{
						retornoFunciones = utn_getNumeroINT(&confederacionJugador,"Ingrese el numero de la confederacion(1,2,3,4,5,6)\n1.CONMEBOL\n2.UEFA\n3.OFC\n4.CONCACAF\n5.CAF\n6.AFC\n","Error/ Opcion invalida, vuelva a escribir el numero(1,2,3,4,5,6)\n",0,7,15);
					}while(retornoFunciones == -1);

					switch(confederacionJugador){
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

					switch(posicionJugador){
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

					//ESTO ES SOLO PARA QUE LA VARIABLE DE CAMISETAS NO DE WARNING DE NO USO
					acumuladorCamisetas += camisetaJugador;
					//

					contadorJugadores++;
					if(contadorJugadores == SELECCION){
						break;
					}
				}while(ConfirmarChar("¿Quiere seguir ingresando jugadores? [S/N]\n","Por favor ingrese solamente S o N (No son necesarias las mayusculas)\n",'S','N')=='S');

			}else{
				printf("Ya se ingresaron todos los jugadores posibles.\n");
			}

			break;
		case 3:
			if(costoHospedaje == 0 || costoComida == 0 || costoTransporte == 0){
				printf("Para hacer el calculo es necesario rellenar toda la OPCION 1...\n");
			}else{
				if(contadorJugadores == 0){
					printf("Para hacer el calculo es necesario ingresar a por lo menos 1 jugador de la OPCION 2...\n");
				}
				else{
					printf("              CALCULANDO DATOS\n");
					//Calculo Mantenimiento
					costoMantenimiento = CalcularSumarFloat(costoComida,costoHospedaje,costoTransporte);
					//Porcentajes confederaciones
					promedioCONMEBOL = CalcularPromedio(contadorCONMEBOL,contadorJugadores);
					promedioUEFA = CalcularPromedio(contadroUEFA,contadorJugadores);
					promedioOFC = CalcularPromedio(contadorOFC,contadorJugadores);
					promedioCONCACAF = CalcularPromedio(contadorCONCACAF,contadorJugadores);
					promedioCAF = CalcularPromedio(contadorCAF,contadorJugadores);
					promedioAFC = CalcularPromedio(contadorAFC,contadorJugadores);
					//En caso de que UEFA tenga la mayor cantidad de jugadores
					if(contadroUEFA > contadorCONMEBOL  && contadroUEFA  > contadorOFC   && contadroUEFA > contadorCONCACAF && contadroUEFA  > contadorCAF  && contadroUEFA > contadorAFC ){
						aumentoMantenimiento = CalcularMultiplicar(costoMantenimiento,0.35);
						netoMantenimiento = CalcularSumarFloat(costoMantenimiento,aumentoMantenimiento,0);
					}
				}
			}
			break;
		case 4:
			if(costoMantenimiento == 0){
				printf("Para mostrar los datos es necesaria la OPCION 3...\n");
			}else{
				printf("\n                 INFORMAR LOS RESULTADOS               \n"
						"Promedio  CONMEBOL  %.2f\n"
						"Promedio  UEFA      %.2f\n"
						"Promedio  OFC       %.2f\n"
						"Promedio  CONCACAF  %.2f\n"
						"Promedio  CAF       %.2f\n"
						"Promedio  AFC       %.2f\n",
						promedioCONMEBOL,promedioUEFA,promedioOFC,
						promedioCONCACAF,promedioCAF,promedioAFC);

				if(aumentoMantenimiento == 0){
					printf("El costo de mantenimiento de la seleccion es de %.2f\n",costoMantenimiento);
				}else{
					printf("El costo del mantenimiento era de $%.2f, pero recibio un aumento de $%.2f\n"
							"Su nuevo costo es $%.2f\n",
							costoMantenimiento,aumentoMantenimiento,netoMantenimiento);
				}
			}
			break;
		case 5:
			printf("TERMINANDO PROGRAMA");
		}

		//Espera 3 segundos
		sleep(3);
		//Esta funcion proviene de la biblioteca <unistd.h> y la funcion sleep(); pone un timer
		//que especificas entre los parentesis en segundos.

	}while(opcion!=5);

	//ESTO ES SOLO PARA QUE LA VARIABLE DE CAMISETAS NO DE WARNING DE NO USO
	printf("\n%d",acumuladorCamisetas);

	return EXIT_SUCCESS;
}
