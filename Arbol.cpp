#include "Arbol.h"


Nodo* Arbol::union_conjuntos(Nodo* a, Nodo* b){
  string n = a->nombre + " U " + b->nombre;
  string e = a->elemento + b->elemento;
  Nodo *nuevo = new Nodo(n, e);
  return nuevo;
}

bool Arbol::esIgual(char a, string b){
  for(int i = 0; i < b.length(); i++){
    if(a == b[i]){
      return true;
    }
  }
  return false;
}

Nodo* Arbol::intersec_conjuntos(Nodo*a, Nodo*b){
  Nodo *resultado =new  Nodo("", "");
  string c1 = a->elemento;
  string c2 = b->elemento;
  string cf = "";
  for(int i = 0; i < c1.length(); i++){
    if(esIgual(c1[i],  c2)){
      cf += c1[i];
    }
  }
  resultado->elemento = cf;
  resultado->nombre = a->nombre + " () " + b->nombre;
  return resultado;
}


Arbol::Arbol(){
  this->raiz = NULL;
  this->tam = 0;
}


void Arbol::insertarNodo(Nodo *actual, string n, string e){
  if(this->raiz == NULL) 
  {
    this->raiz = new Nodo(n, e);
  }
  else
  {
    if(e.length() < actual->elemento.length())
    {
      if(actual->izq == NULL) 
      {
	actual->izq = new Nodo(n, e);
	this->tam++;
      }
      else{
	this->insertarNodo(actual->izq, n, e);
      }
    }
    else{

      if(actual->der == NULL)
      {
	actual->der = new Nodo(n, e);
	this->tam++;
      }
      else{
	this->insertarNodo(actual->der, n, e);
      }
    }
  }
}

void Arbol::add(string n, string e)
{
  this->insertarNodo(this->raiz, n, e);
}

void Arbol::imprimirEnOrden(Nodo* actual)
{
  if(actual == NULL) return;
  this->imprimirEnOrden(actual->izq);
  cout << "Nombre: " << actual->nombre << " elementos: " << actual->elemento << endl;
  this->imprimirEnOrden(actual->der);
}

void Arbol::print(){
  this->imprimirEnOrden(this->raiz);
}


void Arbol::printUnion()
{
  if(this->raiz == NULL) return;
	Nodo *result = this->union_conjuntos(this->raiz, this->raiz->izq);
	cout << "Nombre: " << result->nombre << " elementos: " << result->elemento << endl;
}


void Arbol::printIntersec()
{
	if(this->raiz == NULL) return;
	Nodo *result = this->intersec_conjuntos(this->raiz, this->raiz->izq);
	cout << "Nombre: " << result->nombre << " elementos: " << result->elemento << endl;
}



