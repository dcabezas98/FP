/* Programa que calcula la suma y el producto de los n primeros t�rminos
   de una sucesi�n geom�trica por medio de funciones */

#include<iostream>
#include<cmath>

using namespace std;

double SumaHasta (double primer_termino, double razon, int tope) {
  double suma = 0, termino = primer_termino;
	
  for (int contador = 1; contador <= tope; contador++) {
    suma += termino;
    termino = termino * razon;
  }
  return suma;
}

double ProductoHasta (double primer_termino, double razon, int tope) {
  double producto, radicando, termino = primer_termino;
	
  for (int contador = 1; contador < tope; contador++) { // C�lculo de a_k
    termino = termino * razon;
  }
  radicando = pow(primer_termino * termino, tope);
  producto = sqrt(radicando);
  return producto;
}
	
int main () {
	
  double primer_termino, razon, suma, producto;
  int tope;
	
  cout << "Inserte primer t�rmino de la progresi�n geom�trica: ";
  cin >> primer_termino;
	
  cout << "Inserte factor de progresi�n: ";
  cin >> razon;
	
  cout << "Hasta qu� t�rmino de la progresi�n quiere calcular la suma? ";
  cin >> tope;
	
  suma = SumaHasta (primer_termino, razon, tope);
  producto = ProductoHasta (primer_termino, razon, tope);
  cout << "La suma de los t�rminos de la progresi�n hasta " << tope << " es: " << suma << endl;
  cout << "El producto de los t�rminos de la progresi�n hasta " << tope << " es: " << producto << endl;
}
