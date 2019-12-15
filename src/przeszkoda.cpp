#include "przeszkoda.hh"



void przeszkoda_pr::ZapisWspolrzednychDoStrumienia( std::ostream&      StrmWy){

  StrmWy << std::setw(16) << std::fixed << std::setprecision(10) << *this;

}



bool przeszkoda_pr::ZapisWspolrzednychDoPliku( std::string  sNazwaPliku){
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

przeszkoda_pr::przeszkoda_pr(Wektor3D srodek){

 przeszkoda.stworz_prostopadloscian_o_srodku(srodek);
 rodzaj_obiektu='p';
 utworzonych_obiektow++;
 aktualnych_obiektow++;

}

przeszkoda_pr::przeszkoda_pr(Wektor3D srodek, double dlugosc_x,
      double dlugosc_y, double dlugosc_z){
        rodzaj_obiektu='p';
        utworzonych_obiektow++;
        aktualnych_obiektow++;
        przeszkoda.stworz_prostopadloscian_o_srodku(srodek, dlugosc_x, dlugosc_y, dlugosc_z);
}

przeszkoda_pr::przeszkoda_pr(const przeszkoda_pr &kopiowana){
    utworzonych_obiektow++;
    aktualnych_obiektow++;
    for(unsigned int indeks=0; indeks<FIGURA; indeks++){
        przeszkoda[indeks]=kopiowana[indeks];
    }
}

std::ostream& operator << ( std::ostream       &Strm, 
                            const przeszkoda_pr    &Pr
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
