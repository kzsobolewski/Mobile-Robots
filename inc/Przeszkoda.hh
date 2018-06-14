#ifndef PRZESZKODA_HH
#define PRZESZKODA_HH
/*!
 * \file
 * \brief Definicja klasy Przeszkoda
 *
 * Plik zawiera definicję klasy Przeszkoda.
 */

#include <vector>
#include <math.h>
#include <unistd.h>
#include "ObiektGraficzny.hh"
#include "Wektor2D.hh"
#include "SWektor.hh"
#include "API.hh"

#define HITBOX 26

/*!
 * \brief Modeluje obiekt Sciezka
 *
 *  Modeluja obiekt, który jest reprezentowany jako linia,
 *  ciągnąca się za ruchem robota.
 *
 */
class Przeszkoda : public ObiektGraficzny{

  double _DlugoscBokuX;
  double _DlugoscBokuY;

public:
  /*!
   * \brief Konstruktor klasy
   *
   * Przyjmuje wskaznik na API do obsługi LaczeDoGNUPlota,
   * zeruje pole indeksu rysunku _RysunekID
   */
  Przeszkoda(API * arg, double wspX, double wspY, double bokX, double bokY) : ObiektGraficzny( arg ) {
    _PolozenieObiektu[0] = wspX;
    _PolozenieObiektu[1] = wspY;
    _DlugoscBokuX = bokX;
    _DlugoscBokuY = bokY;
    _RysunekID = 0;
    InicjalizujKsztalt();
    Rysuj();
  }


  /*!
  * \brief Rysuje przeszkode na GNU Plocie
  */
  void Rysuj();

  void InicjalizujKsztalt();

  virtual std::string nazwaKlasy(){
    return "Przeszkoda";
  }

  Wektor2D zwrocZakresX() const;

  Wektor2D zwrocZakresY() const;



};





#endif
