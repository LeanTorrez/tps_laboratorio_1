#include <stdio.h>
#include <stdlib.h>

#include "Jugador.h"
#include "Seleccion.h"
#include "LinkedList.h"
#include "utn.h"
#include "Controller.h"
#include "parser.h"

/** \brief Carga los datos de los jugadores desde el archivo jugadores.csv (modo texto).
 *
 * \param path nombre del archivo al cual se leera los datos
 * \param pArray ListJugador LinkedList*
 * \return retorno 0 en caso de error, 1 en caso exitoso
 */
int controller_cargarJugadoresDesdeTexto(char* path , LinkedList* pArrayListJugador)
{
	int retorno=0;
	FILE* archivoJugadores;

	archivoJugadores = fopen(path,"r");

	if(parser_JugadorFromText(archivoJugadores,pArrayListJugador)==1){

		fclose(archivoJugadores);
		retorno=1;
	}
    return retorno;
}

/** \brief Carga los datos de los jugadores desde el archivo generado en modo binario.
 *
 * \param path nombre del archivo al cual se leera los datos
 * \param pArray ListJugador LinkedList*
 * \return retorno 0 en caso de error, 1 en caso exitoso
 *
 */
int controller_cargarJugadoresDesdeBinario(char* path , LinkedList* pArrayListJugador)
{
	int retorno=0;
	FILE* archivoJugadoresBinario;

	archivoJugadoresBinario = fopen(path,"rb");

	if(parser_JugadorFromBinary(archivoJugadoresBinario,pArrayListJugador)==1){
		fclose(archivoJugadoresBinario);
		retorno=1;
	}
    return retorno;
}

/** \brief Alta de jugadores
 *
 * \param pArrayListJugador LinkedList*
 * \return retorno 0 en caso de error, 1 en caso exitoso
 *
 */
int controller_agregarJugador(LinkedList* pArrayListJugador)
{
	int retorno=0;
	Jugador* pJugador = jug_new();;

	int auxId;
	char auxNombre[100];
	int auxEdad;
	char auxPosicion[30];
	char auxNacionalidad[30];

	if(pArrayListJugador != NULL && pJugador != NULL){
		auxId = jug_IdAutoincremental();

		//utn_getDescripcion(auxNacionalidad, sizeof(auxNacionalidad),"Ingrese la nacionalidad del Jugador\n","Asegurese de ingresar algo\n",20) == 0

		if(utn_getDescripcion(auxNombre,sizeof(auxNombre),"Ingrese el nombre completo del jugador\n","Error/ asegurese de ingresar algo\n",1)==0 &&
		   utn_getNumeroINT(&auxEdad,"Ingrese la edad del jugador\n","Error/ La edad no puede ser menor a 16 o mayor a 40\n",16,40,20) == 1 &&
		   jug_elegirPosicion(auxPosicion)==1 &&
		   jug_elegirNacionalidad(auxNacionalidad)==1)
		{
			if(jug_setId(pJugador, auxId) == 1 &&
			   jug_setNombreCompleto(pJugador, auxNombre) == 1 &&
			   jug_setEdad(pJugador, auxEdad) == 1 &&
			   jug_setPosicion(pJugador, auxPosicion) == 1 &&
			   jug_setNacionalidad(pJugador, auxNacionalidad) == 1 &&
			   jug_setIdSeleccion(pJugador, 0) == 1)
			{
				ll_add(pArrayListJugador,pJugador);
				retorno=1;
			}
		}
	}
	return retorno;
}

/** \brief Modificar datos del jugador
 *
 * \param pArray ListJugador LinkedList*
 * \return retorno 0 en caso de error, 1 en caso exitoso
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

		if(utn_getNumeroINT(&IdBuscar,"Ingrese la ID del jugador que desea modificar\n",
		   "Error/ por favor ingrese un numero por encima de 0",1,2147483646,20)==1 &&
		  jug_BuscarId(pArrayListJugador,IdBuscar,&IndiceJugador)==1)
		{
			pJugador = ll_get(pArrayListJugador, IndiceJugador);

			if( jug_MenuEditarJugador(pJugador)==1){
				retorno=1;
			}
		}
	}
	return retorno;
}

/**
 * \brief Baja de jugador
 *
 * \param pArrayListJugador LinkedList* de jugador
 * \param pArrayListSeleccion LinkedList* de seleccion, necesaria para en caso de remover un jugador convocado
 * \return retorno 0 en caso de error, 1 en caso exitoso
 */
