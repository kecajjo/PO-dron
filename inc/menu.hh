#ifndef MENU_HH
#define MENU_HH

/*!
 * \file
 * \brief tworzy menu
 * 
 *  Plik zawiera funkcje zwiazane z menu
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include "obiekt_sceny.hh"
#include "Wektor3D.hh"
#include "Macierz3x3.hh"
#include "Prostopadloscian.hh"
#include "lacze_do_gnuplota.hh"
#include "bryla.hh"
#include "wirnik.hh"
#include "dron.hh"
#include "scena.hh"
#include "fabryka.hh"

/*!
 * \brief funkcja jedynie wyswietla menu
 */
void wyswietl_menu();

/*!
 * \brief Funkcja tworzy menu
 * 
 * Funkcja tworzy menu pozwalajace na wybor roznych opcji w programie.
 * Argumenty:
 *    &dr - adres zmiennej typu dron w pamieci
 * Zwraca:
 *    funkcja nie zwraca wartosci.
 */
void menu(singleton &fabryka);

/*!
 * \brief ustawia opcje do Gnuplota
 * 
 * Realizuje wyswietlanie Prostopadlosciana gnuplotem
 * Argumenty:
 *    &Lacze - lacze do programu gnuplot, ktorego opcje ustawiamy
 * Zwraca:
 *    funkcja nie zwraca wartosci
 */
void ustaw_opcje_gnuplota(PzG::LaczeDoGNUPlota &Lacze, unsigned int liczba_plikow);

/*!
 * \brief tworzy pliki z danymi do wyswietlenia przez gnuplota
 * 
 * tworzy pliki ktore bedzie wyswietlal gnuplot
 * Argumenty:
 *    &moja_scena - referencja do sceny w ktorej rysujemy drony i przeszkody
 * Zwraca:
 *    zwraca utworzona liczbe plikow
 */
unsigned int uzupelnij_pliki(scena &moja_scena);


#endif