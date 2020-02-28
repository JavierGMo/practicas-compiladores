typedef struct base{
	char inicio;
	char fin;
	char transiscion;
    struct BASE *sigInicial;
    struct BASE *sigFinal;
	struct BASE *autoBase;
	struct BASE *sigEps;
	struct BASE *antEps;
    //Para el pipe
    struct BASE *sigRamaArriba;
	struct BASE *sigRamaAbajo;
	struct BASE *sigRamaFinArriba;
	struct BASE *sigRamaFinAbajo;
	struct PIPE *sigPipe;
}BASE;
typedef struct pipe{
	char inicio;
	char fin;
	char transiscion;
	struct BASE *sigRamaArriba;
	struct BASE *sigRamaAbajo;
	struct BASE *sigRamaFinArriba;
	struct BASE *sigRamaFinAbajo;
}PIPE;
BASE *crearEstadoUnaTransiscion(BASE *estadoUnaTransiscion, char transicion){
    estadoUnaTransiscion = (BASE*)malloc(sizeof(BASE));
    estadoUnaTransiscion->transiscion = transicion;
    return estadoUnaTransiscion;
}
BASE *concatenacionEstados(BASE *estadoUno, BASE *estadoDos){
    BASE *estadoConcatenado = (BASE*)malloc(sizeof(BASE));
    estadoUno->sigEps = estadoDos;
    estadoConcatenado->sigEps = estadoUno;
    return estadoConcatenado;
}
BASE *crearPipe(BASE *tuberia, BASE *estadoArriba, BASE *estadoAbajo, char numeroDeEstadoInicio, char numeroDeEstadofinal){
    BASE *sigArr = (BASE*)malloc(sizeof(BASE));
    BASE *sigAba = (BASE*)malloc(sizeof(BASE));
    BASE *finalPipe = (BASE*)malloc(sizeof(BASE));
    tuberia = (BASE*)malloc(sizeof(BASE));
    tuberia->transiscion = 'e';
    /*
                rama arriba
    --inicio-->tuberia--Epsi-->edoArriba
    --inicio-->tuberia--Epsi-->edoAbajo
    */
    tuberia->sigRamaArriba = estadoArriba;
    tuberia->sigRamaAbajo = estadoAbajo;
    /*
    edoArribaSig---Epsi--->tuberia--Epsi-->ramaArriba
    edoAbajoSig---Epsi--->tuberia--Epsi-->ramaAbajo
    */
    estadoArriba->sigPipe = tuberia->sigRamaFinArriba;
    estadoAbajo->sigPipe = tuberia->sigRamaFinAbajo;
    /*
        edoFinal
        e--Eps-->e--->edoFinal
        e--Eps-->e--->edoFinal
    */
    tuberia->sigRamaFinArriba = finalPipe;
    tuberia->sigRamaFinAbajo = finalPipe;
    return tuberia;
}
BASE *crearCerraduraEstrella(BASE *estado){
    BASE *cerradura = (BASE*)malloc(sizeof(BASE));
    cerradura->transiscion = 'e';
    cerradura->sigInicial = estado;
    cerradura->sigFinal = cerradura->sigInicial;
    estado->sigFinal = cerradura->sigFinal;
    return cerradura;
}
BASE *crearCerraduraEstrella(BASE *estado){
    BASE *cerradura = (BASE*)malloc(sizeof(BASE));
    cerradura->transiscion = 'e';
    cerradura->sigRamaArriba = estado;
    cerradura->sigInicial = NULL;
    cerradura->sigFinal = cerradura->sigInicial;
    estado->sigFinal = cerradura->sigFinal;
    cerradura->sigRamaFinAbajo = NULL;
    return cerradura;
}