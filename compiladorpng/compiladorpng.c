#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include "InfPost.h"

int main(int argc, char *argv[])
{
	//La expresion se pasa por consola ejemplo: "(a+v)*asd"
	char *pal = argv[1], c;
	Nodo *pila = iniciarNodo(pila);
	Nodo *pilaAuxiliar = iniciarNodo(pilaAuxiliar);
	//Nodo *pilaAFNs = iniciarNodo(pilaAFNs);
	while (c=*pal++){
		//printf("car: %c c: %c d:%d \n", c, *pal, *pal==NULL);
		//evaluar la expresion( si tiene o no parentesis
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
				//pilaAFNs->afnchido = crearEdoUnaTransicion(pilaAFNs->afnchido, c);
			}
			else{
				pilaAuxiliar = agregarAlInicio(pilaAuxiliar, c);
			}
		}
		/**
		 * revisamos si el c contiene un parentesis izquierdo porque despues de ese parentesis sigue un caracter y se agregaria un punto 
		 * se veria algo como lo siguiente: sabiendo que c contiene al caracter actual que es ( y *pal=al siguente
		 * *pal es un caracter es diferente de null, no es un operador y no es un paretesis derecho entra a la condicion
		 * caso contrario seria como:
		 * c (actual caracter ) es paretesis izquierdo si, no entra al ciclo
		 * lo que se trata de describir es que despues de cada parIzq siempre va a meter un punto y no es lo que se quiere, de aguna manera se puede decir que 
		 * vemos un paso adelante del arreglo pal
		*/
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
			pila = agregarAlInicio(pila, top(pilaAuxiliar));
		}
		pilaAuxiliar = eliminarElemento(pilaAuxiliar);
	}



	printf("Top: %c", top(pila));




	imprimirPila(pila);
	borrarPila(pila);
	borrarPila(pilaAuxiliar);
	/*free(pila);
	free(pilaAuxiliar);*/
	return 0;
}