#include <stdio.h>
#include <stdlib.h>
typedef struct nodo{
    char simbolo;
    struct Nodo *nodo;
}Nodo;

Nodo *agregarElemento(Nodo *pila);

int main(){
    Nodo *pila = NULL;
    printf("hola:");
    printf("hola: %p", pila);
    return 0;
}

Nodo *agregarElemento(Nodo *pila){
    Nodo *nuevoElemento = (Nodo*)malloc(sizeof(Nodo));
    Nodo *auxNodo = (Nodo*)malloc(sizeof(Nodo));
    nuevoElemento->simbolo = 'c';
    nuevoElemento->nodo = NULL;
    if(pila==NULL){
        pila = nuevoElemento;
    }else{
    }
    return pila;
}

