/* Programa que utiliza metodos de clase para calcular la pendiente
   de una recta, la ordenada a partir de la abscisa y la abscisa a partir
   de la ordenada. Los datos miembro ahora son privados y he creado
   un método de clase para leerlos y asignarlos. */

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
	
  double getA() {
		
    cout << "Coeficiente X: ";
    cin >> A;
                  
    return A;
  }
   
  double getB() {
   	
    cout << "Coeficiente Y: ";
    cin >> B;
   	
    return B;
  }
   
  double getC() {
   	
    cout << "Término independiente: ";
    cin >> C;
   	      
    return C;
  }
	
  void setcoeficientes(double coef_x, double coef_y, double termino_independiente) {
		
    A = coef_x;
    B = coef_y;
    C = termino_independiente; 
  }
};

int main() {
	
  Recta r, s;
  double abscisa, ordenada, A, B, C;
	
  A = r.getA();
  B = r.getB();
  C = r.getC();
  r.setcoeficientes(A, B, C);
  A = s.getA();
  B = s.getB();
  C = s.getC();
  s.setcoeficientes(A, B, C);
			
  cout << "Pendiente primera recta: " << r.pendiente() << endl;
  cout << "Pendiente segunda recta: " << s.pendiente() << endl;
	
  cout << "Abscisa primera recta: ";
  cin >> abscisa;
	
  cout << "Ordenada en ese punto: " << r.ordenada(abscisa) << endl;

  cout << "Ordenada primera recta: ";
  cin >> ordenada;
	
  cout << "Abscisa que corresponde: " << r.abscisa(ordenada) << endl;
}
