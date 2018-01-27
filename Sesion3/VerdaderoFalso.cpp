/* Programa que solcita 4 variables de diferentes tipos y devuelve
   una secuencia de 4 d�gitos en la que 1 significa verdadero y 0 falso,
   siguiendo diversos criterios. */
	
#include<iostream>
	
using namespace std;
	
int main() {
		
  char letra;
  int letra1, edad, adivine, anio;
  bool condicion_letra, condicion_edad, condicion_adivine, condicion_anio;
		
  cout << "Inserte un car�cter: ";
  cin >> letra;
  cout << "Inserte edad: ";
  cin >> edad;
  cout << "Inserte un n�mero: ";
  cin >> adivine;
  cout << "Inserte un a�o: ";
  cin >> anio;
		
  letra1 = letra;                                                             // He a�adido la disyunci�n con letra1 igual a -15
  condicion_letra = (letra1 >= 97 && letra1 <= 122) || (letra1 == -15);       // para evitar la excepci�n en �.
		
  condicion_edad = edad < 18 || edad > 65;
		
  condicion_adivine = adivine >= 1 && adivine <= 100;
		
  condicion_anio = (anio % 400) == 0 || ((anio % 4) == 0 && (anio % 100) != 0);
		                                                                              
  cout << "�Letra min�scula? " << condicion_letra << "\n";
  cout << "�Menor de 18 o mayor de 65? " << condicion_edad << "\n";    
  cout << "�N�mero entre 1 y 100? " << condicion_adivine << "\n";    
  cout << "�A�o bisiesto? " << condicion_anio << "\n";
		            
  system("pause");
}  
