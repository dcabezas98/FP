/* Programa que transforma carácteres mayúsculas
	en minúsculas aprovechando la asignación forzada
	que realiza C++ cuando se le asigna una letra a
	una variable numérica. */
	
	#include<iostream>
	
	using namespace std;
	
	int main(){
		char mayuscula1;                          // No se pueden asignar carácteres a variables
		int mayuscula;                            // enteras directamente con las funciones de E/S
		char minuscula;                           // por lo que me he auxiliado de una tercera variable
	                                             // mayúscula1. 
	   cout << "Inserte letra mayúscula: ";
	   cin >> mayuscula1;
	   
	   mayuscula = mayuscula1;
	   	   
	   minuscula = mayuscula + 32;
	   
	   cout << "Letra en minuscula: " << minuscula << "\n";
	   
	system("pause");
}
