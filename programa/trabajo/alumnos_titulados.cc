#include "alumnos_titulados.h"
#include <iostream>

alumnos_titulados::alumnos_titulados() {
}
int alumnos_titulados::getano_titulacion(){
    return this->ano_titulacion;
}

void alumnos_titulados::setano_titulacion(int ano_tit) {
    this->ano_titulacion = ano_tit;
}

string alumnos_titulados::getempresa_actual(){
    return this->empresa_actual;
}

void alumnos_titulados::setempresa_actual(string empresa_act) {
    this->empresa_actual = empresa_act;
}

void alumnos_titulados::ingresar_ramos_tit(ramos_titular _ramos){
    this->ramos_tit[this->ramos_inscritos]=_ramos;
    this->ramos_inscritos=this->ramos_inscritos+1;
}

void alumnos_titulados::get_ramos_tit(){
    for(int i=0;i<this->ramos_inscritos;i++){
        cout<<i+1<<") "<<ramos_tit[i].getnombre_ramo()<<"     ";
        ramos_tit[i].get_notas_tit();
        cout<<"\n";
    }
}

int alumnos_titulados::get_numero_ramos_inscritos_tit(){
    return this->ramos_inscritos;
}

void alumnos_titulados::get_ramos_tit_1(){
    for(int i=0;i<this->ramos_inscritos;i++){
        cout<<i+1<<") "<<ramos_tit[i].getnombre_ramo()<<endl;
    }
}

void alumnos_titulados::ingresar_nota_tit(int nota,int pos_ramo){
    this->ramos_tit[pos_ramo].ingresar_notas_tit(nota);
}

void alumnos_titulados::set_tesis(string titulo, string profesor_guia){
    this->_tesis.settitulo(titulo);
    this->_tesis.setprofesor_guia(profesor_guia);
}

void alumnos_titulados::get_tesis(){
    cout<<"Titulo: "<<this->_tesis.gettitulo()<<endl;
    cout<<"Profesor guia: "<<this->_tesis.getprofesor_guia()<<endl;
}

void alumnos_titulados::get_prom_tit(){
    int suma=0;
    for(int i=0;i<this->ramos_inscritos;i++){
        suma=suma+this->ramos_tit[i].get_promedio_tit();
    }
    if(this->ramos_inscritos!=0){       
        cout<<"Promedio: "<<suma/this->ramos_inscritos<<endl;
    }
}