#include "scena.hh"



scena::scena(){

std::shared_ptr<dron> ptr_drona(new dron);
lista_dronow.push_back(ptr_drona);
lista_obiektow.push_back(ptr_drona);

std::shared_ptr<dron> ptr_drona1(new dron(Wektor3D (-45,23,5)));
lista_dronow.push_back(ptr_drona1);
lista_obiektow.push_back(ptr_drona1);

std::shared_ptr<dron> ptr_drona2(new dron(Wektor3D (24,30,-27)));
lista_dronow.push_back(ptr_drona2);
lista_obiektow.push_back(ptr_drona2);

std::shared_ptr<przeszkoda_pr> ptr_przeszkody(
        new przeszkoda_pr(
            Wektor3D (15,-47,-20),10,15,23));
lista_obiektow.push_back(ptr_przeszkody);

std::shared_ptr<przeszkoda_pr> ptr_przeszkody1(
        new przeszkoda_pr(
            Wektor3D (-50,-34,45),20,35,15));
lista_obiektow.push_back(ptr_przeszkody1);

std::shared_ptr<przeszkoda_pr> ptr_przeszkody2(
        new przeszkoda_pr(
            Wektor3D (-6,-20,40),20,8,11));
lista_obiektow.push_back(ptr_przeszkody2);

}


unsigned int scena::dron_ktory_na_liscie_obiektow(unsigned int numer_drona){

 unsigned int to_dron=0;
 unsigned int numer_obiektu=0;
 std::list<std::shared_ptr<obiekt_sceny>>::iterator iter;

 iter=lista_obiektow.begin();

    while(to_dron<numer_drona){
        numer_obiektu++;
        if((*iter)->get_rodzaj_obiektu()=='d')
        to_dron++;
        iter++;
    }
 return numer_obiektu;
}

unsigned int scena::przeszkoda_ktora_na_liscie_obiektow(unsigned int numer_przeszkody){

 unsigned int to_przeszkoda=0;
 unsigned int numer_obiektu=0;
 std::list<std::shared_ptr<obiekt_sceny>>::iterator iter;

 iter=lista_obiektow.begin();

    while(to_przeszkoda<numer_przeszkody){
        numer_obiektu++;
        if((*iter)->get_rodzaj_obiektu()=='p')
        to_przeszkoda++;
        iter++;
    }
 return numer_obiektu;
}


bool scena::czy_kolizja(unsigned int numer_drona_na_liscie_obiektow, Wektor3D srodek_drona){

 std::shared_ptr<dron> dron_uderzany;
 std::shared_ptr<przeszkoda_pr> przeszkoda_uderzana;
 std::list<std::shared_ptr
            <obiekt_sceny>>::iterator iterator_ruszanego_drona
            =lista_obiektow.begin();

    if (numer_drona_na_liscie_obiektow>1)
     std::advance(iterator_ruszanego_drona, numer_drona_na_liscie_obiektow-1);

 std::list<std::shared_ptr
            <obiekt_sceny>>::iterator iter=lista_obiektow.begin();


    for(unsigned int numer_obiektu=0;
            numer_obiektu<lista_obiektow.size();
            numer_obiektu++){
        if(iterator_ruszanego_drona!=iter){
            if('p'==(*iter)->get_rodzaj_obiektu()){
             przeszkoda_uderzana=std::dynamic_pointer_cast<przeszkoda_pr>(*iter);
             Wektor3D bok_skrajny_mniejszy=(*przeszkoda_uderzana)[0];
             Wektor3D bok_skrajny_wiekszy=(*przeszkoda_uderzana)[5];

                if(srodek_drona[0]>bok_skrajny_mniejszy[0]-static_cast<double>(DL_X)
                 && srodek_drona[0]<bok_skrajny_wiekszy[0]+static_cast<double>(DL_X)){
                    if(srodek_drona[1]>bok_skrajny_mniejszy[1]-static_cast<double>(DL_Y)
                     && srodek_drona[1]<bok_skrajny_wiekszy[1]+static_cast<double>(DL_Y)){
                        if(srodek_drona[2]>bok_skrajny_mniejszy[2]-static_cast<double>(DL_Z)
                         && srodek_drona[2]<bok_skrajny_wiekszy[2]+static_cast<double>(DL_Z)){
                            return true;
                        }
                    }
                }
            } else{
                if('d'==(*iter)->get_rodzaj_obiektu()){
                 dron_uderzany=std::dynamic_pointer_cast<dron>(*iter);
                 Wektor3D srodek_uderzanego = dron_uderzany->get_korpus().znajdz_srodek();
                 srodek_uderzanego[2] +=(static_cast<double>(Z_SMIGLA))/2;

                    //zamiast pierwiastka na odleglosc nakladamy kwadrat na druga strone
                    if(2*PROMIEN_DRONA*2*PROMIEN_DRONA
                     >(srodek_drona[0]-srodek_uderzanego[0])*(srodek_drona[0]-srodek_uderzanego[0])
                     +(srodek_drona[1]-srodek_uderzanego[1])*(srodek_drona[1]-srodek_uderzanego[1])){
                        //kwadrat rozwiazuje problem modulu
                        if((srodek_drona[2]-srodek_uderzanego[2])*(srodek_drona[2]-srodek_uderzanego[2])
                         <(DL_Z+Z_SMIGLA)*(DL_Z+Z_SMIGLA)){
                             return true;
                        }
                     }
                } else{
                    std::cout<<"nie znam takiego rodzaju obiektu"<<std::endl;
                }
            }
        }
        //*iter=std::dynamic_pointer_cast<obiekt_sceny>(*iter);
        iter++;
    }

 return false;
}

