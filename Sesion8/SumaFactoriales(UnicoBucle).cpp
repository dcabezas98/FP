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

/* La anterior función SumaFactoriales llamaba a la función Factorial,
   pero tenía el defecto de calcular cada factorial desde uno, era esta:

   long long Factorial (int numero) { // Función factorial a la que recurre

   long long factorial = 1;

   for (int contador = numero; contador > 1; contador--) {
   factorial *= contador;
   }
   return factorial;
   }

   long long SumaFactoriales (int numero) { // Antigua función SumaFactoriales

   long long suma = 0;

   for (int contador = 1; contador <= numero; contador++) {
   suma += Factorial(contador);
   }
   return suma;
   }

   La nueva función SumaFactoriales, en cambio, aprovecha la fórmula:
   n!=n(n-1) para evitar iteraciones inncesarias del bucle.
*/

long long SumaFactoriales (int numero) {

  long long suma = 0, factorial_anterior = 1,
    factorial;

  for (int contador = 1; contador <= numero; contador++) {
    factorial = factorial_anterior * contador;
    suma = suma + factorial;
    factorial_anterior = factorial;
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
