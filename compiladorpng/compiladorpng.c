#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include "InfPost.h"

int main(int argc, char *argv[])
{
	//La expresion se pasa por consola ejemplo: "(a+v)*asd"
	char *pal = argv[1];
	char c;
	Nodo *pila = iniciarNodo(pila);
	Nodo *pilaAuxiliar = iniciarNodo(pilaAuxiliar);
	printf("%s\n", argv[0]);
	while (c=*pal++){
		//evaluar la expresion( si tiene o no parentesis
		if(parentesiSIzquierdo(c)){
			pilaAuxiliar = agregarAlInicio(pilaAuxiliar, c);
		}else if(parentesisDerecho(c)){
			/**
			 * a+b)
			 * recorremos la pila auxiliar y excluimos el parentesis izquierdo
			 * 
			*/
			while (!isEmpty(pilaAuxiliar)){
				if(top(pilaAuxiliar)!='(') pila = agregarAlInicio(pila, top(pilaAuxiliar));
				pilaAuxiliar = eliminarElemento(pilaAuxiliar);
			}
		}else{
			if(!operador(c)){
				pila = agregarAlInicio(pila, c);
			}else{
				pilaAuxiliar = agregarAlInicio(pilaAuxiliar, c);
			}
		}
		printf("caracter despues: %c\n", *(pal+1));
		if(!operador(*(pal+1)) && *(pal+1)!=NULL && !parentesisDerecho(*(pal+1)) ){
			pilaAuxiliar = agregarAlInicio(pilaAuxiliar, '.');
		}
	}
	while (!isEmpty(pilaAuxiliar)){
		if(!parentesiSIzquierdo(pilaAuxiliar->data)){
			pila = agregarAlInicio(pila, top(pilaAuxiliar));
		}
		pilaAuxiliar = eliminarElemento(pilaAuxiliar);
	}
	imprimirPila(pilaAuxiliar);
	imprimirPila(pila);
	free(pila);
	free(pilaAuxiliar);
	return 0;
}