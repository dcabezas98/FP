/* Programa que lee una secuencia cifrada de caracteres y la
   descodifica cogiendo la primera y la última letra de cada
   palabra, y sólo la primera en el caso de que la última palabra
   no tenga espacios en blanco a la derecha. */
	
#include<iostream>

using namespace std;

class SecuenciaCaracteres {
	
private:
		
  static const int TAMANIO = 1000;
  char vector[TAMANIO];
  int utilizados;
		
public:
		
  SecuenciaCaracteres() {
    utilizados = 0;
  }
      
  void aniade(char caracter) {
      	
    if(utilizados < TAMANIO) {      	
      vector[utilizados] = caracter;
      utilizados++;
    }
  }
      
  char elemento(int pos) {
      	
    if(pos >= 0 && pos < utilizados) {
      		
      return vector[pos];
    }
  }
      
  int busqueda_secuencial_desde(int pos_inicial, char caracter) {
      	
    bool encontrado = false;
    int pos_buscada = -1;
      	
    for(int i = pos_inicial; i < utilizados && !encontrado; i++) {
      		
      if(caracter == vector[i]) {
	encontrado = true;
	pos_buscada = i;
      }
    }
    return pos_buscada;
  }
     
  string descodifica() {
      	
    string mensaje;
    int i = 1; // Posición del último espacio al que llegué.
    int j = 0; // Posición por la que voy recorriendo el vector.
    mensaje = mensaje + vector[0];  	
      	
    while(i < utilizados - 1 && i != -1) {
         
      i = busqueda_secuencial_desde(j, ' ');
            
      if (i != -1) {
	mensaje = mensaje + vector[i - 1];
	mensaje = mensaje + vector[i + 1];
      		
	j = i + 1;
      }
    }
    return mensaje;
  }
};

int main() {
	
  const char TERMINADOR = '#';
  char caracter;
  SecuenciaCaracteres secuencia;
	
  cout << "Inserte secuencia de caracteres, pulse " << TERMINADOR << " para finalizar:" << endl;
  caracter = cin.get();
   
  int i = 0;
   
  while(caracter != TERMINADOR) {
   	
    secuencia.aniade(caracter);
    i++;
    caracter = cin.get();
  }
 	
  cout << endl << "Secuencia descodificada: " << secuencia.descodifica() << endl;
 	
  system("pause");
}
 	
