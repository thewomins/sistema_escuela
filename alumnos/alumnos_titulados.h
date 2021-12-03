
#ifndef ALUMNOS_TITULADOS_H
#define ALUMNOS_TITULADOS_H
#include <string>
#include "../ramos/ramos_titular.h"
#include "../alumnos/alumnos_egresados.h"
#include "../tesis/tesis.h"

using namespace std;

class alumnos_titulados : public alumnos_egresados{
public:
    alumnos_titulados();
    int getano_titulacion();
    void setano_titulacion(int ano_tit);
    string getempresa_actual();
    void setempresa_actual(string empresa_act);
    void ingresar_ramos_tit(ramos_titular _ramos);
    void get_ramos_tit();
    void get_ramos_tit_1();
    int get_numero_ramos_inscritos_tit();
    void ingresar_nota_tit(int nota,int pos_ramo);
    void set_tesis(string titulo,string profesor_guia);
    void get_tesis();
    
private:
    ramos_titular ramos_tit[6];
    tesis _tesis;
    string empresa_actual;
    int ano_titulacion;
};

#endif /* ALUMNOS_TITULADOS_H */

