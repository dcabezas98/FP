/* Programa para calcular el valor que toma la función
   gaussiana y el área bajo la curva hasta cada punto
   en un intervalo de abscisas definido por un mínimo,
   un máximo y un incremento. Cuenta con dos menús,
   dando el primero la opción de salir del programa y el segundo
   la de volver al primero. */

#include <iostream>   // Inclusión de los recursos de E/S
#include <cmath>      // Inclusión de las funciones matemáticas necesarios
#include <cctype>
#include <string>

using namespace std;

const double PI = 3.1416;

void DesplegarPrimerMenu () {
  cout << "------------------MENU-PRINCIPAL------------------" << endl;
  cout << " (P) Introducir los parámetros (esperanza y desviación)." << endl;
  cout << " (S) Salir del programa el programa." << endl;
  cout << "--------------------------------------------" << endl;
}

void DesplegarSegundoMenu () {
  cout << "--------------------MENU--------------------" << endl;
  cout << " (R) Introducir rango de valores de abscisas." << endl;
  cout << " (V) Volver al menú anterior (Menú Principal)." << endl;
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
    cout << "Inserte número mayor que 0: ";
    cin >> numero;
  } while (numero <= 0);
  return numero;
}

double LeeMayor (double menor) {
  double mayor;
  do {
    cout << "Inserte número mayor que " <<  menor << ": ";
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

      cout << "Inserte valor del parámetro Mu, esperanza: "; // El programa solicita los datos
      cin >> mu;

      cout << "Inserte valor del parámetro Sigma, desviación:\n";
      sigma = LeePositivo();

      do {

	DesplegarSegundoMenu ();

	do {
	  decision2 = LeerOpcion(mensaje2);
	} while (decision2 != 'V' && decision2 != 'R');

	if (decision2 == 'R') {

	  cout << "Inserte valor mínimo del intervalo: ";
	  cin >> minimo;

	  cout << "Inserte valor máximo del intervalo.\n";
	  maximo = LeeMayor(minimo);

	  cout << "¿Cada cuánto quiere calcular el valor de la función?\n";
	  incremento = LeePositivo ();

	  abscisa = minimo;

	  cout << "Valores de la función para cada abscisa del intervalo: " << endl;

	  while (abscisa <= maximo) { // Este código no es muy eficiente, ya que calcula el denominador varias veces cuando no depende de la abscisa y repite el calculo de la ordenada a la hora de calcular el área. Pero de este modo las funciones tienen un carácter más general.

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
