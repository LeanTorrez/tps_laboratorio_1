#include "Seleccion.h"

Seleccion* selec_new(){
	Seleccion* pSeleccion;

	pSeleccion = (Seleccion*) malloc(sizeof(Seleccion));
	return pSeleccion;
}
Seleccion* selec_newParametros(char* idStr,char* paisStr,char* confederacionStr, char* convocadosStr){
	Seleccion* pSeleccion;
	int auxId;
	int auxConvocados;
	pSeleccion = selec_new();
	if(pSeleccion != NULL){
		auxId = atoi(idStr);
		auxConvocados = atoi(convocadosStr);

		selec_setId(pSeleccion,auxId);
		selec_setPais(pSeleccion,paisStr);
		selec_setConfederacion(pSeleccion,confederacionStr);
		selec_setConvocados(pSeleccion,auxConvocados);
		selec_setIsEmpty(pSeleccion,1);
	}
	return pSeleccion;
}
void selec_delete(Seleccion* this){
	free(this);
}



int selec_setId(Seleccion* this,int id){
	int retorno=0;
	if(this != NULL && id > 0){
		this->id = id;
		retorno=1;
	}
	return retorno;
}
int selec_getId(Seleccion* this,int* id){
	int retorno=0;
	if(this != NULL && id != NULL){
		*id = this->id;
		retorno=1;
	}
	return retorno;
}


int selec_setPais(Seleccion* this,char* pais){
	int retorno=0;
	if(this != NULL && pais != NULL){
		strcpy(this->pais,pais);
		retorno=1;
	}
	return retorno;
}
int selec_getPais(Seleccion* this,char* pais){
	int retorno=0;
	if(this != NULL && pais != NULL){
		strcpy(pais,this->pais);
		retorno=1;
	}
	return retorno;
}


int selec_setConfederacion(Seleccion* this,char* confederacion){
	int retorno=0;
	if(this != NULL && confederacion != NULL){
		strcpy(this->confederacion,confederacion);
		retorno=1;
	}
	return retorno;
}
int selec_getConfederacion(Seleccion* this,char* confederacion){
	int retorno=0;
	if(this != NULL && confederacion != NULL){
		strcpy(confederacion,this->confederacion);
		retorno=1;
	}
	return retorno;
}


int selec_setConvocados(Seleccion* this,int convocados){
	int retorno=0;
	if(this != NULL && convocados > -1){
		this->convocados = convocados;
		retorno=1;
	}
	return retorno;
}
int selec_getConvocados(Seleccion* this,int* convocados){
	int retorno=0;
	if(this != NULL && convocados != NULL){
		*convocados = this->convocados;
		retorno=1;
	}
	return retorno;
}


int selec_setIsEmpty(Seleccion* this,int isEmpty){
	int retorno=0;
	if(this != NULL && isEmpty > -1){
		this->isEmpty = isEmpty;
		retorno=1;
	}
	return retorno;
}
int selec_getIsEmpty(Seleccion* this,int* isEmpty){
	int retorno=0;
	if(this != NULL && isEmpty != NULL){
		*isEmpty = this->isEmpty;
		retorno=1;
	}
	return retorno;
}
