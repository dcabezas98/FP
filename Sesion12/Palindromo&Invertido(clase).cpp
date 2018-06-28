/* Programa que dice si una secuencia de carácteres introducida es un
   palíndromo y, en caso negativo, devuelve la secuencia
   invertida. Estaos algoritmos están como métodos de clase
   EsPalindromo en la línea 30 e Invierte en la línea 45 */

#include<iostream>

using namespace std;

// Secuencia de caracteres

class SecuenciaCaracteres{
private:
  static const int TAMANIO = 50;
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

  bool EsPalindromo() {

    bool palindromo = true;

    /*
      Si a mitad del recorrido del vector no se han encontrado, un par
      de caracteres que verifique que no sea pal�ndromo no va a
      encontrarse a partir de ese punto.
     */
    int tope = total_utilizados / 2;

    for(int contador = 0; contador <= tope && palindromo == true; contador++) {

      if (vector_privado[contador] != vector_privado[total_utilizados - 1 - contador]) // Recorro el vector desde ambos extremos.
	palindromo = false; // Si se da este caso, se detiene el bule.
    }

    return palindromo;
  }

  void Invierte() {

    int tope = total_utilizados / 2;

    for(int contador = 0; contador <= tope; contador++) { // Se van intercambiando cada pareja de caracteres.

      IntercambiaComponentes_en_Posiciones(contador, total_utilizados - 1 - contador);

    }
  }

  int TotalUtilizados(){
    return total_utilizados;
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
};

int main() {

  const int TAMANIO = 50;
  const char TERMINADOR = '#';
  SecuenciaCaracteres caracteres;
  char caracter;

  cout << "Inserte caracter o pulse \"" << TERMINADOR << "\" para terminar: ";
  caracter = cin.get();

  int posicion = -1; // Cuando entre en el bucle, quedará en 0, de esta forma evito que la posición aumente cuando se introduzca el terminador.

  while (caracter != TERMINADOR && posicion < TAMANIO) { // Si se introducen 100 caracteres, el bucle de lectura termina.

    posicion++;

    caracteres.Aniade(caracter);

    cout << "Inserte caracter o pulse \"" << TERMINADOR << "\" para terminar: ";
    cin >> caracter;
  }

  if (caracteres.EsPalindromo())
    cout << "La secuencia es un palíndromo." << endl;

  else { // Se procede al algoritmo de inversión.

    caracteres.Invierte();

    cout << "La secuencia no es un palíndromo. Secuencia invertida: " << endl;

    for(int contador = 0; contador <= caracteres.TotalUtilizados(); contador++)
      cout << caracteres.Elemento(contador);
  }
}
