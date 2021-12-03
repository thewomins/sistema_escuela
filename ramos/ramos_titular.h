

#ifndef RAMOS_TITULAR_H
#define RAMOS_TITULAR_H
#include <string>
#include "../ramos/ramos_regular_egresados.h"
#include "../notas/notas.h"
using namespace std;


class ramos_titular : public ramos_regular_egresados {
public:
    ramos_titular();
    string getnombre_area_ramo();
    void setnombre_area_ramo(string nombre_area_ram);
    string getnombre_empresa_auspiciadora();
    void setnombre_empresa_auspiciadora(string nombre_empresa_ausp);
    string getunidad_dicta_ramo();
    void setunidad_dicta_ramo(string unidad_dicta_ram);
    void ingresar_notas_tit(int _notas);
    int get_notas_tit();

private:
    notas nota_tit[6];
    string nombre_area_ramo;
    string nombre_empresa_auspiciadora;
    string unidad_dicta_ramo;
};

#endif /* RAMOS_TITULAR_H */

