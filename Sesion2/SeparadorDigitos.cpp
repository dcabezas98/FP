/* Programa que imprime separados dos espacios
   los dígitos del número de 3 cifras introducido
   por el usuario */

#include <iostream>     // Inclusión recursos E/S

using namespace std;

int main() {
  int numero;           // Declaración de variables
  int unidades;
  int decenas;
  int centenas;

  cout << "Introduzca un número de 3 cifras: ";     // Se solicita la información
  cin >> numero;

  centenas = numero / 100;                                // Operaciones basadas en que cualquier número abc puede expresarse
  decenas = (numero - centenas * 100) / 10;               // como 100a + 10b + c. Aprovechando el truncamiento que realiza
  unidades = numero - centenas * 100 - decenas * 10;      // el programa al asignar un número decimal a una variable int.

  cout<< "  " << centenas << "  " << decenas << "  " << unidades << "\n";    // Se expresan las cifras por separado
}
