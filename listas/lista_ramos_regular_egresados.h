#ifndef Lista_ramos_regular_h
#define Lista_ramos_regular_h
#include <string>
#include <cstring>
#include "../ramos/ramos_regular_egresados.h"
using namespace std;

struct nodo_ramos_alum_regular_egresado{
    ramos_regular_egresados *ramo;
    nodo_ramos_alum_regular_egresado *ant;
    nodo_ramos_alum_regular_egresado *sig;
};

class Lista_ramos_regular{
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
    Lista_ramos_regular();
    nodo_ramos_alum_regular_egresado *lista_ramos_alum_regular_egresados;
    void ingresar_ramo_alumno_regular(ramos_regular_egresados *ramo_new);
    int largo_ramos_reg();
    ramos_regular_egresados* obtener_ramo(int pos);
    ramos_regular_egresados* buscar_ramo(string nombre);
    void imprimir_datos_ramos();
    void iterator_siguiente(int pos);
    void iterator_anterior(int pos);

private:
    
};


#endif /* Lista_ramos_regular_h */