
#include "alumnos_egresados.h"

alumnos_egresados::alumnos_egresados() {
}

string alumnos_egresados::getempresa_practica(){
    return this->empresa_practica;
}

void alumnos_egresados::setempresa_practica(string empresa_prac){
    this->empresa_practica=empresa_prac;
}

int alumnos_egresados::getfecha_egreso(){
    return this->fecha_egreso;
}

void alumnos_egresados::setfecha_egreso(int fecha_egres){
    this->fecha_egreso=fecha_egres;
}

int alumnos_egresados::getpromedio(){
    return this->promedio;
}

void alumnos_egresados::setpromedio(int prom){
    this->promedio= prom;
}

