/* Programa que gestiona la n�mina de los empleados
   a partir del salario por hora y el n�mero de horas
   trabajadas. Adem�s, el programa aplica subidas
   por objetivos de casos resueltos y satisfacci�n
   del cliente. */

#include<iostream>
#include<cmath>

using namespace std;

int main () {
  double salario_hora, salario_final;
  int horas_trabajadas, casos_resueltos;

  cout << "Inserte salario por hora: ";
  cin >> salario_hora;
  cout << "Inserte n�mero de horas trabajadas: ";
  cin >> horas_trabajadas;
  cout << "Inserte n�mero de casos resueltos: ";
  cin >> casos_resueltos;

  salario_final = salario_hora * horas_trabajadas;

  if  (casos_resueltos > 30) {
    salario_final = salario_final * 1.04;
  }

  cout << "El salario final es de: " << salario_final << "\n";
}

/* El programa no solicita el grado de satisfacci�n porque a�n no es
   necesario, se implementar� en posteriores ejercicios. */
