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

		if(auxId > 0){
			pSeleccion->id = auxId;
		}
		if(paisStr != NULL){
			strcpy(pSeleccion->pais,paisStr);
		}
		if(confederacionStr != NULL){
			strcpy(pSeleccion->confederacion,confederacionStr);
		}
		selec_setConvocados(pSeleccion,auxConvocados);
	}
	return pSeleccion;
}
void selec_delete(Seleccion* this){
	free(this);
}

int selec_getId(Seleccion* this,int* id){
	int retorno=0;
	if(this != NULL && id != NULL){
		*id = this->id;
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


int selec_BuscarId(LinkedList* this,int idBuscar,int* indiceEncontrado){
	int retorno=0;
	Seleccion* pAuxSeleccion = selec_new();
	int auxIdBuscar;
	int i=0;

	if(this != NULL && pAuxSeleccion != NULL){
		printf("\n\nEntro al buscar ID\n\n");
		while(i < ll_len(this)){

			pAuxSeleccion = (Seleccion*) ll_get(this, i);
			selec_getId(pAuxSeleccion,&auxIdBuscar);

			if(auxIdBuscar == idBuscar){
				*indiceEncontrado = i;
				retorno=1;
				break;
			}
			i++;
		}
	}
	return retorno;
}
