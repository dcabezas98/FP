/*
  Programa para probar la clase PuntoND, que implementa los métodos
  que esta incorporaba, pero adaptados para N dimensiones.
*/

#include<iostream>
#include<cmath>

using namespace std;

const int DIM_MAX = 50;

class PuntoND {
	
private:
		
  const int DIM;
  double coordenadas[DIM_MAX];
		
public:
		
  /* Constructores */
  PuntoND(int dim) :DIM(dim) {
  }
		
  /* Métodos set y get */
  void setCoordenada(int pos, double valor) {
			
    if (pos >= 0 && pos < DIM)
      coordenadas[pos] = valor;
  }
				
  double getCoordenada(int pos) {
			
    return coordenadas[pos];
  }
		
  double distanciaOrigen() { // Devuelve la distancia del punto al origen de coordenadas.
			
    double mod = 0;
			
    for(int i = 0; i < DIM; i++) {
      mod = mod + coordenadas[i] * coordenadas[i];
    }
			
    return sqrt(mod);		
  }
		
  double distancia (PuntoND p) {
			
    PuntoND vector(DIM);
			
    for (int i = 0; i < DIM; i++) {
				
      double valor = abs(getCoordenada(i) - p.getCoordenada(i));
				
      vector.setCoordenada(i,valor);
    }
			
    return vector.distanciaOrigen();
  }
				
  void leeCoordenadas() {
			
    double coord;
			
    for (int i = 0; i < DIM; i++) {
				 
      cout << "Inserte coordenada " << i + 1 << ": ";
      cin >> coord;
		      
      setCoordenada(i, coord);
    }
  }
};

		
int main() {
	
  int dim;
	
  cout << "¿En qué dimensión quiere trabajar? ";
  cin >> dim;
	
  PuntoND A(dim);
	
  A.leeCoordenadas();
	
  cout << "Distancia de A al origen: " << A.distanciaOrigen() << endl;
	
  PuntoND B(dim);
	
  cout << "Coordenadas de un nuevo punto B: " << endl;
	
  B.leeCoordenadas();
	
  cout << "Distancia de B al origen: " << B.distanciaOrigen() << endl;
  cout << "Distancia de A a B: " << A.distancia(B) << endl;	
} 		
