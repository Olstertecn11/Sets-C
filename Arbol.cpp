#include "Arbol.h"


Nodo* Arbol::union_conjuntos(Nodo* a, Nodo* b){
  string n = a->nombre + " + " + b->nombre;
  vector<string> e_f = a->elementos;
  vector<string> e_b = b->elementos;
  for(int i = 0; i < e_b.size(); i++){
    e_f.push_back(e_b[i]);
  }
  Nodo *nuevo = new Nodo(n, e_f);
  return nuevo;
}

Nodo* Arbol::diferencia_conjuntos(Nodo* a, Nodo* b){
  string n = a->nombre + " - " + b->nombre;
	vector<string> e_f = a->elementos;
	vector<string> e_b = b->elementos;
	for(int i = 0; i < e_b.size(); i++){
		for(int j = 0; j < e_f.size(); j++){
			if(e_b[i] == e_f[j]){
				e_f.erase(e_f.begin() + j);
			}
		}
	}
	Nodo *nuevo = new Nodo(n, e_f);
	return nuevo;
}

Nodo * Arbol::diferencia_sim_conjuntos(Nodo *a, Nodo *b)
{
  vector<string> r;
  vector<string> _a = a->elementos;
  vector<string> _b = b->elementos;
  for(int i = 0; i < _a.size(); i++){
    for(int j = 0; j < _b.size(); j++){
      if(!this->esIgual(_a[i], _b)){
	r.push_back(_a[i]);
      }
    }
  }
  for(int i = 0; i < _b.size(); i++){
    for(int j = 0; j < _a.size(); j++){
      if(!this->esIgual(_b[i], _a)){
	r.push_back(_b[i]);
      }
    }
  }
  string n = a->nombre + " # " + b->nombre;
  Nodo *nuevo = new Nodo(n, r);
  return nuevo;
}


bool Arbol::esIgual(string a, vector<string> b){
  for(int i = 0; i < b.size(); i++){
    if(a == b[i]){
      return true;
    }
  }
  return false;
}

Nodo* Arbol::intersec_conjuntos(Nodo*a, Nodo*b){
  Nodo *resultado =new  Nodo("", {});
  vector<string>_a = a->elementos;
  vector<string>_b = b->elementos;
  vector<string>r;
  string cf = "";
  for(int i = 0; i < _a.size(); i++){
    if(this->esIgual(_a[i], _b)){
      r.push_back(_a[i]);
    }
  }
  resultado->nombre = a->nombre + " * " + b->nombre;
  resultado->elementos = r;
  return resultado;
}


Arbol::Arbol(){
  this->raiz = NULL;
  this->tam = 0;
}


void Arbol::insertarNodo(Nodo *actual, string n, vector<string> e){
  if(this->raiz == NULL) 
  {
    this->raiz = new Nodo(n, e);
  }
  else
  {
    if(e.size() < actual->elementos.size())
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

void Arbol::add(string n, vector<string> e)
{
  this->insertarNodo(this->raiz, n, e);
}

void Arbol::imprimirEnOrden(Nodo* actual)
{
  if(actual == NULL) return;
  this->imprimirEnOrden(actual->izq);
  cout << "Nombre: " << actual->nombre << " elementos: ";
  actual->imp_elementos();
  cout << endl;
  this->imprimirEnOrden(actual->der);
}

void Arbol::print(){
  this->imprimirEnOrden(this->raiz);
}


void Arbol::printUnion(string n1, string n2)
{
  if(this->raiz == NULL) return;
	Nodo *a = this->buscar(this->raiz, n1);
	Nodo *b = this->buscar(this->raiz, n2);
	if(a == NULL || b == NULL) {
	  cout << "No existe el conjunto" << endl;
	  return;
	}
	Nodo *result = this->union_conjuntos(a, b);
	cout << "Nombre: " << result->nombre << " elementos: ";
	result->imp_elementos();
	cout << endl;
}


void Arbol::printIntersec(string n1, string  n2)
{
	if(this->raiz == NULL) return;
	Nodo *a = this->buscar(this->raiz, n1);
	Nodo *b = this->buscar(this->raiz, n2);
	if (a == NULL || b == NULL) {
	  cout << "No existe el conjunto" << endl;
	  return;
	}
	Nodo *result = this->intersec_conjuntos(a, b);
	cout << "Nombre: " << result->nombre << " elementos: ";
	result->imp_elementos();
	cout << endl;
}

void Arbol::printDiferencia(string n1, string  n2)
{
  	if(this->raiz == NULL) return;
	Nodo *a = this->buscar(this->raiz, n1);
	Nodo *b = this->buscar(this->raiz, n2);
	if(a == NULL || b == NULL) {
	  cout << "No existe el conjunto" << endl;
	  return;
	}
	Nodo *result = this->diferencia_conjuntos(a, b);
	cout << "Nombre: " << result->nombre << " elementos: " ;
	result->imp_elementos();
	cout << endl;
}

void Arbol::printDiferenciaSim(string n1, string n2)
{
	if(this->raiz == NULL) return;
	Nodo *a = this->buscar(this->raiz, n1);
	Nodo *b = this->buscar(this->raiz, n1);
	if (a == NULL || b == NULL) {
	  cout << "No existe el conjunto" << endl;
	  return;
	}
	Nodo *result = this->diferencia_sim_conjuntos(a, b);
	cout << "Nombre: " << result->nombre << " elementos: ";
	result->imp_elementos();
	cout << endl;
}

void Arbol::printElementos(string prefijo, Nodo* nodo, bool esIzq){
  if(nodo != NULL)
  {
    cout << prefijo;
    cout << (esIzq ? "├──" : "└──");
    cout << nodo->nombre << " " ;
    nodo->imp_elementos();
    cout << endl;
    this->printElementos(prefijo + (esIzq ? "│   " : "    "), nodo->izq, true);
    this->printElementos(prefijo + (esIzq ? "│   " : "    "), nodo->der, false);
  }
}

void Arbol::printElementos()
{
  this->printElementos("", this->raiz, false);
}


Nodo *Arbol::buscar(Nodo* actual, string nombre)
{
  if(actual == NULL) return NULL;
  if(actual->nombre == nombre) return actual;
  Nodo *izq = this->buscar(actual->izq, nombre);
  if(izq != NULL) return izq;
  Nodo *der = this->buscar(actual->der, nombre);
  if(der != NULL) return der;
  return NULL;
}












