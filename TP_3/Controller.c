#include <stdio.h>
#include <stdlib.h>

#include "Jugador.h"
#include "Seleccion.h"
#include "LinkedList.h"


/** \brief Carga los datos de los jugadores desde el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_cargarJugadoresDesdeTexto(char* path , LinkedList* pArrayListJugador)
{
	int retorno=0;
	FILE* archivoJugadores;
	Jugador* pJugador;
	char auxId[10];
	char auxNombreCompleto[100];
	char auxEdad[5];
	char auxPosicion[30];
	char auxNacionalidad[30];
	char auxIdSeleccion[5];

	int retornoFSCANF;

	archivoJugadores = fopen(path,"r");

	if(archivoJugadores != NULL){

		fscanf(archivoJugadores,"%s\n",auxNombreCompleto);//falsa lectura

		while( feof(archivoJugadores) == 0){
			retornoFSCANF = fscanf(archivoJugadores,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",auxId,auxNombreCompleto,auxEdad,auxPosicion,auxNacionalidad,auxIdSeleccion);

			if(retornoFSCANF == 6){
				//printf("%s,%s,%s,%s,%s,%s\n",auxId,auxNombreCompleto,auxEdad,auxPosicion,auxNacionalidad,auxIdSeleccion);
				pJugador = jug_newParametros(auxId,auxNombreCompleto,auxEdad,auxPosicion,auxNacionalidad,auxIdSeleccion);
				ll_add(pArrayListJugador,pJugador);
				retorno=1;
			}

		}
		fclose(archivoJugadores);
	}
    return retorno;
}

/** \brief Carga los datos de los jugadores desde el archivo generado en modo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_cargarJugadoresDesdeBinario(char* path , LinkedList* pArrayListJugador)
{
    return 1;
}

/** \brief Alta de jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_agregarJugador(LinkedList* pArrayListJugador)
{
    return 1;
}

/** \brief Modificar datos del jugador
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_editarJugador(LinkedList* pArrayListJugador)
{
    return 1;
}

/** \brief Baja del jugador
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_removerJugador(LinkedList* pArrayListJugador)
{
    return 1;
}

/** \brief Listar jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_listarJugadores(LinkedList* pArrayListJugador)
{
    int retorno=0;
    Jugador* pListarJugador;
    int i=0;

    int auxID;
    char auxNombre[100];
    int auxEdad;
    char auxPosicion[30];
    char auxNacionalidad[30];
    int auxIdSeleccion;

    //Jugador* pJugador;
    if(pArrayListJugador != NULL){
    	printf("\n|===========================================================================================================|\n"
    		     "|  ID  | %-30s | Edad | %-20s | %-20s | ID seleccion |\n"
    		     "|===========================================================================================================|\n",
				"Nombre Completo","posicion","Nacionalidad");
    	while(i < ll_len(pArrayListJugador)){
    		pListarJugador = (Jugador*) ll_get(pArrayListJugador,i);

    		if(pListarJugador != NULL){
    			jug_getId(pListarJugador, &auxID);
				jug_getNombreCompleto(pListarJugador, auxNombre);
				jug_getEdad(pListarJugador, &auxEdad);
				jug_getPosicion(pListarJugador, auxPosicion);
				jug_getNacionalidad(pListarJugador, auxNacionalidad);
				jug_getSIdSeleccion(pListarJugador,&auxIdSeleccion);

				printf("| %-4d | %-30s | %-4d | %-20s | %-20s | %-12d |\n",auxID,auxNombre,auxEdad,auxPosicion,auxNacionalidad,auxIdSeleccion);
				retorno=1;
    		}
    		i++;
    	}
    	printf("|===========================================================================================================|\n");
    }
    return retorno;
}

/** \brief Ordenar jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_ordenarJugadores(LinkedList* pArrayListJugador)
{
    return 1;
}

/** \brief Guarda los datos de los jugadores en el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_guardarJugadoresModoTexto(char* path , LinkedList* pArrayListJugador)
{
    return 1;
}

/** \brief Guarda los datos de los jugadores en el archivo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_guardarJugadoresModoBinario(char* path , LinkedList* pArrayListJugador)
{
    return 1;
}



/** \brief Carga los datos de los selecciones desde el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_cargarSeleccionesDesdeTexto(char* path , LinkedList* pArrayListSeleccion)
{
	int retorno=0;
	FILE* archivoSeleccion;
	Seleccion* pSeleccion;
	//auxiliares
	char auxId[5];
	char auxPais[30];
	char auxConfederacion[30];
	char auxConvocados[5];

	int retornoFSCANF;

	archivoSeleccion = fopen(path,"r");
	if(archivoSeleccion != NULL){

		fscanf(archivoSeleccion,"%s\n",auxConfederacion);//Falsa Lectura

		while(feof(archivoSeleccion)==0){
			retornoFSCANF = fscanf(archivoSeleccion,"%[^,],%[^,],%[^,],%[^\n]\n",auxId,auxPais,auxConfederacion,auxConvocados);

			if(retornoFSCANF == 4){

				pSeleccion = selec_newParametros(auxId,auxPais,auxConfederacion,auxConvocados);
				ll_add(pArrayListSeleccion,pSeleccion);
				retorno=1;
			}
		}
		fclose(archivoSeleccion);
	}
    return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_editarSeleccion(LinkedList* pArrayListSeleccion)
{
    return 1;
}


/** \brief Listar selecciones
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_listarSelecciones(LinkedList* pArrayListSeleccion)
{
    int retorno=0;
    int i=0;
    Seleccion* pListarSeleccion;
    int auxId;
    char auxPais[30];
    char auxConfederacion[30];
    int auxConvocados;

    if(pArrayListSeleccion != NULL){
    	printf("\n|================================================================================================|\n"
    			"| %-5s | %-30s | %-30s | %-20s |\n"
    		   "|================================================================================================|\n"
    			,"ID","Pais","Confederacion","Convocados");
    	while(i < ll_len(pArrayListSeleccion)){

    		pListarSeleccion = (Seleccion*) ll_get(pArrayListSeleccion,i);

    		if(pListarSeleccion != NULL){
    			selec_getId(pListarSeleccion, &auxId);
    			selec_getPais(pListarSeleccion, auxPais);
    			selec_getConfederacion(pListarSeleccion, auxConfederacion);
    			selec_getConvocados(pListarSeleccion, &auxConvocados);
    			printf("| %-5d | %-30s | %-30s | %-20d |\n",auxId,auxPais,auxConfederacion,auxConvocados);
    			retorno=1;
    		}
    		i++;
    	}
    	printf("|================================================================================================|\n");
    }
    return retorno;
}

/** \brief Ordenar selecciones
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_ordenarSelecciones(LinkedList* pArrayListSeleccion)
{
    return 1;
}

/** \brief Guarda los datos de los selecciones en el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_guardarSeleccionesModoTexto(char* path , LinkedList* pArrayListSeleccion)
{
    return 1;
}


