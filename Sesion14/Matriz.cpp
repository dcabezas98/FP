/* Programa que calcula la traspuesta de una matriz, encuentra la
   posici�n del mayor de los m�nimos de cada columna. */

#include<iostream>
using namespace std;

int main() {
	
  const int MAX_FILAS = 100;
  const int MAX_COLUMNAS = 100;
	
  int matriz[MAX_FILAS][MAX_COLUMNAS];
  int filas, columnas, i, j, k, elemento;
	
  /* a) Traspuesta */
  int traspuesta[MAX_FILAS][MAX_COLUMNAS];
		
  cout << "N�mero de filas: ";
  cin >> filas;
  cout << "N�mero de columnas: ";
  cin >> columnas;
	
  for(i = 0; i < filas; i++) { // Lectura de la matriz
    for(j = 0; j < columnas; j++) {
      cout << "Fila " << i+1 << ", columna " << j+1 << ": ";
      cin >> elemento;
      matriz[i][j] = elemento;
    }
  }
			
  for(i = 0; i < filas; i++) { // C�lculo de la traspuesta
    for(j = 0; j < columnas; j++) {
      traspuesta[j][i] = matriz[i][j];
    }
  }
	
  cout << "Traspuesta:\n"; // Expresi�n de la traspuesta
	
  for(j = 0; j < columnas; j++) { // Las columnas de la matriz son las filas de la traspuesta
	   
    cout << "  ";
		
    for(i = 0; i < filas; i++) { // Las filas de la matriz son las columnas de la traspuesta
      cout << traspuesta[j][i] << "  ";
    }
    cout << "\n";
  }
	
  /* b) Mayor entre los m�nimos de cada fila */
  int min, columna_min, fila_mayor_min, columna_mayor_min;     
  int mayor_min = -9999999;
	
  for(i = 0; i < filas; i++) {   
		
    min = matriz[i][0]; // Inicializo el m�nimo al primer elemento de la fila
		
    for(j = 0; j < columnas; j++) { // C�lculo del m�nimo de cada fila
      if(matriz[i][j] < min) {
	min = matriz[i][j];
	columna_min = j;
      }
    }
		
    if(min > mayor_min) { // Si es mayor que el mayor m�nimo, se actualiza
      mayor_min = min;
      fila_mayor_min = i;
      columna_mayor_min = columna_min;
    }
  }
		
  cout << "Mayor m�nimo de cada fila: " << mayor_min << "\n";
  cout << "Su posici�n: (" << fila_mayor_min+1 << ", " << columna_mayor_min+1 << ")\n";
	
  /* c) MaxiMin */	
  int max, columna_max, maximin, fila_maximin, columna_maximin;
  bool encontrado = false, minimo_columna; // Para evitar recorridos innecesarios
		
  for(i = 0; i < filas && !encontrado; i++) {      
		
    max = matriz[i][0];
    columna_max = 0;
		
    for(j = 0; j < columnas; j++) { // B�squeda del m�ximo de una fila 
      if(matriz[i][j] > max) {
	max = matriz[i][j];
	columna_max = j;
      }
    }
	   
    minimo_columna = true; // Compruebo si es el m�nimo de su columna
   	                      
    for(k = 0; k < filas && minimo_columna; k++) {
      if(matriz[k][columna_max] < max)    
	minimo_columna = false;
    }
		
    if(minimo_columna) {
      maximin = max;
      fila_maximin = i;
      columna_maximin = columna_max;
      encontrado = true;
    }
  }
	
  if(encontrado) {
    cout << "La matriz tiene un MaxiMin: " << maximin << "\n";
    cout << "Su posici�n: (" << fila_maximin+1 << ", " << columna_maximin+1 << ")\n"; 
  }
	
  else 
    cout << "La matriz no tiene ning�n MaxiMin.\n";
		
  /* d) Multiplicaci�n de matrices */
  int matriz2[MAX_FILAS][MAX_COLUMNAS];
  int producto[MAX_FILAS][MAX_COLUMNAS];
  int columnas2, suma;
	
  cout << "Columnas segunda matriz: "; // Su n�mero de filas ser� el de columnas de la primera matriz
  cin >> columnas2;
	
  for(i = 0; i < columnas; i++) {
    for(j = 0; j < columnas2; j++) {
      cout << "Fila " << i+1 << ", columna " << j+1 << ": ";
      cin >> elemento;
      matriz2[i][j] = elemento; 
    }
  }
	
  for(i = 0; i < filas; i++) {
    for(j = 0; j < columnas2; j++) {	
      suma = 0;
		   
      for(k = 0; k < columnas; k++) {
	suma = suma + matriz[i][k] * matriz2[k][j];
      }
		   
      producto[i][j] = suma;
    }
  }
	
  cout << "Matriz producto:\n";
	
  for(i = 0; i < filas; i++) {   
		   
    cout << "  ";
		
    for(j = 0; j < columnas2; j++) {   
      cout << producto[i][j] << "  ";
    }
    cout << "\n";
  }
}           
