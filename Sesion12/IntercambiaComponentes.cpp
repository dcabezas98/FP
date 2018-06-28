/* Programa que lee una secuencia de caracteres y dos enteros
   correspondientes a posiciones en la secuencia y devuelve la
   secuencia antes y después de intercambiar los caracteres en
   dichas posiciones. En los ejercicios anteriores ya había usado
   este método para invertir secuencias. */

#include<iostream>
#include<string>

using namespace std;

// Secuencia de caracteres

class SecuenciaCaracteres{
private:
  static const int TAMANIO = 50;
  char vector_privado[TAMANIO];
  int total_utilizados;

public:
  SecuenciaCaracteres()
    :total_utilizados(0) {
  }

  void IntercambiaComponentes(int pos_1, int pos_2){
    char aux;

    aux = vector_privado[pos_1];
    vector_privado[pos_1] = vector_privado[pos_2];
    vector_privado[pos_2] = aux;
  }

  void Invierte() {

    int tope = total_utilizados / 2;

    for(int contador = 0; contador <= tope; contador++) { // Se van intercambiando cada pareja de caracteres.

      IntercambiaComponentes(contador, total_utilizados - 1 - contador);

    }
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
    /*
      cadena = cadena + vector_privado[i] <- Evitarlo. Muy ineficiente para
      tamaños grandes
    */

    return cadena;
  }
};

int main() {

  const int TAMANIO = 50;
  const char TERMINADOR = '#';
  SecuenciaCaracteres caracteres;
  char caracter;
  int pos_1, pos_2;
  string antes;
  string despues;

  cout << "Inserte caracteres, pulse \"" << TERMINADOR << "\" para terminar: ";
  caracter = cin.get();

  int posicion = -1; // Cuando entre en el bucle, quedará en 0, de esta forma evito que la posición aumente cuando se introduzca el terminador.

  while (caracter != TERMINADOR && posicion < TAMANIO) { // Si se introducen 100 caracteres, el bucle de lectura termina.

    posicion++;

    caracteres.Aniade(caracter);

    caracter = cin.get();
  }

  do {
    cout << "Posición del primer caracter a intercambiar (la secuencia empieza en 0): ";
    cin >> pos_1;
  } while (pos_1 < 0 || pos_1 >= caracteres.TotalUtilizados() - 1);

  do {
    cout << "Posición del segundo caracter a intercambiar: ";
    cin >> pos_2;
  } while (pos_2 < 0 || pos_2 >= caracteres.TotalUtilizados() - 1);

  antes = caracteres.ToString();

  caracteres.IntercambiaComponentes(pos_1, pos_2);

  despues = caracteres.ToString();

  cout << "\n\n\tAntes:" << "\n\n\t" << antes << endl;

  cout << "\n\n\tDespués:" << "\n\n\t" << despues << endl;
}
