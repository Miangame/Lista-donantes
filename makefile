All: mainDonante.x mainDonantes.x clean
	
mainDonante.x: mainDonante.o
	g++ mainDonante.o -o mainDonante.x 

mainDonantes.x: mainDonantes.o
	g++ mainDonantes.o -o mainDonantes.x

mainDonante.o: mainDonante.cpp donante.hpp donanteInterfaz.hpp funcionesDonante.hpp
	g++ -c mainDonante.cpp

mainDonantes.o: mainDonantes.cpp donantes.hpp donantesInterfaz.hpp funcionesDonantes.hpp
	g++ -c mainDonantes.cpp

clean:
	rm *.o
