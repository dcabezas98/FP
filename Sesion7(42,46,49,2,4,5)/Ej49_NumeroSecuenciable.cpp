/* Programa que lee un numero natural y muestra sus descomposiciones
	con números cosecutivos. */
	
	#include<cmath>
	#include<iostream>
	
	using namespace std;
	
	int main () {
		
		int numero, tope, primero_secuencia, 
		sumando, numero_mostrar, suma;
		bool secuenciable = false;
	
		do {
		cout << "Inserte numero a secuenciar (mayor o igual a 1): ";
		cin >> numero;
		} while ( numero < 1);
		
		tope = numero / 2;                                                // Si el primer número es mayor o igual a la mitad del número, la secuencia 
																                        // superará al número, por lo que esto ahorra iteraciones innecesarias.	
																									
		for (primero_secuencia = 1; primero_secuencia <= tope; primero_secuencia++) {          // Va probando uno por uno los números del 1 al tope, con el primero
				                               														         // de la secuencia igual a la mitad del numero, no debería de salir,
				suma = 0;                                                                        // pero puede exitir truncamiento y que no compruebe la última posibilidad
																											   		   //  si pongo la condición como menor estricto en lugar de menor o igual.
			for (sumando = primero_secuencia; suma < numero; sumando++) {
																						               // Se suma el número con sus consecutivos mientras que la suma sea menor al
				suma += sumando;                                                     // número inicial.
			}
				if (suma == numero) {                                                // Si la suma coincide con el número, repite el bucle con el mismo valor de primero_secuencia,
					suma = 0;                                                         // esta vez mostrando cada sumando en pantalla.
					secuenciable = true;
					
					
					for (numero_mostrar = primero_secuencia; numero_mostrar < sumando; numero_mostrar++) {    // Imprime los desde el primero al último de los sumandos con los que
						         																									   // ha obtenido la secuencia, es decir, cada número que entró en el bucle.
						cout << numero_mostrar << " ";
					}
					cout << endl;
				}	
		}
		
		if (!secuenciable)    
			cout << "El número no es secuenciable" << endl;
	}
		
		
	
