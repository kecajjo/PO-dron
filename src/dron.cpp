#include <iostream>
#include <iomanip>
#include <fstream>
#include <unistd.h>
#include "Wektor.hh"
#include "Macierz.hh"
#include "Macierz3x3.hh"
#include "Wektor3D.hh"
#include "bryla.hh"
#include "wirnik.hh"
#include "Prostopadloscian.hh"
#include "dron.hh"
#include "lacze_do_gnuplota.hh"






dron::dron(){

 Wektor3D srodek, pol_wysokosci_smigla;
 double wys_smigla=Z_SMIGLA;

    obrocony_o_stopni=0;
    rodzaj_obiektu='d';
    utworzonych_obiektow++;
    aktualnych_obiektow++;

    pol_wysokosci_smigla[2]=wys_smigla/2;
    korpus.stworz_prostopadloscian_o_srodku(srodek);

    for(int indeks=0;indeks<ILOSC_SMIGIEL;indeks++){
        smigla[indeks].stworz_wirnik_o_srodku(korpus[2*indeks+1]+pol_wysokosci_smigla);
    }
}

dron::dron(Wektor3D srodek){

 Wektor3D pol_wysokosci_smigla;
 double wys_smigla=Z_SMIGLA;

    obrocony_o_stopni=0;
    rodzaj_obiektu='d';
    utworzonych_obiektow++;
    aktualnych_obiektow++;

    pol_wysokosci_smigla[2]=wys_smigla/2;
    korpus.stworz_prostopadloscian_o_srodku(srodek);

    for(int indeks=0;indeks<ILOSC_SMIGIEL;indeks++){
        smigla[indeks].stworz_wirnik_o_srodku(korpus[2*indeks+1]+pol_wysokosci_smigla);
    }
}

dron::dron(const dron &kopiowany){
    utworzonych_obiektow++;
    aktualnych_obiektow++;
    obrocony_o_stopni=kopiowany.get_obrocony_o_stopni();
    korpus=kopiowany.get_korpus();
    for(unsigned int indeks=0; indeks<ILOSC_SMIGIEL; indeks++){
        smigla[indeks]=kopiowany.get_smigla(indeks);
    }
}

std::ostream& operator << ( std::ostream       &Strm, 
                            const dron    &dr
                          ){

    Strm << dr.get_korpus() << std::endl;

    Strm << std:: endl;

    for (int indeks=0; indeks<ILOSC_SMIGIEL; indeks++){
        Strm << dr.get_smigla(indeks) << std::endl;
    }
return Strm;
}

void dron::rusz_drona(double dlugosc_lotu, double kat_wznoszenia_w_st){

    korpus.na_wprost(obrocony_o_stopni, kat_wznoszenia_w_st, dlugosc_lotu);

    for(int indeks=0; indeks<ILOSC_SMIGIEL; indeks++){
        smigla[indeks].na_wprost(obrocony_o_stopni, kat_wznoszenia_w_st, dlugosc_lotu);
    }
}

void dron::obroc_drona(double kat_obrotu_w_st){
 Wektor3D srodek;

    obrocony_o_stopni+=kat_obrotu_w_st;
    srodek=korpus.znajdz_srodek();
    korpus.obrot_wokol_wlasnej_osi(srodek, kat_obrotu_w_st);
    for(int indeks=0; indeks<ILOSC_SMIGIEL;indeks++){
        smigla[indeks].obrot_wokol_wlasnej_osi(srodek,kat_obrotu_w_st);
    }

}

void dron::usun_drona(){

    korpus.usun_bryle();
    for(int indeks=0;indeks<ILOSC_SMIGIEL;indeks++){
        smigla[indeks].usun_bryle();
    }

}

