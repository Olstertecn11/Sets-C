#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Nodo {
  public:
    Nodo *izq;
    Nodo *der;
    string nombre;
    vector<string> elementos;
    Nodo(string, vector<string>);
    void imp_elementos();
};
