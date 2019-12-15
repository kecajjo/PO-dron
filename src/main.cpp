#include <iostream>
#include <iomanip>
#include <fstream>
#include "Wektor3D.hh"
#include "Macierz3x3.hh"
#include "Prostopadloscian.hh"
#include "lacze_do_gnuplota.hh"
#include "menu.hh"
#include "bryla.hh"



int main(){

 singleton *fabryka=singleton::stworz_fabryke();
  menu(*fabryka);


  std::cout << "ilosc aktualnych obiektow typu Wektor3D:"
    << Wektor3D::get_aktualnych() << std::endl
    << "ilosc utworzonych obiektow typu Wektor3D:"
    << Wektor3D::get_utworzonych() << std::endl;

  std::cout << "ilosc aktualnych obiektow typu obiekt_geometryczny:"
    << obiekt_sceny::get_aktualnych_obiektow() << std::endl
    << "ilosc utworzonych obiektow typu obiekt_geometryczny:"
    << obiekt_sceny::get_utworzonych_obiektow() << std::endl;
   
    //dr.usun_drona();

  //std::cout << "dron usuniety!" << std::endl;

  fabryka->set_scena().set_lista_dronow().clear();
  fabryka->set_scena().set_lista_obiektow().clear();

  std::cout << "ilosc aktualnych obiektow typu Wektor3D:"
    << Wektor3D::get_aktualnych() << std::endl
    << "ilosc aktualnych obiektow typu obiekt_geometryczny:"
    << obiekt_sceny::get_aktualnych_obiektow() << std::endl;


  return 0;
}
