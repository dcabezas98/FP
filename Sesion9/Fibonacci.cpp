/* Programa que calcula un término n de la sucesión de Fibonacci
   y los k términos siguientes de la sucesión usando una función
   recursiva.	*/

#include<iostream>

using namespace std;

int LeePositivo() {
  int numero;
  do {
    cout << "Inserte número mayor que 0: ";
    cin >> numero;
  } while (numero <= 0);
  return numero;
}

long long Fibonacci(int n) {

  if (n <=2)
    return 1;
  else
    return Fibonacci(n - 1) + Fibonacci(n - 2);
}

int main() {
  int n, k;
  long long fn;

  cout << "¿Qué término de la sucesión de Fibonacci quiere calcular? " << endl;
  n = LeePositivo();

  fn = Fibonacci(n);

  cout << "El número de Fibonacci de orden " << n << " es " << fn << endl;

  cout << "¿Cuántos términos de la sucesión de Fibonacci a partir de " << n << " quiere calcular? " << endl;
  k = LeePositivo();

  for (int contador = 1; contador <= k; contador++) {
    fn = Fibonacci(n + contador);
    cout << "Fibonacci de orden " << n + contador << ": \t" << fn << endl;
  }
}
