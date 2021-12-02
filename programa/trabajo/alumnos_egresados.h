#ifndef ALUMNOS_EGRESADOS_H
#define ALUMNOS_EGRESADOS_H
#include <string>
using namespace std;
#include "ramos_regular_egresados.h"
#include "alumnos_regulares.h"

class alumnos_egresados : public alumnos_regulares {
public:
    alumnos_egresados();
    string getempresa_practica();
    void setempresa_practica(string empresa_prac);
    int getfecha_egreso();
    void setfecha_egreso(int fecha_egres);
    int getpromedio();
    void setpromedio(int prom);
private:
    int fecha_egreso;
    string empresa_practica;
    int promedio;
};

#endif /* ALUMNOS_EGRESADOS_H */

