/* Programa que elimina todas las apariciones del carácter introducido
   en el texto elegido. */
	
#include<iostream>

using namespace std;

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
   
  void EliminaOcurrencia(char a_borrar) {
   	
    int escritura = 0;
    int eliminados = 0;
   	
    for(int lectura = 0; lectura < total_utilizados; lectura++) {
   		
      if(vector_privado[lectura] != a_borrar) {
	Modifica(escritura, vector_privado[lectura]);
	escritura++;
      }
      else {
	eliminados++;
      }
    }
    total_utilizados = total_utilizados - eliminados;
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
    //cadena = cadena + vector_privado[i];  <- Evitarlo. Muy ineficiente para tamaños grandes

    return cadena;
  }

  int PrimeraOcurrenciaEntre (int pos_izda, int pos_dcha, char buscado){
    int i = pos_izda;
    bool encontrado = false;

    while (i <= pos_dcha  &&  !encontrado)
      if (vector_privado[i] == buscado)
	encontrado = true;
      else
	i++;

    if (encontrado)
      return i;
    else
      return -1;
  }
   
  int PrimeraOcurrencia (char buscado){
    return PrimeraOcurrenciaEntre (0, total_utilizados - 1, buscado);
  }
   
  int BusquedaBinaria (char buscado){
    int izda, dcha, centro;
    bool encontrado = false;

    izda = 0;
    dcha = total_utilizados - 1;
    centro = (izda + dcha) / 2;

    while (izda <= dcha  &&  !encontrado){
      if (vector_privado[centro] == buscado)
	encontrado = true;
      else if (buscado < vector_privado[centro])
	dcha = centro - 1;
      else
	izda = centro + 1;

      centro = (izda + dcha) / 2;
    }

    if (encontrado)
      return centro;
    else
      return -1;
  }
};

int main() {
	
  const char TERMINADOR = '#';
  char caracter, a_borrar;
  SecuenciaCaracteres secuencia;
	
  cout << "Introduzca secuencia de caracteres, pulse " << TERMINADOR << " para finalizar: ";
  caracter = cin.get();
	
  int i = 0;
	
  while (caracter != TERMINADOR) {
		
    secuencia.Aniade(caracter);
    i++;
		
    caracter = cin.get();
  }
	
  cout << "¿Qué caracter quiere eliminar? ";
  a_borrar = cin.get();
	
  secuencia.EliminaOcurrencia(a_borrar);
	
  cout << "La secuencia ahora queda así: " << endl << endl;
	
  cout << secuencia.ToString();
}
