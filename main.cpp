#include "Arbol.cpp"
#include <iostream>
using namespace std;

int main(){
  Arbol arbol = Arbol();
  Conjunto c_arr[3] = {{"Letras", "qwerwttryt"}, {"Vocales", "aeiou"}, {"Numeros", "1234567"}};
  arbol.add(c_arr[0]);
  arbol.add(c_arr[1]);
  arbol.add(c_arr[2]);
  arbol.print();
}
