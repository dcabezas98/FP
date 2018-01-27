/* Programa para calcular el valor que toma la funci�n
   gaussiana en un intervalo de abscisas definido por un
   m�nimo, un m�ximo y un incremento. Cuenta con dos men�s,
   dando el primero la opci�n de salir del programa y el segundo
   la de volver al primero. */
	
#include <iostream>   // Inclusi�n de los recursos de E/S
#include <cmath>      // Inclusi�n de las funciones matem�ticas necesarios
#include <cctype>
#include <string>
	
using namespace std;
	
const double PI = 3.1416;
	
void DesplegarPrimerMenu () {
  cout << "------------------MENU-PRINCIPAL------------------" << endl;
  cout << " (P) Introducir los par�metros (esperanza y desviaci�n)." << endl; 
  cout << " (S) Salir del programa el programa." << endl;
  cout << "--------------------------------------------" << endl;
}
	
void DesplegarSegundoMenu () {
  cout << "--------------------MENU--------------------" << endl;
  cout << " (R) Introducir rango de valores de abscisas." << endl;
  cout << " (V) Volver al men� anterior (Men� Principal)." << endl;
  cout << "--------------------------------------------" << endl;
}
	
char LeerOpcion (string mensaje) {
  char opcion;
  cout << mensaje;
  cin >> opcion;
  opcion = toupper(opcion);
  return opcion;
}
	
double LeePositivo () {
  double numero;
  do {
    cout << "Inserte n�mero mayor que 0: ";
    cin >> numero;
  } while (numero <= 0);
  return numero;
}
	
double LeeMayor (double menor) {
  double mayor;
  do {
    cout << "Inserte n�mero mayor que " <<  menor << ": ";
    cin >> mayor;
  } while (mayor <= menor);
  return mayor;
}
	
double CalcularGaussiana (double mu, double sigma, double abscisa) {
  double denominador, exponente, ordenada;
  denominador = sigma * sqrt(2 * PI);
  exponente = -0.5 * pow((abscisa - mu) / sigma, 2);	
  ordenada = exp(exponente) / denominador;
  return ordenada;
}
			
int main() {
		
  double mu, sigma, maximo, minimo, incremento,
    abscisa, ordenada;
  string mensaje1 = "Pulse p/P o s/S:\n";
  string mensaje2 = "Pulse r/R o v/V:\n";
  char decision1, decision2;
			
  do {
    DesplegarPrimerMenu ();
				 					
    do {
      decision1 = LeerOpcion(mensaje1); 
    } while (decision1 != 'P' && decision1 != 'S'); 
								
    if (decision1 == 'P') {
				
      cout << "Inserte valor del par�metro Mu, esperanza: ";                            // El programa solicita los datos
      cin >> mu;                                    
			
      cout << "Inserte valor del par�metro Sigma, desviaci�n:\n";
      sigma = LeePositivo();
				
      do {
					
	DesplegarSegundoMenu ();
					
	do { 
	  decision2 = LeerOpcion(mensaje2);
	} while (decision2 != 'V' && decision2 != 'R');
							
	if (decision2 == 'R') {
							
	  cout << "Inserte valor m�nimo del intervalo: ";
	  cin >> minimo;
						
	  cout << "Inserte valor m�ximo del intervalo.\n";
	  maximo = LeeMayor(minimo);
						
	  cout << "�Cada cu�nto quiere calcular el valor de la funci�n?\n";
	  incremento = LeePositivo ();				
	  abscisa = minimo;
	
	  cout << "Valores de la funci�n para cada abscisa del intervalo: " << endl;
							
	  while (abscisa <= maximo) {
								
	    ordenada = CalcularGaussiana (mu, sigma, abscisa);
	    cout << "X= " << abscisa << "\t\tY= " << ordenada << endl;		  
	    abscisa = abscisa + incremento;
	  }
	}						
      } while (decision2 == 'R');
    } 						
    else if (decision1 == 'S') {
      cout << "Fin del programa";
    }				
  } while (decision1 != 'S');
}
