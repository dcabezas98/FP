/* Programa que solcita 4 variables de diferentes tipos y devuelve
   una secuencia de 4 dígitos en la que 1 significa verdadero y 0 falso,
   siguiendo diversos criterios. */
	
#include<iostream>
	
using namespace std;
	
int main() {
		
  char letra;
  int letra1, edad, adivine, anio;
  bool condicion_letra, condicion_edad, condicion_adivine, condicion_anio;
		
  cout << "Inserte un carácter: ";
  cin >> letra;
  cout << "Inserte edad: ";
  cin >> edad;
  cout << "Inserte un número: ";
  cin >> adivine;
  cout << "Inserte un año: ";
  cin >> anio;
		
  letra1 = letra;                                                             // He añadido la disyunción con letra1 igual a -15
  condicion_letra = (letra1 >= 97 && letra1 <= 122) || (letra1 == -15);       // para evitar la excepción en ñ.
		
  condicion_edad = edad < 18 || edad > 65;
		
  condicion_adivine = adivine >= 1 && adivine <= 100;
		
  condicion_anio = (anio % 400) == 0 || ((anio % 4) == 0 && (anio % 100) != 0);
		                                                                              
  cout << "¿Letra minúscula? " << condicion_letra << "\n";
  cout << "¿Menor de 18 o mayor de 65? " << condicion_edad << "\n";    
  cout << "¿Número entre 1 y 100? " << condicion_adivine << "\n";    
  cout << "¿Año bisiesto? " << condicion_anio << "\n";
		            
  system("pause");
}  
