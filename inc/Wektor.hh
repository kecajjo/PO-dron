#ifndef WEKTOR_HH
#define WEKTOR_HH

/*!
 * \file
 * \brief definicja szablonu klasy Wektor
 * 
 *  Plik zawiera szablon klasy wektor
 */

#include <iostream>
#include <cmath>


/*!
 * \brief Tworzy szablon klasy Wektor
 * 
 * Klasa tworzy wektor jako tablice liczb typu double.
 * posiada rowniez pola statyczne wykorzystywane do liczenia ilosci stworzonych wektorow
 * i modeluje metody operujace na wektorach takie jak przyrownanie, +=,
 * iloczyn skalarny, odejmowanie, liczenie dlugosci wektora
 */
template <int Wymiar>
class Wektor {

  static unsigned long int utworzonych;
  static unsigned long int aktualnych;
  double wspolrzedne[Wymiar];
  
    public:

    /*!
    * \brief pozwala na pobranie wartosci aktualne
    */
    static unsigned int get_aktualnych(){return aktualnych;}    
    
    /*!
    * \brief pozwala na pobranie wartosci utworzonych
    */
    static unsigned int get_utworzonych(){return utworzonych;}    

  /*!
  * \brief Konstruktor wypelnia wektor zerami i liczy utworzone obiekty typu Wektor<>
  */
    Wektor(){
        aktualnych++;
        utworzonych++;
        for(int i=0;i<Wymiar;i++)wspolrzedne[i]=0;
    }

  /*!
  * \brief Konstruktor tworzy wektor trojwymiarowy o podanych wspolrzednych lub wypelnia zerami jesli to nie jest wektor3D
  */
    Wektor(double x, double y, double z){
        if (Wymiar!=3){
            std::cout<<"to nie jest Wektor3D"<<std::endl;
            for(int i=0;i<Wymiar;i++)wspolrzedne[i]=0;
        }
        else {
            wspolrzedne[0]=x; wspolrzedne[1]=y; wspolrzedne[2]=z;
        }
        aktualnych++;
        utworzonych++;
    }
    /*!
    * \brief Konstruktor kopiujacy podlicza wartosc utworzonych obiektow typu Wektor<>
    */
    Wektor(const Wektor<Wymiar>& wektor){
        aktualnych++;
        utworzonych++;
        for(int i=0; i<Wymiar;i++)wspolrzedne[i]=wektor[i];
    }
    /*!
    * \brief destruktor odejmuje obecna liczbe obiektow typu Wektor<>
    */
    ~Wektor(){aktualnych--;}

  /*!
  * \brief Przeciazenie pozwala nam na pobieranie wartosci z tablicy wspolrzedne[]
  */
  double operator [] (int indeks) const {return wspolrzedne[indeks];}
  /*!
  * \brief Przeciazenie pozwala nam na modyfikacje wartosci z tablicy wspolrzedne[]
  */
  double& operator [] (int indeks) {return wspolrzedne[indeks];}
  
  /*!
   * \brief przeciaza += dla wektora
   * 
   * Realizuje dodanie do wektora innego wektora (tak jak bysmy mieli double+=double tyle ze z wektorem)
   * Argumenty:
   *    this - modyfikowana przez nas liczba przez dodanie innej
   *    wektor - liczba ktora dodajemy do this
   * Zwraca:
   *    nie zwraca wartosci
   */
  void operator += (Wektor<Wymiar> wektor){int iii=0; for(double &indeks : this->wspolrzedne) indeks+= wektor.wspolrzedne[iii++];}
  
  /*!
   * \brief przeciaza -= dla wektora
   * 
   * Realizuje odjecie do wektora innego wektora (tak jak bysmy mieli double-=double tyle ze z wektorem)
   * Argumenty:
   *    this - modyfikowana przez nas liczba przez odjecie innej
   *    wektor - liczba ktora odejmujemy od this
   * Zwraca:
   *    nie zwraca wartosci
   */
  void operator -= (Wektor<Wymiar> wektor){int iii=0; for(double &indeks : this->wspolrzedne) indeks-= wektor.wspolrzedne[iii++];}
  

  /*!
   * \brief wprowadza iloczyn skalarny wektorow
   * 
   * Realizuje iloczyn skalarny dwoch wektorow.
   * Argumenty:
   *    this - pierwszy czynnik (nie modyfikujemy),
   *    wektor - drugi czynnyik.
   * Zwraca:
   *    iloczyn skalarny dwoch wektorow przekazanych jako parametry.
   */
  double operator * (Wektor<Wymiar> const wektor){
  
  double wynik=0;
  int iii;
      for(iii=0;iii<Wymiar;iii++){
          wynik=wynik+this->wspolrzedne[iii]*wektor[iii];
      }
  return wynik;
  }
  

