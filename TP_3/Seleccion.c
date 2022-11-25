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

		if(selec_getId(this, &auxId)==1 &&
		   selec_getPais(this, auxPais)==1 &&
		   selec_getConfederacion(this, auxConfederacion)==1 &&
		   selec_getConvocados(this, &auxConvocados)==1)
		{
			printf("| %-5d | %-30s | %-30s | %-20d |\n",auxId,auxPais,auxConfederacion,auxConvocados);
			retorno=1;
		}
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
			if(selec_getId(pAuxSeleccion,&auxIdBuscar)==1){

				if(auxIdBuscar == idBuscar){
					*indiceEncontrado = i;
					retorno=1;
					break;
				}
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

int selec_menuEditarSeleccion(Seleccion* pSeleccion){
	int retorno=0;

	char auxPais[30];

	int opcionConfe=-1;
	char auxConfederacion[30];

	int menuOpciones = 0;

	utn_getNumeroINT(&menuOpciones,"1.Pais\n"
								   "2.Confederacion\n"
								   "Ingrese el numero de la opcion que desea modificar\n","Error/ Ingrese una opcion valida (1 al 2)\n",1,2,20);
	switch(menuOpciones){
	case 1:
		printf(" %-60s \n","Modificar Pais");
		if(utn_getDescripcion(auxPais,sizeof(auxPais),"Ingrese el del pais\n","Error/ asegurese de ingresar algo\n",20)==0){
			//ACA IRIA EL SETTER DE PAIS
			retorno=1;
		}
		break;
	case 2:
		printf(" %-60s \n","Modificar Confederacion");
		if(utn_getNumeroINT(&opcionConfe,"1.UEFA\n"
									     "2.CONMEBOL\n"
									     "3.AFC\n"
									     "4.CONCACAF\n"
									     "5.CAF\n"
									     "Ingrese el numero de la confederacion\n","Error/ Ingrese un numero valido (1 al 5)\n",1,5,20)==1)
		{
			switch(opcionConfe){
			case 1:
				strcpy(auxConfederacion,"UEFA");
				break;
			case 2:
				strcpy(auxConfederacion,"CONMEBOL");
				break;
			case 3:
				strcpy(auxConfederacion,"AFC");
				break;
			case 4:
				strcpy(auxConfederacion,"CONCACAF");
				break;
			case 5:
				strcpy(auxConfederacion,"CAF");
				break;
			}
			//ACA IRIA EL SETTER PARA CONFEDERACION
			retorno=1;
		}
		break;
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

int selec_nombreSeleccion(int idSeleccion,char* pNombreSeleccion){
	int retorno=0;

	//Hice esta funcion porque la otra que pensaba resolver la nota 2 tenia que modificar muchos campos que habia ya hecho,
	//y me generaba problemas asi que decidi resolver el problema de esta manera que no es la mas optima
	//porque dado el caso que se agregen mas seleccion esto se volveria inservible
	char auxNombreSeleccion[30];


	if(idSeleccion > 0){

		switch(idSeleccion){
		case 1:
			strcpy(auxNombreSeleccion,"Alemania");
			break;
		case 2:
			strcpy(auxNombreSeleccion,"Arabia Saudita");
			break;
		case 3:
			strcpy(auxNombreSeleccion,"Argentina");
			break;
		case 4:
			strcpy(auxNombreSeleccion,"Australia");
			break;
		case 5:
			strcpy(auxNombreSeleccion,"Belgica");
			break;
		case 6:
			strcpy(auxNombreSeleccion,"Brasil");
			break;
		case 7:
			strcpy(auxNombreSeleccion,"Camerun");
			break;
		case 8:
			strcpy(auxNombreSeleccion,"Canada");
			break;
		case 9:
			strcpy(auxNombreSeleccion,"Corea del Sur");
			break;
		case 10:
			strcpy(auxNombreSeleccion,"Costa Rica");
			break;
		case 11:
			strcpy(auxNombreSeleccion,"Croacia");
			break;
		case 12:
			strcpy(auxNombreSeleccion,"Dinamarca");
			break;
		case 13:
			strcpy(auxNombreSeleccion,"Ecuador");
			break;
		case 14:
			strcpy(auxNombreSeleccion,"Espana");
			break;
		case 15:
			strcpy(auxNombreSeleccion,"Estados Unidos");
			break;
		case 16:
			strcpy(auxNombreSeleccion,"Francia");
			break;
		case 17:
			strcpy(auxNombreSeleccion,"Gales");
			break;
		case 18:
			strcpy(auxNombreSeleccion,"Ghana");
			break;
		case 19:
			strcpy(auxNombreSeleccion,"Holanda");
			break;
		case 20:
			strcpy(auxNombreSeleccion,"Inglaterra");
			break;
		case 21:
			strcpy(auxNombreSeleccion,"Iran");
			break;
		case 22:
			strcpy(auxNombreSeleccion,"Japon");
			break;
		case 23:
			strcpy(auxNombreSeleccion,"Marruecos");
			break;
		case 24:
			strcpy(auxNombreSeleccion,"Mexico");
			break;
		case 25:
			strcpy(auxNombreSeleccion,"Polonia");
			break;
		case 26:
			strcpy(auxNombreSeleccion,"Portugal");
			break;
		case 27:
			strcpy(auxNombreSeleccion,"Qatar");
			break;
		case 28:
			strcpy(auxNombreSeleccion,"Senegal");
			break;
		case 29:
			strcpy(auxNombreSeleccion,"Serbia");
			break;
		case 30:
			strcpy(auxNombreSeleccion,"Suiza");
			break;
		case 31:
			strcpy(auxNombreSeleccion,"Tunez");
			break;
		case 32:
			strcpy(auxNombreSeleccion,"Uruguay");
			break;
		}
		strcpy(pNombreSeleccion,auxNombreSeleccion);
		retorno=1;
	}
	return retorno;
}

