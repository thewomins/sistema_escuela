#ifndef Lista_alumno_regular_h
#define Lista_alumno_regular_h
#include <string>
#include "../alumnos/alumnos_regulares.h"
using namespace std;

struct nodo_alum_regular{
    alumnos_regulares *alumno;
    nodo_alum_regular *ant;
    nodo_alum_regular *sig;
};

class Lista_alumno_regular{
public:
    static Lista_alumno_regular* getintance();
    nodo_alum_regular *lista_alum_reg;
    void ingresar_alumno_regular(alumnos_regulares alu_new);
    void imprimir_lista_completa();
    alumnos_regulares* buscar_alumno_reg(int rut, int inicio, int fin);
    int largo_lista();
    int validar_alumno(alumnos_regulares alu_new);
    void iterator_siguiente(int pos);
    void iterator_anterior(int pos);

private:
    Lista_alumno_regular();
    static Lista_alumno_regular* instancia;
};


#endif /* Lista_alumno_regular_h */