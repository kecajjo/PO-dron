#ifndef SCENA_HH
#define SCENA_HH

#include <memory>
#include <list>
#include <iterator>
#include "dron.hh"
#include "przeszkoda.hh"

#define LICZBA_KLATEK 200

class scena{


    std::list<std::shared_ptr<dron>> lista_dronow;
    std::list<std::shared_ptr<obiekt_sceny>> lista_obiektow;
public:

    std::list<std::shared_ptr<dron>> &set_lista_dronow () {return lista_dronow;}
    std::list<std::shared_ptr<obiekt_sceny>> &set_lista_obiektow () {return lista_obiektow;}

/*!
 * \brief konstruktor tworzy 3 drony i 3 przeszkody i umieszcza je na odpowiednich listach
 */
    scena();

    /*!
    * \brief sprawdza ktory na lista_obiektow jest dron o wybranym numerze
    * 
    * funkcja sprawdza ktory na lista_obiektow jest dron z ktorego chcemy skorzystac
    * argumenty:
    *   numer_drona - numer drona, ktorego wybralismy (liczymy od 1 nie od 0)
    * zwraca:
    *   numer drona na liscie obiektow  (liczony od 1 nie od 0)
    */
    unsigned int dron_ktory_na_liscie_obiektow(unsigned int numer_drona);

    /*!
    * \brief sprawdza ktora na lista_obiektow jest przeszkoda o wybranym numerze
    * 
    * funkcja sprawdza ktora na lista_obiektow jest przeszkoda z ktorej chcemy skorzystac
    * argumenty:
    *   numer_przeszkody - numer przeszkody, ktora wybralismy (liczymy od 1 nie od 0)
    * zwraca:
    *   numer przeszkody na liscie obiektow  (liczony od 1 nie od 0)
    */
    unsigned int przeszkoda_ktora_na_liscie_obiektow(unsigned int numer_przeszkody);

/*!
 * \brief sprawdza czy zaszla kolizja
 * 
 * funkcja sprawdza czy dron wlecial w innego drona lub przeszkode
 * Argumenty:
 *    numer_drona_na_liscie_obiektow - numer sterowanego drona na lista_obiektow (liczac od 1 nie od 0)
 *    srodek_drona - srodek drona ktorym sterujemy
 * Zwraca:
 *    true jesli zaszla kolizja lub false jesli nie zaszla
 */
    bool czy_kolizja(unsigned int numer_drona_na_liscie_obiektow, Wektor3D srodek_drona);

    bool czy_kolizja_przeszkody(unsigned int ilosc_obiektow, przeszkoda_pr &przeszkoda);

/*!
 * \brief animuje obrot drona
 * 
 * Realizuje animacje obrotu drona
 * Argumenty:
 *   lacze - lacze do gnuplota
 *   ktory_plik_modyfikowac - numer pliku odpowiedzialnego za drona ktorym latamy
 *   &dron_poczatkowy - referencja do drona i jego pozycji startowej
 */
    void animuj_obrot_drona(PzG::LaczeDoGNUPlota lacze, unsigned int ktory_plik_modyfikowac,dron &dron_poczatkowy);

/*!
 * \brief animuje lot drona
 * 
 * Realizuje animacje lotu drona
 * Argumenty:
 *   lacze - lacze do gnuplota
 *   ktory_plik_modyfikowac - numer pliku odpowiedzialnego za drona ktorym latamy
 *   &dron_poczatkowy - referencja do drona i jego pozycji startowej
 */
    void animuj_lot_drona(PzG::LaczeDoGNUPlota lacze, unsigned int ktory_plik_modyfikowac, dron &dron_poczatkowy);
};



#endif