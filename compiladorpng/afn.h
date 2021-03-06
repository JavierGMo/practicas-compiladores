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