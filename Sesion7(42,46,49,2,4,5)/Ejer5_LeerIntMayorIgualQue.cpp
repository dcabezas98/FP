/* Programa que usa una funci�n para leer dentro de un intervalo
	3 valores y los suma. */

#include<iostream>

using namespace std;

int LeeIntRango (int min, int max) {

	int numero;
	
	do {
		cout << "Inserte n�mero entre " << min << " y " << max << ": ";
		cin >> numero;
	} while ( numero < min || numero > max);
	
	return numero;
}

int LeeIntMayorIgualQue (int min) {
	
	int numero;
	
	do {
		cout << "Inserte n�mero mayor o igual a " << min << ": ";
		cin >> numero;
	} while (numero < min);
	
	return numero;
}
	
int main () {
	
	int min, max, sumando, suma;
	const int NO_SUMANDOS = 3;
	
	do {
		cout << "Inserte valor m�nimo del intervalo: ";
		cin >> min;
	} while (min < 0);
	
	max = LeeIntMayorIgualQue(min);
		
	suma = 0;
	
	for (int contador = 1; contador <= NO_SUMANDOS; contador++) {
		
		sumando = LeeIntRango(min, max);
		suma += sumando;
	}
	
	cout << "La suma de los tres valores introducidos es : " << suma << endl;
}
	
