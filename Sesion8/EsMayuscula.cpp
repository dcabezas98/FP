/* Programa que lee una secuencia de caracteres hasta que se introduzca
   un terminador y devuelve el n�mero de letras may�sculas introducidas
   en dicha secuencia. */

#include<iostream>

using namespace std;

const char TERMINADOR = '#';

bool EsMayuscula (char letra) {
  bool es_mayuscula = false;
		
  if ((letra >= 'A' && letra <= 'Z') || letra == '�')
    es_mayuscula = true;
	
  return es_mayuscula;
}

char LeeMayuscula () {
  char letra;
	
  do {
    cout << "Inserte letra may�scula: ";
    cin >> letra;
  } while (letra < 'A' && letra > 'Z' && letra != '�' && letra != TERMINADOR);
	
  return letra;
}

int main () {
	
  int numero_mayusculas = 0;
  char letra;
	
  do {
    letra = LeeMayuscula ();
    if (EsMayuscula(letra))
      numero_mayusculas++;
  } while (letra != TERMINADOR);
	
  cout << "Se han introducido " << numero_mayusculas << " letras may�sculas." << endl;
}
