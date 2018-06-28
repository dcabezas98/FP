/*
  Función que utiliza el paso por referencia para intercambiar los
  valores de dos variables.  */

#include<iostream>

using namespace std;

void Intercambia (int &a, int &b) {
  int auxiliar;

  auxiliar = a;
  a = b;
  b = auxiliar;
}

int main () {
  int a, b;

  cout << "a: ";
  cin >> a;
  cout << "b: ";
  cin >> b;

  Intercambia (a, b);

  cout << "a: " << a << endl;
  cout << "b: " << b << endl;
}
