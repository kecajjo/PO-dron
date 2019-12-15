#include <iostream>
#include <iomanip>
#include <fstream>
#include <iterator>
#include "menu.hh"
#include "Wektor3D.hh"
#include "Macierz3x3.hh"
#include "Prostopadloscian.hh"
#include "lacze_do_gnuplota.hh"
#include "wirnik.hh"
#include "bryla.hh"
#include "dron.hh"
#include "przeszkoda.hh"
#include "obiekt_sceny.hh"

#define DL_BOKU 50

void wyswietl_menu(){

std::cout<<"o - obrot drona"<<std::endl;
std::cout<<"r - ruch drona do przodu"<<std::endl;
std::cout<<"m - wyswietl menu"<<std::endl;
//std::cout<<"g - wyswietl Prostopadloscian gnuplotem"<<std::endl;
std::cout<<"w - wybor drona"<<std::endl;
std::cout<<"d - dodaj obiekt"<<std::endl;
std::cout<<"u - usun obiekt"<<std::endl;
std::cout<<"k - koniec dzialania programu"<<std::endl;

}

void menu(singleton &fabryka){

char wybor='\0';
PzG::LaczeDoGNUPlota lacze;
Macierz3x3 kat;
std::list<std::shared_ptr<dron>>::iterator iter;
std::list<std::shared_ptr<obiekt_sceny>>::iterator iter2;
std::string nazwa_pliku;
unsigned int liczba_plikow, numer_drona_na_liscie_obiektow, numer_drona=1;
char rodzaj_obiektu;


iter=fabryka.set_scena().set_lista_dronow().begin();
iter2=fabryka.set_scena().set_lista_obiektow().begin();




    
    wyswietl_menu();

    while(wybor!='k'){
        liczba_plikow=uzupelnij_pliki(fabryka.set_scena());
        ustaw_opcje_gnuplota(lacze, liczba_plikow);

        iter2=fabryka.set_scena().set_lista_obiektow().begin();
        iter=fabryka.set_scena().set_lista_dronow().begin();
        numer_drona_na_liscie_obiektow=fabryka.set_scena().dron_ktory_na_liscie_obiektow(numer_drona);
        if(numer_drona>1) std::advance(iter,numer_drona-1);


        std::cin.clear();
        std::cout<<"Twoj wybor? (m - menu) >";
        std::cin>>wybor;
        switch(wybor){
            case 'o':
                fabryka.set_scena().animuj_obrot_drona(lacze, numer_drona_na_liscie_obiektow, **iter);
                std::cout << "ilosc aktualnych obiektow typu Wektor3D:"
                  << Wektor3D::get_aktualnych() << std::endl
                  << "ilosc utworzonych obiektow typu Wektor3D:"
                  << Wektor3D::get_utworzonych() << std::endl;

                std::cout << "ilosc aktualnych obiektow typu obiekt_geometryczny:"
                  << obiekt_sceny::get_aktualnych_obiektow() << std::endl
                  << "ilosc utworzonych obiektow typu obiekt_geometryczny:"
                  << obiekt_sceny::get_utworzonych_obiektow() << std::endl;
  
                break;
            case 'r': // do zmiany kat_patrzenia=Pr.znajdz_kat_patrzenia();
                fabryka.set_scena().animuj_lot_drona(lacze, numer_drona_na_liscie_obiektow, **iter);
                std::cout << "ilosc aktualnych obiektow typu Wektor3D:"
                  << Wektor3D::get_aktualnych() << std::endl
                  << "ilosc utworzonych obiektow typu Wektor3D:"
                  << Wektor3D::get_utworzonych() << std::endl;
                
                std::cout << "ilosc aktualnych obiektow typu obiekt_geometryczny:"
                  << obiekt_sceny::get_aktualnych_obiektow() << std::endl
                  << "ilosc utworzonych obiektow typu obiekt_geometryczny:"
                  << obiekt_sceny::get_utworzonych_obiektow() << std::endl;
  
                break;
            case 'm': wyswietl_menu();
                break;
            case 'd': 
                std::cout<<"podaj rodzaj obiektu:\n\td - dron\n\tp - przeszkoda"<<std::endl;
                std::cin>>rodzaj_obiektu;
                while(rodzaj_obiektu!='d' && rodzaj_obiektu!='p'){
                    std::cout<<"nie znam takiego obiektu sprobuj jeszcze raz\n\td - dron\n\tp - przeszkoda"<<std::endl;
                    std::cin>>rodzaj_obiektu;
                }
                fabryka.dodaj_obiekt(rodzaj_obiektu);
                break;
            case 'u':
                std::cout<<"podaj rodzaj obiektu:\n\td - dron\n\tp - przeszkoda"<<std::endl;
                std::cin>>rodzaj_obiektu;
                while(rodzaj_obiektu!='d' && rodzaj_obiektu!='p'){
                    std::cout<<"nie znam takiego obiektu sprobuj jeszcze raz\n\td - dron\n\tp - przeszkoda"<<std::endl;
                    std::cin>>rodzaj_obiektu;
                }
                fabryka.usun_obiekt(rodzaj_obiektu);
                numer_drona=1;
                break;
            case 'k': ;// koniec while
                break;
            case 'w': std::cout<<"wybierz numer drona (liczymy od 1)"<<std::endl;
                        std::cin>>numer_drona;
                        while(numer_drona>fabryka.set_scena().set_lista_dronow().size()){
                            std::cout<<"nie ma takiego drona"<<std::endl;
                            std::cin>>numer_drona;
                        }
                break;
            default: std::cout<<"Brak takiej opcji w menu. Sprobuj ponownie."<<std::endl;
                break;
        }
    }
}


