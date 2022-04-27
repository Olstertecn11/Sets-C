#include "Nodo.cpp"

class Arbol{
  public:
    Nodo *raiz;
    int tam;
    Arbol();
    void insertarNodo(Nodo *, Conjunto);
    void imprimirEnOrden(Nodo *);
    void add(Conjunto);
    void print();
};
