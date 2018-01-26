/* Programa que lee un numero natural y muestra sus descomposiciones
	con n�meros cosecutivos. */
	
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
		
		tope = numero / 2;                                                // Si el primer n�mero es mayor o igual a la mitad del n�mero, la secuencia 
																                        // superar� al n�mero, por lo que esto ahorra iteraciones innecesarias.	
																									
		for (primero_secuencia = 1; primero_secuencia <= tope; primero_secuencia++) {          // Va probando uno por uno los n�meros del 1 al tope, con el primero
				                               														         // de la secuencia igual a la mitad del numero, no deber�a de salir,
				suma = 0;                                                                        // pero puede exitir truncamiento y que no compruebe la �ltima posibilidad
																											   		   //  si pongo la condici�n como menor estricto en lugar de menor o igual.
			for (sumando = primero_secuencia; suma < numero; sumando++) {
																						               // Se suma el n�mero con sus consecutivos mientras que la suma sea menor al
				suma += sumando;                                                     // n�mero inicial.
			}
				if (suma == numero) {                                                // Si la suma coincide con el n�mero, repite el bucle con el mismo valor de primero_secuencia,
					suma = 0;                                                         // esta vez mostrando cada sumando en pantalla.
					secuenciable = true;
					
					
					for (numero_mostrar = primero_secuencia; numero_mostrar < sumando; numero_mostrar++) {    // Imprime los desde el primero al �ltimo de los sumandos con los que
						         																									   // ha obtenido la secuencia, es decir, cada n�mero que entr� en el bucle.
						cout << numero_mostrar << " ";
					}
					cout << endl;
				}	
		}
		
		if (!secuenciable)    
			cout << "El n�mero no es secuenciable" << endl;
	}
		
		
	
