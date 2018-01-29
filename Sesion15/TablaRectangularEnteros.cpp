/* 
   Programa que lee los datos de una matriz, indica si es simétrica o
   no, calcula su traspuesta y la multiplica por su traspuesta.
*/

#include<iostream>

using namespace std;

		
const int MAX_FILAS = 50;
const int MAX_COLUMNAS = 50;

class SecuenciaEnteros{
private:
  static const int TAMANIO = 50;
  long vector_privado[TAMANIO];
  int total_utilizados;
   
  void IntercambiaComponentes_en_Posiciones(int pos_izda, int pos_dcha){
    long intercambia;

    intercambia = vector_privado[pos_izda];
    vector_privado[pos_izda] = vector_privado[pos_dcha];
    vector_privado[pos_dcha] = intercambia;
  }
public:
  SecuenciaEnteros()
    :total_utilizados(0) {
  }
   
  int TotalUtilizados(){
    return total_utilizados;
  }
   
  int Capacidad(){
    return TAMANIO;
  }
   
  void EliminaTodos(){
    total_utilizados = 0;
  }
   
  void Aniade(long nuevo){
    if (total_utilizados < TAMANIO){
      vector_privado[total_utilizados] = nuevo;
      total_utilizados++;
    }
  }
   
  void Modifica(int posicion, long nuevo){
    if (posicion >= 0 && posicion < total_utilizados)
      vector_privado[posicion] = nuevo;
  }

  long Elemento(int indice){
    return vector_privado[indice];
  }
};

class LectorSecuenciaEnteros{
private:
  long terminador;
public:
  LectorSecuenciaEnteros(long entero_terminador)
    :terminador(entero_terminador)
  {
  }
  SecuenciaEnteros Lee(){
    SecuenciaEnteros a_leer;
    int total_introducidos; // Esta variable es para contar los introducidos y que no nos pasemos de la capacidad de la secuencia.
    int capacidad_secuencia;
    long entero;

    total_introducidos = 0;
    capacidad_secuencia = a_leer.Capacidad();
    cin >> entero;

    while (entero != terminador && total_introducidos < capacidad_secuencia){
      a_leer.Aniade(entero);
      total_introducidos++;
      cin >> entero;
    }

    return a_leer;
  }
};

class TablaRectangularEnteros {
	
private:

  int matriz_privada[MAX_FILAS][MAX_COLUMNAS];
		
  int filas, columnas;
		
public:	
	
  TablaRectangularEnteros(int j) {
    columnas = j;
    filas = 0;
  }
	   
  TablaRectangularEnteros(int i, int j) {
    columnas = j;
    filas = i;
  }
		   		
  /* Métodos get */
		
  /* Método que devuelve el número de filas utilizadas */
  int FilasUtilizadas() {
    return filas;
  }
		
  /* Método que devuelve el número de columnas utilizadas */
  int ColumnasUtilizadas() {
    return columnas;
  }
		
  /* Método que devuelve el entero en la posición (i,j) */
  int Elemento(int i, int j) {
    return matriz_privada[i][j];
  }
			
  /* Devuelve una fila de la matriz como objeto SecuenciaEnteros */
  SecuenciaEnteros Fila(int i) {
			
    SecuenciaEnteros fila;
			
    for(int j = 0; j < columnas; j++) {
				
      fila.Aniade(matriz_privada[i][j]);
    }
    return fila;
  }
		
  /* Métodos set */
		
  /* Añade una fila completa, como objeto SecuenciaEnteros */
  void AniadeFila(SecuenciaEnteros fila) {
			
    int i = filas;
			
    for(int j = 0; j < columnas; j++) {
				
      matriz_privada[i][j] = fila.Elemento(j);
    }
    filas++;
  }
		
  /* Modifica una casilla (i,j) */
  void Modifica(int i, int j, int nuevo) {
    //	if(i >= 0 && i < MAX_FILAS && j >= 0 && j < MAX_COLUMNAS) 
    matriz_privada[i][j] = nuevo;
  }
		
