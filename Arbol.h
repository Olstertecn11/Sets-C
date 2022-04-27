#include "Nodo.cpp"

class Arbol {
public:
  Nodo *raiz;
  int tam;
  Arbol();
  void insertarNodo(Nodo *, string , string );
  void imprimirEnOrden(Nodo *);
  Nodo *union_conjuntos(Nodo *, Nodo *);
  Nodo *intersec_conjuntos(Nodo *, Nodo *);
  bool esIgual(char, string);
  void add(string, string);
  void print();
  void printUnion();
  void printIntersec();
};
