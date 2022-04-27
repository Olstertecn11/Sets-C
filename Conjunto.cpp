#include "Conjunto.h"

Conjunto::Conjunto(string n, string e){
  this->nombre = n;
  this->elementos = e;
}


string Conjunto::getElementos(){
  return this->elementos;
}

string Conjunto::getNombre(){
  return this->nombre;
}
  
