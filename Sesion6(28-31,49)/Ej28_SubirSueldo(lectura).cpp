/* Programa que lee los datos introducidos correspondientes
	a los casos de un centro de atenci�n telef�nica hasta que
	se introduzca un terminador e imprime el n�mero de casos, 
	el c�digo del empleado con m�s valoraci�n	por satisfacci�n
	 y su media de satisfacci�n al cliente. */
	
	#include<iostream>
	#include<cmath>
	
	using namespace std;
	
	int main () {
		
		double salario_hora, grado_satisfaccion,
		satisfaccion1 = 0, satisfaccion2 = 0,
		satisfaccion3 = 0 , satisfaccion_media1,
		satisfaccion_media2, satisfaccion_media3;
		int duracion, empleado, casos_totales, casos1 = 0, 
		casos2 = 0, casos3 = 0; 
		bool resuelto;
		const int TERMINADOR = -1;
		
		cout << "Inserte salario por hora: ";                              
		cin >> salario_hora;
			
		do {
			
			cout << "C�digo de empleado (1, 2 � 3): ";                    
			cin >> empleado;
			
			if ( empleado == 1 || empleado == 2 || empleado == 3) {          // Este condicional aprovecha el cuerpo del programa como filtro  
																			                 // de entrada y evita que el programa pida el resto de datos
				cout << "Segundos de duraci�n de la llamada: ";               // en caso de introducir el terminador.
				cin >> duracion;
			
				cout << "Si el caso se ha resuelto tatisfactoriamente inserte 1, en caso contrario, inserte 0: ";
				cin >> resuelto;
							
				do {
		   	cout << "Inserte grado de satisfacci�n del cliente (entre 0 y 5): ";
		   	cin >> grado_satisfaccion;
		   	} while (grado_satisfaccion < 0 || grado_satisfaccion > 5);
		   		   	
		   	switch (empleado) {
		   		
					case (1):
						casos1++;
						satisfaccion1 += grado_satisfaccion;
						break;
						
					case (2):
						casos2++;
						satisfaccion2 += grado_satisfaccion;
						break;
						
					case (3):
						casos3++;
						satisfaccion3 += grado_satisfaccion;
						break;
				}
			}
	   } while (empleado != TERMINADOR);
	   
	   if (casos1 != 0)                                        // Debo considerar la posibilidad de
	   satisfaccion_media1 = satisfaccion1 / casos1;           // puede no introducirse ning�n caso para
	   if (casos2 != 0)                                        // alguno de los empleados.
	   satisfaccion_media2 = satisfaccion2 / casos2;
	   if (casos3 != 0)
	   satisfaccion_media3 = satisfaccion3 / casos3;
	   
	   casos_totales = casos1 + casos2 + casos3;
	   
	   if (casos_totales != 0) {
	   	cout << "N�mero de casos: " << casos_totales << endl;
	   	
		   	if (satisfaccion_media1 > satisfaccion_media2 && satisfaccion_media1 > satisfaccion_media3) 
		   		cout << "El empleado 1 ha obtenido la mayor media de satisfacci�n de los clientes con: " << satisfaccion_media1;
		   		
		   else if (satisfaccion_media2 > satisfaccion_media1 && satisfaccion_media2 > satisfaccion_media3)
		   		cout << "El empleado 2 ha obtenido la mayor media de satisfacci�n de los clientes con: " << satisfaccion_media2;
		  
		   else if (satisfaccion_media3 > satisfaccion_media1 && satisfaccion_media3 > satisfaccion_media2)
					cout << "El empleado 3 ha obtenido la mayor media de satisfacci�n de los clientes con: " << satisfaccion_media3;
	   }
		
	   else {
	   	cout << "No se ha introducido ning�n caso."; }
	}
