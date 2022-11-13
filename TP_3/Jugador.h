#include "LinkedList.h"

#ifndef jug_H_INCLUDED
#define jug_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Seleccion.h"

typedef struct
{
	int id;
	char nombreCompleto[100];
	int edad;
	char posicion[30];
	char nacionalidad[30];
	int idSeleccion;
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

//---------------------------------------------------------------------------------------
//Mis funciones

/**
 * \fn int jug_ListarUnJugador(Jugador*)
 * \brief lista a un jugador
 *
 * \param this puntero a un elemento de Jugador
 * \return retorno 0 en caso de error, 1 en caso exitoso
 */
int jug_ListarUnJugador(Jugador* this);

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
 * \param this Linkedlist Jugador
 * \param idBuscar Id del jugador a buscar
 * \param IndiceEncontrado Puntero adonde se guardara el valor del indice que dicho jugador
 * \return retorno 0 en caso de error, 1 en caso exitoso
 */
int jug_BuscarId(LinkedList* this,int idBuscar,int* IndiceEncontrado);

/**
 * \fn int jug_MenuEditarJugador(Jugador*)
 * \brief Menu en el cual el usuario elije que modificar del jugador
 *
 * \param pJugador puntero al elemento de la struct jugador
 * \return retorno 0 en caso de error, 1 en caso exitoso
 */
int jug_MenuEditarJugador(Jugador* pJugador);

/**
 * \fn int jug_OrdenarPorNacionalidad(void*, void*)
 * \brief ordena en base a la nacionalidad
 *
 * \param jugadorUno puntero al primer jugador
 * \param jugadorDos puntero al segundo jugador
 * \return retorno 0 en caso de error, 1 en caso exitoso
 */
int jug_OrdenarPorNacionalidad(void* jugadorUno,void* jugadorDos);

/**
 * \fn int jug_OrdenarPorEdad(void*, void*)
 * \brief ordena en base a la edad
 *
 * \param jugadorUno  puntero al primer jugador
 * \param jugadorDos  puntero al segundo jugador
 * \return retorno 0 en caso de error, 1 en caso exitoso
 */
int jug_OrdenarPorEdad(void* jugadorUno,void* jugadorDos);

/**
 * \fn int jug_OrdenarPorNombre(void*, void*)
 * \brief ordena en base al nombre
 *
 * \param jugadorUno puntero al primer jugador
 * \param jugadorDos puntero al segundo jugador
 * \return retorno 0 en caso de error, 1 en caso exitoso
 */
int jug_OrdenarPorNombre(void* jugadorUno,void* jugadorDos);

#endif // jug_H_INCLUDED