bool scena::czy_kolizja_przeszkody(unsigned int ilosc_obiektow, przeszkoda_pr &przeszkoda){

 std::list<std::shared_ptr
            <obiekt_sceny>>::iterator iter=lista_obiektow.begin();
  char obiekt;  
  std::shared_ptr<przeszkoda_pr> przeszkoda_uderzana;
  std::shared_ptr<dron> dron_uderzany;
    for(unsigned int indeks=0; indeks<ilosc_obiektow;indeks++){
        obiekt=(*iter)->get_rodzaj_obiektu();
        switch(obiekt){
            case 'd':{
                dron_uderzany=std::dynamic_pointer_cast<dron>(*iter);
                Wektor3D bok_skrajny_mniejszy=przeszkoda[0];
                Wektor3D bok_skrajny_wiekszy=przeszkoda[5];
                Wektor3D srodek_drona;

                srodek_drona=dron_uderzany->get_korpus().znajdz_srodek();

                if(srodek_drona[0]>bok_skrajny_mniejszy[0]-static_cast<double>(DL_X)
                 && srodek_drona[0]<bok_skrajny_wiekszy[0]+static_cast<double>(DL_X)){
                    if(srodek_drona[1]>bok_skrajny_mniejszy[1]-static_cast<double>(DL_Y)
                     && srodek_drona[1]<bok_skrajny_wiekszy[1]+static_cast<double>(DL_Y)){
                        if(srodek_drona[2]>bok_skrajny_mniejszy[2]-static_cast<double>(DL_Z)
                         && srodek_drona[2]<bok_skrajny_wiekszy[2]+static_cast<double>(DL_Z)){
                            return true;
                        }
                    }
                }
            } break;
            case 'p':{
                przeszkoda_uderzana=std::dynamic_pointer_cast<przeszkoda_pr>(*iter);
                for(unsigned int wierzcholek=0; wierzcholek<8; wierzcholek++){
                    if(//czy wierzcholek aktualnej przeszkody jest miedzy wierzcholkami tworzonej
                        przeszkoda[0][0]<(*przeszkoda_uderzana)[wierzcholek][0] 
                        && przeszkoda[0][1]<(*przeszkoda_uderzana)[wierzcholek][1]
                        && przeszkoda[0][2]<(*przeszkoda_uderzana)[wierzcholek][2]

                        && przeszkoda[5][0]>(*przeszkoda_uderzana)[wierzcholek][0]
                        && przeszkoda[5][1]>(*przeszkoda_uderzana)[wierzcholek][1]
                        && przeszkoda[5][2]>(*przeszkoda_uderzana)[wierzcholek][2]
                    ) return true;
                }

                for(unsigned int wierzcholek=0;wierzcholek<8;wierzcholek++){    
                    if( // czy tworzona przeszkoda jest zagniezdzona w srodku istniejacej
                         (*przeszkoda_uderzana)[0][0]<przeszkoda[wierzcholek][0] 
                        && (*przeszkoda_uderzana)[0][1]<przeszkoda[wierzcholek][1]
                        && (*przeszkoda_uderzana)[0][2]<przeszkoda[wierzcholek][2]

                        && (*przeszkoda_uderzana)[5][0]>przeszkoda[wierzcholek][0]
                        && (*przeszkoda_uderzana)[5][1]>przeszkoda[wierzcholek][1]
                        && (*przeszkoda_uderzana)[5][2]>przeszkoda[wierzcholek][2]
                    ) return true;
                }
            } break;
            default: std::cout<<"nie znam takiego obiektu"<<std::endl;
            break;
        }
        iter++;
    }



 return false;
}



