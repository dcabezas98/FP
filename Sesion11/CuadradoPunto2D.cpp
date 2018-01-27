/*
  Programa en el que he implementado la clase cuadrado definida por
  las coordenadas x e y del v�rtice inferior izquierdo y la longitud
  del lado. He creado varios m�todos de clase para obtener informaci�n
  sobre el cuadrado (�rea, per�metro, longitud de la diagonal y
  distancia al centro), para comparar caracter�sticas de dos cuadrados
  (su �rea y si uno est� contenido en el otro) y para modificarlos
  (desplazarlos).  En lugar de la coordenadas x e y, el v�rtice se
  define como un objeto de la clase Punto2D.
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
};

class Cuadrado {
	
private:
		
  Punto2D vertice;   // Coordenadas del v�rtice inferior izquierdo
  double lado;       // Longitud del lado
		
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
      setLado(1.0); // Si el lado es negativo, se crear� un cuadrado de lado 1 por defecto
  }
		
  Cuadrado(double l) { // Si no se introducen las coordenadas del v�rtice, se crear� en el origen
	      
    Punto2D punto;
	      
    setVertice(punto);
	      
    if (ladoCorrecto()) 
      setLado(l);
			
    else                
      setLado(1.0); // Si el lado es negativo, se crear� un cuadrado de lado 1 por defecto
  }
		
  /* M�todos set y get */
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

  /* M�todos que considero �tiles */
  double diagonal() {
			
    return sqrt(2) * lado;
  }
				
  void desplazar(Punto2D vector) { // T�cnicamente no es un punto pero puede interpresarse como el vector libre que une el origen con el punto
			
    vector.setX(vector.getX() + vertice.getX());
    vector.setY(vector.getY() + vertice.getY());
    setVertice(vector);
  }
};

int main() {
	
  double vertice_x1, vertice_y1, lado1, lado2, 
    desplazamiento_x, desplazamiento_y;
	
  cout << "Coordenada X del v�rtice inferior izquierdo del primer cuadrado: ";
  cin >> vertice_x1;
  cout << "Coordenada Y del v�rtice inferior izquierdo del primer cuadrado: ";
  cin >> vertice_y1;
	
  do {
    cout << "Longitud del lado del primer cuadrado: ";
    cin >> lado1;
  } while (lado1 < 0);
	
  Punto2D vertice1(vertice_x1, vertice_y1);
  Cuadrado cuadrado1(vertice1, lado1);
	
  cout << "�rea: " << cuadrado1.area() << endl;
  cout << "Per�metro: " << cuadrado1.perimetro() << endl;
  cout << "Diagonal: " << cuadrado1.diagonal() << endl;

  do {
    cout << "Longitud del lado del segundo cuadrado: ";
    cin >> lado2;
  } while (lado2 < 0);
	
  Cuadrado cuadrado2(lado2); // Constructor con un par�metro
	
  if (cuadrado1.contenidoEn(cuadrado2)) 
    cout << "Primer cuadrado contenido en el segundo." << endl;
	
  else if (cuadrado2.contenidoEn(cuadrado1))
    cout << "Segundo cuadrado contenido en el primero." << endl;
 
  else 
    cout << "Ning�n cuadrado contenido en el otro." << endl;
	
  cout << "�Cu�nto quiere desplazar el segundo cuadrado horizontalmente? ";
  cin >> desplazamiento_x;
  cout << "�Cu�nto quiere desplazar el segundo cuadrado verticalmente? ";
  cin >> desplazamiento_y;
	
  Punto2D vector_desplazamiento(desplazamiento_x, desplazamiento_y); // T�cnicamente no es un punto, pero representa el vector desde el origen hasta el punto
  cuadrado2.desplazar(vector_desplazamiento);
	      
  if (cuadrado1.contenidoEn(cuadrado2))
    cout << "Ahora el primer cuadrado est� contenido en el segundo." << endl;
	
  else if (cuadrado2.contenidoEn(cuadrado1))
    cout << "Ahora el segundo cuadrado est� contenido en el primero." << endl;
 		
  else
    cout << "Ninguno del los cuadrados contiene al otro." << endl;
}
