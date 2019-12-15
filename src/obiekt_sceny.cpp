#include "obiekt_sceny.hh"



unsigned int obiekt_sceny::utworzonych_obiektow=0;
unsigned int obiekt_sceny::aktualnych_obiektow=0;

unsigned int obiekt_sceny::get_utworzonych_obiektow(){return utworzonych_obiektow;}
unsigned int obiekt_sceny::get_aktualnych_obiektow(){return aktualnych_obiektow;}