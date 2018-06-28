/* Programa que calcula la distancia entre dos puntos del plano,
   utiliza un struct para agrupar las coordenadas x e y en una
   sóla variable. */

#include<iostream>
#include<cmath>

using namespace std;

struct CoordenadasPunto2D {
  double x, y;
};

double DistanciaEuclidea(CoordenadasPunto2D a, CoordenadasPunto2D b) {
  CoordenadasPunto2D v; // V es el extremo del vector libre AB situando su origen en el (0,0)
  double distancia;

  v.x = b.x - a.x;
  v.y = b.y - a.y;

  distancia = sqrt(v.x * v.x + v.y * v.y);

  return distancia;
}

CoordenadasPunto2D LeePunto2D(string punto) {
  CoordenadasPunto2D p;

  cout << "Inserte primera coordenada del punto " << punto << ": ";
  cin >> p.x;
  cout << "Inserte segunda coordenada del punto " << punto << ": ";
  cin >> p.y;

  return p;
}

char LeeOpcion(string mensaje) {

  char opcion;

  do {
    cout << mensaje;
    cin >> opcion;
    opcion = toupper(opcion);
  } while (opcion != 'S' && opcion != 'N');

  return opcion;
}

int main() {

  CoordenadasPunto2D a, b;
  double distancia;
  string primer_punto = "A";
  string segundo_punto = "B";
  string mensaje = "¿Quiere introducir otro par de puntos? Pulse s/S o n/N: ";
  char opcion;

  do {

    a = LeePunto2D(primer_punto);
    b = LeePunto2D(segundo_punto);

    distancia = DistanciaEuclidea(a, b);

    cout << "La distancia entre ambos puntos es: " << distancia << endl;

    opcion = LeeOpcion(mensaje);

  } while (opcion == 'S');
}
