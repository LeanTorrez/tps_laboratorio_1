#include "LinkedList.h"

#ifndef jug_H_INCLUDED
#define jug_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

typedef struct
{
	int id;
	char nombreCompleto[100];
	int edad;
	char posicion[30];
	char nacionalidad[30];
	int idSeleccion;
	int isEmpty;
}Jugador;

Jugador* jug_new();
Jugador* jug_newParametros(char* idStr,char* nombreCompletoStr,char* edadStr, char* posicionStr, char* nacionalidadStr, char* idSelccionStr);

void jug_delete(Jugador* this);

int jug_setId(Jugador* this,int id);
int jug_getId(Jugador* this,int* id);

int jug_setNombreCompleto(Jugador* this,char* nombreCompleto);
int jug_getNombreCompleto(Jugador* this,char* nombreCompleto);

int jug_setPosicion(Jugador* this,char* posicion);
int jug_getPosicion(Jugador* this,char* posicion);

int jug_setNacionalidad(Jugador* this,char* nacionalidad);
int jug_getNacionalidad(Jugador* this,char* nacionalidad);

int jug_setEdad(Jugador* this,int edad);
int jug_getEdad(Jugador* this,int* edad);

int jug_setIdSeleccion(Jugador* this,int idSeleccion);
int jug_getSIdSeleccion(Jugador* this,int* idSeleccion);

int jug_setIsEmpty(Jugador* this,int isEmpty);
int jug_getIsEmpty(Jugador* this,int* isEmpty);

/**
 * \fn int jug_IdAutoincremental()
 * \brief Id AutoIncremental autonomo
 *
 * \return retorno la id incremental que se le asignara al jugador, o 0 en caso de error
 */
int jug_IdAutoincremental();

/**
 * \fn int jug_BuscarId(LinkedList*, int, Jugador*)
 * \brief Se entrega la linkedlist y la id del jugador a buscar, se comparan las ids hasta encontrar el jugador
 * , una vez encontrado se devolvera el indice del jugador, en caso de no encontrar la ID se devolvera 0
 *
 * \param this
 * \param idBuscar
 * \param pJugador
 * \return Devuelve 1 en caso exitoso o 0 en caso de error
 */
int jug_BuscarId(LinkedList* this,int idBuscar,int* IndiceEncontrado);

int jug_MenuEditarJugador(Jugador* pJugador);

#endif // jug_H_INCLUDED
