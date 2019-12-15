#include "wirnik.hh"
#include "Macierz.hh"
#include "Wektor.hh"
#include "Macierz3x3.hh"
#include "Wektor3D.hh"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>

#define GRANIASTOSLUP 12
#define DL_BOKU 8
#define DL_Z 4

void gran_szesc::stworz_wirnik_o_srodku(Wektor3D srodek){

Wektor3D tmp, dlugosc_z, nastepny_bok;
double tmp_z, tmp_a;
    for(int wierzcholek=0;wierzcholek<GRANIASTOSLUP;wierzcholek++){
    bryla.push_back(tmp);
    }


    tmp_z = DL_Z;
    dlugosc_z[2]=tmp_z;

    tmp_a=DL_BOKU;
    nastepny_bok[0]=tmp_a;

    bryla[0]=srodek-dlugosc_z/2+nastepny_bok;
    bryla[6]=srodek-dlugosc_z/2-nastepny_bok;


    nastepny_bok[0]=-tmp_a/2;
    nastepny_bok[1]=tmp_a*sqrt(3)/2;

    bryla[2]=bryla[0]+nastepny_bok;
    bryla[8]=bryla[6]-nastepny_bok;

    nastepny_bok[0]=-tmp_a;
    nastepny_bok[1]=0;

    bryla[4]=bryla[2]+nastepny_bok;
    bryla[10]=bryla[8]-nastepny_bok;


    for(int wierzcholek=0;wierzcholek<GRANIASTOSLUP;wierzcholek=wierzcholek+2){
        bryla[wierzcholek+1]=bryla[wierzcholek]+dlugosc_z;
    }
}

Wektor3D gran_szesc::znajdz_srodek(){

 Wektor3D wynik;
 
    wynik=bryla[0]+(bryla[7]-bryla[0])/2;
    

return wynik;
}

std::ostream& operator << ( std::ostream       &Strm, 
                            const gran_szesc    &wirnik
                          ){

int i;

    for(i=0;i<GRANIASTOSLUP;i=i+2){
        Strm << wirnik[i] << wirnik[i+1]<<std::endl;
    }

    Strm << wirnik[0] << wirnik[1] << std::endl; // jeszcze raz podajemy 1szy odcinek
    Strm << std::endl; // zeby gnuplot sie nie pogubil (koniec rysowania scian)

    Strm<<wirnik[1]<<wirnik[3]<<std::endl
        <<wirnik[7]<<wirnik[5]<<std::endl
        <<wirnik[9]<<wirnik[11]<<std::endl
        <<wirnik[3]<<wirnik[1]<<std::endl
        <<std::endl<<std::endl;

    Strm<<wirnik[0]<<wirnik[2]<<std::endl
        <<wirnik[6]<<wirnik[4]<<std::endl
        <<wirnik[8]<<wirnik[10]<<std::endl
        <<wirnik[2]<<wirnik[0]<<std::endl
        <<std::endl<<std::endl;

return Strm;
}