/* Programa que calcula el producto de dos números
   utilizando el algoritmo de la multiplicación rusa. */

#include<iostream>

using namespace std;

int main () {

  long long multiplicando, multiplicador, producto;              // Long long para multiplicar números grandes.

  do {
    cout << "Inserte el primer numero a multiplicar: ";
    cin >> multiplicando;
  } while (multiplicando < 0);

  do {
    cout << "Inserte el segundo número a multiplicar: ";
    cin >> multiplicador;
  } while (multiplicador < 0);

  producto = 0;

  while (multiplicando >= 1) {

    if (multiplicando % 2 == 1)
      producto += multiplicador;

    multiplicando /= 2;
    multiplicador += multiplicador;
  }

  cout << "Su producto es: " << producto << endl;
}
