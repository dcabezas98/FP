/* Programa para probar la clase TableroBuscaMinas, que incluye un
   método para colocar una mina en una casilla y otro que dice cuántas
   minas hay alrededor de esa casilla. */

#include<iostream>

using namespace std;

class TableroBuscaMinas {

private:

  static const int FILAS = 50;
  static const int COLUMNAS = 30;

  bool tablero[50][30] = {{}}; // Se inicializan a false

public:

  /* Métodos set */
  void coloca(int i, int j) { // Método para incluir minas

    if(0 < i && i <= FILAS && 0 < j && j <= COLUMNAS)
      tablero[i-1][j-1] = true;
  }

  /* Métodos set */
  int numero_minas(int i, int j) { // Método que devuelve las minas alrededor de una casilla

    int numero_minas = 0;

    if(tablero[i-1][j-1]) // La casilla real es (i-1,j-1)
      numero_minas = -1;

    else {

      for(int k = i-2; k <= i; k++) {
	for(int l = j-2; l <= j; l++) { // Comprobación para no leer basura
	  if(tablero[k][l] && k >= 0 && k < FILAS && l >= 0 && l < COLUMNAS)
	    numero_minas++;
	}
      }
    }

    return numero_minas;
  }
};

int main() {

  TableroBuscaMinas juego;

  juego.coloca(2,6);
  juego.coloca(4,12);
  juego.coloca(2,7);
  juego.coloca(3,7);
  juego.coloca(1,2);
  juego.coloca(2,1);
  juego.coloca(2,2);

  cout << "(2,6)  ->  " << juego.numero_minas(2,6) << " minas.\n";
  cout << "(1,1)  ->  " << juego.numero_minas(1,1) << " minas.\n";
  cout << "(50,30)  ->  " << juego.numero_minas(50,30) << " minas.\n";
  cout << "(3,6)  ->  " << juego.numero_minas(3,6) << " minas.\n";
}
