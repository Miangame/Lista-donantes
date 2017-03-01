/*! 
  \file donante.hpp
  \brief Donante crea un donante con nombre, apellidos, grupo sanguineo y RH
  \author Miguel Angel Gavilan Merino
  \date 13/04/2016
*/


#ifndef DONANTE_HPP
#define DONANTE_HPP


// Ficheros de cabecera
#include <iostream>
#include <cstring>
#include <cstdio>
#include "donanteInterfaz.hpp"
#include "macros.hpp"


// Facilita la entrada y salida
using std::cout;
using std::cin;
using std::endl;
using std::istream;
using std::ostream;



/*!
   \brief Espacio de nombres para la asignatura de Estructura de datos.

*/
namespace ed
{
	/*!
	   \brief Clase Donante

	*/
		class Donante : public DonanteInterfaz
	{
		//! \name Atributos privados de la clase Donante
		private:
			char _nombre[30];
			char _apellidos[30];
			char _grSang[5];
			char _rh[10];

		//! \name Funciones o métodos públicos de la clase Donante
		public:

			//! \name Constructores de la clase Donante
			/*! 
				\brief Constructor que crea un Donante a partir de su nombre, apellidos, grupo sanguineo y factor rh
				\attention Función sobrecargada        
			 	\note Los parámetros tienen valores por defecto
				\param nombre de tipo char
				\param apellidos de tipo char
				\param grSang de tipo char
				\param rh de tipo char
				\pre Ninguna
				\post Ninguna
				\sa setNombre(), setApellidos(), setGrSang(), setRH()
			*/
			Donante(const char * nombre="n", const char * apellidos="a", const char * grSang="gr", const char * rh="rh")
			{
				setNombre(nombre);
				setApellidos(apellidos);
				setGrSang(grSang);
				setRH(rh);
			}


			/*! 
				\brief Constructor de "copia" que crea un Donante a partir de otro Donante
				\attention Función sobrecargada        
				\param d de tipo Donante pasado como referencia constante
				\pre El Donante d debe existir
				\post Ninguna
			*/
			Donante(const Donante &d)
			{
				*this=d;
			}


			//! \name Funciones de consulta de Donante

			/*! 
				\brief Devuelve el "nombre" de un Donante
				\return componente "nombre" de un Donante (tipo char*)
				\pre El Donante debe existir
				\post Ninguna
			*/
			char * getNombre() const
			{
				return (char*)_nombre;
			}


			/*! 
				\brief Devuelve los "apellidos" de un Donante
				\return componente "apellidos" de un Donante (tipo char*)
				\pre El Donante debe existir
				\post Ninguna
			*/
			char * getApellidos() const
			{
				return (char*)_apellidos;
			}


			/*! 
				\brief Devuelve el "grupo sanguineo" de un Donante
				\return componente "grSang" de un Donante (tipo char*)
				\pre El Donante debe existir
				\post Ninguna
			*/
			char * getGrSang() const
			{
				return (char*)_grSang;
			}


			/*! 
				\brief Devuelve el "RH" de un Donante
				\return componente "rh" de un Donante (tipo char*)
				\pre El Donante debe existir
				\post Ninguna
			*/
			char * getRH() const
			{
				return (char*)_rh;
			}


			//! \name Funciones de modificación de Donante

			/*! 
				\brief Asigna un valor "nombre" a la componente "nombre" de un Donante
				\param nombre de tipo char*
				\pre El Donante debe existir
				\post Ninguna
			*/	
			void setNombre(const char * nombre)
			{
				strcpy(_nombre, nombre);
			}


			/*! 
				\brief Asigna un valor "apellidos" a la componente "apellidos" de un Donante
				\param apellidos de tipo char*
				\pre El Donante debe existir
				\post Ninguna
			*/	
			void setApellidos(const char * apellidos)
			{
				strcpy(_apellidos, apellidos);
			}


			/*! 
				\brief Asigna un valor "grSang" a la componente "grSang" de un Donante
				\param grSang de tipo char*
				\pre El Donante debe existir
				\post Ninguna
			*/	
			void setGrSang(const char * grSang)
			{
				strcpy(_grSang, grSang);
			}


			/*! 
				\brief Asigna un valor "rh" a la componente "rh" de un Donante
				\param rh de tipo char*
				\pre El Donante debe existir
				\post Ninguna
			*/	
			void setRH(const char * rh)
			{
				strcpy(_rh, rh);
			}


			//! \name Operadores
   
