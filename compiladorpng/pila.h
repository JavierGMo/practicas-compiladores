typedef struct nodo{
	char data;
	//AFN *afnchido;
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
        printf("\nValor: %c\n", aux->data);
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
void borrarPila(Nodo *pila){
	Nodo *aux;
	while(pila){
		aux = pila;
		pila = pila->sig;
		free(aux);
	}
}