#include "Nodo.h"

Nodo::Nodo(Conjunto c) {
  this->izq = NULL;
  this->der = NULL;
  this->elemento = c;
}
