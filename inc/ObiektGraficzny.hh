#ifndef OBIEKTGRAFICZNY_HH
#define OBIEKTGRAFICZNY_HH

/*!
 * \file
 * \brief Definicja klasy ObiektGraficzny
 *
 * Plik zawiera definicję klasy ObiektGraficzny.
 */

#include <iostream>
#include <vector>
#include <string>
#include "Wektor2D.hh"
#include "API.hh"

/*!
 * \brief Modeluje obiekt, który ma swoją reprezentację graficzną
 *
 * Modeluje obiekt, który ma swoją reprezentację graficzną
 * w postaci łamanej. Może ona być łamaną zamkniętą w postaci
 * wieloboku lub otwartą. Ilość jej wierzchołków nie jest jawnie
 * ograniczona. Jedynym ograniczeniem jest dostępność pamięci
 * komputera.
 */
class ObiektGraficzny {
  /*!
   * \brief Współrzędne pozycji obiektu
   *
   *  Zawiera współrzędne punktu względem, którego podane są
   *  współrzędne punktów obrysu obiektu.
   */
   protected:
   Wektor2D   _PolozenieObiektu;
  /*!
   * \brief Tablica wierzchołków
   *
   *
   */
   std::vector<Wektor2D> _TabWierz;

  /*!
   * \brief Wskaznik na API, które obslguje LaczeDoGNUPlota
   *
   */
    API * wskAPI;

    /*!
     * \brief indeks aktualnie rysowanego obiektu
     */
    int _RysunekID;

  public:


  /*!
   * \brief Metoda zapisuje do pliku współrzędne wierzchołków
   */
   bool ZapiszDoPliku(const char* sNazwaPliku) const;
  /*!
   * \brief Metoda zapisuje do strumienia współrzędne wierzchołków
   */
   bool ZapiszDoStrumienia(std::ostream& StrmWy) const;

  /*!
  * \brief Inicjalizacja współrzędnych wierzchołków
  */
  virtual void InicjalizujKsztalt() = 0;

  /*!
  * \brief Metoda Rysuje lub aktualizuje pozycje obiektu w GNU plocie
  */
  virtual void Rysuj() = 0;

  /*!
  * \brief Konstruktor klasy
  *
  */
  ObiektGraficzny(API* arg) : wskAPI(arg){  }

  /*!
  * \brief Metoda przesuwa obiekt o podany wektor
  *
  */
 void PrzesunOWektor(double x, double y);

 virtual std::string nazwaKlasy(){
   return "Obiekt Graficzny";
 }

};


#endif
