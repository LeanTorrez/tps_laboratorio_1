/*
 ============================================================================
 Name        : TP2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
//Todas mis funciones recaen en Mostrar Informes
#include "MostrarInformes.h"

#define TAMCONFEDERACION 6
#define TAMJUGADORES 3000

int main(void) {
	setbuf(stdout,NULL);

	int menuOpciones=0;
	int idIncremental=1;

	//eJugador jugador[TAMJUGADORES];
	eJugador jugador[TAMJUGADORES] = {{1,"Leonel Messi","Delantero",10,105,5000,5,1},
									  {2,"Cristiano Ronaldo","Delantero",7,101,6054,3,1},
									  {3,"Emiliano Martinez","Arquero",1,102,2312,2,1},
									  {4,"Lautaro Martinez","Delantero",17,100,4123,15,1},
									  {5,"Luis Suarez","Delantero",11,105,51531,3,1},
									  {6,"Gianluigi Donnaruma","Arquero",1,101,12212,4,1},
									  {7,"Kiliam Mbappe","Delantero",7,101,55454,2,1},
									  {8,"Memo Ochoa","Arquero",1,104,7652,6,1},
									  {9,"Leandro Paredes","Mediocampista",14,100,12341,1,1},
									  {10,"Marcos Rojo","Defensor",5,101,5135,11,1},
									  {11,"Cuti Romero","Defensor",3,103,87565,10,1}};

	eConfederacion confederacion[]= {{100,"CONMEBOL","SUDAMERICA",1916,1},
									 {101,"UEFA","EUROPA",1954,1},
									 {102,"AFC","ASIA",1954,1},
									 {103,"CAF","AFRICA",1957,1},
									 {104,"CONCACAF","NORTE Y CENTRO AMERICA",1961,1},
									 {105,"OFC","OCEANIA",1966,1}};
	//InicializacionStructJugadores(jugador,TAMJUGADORES);

	do{
		utn_getNumeroINT(&menuOpciones,"\n\n1.Alta de Jugador\n"
									   "2.Baja de Jugador\n"
									   "3.Modificacion de Jugador\n"
									   "4.Informes\n"
									   "5.Salir\n"
									   "Ingrese como numero, una de las opcines de arriba.","Error/ Las opcines van del 1 al 5" ,1,5,20);
		switch(menuOpciones){
		case 1:
			printf("\n--------->ALTA DE JUGADOR<---------\n");
			if(AltaStructJugador(jugador,TAMJUGADORES,confederacion,TAMCONFEDERACION,&idIncremental)==0){
				printf("Se ingresaron la maxima cantidad de jugadores");
			}else{
				printf("Alta de jugador Exitosa");
			}
			break;
		case 2:
			printf("\n--------->BAJA DE JUGADOR<---------\n");
			if(BuscarStructIndiceLLENO(jugador,TAMJUGADORES)){
				if(BajaStructJugador(jugador,TAMJUGADORES, confederacion,TAMCONFEDERACION)==0){
					printf("No se pudo encontrar al jugador con esa ID... Regresando al Menu");
				}else{
					printf("Baja de jugador Exitosa");
				}
			}else{
				printf("Es Necesario que se ingrese al menos un jugador para entrar en esta opcion\n");
			}
			break;
		case 3:
			printf("\n--------->MODIFICACION DE JUGADOR<---------\n");
			if(BuscarStructIndiceLLENO(jugador,TAMJUGADORES)){
				if(ModificacionStructJugador(jugador,TAMJUGADORES, confederacion,TAMCONFEDERACION)==0){
					printf("No se pudo encontrar al jugador con esa ID... Regresando al Menu");
				}else{
					printf("Modificacion de jugador Exitosa");
				}
			}else{
				printf("Es Necesario que se ingrese al menos un jugador para entrar en esta opcion\n");
			}
			break;
		case 4:
			printf("\n--------->INFORMES<---------\n");
			if(BuscarStructIndiceLLENO(jugador,TAMJUGADORES)){
				MostrarInformes(jugador,TAMJUGADORES, confederacion,TAMCONFEDERACION);

			}else{
				printf("Es Necesario que se ingrese al menos un jugador para entrar en esta opcion\n");
			}
			break;
		case 5:
			printf("\n--------->SALIR<---------\n");
			if(ConfirmarChar("¿Desea salir? Ingrese [s|n]","Error/ Ingrese s o n",'S','N')=='N'){
				printf("Eligio regresar al Menu...");
				menuOpciones = 0;
			}
			break;

		}
	}while(menuOpciones != 5);

	return EXIT_SUCCESS;
}
