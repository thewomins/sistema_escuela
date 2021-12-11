#ifndef ALUMNOS_TITULADOS_H
#define ALUMNOS_TITULADOS_H
#include <string>
#include "../listas/lista_ramos_titular.h"
#include "../alumnos/alumnos_egresados.h"
//#include "../tesis/tesis.h"

using namespace std;

class alumnos_titulados : public alumnos_egresados{
public:
    alumnos_titulados();
    alumnos_titulados(string _nombre, int _rut, int _numero_matricula, string _empresa_practica, int _fecha_egreso, string _empresa_actual, int _ano_titulacion);
    int getano_titulacion();
    void setano_titulacion(int ano_tit);
    string getempresa_actual();
    void setempresa_actual(string empresa_act);
    Lista_ramos_titular *lista_ramos_tit;
    /*void ingresar_ramos_tit(ramos_titular _ramos);
    void get_ramos_tit();
    void get_ramos_tit_1();
    int get_numero_ramos_inscritos_tit();
    void ingresar_nota_tit(int nota,int pos_ramo);
    void set_tesis(string titulo,string profesor_guia);
    void get_tesis();*/
    
private:
    //ramos_titular ramos_tit[6];
    //tesis _tesis;
    string empresa_actual;
    int ano_titulacion;
};

#endif /* ALUMNOS_TITULADOS_H */

