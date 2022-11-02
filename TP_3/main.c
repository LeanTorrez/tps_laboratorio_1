#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "utn.h"
#include "Jugador.h"
#include "Seleccion.h"

int main()
{
	setbuf(stdout,NULL);
    int option = 0;
    int retornoOpcion;
    LinkedList* listaJugadores = ll_newLinkedList();
    LinkedList* listaSeleccion = ll_newLinkedList();

    do{
    	retornoOpcion = utn_getNumeroINT(&option,"\n1.Carga de Archivos\n"
    												 "2.Alta Jugador\n"
    												 "3.Modificacion de Jugador\n"
    												 "4.Baja de Jugador\n"
    												 "5.Listados\n"
    												 "6.Convocar Jugadores\n"
    												 "7.Ordenar y Listar\n"
    												 "8.Generar Archivo Binario\n"
    												 "9.Cargar Archivo Binario\n"
    												 "10.Guardar Archivos .CSV\n"
    												 "11.Salir\n"
    												 "Ingrese el numero de la opcion que quiera ver\n","Error/ Ingresar una opcion valida (1 al 11)",1,11,20);

    	if(retornoOpcion == 0){
			printf("Error/ Se Ingresaron todos los intentos posibles... Recargando el Menu");
			option = 0;
		}
        switch(option)
        {
            case 1:
            	printf(" %-60s \n","CARGA DE ARCHIVOS");
            	if(controller_cargarJugadoresDesdeTexto("jugadores.csv",listaJugadores)){
            		printf("Carga de Jugadores exitosa\n");
            	}
            	if(controller_cargarSeleccionesDesdeTexto("selecciones.csv",listaSeleccion)){
            		printf("Carga de Selecciones exitosa\n");
            	}
                break;
            case 2:
            	printf(" %-60s \n","ALTA JUGADOR");
            	if(ll_isEmpty(listaJugadores)==1){
            		printf("Debe ingresar primero a la opcion 1 para poder empezar a dar de alta a jugadores.\n");
            	}else{
            		controller_agregarJugador(listaJugadores);
            	}
            	break;
            case 3:
            	printf(" %-60s \n","MODIFICACION DE JUGADOR");
            	if(ll_isEmpty(listaJugadores)==1){
					printf("Debe ingresar primero a la opcion 1 para poder empezar a modificar a los jugadores.\n");
				}else{
					controller_editarJugador(listaJugadores);
				}
            	break;
            case 4:
            	printf(" %-60s \n","BAJA DE JUGADOR");
            	if(ll_isEmpty(listaJugadores)==1){
					printf("Debe ingresar primero a la opcion 1 para poder empezar a modificar a los jugadores.\n");
				}else{
					controller_removerJugador(listaJugadores);
				}
            	break;
            case 5:
            	printf(" %-60s \n","LISTADOS");
            	controller_listarJugadores(listaJugadores);
            	//controller_listarSelecciones(listaSeleccion);
				break;
			case 6:
				printf(" %-60s \n","CONVOCAR JUGADORES");
				//jug_IdAutoincremental();
				break;
			case 7:
				printf(" %-60s \n","ORDERNAR Y LISTAR");
				break;
			case 8:
				printf(" %-60s \n","GENERAR ARCHIVO BINARIO");
				if(ll_isEmpty(listaJugadores)==1){
					printf("Debe ingresar primero a la opcion 1 para poder empezar a dar de alta a jugadores.\n");
				}else{
					controller_guardarJugadoresModoBinario("jugadoresBinario.bin",listaJugadores);
				}
				break;
			case 9:
				printf(" %-60s \n","CARGAR ARCHIVO BINARIO");
				break;
			case 10:
				printf(" %-60s \n","GUARDAR ARCHIVO .CSV");
				if(ll_isEmpty(listaJugadores)==1){
					printf("Debe ingresar primero a la opcion 1 para poder empezar a dar de alta a jugadores.\n");
				}else{
					controller_guardarJugadoresModoTexto("jugadoresNuevos.csv",listaJugadores);
				}
				break;
			case 11:
				printf(" %-60s \n","SALIR");
				ll_deleteLinkedList(listaSeleccion);
				ll_deleteLinkedList(listaJugadores);
				break;

        }
    }while(option != 11);

    return 0;
}

