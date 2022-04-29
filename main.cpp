#include "Arbol.cpp"
#include <iostream>
using namespace std;




int main(){
  Arbol arbol = Arbol();
  arbol.add("A", {"Guatemala", "Honduras", "Costa Rica", "Nicaragua", "El Salvador"});
  arbol.add("B", {"Oliver", "Liam", "Noah", "William", "James"});
  arbol.add("C", {"Oliver", "Liam", "Miguel", "Sofia", "Agustin"});
  arbol.print();
  arbol.printUnion("A", "B");
  arbol.printIntersec("B", "C");
  arbol.printDiferencia("A", "B");
  arbol.printDiferenciaSim("B", "C");
  cout << "\n\nArbol" << endl;
  arbol.printElementos();
}








