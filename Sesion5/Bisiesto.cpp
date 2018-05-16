/* Programa que dice si un año es bisiesto o no */

#include<iostream>
#include<cmath>

using namespace std;

int main () {

  int ano;
  bool bisiesto;

  cout << "Inserte año: ";
  cin >> ano;

  bisiesto = ((ano % 400) == 0) || ((ano % 4) == 0 && (ano % 100) != 0);

  if (bisiesto)
    cout << "Bisiesto." << endl;

  else
    cout << "No bisiesto." << endl;
}
