/* Programa que dice si tres enteros están ordenados
   o no, ya sea en orden ascendente o descendente,
   usando un tipo enumerado */

#include<iostream>
#include<cmath>

using namespace std;

enum Orden {creciente, decreciente, desorden};

int main () {

  int numero1, numero2, numero3;

  Orden orden = desorden;                            // Si no se define el valor de la variable, se le asigna
  // el 0, que corresponde al orden creciente.
  cout << "Inserte primer número: ";
  cin >> numero1;
  cout << "Inserte segundo número: ";
  cin >> numero2;
  cout << "Inserte tercer número: ";
  cin >> numero3;

  if (numero1 < numero2 && numero2 < numero3)
    orden = creciente;

  if (numero1 > numero2 && numero2 > numero3)
    orden = decreciente;

  switch (orden){

  case creciente:
    cout << "Los números están ordenados en orden creciente." << endl;
    break;

  case decreciente:
    cout << "Los números están ordenados en orden decreciente." << endl;
    break;

  default:
    cout << "Los números no están ordenados." << endl;
  }
}
