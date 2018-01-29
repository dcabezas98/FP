/* Programa que lee una secuencia de reales hasta que se introduzca un
   terminador, a continuación lee un real de referencia y un entero k
   y devuelve los k primeros valores de la secuencia mayores que la
   diferencia. */
	
#include<iostream>

using namespace std;

static const int TAMANIO = 10000;

class SecuenciaReales {
	
private:
		
  double vector[TAMANIO];
  int utilizados;
		
				
  void swap(int pos1, int pos2) {
			
    double aux = vector[pos1];
    vector[pos1] = vector[pos2];
    vector[pos2] = aux;
  }
		
  int buscaMinimoEntre(int pos1, int pos2) {   
			
    int pos_min = pos1;
			
    for (int i = pos1; i <= pos2; i++) {
				
      if (vector[i] < vector[pos_min]) {
	pos_min = i;
      }
    }
    return pos_min;
  }
		
  void inserta(double num, int pos) {
	   
    for(int i = utilizados; i > pos; i--) {
      vector[i] = vector[i - 1];
    }
    vector[pos] = num;
    utilizados++;
  }
	
public:
		
  void InsertaOrdenadamente(double valor_nuevo){
    int i;

    if (utilizados < TAMANIO) {
      for (i=utilizados; i>0 && valor_nuevo < vector[i-1]; i--)
	vector[i] = vector[i-1];

      vector[i] = valor_nuevo;
      utilizados++;
    }
  }
							
  SecuenciaReales() {
    utilizados = 0;
  }
		
  void aniade(double x) {
    vector[utilizados] = x;
    utilizados++;
  }
		
  double elemento(int pos) {
			
    return vector[pos];
  }
			
  void ordenaAscendente() {
			 
    for (int i = 0; i < utilizados - 1 ; i++) { // Recorro el vector de izquierda a derecha
				
      int pos_menor = buscaMinimoEntre(i, utilizados - 1); // Busco el mínimo de los que haya sin ordenar
      swap(i, pos_menor); // Lo coloco en la siguiente posición 
    }
  }
};

int main() {
	
  const int TERMINADOR = -1;
  double valor, referencia;
  int k;
  SecuenciaReales secuencia;
  SecuenciaReales mayores;
	
  cout << "Inserte secuencia de números reales separados con espacios, pulse " << TERMINADOR << " para terminar." << endl;
  cin >> valor;
	
  int i = 0;
	
  while (valor != TERMINADOR) {                        
		
    secuencia.aniade(valor);
		
    i++;
		
    cin >> valor;
  }
	
  cout << "Inserte valor de referencia: ";
  cin >> referencia;
	
  do {
    cout << "Inserte valor de k: ";
    cin >> k;
  } while (k < 0);
	
  int elementos_restantes = k;
	
  for (int j = 0; j < i && elementos_restantes > 0; j++) { // Recorro el vector de izquierda a derecha
		
    if (secuencia.elemento(j) > referencia) {
      mayores.InsertaOrdenadamente(secuencia.elemento(j));
      elementos_restantes--; // k es igual al número de valores que quedan por buscar
    }
  }
	
  cout << endl << "\t" << k << " primeros números mayores que " << referencia << ":" << endl << endl; // Lo imprimo
  for(int index = 0; index < k; index++)
    cout << mayores.elemento(index) << "\t\t";			
}
