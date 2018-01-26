/* Programa que gestiona la nómina de los empleados
	a partir del salario por hora y el número de horas
	trabajadas. Además, el programa aplica subidas
	por objetivos de casos resueltos y satisfacción
	del cliente. */
	
	#include<iostream>
	#include<cmath>
	
	using namespace std;
	
	int main () {
		
		double salario_hora, salario_final, grado_satisfaccion;
		int horas_trabajadas, casos_resueltos, aumento;
		const int OBJETIVO_CASOS1 = 30;
		const int OBJETIVO_CASOS2 = 20;
		const float OBJETIVO_SATISFACCION = 4.0;
		const int AUMENTO_CASOS1 = 4;
		const int AUMENTO_CASOS2 = 3;
		const int AUMENTO_SATISFACCION = 2;
		
		aumento = 0;
		
		cout << "Inserte salario por hora: ";                              // Se solicitan los datos.
		cin >> salario_hora;
		cout << "Inserte número de horas trabajadas: ";
		cin >> horas_trabajadas;
	   cout << "Inserte número de casos resueltos: ";
	   cin >> casos_resueltos;
	   cout << "Inserte grado de satisfacción de los clientes (entre 0 y 5); ";
	   cin >> grado_satisfaccion;
	   
	   salario_final = salario_hora * horas_trabajadas;
	   
	   if (casos_resueltos >= OBJETIVO_CASOS2 && casos_resueltos <= OBJETIVO_CASOS1)     // Se comprueba cuales de los objetivos se
	   	aumento = aumento + AUMENTO_CASOS2;                                            // han cumplido y se calcula el porcentaje
	   	                                                                               // a aumentar.
	   else if  (casos_resueltos > OBJETIVO_CASOS1) {
	   	aumento = aumento + AUMENTO_CASOS1;
	   }
	   
	   if (grado_satisfaccion >= OBJETIVO_SATISFACCION) {
	   	aumento = aumento + AUMENTO_SATISFACCION;
	   }
	   
	   salario_final = salario_final + salario_final * aumento / 100;                    // Se realiza el aumento en el porcentaje 
	                                                                                     // calculado anteriormente.
	   cout << "El salario final es de: " << salario_final << "\n";
	}

