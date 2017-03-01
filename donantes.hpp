/*! 
  \file donantes.hpp
  \brief Donantes crea una lista con varios donantes
  \author Miguel Angel Gavilan Merino
  \date 13/04/2016
*/


#ifndef DONANTES_HPP
#define DONANTES_HPP


// Ficheros de cabecera
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <list>
#include "donante.hpp"
#include "donantesInterfaz.hpp"
#include "macros.hpp"


// Facilita la entrada y salida
using std::list;
using std::cout;
using std::cin;
using std::endl;
using std::istream;
using std::ostream;



/*!
   \brief Estructura Nodo para usar una lista doblemente enlazada

*/
struct Nodo{
	/*!
	   \brief d de tipo Donante

	*/
	ed::Donante d;

	/*!
	   \brief Apuntador al nodo siguiente

	*/
	struct Nodo * sig;

	/*!
	   \brief Apuntador al nodo anterior

	*/
	struct Nodo * ant;

	/*!
	   \brief Funcion para poner delante un nodo pasado por referencia
	   \param a de tipo Nodo*

	*/
	void ponerAdelante(Nodo* a) 
	{ 
		sig = a;
	}

	/*!
	   \brief Funcuon para poner detras un nodo pasado por referencia
	   \param a de tipo Nodo*

	*/
	void ponerAtras(Nodo* a) 
	{ 
		ant = a; 
	}
};





namespace ed
{
	/*!
	   \brief Clase Donantes

	*/
	class Donantes : public DonantesInterfaz
	{
		//! \name Atributos privados de la clase Donantes
		private:
			Nodo * _lista;

		//! \name Funciones o métodos públicos de la clase Donantes
		public:
			//! \name Constructores de la clase Donantes
			/*! 
				\brief Constructor que inicializa una lista a NULL
				\attention Función sobrecargada        
			 	\note Los parámetros tienen valores por defecto
				\param lista de tipo Nodo*
			
			*/
			Donantes(Nodo * lista=NULL)
			{
				_lista = lista;
			}


			//! \name Funciones de la clase Donantes

			/*! 
				\brief Funcion booleana que dice si un nodo es el ultimo
				\param pos de tipo int
				\pre ninguna
				\post Ninguna
				\sa numElementos()
			*/

			bool esUltimo(int pos) const
			{
				if (pos==numElementos())
				{
					return true;
				}
				else
				{
					return false;
				}
			}


			/*! 
				\brief Funcion que devuelve el numero de elementos de una lista
				\pre La lista deve existir
				\post Ninguna
			*/

			int numElementos() const
			{
				int cont=0;
				Nodo * aux;
				aux=_lista;
				
				while(aux!=NULL)
				{
					cont ++;
					aux=aux->sig;
				}
				return cont;
			}


			/*! 
				\brief Funcion booleana que dice si una lista esta vacia
				\pre ninguna
				\post Ninguna
			*/

			bool estaVacia() const
			{
				if(_lista!=NULL)
				{
					return true;
				}
				else
				{
					return false;
				}
			}


			/*! 
				\brief Funcion booleana que dice si una posicion es valida
				\param pos de tipo int
				\pre ninguna
				\post Ninguna
				\sa numElementos()
			*/

			bool esValida(int pos) const
			{
				if(pos>0 && pos<=numElementos())
				{
					return true;
				}
				else
				{
					return false;
				}
			}


			/*! 
				\brief Funcion de tipo Donante que devuelve un donante
				\param pos de tipo int
				\pre la lista deve existir
				\post Ninguna
				\sa esValida()
			*/

			Donante item(int pos) const
			{
				Nodo * aux;

				if(esValida(pos))
				{
					aux=_lista;
					int cont=0;

					while(aux!=NULL)
					{
						cont ++;
						if(cont==pos)
						{
							return aux->d;
						}
						aux=aux->sig;
					} 
				}
			}


			/*! 
				\brief Funcion que busca un donante en la lista
				\param nombre de tipo char, pasado como constante
				\param apellidos de tipo char, pasado como constante
				\pre La lista debe existir
				\post Ninguna
				\return Posicion del donante en la lista
				\sa setNombre(), setApellidos()
			*/

			int buscaItem(const char nombre[30], const char apellidos[30]) const
			{
				Donante d, d2;

				d.setNombre(nombre);
				d.setApellidos(apellidos);
				int cont=0;
				Nodo * aux=_lista;
				
				while(aux!=NULL)
				{
					cont ++;
					d2=item(cont);
					if(d2 == d)
					{
						return cont;
					}
					aux=aux->sig;
				}

				return -1;
			}


			/*! 
				\brief Funcion que inserta un donante en la lista
				\param item de tipo Donante, pasado como constante
				\pre La lista debe existir
				\post Ninguna
				\sa estaVacia()
			*/

			void inserta(const Donante & item)
			{
				Nodo * nuevo;
				nuevo=new Nodo;
				nuevo->d=item;
				
				if (estaVacia()==0)
				{
					nuevo->sig=NULL;
					nuevo->ant=NULL;
					_lista=nuevo;
				}
				else if (item <= _lista->d)
				{
					nuevo->ant=NULL;
					nuevo->sig=_lista;
					_lista->ant=nuevo;
					_lista=nuevo;
				}
				else
				{
					Nodo * aux=_lista;
					Nodo * ant;
					
					while(aux!=NULL){

						if(item <= aux->d){
							break;
						}

						ant=aux;
						aux=aux->sig;

					}

					ant->sig=nuevo;

					if (aux!=NULL){
						aux->ant=nuevo;
					}

					nuevo->ant=ant;
					nuevo->sig=aux;
				}
			}



			/*! 
				\brief Funcion que elimina un Donante de la lista
				\param d de tipo Donante
				\pre La lista debe existir
				\post Ninguna
				\sa ponerAdelante(), ponerAtras()
			*/

			void eliminar (Donante d)
			{
				Nodo* actual;
				bool encontrado = false;
				actual = _lista;
				// Bucle de búsqueda
				while ((actual != NULL) && (!encontrado))
				{
					encontrado = (actual -> d == d);
					if (!encontrado)
					{
					
						actual = actual -> sig;
					}
				}
				// Enlace de nodo anterior con el siguiente
				if (actual != NULL)
				{
					//distingue entre nodo cabecera o resto de la lista
					if (actual == _lista)
					{
						_lista = actual -> sig;
						if (actual -> sig != NULL)
						{
							actual -> sig -> ponerAtras(NULL);
						}
					}
					else if (actual -> sig != NULL) // No es el último
					{
						actual->ant->ponerAdelante(actual->sig);
						actual->sig->ponerAtras(actual->ant);
					}
					else
						// último nodo
						actual->ant->ponerAdelante(NULL);
				}
			}

			
			//! \name Funciones lectura y escritura de la clase Donantes

			/*! 
				\brief Lee un donante por pantalla y lo inserta en la lista
				\pre Ninguna
				\post Ninguna
				\warning Se deben teclear palabras
				\sa leerDonante(), inserta()
			*/

			void leerDonantes()
			{
				Donante d;

				d.leerDonante();
				inserta(d);
			}


			/*! 
				\brief Escribe por pantalla la lista de donantes
				\pre La lista debe existir
				\post Ninguna
				\sa numElementos(), item()
			*/
			void escribirDonantes(const Donantes &lista)
			{
				Donante d;
				int i;

				for(i=1; i<=numElementos(); i++){
					d=lista.item(i);
					cout << d <<endl;
					cout << endl;
				}
			}


	}; // Fin de la definicion de la clase Donante
}// \brief Fin de namespace ed


// DONANTES_HPP
#endif
