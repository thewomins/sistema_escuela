#ifndef RAMOS_REGULAR_EGRESADOS_H
#define RAMOS_REGULAR_EGRESADOS_H
#include <string>
#include "../notas/notas.h"
using namespace std;

class ramos_regular_egresados {
public:
    ramos_regular_egresados();
    ramos_regular_egresados(string _nombre_ramo, string _nombre_carrera, int _numero_semestre);
    string getnombre_ramo();
    void setnombre_ramo(string nombre_ram);
    string getnombre_carrera();
    int getnumero_semestre();
    void ingresar_notas(int _notas);
    void get_notas();
    void setnombre_carrera(string nombre_carr);
    int get_promedio();
    void setnumero_semestre(int numero_sem);
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



