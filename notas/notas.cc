#include "notas.h"
#include <iostream>

notas::notas() {
    this->lista_notas=NULL;
}

int notas::getnota(){
    return this->nota;
}

void notas::setnota(int ing_notas) {
    this->nota=ing_notas;
}

int notas::largo_lista(){
    nodo_notas *aux=this->lista_notas;
    int contador=1;
    if(aux==NULL){
        return 0;
    }
    while(aux->sig!=NULL){
        contador++;
        aux=aux->sig;
    }
    return contador;
}

void notas::iterator_siguiente(int pos){
    nodo_notas *lista = this->lista_notas;
    for(int i=0; i < pos && i < largo_lista(); i++){
        lista = lista->sig;
    }
}

void notas::iterator_anterior(int pos){
    nodo_notas *lista = this->lista_notas;
    for(int i=0; i<pos && lista->ant!=NULL; i++){
        lista = lista->ant;
    }
}