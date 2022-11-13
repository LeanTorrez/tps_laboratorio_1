#include "LinkedList.h"

#ifndef selec_H_INCLUDED
#define selec_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

typedef struct
{
	int id;
	char pais[30];
	char confederacion[30];
	int convocados;
}Seleccion;

Seleccion* selec_new();
Seleccion* selec_newParametros(char* idStr,char* paisStr,char* confederacionStr, char* convocadosStr);
void selec_delete(Seleccion* this);

int selec_getId(Seleccion* this,int* id);

int selec_getPais(Seleccion* this,char* pais);

int selec_getConfederacion(Seleccion* this,char* confederacion);

int selec_setConvocados(Seleccion* this,int convocados);
int selec_getConvocados(Seleccion* this,int* convocados);

//---------------------------------------------------------
//Mis funciones

/**
 * \fn int selec_ListarUnaSeleccion(Seleccion*)
 * \brief lista a una seleccion
 *
 * \param this puntero al elemento que contiene Struct Seleccion
 * \return retorno 0 en caso de error, 1 en caso exitoso
 */
int selec_ListarUnaSeleccion(Seleccion* this);

/**
 * \fn int selec_BuscarId(LinkedList*, int, int*)
 * \brief busca la id de la seleccion y devuelve que en indice esta ubicada
 *
 * \param this Linkedlist Seleccion
 * \param idBuscar id de la seleccion a buscar
 * \param indiceEncontrado puntero adonde se guardara el indice de la seleccion
 * \return retorno 0 en caso de error, 1 en caso exitoso
 */
int selec_BuscarId(LinkedList* this,int idBuscar,int* indiceEncontrado);

/**
 * \fn int selec_OrdernarPorConfederacion(void*, void*)
 * \brief ordena las seleccion por confederacion
 *
 * \param seleccionUno puntero primer seleccion
 * \param seleccionDos puntero segunda seleccion
 * \return retorno 0 en caso de error, 1 en caso exitoso
 */
int selec_OrdernarPorConfederacion(void* seleccionUno,void* seleccionDos);

/**
 * \fn int selec_elegirConfederacion(char*)
 * \brief el usuario elije la confederacion que el decida
 *
 * \param pConfederacionElegida puntero al cual se guarda el nombre de la confederacion elegida
 * \return retorno 0 en caso de error, 1 en caso exitoso
 */
int selec_elegirConfederacion(char* pConfederacionElegida);

/**
 * \fn int selec_nombreSeleccion(int, char*)
 * \brief ingresa la id de la seleccion, y devuelve el nombre de la misma
 *
 * \param idSeleccion id de la seleccion
 * \param pNombreSeleccion puntero adonde se guardara dicho nombre
 * \return retorno 0 en caso de error, 1 en caso exitoso
 */
int selec_nombreSeleccion(int idSeleccion,char* pNombreSeleccion);

/**
 * \fn int selec_menuEditarSeleccion(Seleccion*)
 * \brief menu para editar la seleccion especifica
 *
 * \param pSeleccion puntero al elemento de la struct Seleccion
 * \return retorno 0 en caso de error, 1 en caso exitoso
 */
int selec_menuEditarSeleccion(Seleccion* pSeleccion);

#endif // selec_H_INCLUDED
