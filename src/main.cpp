/*!
 * \file
 * \brief Zawiera wywołanie funkcji main
 *
 * Główny moduł programu wraz z wywołaniem funkcji main, ktora wywołuje główną metode Sceny
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <unistd.h>
#include "Scena.hh"

using namespace std;

Fabryka Fabryka::_Fabryka;

/*!
 *
 * Głowna funkcja programu, która tworzy Scene i wywołuje metodę do jej obsługi
 */
int main(){

  Scena S;
  S.dodajKilkaObiekow();
  S.MenuSceny();

}
