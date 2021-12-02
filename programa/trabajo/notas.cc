#include "notas.h"

notas::notas() {
}


int notas::getnota(){
    return this->nota;
}

void notas::setnota(int ing_notas) {
    this->nota=ing_notas;
}
