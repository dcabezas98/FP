/* Programa que elimina los caracteres entre dos posiciones de un
   vector. */

#include<iostream>

using namespace std;

class SecuenciaCaracteres{
private:
  static const int TAMANIO = 50;
  char vector_privado[TAMANIO];
  int total_utilizados;

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

  void Aniade(char nuevo){
    if (total_utilizados < TAMANIO){
      vector_privado[total_utilizados] = nuevo;
      total_utilizados++;
    }
  }

  void EliminaBloque(int pos1, int pos2) {

    int num_a_borrar = pos2 - pos1 + 1;

    for(int i = pos2 + 1; i < total_utilizados; i++) {

      Modifica(i - num_a_borrar, vector_privado[i]);
    }

    total_utilizados = total_utilizados - num_a_borrar;
  }

  char Elemento(int indice){
    return vector_privado[indice];
  }

  void Modifica(int posicion, char nuevo){
    if (posicion >= 0 && posicion < total_utilizados)
      vector_privado[posicion] = nuevo;
  }

  void Inserta(int pos_insercion, char valor_nuevo){
    if (total_utilizados < TAMANIO  &&  pos_insercion >= 0
	&&  pos_insercion <= total_utilizados){

      for (int i = total_utilizados ; i > pos_insercion ; i--)
	vector_privado[i] = vector_privado[i-1];

      vector_privado[pos_insercion] = valor_nuevo;
      total_utilizados++;
    }
  }
};

int LeeIntMayorQue(int menor) {

  int mayor;

  do {
    cin >> mayor;
  } while (mayor < menor);

  return mayor;
}

int LeeIntPositivo() {

  int num;

  do{
    cin >> num;
  } while(num < 0);

  return num;
}

int main() {

  char TERMINADOR = '#';
  SecuenciaCaracteres secuencia;
  char caracter;
  int pos1, pos2;

  cout << "Introduzca secuencia de caracteres, pulse " << TERMINADOR << " para finalizar." << endl;
  caracter = cin.get();

  int j = 0;

  while (caracter != TERMINADOR) {

    secuencia.Aniade(caracter);
    j++;
    caracter = cin.get();
  }

  do {
    cout << "Primera posición del bloque a eliminar: ";
    pos1 = LeeIntPositivo();
  } while(pos1 >= j);

  do {
    cout << "Última posición del bloque a eliminar: ";
    pos2 = LeeIntMayorQue(pos1);
  } while(pos2 >= j);

  secuencia.EliminaBloque(pos1, pos2);

  cout << "Nueva secuencia: " << endl;

  for(int i = 0; i < secuencia.TotalUtilizados(); i++) {
    cout << secuencia.Elemento(i);
  }

  cout << endl << "    utilizados    " <<secuencia.TotalUtilizados();
}
