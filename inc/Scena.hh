/*!
 * \file
 * \brief Definicja klasy Scena
 *
 * Plik zawiera definicję klasy Scena.
 */

#ifndef SCENA_HH
#define SCENA_HH
#include <vector>
#include <math.h>
#include <unistd.h>
#include <iostream>
#include <memory>
#include <list>
#include "API.hh"
#include "ObiektGraficzny.hh"
#include "Robot.hh"
#include "Przeszkoda.hh"
#include "Wektor2D.hh"
#include "SWektor.hh"
#include "Fabryka.hh"




using namespace std;


/*!
 * \brief Modeluje obiekt Scena
 *
 * Modeluje obiekt, który zawiera elementy wyswietlane w GNU plocie
 *
 */
class Scena{
  /*!
   * \brief  wskaznik na APIGnuPlot
   */
  APIGnuPlot * api;

  /*!
   * \brief wskaznik na obiekt klasy Robot
   */
  shared_ptr<Robot> R;
  /*!
   * \brief lista wskaznikow wskazujacych na kazdego robota
   */
  list< shared_ptr<Robot> > Lista_robotow;
  /*!
   * \brief lista wskaznikow wskazujacych na kazdy obiekt graficzny
   */
  list< shared_ptr<ObiektGraficzny> > Lista_obiektow;

  /*!
   * \brief Wektor pozycji całej sceny
   */
  Wektor2D Pozycja;

public:

  /*!
   * \brief Przesuwa scene o zadany wektor
   */
void PrzesunScene(double X, double Y);

/*!
 * \brief Konstruktor Sceny
 */
Scena();

/*!
 * \brief  Wyswietla menu do obsługi programu
 */
void wyswietlMenu();

/*!
 * \brief Metoda dzięki której użytkownik komunikuje się z programem
 */
void MenuSceny();

/*!
 * \brief Metoda dodaje robota do planszy
 */
void dodajRobota(double wspX, double wspY);

/*!
 * \brief Metoda dodaje przeszkode do planszy
 */
void dodajPrzeszkode(
  double wspX, double wspY, double bokX, double bokY);

/*!
 * \brief Metoda dzięki której użytkownik wybiera robota ktorych chce sterowac
 */
void wyborRobota(int wybor);


/*!
 * \brief Metoda dodaje kilka wartosci aby nie bylo pusto :)
 */
void dodajKilkaObiekow();


/*!
* \brief Metoda wyswietla liste robotow
*/
void pokazListe();
};

#endif
