/*
   Programa que almacena los nombres y notas de alumnos, cuenta con
   varios métodos, entre ellos uno para ordenar los alumnos de menor a
   mayor nota media. */

#include<iostream>

using namespace std;

const int TAMANIO = 100;

class SecuenciaCaracteres {

private:

  char vector[TAMANIO];
  int utilizados;

public:

  SecuenciaCaracteres() :utilizados(0) {}

  int numero_elementos() {
    return utilizados;
  }

  char elemento(int i) {
    return vector[i];
  }

  void aniade(char a) {

    if(utilizados < TAMANIO) {
      vector[utilizados] = a;
      utilizados++;
    }
  }

  bool contieneSecuencia(SecuenciaCaracteres secuencia) {

    bool contiene = false;
    int i, j;

    for(i = 0; i < utilizados && !contiene; i++) {

      if(vector[i] == secuencia.elemento(0)) {

	contiene = true;

	for(j = 1; j < secuencia.numero_elementos() && contiene; j++)
	  contiene = secuencia.elemento(j) == vector[i+j];
      }
    }
    return contiene;
  }
};

class SecuenciaEnteros {

private:

  int vector[TAMANIO];
  int utilizados;

public:

  SecuenciaEnteros() :utilizados(0) {}

  int elemento(int i) {
    return vector[i];
  }

  void aniade(int n) {

    if(utilizados < TAMANIO) {
      vector[utilizados] = n;
      utilizados++;
    }
  }

  int numero_elementos() {
    return utilizados;
  }
};

class Alumnos {

private:

  int alumnos;
  SecuenciaEnteros notas[TAMANIO];
  SecuenciaCaracteres nombre[TAMANIO];

public:

  int Numero_alumnos() {
    return alumnos;
  }

  SecuenciaCaracteres nombre_alumno(int i) {
    return nombre[i];
  }

  SecuenciaEnteros notas_alumno(int i) {
    return notas[i];
  }

  void swap(int i, int j) {

    SecuenciaCaracteres aux1 = nombre[i];
    nombre[i] = nombre[j];
    nombre[j] = aux1;

    SecuenciaEnteros aux2 = notas[i];
    notas[i] = notas[j];
    notas[j] = aux2;
  }

  SecuenciaEnteros buscar_alumnos(SecuenciaCaracteres secuencia) {

    SecuenciaEnteros compatibles;

    for(int i = 0; i < alumnos; i++) {

      if(nombre[i].contieneSecuencia(secuencia))
	compatibles.aniade(i);
    }

    return compatibles;
  }

  double media(int i) {

    double media = 0;

    for(int j = 0; j < notas[i].numero_elementos(); j++)
      media += notas[i].elemento(j);

    media = media / notas[i].numero_elementos();

    return media;
  }

  void ordenaPorMedia() {

    int i,j;
    bool cambio = true;

    for(i = 0; i < alumnos && cambio; i++) {
      for(j = alumnos-1, cambio = false; j > 0; j--) {

	if(media(j) < media(j-1)) {
	  swap(j,j-1);
	  cambio = true;
	}
      }
    }
  }

  void nuevoAlumno(SecuenciaCaracteres nom, SecuenciaEnteros nots) {

    if(alumnos < TAMANIO) {
      nombre[alumnos] = nom;
      notas[alumnos] = nots;
      alumnos++;
    }
  }
};

int main() {

  const char TERMINADOR1 = ',';
  const int TERMINADOR2 = -1;

  int numero_alumnos, nota;
  char caracter, i, j;

  cout << "Número alumnos: ";
  cin >> numero_alumnos;

  Alumnos alumnos;

  for(i = 0; i < numero_alumnos; i++) {

    SecuenciaCaracteres nombre;

    cout << "Nombre: (\"" << TERMINADOR1 << "\" para finalizar)\n";
    caracter = cin.get();

    while(caracter != TERMINADOR1) {

      nombre.aniade(caracter);
      caracter = cin.get();
    }

    cout << "Notas: (" << TERMINADOR2 << " para finalizar)\n";
    cin >> nota;

    SecuenciaEnteros notas;

    while(nota != TERMINADOR2) {

      notas.aniade(nota);
      cin >> nota;
    }

    alumnos.nuevoAlumno(nombre, notas);
  }

  alumnos.ordenaPorMedia();

  cout << "\nOrdenados por media (de menor a mayor)\n";

  for(i = 0; i < numero_alumnos; i ++) {

    for(j = 0; j < alumnos.nombre_alumno(i).numero_elementos(); j++)
      cout << alumnos.nombre_alumno(i).elemento(j);

    cout << ", (";

    for(j = 0; j < alumnos.notas_alumno(i).numero_elementos()-1; j++)
      cout << alumnos.notas_alumno(i).elemento(j) << ",";

    cout << alumnos.notas_alumno(i).elemento(j) << ")\n";
  }
}
