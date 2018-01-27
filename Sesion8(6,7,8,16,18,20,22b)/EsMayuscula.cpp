/* Programa que lee una secuencia de caracteres hasta que se introduzca
   un terminador y devuelve el número de letras mayúsculas introducidas
   en dicha secuencia. */

#include<iostream>

using namespace std;

const char TERMINADOR = '#';

bool EsMayuscula (char letra) {
  bool es_mayuscula = false;
		
  if ((letra >= 'A' && letra <= 'Z') || letra == 'Ñ')
    es_mayuscula = true;
	
  return es_mayuscula;
}

char LeeMayuscula () {
  char letra;
	
  do {
    cout << "Inserte letra mayúscula: ";
    cin >> letra;
  } while (letra < 'A' && letra > 'Z' && letra != 'Ñ' && letra != TERMINADOR);
	
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
	
  cout << "Se han introducido " << numero_mayusculas << " letras mayúsculas." << endl;
}
