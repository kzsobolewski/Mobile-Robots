/*!
 * \file
 * \brief Zawiera definicje metod klasy ObiektGraficzny
 *
 * Zawiera definicje metod klasy ObiektGraficzny
 * wraz z ich opisem.
 */

#include <fstream>
#include "ObiektGraficzny.hh"


using namespace std;


/*!
 * Zapisuje do strumienia współrzędne globalne wierzchołków
 * obrysu obiektu.
 * \param[in,out] - strumień, do którego wpisane zostałe współrzędne
 *                  wierzchołków.
 * \retval true - gdy operacja powiodła się,
 * \retval false - w przypadku przeciwnym.
 */
bool ObiektGraficzny::ZapiszDoStrumienia(std::ostream& StrmWy) const
{
  Wektor2D  W_glob;

  for (const Wektor2D&  W_lok : _TabWierz) {
    W_glob = W_lok + _PolozenieObiektu;
    StrmWy << W_glob << endl;
  }
  return !StrmWy.fail();
}


/*!
 * Zapisuje do pliku współrzędne globalne wierzchołków
 * obrysu obiektu.
 * \param[in,out] - strumień, do którego wpisane zostałe współrzędne
 *                  wierzchołków.
 * \retval true - gdy operacja powiodła się,
 * \retval false - w przypadku przeciwnym.
 */
bool ObiektGraficzny::ZapiszDoPliku(const char* sNazwaPliku) const
{
  ofstream   StrmWy(sNazwaPliku);

  if (!StrmWy.is_open()) {
    cerr << endl
         << "Blad: Otwarcie do zapisu pliku '" << sNazwaPliku
	 << "' nie powiodlo sie." << endl
	 << endl;
    return false;
  }
  return ZapiszDoStrumienia(StrmWy);
}


/*!
 * Metoda przesuwa wszytskie wierzchołki o
 *
 * \param[in] 2 liczby tworzace Wektor2D
 *
 *
 *
 */
void ObiektGraficzny::PrzesunOWektor(double x, double y){
    Wektor2D wektorPrzesuniecia;
    wektorPrzesuniecia[0] = x;
    wektorPrzesuniecia[1] = y;

    _PolozenieObiektu = _PolozenieObiektu + wektorPrzesuniecia;

    for(unsigned int i = 0; i < _TabWierz.size(); i++){
      _TabWierz[i] = _TabWierz[i] + wektorPrzesuniecia;
    }
}
