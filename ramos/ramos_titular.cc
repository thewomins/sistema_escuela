#include "ramos_titular.h"
#include <iostream>

ramos_titular::ramos_titular() {
}

ramos_titular::ramos_titular(string _nombre_ramo, string _nombre_carrera, int _numero_semestre, string _nombre_area_ramo, string _empresa_aus, string _unidad_dicta) {
    this->setnombre_ramo(_nombre_ramo);
    this->setnombre_carrera(_nombre_carrera);
    this->setnumero_semestre(_numero_semestre);
    this->nombre_area_ramo = _nombre_area_ramo;
    this->nombre_empresa_auspiciadora = _empresa_aus;
    this->unidad_dicta_ramo = _unidad_dicta;
}

string ramos_titular::getnombre_area_ramo(){
    return this->nombre_area_ramo;
}

void ramos_titular::setnombre_area_ramo(string nombre_area_ram) {
    this->nombre_area_ramo = nombre_area_ram;
}

string ramos_titular::getnombre_empresa_auspiciadora(){
    return this->nombre_empresa_auspiciadora;
}

void ramos_titular::setnombre_empresa_auspiciadora(string nombre_empresa_ausp) {
    this->nombre_empresa_auspiciadora = nombre_empresa_ausp;
}

string ramos_titular::getunidad_dicta_ramo(){
    return this->unidad_dicta_ramo;
}

void ramos_titular::setunidad_dicta_ramo(string unidad_dicta_ram) {
    this->unidad_dicta_ramo = unidad_dicta_ram;
}

/*void ramos_titular::ingresar_notas_tit(int _notas){
    this->nota_tit[this->cantidad_notas].setnota(_notas);
    this->cantidad_notas=this->cantidad_notas+1;
}

int ramos_titular::get_notas_tit(){
    for(int i=0;i<this->cantidad_notas;i++){
        cout<<" "<<this->nota_tit[i].getnota()<<" ";
    }
    return 0;
}*/
