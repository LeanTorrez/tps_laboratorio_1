
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

