#include "Listas.h"
#include <iostream>

Listas::Listas() {
    this->lista_alum_reg=NULL;
    this->lista_ramos_alum_regular_egresados=NULL;
}

Listas* Listas::instancia = 0;

Listas* Listas::getintance(){
        if(instancia==0){
            instancia=new Listas();
        };
        return instancia;
};

void Listas::ingresar_alumno_regular(alumnos_regulares alu_new){
    nodo_alum_regular *p=new nodo_alum_regular();
    p->alu=alu_new;
    nodo_alum_regular *aux1=this->lista_alum_reg; 
    nodo_alum_regular *aux2; 
    while((aux1!=NULL)&&(aux1->alu.getrut()<p->alu.getrut())){
        aux2=aux1;
        aux1=aux1->sig;
    }
    if(this->lista_alum_reg == aux1){
        this->lista_alum_reg = p;
    }
    else{
        aux2->sig=p;
        p->ant=aux2;
    }
    p->sig=aux1;
}

void Listas::imprimir_alu(){
    cout<<"nombre: "<<this->lista_alum_reg->alu.getnombre()<<endl;
    cout<<"rut: "<<this->lista_alum_reg->alu.getrut()<<endl;
    
}

int Listas::buscar_alumno_reg(int rut, int inicio, int fin){
    int medio=(inicio+fin)/2;
    nodo_alum_regular *aux=this->lista_alum_reg;
    if(inicio>fin){
        cout<<"no encontrado"<<endl;
        return 0;
    }
    for(int i=0; i<medio;i++){
        aux=aux->sig;
    }
    if(aux->alu.getrut()<rut){
        buscar_alumno_reg(rut,medio+1,fin);
    }
    else if(aux->alu.getrut()>rut){
        buscar_alumno_reg(rut,inicio,medio-1);
    }
    else {
        cout<<"nombre: "<<aux->alu.getnombre()<<endl;
        cout<<"rut: "<<aux->alu.getrut()<<endl;
        return medio;
    }
}

int Listas::largo_reg(){
    nodo_alum_regular *aux=this->lista_alum_reg;
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

void Listas::ingresar_ramo_alumno_regular(ramos_regular_egresados ramo_new){
    nodo_ramos_alum_regular_egresado *p=new nodo_ramos_alum_regular_egresado();
    p->ramo=ramo_new;
    nodo_ramos_alum_regular_egresado *aux1=this->lista_ramos_alum_regular_egresados; 
    nodo_ramos_alum_regular_egresado *aux2; 
    while((aux1!=NULL)&&(aux1->ramo.getnombre_ramo())<(p->ramo.getnombre_ramo())){
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

int Listas::largo_ramos_reg(){
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

ramos_regular_egresados Listas::obtener_ramo(int pos){
    nodo_ramos_alum_regular_egresado *aux=this->lista_ramos_alum_regular_egresados;
    for(int i=0;aux!=NULL&&i<pos-1;i++){
        aux=aux->sig;
    }
    return aux->ramo;
}

void Listas::iterator_siguiente(int pos){
    Listas *lista=getintance();
    for(int i=0;i<pos&&i<largo_reg();i++){
        lista->lista_alum_reg=lista->lista_alum_reg->sig;
    }
}

void Listas::iterator_anterior(int pos){
    Listas *lista=getintance();
    for(int i=0;i<pos&&lista->lista_alum_reg->ant!=NULL;i++){
        lista->lista_alum_reg=lista->lista_alum_reg->ant;
    }
}





