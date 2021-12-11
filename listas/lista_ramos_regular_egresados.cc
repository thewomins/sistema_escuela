#include "lista_ramos_regular_egresados.h"
#include <iostream>
using namespace std;

Lista_ramos_regular::Lista_ramos_regular() {
    this->lista_ramos_alum_regular_egresados=NULL;
}

void Lista_ramos_regular::ingresar_ramo_alumno_regular(ramos_regular_egresados *ramo_new){
    nodo_ramos_alum_regular_egresado *p=new nodo_ramos_alum_regular_egresado();
    p->ramo=ramo_new;
    nodo_ramos_alum_regular_egresado *aux1=this->lista_ramos_alum_regular_egresados; 
    nodo_ramos_alum_regular_egresado *aux2; 
    while((aux1!=NULL)){
        aux2=aux1;
        aux1=aux1->sig;
    }
    if(this->lista_ramos_alum_regular_egresados == aux1){
        this->lista_ramos_alum_regular_egresados = p;
    }
    else{
        aux2->sig=p;
    }
    p->sig=aux1;
}

int Lista_ramos_regular::largo_ramos_reg(){
    nodo_ramos_alum_regular_egresado *aux=this->lista_ramos_alum_regular_egresados;
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

void Lista_ramos_regular::imprimir_datos_ramos(){
    nodo_ramos_alum_regular_egresado *aux=this->lista_ramos_alum_regular_egresados;
    for(int i = 0; i<largo_ramos_reg(); i++){
        cout<<"nombre ramo "<<i<<": "<<aux->ramo->getnombre_ramo()<<endl;
        cout<<"nombre carrera "<<i<<": "<<aux->ramo->getnombre_carrera()<<endl;
        cout<<"numero semestre "<<i<<": "<<aux->ramo->getnumero_semestre()<<endl;
        cout<<"------------------------------------------------------------"<<endl;
        aux=aux->sig;
    }
}

ramos_regular_egresados* Lista_ramos_regular::buscar_ramo(string nombre){
    nodo_ramos_alum_regular_egresado *aux=this->lista_ramos_alum_regular_egresados;

    for(int i=0; i<largo_ramos_reg(); i++){
        if( nombre.compare(aux->ramo->getnombre_ramo()) == 0){
            cout<<"------------------------------------------------------------"<<endl;
            cout<<"Encontrado"<<endl;
            cout<<"nombre: "<<aux->ramo->getnombre_ramo()<<endl;
            cout<<"rut: "<<aux->ramo->getnombre_carrera()<<endl;
            cout<<"------------------------------------------------------------"<<endl;
            return aux->ramo;
        }
        aux = aux->sig;
    }
    return nullptr;
}

ramos_regular_egresados* Lista_ramos_regular::obtener_ramo(int pos){
    nodo_ramos_alum_regular_egresado *aux=this->lista_ramos_alum_regular_egresados;
    for(int i=0;aux!=NULL&&i<pos-1;i++){
        aux=aux->sig;
    }
    return aux->ramo;
}

void Lista_ramos_regular::iterator_siguiente(int pos){
    nodo_ramos_alum_regular_egresado *lista=this->lista_ramos_alum_regular_egresados;
    for(int i=0;i<pos&&i<largo_ramos_reg();i++){
        lista=lista->sig;
    }
}

void Lista_ramos_regular::iterator_anterior(int pos){
    nodo_ramos_alum_regular_egresado *lista=this->lista_ramos_alum_regular_egresados;
    for(int i=0; i<pos&&lista->ant!=NULL; i++){
        lista=lista->ant;
    }
}