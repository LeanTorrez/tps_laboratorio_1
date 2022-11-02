
#include "Jugador.h"

Jugador* jug_new(){
	Jugador* pJugador;
	pJugador = (Jugador*) malloc(sizeof(Jugador));
	//INICIALIZO LOS DATOS EN 0
	if(pJugador != NULL){
		jug_setId(pJugador,1);
		jug_setNombreCompleto(pJugador,"1");
		jug_setEdad(pJugador,1);
		jug_setPosicion(pJugador,"0");
		jug_setNacionalidad(pJugador,"0");
		jug_setIdSeleccion(pJugador,0);
		jug_setIsEmpty(pJugador,0);
	}
	return pJugador;
}

Jugador* jug_newParametros(char* idStr,
							char* nombreCompletoStr,
							char* edadStr,
							char* posicionStr,
							char* nacionalidadStr,
							char* idSelccionStr){

	Jugador* pJugador;
	int auxId;
	int auxEdad;
	int auxIdSeleccion;

	pJugador = jug_new();

	if(pJugador != NULL){
		auxId = atoi(idStr);
		auxEdad = atoi(edadStr);
		auxIdSeleccion = atoi(idSelccionStr);

		jug_setId(pJugador,auxId);
		jug_setNombreCompleto(pJugador,nombreCompletoStr);
		jug_setEdad(pJugador,auxEdad);
		jug_setPosicion(pJugador,posicionStr);
		jug_setNacionalidad(pJugador,nacionalidadStr);
		jug_setIdSeleccion(pJugador,auxIdSeleccion);
		jug_setIsEmpty(pJugador,1);
	}

	return pJugador;
}

void jug_delete(Jugador* this){
	if(this != NULL){
		free(this);
	}
}

int jug_setId(Jugador* this,int id){
	int retorno=0;
	if(this != NULL && id > 0){
		this->id = id;
		retorno=1;
	}
	return retorno;
}
int jug_getId(Jugador* this,int* id){
	int retorno=0;
	if(this != NULL && id != NULL){
		*id = this->id;
		retorno=1;
	}
	return retorno;
}


int jug_setNombreCompleto(Jugador* this,char* nombreCompleto){
	int retorno=0;
	if(this != NULL && nombreCompleto != NULL){
		strcpy(this->nombreCompleto,nombreCompleto);
		retorno=1;
	}
	return retorno;
}
int jug_getNombreCompleto(Jugador* this,char* nombreCompleto){
	int retorno=0;
	if(this != NULL && nombreCompleto != NULL){
		strcpy(nombreCompleto,this->nombreCompleto);
		retorno=1;
	}
	return retorno;
}


int jug_setPosicion(Jugador* this,char* posicion){
	int retorno=0;
	if(this != NULL && posicion != NULL){
		strcpy(this->posicion,posicion);
		retorno=1;
	}
	return retorno;
}
int jug_getPosicion(Jugador* this,char* posicion){
	int retorno=0;
	if(this != NULL && posicion != NULL){
		strcpy(posicion,this->posicion);
		retorno=1;
	}
	return retorno;
}


int jug_setNacionalidad(Jugador* this,char* nacionalidad){
	int retorno=0;
	if(this != NULL && nacionalidad != NULL){
		strcpy(this->nacionalidad,nacionalidad);
		retorno=1;
	}
	return retorno;
}
int jug_getNacionalidad(Jugador* this,char* nacionalidad){
	int retorno=0;
	if(this != NULL && nacionalidad != NULL){
		strcpy(nacionalidad,this->nacionalidad);
		retorno=1;
	}
	return retorno;
}


int jug_setEdad(Jugador* this,int edad){
	int retorno=0;
	if(this != NULL && edad > 0){
		this->edad = edad;
		retorno=1;
	}
	return retorno;
}
int jug_getEdad(Jugador* this,int* edad){
	int retorno=0;
	if(this != NULL && edad != NULL){
		*edad = this->edad;
		retorno=1;
	}
	return retorno;
}


