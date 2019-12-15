#include "bryla.hh"
#include "Macierz.hh"
#include "Wektor.hh"
#include "Macierz3x3.hh"
#include "Wektor3D.hh"
#include <iostream>
#include <iomanip>
#include <fstream>



void obiekt_geometryczny::na_wprost(double kat_patrzenia_w_st,double kat_wznoszenia_w_st, double dlugosc_lotu){

 Wektor<WYMIAR> przesuniecie;
 //double kat_wznoszenia, dlugosc_lotu;
 unsigned int ilosc_wierzcholkow=0;
 
    kat_wznoszenia_w_st=stopnie_na_radiany(kat_wznoszenia_w_st);
    przesuniecie[2]=sin(kat_wznoszenia_w_st)*dlugosc_lotu;

    dlugosc_lotu=dlugosc_lotu*cos(kat_wznoszenia_w_st);
    kat_patrzenia_w_st=stopnie_na_radiany(kat_patrzenia_w_st);
    przesuniecie[0]=cos(kat_patrzenia_w_st)*dlugosc_lotu;
    przesuniecie[1]=sin(kat_patrzenia_w_st)*dlugosc_lotu;

    ilosc_wierzcholkow=bryla.size();

    for(unsigned int indeks=0; indeks<ilosc_wierzcholkow; indeks++)
        bryla[indeks] += przesuniecie;

}

void obiekt_geometryczny::obrot_wokol_wlasnej_osi(Wektor3D const &srodek, double const alfa){
    
 obiekt_geometryczny tmp;
 Macierz3x3 kat;
 unsigned int ilosc_wierzcholkow=0;

    kat=tmp.uzupelnianie(alfa);
    ilosc_wierzcholkow=bryla.size();
    //przesuwa bryle tak by jej srodek byl srodkiem ukladu wspolrzednych
    for(unsigned int indeks=0; indeks<ilosc_wierzcholkow;indeks++){
        bryla[indeks] -= srodek;
    }

    for(unsigned int indeks=0;indeks<ilosc_wierzcholkow;indeks++){
            bryla[indeks]=kat*bryla[indeks];
    }

    //przesuwa bryle na jej poprzednie miejsce jednak obrocona
    for(unsigned int indeks=0; indeks<ilosc_wierzcholkow;indeks++){
        bryla[indeks] += srodek;
    }
}

Macierz3x3 obiekt_geometryczny::uzupelnianie(double const alfa){

Macierz3x3 macierz;
double radian=(stopnie_na_radiany(alfa));

        macierz[0][0]= cos(radian);
        macierz[0][1]= -sin(radian);
        macierz[0][2]= 0;
        macierz[1][0]= sin(radian);
        macierz[1][1]= cos(radian);
        macierz[1][2]= 0;
        macierz[2][0]= 0;
        macierz[2][1]= 0;
        macierz[2][2]= 1;

return macierz;
}

void obiekt_geometryczny::usun_bryle(){

 unsigned int ilosc_wierzcholkow;

    ilosc_wierzcholkow=bryla.size();
    for(unsigned int indeks=0;indeks<ilosc_wierzcholkow;indeks++){
        bryla.pop_back();
    }

}