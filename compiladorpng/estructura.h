typedef struct baseafn{
    char inicio;
    char fin;
    char transicion;
    struct AFN *siguiente;
    struct AFN *anterior;
    struct AFN *sigInicial;
    struct AFN *sigFinal;
    //Para el pipe
    struct AFN *pipeRamaUpIni;
    struct AFN *pipeRamaDownIni;
    struct AFN *pipeRamaUpFin;
    struct AFN *pipeRamaDownFin;
}AFN;
typedef struct nodo{
	char data;
	struct AFN *afnchido;
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
//Fin pila
AFN *crearEdoUnaTransicion(AFN *estado, char transicion){
    estado = (AFN*)malloc(sizeof(AFN));
    estado->transicion = transicion;
    estado->siguiente = NULL;
    estado->sigFinal = NULL;
    estado->sigFinal = NULL;
    estado->pipeRamaUpIni = NULL;
    estado->pipeRamaUpFin = NULL;
    estado->pipeRamaDownIni = NULL;
    estado->pipeRamaDownFin = NULL;
    return estado;
}
AFN *concatenacionEstado(AFN *estadoUno, AFN *estadoDos){
    AFN *estadoConcatenado = (AFN*)malloc(sizeof(AFN));
    estadoUno->sigInicial = estadoDos;
    estadoConcatenado->sigInicial = estadoUno;
    estadoConcatenado->sigFinal = NULL;
    estadoConcatenado->siguiente = NULL;
    estadoConcatenado->pipeRamaUpIni = NULL;
    estadoConcatenado->pipeRamaUpFin = NULL;
    estadoConcatenado->pipeRamaDownIni = NULL;
    estadoConcatenado->pipeRamaDownFin = NULL;
    return estadoConcatenado;
}
AFN *cerraduraPositiva(AFN *estado){
    AFN *estadoCerradura = (AFN*)malloc(sizeof(AFN));
    estadoCerradura->transicion = 'E';
    estadoCerradura->siguiente = estado;
    estadoCerradura->sigFinal = NULL;
    estado->sigFinal = estadoCerradura->sigFinal;
    estadoCerradura->sigFinal = estado;
    estadoCerradura->pipeRamaUpIni = NULL;
    estadoCerradura->pipeRamaUpFin = NULL;
    estadoCerradura->pipeRamaDownIni = NULL;
    estadoCerradura->pipeRamaDownFin = NULL;
    return estadoCerradura;
}
AFN *cerraduraEstrella(AFN *estado){
    AFN *estadoCerradura = (AFN*)malloc(sizeof(AFN));
    /*Transicion inicial*/
    AFN *auxEpsilon = (AFN*)malloc(sizeof(AFN));
    auxEpsilon->transicion = 'E';
    auxEpsilon->sigInicial = NULL;
    auxEpsilon->siguiente = NULL;
    auxEpsilon->sigFinal = NULL;
    /*final del auxiliar de auxEpsilon*/
    estadoCerradura->transicion = 'E';
    estadoCerradura->siguiente = estado;
    estadoCerradura->sigFinal = NULL;
    estado->sigFinal = estadoCerradura->sigFinal;
    estadoCerradura->sigFinal = estado;
    /*Para enlazar el principio del estado con el final*/
    auxEpsilon->sigInicial = estadoCerradura->sigInicial;
    auxEpsilon->sigFinal = estadoCerradura->sigFinal;
    estadoCerradura->pipeRamaUpIni = NULL;
    estadoCerradura->pipeRamaUpFin = NULL;
    estadoCerradura->pipeRamaDownIni = NULL;
    estadoCerradura->pipeRamaDownFin = NULL;
    return auxEpsilon;
}
AFN *pipe(AFN *estadoUno, AFN *estadoDos){
    AFN *tuberia = (AFN*)malloc(sizeof(AFN));
    tuberia->pipeRamaUpIni = estadoUno;
    tuberia->pipeRamaDownIni = estadoDos;
    estadoUno->pipeRamaUpIni = tuberia->pipeRamaUpFin;
    estadoDos->pipeRamaDownFin = tuberia->pipeRamaDownFin;
    tuberia->sigInicial = NULL;
    tuberia->sigFinal = NULL;
    tuberia->siguiente = NULL;
    return tuberia;
}
Nodo *agregarAFN(Nodo *pila, AFN *afnd){
	Nodo *nuevo = (Nodo*)malloc(sizeof(Nodo));
	nuevo->afnchido = afnd;
	nuevo->sig = pila;
	return nuevo;
}
//fin afd