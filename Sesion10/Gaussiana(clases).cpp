/* Programa que calcula el valor que toma la función gaussiana en
   los puntos de un intervalo y el área bajo la curva desde -inf. a 
   cada punto. He implementado la clase Gaussiana para resolverlo. */
	
#include<iostream>
#include<cmath>
#include<cctype>

using namespace std;

class Gaussiana {
	
private:
		
  double esperanza, desviacion;
  static const double PI = 3.1416;
	
public:
					
  void setEsperanza(double valor) {
			
    esperanza = valor;
  }
				
  void setDesviacion(double valor) {
			
    desviacion = valor;
  }
		
  char leeDesviacion() {
			
    double valor;
			
    do {
      cout << "Inserte número mayor que 0: ";
      cin >> valor;
    } while (valor <= 0);
			
    return valor;
  }
			
		
  double ordenada(double abscisa) {
			
    double denominador, base, exponente, ordenada;
		
    denominador = desviacion * sqrt(2 * PI);
    base = (abscisa - esperanza) / desviacion;
    exponente = -0.5 * pow(base, 2);	
    ordenada = exp(exponente) / denominador;
			
    return ordenada;
  }
	
  double CDF(double abscisa) {
			
    double y, area, t, x_tip;
    const double b0 = 0.2316419, b1 = 0.319381530, b2 = -0.356563782,
      b3 = 1.781477937, b4 = -1.821255978, b5 = 1.330274429;
    x_tip = abs((abscisa - esperanza) / desviacion);
					
    t = 1 / (1 + b0 * x_tip);
    y = exp(-0.5 * pow(x_tip, 2)) / sqrt(2 * PI);   
    area = 1 - y * (b1 * t + b2 * pow(t, 2) + b3 * pow(t, 3) + b4 * pow(t, 4) + b5 * pow(t, 5));
			
    if (abscisa < esperanza)
      area = 1 - area;
		
    return area;
  }
};

int main() {
   
  Gaussiana gaussiana;
  double mu, sigma, maximo, minimo, incremento,
    abscisa, ordenada, area;
  string mensaje1 = "Pulse p/P o s/S:\n";
  string mensaje2 = "Pulse r/R o v/V:\n";
  char decision1, decision2;
			
  do {
    cout << "------------------MENU-PRINCIPAL------------------" << endl;
    cout << " (P) Introducir los parámetros (esperanza y desviación)." << endl; 
    cout << " (S) Salir del programa el programa." << endl;
    cout << "--------------------------------------------" << endl;
			 					
    do {
      cout << mensaje1;
      cin >> decision1;
      decision1 = toupper(decision1); 
    } while (decision1 != 'P' && decision1 != 'S'); 
								
    if (decision1 == 'P') {
			
      cout << "Inserte valor del parámetro Mu, esperanza: "; // El programa solicita los datos
      cin >> mu;
			
      gaussiana.setEsperanza(mu);                                    
			
      cout << "Inserte valor del parámetro Sigma, desviación:\n";
      sigma = gaussiana.leeDesviacion();
			
      gaussiana.setDesviacion(sigma);			
				
      do {
				
	cout << "--------------------MENU--------------------" << endl;
	cout << " (R) Introducir rango de valores de abscisas." << endl;
	cout << " (V) Volver al menú anterior (Menú Principal)." << endl;
	cout << "--------------------------------------------" << endl;
								
	do {
	  cout << mensaje2;
	  cin >> decision2;
	  decision2 = toupper(decision2);
	} while (decision2 != 'V' && decision2 != 'R');
						
	if (decision2 == 'R') {
						
	  cout << "Inserte valor mínimo del intervalo: ";
	  cin >> minimo;
					
	  do {	
	    cout << "Inserte valor máximo del intervalo.\n";
	    cin >> maximo;
	  } while (maximo < minimo);
					
	  do {
	    cout << "¿Cada cuánto quiere calcular el valor de la función? ";
	    cin >> incremento;
	  } while (incremento <= 0);
												
	  abscisa = minimo;

	  cout << "Valores de la función para cada abscisa del intervalo: " << endl;
						
	  while (abscisa <= maximo) {                                       								                                                         
	    ordenada = gaussiana.ordenada(abscisa);             
	    area = gaussiana.CDF(abscisa);                                  
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
