/* Programa que utiliza metodos de clase para calcular la pendiente
   de una recta, la ordenada a partir de la abscisa y la abscisa a partir
   de la ordenada. */

#include<iostream>

using namespace std;

class Recta {
	
public:
		
  double A, B, C;
	
  double pendiente() {
		
    return - A / B;
  }
	
  double ordenada(double abscisa) {
		
    return (- C - abscisa * A) / B;
  }
	
  double abscisa(double ordenada) {
		
    return (- C - ordenada * B) / A;
  }
};
	
int main() {
	
  Recta r, s;
  double abscisa, ordenada;
	
  cout << "Coeficiente X primera recta: ";
  cin >> r.A;
  cout << "Coeficiente Y primera recta: ";
  cin >> r.B;
  cout << "Término independiente primera recta: ";
  cin >> r.C;
  cout << "Coeficiente X segunda recta: ";
  cin >> s.A;
  cout << "Coeficiente Y segunda recta: ";
  cin >> s.B;
  cout << "Término independiente segunda recta: ";
  cin >> s.C;
	
  cout << "Pendiente primera recta: " << r.pendiente() << endl;
  cout << "Pendiente segunda recta: " << s.pendiente() << endl;
	
  cout << "Abscisa primera recta: ";
  cin >> abscisa;
	
  cout << "Ordenada en ese punto: " << r.ordenada(abscisa) << endl;

  cout << "Ordenada primera recta: ";
  cin >> ordenada,
	
    cout << "Abscisa que corresponde: " << r.abscisa(ordenada) << endl;
}