//void dron::animuj_obrot_drona(PzG::LaczeDoGNUPlota lacze,unsigned int ktory_plik_modyfikowac, dron &dron_poczatkowy){
//
// double kat_obrotu_w_st;
// dron dron_rysowany;
// Wektor3D srodek_smigla;
// std::string nazwa_pliku = "plik";
// std::string numer_na_string;
// numer_na_string=std::to_string(ktory_plik_modyfikowac);
// nazwa_pliku+=numer_na_string;
// nazwa_pliku+=".dat";
//
//
//    std::cout<<"podaj kat o jaki chcesz obrocic drona"<<std::endl;
//    std::cin>>kat_obrotu_w_st;
//    while(std::cin.fail()){
//        std::cout << "nie podano liczby typu double\n";
//        std::cin.clear();
//        std::cin.ignore(10000, '\n');
//        std::cin>>kat_obrotu_w_st;
//    }
// 
//    for(int indeks=0;indeks<=LICZBA_KLATEK;indeks++){
//        dron_rysowany=dron_poczatkowy;
//        dron_rysowany.obroc_drona(kat_obrotu_w_st*indeks/LICZBA_KLATEK);
//            for(int numer_smigla=0; numer_smigla<ILOSC_SMIGIEL;numer_smigla++){
//                srodek_smigla=dron_rysowany.smigla[numer_smigla].znajdz_srodek();
//                dron_rysowany.smigla[numer_smigla].obrot_wokol_wlasnej_osi(srodek_smigla, -1*KAT_OBROTU_WIRNIKOW*indeks/LICZBA_KLATEK);
//            }
//        if (!dron_rysowany.ZapisWspolrzednychDoPliku(nazwa_pliku))
//              std::cerr<<"liczba argumentow funkcji zapis_wspolrzednych_do_pliku==0";
//        lacze.Rysuj(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku
//        usleep(20000);
//    }
//    std::cin.ignore(100000, '\n');
//    dron_poczatkowy=dron_rysowany;
//    dron_rysowany.usun_drona();
//}
//
//void dron::animuj_lot_drona(PzG::LaczeDoGNUPlota lacze,unsigned int ktory_plik_modyfikowac, dron &dron_poczatkowy){
//
// double kat_wznoszenia_w_st, dlugosc_lotu;
// dron dron_rysowany;
// Wektor3D srodek_smigla;
// std::string nazwa_pliku="plik";
// std::string numer_na_string;
// numer_na_string=std::to_string(ktory_plik_modyfikowac);
// nazwa_pliku+=numer_na_string;
// nazwa_pliku+=".dat";
//
//
// 
//
//    std::cout<< "Podaj dlugosc lotu drona" << std::endl;
//    std::cin >> dlugosc_lotu;
//     while(std::cin.fail()){
//            std::cout << "nie podano liczby typu double\n";
//            std::cin.clear();
//            std::cin.ignore(10000, '\n');
//            std::cin>>dlugosc_lotu;
//        }
//    std::cout<< "Podaj kat wznoszenia (dodatni) lub opadania (ujemny)" << std::endl;
//    std::cin >> kat_wznoszenia_w_st;
//    while(std::cin.fail() || kat_wznoszenia_w_st<=-90 || kat_wznoszenia_w_st>=90){
//            std::cout << "nie podano liczby typu double\n";
//            std::cin.clear();
//            std::cin.ignore(10000, '\n');
//            std::cin>>kat_wznoszenia_w_st;
//        }
//
//    for(int indeks=0;indeks<=LICZBA_KLATEK;indeks++){
//        dron_rysowany=dron_poczatkowy;
//        dron_rysowany.rusz_drona(dlugosc_lotu*indeks/LICZBA_KLATEK, kat_wznoszenia_w_st);
//            for(int numer_smigla=0; numer_smigla<ILOSC_SMIGIEL;numer_smigla++){
//                srodek_smigla=dron_rysowany.smigla[numer_smigla].znajdz_srodek();
//                dron_rysowany.smigla[numer_smigla].obrot_wokol_wlasnej_osi(srodek_smigla, KAT_OBROTU_WIRNIKOW*indeks/LICZBA_KLATEK);
//            }
//        if (!dron_rysowany.ZapisWspolrzednychDoPliku(nazwa_pliku))
//              std::cerr<<"liczba argumentow funkcji zapis_wspolrzednych_do_pliku==0";
//        lacze.Rysuj(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku
//        usleep(20000);
//    }
//    std::cin.ignore(100000, '\n');
//    dron_poczatkowy=dron_rysowany;
//
//    dron_rysowany.usun_drona();
//
//}


void dron::ZapisWspolrzednychDoStrumienia( std::ostream&      StrmWy){

  StrmWy << std::setw(16) << std::fixed << std::setprecision(10) << *this;

}



bool dron::ZapisWspolrzednychDoPliku( std::string  sNazwaPliku){
  std::ofstream  StrmPlikowy;

  StrmPlikowy.open(sNazwaPliku);
  if (!StrmPlikowy.is_open())  {
    std::cerr << ":(  Operacja otwarcia do zapisu \"" << sNazwaPliku << "\"" << std::endl
	 << ":(  nie powiodla sie." << std::endl;
    return false;
  }

  ZapisWspolrzednychDoStrumienia(StrmPlikowy);

  StrmPlikowy.close();
  return !StrmPlikowy.fail();
}
