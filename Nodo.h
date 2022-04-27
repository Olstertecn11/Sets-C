#include <iostream>
using namespace std;

class Nodo {
  public:
    Nodo *izq;
    Nodo *der;
    string nombre;
    string elemento;
    Nodo(string, string);
};
