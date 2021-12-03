#ifndef LISTAS_H
#define LISTAS_H
#include <string>
#include "alumnos/alumnos_regulares.h"
#include "alumnos/alumnos_egresados.h"
#include "alumnos/alumnos_titulados.h"
#include "ramos/ramos_titular.h"
#include "ramos/ramos_regular_egresados.h"
using namespace std;

struct nodo_alum_regular{
    alumnos_regulares alu;
    nodo_alum_regular *ant;
    nodo_alum_regular *sig;
};
struct nodo_ramos_alum_regular_egresado{
    ramos_regular_egresados ramo;
    nodo_ramos_alum_regular_egresado *ant;
    nodo_ramos_alum_regular_egresado *sig;
};
/*
struct nodo1{
        alumnos_egresados alu;
        nodo1 *sig;
};

struct nodo2{
        alumnos_titulados alu;
        nodo2 *sig;
};


struct nodo_ramos_tit{
        ramos_titular ramo;
        nodo_ramos_tit *sig;
};
*/

class Listas{
public:
    //void ingresar_alumno_egre(nodo1 *&lista,alumnos_egresados alu_new);
    //void ingresar_alumno_tit(nodo2 *&lista,alumnos_titulados alu_new);
    //void ingresar_ramos_tit(nodo_ramos_tit *&lista,ramos_titular ramo_new);
    //int largo_egre(nodo1 *lista);
    //int largo_tit(nodo2 *lista);
    //int largo_ramos_reg_egr(nodo_ramos_reg_egr *lista);
    //int largo_ramos_tit(nodo_ramos_tit *lista);
    //nodo1 *buscar_alumno_egre(nodo1 *lista,int rut, int inicio, int fin);
    //nodo2 *buscar_alumno_tit(nodo2 *lista,int rut, int inicio, int fin);
    static Listas* getintance();
    nodo_alum_regular *lista_alum_reg;
    nodo_ramos_alum_regular_egresado *lista_ramos_alum_regular_egresados;
    void ingresar_alumno_regular(alumnos_regulares alu_new);
    void imprimir_alu();
    int buscar_alumno_reg(int rut, int inicio, int fin);
    int largo_reg();
    void ingresar_ramo_alumno_regular(ramos_regular_egresados ramo_new);
    int largo_ramos_reg();
    ramos_regular_egresados obtener_ramo(int pos);
    void iterator_siguiente(int pos);
    void iterator_anterior(int pos);

private:
    Listas();
    static Listas* instancia;
};


#endif /* LISTAS_H */