/* Programa que convierte los grados Celsius introducidos
	a grados Fahrenheit Kelvin o Rankine. Según se introduzca
	F, K o R. */
	
	#include<iostream>
	#include<cmath>
	
	using namespace std;
	
	int main () {
		
		double celsius, fahrenheit, kelvin, rankine;
		char unidad;
		
		cout << "Introduzca grados Celsius: ";
		cin >> celsius;
		
		do {
			cout << "Quiere convertirlos a Fahrenheit, Kelvin o Rankine? (Introduzca F/K/R) ";
			cin >> unidad;
		} while ((unidad != 'F' && unidad != 'K') && unidad != 'R');
		
		switch (unidad) {
		
			case ('F'):
				fahrenheit = celsius * 9 / 5 + 32;
		   	cout << celsius << " grados Celsius equivale a: " << fahrenheit << " grados Fahrenheit.\n";
			break;
		
			case ('K'):
				kelvin = celsius + 273.5;
				cout << celsius << " grados Celsius equivale a: " << kelvin << " grados Kelvin.\n";
	   	break;
	   
	   	case ('R'):
	   		rankine = celsius * 9 / 5 + 491.67; 
	   		cout << celsius << " grados Celsius equivale a: " << rankine << " grados Rankine.\n";
	   	break;
	   }
}
