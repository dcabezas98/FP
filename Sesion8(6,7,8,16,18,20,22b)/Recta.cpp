/* Programa que lee los coeficientes A, B, C de dos rectas
   del espacio y devuelve: los puntos por los que pasa cada 
   recta en un intervalo de abscisas y otro de ordenadas, sus
   ecuaciones explicitas y su posición relativa. */
	
#include<iostream>

using namespace std;

double CalculoOrdenadaRecta (double A, double B, double C, double abscisa) {
  double ordenada;
	
  ordenada = ( -A * abscisa - C) / B;
	
  return ordenada;
}

double CalculoAbscisaRecta (double A, double B, double C, double ordenada) {
  double abscisa;
	
  abscisa = ( -B * ordenada - C) / A;
	
  return abscisa;
}

double CalculoPendienteRecta (double A, double B) {
  double pendiente;
	
  pendiente = -A / B;
	
  return pendiente;
}

double CalculoOrdenadaOrigenRecta (double B, double C) {
  double ordenada_origen;
	
  ordenada_origen = -C / B;
	
  return ordenada_origen;
}

void EscribirExplicita (double A, double B, double C) {
  if (B != 0) {
    double ordenada_origen = CalculoOrdenadaOrigenRecta(B, C);
    double pendiente = CalculoPendienteRecta (A, B);
    cout << "Y= " << pendiente << "X + " << ordenada_origen << endl;
  }
  else {
    cout << "Forma explícita no disponible, la pendiente vale infinito" << endl;
  }
}

string PosicionRelativa (double A1, double B1, double C1, double A2, double B2, double C2) {
  string posicion_relativa;
	
  if (A1 / A2 == B1 / B2) {
    if (A1 / A2 == C1 / C2)
      posicion_relativa = "Rectas coincidentes";
    else { 
      posicion_relativa = "Rectas paralelas";
    }
  }
  else {
    posicion_relativa = "Rectas secantes";
  }
  return posicion_relativa;
}
 	
int main () { 

  const double ORIGEN_INTERVALO_X = -10;
  const double EXTREMO_INTERVALO_X = 10;
  const double INCREMENTO_X = 1;
  const double ORIGEN_INTERVALO_Y = -5;
  const double EXTREMO_INTERVALO_Y = 5;
  const double INCREMENTO_Y = 0.5;
   
  double A1, B1, C1, A2, B2, C2, abscisa, ordenada;
  string posicion_relativa;
	
  cout << "Ax + By + C = 0" << endl;
	 
  cout << "Inserte coeficiente A de la primera recta: ";
  cin >> A1;
  cout << "Inserte coeficiente B de la primera recta: ";
  cin >> B1;
  cout << "Inserte coeficiente C de la primera recta: ";
  cin >> C1;
  cout << "Inserte coeficiente A de la segunda recta: ";
  cin >> A2;
  cout << "Inserte coeficiente B de la segunda recta: ";
  cin >> B2;
  cout << "Inserte coeficiente C de la segunda recta: ";
  cin >> C2;
	
  cout << "Primera recta:" << endl;
	
  if (B1 != 0) {
    
    /* 
       Podría declararlo como función, pero he preferido hacerlo de
       este modo porque la función requeriría de 7 parámetros.
    */
    for (abscisa = ORIGEN_INTERVALO_X; abscisa <= EXTREMO_INTERVALO_X; abscisa += INCREMENTO_X) {
      ordenada = CalculoOrdenadaRecta (A1, B1, C1, abscisa);
      
      cout << "X= " << abscisa << "\t\tY= " << ordenada << endl;       		       
    }
		
    cout << endl;
		
    if (A2 !=0) {
	
      for (ordenada = ORIGEN_INTERVALO_Y; ordenada <= EXTREMO_INTERVALO_Y; ordenada += INCREMENTO_Y) {
				
	abscisa = CalculoAbscisaRecta (A1, B1, C1, ordenada);
	cout << "Y= " << ordenada << "\t\tX= " << abscisa << endl;
      }
    }
		
    else {
      cout << "Recta horizontal con corte al eje Y en Y= " << CalculoOrdenadaOrigenRecta(B1, C1);
    }
  }
		
  else {
    cout << "Recta vertical con corte al eje X en X= " << -C1 / A1 << endl;
  }
	
  cout << endl << "Segunda recta:" << endl;
	
  if (B2 != 0) {
		
    for (abscisa = ORIGEN_INTERVALO_X; abscisa <= EXTREMO_INTERVALO_X; abscisa += INCREMENTO_X) {   
      ordenada = CalculoOrdenadaRecta (A2, B2, C2, abscisa);
      
      cout << "X= " << abscisa << "\t\tY= " << ordenada << endl;       
    } 		
			
    cout << endl;
			
    if (A2 != 0) {
			
      for (ordenada = ORIGEN_INTERVALO_Y; ordenada <= EXTREMO_INTERVALO_Y; ordenada += INCREMENTO_Y) {
	abscisa = CalculoAbscisaRecta (A2, B2, C2, ordenada);
	cout << "Y= " << ordenada << "\t\tX= " << abscisa << endl;
      }
    }
		
    else {
      cout << "Recta horizontal con corte al eje Y en Y= " << CalculoOrdenadaOrigenRecta(B2, C2);
    }
  }
		
  else {
    cout << "Recta vertical con corte al eje X en X= " << -C2 / A2 << endl;
  }
	
  cout << endl << "Primera recta: " << endl;
  EscribirExplicita(A1, B1, C1);
  cout << "Segunda recta: " << endl;
  EscribirExplicita(A2, B2, C2);
	
  posicion_relativa = PosicionRelativa(A1, B1, C1, A2, B2, C2);
  cout << endl << posicion_relativa << endl;
}	