void scena::animuj_obrot_drona(PzG::LaczeDoGNUPlota lacze,unsigned int numer_drona_na_liscie_obiektow, dron &dron_poczatkowy){

 double kat_obrotu_w_st;
 dron dron_rysowany;
 Wektor3D srodek_smigla;
 std::string nazwa_pliku = "plik";
 std::string numer_na_string;
 numer_na_string=std::to_string(numer_drona_na_liscie_obiektow);
 nazwa_pliku+=numer_na_string;
 nazwa_pliku+=".dat";


    std::cout<<"podaj kat o jaki chcesz obrocic drona"<<std::endl;
    std::cin>>kat_obrotu_w_st;
    while(std::cin.fail()){
        std::cout << "nie podano liczby typu double\n";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cin>>kat_obrotu_w_st;
    }
 
    for(int indeks=0;indeks<=LICZBA_KLATEK;indeks++){
        dron_rysowany=dron_poczatkowy;
        dron_rysowany.obroc_drona(kat_obrotu_w_st*indeks/LICZBA_KLATEK);
            for(int numer_smigla=0; numer_smigla<ILOSC_SMIGIEL;numer_smigla++){
                srodek_smigla=dron_rysowany.get_smigla(numer_smigla).znajdz_srodek();
                dron_rysowany.set_smigla(numer_smigla).obrot_wokol_wlasnej_osi(srodek_smigla, -1*KAT_OBROTU_WIRNIKOW*indeks/LICZBA_KLATEK);
            }
        if (!dron_rysowany.ZapisWspolrzednychDoPliku(nazwa_pliku))
              std::cerr<<"liczba argumentow funkcji zapis_wspolrzednych_do_pliku==0";
        lacze.Rysuj(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku
        usleep(20000);


    }
    std::cin.ignore(100000, '\n');
    dron_poczatkowy=dron_rysowany;
    dron_rysowany.usun_drona();
}

void scena::animuj_lot_drona(PzG::LaczeDoGNUPlota lacze,unsigned int numer_drona_na_liscie_obiektow, dron &dron_poczatkowy){

 double kat_wznoszenia_w_st, dlugosc_lotu;
 dron dron_rysowany;
 Wektor3D srodek_smigla,srodek_rysowanego;
 std::string nazwa_pliku="plik";
 std::string numer_na_string;
 numer_na_string=std::to_string(numer_drona_na_liscie_obiektow);
 nazwa_pliku+=numer_na_string;
 nazwa_pliku+=".dat";


 

    std::cout<< "Podaj dlugosc lotu drona" << std::endl;
    std::cin >> dlugosc_lotu;
     while(std::cin.fail()){
            std::cout << "nie podano liczby typu double\n";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cin>>dlugosc_lotu;
        }
    std::cout<< "Podaj kat wznoszenia (dodatni) lub opadania (ujemny)" << std::endl;
    std::cin >> kat_wznoszenia_w_st;
    while(std::cin.fail() || kat_wznoszenia_w_st<=-90 || kat_wznoszenia_w_st>=90){
            std::cout << "nie podano liczby typu double lub kat spoza zakresu\n";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cin>>kat_wznoszenia_w_st;
        }

        dron_rysowany=dron_poczatkowy;
        srodek_rysowanego=dron_rysowany.get_korpus().znajdz_srodek();
        srodek_rysowanego[2]+=(static_cast<double>(Z_SMIGLA))/2;

    if(czy_kolizja(numer_drona_na_liscie_obiektow,srodek_rysowanego)){
            std::cout<<"nastapila kolizja!"<<std::endl;
            dron_rysowany.obroc_drona(180);
            dron_rysowany.rusz_drona(dlugosc_lotu/LICZBA_KLATEK, -1*kat_wznoszenia_w_st);
            dron_rysowany.obroc_drona(180);
    }

    for(int indeks=0;indeks<=LICZBA_KLATEK
     && !czy_kolizja(numer_drona_na_liscie_obiektow,srodek_rysowanego);indeks++){
        dron_rysowany=dron_poczatkowy;
        dron_rysowany.rusz_drona(dlugosc_lotu*indeks/LICZBA_KLATEK, kat_wznoszenia_w_st);
            for(int numer_smigla=0; numer_smigla<ILOSC_SMIGIEL;numer_smigla++){
                srodek_smigla=dron_rysowany.get_smigla(numer_smigla).znajdz_srodek();
                dron_rysowany.set_smigla(numer_smigla).obrot_wokol_wlasnej_osi(srodek_smigla, KAT_OBROTU_WIRNIKOW*indeks/LICZBA_KLATEK);
            }


        //zeby zawsze do kolizji sprawdzac nowe polozenie
        srodek_rysowanego=dron_rysowany.get_korpus().znajdz_srodek();
        srodek_rysowanego[2]+=(static_cast<double>(Z_SMIGLA))/2;

        if(czy_kolizja(numer_drona_na_liscie_obiektow,srodek_rysowanego)){
            std::cout<<"nastapila kolizja!"<<std::endl;
            dron_rysowany.obroc_drona(180);
            dron_rysowany.rusz_drona(dlugosc_lotu/LICZBA_KLATEK, -1*kat_wznoszenia_w_st);
            dron_rysowany.obroc_drona(180);
        }


        if (!dron_rysowany.ZapisWspolrzednychDoPliku(nazwa_pliku))
              std::cout<<"liczba argumentow funkcji zapis_wspolrzednych_do_pliku==0";
        lacze.Rysuj(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku
        usleep(20000);
        
    }
    std::cin.ignore(100000, '\n');
    dron_poczatkowy=dron_rysowany;

    dron_rysowany.usun_drona();

}

