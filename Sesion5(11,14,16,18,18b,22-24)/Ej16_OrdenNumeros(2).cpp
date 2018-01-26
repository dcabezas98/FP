/* Programa que dice si tres enteros est�n ordenados
	o no, ya sea en orden ascendente o descendente,
	usando un tipo enumerado */
	
	#include<iostream>
	#include<cmath>
	
	using namespace std;
	
	enum Orden {creciente, decreciente, desorden};
	
	int main () {
	
		int numero1, numero2, numero3;
		
		Orden orden = desorden;                            // Si no se define el valor de la variable, se le asigna
	   																   // el 0, que corresponde al orden creciente.
		cout << "Inserte primer n�mero: ";
		cin >> numero1;
		cout << "Inserte segundo n�mero: ";
		cin >> numero2;
		cout << "Inserte tercer n�mero: "; 
		cin >> numero3;
		
		if (numero1 < numero2 && numero2 < numero3)
			orden = creciente;
		
		if (numero1 > numero2 && numero2 > numero3)
			orden = decreciente;
					
		switch (orden){
			
			case creciente:
				cout << "Los n�meros est�n ordenados en orden creciente." << endl;
	   		break;
	   		
	   	case decreciente:
				cout << "Los n�meros est�n ordenados en orden decreciente." << endl;
				break;
			
			default: 
				cout << "Los n�meros no est�n ordenados." << endl;
			}
   }	
