#ifndef ALUMNOS_REGULARES_H
#define ALUMNOS_REGULARES_H
#include <string>
#include "../ramos_regular_egresados/ramos_regular_egresados.h"
using namespace std;

class alumnos_regulares {
public:
    alumnos_regulares();
    alumnos_regulares(string _nombre, int _rut, int _numero_matricula);
    string getnombre();
    void setnombre(string nombre_alum);
    int getrut();
    void setrut(int rut_alum);
    void setnumero_matricula(int num);
    int getnumero_matricula();
    void ingresar_ramos(ramos_regular_egresados _ramos);
    void get_ramos();
    void muestra_ramos();
    int get_ramos_inscritos();
    void ingresar_nota(int nota,int pos_ramo);
    void get_prom();
    
private:
    ramos_regular_egresados ramos[6];
    string nombre;
    int rut;
    int numero_matricula;
protected:
    int ramos_inscritos=0;
};

#endif /* ALUMNOS_REGULARES_H */
