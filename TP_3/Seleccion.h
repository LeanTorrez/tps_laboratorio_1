#include "LinkedList.h"

#ifndef selec_H_INCLUDED
#define selec_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	int id;
	char pais[30];
	char confederacion[30];
	int convocados;
	int isEmpty;
}Seleccion;

Seleccion* selec_new();
Seleccion* selec_newParametros(char* idStr,char* paisStr,char* confederacionStr, char* convocadosStr);
void selec_delete(Seleccion* this);

int selec_setId(Seleccion* this,int id);//esta no
int selec_getId(Seleccion* this,int* id);

int selec_setPais(Seleccion* this,char* pais);//esta no
int selec_getPais(Seleccion* this,char* pais);

int selec_setConfederacion(Seleccion* this,char* confederacion);//esta no y deberia de char*
int selec_getConfederacion(Seleccion* this,char* confederacion);//deberia de char*

int selec_setConvocados(Seleccion* this,int convocados);
int selec_getConvocados(Seleccion* this,int* convocados);

int selec_setIsEmpty(Seleccion* this,int isEmpty);//esta no
int selec_getIsEmpty(Seleccion* this,int* isEmpty);




#endif // selec_H_INCLUDED
