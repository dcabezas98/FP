/* Programa que lee una serie de temperaturas introducidas
   hasta que se introduce un terminador y dice la posición
   en la que se introdujo la primera temperatura de la mayor
   subsecuencia ascendente y la duración de la misma. */

#include <iostream>
#include <cmath>

using namespace std;

int main () {

  double temperatura, temperatura_anterior;
  int secuencia, mayor_secuencia, posicion,
    inicio, inicio_mayor;
  const int TERMINADOR = -1;

  cout << "Inserte temperatura: ";
  cin >> temperatura_anterior;

  posicion = 1;                       // Condiciones iniciales;
  inicio = posicion;
  inicio_mayor = inicio;
  secuencia = 1;
  mayor_secuencia = secuencia;

  do {

    cout << "Inserte temperatura: ";
    cin >> temperatura;

    posicion++;

    if (temperatura >= temperatura_anterior)         // En este caso se incrementa la secuencia
      secuencia++;

    else {

      if (secuencia > mayor_secuencia) {            // En este caso se comprueba si la actual subsecuencia es
	mayor_secuencia = secuencia;               // la mayor, se ajustan la longitud y la posición.
	inicio_mayor = inicio;
      }

      inicio = posicion;                            // Se restablecen los valores para volver a medir.
      secuencia = 1;
    }

    temperatura_anterior = temperatura;                 // La temperatura actual pasa a ser la anterior, y se comparar� con la siguiente.

  } while (temperatura != TERMINADOR);

  cout << "Inicio de mayor subsecuencia ascendente en posición: " << inicio_mayor << endl;
  cout << "Longitud de mayor subsecuencia ascendente: " << mayor_secuencia << endl;
}
