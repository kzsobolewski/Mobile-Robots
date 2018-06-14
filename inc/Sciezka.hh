#ifndef SCIEZKA_HH
#define SCIEZKA_HH
/*!
 * \file
 * \brief Definicja klasy Sciezka
 *
 * Plik zawiera definicję klasy Sciezka.
 */

#include <vector>
#include <math.h>
#include <unistd.h>
#include "ObiektGraficzny.hh"
#include "Wektor2D.hh"
#include "SWektor.hh"
#include "API.hh"

/*!
 * \brief Modeluje obiekt Sciezka
 *
 *  Modeluja obiekt, który jest reprezentowany jako linia,
 *  ciągnąca się za ruchem robota.
 *
 */
class Sciezka : public ObiektGraficzny{

public:
  /*!
   * \brief Konstruktor klasy
   *
   * Przyjmuje wskaznik na API do obsługi LaczeDoGNUPlota,
   * zeruje pole indeksu rysunku _RysunekID
   */
  Sciezka(API * arg) : ObiektGraficzny( arg ) {
    _RysunekID = 0;
  }

  /*!
  * \brief Dodaje Wektor2D do tablicy swoich wierzchołków
  */
  void DodajWierzcholek(Wektor2D W);

  /*!
  * \brief Rysuje sciezke na GNU Plocie
  */
  void Rysuj();

  /*!
  * \brief Wymazuje cala sciezke
  */
  void Resetuj();

  /*!
  * \brief Pusta metoda, potrzebna do spojnosci programu
  *
  */
  void InicjalizujKsztalt(){}

  virtual std::string nazwaKlasy(){
    return "Sciezka";
  }
};





#endif
