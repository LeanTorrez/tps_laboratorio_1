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

int selec_ListarUnaSeleccion(Seleccion* this){
	int retorno=0;

	int auxId;
	char auxPais[30];
	char auxConfederacion[30];
	int auxConvocados;

	if(this != NULL){
		selec_getId(this, &auxId);
		selec_getPais(this, auxPais);
		selec_getConfederacion(this, auxConfederacion);
		selec_getConvocados(this, &auxConvocados);
		printf("| %-5d | %-30s | %-30s | %-20d |\n",auxId,auxPais,auxConfederacion,auxConvocados);
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

int selec_OrdernarPorConfederacion(void* seleccionUno,void* seleccionDos){
	int retorno=0;
	Seleccion* pSeleccionUno;
	Seleccion* pSeleccionDos;
	char confeSeleccionUno[30];
	char confeSeleccionDos[30];

	pSeleccionUno = (Seleccion*) seleccionUno;
	pSeleccionDos = (Seleccion*) seleccionDos;

	selec_getConfederacion(pSeleccionUno,confeSeleccionUno);
	selec_getConfederacion(pSeleccionDos,confeSeleccionDos);

	if(stricmp(confeSeleccionUno,confeSeleccionDos) > 0){

		retorno = 1;

	}else{
		if(stricmp(confeSeleccionUno,confeSeleccionDos) < 0){

			retorno = -1;
		}

	}

	return retorno;
}

int selec_elegirConfederacion(char* pConfederacionElegida){
	int retorno=0;
	int opcion=0;
	char AuxNombreConfe[30];
	if( utn_getNumeroINT(&opcion,"1.AFC\n"
								 "2.CAF\n"
								 "3.CONCACAF\n"
								 "4.CONMEBOL\n"
								 "5.UEFA\n"
								 "Elija el numero de la confederacion que quiera generar una lista de jugadores convocados\n","Error/ Las opciones van de 1 al 5",1,5,30)==1)
	{

		switch(opcion){
		case 1:
			strcpy(AuxNombreConfe,"AFC");
			break;
		case 2:
			strcpy(AuxNombreConfe,"CAF");
			break;
		case 3:
			strcpy(AuxNombreConfe,"CONCACAF");
			break;
		case 4:
			strcpy(AuxNombreConfe,"CONMEBOL");
			break;
		case 5:
			strcpy(AuxNombreConfe,"UEFA");
			break;
		}
		strcpy(pConfederacionElegida,AuxNombreConfe);
		retorno=1;
	}
	return retorno;
}
