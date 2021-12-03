#include "ramos_regular_egresados.h"
#include <iostream>

ramos_regular_egresados::ramos_regular_egresados() {
}

ramos_regular_egresados::ramos_regular_egresados(string _nombre_ramo, string _nombre_carrera, int _numero_semestre) {
    this->nombre_ramo=_nombre_ramo;
    this->nombre_carrera=_nombre_carrera;
    this->numero_semestre=_numero_semestre;
}

string ramos_regular_egresados::getnombre_ramo(){
    return this->nombre_ramo;
}
void ramos_regular_egresados::setnombre_ramo(string nombre_ram){
    this->nombre_ramo=nombre_ram;
}

string ramos_regular_egresados::getnombre_carrera(){
    return this->nombre_carrera;
}

void ramos_regular_egresados::setnombre_carrera(string nombre_carr){
    this->nombre_carrera=nombre_carr;
}

int ramos_regular_egresados::getnumero_semestre(){
    return this->numero_semestre;
}

void ramos_regular_egresados::setnumero_semestre(int numero_sem){
    this->numero_semestre = numero_sem;
}

void ramos_regular_egresados::ingresar_notas(int _notas){
    this->nota[this->cantidad_notas].setnota(_notas);
    this->cantidad_notas=this->cantidad_notas+1;
}

void ramos_regular_egresados::get_notas(){
    for(int i=0;i<this->cantidad_notas;i++){
        cout<<" "<<this->nota[i].getnota();
    }
}

int ramos_regular_egresados::get_promedio(){
    int suma=0;
    for(int i=0;i<this->cantidad_notas;i++){
        suma=suma+this->nota[i].getnota();
    }
    if(this->cantidad_notas!=0){
        return suma/this->cantidad_notas;
    }
    else{
        return 0;
    } 
}

int ramos_regular_egresados::get_cantidad_notas(){
    return this->cantidad_notas;
}