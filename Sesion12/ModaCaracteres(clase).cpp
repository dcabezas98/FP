/* Programa que lee una secuencia de caracteres y devuelve el que más
   se repite y las veces que lo hace. */

#include<iostream>

using namespace std;

struct FrecuenciaCaracter {
  char caracter;
  int frecuencia;
};

// Secuencia de caracteres

class SecuenciaCaracteres{

private:

  static const int TAMANIO = 2500000;
  char vector_privado[TAMANIO];
  int total_utilizados;

  void IntercambiaComponentes_en_Posiciones(int pos_izda, int pos_dcha){
    char intercambia;

    intercambia = vector_privado[pos_izda];
    vector_privado[pos_izda] = vector_privado[pos_dcha];
    vector_privado[pos_dcha] = intercambia;
  }

public:

  SecuenciaCaracteres()
    :total_utilizados(0) {
  }

  int TotalUtilizados(){
    return total_utilizados;
  }

  int Capacidad(){
    return TAMANIO;
  }

  void EliminaTodos(){
    total_utilizados = 0;
  }

  FrecuenciaCaracter Moda() {

    const int PRIMER_ASCII = 32; // Correspondiente al espacio en blanco
    const int ULTIMO_ASCII = 173; // Correspondiente a "¡"
    FrecuenciaCaracter candidatos[ULTIMO_ASCII - PRIMER_ASCII + 1]; // Para almacenar los caracteres procesados
    FrecuenciaCaracter moda;
    char caracter;

    for(int contador = PRIMER_ASCII; contador <= ULTIMO_ASCII; contador++) { // Recorro los distintos caracteres pos sus códigos ASCII

      int veces = 0;
      caracter = contador;

      for(int i = 0; i <= total_utilizados; i++) { // Recorro el vector por cada caracter
	if (Elemento(i) == caracter)
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

    return moda;
  }

  void Aniade(char nuevo){
    if (total_utilizados < TAMANIO){
      vector_privado[total_utilizados] = nuevo;
      total_utilizados++;
    }
  }

  void Modifica(int posicion, char nuevo){
    if (posicion >= 0 && posicion < total_utilizados)
      vector_privado[posicion] = nuevo;
  }

  char Elemento(int indice){
    return vector_privado[indice];
  }

  string ToString(){
    // Si el número de caracteres en memoria es muy grande,
    // es mucho más eficiente reservar memoria previamente
    // y usar push_back

    string cadena;

    cadena.reserve(total_utilizados);

    for (int i=0; i < total_utilizados; i++)
      cadena.push_back(vector_privado[i]);
    //cadena = cadena + vector_privado[i]  <- Evitarlo. Muy ineficiente para tamaños grandes;

    return cadena;
  }
};

int main() {

  const char TERMINADOR = '#';
  char caracter;
  SecuenciaCaracteres caracteres;
  FrecuenciaCaracter moda;

  cout << "Inserte caracteres,\"" << TERMINADOR << "\" para terminar: ";
  caracter = cin.get();

  int posicion = -1;

  while (caracter != TERMINADOR && posicion < caracteres.Capacidad()) { // Si se introducen 100 caracteres, el bucle de lectura termina.

    posicion++;

    caracteres.Aniade(caracter);

    caracter = cin.get();
  }

  moda = caracteres.Moda();

  cout << "El caracter que más se repite es \" " << moda.caracter << " \" con " << moda.frecuencia << " veces." << endl;
}
