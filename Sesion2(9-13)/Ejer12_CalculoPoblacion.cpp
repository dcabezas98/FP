/* Programa que estima la poblaci�n de un territorio a los
   3 a�os a partir de las tasas de de natalidad, mortalidad
   y migraci�n */
   
#include <iostream>     // Inclsi�n de recursos de E/S

using namespace std;

int main() {
	long long poblacion0;          // Declaraci�n de variables, he tenido que
   int tasa_nat;                  // asignar long long a las variables que se
	int tasa_mort;                 // refieren a la poblaci�n porque experimentaba
	int tasa_migracion;            // importantes p�rdidas de precisi�n al utilizar
	long long poblacion1;          // int o long.
	long long poblacion2;
 	long long poblacion3;            
	 
	cout << "Inserte poblaci�n inicial del territorio: ";   // El programa solicita los datos necesarios,
	cin >> poblacion0;                                      // la poblaci�n inicial y las tasas de natalidad,
	cout << "Inserte tasa de  natalidad: ";                 // mortalidad y migraci�n.
	cin >> tasa_nat;
	cout << "Inserte tasa de mortalidad: ";
	cin >> tasa_mort;
	cout << "Inserte tasa de migraci�n: ";
	cin >> tasa_migracion;
	
	poblacion1 = poblacion0 + ( poblacion0 * tasa_nat / 1000 ) - ( poblacion0 * tasa_mort / 1000 ) + ( poblacion0 * tasa_migracion / 1000 );      // Operaciones necesarias, se realizan 
	poblacion2 = poblacion1 + ( poblacion1 * tasa_nat / 1000 ) - ( poblacion1 * tasa_mort / 1000 ) + ( poblacion1 * tasa_migracion / 1000 );      // por a�os ya que cada tasa se debe aplicar
	poblacion3 = poblacion2 + ( poblacion2 * tasa_nat / 1000 ) - ( poblacion2 * tasa_mort / 1000 ) + ( poblacion2 * tasa_migracion / 1000 );      // al dato de ese a�o.
	
	cout << "La poblaci�n estimada tras 3 a�os es de: " << poblacion3 << " habitantes. \n";   // Se expresa la soluci�n deseada.
	
	system("pause");
}
	
/* El ejemplo del gui�n de pr�cticas considera la tasa de mortalidad como
   un incremento de la poblaci�n, por lo que es necesario especificar un signo
   negativo en la tasa, sin embargo este programa directamente considera que 
   las defunciones suponen un decrecimiento de la poblaci�n, por lo que a la tasa
   de mortalidad se le debe asignar un n�mero positivo. Solamente es necesario
   especificar el signo de la tasa de migraci�n ya que esta puede ser tanto negativa
   como positiva */
