#include "Prostopadloscian.hh"
#include "Macierz.hh"
#include "Wektor.hh"
#include "Macierz3x3.hh"
#include "Wektor3D.hh"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>



void Prostopadloscian::stworz_prostopadloscian_o_srodku(Wektor3D srodek){

 Wektor3D tmp, dlugosc_x, dlugosc_y, dlugosc_z, wektor_polowkowy;
 double tmp_x, tmp_y, tmp_z;
    for(int wierzcholek=0;wierzcholek<PROSTOPAD;wierzcholek++){
    bryla.push_back(tmp);
    }

    tmp_x = DL_X;
    tmp_y = DL_Y;
    tmp_z = DL_Z;

    dlugosc_x[0]=tmp_x;
    dlugosc_y[1]=tmp_y;
    dlugosc_z[2]=tmp_z;
    wektor_polowkowy[0]=tmp_x/2;
    wektor_polowkowy[1]=tmp_y/2;
    wektor_polowkowy[2]=tmp_z/2;

    bryla[0]=srodek-wektor_polowkowy;
    bryla[2]=bryla[0]+dlugosc_x;
    bryla[4]=bryla[2]+dlugosc_y;
    bryla[6]=bryla[0]+dlugosc_y;

    for(int wierzcholek=0;wierzcholek<PROSTOPAD;wierzcholek=wierzcholek+2){
        bryla[wierzcholek+1]=bryla[wierzcholek]+dlugosc_z;
    }

}


void Prostopadloscian::stworz_prostopadloscian_o_srodku(
                Wektor3D srodek, double dlugosc_x, double dlugosc_y, double dlugosc_z){

 Wektor3D tmp, tmp_x, tmp_y, tmp_z, wektor_polowkowy;
    for(int wierzcholek=0;wierzcholek<PROSTOPAD;wierzcholek++){
    bryla.push_back(tmp);
    }



    tmp_x[0]=dlugosc_x;
    tmp_y[1]=dlugosc_y;
    tmp_z[2]=dlugosc_z;
    wektor_polowkowy[0]=dlugosc_x/2;
    wektor_polowkowy[1]=dlugosc_y/2;
    wektor_polowkowy[2]=dlugosc_z/2;

    bryla[0]=srodek-wektor_polowkowy;
    bryla[2]=bryla[0]+tmp_x;
    bryla[4]=bryla[2]+tmp_y;
    bryla[6]=bryla[0]+tmp_y;

    for(int wierzcholek=0;wierzcholek<PROSTOPAD;wierzcholek=wierzcholek+2){
        bryla[wierzcholek+1]=bryla[wierzcholek]+tmp_z;
    }

}

std::ostream& operator << ( std::ostream       &Strm, 
                            const Prostopadloscian    &Pr
                          ){

 int i;

    for(i=0;i<FIGURA;i=i+2){
        Strm << Pr[i] << Pr [i+1]<<std::endl;
    }

    Strm << Pr[0] << Pr[1] << std::endl << std::endl;
    //zeby narysowac gnuplotem zamknieta bryle
    Strm << Pr[1] << Pr[3] << std::endl;
    Strm << Pr[7] << Pr[5] << std::endl << std::endl;
    Strm << Pr[0] << Pr[2] << std::endl;
    Strm << Pr[6] << Pr[4];

    
 return Strm;
}

Wektor3D Prostopadloscian::znajdz_srodek(){

 Wektor3D wynik;
 
    wynik=bryla[0]+(bryla[5]-bryla[0])/2;
    

return wynik;
}

//w razie gdyby kiedys sie przydalo takie rozwiazanie
//double Prostopadloscian::znajdz_kat_patrzenia(){
//
// double wynik, delta_x, delta_y;
//
//    delta_x=bryla[2][0]-bryla[1][0];
//    delta_y=bryla[2][1]-bryla[1][1];
//
//    wynik=atan(-delta_x/delta_y);
//
// return wynik;
//}