  /* Otros métodos */
		
  /* Devuelve la traspuesta de la matriz */
  TablaRectangularEnteros Traspuesta() {
		
    TablaRectangularEnteros traspuesta(columnas,filas);
		   
    for(int i = 0; i < filas; i++) {
      for(int j = 0; j < columnas; j++) {
	traspuesta.Modifica(j,i,matriz_privada[i][j]);
      }
    }
    return traspuesta;
  }

  /* Combrueba si la matriz es igual a otra */
  bool Igual(TablaRectangularEnteros matriz) {
         
    bool iguales = true;
         
    if(filas != matriz.FilasUtilizadas() || columnas != matriz.ColumnasUtilizadas())
      iguales = false;
            
    for(int i = 0; i < filas && iguales; i++) {
      for(int j = 0; j < columnas && iguales; j++) {
	iguales = matriz_privada[i][j] == matriz.Elemento(i,j);
      }
    }
    return iguales;
  }
      
  /* Comprueba si es simétrica, llamando a Igual y a Traspuesta */
  bool Simetrica() {
      	
    TablaRectangularEnteros traspuesta(Traspuesta());
      	
    return Igual(traspuesta);
  }
      
  /* Comprueba si es simétrica directamente */
  bool Simetrica2() {
      	
    bool simetrica = true;
      	
    for(int i = 0; i < filas && simetrica; i++) {
      for(int j = i; j < columnas && simetrica; j++) {
	simetrica = matriz_privada[i][j] == matriz_privada[j][i];
      }
    }
    return simetrica;
  }
      
  TablaRectangularEnteros Multiplica(TablaRectangularEnteros matriz) {
      	
    if(columnas == matriz.FilasUtilizadas()) {
      	
      TablaRectangularEnteros producto(matriz.ColumnasUtilizadas());
      int i, j, k, suma;
			   
      for(i = 0; i < filas; i++) {
	for(j = 0; j < matriz.ColumnasUtilizadas(); j++) {
			   		
	  suma = 0;
			   		
	  for(k = 0; k < columnas; k++) {
	    suma = suma + matriz_privada[i][k] * matriz.Elemento(k,j);
	  }
	  producto.Modifica(i, j, suma);
	}
      }
      return producto;
    }
  }
};

int main() {
	
  int fil, col, i, j;
  const long TERMINADOR = -1;
  LectorSecuenciaEnteros lector_secuencias(TERMINADOR);
	
  do {
    cout << "Filas: ";
    cin >> fil;
  } while(fil <= 0 || fil > MAX_FILAS);
	
  do {
    cout << "Columnas: ";
    cin >> col;
  } while(col <= 0 || col > MAX_COLUMNAS);
	
  TablaRectangularEnteros matriz(col);

  for(i = 0; i < fil; i++) {
   	
    SecuenciaEnteros fila;
	   
    cout << "Fila " << i+1 << ":\n";
    fila = lector_secuencias.Lee();
    matriz.AniadeFila(fila);
  }
    	
  TablaRectangularEnteros traspuesta(matriz.Traspuesta());
	 	 	
  if(matriz.Simetrica())
    cout << "Simétrica\n";  
    
  else {
    cout << "No simétrica\n\n";
				
    cout << "Traspuesta\n\n";
    for(i = 0; i < col; i++) {
      for(j = 0; j < fil; j++) {
	cout << " " << traspuesta.Elemento(i,j) << " ";
      }
      cout << "\n";
    }
  }
 	
  TablaRectangularEnteros producto(matriz.Multiplica(traspuesta));
 	
  cout << "Producto por su traspuesta \n\n";
 	
  for(i = 0; i < fil; i++) {
    for(j = 0; j < fil; j++) {
      cout << " " << producto.Elemento(i,j) << " ";
    }
    cout << "\n";
  }
}
