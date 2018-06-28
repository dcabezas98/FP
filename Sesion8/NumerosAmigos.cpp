/* Dos números son amigos cuando cada uno es igual a la suma
   de los divisores propios del otro considerando el 1.
   Este programa lee dos números y dice si son amigos y a
   continuación lee un tercero y busca en un intervalo centrado
   en ese número amigos del mismo. */

#include<iostream>

using namespace std;

int LeeIntPositivo () {
  int numero;
  do {
    cout << "Inserte número positivo: ";
    cin >> numero;
  } while (numero < 0);
  return numero;
}

int SumaDivisoresPropios (int numero) {

  int suma_divisores_propios = 0;

  for (int contador = numero / 2; contador > 1; contador--) {
    if (numero % contador == 0)
      suma_divisores_propios += contador;
  }
  return suma_divisores_propios;
}

bool SonAmigos (int numero1, int numero2) {

  bool son_amigos = false;
  int suma_divisores_propios1, suma_divisores_propios2;

  suma_divisores_propios1 = SumaDivisoresPropios(numero1);
  suma_divisores_propios2 = SumaDivisoresPropios(numero2);

  if (numero1 == suma_divisores_propios2 + 1 && numero2 == suma_divisores_propios1 + 1)
    son_amigos = true;

  return son_amigos;
}

int main () {

  const int RANGO_BUSQUEDA = 3;

  int numero1, numero2, numero3;
  bool son_amigos = false;

  cout << "Inserte primer número." << endl;
  numero1 = LeeIntPositivo();

  cout << "Inserte segundo número." << endl;
  numero2 = LeeIntPositivo();

  son_amigos = SonAmigos(numero1, numero2);

  if (son_amigos == true)
    cout << numero1 << " y " << numero2 << " son números amigos." << endl;

  else {
    cout << numero1 << " y " << numero2 << " no son amigos." << endl;
  }

  son_amigos = false; // La reinicializo para reutilizarla
  cout << "Inserte otro número." << endl;
  numero3 = LeeIntPositivo();

  for (int contador = numero3 - RANGO_BUSQUEDA; contador <= numero3 + RANGO_BUSQUEDA; contador++) {
    if (SonAmigos(numero3, contador)) {

      if (numero3 != contador)
	cout << numero3 << " y " << contador << " son números amigos." << endl;

      else {
	cout << numero3 << " es un número perfecto (amigo de sí mismo)" << endl;
      }
      son_amigos = true;
    }
  }
  if (son_amigos == false)
    cout << numero3 << " no tiene amigos dentro del rango." << endl;
}
