/*! 
  \file funcionesDonante.hpp
  \brief Funcion para mostrar un menu del programa en el mainDonante()
  \author Miguel Angel Gavilan Merino
  \date 
*/


#ifndef FUNCIONESDONANTE_HPP
#define FUNCIONESDONANTE_HPP


// Funciones de cabecera
#include <iostream>
#include <unistd.h>
#include "donante.hpp"
#include "macros.hpp"


// Facilita la entrada y salida
using namespace ed;
using std::cout;
using std::cin;
using std::endl;



//! \name Funcion menu para el programa

/*! 
	\brief Muestra un menu en el main para hacer funcionar el programa
	\pre Se deben pasar 3 Donantes
	\post Ninguna
	\param d de tipo Donante
	\param d2 de tipo Donante
*/
void menu(Donante d, Donante d2)
{	
	int opc;
	
	do
	{
		//Opciones del menu para escoger
		BORRAR;
		LUGAR(5, 10);
		cout << "-----Escoja alguna de las siguientes opciones-----";
		LUGAR(7,10);
		cout << "1. Leer un donante desde teclado" << endl;
		LUGAR(8,10);
		cout << "2. Mostrar donante" << endl;
		LUGAR(9,10);
		cout << "3. Modificar los datos de un donante" << endl;
		LUGAR(10,10);
		cout << "4. Comparar lexicograficamente dos donantes" << endl;
		LUGAR(11,10);
		cout << "5. Fin del programa" << endl;
		LUGAR(13,10);
		cout << "Opcion --> ";
		cin >> opc;	


		switch(opc)
		{
			case 1:
				//Leemos un donante por pantalla
				d.leerDonante();
			break;

			case 2:
				//Escribimos un donante por pantalla
				d.escribirDonante();
			break;

			case 3:
				char mod;
				char nombre[30];
				char apellidos[30];
				char grSang[30];
				char rh[30];

				BORRAR;
				LUGAR(5, 10);
				cout << "Introduzca el campo que quiere modificar: ";
				LUGAR(7, 10);
				cout << "---> N.Nombre";
				LUGAR(9, 10);
				cout << "---> A.Apellidos";
				LUGAR(11, 10);
				cout << "---> G.Grupo sanguineo";
				LUGAR(13, 10);
				cout << "---> R.RH";
				LUGAR(15, 10);
				cout << "Opcion: ";
				cin >> mod;
				cout << endl;

				switch (mod)
				{
					case 'N':
						BORRAR;
						LUGAR(10, 5);
						cout << "Introduzca el nuevo nombre que quiere asignar: ";
						getchar();
						cin.getline(nombre,30);
						d.setNombre(nombre);
					
						BORRAR;
						LUGAR(10, 5);
						cout << ">>>Nombre cambiado correctamente...!!";

						LUGAR(23,25);
						printf("pulse ");
						SUBRAYADO;
						printf("ENTER");
						APAGA;
						printf(" para ");
						INVERSO;
						printf("continuar"); 
						APAGA;
						getchar();
						BORRAR;
					break;

					case 'A':
						BORRAR;
						LUGAR(10, 5);
						cout << "Introduzca los nuevos apellidos que quiere asignar: ";
						getchar();
						cin.getline(apellidos, 30);
						d.setApellidos(apellidos);

						BORRAR;
						LUGAR(10, 5);
						cout << ">>>Apellidos cambiados correctamente...!!";

						LUGAR(23,25);
						printf("pulse ");
						SUBRAYADO;
						printf("ENTER");
						APAGA;
						printf(" para ");
						INVERSO;
						printf("continuar"); 
						APAGA;
						getchar();
						BORRAR;
					break;

					case 'G':
						do
						{
							BORRAR;
							LUGAR(10, 5);
							cout << "Introduzca el nuevo grupo sanguineo que quiere asignar: ";
							cin >> grSang;
							
							if(strcmp(grSang, "A") != 0 && strcmp(grSang, "B") != 0 && strcmp(grSang, "AB") != 0 && strcmp(grSang, "0") != 0)
							{
								BORRAR;
								LUGAR(10, 10);
								getchar();
								cout << ">>>ERROR. Grupo sanguineo no valido...\n" << endl;

								LUGAR(23,25);
								printf("pulse ");
								SUBRAYADO;
								printf("ENTER");
								APAGA;
								printf(" para ");
								INVERSO;
								printf("continuar"); 
								APAGA;
								getchar();
								BORRAR;
							}
							else
							{
								d.setGrSang(grSang);
								BORRAR;
								LUGAR(10, 5);
								cout << ">>>Grupo sanguineo cambiados correctamente...!!";

								LUGAR(23,25);
								printf("pulse ");
								SUBRAYADO;
								printf("ENTER");
								APAGA;
								printf(" para ");
								INVERSO;
								printf("continuar"); 
								APAGA;
								getchar();
								getchar();
								BORRAR;
							}
						}while(strcmp(grSang, "A") != 0 && strcmp(grSang, "B") != 0 && strcmp(grSang, "AB") != 0 && strcmp(grSang, "0") != 0);
					break;

					case 'R':
						do{
							BORRAR;
							LUGAR(10, 5);
							cout << "\nIntroduzca el nuevo RH que quiere asignar: ";
							cin >> rh;
							cout << endl;
							if(strcmp(rh, "+") !=0 && strcmp(rh, "positivo") != 0 && strcmp(rh, "-") != 0 && strcmp(rh, "negativo") != 0)
							{
								BORRAR;
								LUGAR(10, 10);
								getchar();
								cout << ">>>ERROR. RH no valido...\n" << endl;

								LUGAR(23,25);
								printf("pulse ");
								SUBRAYADO;
								printf("ENTER");
								APAGA;
								printf(" para ");
								INVERSO;
								printf("continuar"); 
								APAGA;
								getchar();
								BORRAR;
							}
							else
							{
								d.setRH(rh);
								BORRAR;
								LUGAR(10, 5);
								cout << ">>>RH cambiado correctamente...!!";

								LUGAR(23,25);
								printf("pulse ");
								SUBRAYADO;
								printf("ENTER");
								APAGA;
								printf(" para ");
								INVERSO;
								printf("continuar"); 
								APAGA;
								getchar();
								getchar();
								BORRAR;
							}
						}while(strcmp(rh, "+") !=0 && strcmp(rh, "positivo") != 0 && strcmp(rh, "-") != 0 && strcmp(rh, "negativo") != 0);
					break;

					default: 
						BORRAR;
						PARPADEO;
						getchar();
						cout << ">>>ERROR. Opcion introducida no valida...";
	
	
						APAGA;

						LUGAR(23,25);
						printf("pulse ");
						SUBRAYADO;
						printf("ENTER");
						APAGA;
						printf(" para ");
						INVERSO;
						printf("continuar"); 
						APAGA;
						getchar();
				}
			break;

			case 4:

				if (strcmp(d.getNombre(), "n")==0)
				{
					getchar();
					BORRAR;
					LUGAR(10, 5);
					cout << "Por favor introduzca primero un donante...";
					LUGAR(23,25);
					printf("pulse ");
					SUBRAYADO;
					printf("ENTER");
					APAGA;
					printf(" para ");
					INVERSO;
					printf("continuar"); 
					APAGA;
					getchar();
				}
				else
				{
					BORRAR;
					LUGAR(10, 5);
					d2.leerDonante();
					if(d<=d2)
					{
						BORRAR;
						LUGAR(10, 5);
						cout << d.getNombre() << " " << d.getApellidos() << " va antes que " << d2.getNombre() << " " << d2.getApellidos() << endl;
						
						LUGAR(23,25);
						printf("pulse ");
						SUBRAYADO;
						printf("ENTER");
						APAGA;
						printf(" para ");
						INVERSO;
						printf("continuar"); 
						APAGA;
						getchar();
					}
					else
					{
						BORRAR;
						LUGAR(10, 5);
						cout << d2.getNombre() << " " << d2.getApellidos() << " va antes que " << d.getNombre() << " " << d.getApellidos() << endl;
						
						LUGAR(23,25);
						printf("pulse ");
						SUBRAYADO;
						printf("ENTER");
						APAGA;
						printf(" para ");
						INVERSO;
						printf("continuar"); 
						APAGA;
						getchar();
					}
				}
			break;

			case 5: 
				BORRAR;
				LUGAR(10,50);
				INVERSO;
				cout << "\n>>>Saliendo del programa...\n" << endl;
				APAGA;
				

				LUGAR(23,25);
				printf("pulse ");
				SUBRAYADO;
				printf("ENTER");
				APAGA;
				printf(" para ");
				INVERSO;
				printf("continuar"); 
				APAGA;
				getchar();
				getchar();
				BORRAR;
			break;

			default: 
				BORRAR;
				PARPADEO;
				LUGAR(10,25);
				cout << "\n>>>Opcion incorrecta, vuelva a introducir una opcion valida..\n" << endl;
				
				APAGA;

				LUGAR(23,25);
				printf("pulse ");
				SUBRAYADO;
				printf("ENTER");
				APAGA;
				printf(" para ");
				INVERSO;
				printf("continuar"); 
				APAGA;
				getchar();
				getchar();
		}
	}while(opc!=5);

	//Fin de la funcion
}


// FUNCIONESDONANTE_HPP
#endif