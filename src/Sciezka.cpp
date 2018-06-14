/*!
 * \file
 * \brief Zawiera definicje metod klasy Sciezka
 *
 * Zawiera definicje metod klasy Sciezka
 * wraz z ich opisem.
 */
#include "Sciezka.hh"

/*! Metoda dodaje  podany wektor do swojej tablicy wierzchołków _TabWierz
 *
 *
 * \param[in] W - wektor dodany do tablicy
 *
 */
void Sciezka::DodajWierzcholek(Wektor2D W){
  _TabWierz.push_back(W);
}

/*!
 *  Metoda wymazuje poprzedni rysunek i rysuje zaktualizowaną wersję ścieżki
 *
 *
 */
void Sciezka::Rysuj(){
  if(_RysunekID)
    wskAPI -> wymaz_ksztalt(_RysunekID);
  _RysunekID = wskAPI -> rysuj_wielokat( _TabWierz );
}

/*! Metoda wymazuje wszystkie wierzchołki obiektu  
 *
 *
 */
void Sciezka::Resetuj(){
  _TabWierz.clear();
  wskAPI -> wymaz_ksztalt(_RysunekID);
}
