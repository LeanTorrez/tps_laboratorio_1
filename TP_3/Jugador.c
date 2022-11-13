
#include "Jugador.h"

Jugador* jug_new(){
	Jugador* pJugador;
	pJugador = (Jugador*) malloc(sizeof(Jugador));
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


int jug_ListarUnJugador(Jugador* this){
	int retorno=0;
	int auxID;
	char auxNombre[100];
	int auxEdad;
	char auxPosicion[30];
	char auxNacionalidad[30];
	int auxIdSeleccion;

	//Nombre de seleccion
	char auxNombreSeleccion[30];



	if(this != NULL){
		jug_getId(this, &auxID);
		jug_getNombreCompleto(this, auxNombre);
		jug_getEdad(this, &auxEdad);
		jug_getPosicion(this, auxPosicion);
		jug_getNacionalidad(this, auxNacionalidad);
		jug_getSIdSeleccion(this,&auxIdSeleccion);

		//En caso de que el jugador este en la seleccion el id sera reemplazado por el nombre de la misma
		if(auxIdSeleccion == 0){
			strcpy(auxNombreSeleccion,"No convocado");
		}else{
			selec_nombreSeleccion(auxIdSeleccion, auxNombreSeleccion);
		}

		printf("| %-4d | %-30s | %-4d | %-20s | %-20s | %-20s |\n",auxID,auxNombre,auxEdad,auxPosicion,auxNacionalidad,auxNombreSeleccion);
		retorno=1;
	}
	return retorno;
}

int jug_IdAutoincremental(){
	int retorno = 0;
	FILE* IdAutoIncremental;

	char auxIdJugador[10];
	int nuevoIdJugador=0;
	//Abro el archivo en lectura y escritura
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
	Jugador* pAuxJugador = jug_new();
	int auxIdBuscar;
	int i=0;

	if(this != NULL && pAuxJugador != NULL){
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
								   "Ingrese el numero de la opcion que desea modificar\n","Error/ Ingrese una opcion valida (1 al 4)\n",1,4,20);
	switch(menuOpciones){
	case 1:
		printf(" %-60s \n","Modificar Nombre Completo");
		if(utn_getDescripcion(auxNombre,sizeof(auxNombre),"Ingrese el nombre completo del jugador\n","Error/ asegurese de ingresar algo\n",20)==0){
			jug_setNombreCompleto(pJugador, auxNombre);
			retorno=1;
		}
		break;
	case 2:
		printf(" %-60s \n","Modificar Edad");
		utn_getNumeroINT(&auxEdad,"Ingrese la edad del jugador\n","Error/ La edad no puede ser menor a 16 o mayor a 40\n",16,40,20);
		jug_setEdad(pJugador, auxEdad);
		retorno=1;
		break;
	case 3:
		printf(" %-60s \n","Modificar Posicion");
		if(utn_getDescripcion(auxPosicion,sizeof(auxPosicion),"Ingrese la posicion del jugador","Error/ asegures de ingresar algo\n",20) == 0){
			jug_setPosicion(pJugador, auxPosicion);
			retorno=1;
		}
		break;
	case 4:
		printf(" %-60s \n","Modificar Nacionalidad");
		if(utn_getString(auxNacionalidad, sizeof(auxNacionalidad),"Ingrese la nacionalidad del Jugador\n","Asegurese de ingresar algo\n",20) == 0){
			jug_setNacionalidad(pJugador, auxNacionalidad);
			retorno=1;
		}
		break;

	}
	return retorno;
}

int jug_OrdenarPorNacionalidad(void* jugadorUno,void* jugadorDos){
	int retorno=0;
	char nacionalidadJugador1[30];
	char nacionalidadJugador2[30];
	Jugador* pJugadorUno;
	Jugador* pJugadorDos;

	pJugadorUno = (Jugador*) jugadorUno;
	pJugadorDos = (Jugador*) jugadorDos;

	jug_getNacionalidad(pJugadorUno, nacionalidadJugador1);
	jug_getNacionalidad(pJugadorDos, nacionalidadJugador2);

	if(stricmp(nacionalidadJugador1,nacionalidadJugador2) > 0){

		retorno = 1;
	}else{
		if(stricmp(nacionalidadJugador1,nacionalidadJugador2) < 0){

			retorno = -1;
		}

	}

	return retorno;
}

int jug_OrdenarPorEdad(void* jugadorUno,void* jugadorDos){
	int retorno=0;
	int edadJugador1;
	int edadJugador2;
	Jugador* pJugadorUno;
	Jugador* pJugadorDos;

	pJugadorUno = (Jugador*) jugadorUno;
	pJugadorDos = (Jugador*) jugadorDos;

	jug_getEdad(pJugadorUno, &edadJugador1);
	jug_getEdad(pJugadorDos, &edadJugador2);

	if(edadJugador1 > edadJugador2){

		retorno = 1;
	}else{
		if(edadJugador1 < edadJugador2){

			retorno = -1;
		}

	}
	return retorno;
}

int jug_OrdenarPorNombre(void* jugadorUno,void* jugadorDos){
	int retorno=0;
	char nombreJugador1[100];
	char nombreJugador2[100];
	Jugador* pJugadorUno;
	Jugador* pJugadorDos;

	pJugadorUno = (Jugador*) jugadorUno;
	pJugadorDos = (Jugador*) jugadorDos;

	jug_getNombreCompleto(pJugadorUno, nombreJugador1);
	jug_getNombreCompleto(pJugadorDos, nombreJugador2);

	if(stricmp(nombreJugador1,nombreJugador2) > 0){

		retorno = 1;
	}else{
		if(stricmp(nombreJugador1,nombreJugador2) < 0){

			retorno = -1;
		}

	}

	return retorno;
}
