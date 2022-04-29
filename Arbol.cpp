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
  	string n = a->nombre + " - " + b->nombre;
	vector<string> e_f = a->elementos;
	vector<string> e_b = b->elementos;
	for (int i = 0; i < e_b.size(); i++)
	{
		for (int j = 0; j < e_f.size(); j++)
		{
			if (e_b[i] == e_f[j])
			{
				e_f.erase(e_f.begin() + j);
			}
		}
	}
	Nodo *nuevo = new Nodo(n, e_f);
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

void Arbol::printDiferencia()
{
  	if(this->raiz == NULL) return;
	Nodo *result = this->diferencia_conjuntos(this->raiz, this->raiz->izq);
	cout << "Nombre: " << result->nombre << " elementos: " << result->elemento << endl;
}

void Arbol::printDiferenciaSim()
{
	if(this->raiz == NULL) return;
	Nodo *result = this->diferencia_sim_conjuntos(this->raiz, this->raiz->izq);
	cout << "Nombre: " << result->nombre << " elementos: " << result->elemento << endl;
}

void Arbol::printElementos(string prefijo, Nodo* nodo, bool esIzq){
  if(nodo != NULL)
  {
    cout << prefijo;
    cout << (esIzq ? "├──" : "└──");
    cout << nodo->nombre << " " << nodo->elemento << endl;
    this->printElementos(prefijo + (esIzq ? "│   " : "    "), nodo->izq, true);
    this->printElementos(prefijo + (esIzq ? "│   " : "    "), nodo->der, false);
  }
}

void Arbol::printElementos()
{
  this->printElementos("", this->raiz, false);
}


















