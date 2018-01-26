/* Programa que calcula dos salarios, siendo
	estos el resultado de incrementar el salario 
	base introducio en 2  y 3 % respectivamente. 
	Ejercicio 4 realizado usando la opción b, es decir, 
	introduciendo una nueva variable salario_final
	que se corresponda con el incremento del salario base.
*/

#include <iostream>           // Inclusión de recursos de E/S

using namespace std;

int main() {
	
	double salario_base;       // Declaración de variables
 	double salario_final_2;      
	double salario_final_3;
	
	cout << "Inserte salario base en euros: ";     // El programa solicita el valor del salario base
	cin >> salario_base;                             // Se registra en la variable homónima
	
	salario_final_2 = salario_base * 1.02;             // Se calculan las variables salario_final_2 y
	salario_final_3 = salario_final_2 * 1.03;          // salario_final_3
	
	cout << "El salario resultante tras el incremento del 2% es de: " << salario_final_2 << " euros.\n";            // Se imprimen en pantalla los resultados deseado 
	cout << "El salario resultante tras el nuevo incremento del 3% sobre el anterior es de: " <<salario_final_3 << " euros.\n";
	
	system ("pause");
}
	
	
	
	