void ustaw_opcje_gnuplota(PzG::LaczeDoGNUPlota &lacze, unsigned int liczba_plikow){

std::string nazwa_pliku;

    lacze.UsunWszystkieNazwyPlikow();
   //-------------------------------------------------------
   //  Wspolrzedne wierzcholkow beda zapisywane w pliku "prostokat.dat"
   //  Ponizsze metody powoduja, ze dane z pliku beda wizualizowane
   //  na dwa sposoby:
   //   1. Rysowane jako linia ciagl o grubosci 2 piksele
   //
   for(unsigned int ilosc=0;ilosc<liczba_plikow;ilosc++){
        nazwa_pliku="plik";
        nazwa_pliku+=std::to_string(ilosc+1);
        nazwa_pliku+=".dat";

        char tab_charow[20];
   
        for (unsigned int i = 0; i < sizeof(tab_charow); i++) { 
        tab_charow[i] = nazwa_pliku[i]; 
        }
        lacze.DodajNazwePliku(tab_charow,PzG::RR_Ciagly,2);
   }
   

   //
   //  Ustawienie trybu rysowania 3D, tzn. rysowany zbiór punktów
   //  znajduje się na wspólnej płaszczyźnie. Z tego powodu powoduj
   //  jako wspolrzedne punktow podajemy x,y,z.
   //
  lacze.ZmienTrybRys(PzG::TR_3D);

   // Ustawienie zakresow poszczegolnych osi
  lacze.UstawZakresY(-70,70);
  lacze.UstawZakresX(-70,70);
  lacze.UstawZakresZ(-70,70);
  
}


unsigned int uzupelnij_pliki(scena &moja_scena){

 unsigned int liczba_plikow=0;
 std::list<std::shared_ptr<obiekt_sceny>>::iterator iter;
 std::string nazwa_pliku;

    iter=moja_scena.set_lista_obiektow().begin();

    for(unsigned int liczba=0;liczba<moja_scena.set_lista_obiektow().size();liczba++){
        liczba_plikow++;
        nazwa_pliku="plik";
        nazwa_pliku+=std::to_string(liczba_plikow);
        nazwa_pliku+=".dat";
        (*iter)->ZapisWspolrzednychDoPliku(nazwa_pliku);
        iter++;
    }
    return liczba_plikow;
}