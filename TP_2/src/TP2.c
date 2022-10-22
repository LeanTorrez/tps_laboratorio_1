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
#include "utn.h"
#include "funcionesEstructuraConfederacion.h"
#include "funcionesEstructuraJugador.h"

#define TAMCONFEDERACION 6
#define TAMJUGADORES 3000

int main(void) {
	setbuf(stdout,NULL);
	int menuOpciones=0;
	int idIncremental=1;
	eJugador jugador[TAMJUGADORES];
	eConfederacion confederacion[]= {{100,"CONMEBOL","SUDAMERICA            ",1916},
									 {101,"UEFA    ","EUROPA                ",1954},
									 {102,"AFC     ","ASIA                  ",1954},
									 {103,"CAF     ","AFRICA                ",1957},
									 {104,"CONCACAF","NORTE Y CENTRO AMERICA",1961},
									 {105,"OFC     ","OCEANIA               ",1966}};
	InicializacionStructJugadores(jugador,TAMJUGADORES);

	do{
		utn_getNumeroINT(&menuOpciones,"\n1.Alta de Jugador\n"
									   "2.Baja de Jugador\n"
									   "3.Modificacion de Jugador\n"
									   "4.Informes\n"
									   "5.Salir\n"
									   "Ingrese como numero, una de las opcines de arriba.","Error/ Las opcines van del 1 al 5" ,1,5,20);
		switch(menuOpciones){
		case 1:
			printf("\n--------->ALTA DE JUGADOR<---------\n");
			AltaStructJugador(jugador,TAMJUGADORES,confederacion,TAMCONFEDERACION,&idIncremental);
			break;
		case 2:
			printf("\n--------->BAJA DE JUGADOR<---------\n");
			if(BuscarStructIndiceLLENO(jugador,TAMJUGADORES)){
				if(BajaStructJugador(jugador,TAMJUGADORES, confederacion,TAMCONFEDERACION)==0){
					printf("No se pudo encontrar al jugador con esa ID... Regresando al Menu");
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
				}
			}else{
				printf("Es Necesario que se ingrese al menos un jugador para entrar en esta opcion\n");
			}
			break;
		case 4:
			printf("\n--------->INFORMES<---------\n");
			if(BuscarStructIndiceLLENO(jugador,TAMJUGADORES)){

			}else{
				printf("Es Necesario que se ingrese al menos un jugador para entrar en esta opcion\n");
			}
			break;
		case 5:
			printf("\n--------->SALIR<---------\n");
			break;

		}
	}while(menuOpciones != 5);

	return EXIT_SUCCESS;
}
