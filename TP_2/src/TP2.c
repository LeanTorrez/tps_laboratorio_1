/*
 ============================================================================
 Name        : TP2.c
 Author      : Leandro Emanuel Torrez 1-K
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
//Todas mis funciones recaen en Mostrar Informes

#include "Informes.h"

#define TAMCONFEDERACION 6
#define TAMJUGADORES 3000

int main(void) {
	setbuf(stdout,NULL);

	int menuOpciones=0;
	int idIncremental=1;

	eJugador jugadores[TAMJUGADORES]={
		       {1,"Emiliano Martinez","ARQUERO",1,100,100000,4,1},
		       {2,"Juan Musso","ARQUERO",12,100,80000,2,1},
		       {3,"Leo Messi","DELANTERO",10,100,80000,4,1},
		       {4,"Almirez Ali","DELANTERO",9,100,55000,1,1},
		       {5,"Harry Maguire","DEFENSOR",2,101,70000,4,1},
		       {6,"Eric Dier","DEFENSOR",3,101,60000,2,1},
		       {7,"Harry Kane","DELANTERO",10,101,3000,2,1},
		       {8,"Alfred Gomis","ARQUERO",1,101,9000,1,1},
		       {9,"Abdelkarim Hassan","MEDIOCAMPISTA",8,101,48000,1,1},
		       {10,"Guillermo Ochoa","ARQUERO",1,104,90000,4,1},
		       {11,"Tecatito","DELANTERO",11,104,100000,3,1},
		       {12,"Luis Romo","MEDIOCAMPISTA",7,104,100000,2,1},
		       {13,"Bamba Dieng ","DELANTERO",9,103,100000,2,1},
		       {14,"Demba Seck","DELANTERO",11,103,6000,2,1},
		       {15,"Tarek Salman","DEFENSOR",6,102,78000,5,1}
		   };


	eConfederacion confederaciones[]= {{100,"CONMEBOL","SUDAMERICA",1916,1},
									 {101,"UEFA    ","EUROPA",1954,1},
									 {102,"AFC     ","ASIA",1954,1},
									 {103,"CAF     ","AFRICA",1957,1},
									 {104,"CONCACAF","NORTE Y CENTRO AMERICA",1961,1},
									 {105,"OFC     ","OCEANIA",1966,1}};


	//jug_inicializacionStruct(jugadores,TAMJUGADORES);

	do{
		utn_getNumeroINT(&menuOpciones,"\n\n1.Alta de Jugador\n"
									   "2.Baja de Jugador\n"
									   "3.Modificacion de Jugador\n"
									   "4.Informes\n"
									   "5.Salir\n"
									   "Ingrese como numero, una de las opciones de arriba.","Error/ Las opcines van del 1 al 5" ,1,5,20);
		switch(menuOpciones){
		case 1:
			printf("\n--------->ALTA DE JUGADOR<---------\n");
			if(jug_alta(jugadores,TAMJUGADORES,confederaciones,TAMCONFEDERACION,&idIncremental)==0){
				printf("Se ingresaron la maxima cantidad de jugadores");
			}else{
				printf("Alta de jugador Exitosa");
			}
			break;
		case 2:
			printf("\n--------->BAJA DE JUGADOR<---------\n");
			if(jug_buscarIndiceLleno(jugadores,TAMJUGADORES)){
				if(jug_baja(jugadores,TAMJUGADORES,confederaciones,TAMCONFEDERACION)==0){
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
			if(jug_buscarIndiceLleno(jugadores,TAMJUGADORES)){
				if(jug_modificacion(jugadores,TAMJUGADORES,confederaciones,TAMCONFEDERACION)==0){
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
			if(jug_buscarIndiceLleno(jugadores,TAMJUGADORES)){
				if(inf_menu(jugadores,TAMJUGADORES,confederaciones,TAMCONFEDERACION)==0){
					printf("Se superaron los maximos reintentos... Regresando al Menu");
				}
			}else{
				printf("Es Necesario que se ingrese al menos un jugador para entrar en esta opcion\n");
			}
			break;
		case 5:
			printf("\n--------->SALIR<---------\n");
			if(ConfirmarChar("¿Desea salir? Ingrese [s|n]","Error/ Ingrese s o n",'S','N')=='N'){
				printf("Eligio regresar al Menu...");
				menuOpciones = 0;
			}else{
				printf("Cerrando Programa.");
			}
			break;

		}

	}while(menuOpciones != 5);

	return EXIT_SUCCESS;
}
