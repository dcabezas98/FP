/* Programa que lee una secuencia cifradada de caracteres y devuelve
   el número de series ascendentes que contiene. */

#include <iostream>

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

  int seriesAscendentes() {

    int ascendentes = 0;

    if(utilizados > 0)
      ascendentes++;

    for(int i = 1; i < utilizados; i++) {
      if(vector[i-1] > vector[i])
	ascendentes++;
    }

    return ascendentes;
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

  cout << "Número de series ascendentes: " << secuencia.seriesAscendentes() << endl;
}
