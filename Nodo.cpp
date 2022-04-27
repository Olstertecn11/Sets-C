#include "Nodo.h"

Nodo::Nodo(string n, string e) {
  this->izq = NULL;
  this->der = NULL;
  this->elemento = e;
  this->nombre = n;
}
