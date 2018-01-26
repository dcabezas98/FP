/* Programa para calcular el valor que toma la función
   gaussiana en un determinado intervalo de abscisa a partir 
   de los parámetros mu y sigma. Incluye diversos filtros
   de entrada */
	
#include <iostream>   // Inclusión de los recursos de E/S
#include <cmath>      // Inclusión de las funciones matemáticas necesarios

using namespace std;

int main() {
  double mu, sigma, maximo, minimo, incremento;        // Declaración de las variables
  double denominador, exponente, abscisa, gauss;       // y constante necesarias 
  const double PI = 3.1416;
	
  cout << "Inserte valor del parámetro Mu, esperanza: ";                           
  cin >> mu;                                    
	
  do {
    cout << "Inserte valor del parámetro Sigma, desviación (mayor o igual que 0): ";
    cin >> sigma;
  } while (sigma < 0);
	
  denominador = sigma * sqrt(2 * PI);                  // El denominador sólo depende de Sigma, no tiene sentido que entre en el bucle con el resto de cálculos.
	
  cout << "Inserte el menor valor de abscisa para el que quiere calcular la imagen: ";  
  cin >> minimo;
	
  do {
    cout << "Inserte el mayor valor de abscisa para el que que quiere calcular la imagen: ";
    cin >> maximo;
  } while (maximo < minimo);
	
  cout << "¿Cada cuánto quiere calcular el valor de la función?: ";
  cin >> incremento;
	
  abscisa = minimo;
	
  cout << "Valores de la función para cada abscisa del intervalo:" << endl;
	
  while (abscisa <= maximo) {
    exponente = -0.5 * pow( (abscisa - mu) / sigma, 2 );				// Operaciones necesarias
    gauss = exp(exponente) / denominador; 
    cout << "X= " << abscisa << "\t\tY= " << gauss << endl;		   // Se expresa el resultado
    abscisa = abscisa + incremento;
  }
}
