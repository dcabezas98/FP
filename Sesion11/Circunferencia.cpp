/* Programa que solicita el centro y el radio de una circunferencia
   y las coordenadas del punto y devuelve la longitud
   de la circunferencia, el área del círculo interior y si el punto
   está o no dentro de la circunferencia. A continuación solicita un
   desplazamiento y vuelve a realizar la última comprobación.
   He usado la sobrecarga para añadir métodos que devuelven al distancia
   a un punto, cuadrado u otra circunferencia.
*/

#include<iostream>
#include<cmath>

using namespace std;

class Punto2D {

private:

  static const int NUMERO_COMPONENTES = 2;
  double x, y;

public:

  /* Constructores */
  Punto2D() {

    x = 0;
    y = 0;
  }

  Punto2D(double abscisa, double ordenada) {

    setCoordenadas(abscisa, ordenada);
  }

  /* Métodos set y get */
  void setCoordenadas(double abscisa, double ordenada) {

    x = abscisa;
    y = ordenada;
  }

  void setX(double abscisa) {

    x = abscisa;
  }

  void setY(double ordenada) {

    x = ordenada;
  }

  double getX() {

    return x;
  }

  double getY() {

    return y;
  }

  double distancia(Punto2D punto) {

    return hypot(x - punto.getX(), y - punto.getY());
  }
};

class Cuadrado {

private:

  Punto2D vertice;  // Coordenadas del vértice inferior izquierdo
  double lado;      // Longitud del lado

  bool ladoCorrecto() {

    return lado >= 0.0;
  }

public:

  /* Constructores, para una o para tres variables tipo double */
  Cuadrado(Punto2D punto, double l) {

    setVertice(punto);

    if (ladoCorrecto())
      setLado(l);

    else
      setLado(1.0); // Si el lado es negativo, se creará un cuadrado de lado 1 por defecto
  }

  Cuadrado(double l) { // Si no se introducen las coordenadas del vértice, se creará en el origen

    Punto2D punto;

    setVertice(punto);

    if (ladoCorrecto())
      setLado(l);

    else
      setLado(1.0);                       // Si el lado es negativo, se creará un cuadrado de lado 1 por defecto
  }

  /* Métodos set y get */
  void setVertice(Punto2D punto) {

    vertice = punto;
  }

  void setLado(double l) {

    lado = l;
  }

  Punto2D getVertice() {

    return vertice;
  }

  double getLado() {

    return lado;
  }

  /* M�todos obligatorios */
  double area() {

    return lado * lado;
  }

  double perimetro() {

    return 4 * lado;
  }

  bool mayorAreaQue(Cuadrado otro_cuadrado) {

    return area() > otro_cuadrado.area();
  }

  bool contenidoEn(Cuadrado otro_cuadrado) {

    if (lado > otro_cuadrado.getLado()) // Si es mayor, no puede estar contenido
      return false;

    else

      return otro_cuadrado.getVertice().getX() <= vertice.getX() && otro_cuadrado.getVertice().getY() <= vertice.getY() && otro_cuadrado.getVertice().getX() + otro_cuadrado.getLado() >= vertice.getX() + lado && otro_cuadrado.getVertice().getY() + otro_cuadrado.getLado() >= vertice.getY() + lado;
  }

  /* Métodos que considero útiles */
  double diagonal() {

    return sqrt(2) * lado;
  }

  void desplazar(Punto2D vector) { // Técnicamente no es un punto pero puede interpresarse como el vector libre que une el origen con el punto

    vector.setX(vector.getX() + vertice.getX());
    vector.setY(vector.getY() + vertice.getY());
    setVertice(vector);
  }
};

class Circunferencia {

private:

  double radio;
  Punto2D centro;
  static const double PI = 3.1416;

  bool radioCorrecto() {

    return radio >= 0.0;
  }

public:

  /* Constructores */
  Circunferencia(Punto2D p, double r) {

    setCentro(p);

    if (r>0)
      setRadio(r);

    else
      setRadio(0.0);
  }

  /* set, get */
  void setRadio(double valor) {

    radio = valor;
  }

  void setCentro(Punto2D punto) {

    centro = punto;
  }

  double getRadio() {

    return radio;
  }

  Punto2D getCentro() {

    return centro;
  }

  double longitud() {

    return 2 * PI * radio;
  }

  double area() {

    return PI * radio * radio;
  }

  bool contiene(Punto2D punto) {

    return centro.distancia(punto) < radio;
  }

  void desplazar(double x, double y) {

    centro.setX(centro.getX() + x);
    centro.setY(centro.getY() + y);
  }

  /* Métodos distancia usando sobrecarga */

  double distancia(Punto2D p) { // Distancia a un punto (centro de la circunferencia a punto)

    return centro.distancia(p);
  }

  double distancia(Cuadrado cuadrado) { // Distancia a un cuadrado (centro de la circunferencia a esquina superior izquierda del cuadrado

    Punto2D esquina_sup_izda(cuadrado.getVertice().getX(), cuadrado.getVertice().getY() + cuadrado.getLado()); // Coordenadas de la esquina superior izquierda

    return centro.distancia(esquina_sup_izda);
  }

  double distancia(Circunferencia circunferencia) {

    return centro.distancia(circunferencia.getCentro());
  }
};

int main() {

  double centro_x1, centro_y1, radio1, punto_x, punto_y, cuadrado_vx,
    cuadrado_vy, lado_cuadrado, centro_x2, centro_y2, radio2;

  cout << "Coordenada X del centro de la circunferencia: ";
  cin >> centro_x1;
  cout << "Coordenada Y del centro de la circunferencia: ";
  cin >> centro_y1;

  Punto2D centro1(centro_x1, centro_y1);

  cout << "Longitud del radio de la circunferencia: ";
  cin >> radio1;

  Circunferencia circunferencia1(centro1, radio1);

  cout << "Coordenada X de un punto: ";
  cin >> punto_x;
  cout << "Coordenada Y de un punto: ";
  cin >> punto_y;

  Punto2D punto(punto_x, punto_y);

  cout << endl << "Distancia de la circunferencia al punto: " << circunferencia1.distancia(punto) << endl << endl;

  cout << "Coordenada X del vértice inferior izquierdo de un cuadrado: ";
  cin >> cuadrado_vx;
  cout << "Coordenada Y: ";
  cin >> cuadrado_vy;
  cout << "Lado del cuadrado: ";
  cin >> lado_cuadrado;

  Punto2D vertice(cuadrado_vx, cuadrado_vy);

  Cuadrado cuadrado(vertice, lado_cuadrado);

  cout << endl << "Distancia de la circunferencia al cuadrado: " << circunferencia1.distancia(cuadrado) << endl << endl;

  cout << "Coordenada X del centro de otra circunferencia: ";
  cin >> centro_x2;
  cout << "Coordenada Y del centro de otra circunferencia: ";
  cin >> centro_y2;

  Punto2D centro2(centro_x2, centro_y2);

  cout << "Longitud del radio de la circunferencia: ";
  cin >> radio2;

  Circunferencia circunferencia2(centro2, radio2);

  cout << endl << " Distancia de un a circunferencia a otra: " << circunferencia1.distancia(circunferencia2) << endl << endl;
}
