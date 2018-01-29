/*
  Implementaci�n de la clase Avion, incluye m�todos para consultar la
  disponibilidad de los asientos y para marcarlos como ocupados.
 */

#include<iostream>
using namespace std;

class Avion {
	
private:
		
  static const int FILAS = 7;
  static const int COLUMNAS = 4;
  static const int CAPACIDAD = FILAS * COLUMNAS;
  int pasajeros;
  bool matriz[FILAS][COLUMNAS] = {{}}; // Inicializo todos los asientos a no ocupados
  int ocupados;
		
  bool ocupado_priv(int i, int j) {   
    return matriz[i][j];
  }
		
public:
		
  /* Constructor */
  Avion() :ocupados(0) {}
		
  /* M�todos get */
  void muestra() {
			
    int pasillo = COLUMNAS / 2;
    char letra;
			
    for(int i = 0; i < FILAS; i++) {
				
      cout << i+1 << " | ";
				
      for(int j = 0; j < COLUMNAS; j++) {
					
	if(j == pasillo)
	  cout << "| ";
					   
	if(ocupado_priv(i,j)) // Llamo al privado porque s� que las variables no van a salirse de los l�mites
	  cout << "X ";
					
	else {
	  letra = j+'A'; // Para que sea m�s c�modo trabajar en fase de ejecuci�n
	  cout << letra << " ";
	}
      }
      cout << "\n";
    }
  }
		
  bool ocupado(int i, char a) {
    return ocupado_priv(i-1, a-'A');    
  }
		
  int filas() {
    return FILAS;
  }
		
  int columnas() {
    return COLUMNAS;
  }
		
  int numero_ocupados() {
    return ocupados;
  }
		
  int capacidad() {
    return CAPACIDAD;
  }
		
  /* M�todos set */
  void sienta(int i, char a) {
    if(i-1 >= 0 && i-1 < FILAS && a-'A' >= 0 && a-'A' < COLUMNAS) {
      matriz[i-1][a-'A'] = true;
      ocupados++;
    }
  }
};

int main() {
	
  const int TERMINADOR = -1;
  Avion avion;
  int fila;
  char asiento;
	
  avion.muestra();
	
  do { // Lectura anticipada
    cout << "Fila (introduzca " << TERMINADOR << " para finalizar): ";
    cin >> fila;
  } while((fila < 1 || fila > avion.filas()) && fila != TERMINADOR); // Filtro de entrada
	
  while(fila != TERMINADOR && avion.numero_ocupados() < avion.capacidad()) {
		
    do {                                                      
      cout << "Asiento: ";
      cin >> asiento;
      asiento = toupper(asiento);
    } while(asiento < 'A' || asiento >= 'A'+ avion.columnas()); // Filtro tambi�n las columnas
		
    if(avion.ocupado(fila, asiento)) // Mensaje informativo, en caso de que el asiento est� ocupado
      cout << "Asiento ocupado, seleccione otro.\n";
         
    else 
      avion.sienta(fila, asiento); // si est� libre, se sienta a la persona
		   
    avion.muestra(); // Se muestra el plano del avi�n
      
    do {   
      cout << "Fila (introduzca " << TERMINADOR << " para finalizar): "; // Se vuelven a solicitar datos
      cin >> fila;
    } while((fila < 1 || fila > avion.filas()) && fila != TERMINADOR);
  }
	
  if(avion.numero_ocupados() == avion.capacidad()) // En caso de que el programa termine porque se llena el avi�n, se informa de ello
    cout << "Se ha superado la capacidad m�xima del avion.\n";
}		
