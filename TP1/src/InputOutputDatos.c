/*
 * InputOutputDatos.c
 *
 *  Created on: 31 ago. 2022
 *      Author: leand
 */
#include "InputOutputDatos.h"
#include <ctype.h>

char Confirmar(){
	char letra;
	do{
		printf("¿Quiere seguir [S|N]?");
		fflush(stdin);
		scanf("%c",&letra);
		letra = toupper(letra);
	}while(letra != 'S' && letra != 'N');
	return letra;
}

int NumeroIngresadoEntero(char mensaje[]){
	int numero;
	printf(mensaje);
	scanf("%d",&numero);
	return numero;
}

float NumeroIngresadoFloat(char mensaje[]){
	float numero;
	printf(mensaje);
	scanf("%f",&numero);
	return numero;
}

int NumeroIngresadoPositivoEntero(char mensaje[],char mensajeError[]){
	int numero;
	numero = NumeroIngresadoEntero(mensaje);
	while(numero < 1){
		numero = NumeroIngresadoEntero(mensajeError);
	}
	return numero;
}

float NumeroIngresadoPositivoFloat(char mensaje[],char mensajeError[]){
	float numero;
	numero = NumeroIngresadoFloat(mensaje);
	while(numero < 1){
		numero = NumeroIngresadoFloat(mensajeError);
	}
	return numero;
}

int NumeroIngresadoVerificar(char mensaje[],char mensajeError[],int minimo,int maximo){
	int numero;
	numero = NumeroIngresadoEntero(mensaje);
	while(numero < minimo || numero > maximo){
		numero = NumeroIngresadoEntero(mensajeError);
	}
	return numero;
}


