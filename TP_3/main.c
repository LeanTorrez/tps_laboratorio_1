#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "utn.h"
#include "Jugador.h"

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
    												 "3.Modifciacion de Jugador\n"
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
            	controller_cargarJugadoresDesdeTexto("jugadores.csv",listaJugadores);
            	controller_cargarSeleccionesDesdeTexto("selecciones.csv",listaSeleccion);
                break;
            case 2:
            	break;
            case 3:
            	break;
            case 4:
            	break;
            case 5:
				break;
			case 6:
				break;
			case 7:
				break;
			case 8:
				break;
			case 9:
				break;
			case 10:
				break;
			case 11:
				break;

        }
    }while(option != 11);

    return 0;
}

