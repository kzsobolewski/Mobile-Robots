/*!
 * \file
 * \brief Definicja klasy SMacierz
 *
 * Zawiera definicje metod klasy SMacierz i jej metod
 */

#ifndef SMACIERZ_HH
#define SMACIERZ_HH

#include "rozmiar.hh"
#include "SWektor.hh"
#include <iostream>



template <typename STyp, int SWymiar>
/*!
* \brief Klasa Macierz implementuje tablice wektorow, tworzac macierz kwadratowa.
*
*/
class SMacierz {

  SWektor<STyp,SWymiar> tabMac[ROZMIAR];  // tablica obiektow klasy wektor o zadanym rozmiarze
public:

/*!
 * Metoda transponujaca Macierz.
 * WYJSCIE: transponowana Macierz
 */
SMacierz<STyp,SWymiar> trans() const{
  SMacierz<STyp,SWymiar> wynik;
  for(int i = 0; i < SWymiar; i++)
    for(int j = 0 ; j <SWymiar; j++)
      wynik[i][j] = tabMac[j][i];
  return wynik;
}

/*!
 * Metoda liczaca wyznacznik macierzy 3x3
 * WYJSCIE: zmienna double bedaca wyznacznikiem macierzy.
 */
STyp wyznacznik(int rozmiar = SWymiar) const {
  STyp wynik;
  wynik = 0;
  if(rozmiar == 2) return tabMac[0][0]*tabMac[1][1] - tabMac[0][1]*tabMac[1][0];

  for(int i =0; i<rozmiar; i++){
    if(i%2) wynik = wynik + tabMac[0][i] * this->macierzDopelnien(i).wyznacznik(rozmiar-1);
    else    wynik = wynik - tabMac[0][i] * this->macierzDopelnien(i).wyznacznik(rozmiar-1);
  }
  return wynik;
}

SMacierz<STyp, SWymiar> macierzDopelnien(int indeks) const{
  SMacierz<STyp, SWymiar> Wynik;
  for(int i =1 ; i<SWymiar; i++)
    for(int j =0, k=0; j<SWymiar; j++, k++ ){
      if(j != indeks) Wynik[i-1][k]= tabMac[i][j];
      else k--;
    }
  return Wynik;
}

/*!
 * Przeciazenie operatora '*', mnozy macierz przez wektor.
 * WEJSCIE: obiekt typu macierz i wektor.
 * WYJSCIE: wektor bedacy wynikiem mnozenia.
 */
SWektor<STyp,SWymiar> operator * (SWektor<STyp,SWymiar> W) const{
  SWektor<STyp, SWymiar> wynik;
  for(int i = 0 ; i<SWymiar; i++)
    wynik[i] = tabMac[i]*W;
  return wynik;
}


/*!
 * Przeciazenie operatora '*', mnozy macierz przez liczbe.
 * WEJSCIE: obiekt typu macierz oraz zmienna double bedacy mnoznikiem
 * WYJSCIE: macierz bedaca wynikiem mnozenia.
 */
SMacierz<STyp,SWymiar> operator * (double mnoz) const{
  SMacierz<STyp, SWymiar> wynik;
  for(int i =0; i<SWymiar;i++){
    wynik[i] = tabMac[i] * mnoz;
  }
  return wynik;
}

/*!
 * Przeciazenie operatora '/', dzieli macierz przez liczbe.
 * WEJSCIE: obiekt typu macierz oraz zmienna double bedacy dzielnikiem.
 * WYJSCIE: macierz bedaca wynikiem dzielenia.
 */
SMacierz<STyp,SWymiar> operator / (STyp dziel) const{
  SMacierz<STyp, SWymiar> wynik;
  for(int i = 0; i<SWymiar; i++){
    wynik[i] = tabMac[i] / dziel;
  }
  return wynik;
}

/*!
 * Przeciazenie operatora '[]', daje dostep do pol obiektu oraz ulatwia zapis.
 * WEJSCIE: obiekt klasy macierz oraz indeks
 * WYJSCIE: Wektor wybrany z pola obiektu
 */
SWektor<STyp,SWymiar> & operator[] (int indeks){
  return tabMac[indeks];
}

/*!
 * Przeciazenie operatora '[]' dla stalych obiektow.
 * WEJSCIE: obiekt klasy SMacierz<STyp,SWymiar> oraz indeks
 * WYJSCIE: Wektor wybrany z pola obiektu
 */
const SWektor<STyp,SWymiar> & operator[] (int indeks) const{
  return tabMac[indeks];
}
//double wyznacznik() const;
//Macierz odwroc() const;
};

/*
 * Przeciazenie operatora >>, pozwala na zapis liczb do macierzy
 */
 template <typename STyp, int SWymiar>
std::istream& operator >> (std::istream &Strm, SMacierz<STyp,SWymiar> &Mac){
for(int i =0; i<SWymiar; i++)
  Strm >> Mac[i];
return Strm;
}

/*!
 * Przeciazenie operatora <<, pozwala wyswietlic cala macierz
 */
template <typename STyp, int SWymiar>
std::ostream& operator << (std::ostream &Strm, const SMacierz<STyp,SWymiar> Mac){
  for(int i=0; i<SWymiar; i++){
    Strm << Mac[i] << "\n";
  }
  return Strm;
}





#endif
