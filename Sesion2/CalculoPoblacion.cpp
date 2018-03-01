/* Programa que estima la población de un territorio a los
   3 años a partir de las tasas de de natalidad, mortalidad
   y migración */

#include <iostream>     // Inclsión de recursos de E/S

using namespace std;

int main() {
  long long poblacion0;          // Declaración de variables, he tenido que
  int tasa_nat;                  // asignar long long a las variables que se
  int tasa_mort;                 // refieren a la población porque experimentaba
  int tasa_migracion;            // importantes pérdidas de precisión al utilizar
  long long poblacion1;          // int o long.
  long long poblacion2;
  long long poblacion3;

  cout << "Inserte población inicial del territorio: ";   // El programa solicita los datos necesarios,
  cin >> poblacion0;                                      // la población inicial y las tasas de natalidad,
  cout << "Inserte tasa de  natalidad: ";                 // mortalidad y migración.
  cin >> tasa_nat;
  cout << "Inserte tasa de mortalidad: ";
  cin >> tasa_mort;
  cout << "Inserte tasa de migración: ";
  cin >> tasa_migracion;

  poblacion1 = poblacion0 + ( poblacion0 * tasa_nat / 1000 ) - ( poblacion0 * tasa_mort / 1000 ) + ( poblacion0 * tasa_migracion / 1000 );      // Operaciones necesarias, se realizan
  poblacion2 = poblacion1 + ( poblacion1 * tasa_nat / 1000 ) - ( poblacion1 * tasa_mort / 1000 ) + ( poblacion1 * tasa_migracion / 1000 );      // por años ya que cada tasa se debe aplicar
  poblacion3 = poblacion2 + ( poblacion2 * tasa_nat / 1000 ) - ( poblacion2 * tasa_mort / 1000 ) + ( poblacion2 * tasa_migracion / 1000 );      // al dato de ese año.

  cout << "La población estimada tras 3 años es de: " << poblacion3 << " habitantes. \n";   // Se expresa la solución deseada.
}

/* Este programa directamente considera que las defunciones suponen un
   decrecimiento de la población, por lo que a la tasa de mortalidad
   se le debe asignar un número positivo. Solamente es necesario
   especificar el signo de la tasa de migración ya que esta puede ser
   tanto negativa como positiva */