			/*! 
				\brief Operador que "copia" un Donante en otro Donante
				\attention Se sobrecarga el operador de asignación "="
				\param d de tipo Donante pasado como referencia constante
				\pre El Donante d debe existir
				\post Ninguna
				\sa getNombre(), getApellidos(), getGrSang(), getRH(), setNombre(), setApellidos(), setGrSang(), setRH()
			*/
			Donante & operator = (const Donante & d)
			{
				if (this != &d)
				{
					setNombre(d.getNombre());
					setApellidos(d.getApellidos());
					setGrSang(d.getGrSang());
					setRH(d.getRH());
				}
				return *this;
			}


			/*! 
				\brief Operador que compara dos Donantes por apellidos y nombre
				\attention Se sobrecarga el operador "=="
				\param d de tipo Donante pasado como referencia constante
				\pre El Donante d debe existir
				\post Ninguna
				\sa getNombre(), getApellidos()
			*/
			bool operator == (const Donante & d) const
			{
				return strcmp(getApellidos(), d.getApellidos()) == 0 and strcmp(getNombre(), d.getNombre()) == 0;
			}


			/*! 
				\brief Operador que compara dos Donantes por apellidos y nombre
				\attention Se sobrecarga el operador "<="
				\param d de tipo Donante pasado como referencia constante
				\pre El Donante d debe existir
				\post Ninguna
				\sa getApellidos(), getNombre()
			*/
			bool operator <= (const Donante & d) const
			{
				char cad[30];
				char cad2[30];

				strcpy(cad, getApellidos());
				strcpy(cad2, d.getApellidos());

				if (strcmp(cad, cad2)<0)
				{
					return true;
				}

				if (strcmp(cad, cad2)>0)
				{
					return false;
				}

				if (strcmp(cad, cad2)==0)
				{
					if (strcmp(getNombre(), d.getNombre())<0)
					{
						return true;
					}

					if (strcmp(getNombre(), d.getNombre())>0)
					{
						return false;
					}

					if (strcmp(getNombre(), d.getNombre())==0)
					{
						BORRAR;
						LUGAR(10, 10);
						cout << "Los donantes son iguales";
						LUGAR(23,25);
						cout <<"pulse ";
						SUBRAYADO;
						cout <<"ENTER";
						APAGA;
						cout <<" para ";
						INVERSO;
						cout <<"continuar"; 
						APAGA;
						getchar();
					}
				}

				return 0;
			}


			/*! 
				\brief Operador que muestra por pantalla un Donante
				\attention Se sobrecarga el operador "<<"
				\param d de tipo Donante pasado como referencia constante
				\param stream de tipo ostream
				\return Variable stream de salida
				\pre El Donante d debe existir
				\post Ninguna
			*/
			friend ostream & operator << (ostream &stream, Donante const &d)
			{
				stream << "Nombre: " << d.getNombre() << "\n" << "Apellidos: " << d.getApellidos() << "\n" << "Grupo sanguineo: " << d.getGrSang() << "\n" << "Factor RH: " << d.getRH() << "\n" << endl;
				return stream;
			}


			/*! 
				\brief Operador que pide por pantalla un Donante
				\attention Se sobrecarga el operador ">>"
				\param d de tipo Donante pasado como referencia constante
				\param stream de tipo istream
				\return Variable stream de entrada
				\pre El Donante d debe existir
				\post Ninguna
			*/
			friend istream & operator >> (istream &stream, Donante &d)
			{
				char aux[30];
				
				//Pedimos el nombre
				cout << "\nIntroduzca el nombre: ";
				getchar();
				stream.getline(aux, 30);
				d.setNombre(aux);
				cout << endl;
				
				//Pedimos los apellidos
				cout << "Introduzca los apellidos: ";
			  	stream.getline(aux, 30);
			  	d.setApellidos(aux);
			  	cout << endl;
				
				//Pedimos el grupo sanguineo
				do
				{
					cout << "Introduzca el grupo sanguineo: ";
					stream >> aux;
					cout << endl;

					//El grupo sanguineo tiene que ser "A", "B", "AB" o "0"
					if(strcmp(aux, "A") != 0 && strcmp(aux, "B") != 0 && strcmp(aux, "AB") != 0 && strcmp(aux, "0") != 0)
					{
						cout << ">>>ERROR. Grupo sanguineo no valido...\n" << endl;
					}
					else
					{
						d.setGrSang(aux);
					}
				}while(strcmp(aux, "A") != 0 && strcmp(aux, "B") != 0 && strcmp(aux, "AB") != 0 && strcmp(aux, "0") != 0);

				//Pedimos el factor RH
				do
				{
					cout << "Introduzca el factor RH: ";
					stream >> aux;
					cout << endl;

					//El factor RH puede ser "+", "positivo" o "-", "negativo"
					if(strcmp(aux, "+") !=0 && strcmp(aux, "positivo") != 0 && strcmp(aux, "-") != 0 && strcmp(aux, "negativo") != 0)
					{
						cout << ">>>ERROR. RH no valido...\n" << endl;
					}
					else
					{
						d.setRH(aux);
					}
				}while(strcmp(aux, "+") !=0 && strcmp(aux, "positivo") != 0 && strcmp(aux, "-") != 0 && strcmp(aux, "negativo") != 0);

				return stream;
			}



