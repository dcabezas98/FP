/* Programa que utiliza metodos de clase para calcular la pendiente
   de una recta, la ordenada a partir de la abscisa y la abscisa a partir
   de la ordenada. Los datos miembro ahora son privados y he creado los
   métodos de clase oportunos para leerlos y asignarlos. */

#include<iostream>

using namespace std;

class Recta {
	
private:
		
  double A, B, C;
	
public:
	
  double pendiente() {
		
    return - A / B;
  }
	
  double ordenada(double abscisa) {
		
    return (- C - abscisa * A) / B;
  }
	
  double abscisa(double ordenada) {
		
    return (- C - ordenada * B) / A;
  }
	
  double leeA() {
      
    cout << "Coeficiente de la X: ";
    cin >> A;
            
    return A;
  }
   
  double leeB() {
   	
    cout << "Coeficiente de la Y: ";
    cin >> B;
      
    return B;
  }
   
  double leeC() {
   	
    cout << "Término independiente: ";
    cin >> C;
      
    return C;
  }
};
	
int main() {
	
  Recta r, s;
  double abscisa, ordenada;
	
  r.leeA();
  r.leeB();
  r.leeC();
  s.leeA();
  s.leeB();
  s.leeC();
	
  cout << "Pendiente primera recta: " << r.pendiente() << endl;
  cout << "Pendiente segunda recta: " << s.pendiente() << endl;
	
  cout << "Abscisa primera recta: ";
  cin >> abscisa;
	
  cout << "Ordenada en ese punto: " << r.ordenada(abscisa) << endl;

  cout << "Ordenada primera recta: ";
  cin >> ordenada,
	
    cout << "Abscisa que corresponde: " << r.abscisa(ordenada) << endl;
}
