/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   tesis.h
 * Author: Felipe
 *
 * Created on 22 de octubre de 2018, 23:06
 */

#ifndef TESIS_H
#define TESIS_H
#include <string>
using namespace std;


class tesis {
public:
    tesis();
    string getprofesor_guia();
    void setprofesor_guia(string prof_guia);
    string gettitulo();
    void settitulo(string tit);

private:
    string titulo;
    string profesor_guia;//si añado clase profesor no es necesaria
};

#endif /* TESIS_H */

