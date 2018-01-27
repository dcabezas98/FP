/*
  Programa en el que he implementado la clase cuadrado definida por
  las coordenadas x e y del vértice inferior izquierdo y la longitud
  del lado. He creado varios métodos de clase para obtener información
  sobre el cuadrado (área, perímetro, longitud de la diagonal y
  distancia al centro), para comparar características de dos cuadrados
  (su área y si uno está contenido en el otro) y para modificarlos
  (desplazarlos).
*/

#include<iostream>
#include<cmath>

using namespace std;

class Cuadrado {
	
private:
		
  double vertice_x;      // Coordenadas del vértice inferior izquierdo
  double vertice_y;
  double lado;           // Longitud del lado
		
  bool ladoCorrecto() {
			
    return lado >= 0.0;
  }
	
public:
		
  /* Constructores, para una o para tres variables tipo double */
  Cuadrado(double x, double y, double l) {          
	      
    setVertice(x, y);
	      
    if (ladoCorrecto()) 
      setLado(l);
			
    else                
      setLado(1.0); // Si el lado es negativo, se creará un cuadrado de lado 1 por defecto
  }
		
  Cuadrado(double l) { // Si no se introducen las coordenadas del vértice, se creará en el origen
			
    setVertice(0.0, 0.0);
						
    if (ladoCorrecto()) 
      setLado(l);
			
    else                
      setLado(1.0);
  }
		
  /* Métodos set y get */
  void setVertice(double x, double y) {
			
    vertice_x = x;
    vertice_y = y;
  }
		
  void setLado(double l) {
			
    lado = l;
  }
		
  double getX() {
			
    return vertice_x;
  }
		
  double getY() {
			
    return vertice_y;
  }
		
  double getLado() {
			
    return lado;
  }
		
  /* Métodos obligatorios */
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
			
      return otro_cuadrado.getX() <= vertice_x && otro_cuadrado.getY() <= vertice_y && otro_cuadrado.getX() + otro_cuadrado.getLado() >= vertice_x + lado && otro_cuadrado.getY() + otro_cuadrado.getLado() >= vertice_y + lado; 
  }
		
  bool iguales(Cuadrado otro_cuadrado) {
			
    return vertice_x == otro_cuadrado.getX() && vertice_y == otro_cuadrado.getY() && lado == otro_cuadrado.getLado();
  }
		
  /* Métodos que considero útiles */
  double diagonal() {
			
    return sqrt(2) * lado;
  }

  void desplazar(double dx, double dy) {
			
    setVertice(vertice_x + dx, vertice_y + dy);
  }
};

int main() {
	
  double vertice_x1, vertice_y1, lado1, lado2,
    desplazamiento_x, desplazamiento_y;
	
  cout << "Coordenada X del vértice inferior izquierdo del primer cuadrado: ";
  cin >> vertice_x1;
  cout << "Coordenada Y del vértice inferior izquierdo del primer cuadrado: ";
  cin >> vertice_y1;
  cout << "Longitud del lado del primer cuadrado: ";
  cin >> lado1;
	
  Cuadrado cuadrado1(vertice_x1, vertice_y1, lado1); // Definido por el primer constructor
	
  cout << "Área: " << cuadrado1.area() << " (unidades cuadradas)" << endl;
  cout << "Perímetro: " << cuadrado1.perimetro() << " (unidades)" << endl;
  cout << "Longitud diagonal: " << cuadrado1.diagonal() << " (unidades)" << endl;
	
  cout << "Longitud del lado del segundo cuadrado: ";
  cin >> lado2; 
	
  Cuadrado cuadrado2(lado2); // La coordenadas del vértice inferior izquierdo se inicializan al origen
	
  if (cuadrado1.mayorAreaQue(cuadrado2))
    cout << "El primer cuadrado tiene mayor área." << endl;
	
  else 
    cout << "El segundo cuadrado tiene mayor o igual área que el primero." << endl;
	
  if (cuadrado1.iguales(cuadrado2))
    cout << "Ambos cuadrados son iguales." << endl;
		
  else if (cuadrado1.contenidoEn(cuadrado2))
    cout << "El primer cuadrado está contenido en el segundo." << endl;
	
  else if (cuadrado2.contenidoEn(cuadrado1))
    cout << "El segundo cuadrado está contenido en el primero." << endl;
 		
  else
    cout << "Ninguno del los cuadrados contiene al otro." << endl << endl;
 
  cout << "¿Cuánto quiere desplazar el segundo cuadrado en el eje X? ";
  cin >> desplazamiento_x;
	
  cout << "¿Cuánto quiere desplazar el segundo cuadrado en el eje Y? ";
  cin >> desplazamiento_y;
	
  cuadrado2.desplazar(desplazamiento_x, desplazamiento_y);

  if (cuadrado1.iguales(cuadrado2))
    cout << "Ahora ambos cuadrados son iguales." << endl;
		
  else if (cuadrado1.contenidoEn(cuadrado2))
    cout << "Ahora el primer cuadrado está contenido en el segundo." << endl;
	
  else if (cuadrado2.contenidoEn(cuadrado1))
    cout << "Ahora el segundo cuadrado está contenido en el primero." << endl;
 		
  else
    cout << "Ninguno del los cuadrados contiene al otro." << endl;
}
