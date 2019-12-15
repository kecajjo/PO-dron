#ifndef BRYLA_HH
#define BRYLA_HH

/*!
 * \file
 * \brief definicja klasy obiekt_geometryczny
 * 
 *  Plik zawiera definicje klasy obiekt geometryczny
 */

#include <iostream>
#include "Wektor.hh"
#include "Macierz.hh"
#include "Macierz3x3.hh"
#include "Wektor3D.hh"

#define FIGURA 8
#define WYMIAR 3

/*!
 * \brief klasa tworzy obiekt_geometrzyczny jako dynamiczna tablice Wektorow3D
 * 
 *  klasa modeluje obiekt geometryczny jako dynamiczna tablice korzystajaca z szablonu vector o typie zmiennej Wektor3D
 *  modeluje operacje przesuniecia i obrotu wokol wlasnej osi.
 */
class obiekt_geometryczny {

    /*!
     * \brief Wypelnia macierz obrotu funkcjami trygonometrycznymi
     * 
     * Realizuje wypelnienie macierzy obrotu funkcjami trygonometrycznymi z 
     * argumentem alfa
     * Argumenty:
     *    this - nie wykorzystujemy
     *    alfa - kat ktorego funkcje trygoometryczne liczymy (podany w stoniach)
     * Zwraca:
     *    macierz wypelniona wartosciami odpowiednich funkcji trygonometrycznych
     */
    Macierz3x3 uzupelnianie(double const alfa);
    
    /*!
    * \brief zamienia stopnie na radiany
    */
    double stopnie_na_radiany(double const alfa){double wynik; wynik=alfa*M_PI/180; return wynik;}
    
    protected:
    std::vector<Wektor3D> bryla;

    public:
    /*!
    * \brief Przeciazenie pozwala nam na pobieranie wartosci z tablicy wierzcholki[]
    */
    Wektor3D operator [] (int indeks) const {return bryla[indeks];}
    /*!
    * \brief Przeciazenie pozwala nam na modyfikacje wartosci z tablicy wierzcholki[]
    */
    Wektor3D& operator [] (int indeks) {return bryla[indeks];}

    /*!
     * \brief obraca obiekt wokol wlasnej osi
     * 
     * Realizuje obrot obiektu geometrycznego wokol wlasnej osi przechodzacej przez srodek podstawy (wzgledem osi z)
     * Argumenty:
     *    srodek - punkt bedacy srodkiem obiektu geometrycznego
     *    alfa - kat (w stopniach) o jaki obiekt obracamy
     */
    void obrot_wokol_wlasnej_osi(Wektor3D const &srodek, double const alfa);


    /*!
    * \brief przesuwa obiekt geometryczny o zadana przez uzytkownika dlugosc
    *  
    * przesuwa obiekt geometryczny o zadana przez uzytkownika dlugosc 
    * z wskazanym katem opadania lub wznoszenia w strone w ktora jest on obrocony
    * Argumenty:
    *       kat_patrzenia_w_st - kat okreslajacy strone w ktora obiekt jest zwrocony podany w stopniach
    *       kat_wznoszenia_w_st - kat pod jakim dron sie bedzie wznosic
    *       dlugosc_lotu - dlugosc drogi jaka ma przebyc dron
    */
    void na_wprost(double kat_patrzenia_w_st,double kat_wznoszenia_w_st, double dlugosc_lotu);


    /*!
    * \brief zwalnia pamiec zajeta przez bryle
    * 
    * zwalnia pamiec zaalokowane na bryle usuwajac caly obiekt 
    */ 
    void usun_bryle();
};

#endif