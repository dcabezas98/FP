/* Programa que imprime separados dos espacios
   los d�gitos del n�mero de 3 cifras introducido
   por el usuario*/
   
#include <iostream>     // Inclusi�n recursos E/S

using namespace std;    

int main() {
	int numero;           // Declaraci�n de variables
	int unidades;
	int decenas;
	int centenas;
	
	cout << "Introduzca un n�mero de 3 cifras: ";     // Se solicita la informaci�n
	cin >> numero;
	
 	centenas = numero / 100;                                // Operaciones basadas en que cualquier n�mero abc puede expresarse
	decenas = (numero - centenas * 100) / 10;               // como 100a + 10b + c. Aprovechando el truncamiento que realiza
	unidades = numero - centenas * 100 - decenas * 10;      // el programa al asignar un n�mero decimal a una variable int. 
	
	cout<< "  " << centenas << "  " << decenas << "  " << unidades << "\n";    // Se expresan las cifras por separado
	
	system ("pause");
}
	
