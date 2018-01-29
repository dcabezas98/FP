/* Programa que lee y almacena texto en objetos del tipo
   SecuenciaCaracteres, cuenta con clases específicas para operaciones
   de E/S. */

#include<iostream>
using namespace std;

const int TAMANIO = 1000;
   
class SecuenciaCaracteres {
	
private:
		
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
      
  int elementos_utilizados() {
    return utilizados;
  }
};

class ImpresorSecuenciaCaracteres { // Clase para imprimir secuencias
	
private:
				
  char inicio;
  char separador;
  char final;
		
public:
		
  ImpresorSecuenciaCaracteres(char ini, char fin, char sep) {
    inicio = ini;
    separador = sep;
    final = fin;
  }		
		
  void Imprime(SecuenciaCaracteres a_imprimir) {
			
    int i;
			
    cout << inicio;
    for(i = 0; i < a_imprimir.elementos_utilizados()-1; i++) {
      cout << a_imprimir.elemento(i) << separador;
    }
    cout << a_imprimir.elemento(i) << final << "\n";
  }
};

class LectorSecuenciaCaracteres { // Clase que crea secuencias que lee desde el teclado
	
private:
		
  const char TERMINADOR;
	
public:
		
  LectorSecuenciaCaracteres(char term): TERMINADOR(term) {
  }
		
  char Terminador() {
    return TERMINADOR;
  }
		
  SecuenciaCaracteres Lee() {
			
    SecuenciaCaracteres secuencia;
    char caracter;
			
    cin >> caracter;
						
    while(caracter != TERMINADOR) {
				
      secuencia.aniade(caracter);
				
      cin >> caracter;
    }
			
    return secuencia;
  }
};
		
class Texto {
	
private:
		
  int lineas;
  int utilizados[TAMANIO] = {};
  char matriz[TAMANIO][TAMANIO];
		
public:
		
  void Aniade(SecuenciaCaracteres linea) {
				
    for(int j = 0; j < linea.elementos_utilizados(); j++) {
      matriz[lineas][j] = linea.elemento(j);				
      utilizados[lineas]++;
    }
    lineas++;
  }
		
  SecuenciaCaracteres Fila(int i) {
			
    SecuenciaCaracteres fila;
			
    for(int j = 0; j < utilizados[i]; j++)
      fila.aniade(matriz[i][j]);
			
    return fila;
  }
};

int main() {
	
  int lineas;
	
  LectorSecuenciaCaracteres lector('.');
  SecuenciaCaracteres frase;
  Texto texto;
   
  cout << "Líneas a leer: ";
  cin >> lineas;
	
  int i;
	             
  cout << "Escriba su secuencia (" << lector.Terminador() << ") para finalizar:\n";
  for(i = 0; i < lineas; i++) {
	   
    frase = lector.Lee(); // leo cada secuencia
    texto.Aniade(frase); // La añado al texto
  }
	
  ImpresorSecuenciaCaracteres impresor('[',']','-');
	
  for(i = 0; i < lineas; i++) {
		
    impresor.Imprime(texto.Fila(i)); // Imprimo las secuencias
  }		
}		
