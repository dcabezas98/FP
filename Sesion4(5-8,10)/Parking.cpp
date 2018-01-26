/* Programa que calcula el precio a pagar en el parking
   a partir de las horas de entrada y salida */
	
#include<iostream>
#include<cmath>
	
using namespace std;
	
int main () {
  int hora_entrada, minuto_entrada, segundo_entrada,
    hora_salida, minuto_salida, segundo_salida,
    tiempo_total;
  double tarifa;
		
  cout << "Inserte hora de entrada: ";
  cin >> hora_entrada;
  cout << "Inserte minuto de entrada: ";
  cin >> minuto_entrada;
  cout << "Inserte segundo de entrada: ";
  cin >> segundo_entrada;
  cout << "Inserte hora de salida: ";
  cin >> hora_salida;
  cout << "Inserte minuto de salida: ";
  cin >> minuto_salida;
  cout << "Inserte segundo de salida: ";
  cin >> segundo_salida;
		
  tiempo_total = hora_salida * 3600 + minuto_salida * 60 + segundo_salida - hora_entrada * 3600 - minuto_entrada *60 - segundo_entrada;
		
  tiempo_total = tiempo_total / 60;       // Paso a minutos
		
  if (tiempo_total > 660) 
    tarifa = 31.55;
			
  else {
    if (tiempo_total >= 0 && tiempo_total <= 30)
      tarifa = tiempo_total * 0.0412;
				
    else {
      if (tiempo_total > 30 && tiempo_total <= 90)
	tarifa = 1.236 + (tiempo_total - 30) * 0.0370;   // 1.236 es el precio de los primeros 30 minutos.
				
      else {
	if (tiempo_total > 90 && tiempo_total <= 660)
	  tarifa = 3.456 + (tiempo_total - 90) * 0.0493; }  // 3.456 es el precio de los primeros 90 minutos.
    }
  }
		
  cout << "Tiempo transcurrido: " << tiempo_total << " minutos.\n";
  cout << "La tarifa a pagar es: " << tarifa << " euros.\n";
	
  system("pause");
}
