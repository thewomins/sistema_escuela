#ifndef Lista_alumno_titulado_h
#define Lista_alumno_titulado_h
#include <string>
#include "../alumnos/alumnos_titulados.h"
using namespace std;

struct nodo_alum_titulado{
    alumnos_titulados *alumno;
    nodo_alum_titulado *ant;
    nodo_alum_titulado *sig;
};

class Lista_alumno_titulado{
public:
    static Lista_alumno_titulado* getintance();
    nodo_alum_titulado *lista_alum_titulado;
    void ingresar_alumno_titulado(alumnos_titulados alu_new);
    void imprimir_lista_completa();
    alumnos_titulados* buscar_alumno_tit(int rut, int inicio, int fin);
    int largo_lista();
    int validar_alumno(alumnos_titulados alu_new);
    void iterator_siguiente(int pos);
    void iterator_anterior(int pos);

private:
    Lista_alumno_titulado();
    static Lista_alumno_titulado* instancia;
};


#endif /* Lista_alumno_titulado_h */
