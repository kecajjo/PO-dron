#ifndef MACIERZ_HH
#define MACIERZ_HH

/*!
 * \file
 * \brief definicja szablonu klasy Macierz
 * 
 *  Plik zawiera szablon klasy macierz, ktory tworzy macierz kwadratowa
 *  na bazie szablonu Wektor
 */

#include <iostream>
#include <cmath>
#include <math.h>
#include "Wektor.hh"


/*!
 * \brief Modeluje szablon klasy Macierz
 * 
 *  klasa tworzy macierz jako tablice wektorow
 *  pozwala na zamiane stopni na radiany wewnatrz tej klasy,
 *  uzupelnienie sie funkcjami trygonometrycznymi oraz iloczyn macierzy * wektor
 */
template<int Wymiar>
class Macierz
{
  Wektor<Wymiar> wiersze[Wymiar];

public:




/*!
* \brief Konstruktor wypelnia macierz zerami
*/
  Macierz(){Wektor<Wymiar> zero; for(int indeks=0;indeks<Wymiar;indeks++)wiersze[indeks]=zero;}
/*!
* \brief Przeciazenie pozwala nam na pobieranie wartosci z tablicy wiersze[]
*/
  Wektor<Wymiar> operator[](int indeks) const { return wiersze[indeks]; }
/*!
* \brief Przeciazenie pozwala nam na modyfikacje wartosci z tablicy wiersze[]
*/
  Wektor<Wymiar> &operator[](int indeks) {return wiersze[indeks];}


/*!
 * \brief Mnozy macierz przez wektor
 * 
 * Realizuje mnozenie macierzy przez wektor
 * Argumenty:
 *    this - macierz ktora mnozymy
 *    wspolrzedne - wektor przez ktory mnozymy macierz
 * Zwraca:
 *    wektor bedacy wynikiem mnozenia
 */
  Wektor<Wymiar> operator * (Wektor<Wymiar> const wspolrzedne){
    Wektor<Wymiar> wynik;

      for(int iii=0;iii<Wymiar;iii++){
      wynik[iii]=this->wiersze[iii]*wspolrzedne;
      }

return wynik;
  }
  


/*!
 * \brief Mnozenie macierzy przez macierz
 * 
 * Realizuje mnozenie macierzy przez macierz
 * Argumenty:
 *    this - macierz ktora mnozymy
 *    mac - macierz przez ktory mnozymy macierz
 * Zwraca:
 *    macierz bedaca wynikiem mnozenia
 */
  Macierz<Wymiar> operator * (Macierz<Wymiar> const mac){
    
    Macierz<Wymiar> wynik;

    for(int ind_wier=0; ind_wier<Wymiar; ind_wier++){
      for(int ind_kol=0; ind_kol<Wymiar; ind_kol++){
        for(int skladnik=0; skladnik<Wymiar; skladnik++){
          wynik[ind_wier][ind_kol]=wynik[ind_wier][ind_kol]+wiersze[ind_wier][skladnik]*mac[skladnik][ind_kol];
        }
      }
    }    

return wynik;
  }

};

/*!
 * \brief Wyswietla macierz
 * 
 * Realizuje wyswietlanie macierzy.
 * Argumenty:
 *    Strm - strumien wyjsciowy ostream&,
 *    Wek - wektor do wyswietlenia.
 * Zwraca:
 *    Strumien wyjsciowy wyswietlajacy macierz.
 */
template <int Wymiar>
inline
std::ostream &operator<<(std::ostream &Strm, const Macierz<Wymiar> &Mac){
  int iii;

    for(iii=0;iii<Wymiar;iii++){
            Strm << Mac[iii];
        Strm << std::endl;
    }
return Strm;
}


#endif
