/* Programa que suaviza los píxeles negativos de una imagen, haciendo
   la media de los píxeles no negativos alrededor de cada uno. */
	
#include<iostream>

using namespace std;

const int MAX_FILAS = 100;     // Las uso tanto en el main como en la clase
const int MAX_COLUMNAS = 100;

class ImagenBlancoNegro {
	
private:
				
  int filas;
  int columnas;
  int matriz[MAX_FILAS][MAX_COLUMNAS] = {{}};
		
public:
		
  /* Constructor */
  ImagenBlancoNegro(int fil, int col) {
    filas = fil;
    columnas = col;
  }
		
  /* Métodos set */
		
  /* Modifica el valor de una casilla */
  void Modifica(int fil, int col, int nuevo) {
			
    if(fil < filas && fil >= 0 && col < columnas && col >= 0)
      matriz[fil][col] = nuevo;
  }
		
  /* Métodos get */
		
  /* Devuelve el valor de una casilla */
  int Pixel(int fil, int col) {
    return matriz[fil][col];
  }
	   
  /* Otros métodos */
	   
  /* Método para obtener la imagen suavizada */
  ImagenBlancoNegro MeanFilterForSmoothing() {
	   	
    ImagenBlancoNegro suavizada(filas, columnas);
	   	
    int i, j, k, l, suma, divisor;
	   	
    for(i = 0; i < filas; i++) { // Recorro la matriz original
      for(j = 0; j < columnas; j++) {
			   	
	if(matriz[i][j] < 0 && i != 0 && j != 0 && i != filas-1 && j != columnas-1) { // Si un elemento es negativo y no pertenece al borde:
			   		
	  suma = 0;
	  divisor = 9; // La casilla que estoy modificando (en la otra matriz) es negativa al menos entrará una vez en el else 
			   		
	  for(k = i-1; k <= i+1; k++) { // Recooro las casillas circundantes
	    for(l = j-1; l <= j+1; l++) {
			   				
	      if(matriz[k][l] >= 0) // Hago la media de las que son positivas
		suma += matriz[k][l];
									 
	      else
		divisor--; // Sólo divido entre las positivas
	    }
	  }
	  if(suma == 0) 
	    suavizada.Modifica(i,j,suma); // Se modifica el píxel en la suavizada (sin dividir por 0)
			         
	  else
	    suavizada.Modifica(i,j,suma/divisor);
	}
					
	else 
	  suavizada.Modifica(i,j,matriz[i][j]); // Si es positivo o del borde, directamente se copia
      }
    }
    return suavizada; // Se devuelve la suavizada
  }		
};
         
int main() {
	
  int fil, col, i, j, elemento;
	
  do {
    cout << "Filas: ";
    cin >> fil;
  } while(fil < 1 || fil >= MAX_FILAS);
	
  do {
    cout << "Columnas: ";
    cin >> col;
  } while(col < 1 || col >= MAX_COLUMNAS);
	   
  ImagenBlancoNegro original(fil, col);
	
  for(i = 0; i < fil; i++) {
    for(j = 0; j < col; j++) {
			
      cout << "Fila " << i+1 << ", columna " << j+1 << ": ";
      cin >> elemento;
			
      original.Modifica(i,j,elemento);
    }
  }			
			
  ImagenBlancoNegro suavizada(fil, col);
   
  suavizada = original.MeanFilterForSmoothing();
   
  cout << "Matriz suavizada:\n\n";
   
  for(i = 0; i < fil; i++) {
    for(j = 0; j < col; j++) {
      cout << " " << suavizada.Pixel(i,j) << " ";
    }
    cout << "\n";
  }
}
