/* Programa para probar el método de ordenación por áreas de la clase
   VectorCuadrados. */

#include<iostream>
#include<cmath>

using namespace std;

class Cuadrado {
	
private:
		
  double v_x; // Coordenadas del vértice inferior izquierdo
  double v_y;
  double l;
		
  bool ladoCorrecto() {
    return l >= 0.0;
  }
		
public:
	
  Cuadrado(double x, double y, double lado) {
    setVertice(x,y);
    setLado(lado);
  }
		
  Cuadrado(double lado) 
    :Cuadrado(0, 0, lado) {}
         
  Cuadrado() 
    :Cuadrado(0, 0, 0) {}
         
  /* Métodos set, get. */
  void setVertice(double x, double y) {
    v_x = x;
    v_y = y;
  }
      
  void setLado(double lado) {
    if(ladoCorrecto()) // Para que el lado no sea nagativo
      l = lado;
    else 
      l = 0;
  }
      
  double getVX() {
    return v_x;
  }
      
  double getVY() {
    return v_y;
  }
      
  double getLado() {
    return l;
  }
      
  /* Métodos propios de la clase cuadrado. */
  double area() {
			
    return l * l;
  }
		
  double perimetro() {
			
    return 4 * l;
  }
		
  bool mayorAreaQue(Cuadrado otro_cuadrado) {
			
    return area() > otro_cuadrado.area();
  }
		
  bool contenidoEn(Cuadrado c) {
    bool empieza_despues = c.getVX() <= v_x && c.getVY() <= v_y;
    bool acaba_antes = c.getVX() + c.getLado() >= v_x + l && c.getVY() + c.getLado() >= v_y + l;

    return empieza_despues && acaba_antes; 
  }
		
  /* Sobrecarga de operador. */
  bool operator > (Cuadrado c) {
    return mayorAreaQue(c);
  }
};

class VectorCuadrados {
	
private:
		
  static const int MAX = 100;
  Cuadrado vector[MAX];
  int utilizados;
		
public:
		
  VectorCuadrados() :utilizados(0) {}
		
  /* Métodos set, get. */
  Cuadrado getCuadrado(int pos) {
    if(pos < utilizados) // Me aseguro de que no devuelva basura
      return vector[pos];
  }
		
  void setCuadrado(Cuadrado c, int pos) {
    if(pos < MAX) // Para no escribir fuera de la memoria reservada
      vector[pos] = c;
  }
      
  void aniade(Cuadrado c) {
    if(utilizados < MAX) {
      vector[utilizados] = c;
      utilizados++;
    }
  }
		
  void swap(int pos1, int pos2) {
			
    if(pos1 >= 0 && pos1 < utilizados && pos2 >= 0 && pos2 < utilizados) {
      Cuadrado aux = vector[pos1];
      vector[pos1] = vector[pos2];
      vector[pos2] = aux;
    }
  }
		
  void ordenaAreaAscendente() {
    int i, j;
    bool cambio = true;
			
    for(i = 0; i < utilizados && cambio; i++) {
      for(j = utilizados-1, cambio = false; j > i; j--) {
	if(vector[j-1] > vector[j]) {
	  swap(j,j-1);
	  cambio = true;
	}
      }
    }
  }
};

int main() {
	
  const double E = 0.000001;
  double l;
  const double TERMINADOR = -1.0;
  Cuadrado cuadrado;
  VectorCuadrados vector;
	
  do {
    cout << "Lado del cuadrado, pulse " << TERMINADOR << " para finalizar: ";
    cin >> l;
  } while(l < 0);
	
  int i = 0;
	
  while(abs(l - TERMINADOR) > E) {
		
    cuadrado.setLado(l);
		
    vector.aniade(cuadrado);
    i++;
		
    do {
      cout << "Lado del cuadrado, pulse " << TERMINADOR << " para finalizar: ";
      cin >> l;
    } while(l < 0 && abs(l-TERMINADOR) > E);
  }
		
  vector.ordenaAreaAscendente();
	
  cout << "Áreas de los cuadrados ordenadas: " << endl << endl;
	
  for (int j = 0; j < i; j++)
    cout << "\t" << vector.getCuadrado(j).area();
}
