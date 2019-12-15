#ifndef DRON_HH
#define DRON_HH

/*!
 * \file
 * \brief definicja klasy dron
 * 
 *  Plik zawiera definicje klasy dron
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <unistd.h>
#include "Wektor.hh"
#include "Macierz.hh"
#include "Macierz3x3.hh"
#include "Wektor3D.hh"
#include "bryla.hh"
#include "wirnik.hh"
#include "Prostopadloscian.hh"
#include "lacze_do_gnuplota.hh"
#include "obiekt_sceny.hh"

#define ILOSC_SMIGIEL 4
#define Z_SMIGLA 4
#define KAT_OBROTU_WIRNIKOW 1800
#define PROMIEN_DRONA 22.143

/*!
 * \brief klasa dron jako zmienna typu Prostopadloscian i tablice zmiennych typu gran_szesc
 * 
 *  klasa modeluje dron jako zmienna typu Prostopadloscian i tablice zmiennych typu gran_szesc
 * zawiera statyczne pole pamietajace o ile stopni byl odwrocony dron (statyczne gdyz przy animacji tworzymy drona 
 * ktory bedzie wyswietlany a bedzie ruszonym dronem pierwotnym w celu minimalizacji bledow obliczen)
 */
class dron: public obiekt_sceny{

double obrocony_o_stopni;
Prostopadloscian korpus;
gran_szesc smigla[ILOSC_SMIGIEL];


/*!
 * \brief zapisuje wspolrzedne prostopadloscianu do stumienia
 * 
 * Przyklad zapisu wspolrzednych zbioru punktow do strumienia wyjściowego.
 * Dane sa odpowiednio sformatowane, tzn. przyjęto notację stałoprzecinkową
 * z dokładnością do 10 miejsca po przecinku. Szerokość wyświetlanego pola 
 * to 16 miejsc, sposób wyrównywania - do prawej strony.
 * \param[in] StrmWy - strumien wyjsciowy, do ktorego maja zostac zapisane
 *                     kolejne wspolrzedne.
 * \param[in] Pr - Prostopadloscian ktory zapisujemy
 * \retval true - gdy operacja zapisu powiodła się,
 * \retval false - w przypadku przeciwnym.
 */
void ZapisWspolrzednychDoStrumienia(std::ostream &StrmWy);


public:


double get_obrocony_o_stopni()const {return obrocony_o_stopni;}

/*!
 * \brief zapisuje wspolrzedne Prostopadloscianu do pliku
 * 
 * Przyklad zapisu wspolrzednych zbioru punktow do pliku, z ktorego
 * dane odczyta program gnuplot i narysuje je w swoim oknie graficznym.
 * \param[in] sNazwaPliku - nazwa pliku, do którego zostana zapisane
 *                          wspolrzędne punktów.
 * \param[in] Przesuniecie - ten parameter jest tylko po to, aby pokazać
 *                          mozliwosc zmiany wspolrzednych i Prostopadlosciana
 *                          i zmiane jego polozenia na okienku graficznym
 *                         rysownym przez gnuplota.
 * \retval true - gdy operacja zapisu powiodła się,
 * \retval false - w przypadku przeciwnym.
 */
bool ZapisWspolrzednychDoPliku(std::string sNazwaPliku);

 /*!
 * \brief pozwala na wyswietlenie korpusu
 */
 Prostopadloscian get_korpus () const {return korpus;}
 
 /*!
 * \brief pozwala na wyswietlenie wirnikow
 */
 gran_szesc get_smigla (unsigned int const indeks) const {if(indeks>=ILOSC_SMIGIEL) exit(1); return smigla[indeks];}
 
 /*!
 * \brief pozwala na modyfikowanie wirnikow
 */
 gran_szesc &set_smigla (unsigned int const indeks) {if(indeks>=ILOSC_SMIGIEL) exit(1); return smigla[indeks];}

 /*!
 * \brief konstruktor tworzacy dron o srodku w poczatku ukladu wspolrzednych
 */
 dron();

 /*!
 * \brief konstruktor tworzacy dron o srodku korpusu w zadanym punkcie
 */
 dron(Wektor3D srodek);

 /*!
 * \brief obraca dron
 * 
 * funkcja obraca dron wokol wlasnej osi z
 * argumenty:
 *      kat_obrotu_w_st - kat o jaki chcemy obrocic dron podany w stopniach
 */
void obroc_drona(double kat_obrotu_w_st);

 /*!
 * \brief przemieszcza dron
 * 
 * funkcja przemieszcza dron o zadana dlugosc z zadanym katem wznoszenia/opadania
 * argumenty:
 *      dlugosc_lotu - odleglosc jaka pokona dron
 *      kat_wznoszenia_w_st - kat pod jakim chcemy zeby dron sie wzniosl/opadl
 */
void rusz_drona(double dlugosc_lotu, double kat_wznoszenia_w_st);

 /*!
 * \brief usuwa dron
 * 
 * funkcja zwalnia pamiec zajeta przez obiekt typu dron
 */
void usun_drona();

 /*!
 * \brief destruktor do podliczania aktualnych obiektow
 */
~dron(){aktualnych_obiektow--;}

 /*!
 * \brief konstruktor kopiujacy do podliczania aktualnych i utworzonych obiektow
 */
dron(const dron &kopiowany);

 /*!
 * \brief animuje obrot drona
 * 
 * odpowiada za animacje obrotu drona za pomoca gnuplota
 * argumenty:
 *      lacze - lacze do programu Gnuplot
 */
//void animuj_obrot_drona(PzG::LaczeDoGNUPlota lacze, unsigned int ktory_plik_modyfikowac);

 /*!
 * \brief animuje lot drona
 * 
 * odpowiada za animacje lotu drona za pomoca gnuplota
 * argumenty:
 *      lacze - lacze do programu Gnuplot
 */
//void animuj_lot_drona(PzG::LaczeDoGNUPlota lacze, unsigned int ktory_plik_modyfikowac);


};

/*!
 * \brief wyswietla drona
 * 
 * Realizuje wyswietlanie drona.
 * Argumenty:
 *    Strm - strumien wyjsciowy ostream&,
 *    dr - dronc do wyswietlenia.
 * Zwraca:
 *    Strumien wyjsciowy wyswietlajacy drona.
 */
std::ostream& operator << ( std::ostream       &Strm, 
                            const dron    &dr
                          );

#endif
