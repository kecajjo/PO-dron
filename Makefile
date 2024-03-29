#
#  To sa opcje dla kompilacji
#
CXXFLAGS=-g -Iinc -Wall -pedantic -std=c++0x

__start__: obroty_3D
	./obroty_3D

obroty_3D: obj obj/main.o obj/Prostopadloscian.o obj/Macierz3x3.o obj/Wektor3D.o\
           obj/lacze_do_gnuplota.o obj/menu.o obj/bryla.o obj/wirnik.o obj/dron.o\
		   obj/obiekt_sceny.o obj/scena.o obj/przeszkoda.o obj/fabryka.o
	g++ -Wall -pedantic -std=c++0x -o obroty_3D obj/main.o obj/Wektor3D.o\
                    	obj/Macierz3x3.o obj/Prostopadloscian.o obj/lacze_do_gnuplota.o\
						obj/menu.o obj/bryla.o obj/wirnik.o obj/dron.o\
						obj/obiekt_sceny.o obj/scena.o obj/przeszkoda.o obj/fabryka.o

obj:
	mkdir obj

obj/lacze_do_gnuplota.o: inc/lacze_do_gnuplota.hh src/lacze_do_gnuplota.cpp
	g++ -c ${CXXFLAGS} -o obj/lacze_do_gnuplota.o src/lacze_do_gnuplota.cpp

obj/main.o: src/main.cpp inc/Prostopadloscian.hh inc/Macierz3x3.hh inc/Macierz.hh\
           inc/Wektor3D.hh inc/Wektor.hh
	g++ -c ${CXXFLAGS} -o obj/main.o src/main.cpp

obj/Prostopadloscian.o: src/Prostopadloscian.cpp inc/Prostopadloscian.hh\
         inc/Wektor3D.hh inc/Wektor.hh inc/bryla.hh
	g++ -c ${CXXFLAGS} -o obj/Prostopadloscian.o src/Prostopadloscian.cpp

obj/Macierz3x3.o: src/Macierz3x3.cpp inc/Macierz3x3.hh inc/Macierz.hh inc/Wektor3D.hh inc/Wektor.hh
	g++ -c ${CXXFLAGS} -o obj/Macierz3x3.o src/Macierz3x3.cpp

obj/Wektor3D.o: src/Wektor3D.cpp inc/Wektor3D.hh inc/Wektor.hh
	g++ -c ${CXXFLAGS} -o obj/Wektor3D.o src/Wektor3D.cpp

obj/menu.o: src/menu.cpp inc/menu.hh inc/Prostopadloscian.hh inc/Macierz3x3.hh inc/Macierz.hh\
           inc/Wektor3D.hh inc/Wektor.hh inc/bryla.hh inc/obiekt_sceny.hh inc/fabryka.hh
	g++ -c ${CXXFLAGS} -o obj/menu.o src/menu.cpp

obj/bryla.o: src/bryla.cpp inc/Prostopadloscian.hh\
         inc/Wektor3D.hh inc/Wektor.hh inc/bryla.hh
	g++ -c ${CXXFLAGS} -o obj/bryla.o src/bryla.cpp

obj/wirnik.o: src/wirnik.cpp inc/wirnik.hh\
         inc/Wektor3D.hh inc/Wektor.hh inc/bryla.hh
	g++ -c ${CXXFLAGS} -o obj/wirnik.o src/wirnik.cpp

obj/dron.o: src/dron.cpp inc/dron.hh\
         inc/Wektor3D.hh inc/obiekt_sceny.hh inc/Wektor.hh inc/bryla.hh inc/Prostopadloscian.hh inc/wirnik.hh
	g++ -c ${CXXFLAGS} -o obj/dron.o src/dron.cpp

obj/przeszkoda.o: src/przeszkoda.cpp inc/przeszkoda.hh\
         inc/Wektor3D.hh inc/obiekt_sceny.hh inc/Wektor.hh inc/bryla.hh inc/Prostopadloscian.hh
	g++ -c ${CXXFLAGS} -o obj/przeszkoda.o src/przeszkoda.cpp

obj/obiekt_sceny.o: src/obiekt_sceny.cpp inc/obiekt_sceny.hh\
         inc/Wektor3D.hh inc/Wektor.hh inc/bryla.hh inc/Prostopadloscian.hh
	g++ -c ${CXXFLAGS} -o obj/obiekt_sceny.o src/obiekt_sceny.cpp

obj/scena.o: src/scena.cpp inc/scena.hh\
         inc/Wektor3D.hh inc/Wektor.hh inc/bryla.hh inc/Prostopadloscian.hh inc/obiekt_sceny.hh\
		 inc/przeszkoda.hh inc/dron.hh
	g++ -c ${CXXFLAGS} -o obj/scena.o src/scena.cpp

obj/fabryka.o: src/fabryka.cpp inc/fabryka.hh\
         inc/scena.hh
	g++ -c ${CXXFLAGS} -o obj/fabryka.o src/fabryka.cpp

clean:
	rm -f obj/*.o obroty_3D
