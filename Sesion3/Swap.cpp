/* Programa que intercambia los valores de
   tres variables introducidas por el usurio. */

#include<iostream>

using namespace std;

int main(){

  double x, y, z;
  double auxiliar;

  cout << "Inserte valor de X: ";
  cin >> x;
  cout << "Inserte valor de Y: ";
  cin >> y;
  cout << "Inserte valor de Z: ";
  cin >> z;

  auxiliar = y;
  y = x;
  x = z;
  z = auxiliar;

  cout << "X = " << x << "\n";
  cout << "Y = " << y << "\n";
  cout << "Z = " << z << "\n";
}
