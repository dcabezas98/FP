/* Programa que calcula la sumatoria de los factoriales
   desde uno a un valor T introducido. */
	
#include<iostream>
	
using namespace std;
	
int main () {
		
  int T;
  long long factorial, suma = 0;
		
  do {
    cout << "¿Hasta qué numero quiere calcular la sumatoria de factoriales? ";
    cin >> T;
  } while ( T < 0);
		
  for (int contador1 = 1; contador1 <= T; contador1++) {
			
    factorial = 1;
			
    for (int contador2 = 2; contador2 <= contador1; contador2++) { // La interación con contador2 = 1 se puede omitir.
				
      factorial *= contador2;
    }
			
    suma += factorial;
  }
		
  cout << "La suma de factoriales desde 1 hasta " << T << " es: " << suma << endl;
}
