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

int main(void) {
	setbuf(stdout,NULL);
	int menuOpciones=0;

	do{
		utn_getNumeroINT(&menuOpciones,"1.Alta de Jugador\n"
									   "2.Baja de Jugador\n"
									   "3.Modificacion de Jugador\n"
									   "4.Informes\n"
									   "5.Salir\n"
									   "Ingrese como numero, una de las opcines de arriba.","Error/ Las opcines van del 1 al 5" ,1,5,20);
		switch(menuOpciones){
		case 1:
			printf("\n--------->ALTA DE JUGADOR<---------\n");
			break;
		case 2:
			printf("\n--------->BAJA DE JUGADOR<---------\n");
			break;
		case 3:
			printf("\n--------->MODIFICACION DE JUGADOR<---------\n");
			break;
		case 4:
			printf("\n--------->INFORMES<---------\n");
			break;
		case 5:
			printf("\n--------->SALIR<---------\n");
			break;

		}
	}while(menuOpciones != 5);

	return EXIT_SUCCESS;
}
