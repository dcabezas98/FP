/* Programa que estima la población de un territorio a los
   ciertos años a partir de las tasas de de natalidad, mortalidad
   y migración. También calcula los años necesarios para que el 
	territorio doble su población */
   
#include <iostream>     // Inclsión de recursos de E/S.
#include <cmath>			// Iclusión de recursos matemáticos.

using namespace std;

int main() {
	long long poblacion_inicial, poblacion;                             
   int tasa_nat, tasa_mort, tasa_migracion;          
	int anos, anos_doble = 0;
	
	do { 
		cout << "Inserte población inicial del territorio: ";   
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
		cout << "Inserte tasa de migración: ";
		cin >> tasa_migracion;
	} while (tasa_migracion > 1000 || tasa_migracion < -1000);   // En el enunciado del ejercicio dice que debe ser positiva, sin embargo, tiene sentido considerar que exista emigración.

	do {
		cout << "¿Después de cúantos años quiere calcular la población del territorio? ";
		cin >> anos;
	} while (anos < 0);
	
	poblacion = poblacion_inicial;
	
	for (int contador = 1; contador <= anos; contador++ ) {
		poblacion = poblacion + ( poblacion * tasa_nat / 1000 ) - ( poblacion * tasa_mort / 1000 ) + ( poblacion * tasa_migracion / 1000 ); 
	}
	
	cout << "La población estimada tras " << anos << " años es de: " << poblacion << " habitantes." << endl;
	
	poblacion = poblacion_inicial;                                // Se le restaura el valor a la población para proceder al segundo cálculo.
	
	while (poblacion < 2 * poblacion_inicial) {
		poblacion = poblacion + ( poblacion * tasa_nat / 1000 ) - ( poblacion * tasa_mort / 1000 ) + ( poblacion * tasa_migracion / 1000 );
		anos_doble++;
	}
	
	cout << "Años para duplicar la población: " << anos_doble << endl;
	cout << "Población tras " << anos_doble << " años: " << poblacion << " habitantes." << endl;
}

/* El ejemplo del guión de prácticas considera la tasa de mortalidad como
   un incremento de la población, por lo que es necesario especificar un signo
   negativo en la tasa, sin embargo este programa directamente considera que 
   las defunciones suponen un decrecimiento de la población, por lo que a la tasa
   de mortalidad se le debe asignar un número positivo. Solamente es necesario
   especificar el signo de la tasa de migración ya que esta puede ser tanto negativa
   como positiva */
