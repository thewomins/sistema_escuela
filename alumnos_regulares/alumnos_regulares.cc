/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   alumnos_regulares.cc
 * Author: Felipe
 * 
 * Created on 22 de octubre de 2018, 22:45
 */

#include "alumnos_regulares.h"
#include <iostream>

alumnos_regulares::alumnos_regulares() {
}

string alumnos_regulares::getnombre(){
    return nombre;
}

void alumnos_regulares::setnombre(string nombre_alum){
    nombre=nombre_alum;
}
  
string alumnos_regulares::getrut(){
    return rut;
}

void alumnos_regulares::setrut(string rut_alum){
    rut=rut_alum;
}

int alumnos_regulares::getnumero_matricula(){
    return numero_matricula;
}

int alumnos_regulares::generador_num_matricula(){
    
}
