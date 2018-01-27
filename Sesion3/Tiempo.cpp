/* Programa que expresa el tiempo introducido en horas, minutos
   y segundos respetando un intervalo máximo de 24 horas y 
   expresando en días el tiempo que excede de ese intervalo. */

#include<iostream>
#include<cmath>

using namespace std;

int main(){
	
  int horas1, minutos1, segundos1, tiempo,
    dias,	horas2, minutos2, segundos2; 
	
  cout << "Inserte horas: ";
  cin >> horas1;
  cout << "Inserte minutos: ";
  cin >> minutos1;
  cout << "Inserte segundos: ";
  cin >> segundos1;
	
  tiempo = horas1 * 3600 + minutos1 * 60 + segundos1;    // Se calcula el tiempo total en segundos,
  dias = tiempo / 86400;                                 // se divide entre los segundos de un dia y
  horas2 = (tiempo % 86400) / 3600;                      // se usa el resto para calcular las horas,
  minutos2 = ((tiempo % 86400) % 3600) / 60;             // esto se repite para los minutos y segundos.
  segundos2 = (((tiempo % 86400) % 3600) % 60);
	
  cout << "Dias: " << dias << "\n";
  cout << "Horas: " << horas2 << "\n";
  cout << "Minutos: " << minutos2 << "\n";
  cout << "Segundos: " << segundos2 << "\n";
	
  system("pause");
}
