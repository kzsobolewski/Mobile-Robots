#ifndef ROBOT_HH
#define ROBOT_HH

/*!
 * \file
 * \brief Definicja klasy Robot
 *
 * Plik zawiera definicję klasy Robot.
 */

#include <vector>
#include <list>
#include <math.h>
#include <iostream>
#include <unistd.h>
#include <memory>
#include "ObiektGraficzny.hh"
#include "Wektor2D.hh"
#include "SWektor.hh"
#include "SMacierz.hh"
#include "Macierz2D.hh"
#include "Sciezka.hh"
//#include "Fabryka.hh"
#include "Przeszkoda.hh"
#include "API.hh"

using namespace std;
#define SKOK 5 ///< ilosc na jaka dzieli sie animacje


/*!
 * \brief Modeluje obiekt Robot
 *
 * Modeluje obiekt, który ma swój okreslony kształt w postaci
 * zamkniętej łamanej. Klasa dziedziczy po ObiektGraficzny, rozszerzajac
 * klase o dodatkowe metody interakcji oraz atrybuty opisujace stan obiektu.
 *
 */
class Robot: public ObiektGraficzny{

  /*!
   * \brief Kat pomiedzy przodem robota a osią OX
   */
  double _KatPolozenia;

  /*!
   * \brief czas zawieszaenia programu aby utworzyc zludzenie ruchu
   */
  int _CzasSkoku;


  /*!
   * \brief  Tablica przechowujaca ksztalt robota
   */
  std::vector<Wektor2D> _WzorRobota;

  /*!
   * \brief Sciezka tworzona za robotem
   */
  Sciezka * _SladZaRobotem;





public:

  /*!
  * \brief Konstruktor klasy
  *
  * Przyjmuje wskaznik na API do obsługi LaczeDoGNUPlota, tworzy sciezke
  * oraz inicjalizuje ksztalt robota.
  */
  Robot(API * arg, double wspX, double wspY) : ObiektGraficzny( arg){
    _PolozenieObiektu[0] = wspX;  _PolozenieObiektu[1] = wspY;
    InicjalizujKsztalt();
    _CzasSkoku = 25000;
    _RysunekID = 0;
    _SladZaRobotem = new Sciezka(arg);
    _SladZaRobotem->DodajWierzcholek(_PolozenieObiektu);
    Rysuj();
  }
//friend class Fabryka;

/*!
* \brief Przesuwa robota i sciezke o podany wektor
*/
void PrzesunCalosc(double X, double Y);

/*!
 * \brief Resetuje pozycje robota
 */
void ResetujPozycjeRobota();

/*!
 * \brief Inicjalizuje Ksztalt Obiektu
 */
void  InicjalizujKsztalt();

/*!
 * \brief Rysuje robota i jego sciezke na GNU plocie
 */
void  Rysuj();

/*!
 * \brief Robot jedzie w konkretne miejsce
 */
void  JedzWMiejsce(double x, double y,
          std::list<shared_ptr<ObiektGraficzny>> LstOb);

/*!
 * \brief Robot obraca sie o podany kąt
 */
void  Obroc(double katWStopniach);

/*!
 * \brief Robot zwieksza lub zmiejsza swoj rozmiar
 */
void  Skaluj(double mnoznik=2);

/*!
 * \brief Robot jedzie w przód o podaną odleglosc
 */
void  JedzWPrzod(double odleglosc,
        std::list<shared_ptr<ObiektGraficzny>> LstOb);

/*!
 * \brief Metoda dzieli jazde w przod na mniejsze części
 */
void  JedzWPrzod_Animacja(double odleglosc,
        std::list<shared_ptr<ObiektGraficzny>> LstOb);

/*!
 * \brief Metoda dzieli obrót robota na mniejsze części
 */
void  Obroc_Animacja(double kat);

/*!
 * \brief Zmiana szybkosci poruszania sie robota
 */
void  ZmienSzybkoscAnimacji(double zadanyCzas);

/*!
 * \brief Metoda zwraca polozenie robota
 */
Wektor2D ZwrocPolozenie() const;

/*!
 * \brief Metoda wyswietla informacje o robocie
 */
void Info();

/*!
 * \brief Metoda sprawdza kolizje miedzy robotem a innym obiektem graficznym
 */
bool Kolizja(shared_ptr<ObiektGraficzny> Ob);

/*!
 * \brief Wirtulna metoda zwracająca nazwa klasy
 */
 std::string nazwaKlasy(){
  return "Robot";
}

};





#endif
