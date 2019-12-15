#ifndef gran_szesc_HH
#define gran_szesc_HH

/*!
 * \file
 * \brief definicja klasy gran_szesc
 * 
 *  Plik zawiera definicje klasy gran_szesc
 */

#include <iostream>
#include <cmath>
#include "Wektor.hh"
#include "Macierz.hh"
#include "Macierz3x3.hh"
#include "Wektor3D.hh"
#include "bryla.hh"



/*!
 * \brief klasa tworzy gran_szesc jako klase pochodna obiektu geometrycznego
 * 
 *  klasa modeluje gran_szesc jako klase dziedziczaca po obiekcie geometrycznym
 *  modeluje operacje stworzenia gran_szescu, znalezienia srodka gran_szescu i kata o jaki jest on obrocony, 
 */
class gran_szesc:public obiekt_geometryczny {
  


  public:


/*!
 * \brief tworzy gran_szesc
 * 
 * tworzy gran_szesc korzystajac z dynamicznej tablicy vector
 * Argumenty:
 *    srodek - srodek tworzonego gran_szescu
 */

void stworz_wirnik_o_srodku(Wektor3D srodek);

/*!
 * \brief wylicza srodek gran_szescu
 * 
 * Realizuje wyliczenie srodka gran_szescu.
 * Zwraca:
 *    punkt bedacy srodkiem gran_szescu.
 */
Wektor3D znajdz_srodek();

};


/*!
 * \brief wyswietla gran_szesc
 * 
 * Realizuje wyswietlanie gran_szesca.
 * Argumenty:
 *    Strm - strumien wyjsciowy ostream&,
 *    wirnik - gran_szesc do wyswietlenia.
 * Zwraca:
 *    Strumien wyjsciowy wyswietlajacy gran_szesc.
 */
std::ostream& operator << ( std::ostream       &Strm, 
                            const gran_szesc    &wirnik
                          );


#endif
