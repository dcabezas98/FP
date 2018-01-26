/* Programa que estima la poblaci�n de un territorio a los
   ciertos a�os a partir de las tasas de de natalidad, mortalidad
   y migraci�n. Tambi�n calcula los a�os necesarios para que el 
	territorio doble su poblaci�n */
   
#include <iostream>     // Inclsi�n de recursos de E/S.
#include <cmath>			// Iclusi�n de recursos matem�ticos.

using namespace std;

int main() {
	long long poblacion_inicial, poblacion;                             
   int tasa_nat, tasa_mort, tasa_migracion;          
	int anos, anos_doble = 0;
	
	do { 
		cout << "Inserte poblaci�n inicial del territorio: ";   
		cin >> poblacion_inicial;
	} while (poblacion_inicial < 0);
	
   do {
		cout << "Inserte tasa de  natalidad: ";                 
		cin >> tasa_nat;
	} while (tasa_nat < 0 || tasa_nat > 1000);
	
	do {
		cout << "Inserte tasa de mortalidad: ";
		cin >> tasa_mort;
	} while (tasa_mort < 0 || tasa_mort > 1000);
	
	do {
		cout << "Inserte tasa de migraci�n: ";
		cin >> tasa_migracion;
	} while (tasa_migracion > 1000 || tasa_migracion < -1000);   // En el enunciado del ejercicio dice que debe ser positiva, sin embargo, tiene sentido considerar que exista emigraci�n.

	do {
		cout << "�Despu�s de c�antos a�os quiere calcular la poblaci�n del territorio? ";
		cin >> anos;
	} while (anos < 0);
	
	poblacion = poblacion_inicial;
	
	for (int contador = 1; contador <= anos; contador++ ) {
		poblacion = poblacion + ( poblacion * tasa_nat / 1000 ) - ( poblacion * tasa_mort / 1000 ) + ( poblacion * tasa_migracion / 1000 ); 
	}
	
	cout << "La poblaci�n estimada tras " << anos << " a�os es de: " << poblacion << " habitantes." << endl;
	
	poblacion = poblacion_inicial;                                // Se le restaura el valor a la poblaci�n para proceder al segundo c�lculo.
	
	while (poblacion < 2 * poblacion_inicial) {
		poblacion = poblacion + ( poblacion * tasa_nat / 1000 ) - ( poblacion * tasa_mort / 1000 ) + ( poblacion * tasa_migracion / 1000 );
		anos_doble++;
	}
	
	cout << "A�os para duplicar la poblaci�n: " << anos_doble << endl;
	cout << "Poblaci�n tras " << anos_doble << " a�os: " << poblacion << " habitantes." << endl;
}

/* El ejemplo del gui�n de pr�cticas considera la tasa de mortalidad como
   un incremento de la poblaci�n, por lo que es necesario especificar un signo
   negativo en la tasa, sin embargo este programa directamente considera que 
   las defunciones suponen un decrecimiento de la poblaci�n, por lo que a la tasa
   de mortalidad se le debe asignar un n�mero positivo. Solamente es necesario
   especificar el signo de la tasa de migraci�n ya que esta puede ser tanto negativa
   como positiva */
