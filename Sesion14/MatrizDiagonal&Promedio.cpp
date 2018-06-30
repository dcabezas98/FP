/* Programa que lee una matriz simétrica y construye una matriz
   suavizada, cuya diagonal principal son iguales a la original, es
   simétrica y en cada posición (i,j) incluye el valor medio de los
   valores que ocupan las posiciones de las columnas j,j+1,...,n-1 en
   la fila i de la original. */

#include<iostream>
using namespace std;

int main() {

  const int MAX_FILAS = 50;
  double original[MAX_FILAS][MAX_FILAS];
  double suavizada[MAX_FILAS][MAX_FILAS];
  int n, i, j, columnas;
  double elemento, suma;

  do {
    cout <<"Número de filas: ";
    cin >> n;
  } while(n < 0 || n>= MAX_FILAS);

  for(i = 0; i < n; i++) { // Lectura de la matriz original
    for(j = i; j < n; j++) {
      cout << "Fila: " << i+1 << " , columna " << j+1 << ": ";
      cin >> elemento;

      original[i][j] = elemento;
    }
  }

  for(i = 0; i < n; i++) // Copia de la diagonal principal
    suavizada[i][i] = original[i][i];

  for(i = 0; i < n; i++) { // Recorro la matriz original

    suma = 0;
    columnas = 0;

    for(j = n-1; j > i; j--) {

      suma += original[i][j]; // Sumo los distinos elementos

      suavizada[i][j] = suma / ++columnas; // Asigno a cada posición el valor medio correspondiente
      suavizada[j][i] = suavizada[i][j]; // Para que la matriz sea simétrica
    }
  }

  cout <<"Matriz suavizada:\n\n";

  for(i = 0; i < n; i++) {
    for(j = 0; j < n; j++)
      cout << "\t" << suavizada[i][j];

    cout << "\n";
  }
}
