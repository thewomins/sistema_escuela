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
    string getnombre();
    void setnombre(string nombre_alum);
    string getrut();
    void setrut(string rut_alum);
    int getnumero_matricula();
private:
    string nombre;
    string rut;
    int numero_matricula;
    int generador_num_matricula();
};

#endif /* ALUMNOS_REGULARES_H */

