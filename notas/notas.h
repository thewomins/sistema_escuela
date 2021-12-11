#ifndef NOTAS_H
#define NOTAS_H

struct nodo_notas{
    notas notas;
    nodo_notas *ant;
    nodo_notas *sig;
};

class notas {
public:
    notas();
    int getnota();
    void setnota(int ing_notas);
    nodo_notas *lista_notas;
    int largo_lista();
    void iterator_siguiente(int pos);
    void iterator_anterior(int pos);
private:
    int nota;
};

#endif /* NOTAS_H */



