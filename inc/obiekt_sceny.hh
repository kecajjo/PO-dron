#ifndef OBIEKT_SCENY_HH
#define OBIEKT_SCENY_HH

#include <iostream>
#include <iomanip>
#include <fstream>
#include <unistd.h>
#include <memory>
#include "Wektor.hh"
#include "Macierz.hh"
#include "Macierz3x3.hh"
#include "Wektor3D.hh"
#include "bryla.hh"
#include "Prostopadloscian.hh"
#include "lacze_do_gnuplota.hh"

class obiekt_sceny{

    protected:
        char rodzaj_obiektu;
        static unsigned int utworzonych_obiektow;
        static unsigned int aktualnych_obiektow;

    public:
 /*!
 * \brief pobiera znak oznaczajacy drona lub przeszkode
 */
 char get_rodzaj_obiektu() const {return rodzaj_obiektu;}

 /*!
 * \brief pobiera ilosc utworzonych obiektow
 */
 static unsigned int get_utworzonych_obiektow();

 /*!
 * \brief pobiera ilosc aktualnych obiektow
 */
 static unsigned int get_aktualnych_obiektow();

 /*!
 * \brief zapisuje wspolrzedne do pliku
 * 
 * funkcja odpowiada za zapis wspolrzednych do pliku
 * argumenty:
 *      sNazwaPliku - nazwa pliku do ktorego zapisujemy
 * zwraca:
 *      false jesli nie udalo sie nic zapisac lub true jesli sie udalo
 */
 virtual bool ZapisWspolrzednychDoPliku(std::string sNazwaPliku){return false;}
        

};



#endif