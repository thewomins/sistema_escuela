#include "Lista_alum_regular.h"
#include <iostream>

Lista_alumno_regular::Lista_alumno_regular() {
    this->lista_alum_reg=NULL;
}

Lista_alumno_regular* Lista_alumno_regular::instancia = 0;

Lista_alumno_regular* Lista_alumno_regular::getintance(){
        if(instancia==0){
            instancia=new Lista_alumno_regular();
        };
        return instancia;
};

void Lista_alumno_regular::ingresar_alumno_regular(alumnos_regulares alu_new){
    if(validar_alumno(alu_new)==1){
        try{
            nodo_alum_regular *p=new nodo_alum_regular(); //crea nodo p 
            p->alumno = &alu_new; //asigna alumno al nodo 
            nodo_alum_regular *aux1= this->lista_alum_reg; //asigna la lista a aux1
            nodo_alum_regular *aux2; 
            while((aux1!=NULL) && (aux1->alumno->getrut() < p->alumno->getrut())){ //mientra la lista no sea nula y el ultimo rut sea menor al rut a ingrasar
                aux2 = aux1; //asigna lista a aux2
                aux1 = aux1->sig; //lista se va al siguente elemento busca donde posisionar rut
            }
            if(this->lista_alum_reg == aux1){ //si la lista == a nulo o no hay elemntos en la lista
                this->lista_alum_reg = p; // asigna el nodo creado a la lista
            }
            else{ //si ya existen elementos en la lista
                aux2->sig = p; //asigna el nodo creado a el siguiente en la lista
                p->ant = aux2; //asigna el nodo anterior de la lista al puntero anterir del nodo
            }
            p->sig = aux1; //asigna null si es ultimo o el resto de la lista si no lo es
            cout<<"Alumno creado correctamente"<<endl;
        }
        catch(...){
            cout<<"Error al crear nuevo alumno"<<endl;
        }  
    }else{
        cout<<"El rut ya existe"<<endl;
    }
}

int Lista_alumno_regular::validar_alumno(alumnos_regulares alu_new){
    nodo_alum_regular *aux = this->lista_alum_reg;
    int esta =1;
    if(buscar_alumno_reg(alu_new.getrut(),0,this->largo_lista()-1)==nullptr){
        esta=0;
    }
    if(esta==0){
        return 1;
    }else{
        return 0;
    }
}

void Lista_alumno_regular::imprimir_lista_completa(){
    nodo_alum_regular *aux = this->lista_alum_reg;
    for(int i=0; i<this->largo_lista(); i++){
        cout<<"------------------------------------------------------------"<<endl;
        cout<<"alumno "<<i+1<<": "<<endl;
        cout<<"nombre: "<<aux->alumno->getnombre()<<endl;
        cout<<"rut: "<<aux->alumno->getrut()<<endl;
        cout<<"matricula: "<<aux->alumno->getnumero_matricula()<<endl;
        aux=aux->sig;
    }
}

alumnos_regulares* Lista_alumno_regular::buscar_alumno_reg(int rut, int inicio, int fin){
    int medio=(inicio+fin)/2;
    nodo_alum_regular *aux=this->lista_alum_reg;
    if(inicio>fin){
        cout<<"no encontrado"<<endl;
        return nullptr;
    }
    for(int i=0; i<medio;i++){
        aux=aux->sig;
    }
    if(aux->alumno->getrut()<rut){
        buscar_alumno_reg(rut,medio+1,fin);
    }
    else if(aux->alumno->getrut()>rut){
        buscar_alumno_reg(rut,inicio,medio-1);
    }
    else {
        cout<<"------------------------------------------------------------"<<endl;
        cout<<"Encontrado"<<endl;
        cout<<"nombre: "<<aux->alumno->getnombre()<<endl;
        cout<<"rut: "<<aux->alumno->getrut()<<endl;
        cout<<"------------------------------------------------------------"<<endl;
        return aux->alumno;
    }
}

int Lista_alumno_regular::largo_lista(){
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

void Lista_alumno_regular::iterator_siguiente(int pos){
    Lista_alumno_regular *lista=getintance();
    for(int i=0;i<pos&&i<largo_lista();i++){
        lista->lista_alum_reg=lista->lista_alum_reg->sig;
    }
}

void Lista_alumno_regular::iterator_anterior(int pos){
    Lista_alumno_regular *lista=getintance();
    for(int i=0;i<pos&&lista->lista_alum_reg->ant!=NULL;i++){
        lista->lista_alum_reg=lista->lista_alum_reg->ant;
    }
}