/* Programa que calcula la longitud de la circunferencia
   y el área del círculo a partir del radio indicado.
*/

#include <iostream>     // Inclusión de recursos de E/S

using namespace std;

int main() {
  double radio;              // Declaración de variables y constante PI
  double longitud_circunferencia;
  double area_circulo;
  const double PI = 3.1415927;
   
  cout << "Inserte el valor del  radio de la circunferencia: ";   // El programa solicita los datos
  cin >> radio;
   
  longitud_circunferencia = 2 * PI * radio;                       // Operaciones necesarias
  area_circulo = PI * radio * radio;
   
  cout << "La longitud de la circunferencia (en las mismas unidades que el radio dado) es: "  << longitud_circunferencia << "\n";    // Expresión del resultado
  cout << "El área del círculo (en esas mismas unidades cuadradas) es: " << area_circulo << "\n";
   
  system("pause");
}

/* Aclaración: Ha sido incluido el valor de PI como un valor constante. */
