#ifndef PRZESZKODA_HH
#define PRZESZKODA_HH

#include "obiekt_sceny.hh"

class przeszkoda_pr: public obiekt_sceny{

 Prostopadloscian przeszkoda;

 public:

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
    * \brief Przeciazenie pozwala nam na pobieranie wartosci z tablicy wierzcholki[]
    */
    Wektor3D operator [] (int indeks) const {return przeszkoda[indeks];}
    /*!
    * \brief Przeciazenie pozwala nam na modyfikacje wartosci z tablicy wierzcholki[]
    */
    Wektor3D& operator [] (int indeks) {return przeszkoda[indeks];}

    /*!
    * \brief konstruktor tworzacy przeszkode o danym srodku (dlugosci zadane przez #define)
    */
    przeszkoda_pr(Wektor3D srodek);

/*!
 * \brief konstruktor tworzy przeszkode
 * 
 * konstruktor tworzy przeszkode korzystajac z dynamicznej tablicy vector
 * Argumenty:
 *    srodek - srodek tworzonego prostopadloscianu
 *    dlugosc_x - dlugosc tworzonego prostopadloscianu
 *    dlugosc_y - szerokosc tworzonego prostopadloscianu
 *    dlugosc_z 0 wysokosc tworzonego prostopadloscianu
 */
    przeszkoda_pr(Wektor3D srodek, double dlugosc_x, double dlugosc_y, double dlugosc_z);

    /*!
    * \brief destruktor do podliczania aktualnych obiektow
    */
    ~przeszkoda_pr(){aktualnych_obiektow--;}
    /*!
    * \brief konstruktor kopiujacy do podliczania aktualnych i utworzonych obiektow
    */
    przeszkoda_pr(const przeszkoda_pr &kopiowana);

};


/*!
 * \brief wyswietla przeszkode
 * 
 * Realizuje wyswietlanie przeszkody.
 * Argumenty:
 *    Strm - strumien wyjsciowy ostream&,
 *    Pr - przeszkoda do wyswietlenia.
 * Zwraca:
 *    Strumien wyjsciowy wyswietlajacy przeszkode.
 */
std::ostream& operator << ( std::ostream       &Strm, 
                            const przeszkoda_pr    &Pr
                          );



#endif