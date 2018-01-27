/* Programa que calcula un t�rmino n de la sucesi�n de Fibonacci
   y los k t�rminos siguientes de la sucesi�n usando una funci�n 
   recursiva.	*/
	
#include<iostream>

using namespace std;

int LeePositivo() {
  int numero;
  do {
    cout << "Inserte n�mero mayor que 0: ";
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
	
  cout << "�Qu� t�rmino de la sucesi�n de Fibonacci quiere calcular? " << endl;
  n = LeePositivo();
	
  fn = Fibonacci(n);
	
  cout << "El n�mero de Fibonacci de orden " << n << " es " << fn << endl;
	
  cout << "�Cu�ntos t�rminos de la sucesi�n de Fibonacci a partir de " << n << " quiere calcular? " << endl;
  k = LeePositivo(); 
	
  for (int contador = 1; contador <= k; contador++) {
    fn = Fibonacci(n + contador);
    cout << "Fibonacci de orden " << n + contador << ": \t" << fn << endl;
  }
}
