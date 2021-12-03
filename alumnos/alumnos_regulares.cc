#include "alumnos_regulares.h"
#include <iostream>

alumnos_regulares::alumnos_regulares() {
}

alumnos_regulares::alumnos_regulares(string _nombre, int _rut, int _numero_matricula){
    this->nombre=_nombre;
    this->rut=_rut;
    this->numero_matricula=_numero_matricula;
}


string alumnos_regulares::getnombre(){
    return this->nombre;
}

void alumnos_regulares::setnombre(string nombre_alum){
    this->nombre=nombre_alum;
}
  
int alumnos_regulares::getrut(){
    return this->rut;
}

void alumnos_regulares::setrut(int rut_alum){
    this->rut=rut_alum;
}

int alumnos_regulares::getnumero_matricula(){
    return this->numero_matricula;
}

void alumnos_regulares::setnumero_matricula(int num){
    this->numero_matricula=num;
}


int alumnos_regulares::get_ramos_inscritos(){
    return this->ramos_inscritos;
}

void alumnos_regulares::ingresar_ramos(ramos_regular_egresados _ramos){
    this->ramos[this->ramos_inscritos]=_ramos;
    this->ramos_inscritos=this->ramos_inscritos+1;
}

void alumnos_regulares::get_ramos(){
    for(int i=0;i<this->ramos_inscritos;i++){
        cout<<i+1<<") "<<this->ramos[i].getnombre_ramo()<<endl;
        cout<<"  ";
        ramos[i].get_notas();
        cout<<"\n";
    }
}

void alumnos_regulares::get_prom(){
    int suma=0;
    for(int i=0;i<this->ramos_inscritos;i++){
        suma=suma+this->ramos[i].get_promedio();
    }
    if(this->ramos_inscritos!=0){
        cout<<"Promedio: "<<suma/this->ramos_inscritos<<endl;
    }   
}

void alumnos_regulares::muestra_ramos(){
    for(int i=0;i<this->ramos_inscritos;i++){
        cout<<i+1<<") "<<this->ramos[i].getnombre_ramo()<<endl;
    }
}

void alumnos_regulares::ingresar_nota(int nota,int pos_ramo){
    this->ramos[pos_ramo].ingresar_notas(nota);
}

