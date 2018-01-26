/* Programa para calcular el valor que toma la funci�n
   gaussiana en una determinada abscisa a partir 
	de los par�metros mu y sigma */
	
#include <iostream>   // Inclusi�n de los recursos de E/S
#include <cmath>      // Inclusi�n de las funciones matem�ticas necesarios

using namespace std;

int main() {
	double mu;                  // Declaraci�n de las variables
	double sigma;               // y constante necesarias 
	const double PI = 3.1416;
	double X;
	double gaussY;
	double denominador;
	double exponente;
	
	cout << "Inserte valor del par�metro mu: ";                                               // El programa solicita los datos
	cin >> mu;                                    
	cout << "Inserte valor del par�metro sigma: ";
	cin >> sigma;
	cout << "Inserte punto de abscisa para el que quiera calcular el valor de la funci�n: ";  
	cin >> X;
	
   denominador = sigma * sqrt(2 * PI);                                                       // Operaciones necesarias
   exponente = -0.5 * pow( (X - mu) / sigma, 2 );
   gaussY = exp(exponente) / denominador;
   
   cout << "La funci�n gaussiana seleccionada toma el valor de: "<< gaussY << " en dicho punto\n";   // Se expresa el resultado
   
   system ("pause");
}

/* Aclaraci�n ejercicio 11: el valor de PI ya hab�a sido definido como constante en el ejercicio 10
   y no es oportuno incluir ninguna otra */
   
	
	
