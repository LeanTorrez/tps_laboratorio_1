#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this= NULL;
    this = (LinkedList*) malloc(sizeof(LinkedList));

    if(this != NULL){

    	this->pFirstNode = NULL;
    	this->size = 0;
    }

    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL){
    	returnAux = this->size;
    }

    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
	Node* auxNode=NULL;
	int i;

    if(this != NULL && nodeIndex >= 0 && (ll_len(this) > nodeIndex)){

    	auxNode = this->pFirstNode;

    	for(i=0;i<nodeIndex;i++){
    		auxNode = auxNode->pNextNode;
    	}
    }

    return auxNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
	Node* pNode = NULL;
	Node* auxNodeAnterior = NULL;
	Node* auxNodeSiguiente = NULL;
    int returnAux = -1;

    if(this != NULL && nodeIndex >= 0 && nodeIndex <= ll_len(this)){

    	pNode = (Node*) malloc(sizeof(Node));

    	if(pNode != NULL){

    		auxNodeSiguiente = getNode(this, nodeIndex);

			if(nodeIndex == 0){

				pNode->pElement = pElement;
				pNode->pNextNode = auxNodeSiguiente;
				this->size += 1;
				this->pFirstNode = pNode;
				returnAux = 0;

			}else{

				auxNodeAnterior = getNode(this, nodeIndex-1);
				pNode->pNextNode = auxNodeSiguiente;
				auxNodeAnterior->pNextNode = pNode;
				pNode->pElement = pElement;
				this->size += 1;
				returnAux = 0;

			}
    	}
    }
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if(this != NULL){

    	if(addNode(this,ll_len(this), pElement)==0){
    		returnAux = 0;
    	}
    }

    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* pNode = NULL;

    if(this != NULL && index >= 0 && index < ll_len(this)){

    	pNode = getNode(this,index);
    	if(pNode != NULL){
    		returnAux = pNode->pElement;
    	}

    }
    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
	Node* pNode = NULL;

	if(this != NULL && index >= 0 && index < ll_len(this)){

		pNode = getNode(this,index);
		if(pNode != NULL){
			pNode->pElement = pElement;
			returnAux = 0;
		}

	}
    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    Node* pNode = NULL;
    Node* auxNode = NULL;

    if(this != NULL && index >= 0 && index < ll_len(this)){

    	pNode = getNode(this,index);

    	if(pNode != NULL){

    		if(index == 0){
    			this->pFirstNode = NULL;
    			this->size -= 1;
    			free(pNode);
    			returnAux = 0;
    		}else{

    			auxNode = getNode(this, index -1);

				if(auxNode != NULL){

					if(pNode->pNextNode == NULL){
						auxNode->pNextNode = NULL;
						this->size -= 1;
						free(pNode);
						returnAux = 0;
					}else{
						auxNode->pNextNode = pNode->pNextNode;
						this->size -= 1;
						free(pNode);
						returnAux = 0;
					}
				}
    		}
       	}
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    int i;
    if(this != NULL){

    	for(i = ll_len(this)-1 ;i>-1;i--){

    		if(ll_remove(this, i)==0){
    			returnAux = 0;
    		}
    	}

    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL){
    	if(ll_clear(this)==0){
    		free(this);
    		returnAux = 0;
    	}
    }

    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int i;
    Node* pNode = NULL;

    if(this != NULL){

    	for(i=0;i<ll_len(this);i++){
    		pNode = getNode(this,i);

    		if(pNode != NULL){

    			if(pNode->pElement == pElement){
    				returnAux = i;
    				break;
    			}
    		}

    	}
    }
    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL){

    	if(this->pFirstNode != NULL){
    		returnAux = 0;
    	}else{
    		returnAux = 1;
    	}
    }
    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;
    //DEBERIA ESTAR MAL
    if(addNode(this,index, pElement)==0){
    	returnAux = 0;
    }
    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    Node* pNode = NULL;

    if(this != NULL){

    	pNode = getNode(this, index);
    	if(pNode != NULL){
    		returnAux = pNode->pElement;
    		ll_remove(this, index);
    	}
    }
    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    if(this != NULL){

    	if(ll_indexOf(this, pElement) > -1){
			returnAux = 1;
		}else{
			returnAux = 0;
		}

    }
    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 * usar contains
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    int i;

    void* pElementThis = NULL;
    void* pElementThis2 = NULL;

    if(this != NULL && this2 != NULL){

    	returnAux = 1;

		for(i=0;i < ll_len(this);i++){

			pElementThis = ll_get(this, i);
		    pElementThis2 = ll_get(this2,i);

			if(pElementThis2 != pElementThis){
				returnAux = 0;
				break;
			}
		}
    }
    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    int i;
    void* pAuxElement = NULL;
    if(this != NULL){
    	// && from != to && from < to
    	if(from >= 0 && to >= 0 && from <= ll_len(this) && to <= ll_len(this) && from < to){

    		cloneArray = ll_newLinkedList();

    		if(cloneArray != NULL){


    			for(i=from;i < to;i++){
    				//printf("Entro al clone array diferente a NULL");
    				pAuxElement = ll_get(this, i);

    				if(ll_add(cloneArray,pAuxElement)==-1){
    					printf("Sucedio un error\n");
    					cloneArray = NULL;
    					break;
    				}
    			}
    		}
    	}
    }
    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;
    void* pElement = NULL;
    int i;

    if(this != NULL){

    	cloneArray = ll_newLinkedList();

    	if(cloneArray != NULL){

    		for(i=0;i<ll_len(this);i++){

    			pElement = ll_get(this, i);
    			ll_add(cloneArray, pElement);
    		}
    	}
    }
    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux = -1;
    int tamLinkedlist = ll_len(this);
    int i,j;
    int retornoSort;
    void* pAuxElement = NULL;
    void* pElement1 = NULL;
    void* pElement2 = NULL;
    if(this != NULL && pFunc != NULL){

    	for(i=0;i < tamLinkedlist-1;i++){

    		for(j=i+1;j < tamLinkedlist;j++){

    			pElement1 = ll_get(this,i);

    			pElement2 = ll_get(this, j);

    			retornoSort = pFunc(pElement1,pElement2);

    			if(retornoSort == 1 && order == 1){
    				//ascendente
    				pAuxElement = pElement1;
    				if(ll_set(this,i,pElement2)==0){
    					if(ll_set(this,j,pAuxElement)==0){
    						returnAux = 0;
    					}
    				}
    			}else{
    				if(retornoSort == -1 && order == 0){
    					//descendente
    					pAuxElement = pElement1;
						if(ll_set(this,i,pElement2)==0){
							if(ll_set(this,j,pAuxElement)==0){
								returnAux = 0;
							}
						}
    				}
    			}
    		}
    	}
    }
    return returnAux;
}

/**
 * \fn int ll_map(LinkedList*, int(*)(void*))
 * \brief Modifica todos los elementos de la Linkedlist
 * con el criterio pasado
 *
 * \param this Puntero a la lista
 * \param pFunc Puntero a la funcion criterio
 * \return retorna -1 si la linkedlist es NULL o el Critero es NULL,
 * 1 en caso exitoso , 0 en caso de error
 */
int ll_map(LinkedList* this, int (*pFunc)(void*)){

	int returnAux = -1;
	int tamLinkedlist = ll_len(this);
	int i;
	void* pElement = NULL;
	if(this != NULL && pFunc != NULL){

		returnAux = 1;

		for(i=0;i<tamLinkedlist;i++){

			pElement = ll_get(this, i);
			if(pFunc(pElement)==0){
				returnAux = 0;
				break;
			}

		}
	}
	return returnAux;
}

