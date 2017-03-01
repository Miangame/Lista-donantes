/*! 
  \file funcionesDonantes.hpp
  \brief Funcion para mostrar un menu del programa en el mainDonantes()
  \author Miguel Angel Gavilan Merino
  \date 13/04/2016
*/


#ifndef FUNCIONESDONANTES_HPP
#define FUNCIONESDONANTES_HPP


// Funciones de cabecera
#include <iostream>
#include <cstdio>
#include <unistd.h>
#include <fstream>
#include <sstream>
#include "donantes.hpp"
#include "donante.hpp"
#include "macros.hpp"



// Facilita la entrada y salida
using namespace ed;
using std::stringstream;
using std::string;
using std::ios;
using std::ofstream;
using std::ifstream;
using std::cout;
using std::cin;
using std::endl;



void guardarLista(Donantes lista, string nombreFich);
Donantes cargarLista(string nombreFich);


//! \name Funcion menu para el programa

/*! 
	\brief Muestra un menu en el main para hacer funcionar el programa
*/
void menu()
{	
	Donantes lista;
	int opc;
	char nombre[30];
	char apellidos[30];
	string nombreFich;
	Donante d, d2, d3;
	int pos;
	
	do
	{
		BORRAR;
		LUGAR(5, 10);
		cout << "-----Escoja alguna de las siguientes opciones-----";
		LUGAR(7,10);
		cout << "1. Comprobar si hay donantes" << endl;
		LUGAR(8,10);
		cout << "2. Cargar lista de donantes desde un fichero" << endl;
		LUGAR(9,10);
		cout << "3. Grabar lista de donantes en un fichero" << endl;
		LUGAR(10,10);
		cout << "4. Insertar un nuevo donante" << endl;
		LUGAR(11,10);
		cout << "5. Modificar la informacion de un donante" << endl;
		LUGAR(12,10);
		cout << "6. Borrar un donante de la lista" << endl;
		LUGAR(13,10);
		cout << "7. Mostrar los donantes de sangre" << endl;
		LUGAR(14,10);
		cout << "8. Salir del programa" << endl;
		LUGAR(16,10);
		cout << "Opcion --> ";
		cin >> opc;	


		switch(opc)
		{
			case 1:
				if(lista.estaVacia()==0)
				{
					getchar();
					BORRAR;
					LUGAR(10, 5);
					cout << ">>>La lista de donantes está vacia";

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
					getchar();
					BORRAR;
					LUGAR(10, 5);
					cout << ">>>La lista de donantes no está vacia";

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
			break;

			case 2:
				BORRAR;
				LUGAR(10, 5);
				cout <<"Introduzca el nombre del fichero: ";
				cin >> nombreFich;
				

				lista=cargarLista(nombreFich);

				if(lista.estaVacia()==0)
				{
					getchar();
					BORRAR;
					LUGAR(10, 5);
					cout << ">>>El fichero está vacio...";

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
					getchar();
					BORRAR;
					LUGAR(10, 5);
					cout << ">>>Fichero leido correctamente...!!";

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

			case 3:
				BORRAR;
				LUGAR(10, 5);
				cout <<"Introduzca el nombre del fichero: ";
				cin >> nombreFich;
				guardarLista(lista, nombreFich);

				getchar();
				BORRAR;
				LUGAR(10, 5);
				cout << ">>>Lista volcada en fichero correctamente...!!";

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
			break;

			case 4:
				lista.leerDonantes();

				BORRAR;
				LUGAR(10, 5);
				cout << ">>>Donante añadido correctamente...!!";

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
			break;

			case 5: 
				BORRAR;
				LUGAR(5, 2);
				cout << "Introduzca el nombre de la persona que quiere modificar: ";
				getchar();
				cin.getline(nombre, 30);

				LUGAR(7, 2);
				cout << "Introduzca los apellidos de la persona que quiere modificar: ";
				cin.getline(apellidos, 30);

				pos=lista.buscaItem(nombre, apellidos);

				if (pos!=-1)
				{
					char mod;
					char nombre2[30];
					char apellidos2[30];
					char grSang2[30];
					char rh2[30];

					d3=lista.item(pos);

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
							cin.getline(nombre2,30);

							d.setNombre(nombre2);
							d.setApellidos(d3.getApellidos());
							d.setGrSang(d3.getGrSang());
							d.setRH(d3.getRH());

							lista.eliminar(d3);
							lista.inserta(d);

						
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
							cin.getline(apellidos2, 30);
							
							d.setNombre(d3.getNombre());
							d.setApellidos(apellidos2);
							d.setGrSang(d3.getGrSang());
							d.setRH(d3.getRH());

							lista.eliminar(d3);
							lista.inserta(d);

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
								cin >> grSang2;
								
								if(strcmp(grSang2, "A") != 0 && strcmp(grSang2, "B") != 0 && strcmp(grSang2, "AB") != 0 && strcmp(grSang2, "0") != 0)
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
									d.setNombre(d3.getNombre());
									d.setApellidos(d3.getApellidos());
									d.setGrSang(grSang2);
									d.setRH(d3.getRH());

									lista.eliminar(d3);
									lista.inserta(d);

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
							}while(strcmp(grSang2, "A") != 0 && strcmp(grSang2, "B") != 0 && strcmp(grSang2, "AB") != 0 && strcmp(grSang2, "0") != 0);
						break;

						case 'R':
							do{
								BORRAR;
								LUGAR(10, 5);
								cout << "\nIntroduzca el nuevo RH que quiere asignar: ";
								cin >> rh2;
								cout << endl;

								if(strcmp(rh2, "+") !=0 && strcmp(rh2, "positivo") != 0 && strcmp(rh2, "-") != 0 && strcmp(rh2, "negativo") != 0)
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
									d.setNombre(d3.getNombre());
									d.setApellidos(d3.getApellidos());
									d.setGrSang(d3.getGrSang());
									d.setRH(rh2);

									lista.eliminar(d3);
									lista.inserta(d);

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
							}while(strcmp(rh2, "+") !=0 && strcmp(rh2, "positivo") != 0 && strcmp(rh2, "-") != 0 && strcmp(rh2, "negativo") != 0);
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
				}
				else
				{
					BORRAR;
					LUGAR(10, 5);
					cout <<">>>Donante no encontrado...";

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
			break;

			case 6: 
				BORRAR;
				LUGAR(5, 2);
				cout << "Introduzca el nombre de la persona que quiere borrar: ";
				getchar();
				cin.getline(nombre, 30);

				LUGAR(7, 2);
				cout << "Introduzca los apellidos de la persona que quiere borrar: ";
				cin.getline(apellidos, 30);

				pos=lista.buscaItem(nombre, apellidos);
				d2=lista.item(pos);

				if(pos!=-1)
				{
					lista.eliminar(d2);

					BORRAR;
					LUGAR(10, 5);
					cout << ">>>Donante borrado correctamente...!!";

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
					BORRAR;
					LUGAR(10, 5);
					cout <<">>>Donante no encontrado...";

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
			break;

			case 7: 
				BORRAR;
				LUGAR(10, 5);

				lista.escribirDonantes(lista);

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
			break;

			case 8: 
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
	}while(opc!=8);

	//Fin de la funcion
}



/*! 
	\brief Guarda una lista en un fichero
	\param lista de tipo Donantes
	\param nombreFich de tipo string
	\pre La lista debe existir
	\post Ninguna
*/
void guardarLista(Donantes lista, string nombreFich)
{
	int i;
	Donante d;
	ofstream f (nombreFich.c_str());
	
	for (i=1; i<=lista.numElementos(); i++)
	{
		d=lista.item(i);
		f << d.getNombre() << "," << d.getApellidos() << "," << d.getGrSang() << "," << d.getRH() << endl;
	}
	f.close();
}




/*! 
	\brief Carga donantes de un fichero y los inserta en una lista
	\param nombreFich de tipo string
	\pre El fichero debe existir
	\post Ninguna
	\return lista
*/
Donantes cargarLista(string nombreFich)
{
	Donantes lista;
	Donante d;
	char nombre[30];
	char apellidos[30];
	char grSang[5];
	char rh[10];
	string l;

	ifstream f (nombreFich.c_str());

	while(getline(f, l))
	{
		stringstream linea (l);

		linea.getline(nombre, 30, ',');
		linea.getline(apellidos, 30, ',');
		linea.getline(grSang, 5, ',');
		linea.getline(rh, 10, '\n');

		d.setNombre(nombre);
		d.setApellidos(apellidos);
		d.setGrSang(grSang);
		d.setRH(rh);

		lista.inserta(d);
	}

	f.close();

	return lista;
} 


// FUNCIONESDONANTES_HPP
#endif