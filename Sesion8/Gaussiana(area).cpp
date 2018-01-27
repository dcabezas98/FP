/* Programa para calcular el valor que toma la funci�n
   gaussiana y el �rea bajo la curva hasta cada punto
   en un intervalo de abscisas definido por un m�nimo, 
   un m�ximo y un incremento. Cuenta con dos men�s,
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
	
double Potencia ( double base, int exponente) {
		
  double potencia = 1;
		
  for (int contador = 1; contador <= exponente; contador++) {
    potencia *= base;
  }
  return potencia;
}
	
double CalcularGaussiana (double mu, double sigma, double abscisa) {
  double denominador, base, exponente, ordenada;
		
  denominador = sigma * sqrt(2 * PI);
  base = (abscisa - mu) / sigma;
  exponente = -0.5 * Potencia(base, 2);	
  ordenada = exp(exponente) / denominador;
  return ordenada;
}
	
double CDF (double mu, double sigma, double abscisa) {
  double ordenada, area, t;
  const double b0 = 0.2316419, b1 = 0.319381530, b2 = -0.356563782,
    b3 = 1.781477937, b4 = -1.821255978, b5 = 1.330274429;
		
  t = 1 / (1 + b0 * abscisa);
  ordenada = CalcularGaussiana (mu, sigma, abscisa);
  area = 1 - ordenada * (b1 * t + b2 * Potencia(t, 2) + b3 * Potencia(t, 3) + b4 * Potencia(t, 4) + b5 * Potencia(t, 5)); 
		
  return area;
}
				
int main() {
		
  double mu, sigma, maximo, minimo, incremento,
    abscisa, ordenada, area;
  string mensaje1 = "Pulse p/P o s/S:\n";
  string mensaje2 = "Pulse r/R o v/V:\n";
  char decision1, decision2;
			
  do {
    DesplegarPrimerMenu ();
				 					
    do {
      decision1 = LeerOpcion(mensaje1); 
    } while (decision1 != 'P' && decision1 != 'S'); 
								
    if (decision1 == 'P') {
				
      cout << "Inserte valor del par�metro Mu, esperanza: "; // El programa solicita los datos
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
							
	  while (abscisa <= maximo) { // Este c�digo no es muy eficiente, ya que calcula el denominador varias veces cuando no depende de la abscisa y repite el calculo de la ordenada a la hora de calcular el �rea. Pero de este modo las funciones tienen un car�cter m�s general.
	    
	    ordenada = CalcularGaussiana (mu, sigma, abscisa);  
	    area = CDF (mu, sigma, abscisa); 
	    cout << "f(" << abscisa << ")= " << ordenada << "\t\t\tCDF(" << abscisa << ")= " << area << endl;		  
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
