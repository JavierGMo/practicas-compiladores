typedef struct nodo{
	char data;
	struct Nodo *sig;
}Nodo;

Nodo *iniciarNodo(Nodo *pila){
	pila = NULL;
	return pila;
}

Nodo *agregarAlInicio(Nodo *pila, char caracter){
	Nodo *nuevo = (Nodo*)malloc(sizeof(Nodo));
	nuevo->data = caracter;
	nuevo->sig = pila;
	return nuevo;
}
/*Nodo *agregarAlFinal(Nodo *pila, char caracter){
	Nodo *nuevoNodo = (Nodo*)malloc(sizeof(Nodo)), *tmp;
	if(nuevoNodo != NULL){
		nuevoNodo->data = caracter;
		nuevoNodo->sig = NULL;
		//Si la pila esta vacia
		if(pila == NULL)
			pila = nuevoNodo;
		else{
			//Agregar al final
			tmp = pila;
			while(tmp->sig != NULL)
				tmp = tmp->sig;
			tmp->sig = nuevoNodo;
		}
	}else
		printf("Memoria llena\n");

	return pila;
}*/
void imprimirPila(Nodo *pila){
	Nodo *aux = pila;
	while(aux){
		//printf("caracter: %c, dir: %p\n", aux->data, aux->sig);
        printf("Valor: %c\n", aux->data);
		aux = aux->sig;
	}
}
Nodo *eliminarElemento(Nodo *pila){
	Nodo *tmp = (Nodo*)malloc(sizeof(Nodo));
	tmp = pila->sig;
	free(pila);
	return tmp;
}
char top(Nodo *pila){
    return pila->data;
}
int isEmpty(Nodo *pila){
    return pila == NULL;
}
/*Nodo *eliminarElemento(Nodo *pila){
	Nodo *aux;
	if(pila == NULL){
		printf("La pila esta vacia...");
	}else{
		aux = pila;
		if(aux->sig!=NULL){
			aux->ant = aux;
			while (aux->sig != NULL){
				aux = aux->sig;
			}
			free(aux);
			aux->ant = NULL;
		}else{
			pila = NULL;
		}
	}
	return pila;
}*/
/*Nodo *eliminarElementoFinal(Nodo *pila){
	Nodo *aux;
	if(pila == NULL){
		printf("La pila esta vacia...");
	}else{
		aux = pila;
		if(aux->sig!=NULL){
			while ((aux->sig)->sig != NULL){
				aux = aux->sig;
			}
			free(aux->sig);
			aux->sig = NULL;
		}else{
			pila = NULL;
		}
	}
	return pila;
}*/