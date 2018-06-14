#ifndef FABRYKA_HH
#define FABRYKA_HH

/*!
 * \file
 * \brief definicja klasy Fabryka
 *
 *  Klasa jest singletone i fabryka prosta. Za jej pomocą można tworzyć obiekty
 *  graficzne takie jak Robot czy Przeszkoda
 *
 *
 */

#include <iostream>
#include <unistd.h>
#include <memory>
#include "ObiektGraficzny.hh"
#include "Wektor2D.hh"
#include "SWektor.hh"
#include "Przeszkoda.hh"
#include "API.hh"
#include "Robot.hh"

using namespace std;

enum TypObiektu { TO_Robot, TO_Przeszkoda };

/*
 * \brief Modeluje klase Fabryka
 *
 *  Klasa jest singletone i fabryka prosta. Za jej pomocą można tworzyć obiekty
 *  graficzne takie jak Robot czy Przeszkoda
 *
 *
 */
class Fabryka {
    static Fabryka   _Fabryka;
  public:
    ~Fabryka(){
       cout << "--- D: Fabryka" << endl;
     }


    static shared_ptr<ObiektGraficzny> Zbuduj(
          TypObiektu  TypOb , API * arg, double wspX=0, double wspY=0,
          double bokX=100, double bokY=100);

  private:
    Fabryka(){
       cout << "+++ K: Fabryka" << endl;
     }

    shared_ptr<ObiektGraficzny> UtworzObiekt(
       TypObiektu  TypOb , API * arg, double wspX, double wspY,
       double bokX, double bokY) const;
};



#endif
