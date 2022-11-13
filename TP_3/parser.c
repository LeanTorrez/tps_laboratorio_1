#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Jugador.h"
#include "Seleccion.h"
#include "Controller.h"

/** \brief Parsea los datos de los jugadores desde el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 */
int parser_JugadorFromText(FILE* pFile , LinkedList* pArrayListJugador)
{
	int retorno=0;

	int retornoFSCANF;
	char auxId[10];
	char auxNombreCompleto[100];
	char auxEdad[5];
	char auxPosicion[30];
	char auxNacionalidad[30];
	char auxIdSeleccion[5];
	Jugador* pJugador = NULL;

    if(pFile != NULL){

    	fscanf(pFile,"%s\n",auxNombreCompleto);//falsa lectura

		while( feof(pFile) == 0){
			retornoFSCANF = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",auxId,auxNombreCompleto,auxEdad,auxPosicion,auxNacionalidad,auxIdSeleccion);

			if(retornoFSCANF == 6){

				pJugador = jug_newParametros(auxId,auxNombreCompleto,auxEdad,auxPosicion,auxNacionalidad,auxIdSeleccion);
				ll_add(pArrayListJugador,pJugador);
				retorno=1;
			}

		}
    }
    return retorno;
}

/** \brief Parsea los datos de los jugadores desde el archivo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int parser_JugadorFromBinary(FILE* pFile , LinkedList* pArrayListJugador)
{
	int retorno=0;
	Jugador* pJugador = jug_new();

	Jugador* auxJugador = NULL;

    if(pFile != NULL && pArrayListJugador != NULL && pJugador != NULL ){

    	while(fread(pJugador,sizeof(Jugador),1,pFile) != 0){

    		auxJugador = jug_new();
    		if(auxJugador != NULL){

    			*auxJugador = *pJugador;
    			ll_add(pArrayListJugador,auxJugador);
    			retorno=1;
    		}
    	}
    }
    jug_delete(pJugador);
    return retorno;
}


/** \brief Parsea los datos de los selecciones desde el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int parser_SeleccionFromText(FILE* pFile , LinkedList* pArrayListSeleccion)
{
	int retorno=0;
	char auxId[5];
	char auxPais[30];
	char auxConfederacion[30];
	char auxConvocados[5];
	Seleccion* pSeleccion = NULL;
	int retornoFSCANF;

	if(pFile != NULL && pArrayListSeleccion != NULL){

		fscanf(pFile,"%s\n",auxConfederacion);//Falsa Lectura

		while(feof(pFile)==0){
			retornoFSCANF = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",auxId,auxPais,auxConfederacion,auxConvocados);

			if(retornoFSCANF == 4){

				pSeleccion = selec_newParametros(auxId,auxPais,auxConfederacion,auxConvocados);
				ll_add(pArrayListSeleccion,pSeleccion);
				retorno=1;
			}
		}
	}
	return retorno;
}

