/*! 
  \file donantesInterfaz.hpp
  \brief DonantesInterfaz declara de manera publica las funciones virtuales de la clase Donantes
  \author Miguel Angel Gavilan Merino
  \date 
*/


#ifndef DONANTESINTERFAZ_HPP
#define DONANTESINTERFAZ_HPP


// Ficheros de cabecera
#include <iostream>


namespace ed
{
	/*!
	   \brief Clase DonantesInterfaz

	*/
	class DonantesInterfaz
	{
		//! \name Funciones publicas virtuales de la clase DonantesInterfaz
		public:
			virtual bool estaVacia() const = 0;

			virtual int buscaItem(const char nombre[30], const char apellidos[30]) const = 0;

			virtual void inserta(const Donante & item) = 0;

			virtual void eliminar (Donante d) = 0;
		
	}; // Fin de la definicion de la clase DonantesInterfaz
} // \brief Fin de namespace ed


// DONANTESINTERFAZ_HPP
#endif