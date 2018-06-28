/* Programa que calcula la sumatoria de los factoriales
   desde uno a un valor T introducido. */

#include<iostream>

using namespace std;

int LeeIntRango (int min, int max) {

  int numero;

  do {
    cout << "Inserte número entre " << min << " y " << max << ": ";
    cin >> numero;
  } while ( numero < min || numero > max);

  return numero;
}

long long Factorial (int numero) {

  long long factorial = 1;

  for (int contador = numero; contador > 1; contador--) {
    factorial *= contador;
  }
  return factorial;
}

long long SumaFactoriales (int numero) {

  long long suma = 0;

  for (int contador = 1; contador <= numero; contador++) {
    suma += Factorial(contador);
  }
  return suma;
}

int main () {

  int T;
  long long resultado;

  T = LeeIntRango (1, 20);

  resultado = SumaFactoriales(T);

  cout << "La suma de factoriales desde 1 hasta " << T << " es: " << resultado << endl;
}
