/*! 
  \file donanteInterfaz.hpp
  \brief DonanteInterfaz declara de manera publica las funciones virtuales de la clase Donante
  \author Miguel Angel Gavilan Merino
  \date 
*/


#ifndef DONANTEINTERFAZ_HPP
#define DONANTEINTERFAZ_HPP


// Ficheros de cabecera
#include <iostream>



namespace ed
{
	/*!
	   \brief Clase DonanteInterfaz

	*/
	class DonanteInterfaz
	{
		//! \name Funciones publicas virtuales de la clase DonanteInterfaz
		public:
			virtual char * getNombre() const = 0;

			virtual char * getApellidos() const = 0;

			virtual char * getGrSang() const = 0;

			virtual char * getRH() const = 0;

			virtual void setNombre(const char * nombre) = 0;

			virtual void setApellidos(const char * apellidos) = 0;

			virtual void setGrSang(const char * grSang) = 0;

			virtual void setRH(const char * rh) = 0;
	}; // Fin de la definicion de la clase DonanteInterfaz
} // \brief Fin de namespace ed


// DONANTEINTERFAZ_HPP
#endif