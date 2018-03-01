/* Programa para calcular los segundos transcurridos
   entre dos instantes del mismo día.
*/

#include <iostream>          // Inclusión de recursos E/S
#include <cmath>             // Inclusión de recursos matemáticos

using namespace std;

int main () {
  int hora1;                   // Declaración de variables
  int minuto1;
  int segundo1;
  int hora2;
  int minuto2;
  int segundo2;
  int diferencia_segundos;

  cout << "Inserte hora del primer instante (entre 0 y 23): ";      // Se solicitan los datos
  cin >> hora1;
  cout << "Inserte minuto del primer instante (entre 0 y 59): ";
  cin >> minuto1;
  cout << "Inserte segundo del primer instante (entre 0 y 59): ";
  cin >> segundo1;
  cout << "Inserte hora del segundo instante (entre 0 y 23): ";
  cin >> hora2;
  cout << "Inserte minuto del segundo instante (entre 0 y 59): ";
  cin >> minuto2;
  cout << "Inserte segundo del segundo instante (entre 0 y 59); ";
  cin >> segundo2;

  diferencia_segundos = abs( hora2 * 3600 + minuto2 * 60 + segundo2 - ( hora1 * 3600 + minuto1 * 60 + segundo1 ) );  // Se realizan las operaciones

  cout << "El tiempo transcurrido entre los dos instantes indicados es de: " << diferencia_segundos << " segundos. \n";   // Se expresa el resultado

  system ("pause");
}

/* Alclaración: En este programa no es oportuno incluir una constante */
