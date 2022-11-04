#include <stdio.h>
#include <stdlib.h>

#include "Jugador.h"
#include "Seleccion.h"
#include "LinkedList.h"
#include "utn.h"
#include "Controller.h"

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

	if(archivoJugadores != NULL && pArrayListJugador != NULL){

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
	int retorno=0;

    return retorno;
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
	int retorno=0;
	Jugador* pJugador;

	int auxId;
	char auxNombre[100];
	int auxEdad;
	char auxPosicion[30];
	char auxNacionalidad[30];

	pJugador = jug_new();

	if(pArrayListJugador != NULL && pJugador != NULL){
		auxId = jug_IdAutoincremental();

		utn_getString(auxNombre,sizeof(auxNombre),"Ingrese el nombre completo del jugador\n","Error/ asegurese de ingresar algo",20);
		utn_getNumeroINT(&auxEdad,"Ingrese la edad del jugador\n","Error/ La edad no puede ser menor a 16 o mayor a 40",16,40,20);
		utn_getString(auxPosicion,sizeof(auxPosicion),"Ingrese la posicion del jugador","Error/ asegures de ingresar algo",20);
		utn_getString(auxNacionalidad, sizeof(auxNacionalidad),"Ingrese la nacionalidad del Jugador\n","Asegurese de ingresar algo",20);

		jug_setId(pJugador, auxId);
		jug_setNombreCompleto(pJugador, auxNombre);
		jug_setEdad(pJugador, auxEdad);
		jug_setPosicion(pJugador, auxPosicion);
		jug_setNacionalidad(pJugador, auxNacionalidad);
		jug_setIdSeleccion(pJugador, 0);
		jug_setIsEmpty(pJugador, 1);

		ll_add(pArrayListJugador,pJugador);

		retorno=1;
	}
	return retorno;
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
	int retorno=0;
	Jugador* pJugador;
	int IdBuscar=-1;
	int IndiceJugador=-1;

	if(pArrayListJugador != NULL){

		controller_listarJugadores(pArrayListJugador);
		                                                                                                                                //maximo numero positivo int -1
		utn_getNumeroINT(&IdBuscar,"Ingrese la ID del jugador que desea modificar\n","Error/ por favor ingrese un numero por encima de 0",1,2147483646,20);

		if(jug_BuscarId(pArrayListJugador,IdBuscar,&IndiceJugador)==1){

			pJugador = ll_get(pArrayListJugador, IndiceJugador);

			if( jug_MenuEditarJugador(pJugador)==1){
				retorno=1;
			}
		}
	}
	return retorno;
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
	int retorno=0;
	Jugador* pJugador;
	int IdBuscar=-1;
	int IndiceJugador=-1;

	if(pArrayListJugador != NULL){

		controller_listarJugadores(pArrayListJugador);
																														//maximo numero positivo int -1
		utn_getNumeroINT(&IdBuscar,"Ingrese la ID del jugador que desea dar de Baja\n","Error/ Por favor ingrese un numero por encima de 0",1,2147483646,20);

		if(jug_BuscarId(pArrayListJugador,IdBuscar,&IndiceJugador)==1){

			pJugador = ll_get(pArrayListJugador, IndiceJugador);

			//Baja tanto en struct Jugador como Linkedlist
			jug_delete(pJugador);
			ll_remove(pArrayListJugador,IndiceJugador);

			retorno=1;
		}
	}
	return retorno;
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
	int retorno=0;
	int i=0;
	Jugador* pJugador;
	FILE* archivoGuardar;

	int auxID;
	char auxNombre[100];
	int auxEdad;
	char auxPosicion[30];
	char auxNacionalidad[30];
	int auxIdSeleccion;

	archivoGuardar = fopen(path,"w");

	if(archivoGuardar != NULL && pArrayListJugador != NULL){
		fprintf(archivoGuardar,"%s\n","id,nombreCompleto,edad,posicion,nacionalidad,idSelecion");
		while(i < ll_len(pArrayListJugador)){

			pJugador = (Jugador*) ll_get(pArrayListJugador, i);
			jug_getId(pJugador,&auxID);
			jug_getNombreCompleto(pJugador, auxNombre);
			jug_getEdad(pJugador, &auxEdad);
			jug_getPosicion(pJugador, auxPosicion);
			jug_getNacionalidad(pJugador, auxNacionalidad);
			jug_getSIdSeleccion(pJugador, &auxIdSeleccion);

			fprintf(archivoGuardar,"%d,%s,%d,%s,%s,%d\n",auxID,auxNombre,auxEdad,auxPosicion,auxNacionalidad,auxIdSeleccion);

			i++;
			retorno=1;
		}
		fclose(archivoGuardar);
	}
	return retorno;
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
	int retorno=0;
	int i=0;
	Jugador* pJugador;
	FILE* archivoGuardarBinario;

	int auxID;
	char auxNombre[100];
	int auxEdad;
	char auxPosicion[30];
	char auxNacionalidad[30];
	int auxIdSeleccion;

	archivoGuardarBinario = fopen(path,"wb");

	if(archivoGuardarBinario != NULL && pArrayListJugador != NULL){
		fprintf(archivoGuardarBinario,"%s\n","id,nombreCompleto,edad,posicion,nacionalidad,idSelecion");
		while(i < ll_len(pArrayListJugador)){

			pJugador = (Jugador*) ll_get(pArrayListJugador, i);
			jug_getId(pJugador,&auxID);
			jug_getNombreCompleto(pJugador, auxNombre);
			jug_getEdad(pJugador, &auxEdad);
			jug_getPosicion(pJugador, auxPosicion);
			jug_getNacionalidad(pJugador, auxNacionalidad);
			jug_getSIdSeleccion(pJugador, &auxIdSeleccion);

			fprintf(archivoGuardarBinario,"%d,%s,%d,%s,%s,%d\n",auxID,auxNombre,auxEdad,auxPosicion,auxNacionalidad,auxIdSeleccion);

			i++;
			retorno=1;
		}
		fclose(archivoGuardarBinario);
	}
	return retorno;
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
	if(archivoSeleccion != NULL && pArrayListSeleccion != NULL){

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

int controller_convocarJugadores(LinkedList* pArrayListJugador,LinkedList* pArrayListSeleccion){
	int retorno=0;
	int idBuscarJugador;
	int indiceJugador;
	Jugador* pJugador = jug_new();
	int jugadorConvocado;

	//Seleccion
	int idBuscarSeleccion;
	int indiceSeleccion;
	Seleccion* pSeleccion = selec_new();
	int seleccionSuperaVeintiDos;

	if(pArrayListJugador != NULL && pArrayListSeleccion != NULL && pJugador != NULL && pSeleccion != NULL){

		controller_listarJugadores(pArrayListJugador);																						//maximo numero positivo int -1
		utn_getNumeroINT(&idBuscarJugador,"Ingrese la ID del jugador que desea convocar\n","Error/ Por favor ingrese un numero por encima de 0",1,2147483646,20);

		if(jug_BuscarId(pArrayListJugador,idBuscarJugador,&indiceJugador)==1){

			pJugador = (Jugador*) ll_get(pArrayListJugador,indiceJugador);
			jug_getSIdSeleccion(pJugador, &jugadorConvocado);
			printf("paso id de la seleccion del jugador %d\n",jugadorConvocado);
			//Verifico que el jugador que se eligio no este convocado a una seleccion
			if(0 == jugadorConvocado){

				controller_listarSelecciones(pArrayListSeleccion);
				utn_getNumeroINT(&idBuscarSeleccion,"Ingrese la ID de la seleccion que desea convocar al jugador\n","Error/ Por favor ingrese el numero de las posibles selecciones(1 al 32)",1,32,20);

				if(selec_BuscarId(pArrayListSeleccion,idBuscarSeleccion,&indiceSeleccion)){

					pSeleccion = (Seleccion*) ll_get(pArrayListSeleccion,indiceSeleccion);
					selec_getConvocados(pSeleccion, &seleccionSuperaVeintiDos);
					if(seleccionSuperaVeintiDos < 22){
						//Le asigno al jugador el pais
						jug_setIdSeleccion(pJugador,idBuscarSeleccion);
						//le sumo el contador a la confederacion;
						selec_setConvocados(pSeleccion, seleccionSuperaVeintiDos + 1);
						retorno=1;
					}else{
						retorno=5;
					}
				}else{
					retorno=4;
				}
			}else{
				retorno=3;
			}
		}else{
			retorno=2;
		}
	}
	return retorno;
}

