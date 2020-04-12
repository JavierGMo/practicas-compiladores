#include <stdio.h>
#include <stdlib.h>
typedef struct baseafn{
    char inicio;
    char fin;
    char transicion;
    struct AFN *siguiente;
    struct AFN *anterior;
	struct AFN *arribaTransi;
	struct AFN *abajoTransi;
}AFN;

typedef struct nodo{
	char data;
	AFN *afnchido;
	struct Nodo *sig;
}Nodo;

Nodo *pilaGlobal = (Nodo*)malloc(sizeof(Nodo));
/*funciones afn*/
AFN *crearEdoUnaTransicion(char transicion){
    AFN *estado = (AFN*)malloc(sizeof(AFN));
	estado->transicion = transicion;
    return estado;
}
AFN *concatenacionEstado(Nodo *pila){
    //AFN *estadoConcatenado = (AFN*)malloc(sizeof(AFN));
	/*creamos otro afn para apuntar a la concatenacion de
		AfnBase = (Afn1->sig)->afn2
	*/
    AFN *afnAux = (AFN*)malloc(sizeof(AFN));
	AFN *auxAFN0 = pila->afnchido;
	//sacamos los dos elementos que hay en la pila
	Nodo *auxPilaSig = pila->sig;
	AFN *auxAFN1 = auxPilaSig->afnchido;
	auxAFN0->siguiente = auxAFN1;
	afnAux->siguiente = auxAFN0;
    return afnAux;
}

AFN *cerraduraPositiva(AFN *estado){
	/*
		afnprincipal;
		afnEpsionInicio->trans = e;
		afnEpsionInicio->sig = pila->afn;
		afnEpsionFinal->trans = e,
		afnEpsionFinal->sig = null
		afnEpsionFinal->ant = afnEpsionInicio->sig;
	*/
    AFN *afnPrincipal = (AFN*)malloc(sizeof(AFN));
	AFN *afnFinal = (AFN*)malloc(sizeof(AFN));
	afnPrincipal->transicion = 'E';
	afnFinal->transicion = 'E';
	afnPrincipal->siguiente = estado;
	estado->siguiente = afnFinal;
	afnFinal->siguiente = NULL;
	afnFinal->anterior = estado;
    return afnPrincipal;
}

AFN *cerraduraEstrella(AFN *estado){
    AFN *afnPrincipal = (AFN*)malloc(sizeof(AFN));
	AFN *afnMedio = (AFN*)malloc(sizeof(AFN));
	AFN *afnFinal = (AFN*)malloc(sizeof(AFN));
	afnPrincipal->transicion = 'E';
	afnMedio->transicion = 'E';
	afnFinal->transicion = 'E';
	afnPrincipal->siguiente = estado;
	afnPrincipal->abajoTransi = NULL;
	estado->siguiente = afnFinal;
	afnFinal->siguiente = NULL;
	afnFinal->arribaTransi = estado;
    return afnPrincipal;
}

AFN *pipe(AFN *estadoUno, AFN *estadoDos){
    AFN *tuberiaInicial = (AFN*)malloc(sizeof(AFN));
	AFN *tuberiaFinalUp = (AFN*)malloc(sizeof(AFN));
	AFN *tuberiaFinalDown = (AFN*)malloc(sizeof(AFN));
	tuberiaInicial->transicion = 'E';
	tuberiaInicial->arribaTransi = estadoUno;
	tuberiaInicial->arribaTransi = estadoDos;
	tuberiaFinalUp->transicion = 'E';
	tuberiaFinalDown->transicion = 'E';
	estadoUno->siguiente = tuberiaFinalUp;
	estadoDos->siguiente = tuberiaFinalDown;
	tuberiaFinalUp->siguiente = NULL;
	tuberiaFinalDown->siguiente = NULL;
    return tuberiaInicial;
}

