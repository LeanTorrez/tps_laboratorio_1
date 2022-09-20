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
#include "UTNinputs.h"
#include <windows.h> //Esta funcion es para darle tiempo para que el usuario pueda leer.
#define SELECCION 22
//
//CAMBIAR LOS COSTOS A FLOAT Y LA FUNCION QUE TAMBIEN DE FLOAT
//
int main(void) {
	setbuf(stdout,NULL);
	int opcion;
	int opcionesCostos;
	int retornoFunciones;
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
	//Los datos pedidos
	//int camisetaJugador;//El tp no la pide usar en nada.
	int confederacionJugador;
	int posicionJugador;
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

	//hola cambio

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

		//opcion = NumeroIngresadoEntero("\nIngrese la opcion que quiera ver: \n");
		retornoFunciones = utn_getNumeroINT(&opcion,"Ingrese la opcion que quiera ver: \n","Error/ Ingrese la opcion nuevamente\n",0,6,15);
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
				utn_getNumeroFLOAT(&costoHospedaje,"Ingrese el costo de Hospedaje\n","ERROR/ El costo no puede ser negativo\n",0,1000000,15);
				//costoHospedaje = NumeroIngresadoPositivoFloat("Ingrese el costo de Hospedaje","ERROR/ El costo no puede ser negativo\n");
				break;

			case 2:
				utn_getNumeroFLOAT(&costoComida,"Ingrese el costo de Comida\n","ERROR/ El costo no puede ser negativo\n",0,1000000,15);
				//costoComida = NumeroIngresadoPositivoFloat("Ingrese el costo de Comida","ERROR/ El costo no puede ser negativo\n");
				break;

			case 3:
				utn_getNumeroFLOAT(&costoTransporte,"Ingrese el costo de Transporte\n","ERROR/ El costo no puede ser negativo\n",0,1000000,15);
				//costoTransporte = NumeroIngresadoPositivoFloat("Ingrese el costo de Transporte","ERROR/ El costo no puede ser negativo\n");
				break;
			}
			break;
		case 2:
			printf("            INGRESO DE JUGADORES\n");
			if(contadorJugadores != SELECCION){

				do{

					utn_getNumeroINT(&posicionJugador,"Ingrese el numero de la posicion\n1.Arquero\n2.Defensor\n3.Mediocampista\n4.Delantero\n","Error/Vuelva ingresar la el numero de al opcion: \n",0,5,15);
					posicionJugador = NumeroIngresadoVerificar("Ingrese el numero de la posicion\n1.Arquero\n2.Defensor\n3.Mediocampista\n4.Delantero","Error/Vuelva ingresar la el numero de al opcion: ",1,4);

					if((posicionJugador == 1) && (contadorArqueros == 2)){
						printf("\nSe han ingresado la maxima cantidad de Arqueros...Regresando al MENU\n");
						break;
					}else{
						if((posicionJugador == 2) && (contadorDefensores == 8)){
							printf("\nSe han ingresado la maxima cantidad de Defensores...Regresando al MENU\n");
							break;
						}else{
							if((posicionJugador == 3) && (contadorMediocampistas == 8)){
								printf("\nSe han ingresado la maxima cantidad de Mediocampistas...Regresando al MENU\n");
								break;
							}else{
								if((posicionJugador == 4) && (contadorDelanteros == 4)){
									printf("\nSe han ingresado la maxima cantidad de Delanteros...Regresando al MENU\n");
									break;
								}
							}
						}
					}
					//utn_getNumeroINT(&camisetaJugador,"Ingrese el numero de la confederacion\n1.CONMEBOL\n2.UEFA\n3.OFC\n4.CONCACAF\n5.CAF\n6.AFC\n","Error/ Opcion invalida, vuelva a escribir el numero:\n",0,101,15);
					//camisetaJugador = NumeroIngresadoPositivoEntero("Ingrese el numero de camiseta: ","Error/ Vuelva a ingresar el numero de camiseta: ");
					utn_getNumeroINT(&confederacionJugador,"Ingrese el numero de la confederacion\n1.CONMEBOL\n2.UEFA\n3.OFC\n4.CONCACAF\n5.CAF\n6.AFC\n","Error/ Opcion invalida, vuelva a escribir el numero: \n",0,7,15);
					confederacionJugador = NumeroIngresadoVerificar("Ingrese el numero de la confederacion\n1.CONMEBOL\n2.UEFA\n3.OFC\n4.CONCACAF\n5.CAF\n6.AFC","Error/ Opcion invalida, vuelva a escribir el numero: ",1,6);

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
			if(costoHospedaje == 0 && costoComida == 0 && costoTransporte == 0){
				printf("Para hacer el calculo es necesario rellenar algo de la OPCION 1...\n");
			}else{
				if(contadorArqueros == 0 && contadorDefensores == 0 && contadorDelanteros == 0 && contadorMediocampistas == 0){
					printf("Para hacer el calculo es necesario ingresar a por lo menos 1 jugador de la OPCION 2...\n");
				}
				else{
					printf("              CALCULANDO DATOS\n");
					//Calculo Mantenimiento
					costoMantenimiento = CalcularSumarFloat(costoComida,costoHospedaje,costoTransporte);
					//Porcentajes confederaciones
					porcentajeCONMEBOL = CalcularPromedio(contadorCONMEBOL,contadorJugadores);
					porcentajeUEFA = CalcularPromedio(contadroUEFA,contadorJugadores);
					porcentajeOFC = CalcularPromedio(contadorOFC,contadorJugadores);
					porcentajeCONCACAF = CalcularPromedio(contadorCONCACAF,contadorJugadores);
					porcentajeCAF = CalcularPromedio(contadorCAF,contadorJugadores);
					porcentajeAFC = CalcularPromedio(contadorAFC,contadorJugadores);
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
				printf("Para mostrar los datos es necesaria la OPCION 3...\n");
			}else{
				printf("\n                 INFORMAR LOS RESULTADOS               \n"
						"Promedio  CONMEBOL  %.2f\n"
						"Promedio  UEFA      %.2f\n"
						"Promedio  OFC       %.2f\n"
						"Promedio  CONCACAF  %.2f\n"
						"Promedio  CAF       %.2f\n"
						"Promedio  AFC       %.2f\n",
						porcentajeCONMEBOL,porcentajeUEFA,porcentajeOFC,
						porcentajeCONCACAF,porcentajeCAF,porcentajeAFC);

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
		//Espera 5 segundos
		sleep(4);
		//Esta funcion proviene de la biblioteca <windows.h> y la funcion sleep(); pone un timer
		//que especificas entre los parentesis, es en segundos

	}while(opcion!=5);
	return EXIT_SUCCESS;
}
