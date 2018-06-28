/* Programa que solicita el centro y el radio de una circunferencia
   y las coordenadas del punto y devuelve la longitud
   de la circunferencia, el área del círculo interior y si el punto
   está o no dentro de la circunferencia. A continuación solicita un
   desplazamiento y vuelve a realizar la última comprobación. */

#include<iostream>
#include<cmath>

using namespace std;

class Circunferencia {

private:

  double radio;
  double centro_x, centro_y;
  static const double PI = 3.1416;

public:

  void setRadio(double valor) {

    radio = valor;
  }

  void setCentro_x(double valor) {

    centro_x = valor;
  }

  void setCentro_y(double valor) {

    centro_y = valor;
  }

  double longitud() {

    return 2 * PI * radio;
  }

  double area() {

    return PI * radio * radio;
  }

  bool contiene(double x, double y) {

    double dx, dy;

    dx = x - centro_x;
    dy = y - centro_y;

    return hypot(dx, dy) < radio;
  }

  void desplazar(double x, double y) {

    centro_x += x;
    centro_y += y;
  }
};

int main() {

  Circunferencia circunferencia;
  double r, centro_x, centro_y, punto_x,
    punto_y, desplazamiento_x, desplazamiento_y;
  bool contiene;
  string respuesta;

  do {
    cout << "Inserte radio: ";
    cin >> r;
  } while (r <= 0);

  circunferencia.setRadio(r);

  cout << "Inserte coorenada X del centro: ";
  cin >> centro_x;

  circunferencia.setCentro_x(centro_x);

  cout << "Inserte coordenada Y del centro: ";
  cin >> centro_y;

  circunferencia.setCentro_y(centro_y);

  cout << "Inserte coordenada X del punto: ";
  cin >> punto_x;

  cout << "Inserte coordenada Y del punto: ";
  cin >> punto_y;

  contiene = circunferencia.contiene(punto_x, punto_y);

  if (contiene)
    respuesta = "S�";
  else
    respuesta = "No";

  cout << "Longitud: " << circunferencia.longitud() << endl;
  cout << "Área: " << circunferencia.area() << endl;
  cout << "¿Contiene al punto? " << respuesta << endl;

  cout << "Seleccione desplazamiento horizontal: ";
  cin >> desplazamiento_x;

  cout << "Seleccione desplazamiento vertical: ";
  cin >> desplazamiento_y;

  circunferencia.desplazar(desplazamiento_x, desplazamiento_y);

  contiene = circunferencia.contiene(punto_x, punto_y);

  if (contiene)
    respuesta = "Sí";
  else
    respuesta = "No";

  cout << "¿Contiene al punto ahora? " << respuesta << endl;
}
