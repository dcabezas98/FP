/* Programa que permite a dos jugadores jugar al tres-en-raya. */

#include<iostream>

using namespace std;

class TresEnRaya {
	
private:
		
  int tablero[3][3] = {{1,2,3},{4,5,6},{7,8,9}}; // Tablero inicial
  bool jugadorX[3][3] = {{}}; // Ningún jugador ha jugado aún,
  bool jugadorO[3][3] = {{}}; // luego todos están en false
		
  bool ocupada_priv(int i, int j) {
    return jugadorX[i][j] || jugadorO[i][j];
  }
				
public:
		
  /* Métodos get */
  void muestra() {
    for(int i = 0; i < 3; i++) {
      for(int j = 0; j < 3; j++) {
					
	if(jugadorX[i][j])
	  cout << " X ";
		           
	else if(jugadorO[i][j])
	  cout << " O ";   			   
		         
	else
	  cout << " " << tablero[i][j] << " ";
      }
      cout << "\n";
    }
  }  
         
  bool ocupada(int a) {
      	
    bool ocupada = false;
      	
    for(int i = 0; i < 3 && !ocupada; i++) {
      for(int j = 0; j < 3 && !ocupada; j++) {
      			
	if(a == tablero[i][j])
	  ocupada = ocupada_priv(i,j);
      }
    }
      	
    return ocupada;
  }		
      
  char resultado() {
      	
    if(jugadorX[0][0] && jugadorX[0][1] && jugadorX[0][2] ||
       jugadorX[1][0] && jugadorX[1][1] && jugadorX[1][2] ||
       jugadorX[2][0] && jugadorX[2][1] && jugadorX[2][2] ||
       jugadorX[0][0] && jugadorX[1][0] && jugadorX[2][0] ||
       jugadorX[0][1] && jugadorX[1][1] && jugadorX[2][1] ||
       jugadorX[0][2] && jugadorX[1][2] && jugadorX[2][2] ||
       jugadorX[0][0] && jugadorX[1][1] && jugadorX[2][2] ||
       jugadorX[0][2] && jugadorX[1][1] && jugadorX[2][0])
      	   
      return 'X';
   	   
    else if(jugadorO[0][0] && jugadorO[0][1] && jugadorO[0][2] ||
	    jugadorO[1][0] && jugadorO[1][1] && jugadorO[1][2] ||
	    jugadorO[2][0] && jugadorO[2][1] && jugadorO[2][2] ||
	    jugadorO[0][0] && jugadorO[1][0] && jugadorO[2][0] ||
	    jugadorO[0][1] && jugadorO[1][1] && jugadorO[2][1] ||
	    jugadorO[0][2] && jugadorO[1][2] && jugadorO[2][2] ||
	    jugadorO[0][0] && jugadorO[1][1] && jugadorO[2][2] ||
	    jugadorO[0][2] && jugadorO[1][1] && jugadorO[2][0])
   	           
      return 'O';
   	           
    else
      return '-';
  }
				  	   
  /* Métodos set */   
  void juegaX(int a) {
      	
    bool done = false;
      	
    for(int i = 0; i < 3 && !done; i++) {
      for(int j = 0; j < 3 && !done; j++) {
      	   	
	if(a == tablero[i][j] && !ocupada_priv(i,j)) { // Se busca la casilla
	  jugadorX[i][j] = true;  // El jugador pone su símbolo
	  done = true;
	}
      }
    }
  }
      
  void juegaO(int a) { 
      	
    bool done = false; // Para cortar el bucle cuando se realice la jugada
      	
    for(int i = 0; i < 3 && !done; i++) {
      for(int j = 0; j < 3 && !done; j++) {
      	   	
	if(a == tablero[i][j] && !ocupada_priv(i,j)) { // Se busca la casilla y se comprueba que no esté marcada
	  jugadorO[i][j] = true; // El jugador pone su símbolo
	  done = true;
	}
      }
    }
  }
};
      
int main() {

  int casilla;
  char continuar;
   
  do {
    bool fin = false;
    TresEnRaya juego;
	         
    for(int turno = 1; turno <=4 && !fin; turno++) {
	   	
      juego.muestra();
	   	
      do {
	do {
	  cout << "Juega X: ";    // Turno de X
	  cin >> casilla;
	} while(casilla < 1 || casilla > 9);
	      
	if(juego.ocupada(casilla)) {
	  cout << "Movimiento inválido, inténtelo de nuevo.\n";
	  juego.muestra();
	}
	                 
      } while(juego.ocupada(casilla));
	      
      juego.juegaX(casilla);
	      
      if(juego.resultado() != '-') {
	fin = true;
      }
	      
      juego.muestra();
	      
      do {
	do {
	  cout << "Juega O: ";   // Turno de O
	  cin >> casilla;
	} while(casilla < 1 || casilla > 9);
	  	   
	if(juego.ocupada(casilla)) {
	  cout << "Movimiento inválido, inténtelo de nuevo.\n";
	  juego.muestra();
	}  
	  	     	         
      } while(juego.ocupada(casilla));
	      
      juego.juegaO(casilla);
	      
      if(juego.resultado() != '-')
	fin = true;
    } 
	   
    if(!fin) {
      juego.muestra();
		   	
      do {
	do {
	  cout << "Juega X: ";   // Último turno de X
	  cin >> casilla;
	} while(casilla < 1 || casilla > 9);
		      
	if(juego.ocupada(casilla)) {
	  cout << "Movimiento inválido, inténtelo de nuevo.\n";
	  juego.muestra();
	}
		                 
      } while(juego.ocupada(casilla));
		      
      juego.juegaX(casilla);
    }
	      
    if(juego.resultado() == '-') 
      cout << "\nEmpate\n"; 
	   
    else
      cout << "\nGanador: " << juego.resultado() << "\n";
	      
    juego.muestra();
	   
    do {
      cout << "¿Nueva partida? (s/n) ";
      cin >> continuar;
      continuar = toupper(continuar);
    } while(continuar != 'S' && continuar != 'N');
	      
  } while(continuar == 'S');
}
