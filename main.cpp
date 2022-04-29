#include "Arbol.cpp"
#include <iostream>
using namespace std;




int main(){
  Arbol arbol = Arbol();
  arbol.add("A", {"Guatemala", "Honduras", "Costa Rica", "Nicaragua", "El Salvador"});
  arbol.add("B", {"Oliver", "Liam", "Noah", "William", "James"});
  arbol.add("C", {"Oscar", "Lucas", "Miguel", "Sofia", "Agustin"});
  arbol.print();
  arbol.printUnion("A", "B");
  /* arbol.printIntersec(); */
  /* arbol.printDiferencia(); */
  /* arbol.printDiferenciaSim(); */
  cout << "Arbol" << endl;
  arbol.printElementos();
}








