#include "Arbol.cpp"
#include <iostream>
using namespace std;




int main(){
  Arbol arbol = Arbol();
  arbol.add("Letras", "qwertyuiop");
  arbol.add("Vocales", "aeiou");
  arbol.add("Numeros", "123456789");
  arbol.print();
  arbol.printUnion();
  arbol.printIntersec();
  arbol.printDiferencia();
  arbol.printDiferenciaSim();
}








