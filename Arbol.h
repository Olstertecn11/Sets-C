#include "Nodo.cpp"
#include <vector>

class Arbol {
public:
  Nodo *raiz;
  int tam;
  Arbol();
  void insertarNodo(Nodo *, string , vector<string>);
  void imprimirEnOrden(Nodo *);
  Nodo *union_conjuntos(Nodo *, Nodo *);
  Nodo *intersec_conjuntos(Nodo *, Nodo *);
  Nodo *diferencia_conjuntos(Nodo *, Nodo *);
  Nodo *diferencia_sim_conjuntos(Nodo *, Nodo *);
  bool esIgual(string, vector<string>);
  void add(string, vector<string>);
  void print();
  void printUnion();
  void printIntersec();
  void printDiferencia();
  void printDiferenciaSim();
  void printElementos(string, Nodo*,  bool);
  void printElementos();
};
