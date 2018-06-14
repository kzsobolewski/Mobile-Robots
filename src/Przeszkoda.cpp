#include "Przeszkoda.hh"


void Przeszkoda::Rysuj(){
  if(_RysunekID)
    wskAPI -> wymaz_ksztalt(_RysunekID);
  _RysunekID = wskAPI -> rysuj_wielokat( _TabWierz );
}

void Przeszkoda::InicjalizujKsztalt(){
  Wektor2D W[4];

  W[0][0] =  _PolozenieObiektu[0] ;
  W[0][1] =  _PolozenieObiektu[1] ;

  W[1][0] =  _PolozenieObiektu[0] + _DlugoscBokuX ;
  W[1][1] =  _PolozenieObiektu[1] ;

  W[2][0] =  _PolozenieObiektu[0] + _DlugoscBokuX ;
  W[2][1] =  _PolozenieObiektu[1] + _DlugoscBokuY ;

  W[3][0] =  _PolozenieObiektu[0] ;
  W[3][1] =  _PolozenieObiektu[1] + _DlugoscBokuY;


  _TabWierz.push_back(W[0]);
  _TabWierz.push_back(W[1]);
  _TabWierz.push_back(W[2]);
  _TabWierz.push_back(W[3]);
  _TabWierz.push_back(W[0]);
}


Wektor2D Przeszkoda::zwrocZakresX() const{
  Wektor2D wynik;
  wynik[0] = _PolozenieObiektu[0] - HITBOX ;
  wynik[1] = _PolozenieObiektu[0] + _DlugoscBokuX + HITBOX ;
  return wynik;
}

Wektor2D Przeszkoda::zwrocZakresY() const{
  Wektor2D wynik;
  wynik[0] = _PolozenieObiektu[1] - HITBOX ;
  wynik[1] = _PolozenieObiektu[1] + _DlugoscBokuX + HITBOX ;
  return wynik;
}
