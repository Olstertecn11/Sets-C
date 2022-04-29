#include "Arbol.cpp"
#include <iostream>
using namespace std;




int main(){
  Arbol arbol = Arbol();
  arbol.add("A", {"Guatemala", "Honduras", "Costa Rica", "Nicaragua", "El Salvador"});
  arbol.add("B", {"Oliver", "Liam", "Noah", "William", "James"});
  arbol.add("C", {"Oliver", "Liam", "Miguel", "Sofia", "Agustin"});
  arbol.crearUniverso();
  cout << "============================ CONJUNTOS ===================================" << endl;
  arbol.print();
  cout << "----------------------------------------------------------------------------------------------------" << endl;
  arbol.printUnion("A", "B");
  arbol.printIntersec("B", "C");
  arbol.printDiferencia("A", "B");
  arbol.printDiferenciaSim("B", "C");
  arbol.printComplemento("B");
  /* cout << "Universo: "; */
  /* arbol.universo->imp_elementos(); cout << endl << endl; */
  cout << "\n\nArbol" << endl;
  arbol.printElementos();
}








