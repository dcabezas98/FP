/* Programa que lee cuatro caracteres de tipo char y devuelve
   todas las combinaciones que se pueden formar con los elementos
   de los conjuntos delimitados por ellos. */
	
#include<iostream>
	
using namespace std;
			
main () {
		
  char min_izda, max_izda, min_dcha, max_dcha,
    primera_letra, segunda_letra;
		
  cout << "min_izda: ";
  cin >> min_izda;
  cout << "max_izda: ";
  cin >> max_izda;
  cout << "min_dcha: ";
  cin >> min_dcha;
  cout << "max_dcha: ";
  cin >> max_dcha;
		
  for (int contador1 = min_izda; contador1 <= max_izda; contador1++) { // Me auxilio de un tipo int para el bucle.
			
    primera_letra = contador1; // Recupero la forma de letra.
			
    for ( int contador2 = min_dcha; contador2 <= max_dcha; contador2++) {
				
      segunda_letra = contador2;
				
      cout << primera_letra << segunda_letra << " ";    // Imprime un fila, con las parejas separadas por espacios.
    }
			
    cout << endl;         // Cambia de fila.
			
  }
}	
