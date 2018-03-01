/* Programa que dice si tres enteros están ordenados
   o no, ya sea en orden ascendente o descendente */

#include<iostream>
#include<cmath>

using namespace std;

int main () {

  int numero1, numero2, numero3;
  bool creciente, decreciente;

  cout << "Inserte primer número: ";
  cin >> numero1;
  cout << "Inserte segundo número: ";
  cin >> numero2;
  cout << "Inserte tercer número: ";
  cin >> numero3;

  creciente = numero1 <= numero2 && numero2 <= numero3;
  decreciente = numero1 >= numero2 && numero2 >= numero3;

  if (creciente && !decreciente)
    cout << "Los números están ordenados en orden creciente.\n";

  else if (decreciente && !creciente)
    cout << "Los números están ordenados en orden decreciente.\n";

  else if (creciente && decreciente)
    cout << "Los tres números son iguales.\n";

  else (
	cout << "Los números no presentan orden.\n"); 
}
