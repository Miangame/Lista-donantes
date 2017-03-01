/*! 
  \file mainDonante.cpp
  \brief Programa para usar el tipo de dato Donante
*/


 /*!
	\mainpage Plantillas de clases y funciones
	\author Miguel Angel Gavilan Merino
	\date 13/04/2016
*/



//Ficheros de cabecera
#include <iostream>
#include <cassert>
#include <cstdlib>
#include <unistd.h>
#include "donante.hpp"
#include "funcionesDonante.hpp"
#include "macros.hpp"


// Uso del espacio de nombres ed
using namespace ed;

// Facilita la entrada y salida
using std::cout;
using std::endl;
using std::cin;



//! Programa principial que muestra el uso de la clase Donante
int main()
{
	BORRAR;

	// Declaracion de 3 donantes
	Donante d, d2("n", "a", "gr", "rh"), d3(d2);

	// Comprobacion del constructor
	if(strcmp(d.getNombre(), "n")==0 && strcmp(d.getApellidos(), "a")==0 && strcmp(d.getGrSang(), "gr")==0 && strcmp(d.getRH(), "rh")==0 )
	{
		cout << "\n>>>Constructor funciona correctamente...\n" << endl;
	}

	// Comprobacion del constructor con valores por defecto
	if(strcmp(d2.getNombre(), "n")==0 && strcmp(d2.getApellidos(), "a")==0 && strcmp(d2.getGrSang(), "gr")==0 && strcmp(d2.getRH(), "rh")==0 )
	{
		cout << "\n>>>Constructor con valores por defecto funciona correctamente...\n" << endl;
	}

	// Comprobacion del constructor de copia
	if(strcmp(d2.getNombre(), d3.getNombre())==0 && strcmp(d2.getApellidos(), d3.getApellidos())==0 && strcmp(d2.getGrSang(), d3.getGrSang())==0 && strcmp(d2.getRH(), d3.getRH())==0 )
	{
		cout << "\n>>>Constructor de copia funciona correctamente...\n" << endl;
	}

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


	//Llamada a la funcion menu()
	menu(d, d2);

	// Fin del programa
	return 0;
}