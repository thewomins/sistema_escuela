/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   tesis.cc
 * Author: Felipe
 * 
 * Created on 22 de octubre de 2018, 23:06
 */

#include "tesis.h"

tesis::tesis() {
}

string tesis::getprofesor_guia(){
    return profesor_guia;
}

void tesis::setprofesor_guia(string prof_guia) {
    profesor_guia = prof_guia;
}

string tesis::gettitulo(){
    return titulo;
}

void tesis::settitulo(string tit) {
    titulo = tit;
}
