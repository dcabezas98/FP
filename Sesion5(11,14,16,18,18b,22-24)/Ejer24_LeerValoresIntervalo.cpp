/* Programa que pide extremos de un intervalo, asegur�ndose de que
	el inferior sea positivo y que el superior sea mayor.
	A continuaci�n da 3 intentos para introducir un nuevo valor
	dentro del intervalo y calcula su diferencia con los extremos. */

#include<iostream>
#include<cmath>

using namespace std;

int main () {
	int min, max, nuevo_numero, contador,
	diferencia_min, diferencia_max;
	const int INTENTOS = 3;
	bool condicion_repeticion;
	
	do {
		cout << "Inserte valor m�nimo del intervalo: ";
		cin >> min;
	} while (min < 0);
	
	do {
		cout << "Inserte valor m�ximo del intervalo: ";
		cin >> max;
	} while (max <= min);
	
	contador = 1;
		
	do {
		cout << "Inserte nuevo valor dentro del intervalo: ";
		cin >> nuevo_numero;
		contador++;
	} while ((contador <= INTENTOS) && ((nuevo_numero < min) || (nuevo_numero > max)));
		
	condicion_repeticion = ((nuevo_numero < min) || (nuevo_numero > max));
		
	if (condicion_repeticion)
		cout << "Se ha superado el n�mero m�ximo de intentos permitidos.";
				
	else {
		diferencia_min = nuevo_numero - min;
		diferencia_max = max - nuevo_numero;
		cout << "Nuevo valor menos m�nimo: " << diferencia_min << endl;
		cout << "M�ximo menos nuevo valor: " << diferencia_max << endl;
	}
}
	
	
