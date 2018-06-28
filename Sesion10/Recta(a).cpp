/* Programa que lee los coeficiente A, B y C de dos rectas
   y calcula sus pendiente. */

#include<iostream>

using namespace std;

class Recta {

public:

  double A, B, C;
};

int main() {

  Recta r, s;
  double pendiente_r, pendiente_s;

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

  pendiente_r = - r.A / r.B;
  pendiente_s = - s.A / s.B;

  cout << "Pendiente primera recta: " << pendiente_r << endl;
  cout << "Pendiente segunda recta: " << pendiente_s << endl;
}
