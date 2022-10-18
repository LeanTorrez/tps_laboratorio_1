/*
 * funcionesEstructuraJugador.c
 *
 *  Created on: 12 oct. 2022
 *      Author: leand
 */


int InicializacionStructJugadores(eJugador jugador,int tamJugador){
	int retorno = 0;
	if(tamJugador>0){
		for(int i=0;i<tamJugador;i++){
				jugador[i].isEmpty = 0;
		}
		retorno=1;
	}
	return retorno;
}

int BuscarStructIndiceIsEmpty(eJugador jugador,int tamJugador,int* indice){
	int retorno=0;
	if(tamJugador > 0){
		for(int i=0;i<tamJugador;i++){
			if(jugador[i].isEmpty == 0){
				*indice = i;
				retorno = 1;
				break;
			}
		}
	}
	return retorno;
}

int BuscarStructIndiceLLENO(eJugador jugador,int tamJugador){
	int retorno=0;
	for(int i=0;i<tamJugador;i++){
		if(jugador[i].isEmpty == 1){
			retorno = 1;
			break;
		}
	}
	return retorno;
}