int controller_removerJugador(LinkedList* pArrayListJugador,LinkedList* pArrayListSeleccion)
{
	int retorno=0;
	Jugador* pJugador;
	Seleccion* pSeleccion;
	int IdBuscar=-1;
	int IndiceJugador=-1;

	int seleccionJugador=-1;
	int indiceSeleccion;
	int convocado;
	if(pArrayListJugador != NULL){

		controller_listarJugadores(pArrayListJugador);

		if(utn_getNumeroINT(&IdBuscar,"Ingrese la ID del jugador que desea dar de Baja\n"
				,"Error/ Por favor ingrese un numero por encima de 0",1,2147483646,20)==1 &&
		   jug_BuscarId(pArrayListJugador,IdBuscar,&IndiceJugador)==1)
		{

			pJugador = ll_get(pArrayListJugador, IndiceJugador);

			if(jug_getSIdSeleccion(pJugador, &seleccionJugador)==1 &&
			   seleccionJugador > 0)
			{

				//En caso de que el jugador que estoy dando de baja este en alguna seleccion
				if(selec_BuscarId(pArrayListSeleccion, seleccionJugador, &indiceSeleccion)==1){

					//Obtengo a la seleccion en cuestion y le bajo el contador en 1
					pSeleccion = (Seleccion*) ll_get(pArrayListSeleccion, indiceSeleccion);
					selec_getConvocados(pSeleccion,&convocado);
					selec_setConvocados(pSeleccion, convocado -1);

				}
			}

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
 * \param pArray ListJugador LinkedList*
 * \return retorno 0 en caso de error, 1 en caso exitoso
 *
 */
int controller_listarJugadores(LinkedList* pArrayListJugador)
{
    int retorno=0;
    Jugador* pListarJugador = jug_new();
    int i=0;

    //Jugador* pJugador;
    if(pArrayListJugador != NULL && pListarJugador != NULL){
    	printf("\n|===================================================================================================================|\n"
    		     "|  ID  | %-30s | Edad | %-20s | %-20s | %-20s |\n"
    		     "|===================================================================================================================|\n",
				"Nombre Completo","posicion","Nacionalidad","Seleccion");
    	while(i < ll_len(pArrayListJugador)){
    		pListarJugador = (Jugador*) ll_get(pArrayListJugador,i);

    		jug_ListarUnJugador(pListarJugador);

    		i++;
    	}
    	printf("|===================================================================================================================|\n");
    }
    return retorno;
}

/**
 * \fn int controller_ordenarJugadores(LinkedList*)
 * \brief Menu de opciones en el cual el usuario puede elegir los distintos metodos de ordenamiento
 *
 * \param pArray ListJugador LinkedList*
 * \return retorno 0 en caso de error, 1 en caso exitoso
 */
int controller_ordenarJugadores(LinkedList* pArrayListJugador)
{
	int retorno=0;
    int opciones=0;
    int ordenamiento=1;

	if(utn_getNumeroINT(&opciones,"1.Ordenar Jugadores Por Nacionalidad\n"
							   "2.Ordenar Jugadores Por Edad\n"
							   "3.Ordenar Jugadores Por Nombre\n"
							   "Escriba el numero de la opcion que desea acceder\n","Error/ Ingrese un numero dentro de las opciones (1  al 3)",1,3,20) == 1)
	{

		switch(opciones){
			case 1:
				ll_sort(pArrayListJugador,jug_OrdenarPorNacionalidad,ordenamiento);
				retorno=1;
				break;
			case 2:
				ll_sort(pArrayListJugador,jug_OrdenarPorEdad,ordenamiento);
				retorno=1;
				break;
			case 3:
				ll_sort(pArrayListJugador,jug_OrdenarPorNombre,ordenamiento);
				retorno=1;
				break;
		}
		controller_listarJugadores(pArrayListJugador);
	}
	return retorno;
}

/** \brief Guarda los datos de los jugadores en el archivo jugadores.csv (modo texto).
 *
 * \param path nombre del archivo al cual se leera los datos
 * \param pArray ListSeleccion LinkedList*
 * \return retorno 0 en caso de error, 1 en caso exitoso
 */
int controller_guardarJugadoresModoTexto(char* path , LinkedList* pArrayListJugador)
{
	int retorno=0;
	int i=0;
	Jugador* pJugador = NULL;
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
 * \param path nombre del archivo al cual se leera los datos
 * \param pArray ListJugador LinkedList*
 * \return retorno 0 en caso de error, 1 en caso exitoso
 */
int controller_guardarJugadoresModoBinario(char* path , LinkedList* pArrayListJugador,LinkedList* pArrayListSeleccion)
{
	int retorno=0;
	int i=0;
	Jugador* pJugador = NULL;
	Seleccion* pSeleccion = NULL;
	FILE* archivoGuardarBinario;

	char auxNombreConfederacion[30];
	int idSeleccion;

	int indiceSeleccion;
	char nombreConfederacion[30];

	archivoGuardarBinario = fopen(path,"wb");

	if(archivoGuardarBinario != NULL && pArrayListJugador != NULL && pArrayListSeleccion){

		if(selec_elegirConfederacion(auxNombreConfederacion)==1){

			while(i < ll_len(pArrayListJugador)){

				pJugador = (Jugador*) ll_get(pArrayListJugador, i);
				jug_getSIdSeleccion(pJugador,&idSeleccion);

				if(idSeleccion > 0){

					if(selec_BuscarId(pArrayListSeleccion,idSeleccion,&indiceSeleccion)==1){

						pSeleccion = (Seleccion*) ll_get(pArrayListSeleccion, indiceSeleccion);
						selec_getConfederacion(pSeleccion,nombreConfederacion);

						if(stricmp(nombreConfederacion,auxNombreConfederacion)==0){

							fwrite(pJugador,sizeof(Jugador),1,archivoGuardarBinario);
							retorno=1;
						}
					}
				}
				i++;
			}
		}
		fclose(archivoGuardarBinario);
	}
	return retorno;
}



/** \brief Carga los datos de los selecciones desde el archivo selecciones.csv (modo texto).
 *
 * \param path nombre del archivo al cual se leera los datos
 * \param pArray ListSeleccion LinkedList*
 * \return retorno 0 en caso de error, 1 en caso exitoso
 *
 */
int controller_cargarSeleccionesDesdeTexto(char* path , LinkedList* pArrayListSeleccion)
{
	int retorno=0;
	FILE* archivoSeleccion;
	archivoSeleccion = fopen(path,"r");

	if(parser_SeleccionFromText(archivoSeleccion, pArrayListSeleccion)){
		retorno=1;
		fclose(archivoSeleccion);
	}
    return retorno;
}

/** \brief Modificar datos de Seleccion
 *
 * \param pArray ListSeleccion LinkedList*
 * \return retorna 0 en caso de error , 1 en caso de exito
 */
int controller_editarSeleccion(LinkedList* pArrayListSeleccion)
{

    int retorno=0;
	Seleccion* pSeleccion;
	int idBuscar = -1;
	int indiceSeleccion=-1;

	if(pArrayListSeleccion != NULL){

		controller_listarSelecciones(pArrayListSeleccion);

		if(utn_getNumeroINT(&idBuscar,"Ingrese la ID de la seleccion\n",
		   "Error/ Por ingrese la id de la seleccion van de 1 al 32",1,32,20)==1 &&
		   selec_BuscarId(pArrayListSeleccion,idBuscar,&indiceSeleccion)==1)
		{

			pSeleccion = ll_get(pArrayListSeleccion, indiceSeleccion);

			if( selec_menuEditarSeleccion(pSeleccion)==1){
				retorno=1;
			}
		}
	}

    return retorno;
}


/** \brief Listar selecciones
 *
 * \param path nombre del archivo al cual se leera los datos
 * \param pArray ListSeleccion LinkedList*
 * \return retorna 0 en caso de error , 1 en caso de exito
 *
 */
int controller_listarSelecciones(LinkedList* pArrayListSeleccion)
{
    int retorno=0;
    int i=0;
    Seleccion* pListarSeleccion = selec_new();

    if(pArrayListSeleccion != NULL && pListarSeleccion != NULL){
    	printf("\n|================================================================================================|\n"
    			"| %-5s | %-30s | %-30s | %-20s |\n"
    		   "|================================================================================================|\n"
    			,"ID","Pais","Confederacion","Convocados");
    	while(i < ll_len(pArrayListSeleccion)){

    		pListarSeleccion = (Seleccion*) ll_get(pArrayListSeleccion,i);

    		selec_ListarUnaSeleccion(pListarSeleccion);
    		i++;
    	}
    	printf("|================================================================================================|\n");
    }
    return retorno;
}

/** \brief Ordenar selecciones
 *
 * \param pArray ListSeleccion LinkedList*
 * \return retorna 0 en caso de error , 1 en caso de exito
 */
int controller_ordenarSelecciones(LinkedList* pArrayListSeleccion)
{
	int retorno=0;
	int ordenamiento =1;

	if(pArrayListSeleccion != NULL){

		ll_sort(pArrayListSeleccion,selec_OrdernarPorConfederacion,ordenamiento);

		controller_listarSelecciones(pArrayListSeleccion);
	}
	return retorno;
}

/** \brief Guarda los datos de los selecciones en el archivo selecciones.csv (modo texto).
 *
 * \param path nombre del archivo al cual se guardara los datos
 * \param pArray ListSeleccion LinkedList*
 * \return retorna 0 en caso de error , 1 en caso de exito
 *
 */
int controller_guardarSeleccionesModoTexto(char* path , LinkedList* pArrayListSeleccion)
{
	int retorno=0;
	int i=0;
	Seleccion* pSeleccion = NULL;
	FILE* archivoGuardar;

	int auxID;
	char auxPais[30];
	char auxConfederacion[30];
	int auxConvocados;

	archivoGuardar = fopen(path,"w");

	if(archivoGuardar != NULL && pArrayListSeleccion != NULL){

		fprintf(archivoGuardar,"%s\n","id,pais,confederacion,convocados");

		while(i < ll_len(pArrayListSeleccion)){

			pSeleccion = (Seleccion*) ll_get(pArrayListSeleccion, i);

			if(selec_getId(pSeleccion, &auxID)==1 &&
			   selec_getPais(pSeleccion, auxPais)==1 &&
			   selec_getConfederacion(pSeleccion, auxConfederacion)==1 &&
			   selec_getConvocados(pSeleccion, &auxConvocados)==1)
			{
				fprintf(archivoGuardar,"%d,%s,%s,%d\n",auxID,auxPais,auxConfederacion,auxConvocados);
				retorno=1;
			}

			i++;

		}
		fclose(archivoGuardar);
	}
	return retorno;
}

/**
 * \fn int controller_ListarJugadoresConvocados(LinkedList*)
 * \brief Listar unicamento jugadores convocados a una seleccion
 * \param pArrayListJugador LinkedList* jugador
 * \return retorna 0 en caso de error , 1 en caso de exito
 */
int controller_ListarJugadoresConvocados(LinkedList* pArrayListJugador){
	int retorno=0;
	Jugador* pJugador = jug_new();
	int i=0;
	int auxConvocar;
	if(pArrayListJugador != NULL && pJugador != NULL){

		printf("\n|===================================================================================================================|\n"
				 "|  ID  | %-30s | Edad | %-20s | %-20s | %-20s |\n"
				 "|===================================================================================================================|\n",
				"Nombre Completo","posicion","Nacionalidad","Seleccion");
		while(i < ll_len(pArrayListJugador)){

			pJugador = (Jugador*) ll_get(pArrayListJugador, i);

			if(jug_getSIdSeleccion(pJugador, &auxConvocar)==1){

				if(auxConvocar != 0){

					jug_ListarUnJugador(pJugador);
					retorno=1;
				}
			}

			i++;
		}
		printf("|===================================================================================================================|\n");
	}
	return retorno;
}

/**
 * \fn int controller_convocarJugadores(LinkedList*, LinkedList*)
 * \brief Convocar un jugador a una seleccion a eleccion del usuario
 *
 * \param pArray LinkedList* lista jugador
 * \param pArray LinkedList* lista seleccion
 * \return retorna 0 en caso de error , 1 en caso de exito
 */
int controller_convocarJugadores(LinkedList* pArrayListJugador,LinkedList* pArrayListSeleccion){
	int retorno=0;
	int idBuscarJugador = -1;
	int indiceJugador;
	Jugador* pJugador = jug_new();
	int jugadorConvocado;

	//Seleccion
	int idBuscarSeleccion = -1;
	int indiceSeleccion;
	Seleccion* pSeleccion = selec_new();
	int seleccionSuperaVeintiDos;

	if(pArrayListJugador != NULL && pArrayListSeleccion != NULL && pJugador != NULL && pSeleccion != NULL){

		controller_listarJugadores(pArrayListJugador);

		if(utn_getNumeroINT(&idBuscarJugador,"Ingrese la ID del jugador que desea convocar\n",
				"Error/ Por favor ingrese un numero por encima de 0",1,2147483646,20)==1 &&
		   jug_BuscarId(pArrayListJugador,idBuscarJugador,&indiceJugador)==1){

			pJugador = (Jugador*) ll_get(pArrayListJugador,indiceJugador);
			if(jug_getSIdSeleccion(pJugador, &jugadorConvocado)==1){

				//Verifico que el jugador que se eligio no este convocado a una seleccion
				retorno = 3;
				if(0 == jugadorConvocado){

					controller_listarSelecciones(pArrayListSeleccion);

					if(utn_getNumeroINT(&idBuscarSeleccion,"Ingrese la ID de la seleccion que desea convocar al jugador\n",
							"Error/ Por favor ingrese el numero de las posibles selecciones(1 al 32)",1,32,20)==1)
					{
						if(selec_BuscarId(pArrayListSeleccion,idBuscarSeleccion,&indiceSeleccion)==1){

							pSeleccion = (Seleccion*) ll_get(pArrayListSeleccion,indiceSeleccion);
							selec_getConvocados(pSeleccion, &seleccionSuperaVeintiDos);

							retorno = 2;
							//verifico que la seleccion no supere los 22 jugadores
							if(seleccionSuperaVeintiDos < 22){

								//Le asigno al jugador el pais
								if(jug_setIdSeleccion(pJugador,idBuscarSeleccion)==1 &&
								   selec_setConvocados(pSeleccion, seleccionSuperaVeintiDos + 1)==1)
								{
									retorno=1;
								}
							}
						}
					}
				}
			}
		}
	}
	return retorno;
}

/**
 * \fn int controller_quitarSeleccionJugador(LinkedList*, LinkedList*)
 * \brief Da de baja a un jugador si el mismo esta convocado en una seleccion
 *
 * \param pArray LinkedList* ListJugador
 * \param pArray LinkedList* ListSeleccion
 * \return retorna 0 en caso de error , 1 en caso de exito
 */
int controller_quitarSeleccionJugador(LinkedList* pArrayListJugador,LinkedList* pArrayListSeleccion){
	int retorno=0;
	int IdJugador = -1;
	int indiceJugador;
	Jugador* pJugador = jug_new();
	Seleccion* pSeleccion = selec_new();

	int idSeleccion;
	int indiceSeleccion;
	int JugadoresConvocados;

	if(pArrayListJugador != NULL && pArrayListSeleccion != NULL && pJugador != NULL && pSeleccion != NULL){

		if(controller_ListarJugadoresConvocados(pArrayListJugador)==1){

			if(utn_getNumeroINT(&IdJugador,"Ingrese la id del jugador que desea quitar de una seleccion\n",
			   "Error asegurese de ingresar numeros y que no sea menores a 1\n",1,2147483646,20)==1 &&
			   jug_BuscarId(pArrayListJugador,IdJugador,&indiceJugador)==1)
			{

				pJugador = (Jugador*) ll_get(pArrayListJugador, indiceJugador);

				//Me aseguro que la id que ingreso sea el de un jugador convocado
				if(jug_getSIdSeleccion(pJugador, &idSeleccion)==1 &&
				   idSeleccion != 0){

					if(selec_BuscarId(pArrayListSeleccion,idSeleccion,&indiceSeleccion)==1){

						pSeleccion = (Seleccion*) ll_get(pArrayListSeleccion, indiceSeleccion);

						if(jug_setIdSeleccion(pJugador, 0)==1 &&
						   selec_getConvocados(pSeleccion, &JugadoresConvocados)==1 &&
						   selec_setConvocados(pSeleccion,JugadoresConvocados -1)==1)
						{
							retorno=1;
						}
					}
				}
			}
		}

	}
	return retorno;
}

/**
 * \fn int controller_menuConvocarQuitar(LinkedList*, LinkedList*)
 * \brief menu donde el usuario elegira entre convocar o quitar a un jugador de la seleccion
 *
 * \param pArray LinkedList* ListJugador
 * \param pArray  LinkedList* ListSeleccion
 * \return retorna 0 en caso de error , 1 en caso de exito
 */
int controller_menuConvocarQuitar(LinkedList* pArrayListJugador,LinkedList* pArrayListSeleccion){
	int retorno=0;
	int retornoFunc;
	int opcion=0;
	if(pArrayListJugador != NULL && pArrayListSeleccion != NULL){

		if(utn_getNumeroINT(&opcion,"1.Convocar a un jugador\n"
									"2.Quitar la seleccion a un jugador\n"
									"Ingrese el numero de la opcion que desea ingresar","Error/ Ingrese un opcion valida (1 o 2)",1,2,20)==1)
		{
			switch(opcion){
			case 1:
				retornoFunc = controller_convocarJugadores(pArrayListJugador, pArrayListSeleccion);

				switch(retornoFunc){
				case 1:
					printf("Convocacion exitosa\n");
					retorno=1;
					break;
				case 2:
					printf("La seleccion que ingresa ya tiene sus 22 jugadores convocados, regresando al menu\n");
					retorno=0;
					break;
				case 3:
					printf("El jugador ya pertenece a una seleccion\n");
					retorno=0;
					break;
				}
				break;
			case 2:
				if(controller_quitarSeleccionJugador(pArrayListJugador, pArrayListSeleccion)==1){
					retorno=1;
				}

				break;
			}
		}
	}

	return retorno;
}

/**
 * \fn int controller_menuOrdernar(LinkedList*, LinkedList*)
 * \brief Menu adonde el usuario elegira entre ordenar jugadores o ordenar selecciones
 *
 * \param pArray LinkedList* ListJugador
 * \param pArray LinkedList* ListSeleccion
 * \return retorna 0 en caso de error , 1 en caso de exito
 */
int controller_menuOrdernar(LinkedList* pArrayListJugador,LinkedList* pArrayListSeleccion){
	int retorno=0;
	int opciones=0;
	if(pArrayListJugador != NULL && pArrayListSeleccion != NULL){

		utn_getNumeroINT(&opciones,"1.Ordenar Jugadores\n"
				                   "2.Ordenar Selecciones\n"
				                   "Las opciones para ordenar a jugadores son, Edad, Nombre y Nacionalidad\n"
				                   "Mientras que las opcion de ordenar a Seleccion solo cuenta con ordenar por Confederacion\n"
				                   "Escriba la opcion que desea ver\n","Error/ Ingrese un numero dentro de las opciones (1  al 2)",1,2,20);

		switch(opciones){
		case 1:
			controller_ordenarJugadores(pArrayListJugador);
			retorno=1;
			break;
		case 2:
			controller_ordenarSelecciones(pArrayListSeleccion);
			retorno=1;
			break;
		}
	}
	return retorno;
}

/**
 * \fn int controller_menuListar(LinkedList*, LinkedList*)
 * \brief Menu adonde se elegira que listar
 *
 * \param pArray LinkedList* ListJugador
 * \param pArray LinkedList* ListSeleccion
 * \return retorna 0 en caso de error , 1 en caso de exito
 */
int controller_menuListar(LinkedList* pArrayListJugador,LinkedList* pArrayListSeleccion){
	int retorno=0;
	int opciones=0;
	if(pArrayListJugador != NULL && pArrayListSeleccion != NULL){
		utn_getNumeroINT(&opciones,"1.Listar Jugadores\n"
								   "2.Listar Selecciones\n"
								   "3.Listar Jugadores convocados\n"
					 	 	 	   "Escriba la opcion que desea ver\n","Error/ Ingrese un numero dentro de las opciones (1  al 3)",1,3,20);

		switch(opciones){
		case 1:
			controller_listarJugadores(pArrayListJugador);
			retorno = 1;
			break;
		case 2:
			controller_listarSelecciones(pArrayListSeleccion);
			retorno = 1;
			break;
		case 3:
			if(controller_ListarJugadoresConvocados(pArrayListJugador)==0){
				printf("|                                 No existen Jugadores convocados en ninguna Seleccion                              |\n"
					   "|===================================================================================================================|\n");
			}
			retorno = 1;
			break;
		}
	}
	return retorno;
}


