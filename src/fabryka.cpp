#include "fabryka.hh"


unsigned int singleton::ilosc_fabryk=0;

//singleton singleton::*stworz_fabryke(){
//    if(ilosc_fabryk<1){
//        singleton *stworzony=new(singleton);
//        return stworzony;
//    }
//    else {
//        std::cout<<"fabryka juz istnieje"<<std::endl;
//    } 
// return nullptr;
//}

void singleton::dodaj_obiekt(char rodzaj){

    switch(rodzaj){
        case 'd':{
            Wektor3D srodek;
            unsigned int numer_drona_na_liscie_obiektow;
            std::cout<<"podaj srodek drona"<<std::endl;
            std::cin>>srodek;
            auto dron_dodawany=std::make_shared<dron>(srodek);
            moja_scena.set_lista_dronow().push_back(dron_dodawany);
            moja_scena.set_lista_obiektow().push_back(dron_dodawany);
            numer_drona_na_liscie_obiektow
                =moja_scena.set_lista_obiektow().size();
            if(moja_scena.czy_kolizja(numer_drona_na_liscie_obiektow, srodek)){
                moja_scena.set_lista_dronow().pop_back(); //usuwa dodanego drona
                moja_scena.set_lista_obiektow().pop_back();
                std::cout<<"dron kolidowal z innym obiektem\ndodanie nie powiodlo sie"<<std::endl;
            }
        } break;
        case 'p':{
            Wektor3D srodek;
            double dlugosc_x, dlugosc_y, dlugosc_z;
            std::cout<<"podaj srodek przeszkody"<<std::endl;
            std::cin>>srodek;
            std::cout<<"podaj dlugosci x, y i z przeszkody"<<std::endl;
            std::cin>>dlugosc_x>>dlugosc_y>>dlugosc_z;
            auto przeszkoda_dodawana=std::make_shared<przeszkoda_pr>
                (srodek,dlugosc_x,dlugosc_y,dlugosc_z);
            moja_scena.set_lista_obiektow().push_back(przeszkoda_dodawana);
            if(moja_scena.czy_kolizja_przeszkody(
                                                moja_scena.set_lista_obiektow().size()-1,
                                                *przeszkoda_dodawana)){
                moja_scena.set_lista_obiektow().pop_back();
                std::cout<<"przeszkoda kolidowala z innym obiektem\ndodanie nie powiodlo sie"<<std::endl;
            }
        } break;
        default:{
            std::cout<<"nie ma takiego typu obiektu"<<std::endl;
        } break;
    }

}

void singleton::usun_obiekt(char rodzaj){

 unsigned int numer_drona, numer_drona_na_liscie_obiektow;
 unsigned int numer_przeszkody, numer_przeszkody_na_liscie_obiektow;
 std::list<std::shared_ptr<dron>>::iterator iter_drona;
 std::list<std::shared_ptr<obiekt_sceny>>::iterator iter_obiektu;
 unsigned int liczba_przeszkod;

    switch(rodzaj){
        case 'd':
            if(moja_scena.set_lista_dronow().size()>1){
                std::cout<<"wybierz numer drona (liczymy od 1)"<<std::endl;
                std::cin>>numer_drona;
                while(numer_drona>moja_scena.set_lista_dronow().size()){
                    std::cout<<"nie ma takiego drona"<<std::endl;
                    std::cin>>numer_drona;
                }

                iter_drona=moja_scena.set_lista_dronow().begin();
                iter_obiektu=moja_scena.set_lista_obiektow().begin();
                if(numer_drona>1) std::advance(iter_drona,numer_drona-1);
                numer_drona_na_liscie_obiektow
                    =moja_scena.dron_ktory_na_liscie_obiektow(numer_drona);
                if(numer_drona_na_liscie_obiektow>1)
                    std::advance(iter_obiektu,numer_drona_na_liscie_obiektow-1);

                moja_scena.set_lista_dronow().erase(iter_drona);
                moja_scena.set_lista_obiektow().erase(iter_obiektu);
            }
        break;
        case 'p':
            liczba_przeszkod=moja_scena.set_lista_obiektow().size()
                                    -moja_scena.set_lista_dronow().size();
            if(liczba_przeszkod>0){
                std::cout<<"wybierz numer przeszkody (liczymy od 1)"<<std::endl;
                std::cin>>numer_przeszkody;
                while(numer_przeszkody>liczba_przeszkod){
                    std::cout<<"nie ma takiej przeszkody"<<std::endl;
                    std::cin>>numer_przeszkody;
                }

                iter_obiektu=moja_scena.set_lista_obiektow().begin();
                numer_przeszkody_na_liscie_obiektow
                    =moja_scena.przeszkoda_ktora_na_liscie_obiektow(numer_przeszkody);
                if(numer_przeszkody_na_liscie_obiektow>1) 
                    std::advance(iter_obiektu, numer_przeszkody_na_liscie_obiektow-1);

                moja_scena.set_lista_obiektow().erase(iter_obiektu);
            }
        break;
        default:
            std::cout<<"nie znam takiego obiektu"<<std::endl;
        break;
    }

}