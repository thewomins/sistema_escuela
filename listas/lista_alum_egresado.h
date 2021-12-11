#ifndef Lista_alumno_egresador_h
#define Lista_alumno_egresador_h
#include <string>
#include "../alumnos/alumnos_egresados.h"
using namespace std;

struct nodo_alum_egresado{
    alumnos_egresados *alumno;
    nodo_alum_egresado *ant;
    nodo_alum_egresado *sig;
};

class Lista_alumno_egresador{
public:
    static Lista_alumno_egresador* getintance();
    nodo_alum_egresado *lista_alum_egresado;
    void ingresar_alumno_egresado(alumnos_egresados alu_new);
    void imprimir_lista_completa();
    alumnos_egresados* buscar_alumno_egre(int rut, int inicio, int fin);
    int largo_lista();
    int validar_alumno(alumnos_egresados alu_new);
    void iterator_siguiente(int pos);
    void iterator_anterior(int pos);

private:
    Lista_alumno_egresador();
    static Lista_alumno_egresador* instancia;
};


#endif /* Lista_alumno_egresador_h */