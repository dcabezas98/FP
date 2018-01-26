/* Programa que gestiona la nómina de los empleados
   a partir del salario por hora y el número de horas
   trabajadas. Además, el programa aplica subidas
   por objetivos de casos resueltos y satisfacción
   del cliente. */
	
#include<iostream>
#include<cmath>
	
using namespace std;
	
int main () {
  double salario_hora, salario_final;
  int horas_trabajadas, casos_resueltos;
		
  cout << "Inserte salario por hora: ";
  cin >> salario_hora;
  cout << "Inserte número de horas trabajadas: ";
  cin >> horas_trabajadas;
  cout << "Inserte número de casos resueltos: ";
  cin >> casos_resueltos;
	   
  salario_final = salario_hora * horas_trabajadas;
	   
  if  (casos_resueltos > 30) {
    salario_final = salario_final * 1.04;
  }
	   	
  cout << "El salario final es de: " << salario_final << "\n";
	   
  system("pause");
}
	
/* El programa no solicita el grado de satisfacción porque aún no es
   necesario, se implementará en posteriores ejercicios. */
