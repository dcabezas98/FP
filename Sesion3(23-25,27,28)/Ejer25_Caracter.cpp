/* Programa que transforma car�cteres may�sculas
	en min�sculas aprovechando la asignaci�n forzada
	que realiza C++ cuando se le asigna una letra a
	una variable num�rica. */
	
	#include<iostream>
	
	using namespace std;
	
	int main(){
		char mayuscula1;                          // No se pueden asignar car�cteres a variables
		int mayuscula;                            // enteras directamente con las funciones de E/S
		char minuscula;                           // por lo que me he auxiliado de una tercera variable
	                                             // may�scula1. 
	   cout << "Inserte letra may�scula: ";
	   cin >> mayuscula1;
	   
	   mayuscula = mayuscula1;
	   	   
	   minuscula = mayuscula + 32;
	   
	   cout << "Letra en minuscula: " << minuscula << "\n";
	   
	system("pause");
}
