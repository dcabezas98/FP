/* Programa que lee el número de kilómetros de un vuelo y
   si el comprador es cliente previo. Calcula el precio
   del billete teniendo en cuenta las ofertas de la compañía
   cuando el descuento de cliente previo se acumula con los
   demás descuentos y cuando los descuentos son excluyentes. */

#include<iostream>
#include<cmath>

using namespace std;

int main () {

  char cliente_previo;
  unsigned int kilometros;
  double precio_inicial;
  double precio_final_acumulativo;
  double precio_final_excluyente;
  double descuento = 0;

  const double DESCUENTO_CLIENTE_PREVIO = 5;
  const double KM_DESCUENTO1 = 600;
  const double KM_DESCUENTO2 = 1100;
  const double DESCUENTO1 = 3;
  const double DESCUENTO2 = 4;
  const double TARIFA_INICIAL = 150;
  const double KM_PRECIO_INICIAL = 200;
  const double PRECIO_KM = 0.1;
  const double REBAJA_LINEAL = 15;

  do {
    cout << "Se trata de un cliente previo? (s/n): ";
    cin >> cliente_previo;
  } while (cliente_previo != 's' && cliente_previo != 'n');

  cout << "Cuántos kilómetros va a viajar? ";
  cin >> kilometros;

  if (kilometros <=	KM_PRECIO_INICIAL)                                             // Precio mínimo.
    precio_inicial = TARIFA_INICIAL - REBAJA_LINEAL;

  else {
    precio_inicial = TARIFA_INICIAL + (kilometros - KM_PRECIO_INICIAL) * PRECIO_KM - REBAJA_LINEAL;  // El precio se calcula igual para el resto de casos.
  }

  if (cliente_previo == 's') {
    descuento += DESCUENTO_CLIENTE_PREVIO;
    precio_final_excluyente = precio_inicial - precio_inicial * DESCUENTO_CLIENTE_PREVIO / 100;
  }

  if (kilometros > KM_DESCUENTO1 && kilometros <= KM_DESCUENTO2)
    descuento += DESCUENTO1;

  else if (kilometros > KM_DESCUENTO2)
    descuento += DESCUENTO2;

  if (cliente_previo == 'n') {                                                                         // Se calcula el precio final si los descuentos
    if (kilometros > KM_DESCUENTO1 && kilometros <= KM_DESCUENTO2)                                    // son excluyentes y el comprador no es cliente
      precio_final_excluyente = precio_inicial - precio_inicial * DESCUENTO1 / 100;  					  // previo.

    else if (kilometros > KM_DESCUENTO2)
      precio_final_excluyente = precio_inicial - precio_inicial * DESCUENTO2 / 100;

    else {
      precio_final_excluyente = precio_inicial;
    }
  }

  precio_final_acumulativo = precio_inicial - precio_inicial  * descuento / 100;

  cout << "El precio final en caso de que el descuento de cliente previo sea acumulativo es: " << precio_final_acumulativo << " euros.\n";
  cout << "El precio final en caso de que el descuento de cliente previo sea excluyente es: " << precio_final_excluyente << " euros.\n";
}

/* He considerado que la rebaja lineas se aplica antes de realizar los descuentos porcentuales, lo que resulta ventajoso para la compañía */