int jug_setIdSeleccion(Jugador* this,int idSeleccion){
	int retorno=0;
	if(this != NULL && idSeleccion > -1){
		this->idSeleccion = idSeleccion;
		retorno=1;
	}
	return retorno;
}
int jug_getSIdSeleccion(Jugador* this,int* idSeleccion){
	int retorno=0;
	if(this != NULL && idSeleccion != NULL){
		*idSeleccion = this->idSeleccion;
		retorno=1;
	}
	return retorno;
}


int jug_setIsEmpty(Jugador* this,int isEmpty){
	int retorno=0;
	if(this != NULL && isEmpty > -1){
		this->isEmpty = isEmpty;
		retorno=1;
	}
	return retorno;
}
int jug_getIsEmpty(Jugador* this,int* isEmpty){
	int retorno=0;
	if(this != NULL && isEmpty != NULL){
		*isEmpty = this->isEmpty;
		retorno=1;
	}
	return retorno;
}

int jug_IdAutoincremental(){
	int retorno = 0;
	FILE* IdAutoIncremental;

	char auxIdJugador[10];
	int nuevoIdJugador=0;

	IdAutoIncremental = fopen("IDAUTOINCREMENTAL.csv","r+");

	if(IdAutoIncremental != NULL){

		fscanf(IdAutoIncremental,"%s\n",auxIdJugador);

		//Devuelvo el ID autoincremental
		retorno = atoi(auxIdJugador);

		rewind(IdAutoIncremental);

		nuevoIdJugador = retorno + 1;

		fprintf(IdAutoIncremental,"%d",nuevoIdJugador);

		fclose(IdAutoIncremental);
	}
	return retorno;
}

int jug_BuscarId(LinkedList* this,int idBuscar,int* IndiceEncontrado){
	int retorno=0;
	Jugador* pAuxJugador;
	int auxIdBuscar;
	int i=0;

	if(this != NULL){
		printf("\n\nEntro al buscar ID\n\n");
		while(i < ll_len(this)){

			pAuxJugador = (Jugador*) ll_get(this, i);
			jug_getId(pAuxJugador, &auxIdBuscar);

			if(auxIdBuscar == idBuscar){
				*IndiceEncontrado = i;
				retorno=1;
				break;
			}
			i++;
		}
	}
	return retorno;
}

int jug_MenuEditarJugador(Jugador* pJugador){
	int retorno=0;

	char auxNombre[100];
	int auxEdad;
	char auxPosicion[30];
	char auxNacionalidad[30];

	int menuOpciones = 0;

	utn_getNumeroINT(&menuOpciones,"1.Nombre Completo\n"
								   "2.Edad\n"
								   "3.Posicion\n"
								   "4.Nacionalidad\n"
								   "Ingrese el numero de la opcion que desea modificar\n","Error/ Ingrese una opcion valida (1 al 4)",1,4,20);
	switch(menuOpciones){
	case 1:
		printf(" %-60s \n","Modificar Nombre Completo");
		utn_getString(auxNombre,sizeof(auxNombre),"Ingrese el nombre completo del jugador\n","Error/ asegurese de ingresar algo",20);
		jug_setNombreCompleto(pJugador, auxNombre);
		retorno=1;
		break;
	case 2:
		printf(" %-60s \n","Modificar Edad");
		utn_getNumeroINT(&auxEdad,"Ingrese la edad del jugador\n","Error/ La edad no puede ser menor a 16 o mayor a 40",16,40,20);
		jug_setEdad(pJugador, auxEdad);
		retorno=1;
		break;
	case 3:
		printf(" %-60s \n","Modificar Posicion");
		utn_getString(auxPosicion,sizeof(auxPosicion),"Ingrese la posicion del jugador","Error/ asegures de ingresar algo",20);
		jug_setPosicion(pJugador, auxPosicion);
		retorno=1;
		break;
	case 4:
		printf(" %-60s \n","Modificar Nacionalidad");
		utn_getString(auxNacionalidad, sizeof(auxNacionalidad),"Ingrese la nacionalidad del Jugador\n","Asegurese de ingresar algo",20);
		jug_setNacionalidad(pJugador, auxNacionalidad);
		retorno=1;
		break;

	}
	return retorno;
}
