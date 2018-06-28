/* Programa que lee una secuencia de caracteres y devuelve el que más
   se repite y las veces que lo hace. */

#include<iostream>

using namespace std;

struct FrecuenciaCaracter {
  char caracter;
  int frecuencia;
};

int main() {

  const int PRIMER_ASCII = 32; // Correspondiente al espacio en blanco
  const int ULTIMO_ASCII = 173; // Correspondiente a "¡"
  const char TERMINADOR = '#';
  const int TAMANIO = 2500000;
  char caracter;
  char caracteres[TAMANIO];
  FrecuenciaCaracter candidatos[ULTIMO_ASCII - PRIMER_ASCII + 1]; // Para almacenar los caracteres procesados
  FrecuenciaCaracter moda;

  cout << "Inserte caracter o pulse \"" << TERMINADOR << "\" para terminar: ";
  caracter = cin.get();

  int posicion = -1;

  while (caracter != TERMINADOR && posicion < TAMANIO) {

    posicion++;

    caracteres[posicion] = caracter;

    caracter = cin.get();
  }

  for(int contador = PRIMER_ASCII; contador <= ULTIMO_ASCII; contador++) { // Recorro los distintos caracteres pos sus códigos ASCII

    int veces = 0;
    caracter = contador;

    for(int i = 0; i <= posicion; i++) { // Recorro el vector por cada caracter
      if (caracteres[i] == caracter)
	veces++; // Cuento las veces que se repite
    }

    FrecuenciaCaracter x; // Lo almaceno en una variable del tipo FrecuenciaCaracter
    x.caracter = caracter;
    x.frecuencia = veces;
    candidatos[contador - PRIMER_ASCII] = x; // Añado ese dato al vector
  }

  moda = candidatos[0]; // Escojo un caracter cualquiera como moda incial

  for(int i = 1; i < ULTIMO_ASCII - PRIMER_ASCII + 1; i++) {

    if (candidatos[i].frecuencia > moda.frecuencia) // Si alguno lo supera en frecuencia, se convierte en la moda
      moda = candidatos[i];
  }

  cout << "El caracter que más se repite es \" " << moda.caracter << " \" con " << moda.frecuencia << " veces." << endl;
}
