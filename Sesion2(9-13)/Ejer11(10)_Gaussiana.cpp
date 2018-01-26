/* Programa para calcular el valor que toma la función
   gaussiana en una determinada abscisa a partir 
	de los parámetros mu y sigma */
	
#include <iostream>   // Inclusión de los recursos de E/S
#include <cmath>      // Inclusión de las funciones matemáticas necesarios

using namespace std;

int main() {
	double mu;                  // Declaración de las variables
	double sigma;               // y constante necesarias 
	const double PI = 3.1416;
	double X;
	double gaussY;
	double denominador;
	double exponente;
	
	cout << "Inserte valor del parámetro mu: ";                                               // El programa solicita los datos
	cin >> mu;                                    
	cout << "Inserte valor del parámetro sigma: ";
	cin >> sigma;
	cout << "Inserte punto de abscisa para el que quiera calcular el valor de la función: ";  
	cin >> X;
	
   denominador = sigma * sqrt(2 * PI);                                                       // Operaciones necesarias
   exponente = -0.5 * pow( (X - mu) / sigma, 2 );
   gaussY = exp(exponente) / denominador;
   
   cout << "La función gaussiana seleccionada toma el valor de: "<< gaussY << " en dicho punto\n";   // Se expresa el resultado
   
   system ("pause");
}

/* Aclaración ejercicio 11: el valor de PI ya había sido definido como constante en el ejercicio 10
   y no es oportuno incluir ninguna otra */
   
	
	
