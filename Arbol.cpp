#include "Arbol.h"

Arbol::Arbol(){
  this->raiz = NULL;
  this->tam = 0;
}


void Arbol::insertarNodo(Nodo *actual, Conjunto n){
  if(this->raiz == NULL) 
  {
    this->raiz = new Nodo(n);
  }
  else
  {
    if(n.elementos.length() < actual->elemento.elementos.length())
    {
      if(actual->izq == NULL) 
      {
	actual->izq = new Nodo(n);
	this->tam++;
      }
      else{
	this->insertarNodo(actual->izq, n);
      }
    }
    else{

      if(actual->der == NULL)
      {
	actual->der = new Nodo(n);
	this->tam++;
      }
      else{
	this->insertarNodo(actual->der, n);
      }
    }
  }
}

void Arbol::add(Conjunto n)
{
  this->insertarNodo(this->raiz, n);
}

void Arbol::imprimirEnOrden(Nodo* actual)
{
  if(actual == NULL) return;
  this->imprimirEnOrden(actual->izq);
  cout << "Nombre: " << actual->elemento.nombre << " elementos: " << actual->elemento.elementos << endl;
  this->imprimirEnOrden(actual->der);
}


void Arbol::print(){
  this->imprimirEnOrden(this->raiz);
}



