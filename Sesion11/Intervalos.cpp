/*
  Clase intervalo y distintos operadores con intervalos.
 */

#include<iostream>

using namespace std;

class Intervalo {
	
private:
		
  /* Datos miembro */
  double a, b;
      	
  bool a_cerrado = false;
  bool b_cerrado = false;
  bool vacio = false;
				
public:
		
  /* Constructores */
  Intervalo() {
			
    vacio = true; // En este tipo de intervalo no están definidas las cotas, por lo que debo filtrar bien los métodos 
  }
		
  Intervalo(double origen, double extremo){ // Las cotas se consideran abiertas por defecto
			
    setCotas(origen, extremo);
  }
		
  Intervalo(bool origen_cerrado, double origen, double extremo, bool extremo_cerrado) { // Intenta imitar la nomenclatura tradicional
		                                                                                           
    setCotas(origen, extremo);
    setTipoCotas(origen_cerrado, extremo_cerrado);
  }
		
  /* Métodos set y get */
  void setCotas(double origen, double extremo) {
			
    a = origen;
    b = extremo;
  }
		
  void setTipoCotas(bool origen_cerrado, bool extremo_cerrado) {
			
    a_cerrado = origen_cerrado;
    b_cerrado = extremo_cerrado;
  }
		
  double getA() {
			
    return a;
  }
		
  double getB() {
			
    return b;
  }
		
  double getAcerrado() {
			
    return a_cerrado;
  }
		
  double getBcerrado() {
			
    return b_cerrado;
  }
		
  /* Métodos obligatorios */
  bool esVacio() {
			
    return vacio;
  }
		
  bool contiene(double valor) {
    bool contiene;
						
    if (esVacio())
      contiene = false; // Un intervalo vacío no puede contener un punto
			
    if ((valor == a && a_cerrado) || (valor == b && b_cerrado)) // Estudia si el valor coincide con alguna de las cotas
      contiene = true; 
			
    else 
      contiene = (valor > a && valor < b);
				
    return contiene;
  }
		
  /* Métodos que considero útiles */
		
  /* Dice si un intervalo está dentro de otro*/
  bool contiene(Intervalo otro_intervalo) { // Hago uso de la sobrecarga, ya que es un tipo distinto de parámetro
    bool contiene;
			
    if (otro_intervalo.esVacio())
      contiene = true; // El vacío se considera subconjunto de cualquier conjunto
	  		   
    else if (esVacio())
      contiene = false; // Un intervalo vacío no puede contener a otro intervalo no vacío
				  		   
    else if (a > otro_intervalo.getA()) 
      contiene = false;
			
    else if (a == otro_intervalo.getA() && !a_cerrado && otro_intervalo.getAcerrado()) // En caso de que coincidan las cotas, el único caso en el que no contiene es en el que el primero es abierto y el segundo cerrado.
      contiene = false;
    
    else if(b < otro_intervalo.getB())
      contiene = false;
   			
    else if (b == otro_intervalo.getB() && !b_cerrado && otro_intervalo.getBcerrado())
      contiene = false;
			
    else // En el momento que una premisa se verifique, se sale de la cadena y se emite la salida
      contiene = true;
			
    return contiene;
  }
		
  /* Da la longitud de intervalo*/
  double longitud() {
			
    if (!esVacio())
      return b - a;
  }
};
		
int main() {
	
  double origen1, extremo1, numero;
  bool origen1_cerrado = false, extremo1_cerrado = false;
  char opcion1, opcion2;
			
  cout << "Origen del intervalo: ";
  cin >> origen1;
	
  do {
    cout << "¿Abierto o cerrado? (A/C) ";
    cin >> opcion1;
    opcion1 = toupper(opcion1);
  } while (opcion1 != 'A' && opcion1 != 'C');
	
  if (opcion1 == 'C')
    origen1_cerrado = true;
	
  do {
    cout << "Extremo del intervalo: ";
    cin >> extremo1;
  } while (extremo1 <= origen1);
		
  do {
    cout << "¿Abierto o cerrado? (A/C) ";
    cin >> opcion2;
    opcion2 = toupper(opcion2);
  } while (opcion2 != 'A' && opcion2 != 'C');
   
  if (opcion2 == 'C')
    extremo1_cerrado = true;
  	
  Intervalo intervalo1(origen1_cerrado, origen1, extremo1, extremo1_cerrado);
  	   
  cout << "Longitud: " << intervalo1.longitud() << endl;
  
  cout << "Inserte un valor: ";
  cin >> numero;
  
  if (intervalo1.contiene(numero))
    cout << "El intervalo contiene al número." << endl;
   	   
  else 
    cout << "El intervalo no contiene al número." << endl;
   
  Intervalo intervalo2;
   
  if (intervalo2.esVacio())
    cout << "Se ha creado otro intervalo vacío." << endl;  
}
