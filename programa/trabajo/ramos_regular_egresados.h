#ifndef RAMOS_REGULAR_EGRESADOS_H
#define RAMOS_REGULAR_EGRESADOS_H
#include <string>
#include "notas.h"
using namespace std;

class ramos_regular_egresados {
public:
    ramos_regular_egresados();
    string getnombre_ramo();
    void setnombre_ramo(string nombre_ram);
    string getnombre_carrera();
    void setnombre_carrera(string nombre_carr);
    int getnumero_semestre();
    void setnumero_semestre(int numero_sem);
    void ingresar_notas(int _notas);
    void get_notas();
    int get_promedio();
    int get_cantidad_notas();
    
private:
    notas nota[6];
    string nombre_ramo;
    string nombre_carrera;
    int numero_semestre;
protected:
    int cantidad_notas=0;
    
};

#endif /* RAMOS_REGULAR_EGRESADOS_H */

