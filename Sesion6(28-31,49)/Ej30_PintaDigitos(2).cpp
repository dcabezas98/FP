/* Programa que imprime separadas dos espacios las
	cifras de cualquier número entero que se le introduzca */
	
	#include<iostream>
	#include<cmath>
	
	using namespace std;
	
	int main () {
		long long numero, numero_dividido;           // Para aumentar la capacidad del programa.
		int cifras = 1,
		digito, contador, divisor;
		
		do {
		cout << "Introduzca el número entero cuyas cifras quiere separar: ";
		cin >> numero;
		} while (numero < 0);
		
		numero_dividido = numero;                                     
		
		while (numero_dividido > 9) {
			numero_dividido = numero_dividido / 10;
			cifras++;
		}
		
		for (contador = 1; contador <= cifras; contador++) {              
			divisor = pow(10, (cifras - contador));						
			digito = numero / divisor;                                 // Extraigo la primera cifra.
			cout << "  " << digito;								              // la expulso.
			numero = numero % divisor;							              // Reduzco el número al resto de cifras.
		}		
	}