			//! \name Funciones lectura y escritura de la clase Donante

			/*! 
				\brief Asigna a un Donante las variables "nombre", "Apellidos", "grSang" y "rh" leídas desde el teclado
				\pre El Donante debe existir
				\post Ninguna
				\warning Se deben teclear palabras
				\sa setNombre(), setApellidos(), setGrSang(), setRH()
			*/
			void leerDonante()
			{
				//Declaracion de variables
				char nombre[30];
				char apellidos[30];
				char grSang[5];
				char rh[10];

				do
				{
					//Pedimos el nombre
					BORRAR;
					LUGAR(5, 10);
					cout << "Introduzca el nombre: ";
					getchar();
					cin.getline(nombre, 30);
					setNombre(nombre);

					//Pedimos los apellidos
					LUGAR(7,10);
					cout << "Introduzca los apellidos: ";
					cin.getline(apellidos, 30);
					setApellidos(apellidos);

					//Pedimos el grupo sanguineo, que tiene que ser "A", "B", "AB" o "0"
					do
					{
						LUGAR(9,10);
						cout << "Introduzca el grupo sanguineo: ";
						cin >> grSang;
						if(strcmp(grSang, "A") != 0 && strcmp(grSang, "B") != 0 && strcmp(grSang, "AB") != 0 && strcmp(grSang, "0") != 0)
						{
							BORRAR;
							LUGAR(10, 10);
							cout << ">>>ERROR. Grupo sanguineo no valido...\n" << endl;
						}
						else
						{
							setGrSang(grSang);
						}
					}while(strcmp(grSang, "A") != 0 && strcmp(grSang, "B") != 0 && strcmp(grSang, "AB") != 0 && strcmp(grSang, "0") != 0);

					//Pedimos el RH que tiene que ser "+", "positivo" o "-", "negativo"
					do
					{
						LUGAR(11,10);
						cout << "Introduzca el RH: ";
						cin >> rh;
						if(strcmp(rh, "+") !=0 && strcmp(rh, "positivo") != 0 && strcmp(rh, "-") != 0 && strcmp(rh, "negativo") != 0)
						{
							BORRAR;
							LUGAR(10,10);
							cout << ">>>ERROR. RH no valido...\n" << endl;
						}
						else
						{
							setRH(rh);
						}
					}while(strcmp(rh, "+") !=0 && strcmp(rh, "positivo") != 0 && strcmp(rh, "-") != 0 && strcmp(rh, "negativo") != 0);

				}while(getchar()!='\n');

			}


			/*! 
				\brief Escribe por pantalla las componentes nombre, apellidos, grupo sanguineo y rh de un Donante
				\pre El Donante debe tener valores asignados a sus componentes
				\post Ninguna
				\sa getNombre(), getApellidos(), getGrSang(), getRH()
			*/
			void escribirDonante()
			{
				BORRAR;
				LUGAR(5,10);
				cout << "Nombre: " << getNombre();
				LUGAR(7,10);
				cout << "Apellidos: " << getApellidos();
				LUGAR(9,10);
				cout << "Grupo sanguineo: " << getGrSang();
				LUGAR(11,10);
				cout << "RH: " << getRH();

				LUGAR(23,25);
				cout <<"pulse ";
				SUBRAYADO;
				cout <<"ENTER";
				APAGA;
				cout <<" para ";
				INVERSO;
				cout <<"continuar"; 
				APAGA;
				getchar();
				getchar();		
			}
	}; // Fin de la definicion de la clase Donante

}// \brief Fin de namespace ed


// DONANTE_HPP
#endif

















