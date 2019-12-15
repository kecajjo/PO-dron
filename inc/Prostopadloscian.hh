#ifndef PROSTOPADLOSCIAN_HH
#define PROSTOPADLOSCIAN_HH

/*!
 * \file
 * \brief definicja klasy Prostopadloscian
 * 
 *  Plik zawiera definicje klasy Prostopadloscian
 */

#include <iostream>
#include <cmath>
#include "Wektor.hh"
#include "Macierz.hh"
#include "Macierz3x3.hh"
#include "Wektor3D.hh"
#include "bryla.hh"

#define FIGURA 8
#define WYMIAR 3
#define PROSTOPAD 8
#define DL_X 20
#define DL_Y 20
#define DL_Z 10
/*!
 * \brief klasa tworzy prostopadloscian jako klase pochodna obiektu geometrycznego
 * 
 *  klasa modeluje prostopadloscian jako klase dziedziczaca po obiekcie geometrycznym
 *  modeluje operacje stworzenia prostopadloscianu, znalezienia srodka prostopadloscianu i kata o jaki jest on obrocony, 
 */
class Prostopadloscian:public obiekt_geometryczny {
  


  public:


/*!
 * \brief tworzy prostopadloscian
 * 
 * tworzy prostopadloscian korzystajac z dynamicznej tablicy vector
 * Argumenty:
 *    srodek - srodek tworzonego prostopadloscianu
 */
void stworz_prostopadloscian_o_srodku(Wektor3D srodek);


/*!
 * \brief tworzy prostopadloscian
 * 
 * tworzy prostopadloscian korzystajac z dynamicznej tablicy vector
 * Argumenty:
 *    srodek - srodek tworzonego prostopadloscianu
 *    dlugosc_x - dlugosc tworzonego prostopadloscianu
 *    dlugosc_y - szerokosc tworzonego prostopadloscianu
 *    dlugosc_z 0 wysokosc tworzonego prostopadloscianu
 */
void stworz_prostopadloscian_o_srodku(
            Wektor3D srodek, double dlugosc_x, double dlugosc_y, double dlugosc_z);

/*!
 * \brief wylicza srodek prostopadloscianu
 * 
 * Realizuje wyliczenie srodka prostopadloscianu.
 * Zwraca:
 *    punkt bedacy srodkiem prostopadloscianu.
 */
Wektor3D znajdz_srodek();

//
// gdyby kiedys takie rozwiazanie sie przydalo wylicza kat o jaki jest obrocony prostopadloscian
// 
// Realizuje wyliczenie kata o jaki jest obrocony prostopadloscian.
// Zwraca:
//    kat o jaki jest obrocony prostopadloscian.
//
//double znajdz_kat_patrzenia();
};


/*!
 * \brief wyswietla Prostopadloscian
 * 
 * Realizuje wyswietlanie Prostopadlosciana.
 * Argumenty:
 *    Strm - strumien wyjsciowy ostream&,
 *    Pr - Prostopadloscian do wyswietlenia.
 * Zwraca:
 *    Strumien wyjsciowy wyswietlajacy Prostopadloscian.
 */
std::ostream& operator << ( std::ostream       &Strm, 
                            const Prostopadloscian    &Pr
                          );


#endif
