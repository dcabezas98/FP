/* Programa que calcula el producto de dos n�meros
   utilizando el algoritmo de la multiplicaci�n rusa. */
	
#include<iostream>
	
using namespace std;
	
int main () {
		
  long long multiplicando, multiplicador, producto;              // Long long para multiplicar n�meros grandes.
		
  do {
    cout << "Inserte el primer numero a multiplicar: ";
    cin >> multiplicando;
  } while (multiplicando < 0);
			
  do {
    cout << "Inserte el segundo n�mero a multiplicar: ";  
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
