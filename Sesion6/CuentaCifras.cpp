/* Programa que lee una cifra y los extremos de un intervalo
   y calcula el numero de veces que se repite esa cifra en
   los números del intervalo. */

#include<iostream>
#include<cmath>

using namespace std;

int main () {

  int digito, minimo, maximo,
    cifra, veces, numero, numero_a_descuartizar;

  do {
    cout << "Inserte dígito: ";
    cin >> digito;
  } while (digito < 0 || digito > 10);

  do {
    cout << "Inserte mínimo del intervalo: ";
    cin >> minimo;
  } while (minimo < 0);

  do {
    cout << "Inserte máximo del intervalo: ";
    cin >> maximo;
  } while (maximo < minimo);

  veces = 0;

  for (numero = minimo; numero <= maximo; numero++) {       // Cojo uno por uno los números entre
    // el mínimo y el máximo del intervalo,
    numero_a_descuartizar = numero;						       // voy extrayendo sus cifras y las voy
    // comparando con el dígito introducido
    do {                                                   // al principio.
      cifra = numero_a_descuartizar % 10;

      if (cifra == digito)
	veces++;

      numero_a_descuartizar = numero_a_descuartizar / 10;

    } while (numero_a_descuartizar > 1);
  }
  cout << veces;
}