  /*!
   * \brief wprowadza odejmowanie dwoch wektorow
   * 
   * Realizuje odejmowanie dwoch wektorow.
   * Argumenty:
   *    this - odjemna,
   *    odjemnik - odjemnik.
   * Zwraca:
   *    roznice dwoch wektorow.
   */
  Wektor<Wymiar> operator - (Wektor<Wymiar> const odjemnik){
  Wektor<Wymiar> wynik;
      for(int iii=0;iii<Wymiar;iii++){
          wynik[iii]=this->wspolrzedne[iii]-odjemnik[iii];
      }
  return wynik;
  }

   /*!
   * \brief wprowadza dodawanie dwoch wektorow
   * 
   * Realizuje dodawanie dwoch wektorow.
   * Argumenty:
   *    this - skladnik1,
   *    skladnik - skladnik2.
   * Zwraca:
   *    sume dwoch wektorow.
   */
  Wektor<Wymiar> operator + (Wektor<Wymiar> const skladnik){
  Wektor<Wymiar> wynik;
      for(int iii=0;iii<Wymiar;iii++){
          wynik[iii]=this->wspolrzedne[iii]+skladnik[iii];
      }
  return wynik;
  }
  
  
  /*!
   * \brief wprowadza dzielenie wektora przez liczbe
   * 
   * Realizuje dzielenie wektora przez liczbe.
   * Argumenty:
   *    this - dzielna,
   *    skladnik - dzielnik.
   * Zwraca:
   *    iloraz wektora przez liczbe.
   */
  Wektor<Wymiar> operator / (double const dzielnik){
  Wektor<Wymiar> wynik;
      for(int iii=0;iii<Wymiar;iii++){
          wynik[iii]=this->wspolrzedne[iii]/dzielnik;
      }
  return wynik;
  }
  

  /*!
   * \brief pozwala na przyrownanie dwoch wektorow
   * 
   * Realizuje przyrownanie dwoch wektorow z zadana dokladnoscia.
   * Argumenty:
   *    this - liczba przyrownywana
   *    tmp - liczba ktora przyrownujemy
   * Zwraca:
   *    true jesli liczby sa rowne lub false jesli sie roznia.
   */
  bool operator == (Wektor<Wymiar> const tmp){
  
  double dokladnosc=1.0e-8;
      for(int iii=0;iii<Wymiar;iii++){
          if((this->wspolrzedne[iii]-tmp[iii])>dokladnosc 
          || (this->wspolrzedne[iii]-tmp[iii])<(dokladnosc * -1 )){
              return false;
          }
      }
  return true;
  }
  
  /*!
   * \brief liczy dlugosc Wektora
   * 
   * oblicza dlugosc wektora
   * Argumenty:
   *    this - wektor ktorego dlugosc liczymy
   * Zwraca:
   *    dlugosc wektora (odleglosc punktu od punktu 0,0).
   */
  double dlugosc(){
  
  double wynik;
  double kwadraty_dodane=0;
  
      for(int iii=0;iii<Wymiar;iii++){
          kwadraty_dodane=kwadraty_dodane+this->wspolrzedne[iii]*this->wspolrzedne[iii];
      }
      
      wynik=sqrt(kwadraty_dodane);
  
  return wynik;
  }
  
};

/* koniec klasy!!!*/

  template <int Wymiar> unsigned long int Wektor<Wymiar>::utworzonych=0;
  template <int Wymiar> unsigned long int Wektor<Wymiar>::aktualnych=0;

/*!
 * \brief Pozwala na wczytanie Wektora
 * 
 * Realizuje wczytywanie wektora. W razie podania czesgos co nie jest typem double (np char) prosi o ponowne wpisanie.
 * Argumenty:
 *    Strm - strumien wejsciowy istream&,
 *    Wek - wektor do wczytania.
 * Zwraca:
 *    Strumien wejsciowy zawierajacy wczytany wektor.
 */
template <int Wymiar>
std::istream& operator >> (std::istream &Strm, Wektor<Wymiar> &Wek){

int iii;
double dable;

    for(iii=0;iii<Wymiar;iii++){
        Strm >> dable;
        while(Strm.fail()){
            std::cout << "nie podano liczby typu double\n";
            Strm.clear();
            Strm.ignore(10000, '\n');
            Strm>>dable;
        }
        Wek[iii]=dable;
        
    }

return Strm;
}

/*!
 * \brief pozwala na wypisanie Wektora
 * 
 * Realizuje wyswietlanie wektora.
 * Argumenty:
 *    Strm - strumien wyjsciowy ostream&,
 *    Wek - wektor do wyswietlenia.
 * Zwraca:
 *    Strumien wyjsciowy wyswietlajacy wektor.
 */
template<int Wymiar>
inline
std::ostream& operator << (std::ostream &Strm, const Wektor<Wymiar> &Wek){

int iii;

    for(iii=0;iii<Wymiar;iii++){
        Strm << Wek[iii] << "   ";
    }
    Strm << std::endl;
return Strm;
}



#endif
