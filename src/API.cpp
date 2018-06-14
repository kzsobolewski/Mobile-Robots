/*!
 * \file
 * \brief Definicje metod APIGnuPlot
 *
 * Plik zawiera definicje metod klasy APIGnuPlot
 */

#include "API.hh"

#define GRUBOSC_LINI 2


APIGnuPlot::APIGnuPlot(double minX, double minY, double maxX, double maxY) : l_stworzone_ob(0) {
  Lacze.Inicjalizuj();
  Lacze.ZmienTrybRys(PzG::TR_2D);
  Lacze.UstawZakresY(minY,maxY);
  Lacze.UstawZakresX(minX,maxX);
  Lacze.PrzeslijDoGNUPlota("set size square");//linia odpowiedzialna za rownomierne rozlozenie osi
  //UWAGA!!! powyzsza linia wymaga zmiany w pliku lacze_do_gnuplota.hh - nalezy zmienic metode
  //PrzeslijDoGNUPlota z protected na public
}

int APIGnuPlot::rysuj_linie(const Wektor2D & pt1, const Wektor2D & pt2) {
  l_stworzone_ob++;//nowe id
  istniejace_obiekty.push_back(l_stworzone_ob);
  stringstream str;
  str << "figury/dane" << l_stworzone_ob << ".dat";//stworzenie nazwy pliku, wymaga istnienia katalogu figury
  Lacze.DodajNazwePliku(str.str().c_str(),PzG::RR_Ciagly,GRUBOSC_LINI);
  ofstream strm(str.str().c_str());
  if (!strm.is_open()) {
    cerr << endl
         << "Blad: Otwarcie do zapisu pliku '" << "dane.dat"
         << "' nie powiodlo sie." << endl
         << endl;
  }
  strm << pt1 << endl;
  strm << pt2 << endl;//wypisanie danych do pliku
  Lacze.Rysuj();//wyswietlanie danych z wszystkich plikow dodanych do lacza
  return l_stworzone_ob;
}

void APIGnuPlot::wymaz_ksztalt(int indeks) {
  istniejace_obiekty.erase(std::remove(istniejace_obiekty.begin(),
				       istniejace_obiekty.end(),indeks),
			   istniejace_obiekty.end());//patrz haslo erase-remove idiom
  Lacze.UsunWszystkieNazwyPlikow();
  stringstream str;
  for (int ind : istniejace_obiekty) {
    str.str("");
    str << "figury/dane" << ind << ".dat";
    Lacze.DodajNazwePliku(str.str().c_str(),PzG::RR_Ciagly,GRUBOSC_LINI);
  }
  Lacze.Rysuj();
  //usuwanie wyszstkich plikow z pamieci lacza a potem dodawanie tych co mialy tam
  //pozostac jest nieoptymalne, jednak lacze udostepnia tylko takie metody
}

int APIGnuPlot::rysuj_punkt(const Wektor2D & pt){
  return 0;
}
  //tu implementacja

int APIGnuPlot::rysuj_luk(const Wektor2D & pt1, double promien, double kat){
  return 0;
}
  //tu implementacja

int APIGnuPlot::rysuj_wielokat(const vector<Wektor2D> & pts) {
  l_stworzone_ob++;//nowe id
  istniejace_obiekty.push_back(l_stworzone_ob);
  stringstream str;
  str << "figury/dane" << l_stworzone_ob << ".dat";//stworzenie nazwy pliku, wymaga istnienia katalogu figury
  Lacze.DodajNazwePliku(str.str().c_str(),PzG::RR_Ciagly,GRUBOSC_LINI);
  ofstream strm(str.str().c_str());
  if (!strm.is_open()) {
    cerr << endl
         << "Blad: Otwarcie do zapisu pliku '" << "dane.dat"
         << "' nie powiodlo sie." << endl
         << endl;
  }
  for(unsigned int i = 0; i< pts.size(); i++)
    strm << pts[i] << endl;



  Lacze.Rysuj();//wyswietlanie danych z wszystkich plikow dodanych do lacza
  return l_stworzone_ob;



}
int APIGnuPlot::rysuj_okrag(const Wektor2D & pt,double promien) {
  return 0;
}
