/* Programa que lee un entero en un rango y calcula su factorial,
   a continuación lee un real y lo eleva al entero. */
	
#include<iostream>
	
using namespace std;
	
long long Factorial (int numero) {
		
  long long factorial = 1;
		
  for (int contador = numero; contador > 1; contador--) {
    factorial *= contador;
  }
  return factorial;
}
	
double Potencia ( double base, int exponente) {
		
  double potencia = 1;
		
  for (int contador = 1; contador <= exponente; contador++) {
    potencia *= base;
  }
  return potencia;
}
		
int main () {
		
  int n;
  long long factorial;
  double x, potencia;
		
  do {
    cout << "Inserte valor de n entre 1 y 20: ";
    cin >> n;
  } while ( n < 1 || n > 20 );
		
  cout << "Inserte valor de X: ";
  cin >> x;
				
  factorial = Factorial(n);
				
  cout << n << "! = " << factorial << endl;
		
  potencia = Potencia(x, n);
		
  cout << x << "^" << n << " = " << potencia << endl;
}
