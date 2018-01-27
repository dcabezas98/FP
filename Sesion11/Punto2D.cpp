/*
  Programa que implementa la clase Punto2D, definido por sus
  coordenadas x e y, e implementa una serie de m�todos para
  operar y obtener informaci�n de cada objeto.
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
		
  Punto2D(double abscisa) { // Si s�lo se introduce un par�metro, se crea un punto del eje X
			
    setCoordenadas(abscisa, 0);
  }
		
  /* M�todos set y get */
		
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
		
  /* M�todos que considero oportunos */
				
  double distanciaOrigen() { // Devuelve la distancia del punto al origen de coordenadas.
			
    return hypot(x, y);
  }
		
  double distancia(Punto2D otro_punto) { // Devuelve la distancia del punto al punto introducido como par�metro.
			
    return hypot(x - otro_punto.getX(), y - otro_punto.getY());
  }
		
  int cuadrante() { // Dice en qu� cuadrante est� contenido el punto
    int cuadrante;
	 		
    if (x < 0) { // Si el punto est� contenido alguno de los ejes de
		 // coordenadas, se interpreta que est� en la parte
		 // positiva del espacio dividido por el eje.
      if (y < 0)                
	cuadrante = 3;
 				
      else 
	cuadrante = 2;
    }	
		   
    else {
		   	
      if (y < 0)
	cuadrante = 4;
	   		
      else 
	cuadrante = 1;
    }
			
    return cuadrante;
  }
		
  void desplazar(double dx, double dy) {
			
    setCoordenadas(x + dx, y + dy);
  }
};
		
int main() {
	
  double x, y, dx, dy;
	
  cout << "Coordenada X: ";
  cin >> x;
  cout << "Coordenada Y: ";
  cin >> y;
	
  Punto2D punto1(x, y);
		
  cout << "Distancia al origen: " << punto1.distanciaOrigen() << endl;
  cout << "El punto se encuentra en el cuadrante: " << punto1.cuadrante() << endl << endl;
	
  cout << "Desplazamiento horizontal: ";
  cin >> dx;
  cout << "Desplazamiento vertical: ";
  cin >> dy;
	
  Punto2D punto2(punto1);
	
  punto1.desplazar(dx, dy);
	
  cout << "Nueva distancia al origen: " << punto1.distanciaOrigen() << endl;
  cout << "El punto se encuentra ahora en el cuadrante: " << punto1.cuadrante() << endl;
  cout << "Distancia a la posici�n anterior: " << punto1.distancia(punto2) << endl;
}
