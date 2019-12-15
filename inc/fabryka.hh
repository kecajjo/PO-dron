#ifndef FABRYKA_HH
#define FABRYKA_HH


#include "scena.hh"


class singleton{

    scena moja_scena;
    public:static unsigned int ilosc_fabryk;

    /*!
    * \brief Konstruktor liczacy ilosc fabryk i tworzacy scene
    */
   singleton(){scena tmp; moja_scena = tmp; ilosc_fabryk++;}

 public:

    /*!
    * \brief Konstruktor kopiujacy liczacy ilosc fabryk
    */
    singleton(const singleton& single){
        ilosc_fabryk++;
        moja_scena=single.moja_scena;
    }
    /*!
    * \brief destruktor do zloczania ilosc fabryk
    */
    ~singleton(){ ilosc_fabryk--;}

    scena &set_scena(){return moja_scena;}
    scena get_scena() const {return moja_scena;}

    /*!
   * \brief pozwala stworzyc singleton
   * 
   * tworzy singleton o ile zaden obecnie nie istnieje
   * Argumenty:
   *    this - nasz singleton
   * Zwraca:
   *    pointer na stworzony singleton
   */
    static singleton *stworz_fabryke(){if(ilosc_fabryk<1){singleton *stworzony=new(singleton); return stworzony;}
                                 else {std::cout<<"fabryka juz istnieje\nzwrocono nullptr!"<<std::endl;} return nullptr;}

   /*!
   * \brief dodaje obiekt
   * 
   * pozwala na dodanie drona i przeszkody
   * Argumenty:
   *    char rodzaj - rodzaj obiektu jaki chcemy dodac (p - przeszkoda d - dron)
   */                                 
    void dodaj_obiekt(char rodzaj);

    /*!
   * \brief usuwa obiekt
   * 
   * pozwala na usuniecie drona i przeszkody
   * Argumenty:
   *    char rodzaj - rodzaj obiektu jaki chcemy usunac (p - przeszkoda d - dron)
   */     
    void usun_obiekt(char rodzaj);


};

#endif