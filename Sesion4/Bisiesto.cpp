/* Programa que dice si un a�o es bisiesto o no */

#include<iostream>
#include<cmath>

using namespace std;

int main () {
  int ano;

  cout << "Inserte a�o: ";
  cin >> ano;

  if ((ano % 400) == 0)
    cout << "Bisiesto.\n";

  else {
    if ((ano % 4) == 0) {
      if ((ano % 100) != 0)
	cout << "Bisiesto.\n";

      else {
	cout << "No bisiesto.\n";
      }
    }

    else {
      cout << "No bisiesto.\n";
    }
  }
}
