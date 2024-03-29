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
    int flagGuardar=1;
    int flagCreoArchivoBinario=0;
    LinkedList* listaJugadores = ll_newLinkedList();
    LinkedList* listaSeleccion = ll_newLinkedList();
    LinkedList* listaJugadoresBinario = ll_newLinkedList();

    do{
    	retornoOpcion = utn_getNumeroINT(&option,"\n1.Carga de Archivos\n"
    												 "2.Alta Jugador\n"
    												 "3.Modificacion de Jugador\n"
    												 "4.Baja de Jugador\n"
    												 "5.Listados\n"
    												 "6.Convocar o Remover Jugadores de Seleccion\n"
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
            	printf("%-60s \n","CARGA DE ARCHIVOS");
            	if(ll_isEmpty(listaJugadores) == 1 && ll_isEmpty(listaSeleccion) == 1){
            		if(controller_cargarJugadoresDesdeTexto("jugadores.csv",listaJugadores)){
						printf("Carga de Jugadores exitosa\n");
					}
					if(controller_cargarSeleccionesDesdeTexto("selecciones.csv",listaSeleccion)){
						printf("Carga de Selecciones exitosa\n");
					}
            	}else{
            		printf("Ya se han cargado los datos en la lista... Volviendo al menu\n");
            	}

                break;

            case 2:
            	printf("%-60s \n","ALTA JUGADOR");

            	if(ll_isEmpty(listaJugadores)==1){
            		printf("Debe ingresar primero a la opcion 1 para poder empezar a dar de alta a jugadores.\n");
            	}else{
            		if(controller_agregarJugador(listaJugadores) == 1){
            			printf("Se Agrego con exito al jugador\n");
            			flagGuardar = 0;
            		}else{
            			printf("Error al intentar agregar al jugador... Volviendo al menu");
            		}

            	}
            	break;

            case 3:
            	printf("%-60s \n","MODIFICACION DE JUGADOR");

            	if(ll_isEmpty(listaJugadores)==1){
					printf("Debe ingresar primero a la opcion 1 para poder empezar a modificar a los jugadores.\n");
				}else{
					if(controller_editarJugador(listaJugadores)==0){
						printf("Error al ejecutar la modificacion... regresando al Menu\n");
					}else{
						printf("Jugador Editado Exitosamente\n");
						flagGuardar = 0;
					}
				}
            	break;

            case 4:
            	printf("%-60s \n","BAJA DE JUGADOR");

            	if(ll_isEmpty(listaJugadores)==1){
					printf("Debe ingresar primero a la opcion 1 para dar de baja a los jugadores.\n");
				}else{
					if(controller_removerJugador(listaJugadores,listaSeleccion)==1){
						printf("Se ha dado baja exitosamente\n");
						flagGuardar = 0;
					}else{
						printf("Error/ Id no encontrado... regresando al menu\n");
					}
				}
            	break;

            case 5:
            	printf("%-60s \n","LISTADOS");
            	if(ll_isEmpty(listaJugadores)==1 && ll_isEmpty(listaSeleccion)==1){
					printf("Debe ingresar primero a la opcion 1 para poder ver las listas.\n");
				}else{
					if(controller_menuListar(listaJugadores,listaSeleccion)){
					}else{
						printf("Error al mostrar las listas... Regresando al menu\n");
					}
				}
				break;

			case 6:
				printf("%-60s \n","CONVOCAR JUGADORES");

				if(ll_isEmpty(listaJugadores)==1){
					printf("Debe ingresar primero a la opcion 1 para poder convocar a los jugadores.\n");
				}else{
					if(controller_menuConvocarQuitar(listaJugadores,listaSeleccion)==1){
						printf("Se llevo con exito la operacion\n");
						flagGuardar = 0;
					}else{
						printf("\nError en la operacion\n");
					}
				}
				break;

			case 7:
				printf("%-60s \n","ORDERNAR Y LISTAR");
				if(ll_isEmpty(listaJugadores)==1){
					printf("Debe ingresar primero a la opcion 1 para para poder ordenar las listas.\n");
				}else{
					if(controller_menuOrdernar(listaJugadores,listaSeleccion)==0){
						printf("Ocurrio un error... regresando al menu\n");
					}
				}
				break;

			case 8:
				printf("%-60s \n","GENERAR ARCHIVO BINARIO");

				if(ll_isEmpty(listaJugadores)==1 && ll_isEmpty(listaSeleccion)==1){
					printf("Debe ingresar primero a la opcion 1 para poder crear el archivo binario.\n");
				}else{
					if(controller_guardarJugadoresModoBinario("jugadoresBinario.bin",listaJugadores,listaSeleccion)==1){
						printf("Creacion de archivo binario exitoso\n");

						if(ll_isEmpty(listaJugadoresBinario) == 0){
							ll_clear(listaJugadoresBinario);
						}
						flagCreoArchivoBinario=1;
					}else{
						printf("Erro en la creacion del archivo binario... Regresando al Menu\n");
					}
				}
				break;

			case 9:
				printf("%-60s \n","CARGAR ARCHIVO BINARIO");
				if(flagCreoArchivoBinario == 1){
					if(controller_cargarJugadoresDesdeBinario("jugadoresBinario.bin",listaJugadoresBinario)==1){
						controller_listarJugadores(listaJugadoresBinario);
					}
				}else{
					printf("Es necesario que se ingrese a la opcion 8 para podeer leer el archivo binario \n");
				}
				break;

			case 10:
				printf("%-60s \n","GUARDAR ARCHIVO .CSV");

				if(ll_isEmpty(listaJugadores)==1){
					printf("Debe ingresar primero a la opcion 1 para poder empezar a dar de alta a jugadores.\n");
				}else{
					controller_guardarJugadoresModoTexto("jugadores.csv",listaJugadores);
					controller_guardarSeleccionesModoTexto("selecciones.csv",listaSeleccion);
					flagGuardar = 1;
				}
				break;

			case 11:
				printf("%-60s \n","SALIR");
				if(flagGuardar != 1){
					printf("Para poder salir primero guarde los cambios que hizo en la opcion 10\n");
					option=0;
				}else{
					if(ConfirmarChar("Esta seguro que quiere salir [s/n]","Error/ ingrese 's' para salir o 'n' para volver al menu",'S','N')=='N'){
						option = 0;
						printf("Regresando al Menu");
					}else{
						ll_deleteLinkedList(listaJugadoresBinario);
						ll_deleteLinkedList(listaSeleccion);
						ll_deleteLinkedList(listaJugadores);
					}
				}
				break;


        }
    }while(option != 11);

    return 0;
}

