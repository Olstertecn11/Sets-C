#include <iostream>
#include "Conjunto.h"
using namespace std;

class Nodo {
  public:
    Nodo *izq;
    Nodo *der;
    Conjunto elemento;
    Nodo(Conjunto);
};
