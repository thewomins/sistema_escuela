/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   alumnos_regulares.h
 * Author: Felipe
 *
 * Created on 22 de octubre de 2018, 22:45
 */

#ifndef ALUMNOS_REGULARES_H
#define ALUMNOS_REGULARES_H
#include <string>
using namespace std;

class alumnos_regulares {
public:
    alumnos_regulares();
    alumnos_regulares(const alumnos_regulares& orig);
    virtual ~alumnos_regulares();
private:
    string nombre;
    string rut;
    int numero_matricula;
};

#endif /* ALUMNOS_REGULARES_H */

