/* Programa que dice si tres enteros est�n ordenados
   o no, ya sea en orden ascendente o descendente */

#include<iostream>
#include<cmath>

using namespace std;

int main () {

  int numero1, numero2, numero3;
  bool creciente, decreciente;

  cout << "Inserte primer n�mero: ";
  cin >> numero1;
  cout << "Inserte segundo n�mero: ";
  cin >> numero2;
  cout << "Inserte tercer n�mero: ";
  cin >> numero3;

  creciente = numero1 <= numero2 && numero2 <= numero3;
  decreciente = numero1 >= numero2 && numero2 >= numero3;

  if (creciente && !decreciente)
    cout << "Los n�meros est�n ordenados en orden creciente.\n";

  else if (decreciente && !creciente)
    cout << "Los n�meros est�n ordenados en orden decreciente.\n";

  else if (creciente && decreciente)
    cout << "Los tres n�meros son iguales.\n";

  else (
	cout << "Los n�meros no presentan orden.\n"); 
}
