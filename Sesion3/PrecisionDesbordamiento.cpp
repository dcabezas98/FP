/* Programa para comprobar si se produce o no pérdida 
   de precisión o desbordamiento en distintos casos. */
   
#include<iostream>
#include<cmath> 
   
using namespace std;
  
int main() {
   	
  cout.precision(50);
   
  /* Ejemplo(a) */
   	
  int chico, chico1, chico2;
   	
  chico1 = 1234567;
  chico2 = 1234567;
  chico = chico1 * chico2;
   	
  cout << chico << "\n";
   	
  /* Ejemplo(b) */
   	
  long grande;
   	
  grande = chico1 * chico2;
      
  cout << grande << "\n";
      
  /* Ejemplo(c) */
      
  double real, real1, real2;
      
  real1 = 123.1;
  real2 = 124.2;
  real = real1 * real2;
      
  cout << real << "\n";
      
  /* Ejemplo(d) */
            
  real1 = 123456789.1;
  real2 = 123456789.2;
  real = real1 * real2;
      
  cout << real << "\n";
      
  /* Ejemplo(e) */
      
  double otro_real;
      
  real = 2e34;
  otro_real = real +1;
  otro_real = otro_real - real;
      
  cout << otro_real << "\n";
      
  /* Ejemplo(f) */
      
  real = 1e+300;
  otro_real = 1e+200;
  otro_real = otro_real * real;
      
  cout << otro_real << "\n";
      
  /* Ejemplo(g) */
      
  float chico0;
  double grande0;
      
  grande0 = 2e+150;
  chico0 = grande0;
      
  cout << chico0 << "\n";
  cout << grande0 << "\n";
      
  system("pause");
}
