/*!
 * \file
 * \brief Definicja klasy SWektor
 *
 * Plik zawiera definicję szablonu klasy SWektor
 */

#ifndef SWEKTOR_HH
#define SWEKTOR_HH


#include <iostream>
#include <iomanip>
#include <math.h>


template <typename STyp, int SWymiar>


/*!
 * \brief Szablon klasy implementuje wektor o dowolnym typie i wielkości
 *
 */
class SWektor  {
    STyp  _Wsp[SWymiar];

  public:
    static int _StworzoneObiekty ;

    SWektor() {
       for (STyp &Wsp: _Wsp)
          Wsp = 0;
       _StworzoneObiekty++;
      }



    STyp  operator [] (unsigned int Ind) const { return _Wsp[Ind]; }
    STyp &operator [] (unsigned int Ind)       { return _Wsp[Ind]; }

    SWektor<STyp,SWymiar> operator - (const SWektor<STyp,SWymiar> &Odjemnik) const;
    SWektor<STyp,SWymiar> operator * (double Mnoznik) const;


    STyp operator * (const SWektor<STyp, SWymiar> W1) const;
    SWektor<STyp, SWymiar> operator + (const SWektor<STyp, SWymiar> &W1) const;
    SWektor<STyp, SWymiar> operator / (STyp dziel) const;
    STyp dlugosc() const{
      STyp wynik;
      wynik =0;
      for(int i=0; i<SWymiar; i++)
        wynik = wynik + _Wsp[i]*_Wsp[i];
      return sqrt(wynik);
    }
    STyp odleglosc(SWektor<STyp, 2> W2){
      return sqrt(pow( W2[0] - _Wsp[0], 2 ) + pow( W2[1] - _Wsp[1] ,2 ));
    }


};

template <typename STyp, int SWymiar>
int SWektor<STyp,SWymiar>::_StworzoneObiekty = 0;

template <typename STyp, int SWymiar>
STyp SWektor<STyp,SWymiar>::operator * (const SWektor<STyp,SWymiar> W1) const
{
  STyp wynik = _Wsp[0]*W1[0];
  for(int i=1; i<SWymiar; i++){
    wynik = wynik + (*this)[i]*W1[i];
  }
  return wynik;
}


template <typename STyp, int SWymiar>
SWektor<STyp, SWymiar> SWektor<STyp,SWymiar>::operator / (STyp dziel) const{
  SWektor<STyp, SWymiar> wynik;
  for(int i=0; i<SWymiar;i++)
    wynik[i] = (*this)[i] / dziel;
  return wynik;
}

template <typename STyp, int SWymiar>
SWektor<STyp, SWymiar> SWektor<STyp,SWymiar>::operator + (const SWektor<STyp, SWymiar> & W1) const{
  SWektor<STyp,SWymiar>  Wynik;
  for (unsigned int Ind = 0; Ind < SWymiar; ++Ind) Wynik[Ind] = (*this)[Ind] + W1[Ind];
  return Wynik;
}

template <typename STyp, int SWymiar>
SWektor<STyp,SWymiar> SWektor<STyp,SWymiar>::operator - (const SWektor<STyp,SWymiar> &Odjemnik) const
{
  SWektor<STyp,SWymiar>  Wynik;

  for (unsigned int Ind = 0; Ind < SWymiar; ++Ind) Wynik[Ind] = (*this)[Ind] - Odjemnik[Ind];
  return Wynik;
}


template <typename STyp, int SWymiar>
SWektor<STyp,SWymiar> SWektor<STyp,SWymiar>::operator * (double Mnoznik) const
{
  SWektor<STyp,SWymiar>  Wynik;

  for (unsigned int Ind = 0; Ind < SWymiar; ++Ind) Wynik[Ind] = (*this)[Ind]*Mnoznik;
  return Wynik;
}


template <typename STyp, int SWymiar>
std::ostream& operator << (std::ostream &StrmWyj, const SWektor<STyp,SWymiar> W)
{
  for (unsigned int Ind = 0; Ind < SWymiar; ++Ind) {
    StrmWyj << std::setprecision(2) << "  " << std::fixed<< W[Ind];
  }
  return StrmWyj;
}

template <typename STyp, int SWymiar>
std::istream& operator >> (std::istream &Strm, SWektor<STyp,SWymiar> & W)
{
  for (unsigned int Ind = 0; Ind < SWymiar; ++Ind) {
    Strm >> W[Ind];
  }
  return Strm;
}



#endif