/*fin funciones afn*/
Nodo *agregarAFNAPila(Nodo *pila, AFN *afnd){
    //aun no se crea el afns
	Nodo *nuevo = (Nodo*)malloc(sizeof(Nodo));
	nuevo->afnchido = afnd;
	nuevo->sig = pila;
	return nuevo;
}
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
/*Agreagar el peso de los operadoress*/
int parentesiSIzquierdo(char e){
    return e == '(';
}
int parentesisDerecho(char e){
    return e == ')';
}
int operador(char e){
    return e== '|' || e=='+' ||e=='*' || e=='^' ||  e=='/'  || e=='-';
}
char agregarPunto(){
    return '.';
}
int hacerRecorridoAFN(Nodo *pila){
	AFN *auxAFN = pila->afnchido;
	AFN *auxAFNs;
	int i = 0;
	if(isEmpty(pila)){
		i = 0;
	}else{
		if(auxAFN->siguiente != NULL){
			auxAFNs = auxAFN->siguiente;
			pilaGlobal = iniciarNodo(pilaGlobal);
			pilaGlobal = agregarAlInicio(pilaGlobal, auxAFNs->transicion);
			hacerRecorridoAFN(pila->sig);
			i = 1;
		}
	}
	return i;
}
int main(int argc, char *argv[])
{
	//La expresion se pasa por consola ejemplo: "(a+v)*asd"
	char *pal = argv[1], c;
	Nodo *pila = iniciarNodo(pila);
	Nodo *pilaAuxiliar = iniciarNodo(pilaAuxiliar);
	Nodo *pilaAFNs = iniciarNodo(pilaAFNs);
    Nodo *auxPila = iniciarNodo(auxPila);
	while (c=*pal++){
		if(parentesiSIzquierdo(c)){
			pilaAuxiliar = agregarAlInicio(pilaAuxiliar, c);
		}else if(parentesisDerecho(c)){
			while (!isEmpty(pilaAuxiliar)){
				if(top(pilaAuxiliar)!='('){
					pila = agregarAlInicio(pila, top(pilaAuxiliar));
				}
				pilaAuxiliar = eliminarElemento(pilaAuxiliar);
			}
		}else{
			if(!operador(c)){
				pila = agregarAlInicio(pila, c);
                pilaAFNs = agregarAFNAPila(pilaAFNs, crearEdoUnaTransicion(c) );
			}
			else{
                switch (c){
                    case '.':
                        //pilaAFNs = agregarAFNAPila(pilaAFNs, concatenacionEstado(pilaAFNs));
                        break;
                    case '*':
                        //pilaAFNs = agregarAFNAPila(pilaAFNs, cerraduraEstrella(pilaAFNs->afnchido));
                        break;
                    case '+':
                        //pilaAFNs = agregarAFNAPila(pilaAFNs, cerraduraPositiva(pilaAFNs->afnchido));
                        break;
					case '|':
						//auxPila = pilaAFNs->sig;
                        //pilaAFNs = agregarAFNAPila(pilaAFNs, pipe(pilaAFNs->afnchido, auxPila->afnchido));
                        break;
                    default:
                        printf("Ningun simbolo xD");
                        break;
                }
				pilaAuxiliar = agregarAlInicio(pilaAuxiliar, c);
			}
		}
		if(!parentesiSIzquierdo(c) && *pal!=NULL && !operador(*pal) && !parentesisDerecho(*pal)){
			if(c!='|'){
				//evitamos que despues del pipe se concatene porque este actua como un or
				pilaAuxiliar = agregarAlInicio(pilaAuxiliar, '.');
			}
		}
	}

	//Vaciar la pila auxiliar
	while (!isEmpty(pilaAuxiliar)){
		if(!parentesiSIzquierdo(pilaAuxiliar->data)){
			/*
			switch (pilaAuxiliar->data){
                    case '.':
                        pilaAFNs = agregarAFNAPila(pilaAFNs, concatenacionEstado(pilaAFNs));
                        break;
                    case '*':
                        pilaAFNs = agregarAFNAPila(pilaAFNs, cerraduraEstrella(pilaAFNs->afnchido));
                        break;
                    case '+':
                        pilaAFNs = agregarAFNAPila(pilaAFNs, cerraduraPositiva(pilaAFNs->afnchido));
                        break;
					case '|':
						auxPila = pilaAFNs->sig;
                        pilaAFNs = agregarAFNAPila(pilaAFNs, pipe(pilaAFNs->afnchido, auxPila->afnchido));
                        break;
                    default:
                        printf("Ningun simbolo xD");
                        break;
            }*/
			pila = agregarAlInicio(pila, top(pilaAuxiliar));
		}
		pilaAuxiliar = eliminarElemento(pilaAuxiliar);
	}



	printf("Top: %c", top(pila));




	imprimirPila(pila);
	borrarPila(pila);
	borrarPila(pilaAuxiliar);
	borrarPila(pilaAFNs);
	/*free(pila);
	free(pilaAuxiliar);*/
	return 0;
}