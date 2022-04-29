#include "Nodo.cpp"
#include <vector>

class Arbol {
public:
  Nodo *raiz;
  Nodo *universo;
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
  void printUnion(string, string);
  Nodo* buscar(Nodo*, string);
  void printIntersec(string, string);
  void printDiferencia(string, string);
  void printDiferenciaSim(string, string);
  void printElementos(string, Nodo*,  bool);
  void printElementos();
  void printComplemento(string);
  void crearUniverso(Nodo *, vector<string>);
  void crearUniverso();
  Nodo* complemento(string);
};
