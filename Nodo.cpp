#include "Nodo.h"

Nodo::Nodo(string n, vector<string> e) {
  this->izq = NULL;
  this->der = NULL;
  this->elementos = e;
  this->nombre = n;
}


void Nodo::imp_elementos(){
  cout << "{ ";
  for(int i = 0; i < this->elementos.size(); i++){
    cout << this->elementos[i] << " ";
  }
  cout << " }";
}







