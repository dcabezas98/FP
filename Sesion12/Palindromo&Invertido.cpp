/* Programa que dice si una secuencia de car�cteres introducida es un
   pal�ndromo y, en caso negativo, devuelve la secuencia invertida. */
	
#include<iostream>

using namespace std;

int main() {
	
  const int MAX_CARACTERES = 99;
  const char TERMINADOR = '#';
  char caracteres[MAX_CARACTERES];
  char caracter;
	
  cout << "Inserte caracter o pulse \"" << TERMINADOR << "\" para terminar: ";   
  caracter = cin.get();                                                  
	
  int posicion = -1; // Cuando entre en el bucle, quedar� en 0, de
		     // esta forma evito que la posici�n aumente
		     // cuando se introduzca el terminador.
	
  while (caracter != TERMINADOR && posicion < MAX_CARACTERES) { // Si se introducen 100 caracteres, el bucle de lectura termina.
 		
    posicion++;
		
    caracteres[posicion] = caracter;
				
    cout << "Inserte caracter o pulse \"" << TERMINADOR << "\" para terminar: ";
    cin >> caracter;    
  }
	
  bool palindromo = true;
	
  int tope = posicion / 2; // Si a mitad del recorrido del vector no
			   // se han encontrado un par de caracteres
			   // que verifique que no sea pal�ndromo, no
			   // va a encontrarse a partir de ese punto.
  for(int contador = 0; contador <= tope && palindromo == true; contador++) {
		
    if (caracteres[contador] != caracteres[posicion - contador])    // Recorro el vector desde ambos extremos.
      palindromo = false;                                          // Si se da este caso, se detiene el bule.
  }
	
  if (palindromo)
    cout << "La secuencia es un pal�ndromo." << endl;
	
  else { // Se procede al algoritmo de inversi�n.
		
    char aux;
		
    for(int contador = 0; contador <= tope; contador++) { // Se van intercambiando cada pareja de caracteres.
			
      aux = caracteres[contador];
      caracteres[contador] = caracteres[posicion - contador];
      caracteres[posicion - contador] = aux;
    }
	
    cout << "La secuencia no es un pal�ndromo. Secuencia invertida: " << endl;
	
    for(int contador = 0; contador <= posicion; contador++)
      cout << caracteres[contador];		  	
  }
}
