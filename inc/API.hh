#ifndef API_HH
#define API_HH

/*!
 * \file
 * \brief Definicja klasy API i APIGnuPlot
 *
 * Plik zawiera definicje klasy API i APIGnuPlot, potrzebną do obsługi
 * LaczeDoGNUPlota
 */

#include "Wektor2D.hh"
#include "lacze_do_gnuplota.hh"
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>

//uzywane funkcje z biblioteki standardowej
using std::vector;
using std::ofstream;
using std::cerr;
using std::cout;
using std::endl;
using std::stringstream;

/*!
 * \brief interfejs dla implementacji rysowania dla roznych platform
 *
 */
class API {
public:
  virtual int rysuj_punkt(const Wektor2D & pt) = 0;
  virtual int rysuj_linie(const Wektor2D & pt1, const Wektor2D & pt2) = 0;
  virtual int rysuj_luk(const Wektor2D & pt1, double promien, double kat) = 0;
  virtual int rysuj_wielokat(const vector<Wektor2D> & pts) = 0;
  virtual int rysuj_okrag(const Wektor2D & pt,double promien) = 0;
  virtual void wymaz_ksztalt(int indeks) = 0;
};

/*!
 * \brief implementacja rysowania w GNU plocie za pomoca lacza do GNU plota
 *
 */
class APIGnuPlot : public API {
  PzG::LaczeDoGNUPlota Lacze;
  // zmienne potrzebne do okreslania jakie pliki z danymi maja byc brane pod uwage
  int l_stworzone_ob;
  vector<int> istniejace_obiekty;
public:
  //konstruktor z argumentami okreslajacymi wielkosc sceny
  APIGnuPlot(double minX,double minY,double maxX,double maxY);
  //implementacje funkcji z interfejsu - zwracany int okresla jakie id zostalo przydzielone ksztaltowi
  int rysuj_punkt(const Wektor2D & pt);
  int rysuj_linie(const Wektor2D & pt1, const Wektor2D & pt2);
  int rysuj_luk(const Wektor2D & pt1, double promien, double kat);
  int rysuj_wielokat(const vector<Wektor2D> & pts);
  int rysuj_okrag(const Wektor2D & pt,double promien);
  void wymaz_ksztalt(int indeks);
};


#endif
