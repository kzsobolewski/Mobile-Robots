/*!
 * \file
 * \brief Zawiera definicje metod klasy Robot
 *
 * Zawiera definicje metod klasy Robot
 * wraz z ich opisem.
 */

#include "Robot.hh"

/*! Metoda zmienia szybkosc poruszania sie robota (jego jazdy oraz obrotu)
 *  podana liczba jest mnozona razy 1 mil oraz dzielona przez SKOK
 *  aby liczba mogla byc podawana w sekundach
 *
 * \param[in] zadanyCzas - czas jednego ruchu w sekundach
 *
 */
void  Robot::ZmienSzybkoscAnimacji(double zadanyCzas){
  zadanyCzas--;
  zadanyCzas = 1000000*zadanyCzas / SKOK;
  _CzasSkoku = zadanyCzas;
}

/*! Metoda dzieli obrót robota na mniejsze części zależle od SKOK,
 *  aby sprawić wrażenie poruszania się.
 *
 *
 * \param[in] kat - kąt o jaki Robot zostanie przesunięty
 *
 */
void  Robot::Obroc_Animacja(double kat){
  for(int i = 1; i <= abs(kat/SKOK) ; i++){
    if(kat < 0)
      this->Obroc(-SKOK);
    else
      this->Obroc(SKOK);
    usleep(_CzasSkoku);
  }
  this->Obroc(fmod(kat,SKOK));
  usleep(_CzasSkoku);
}
/*! Metoda resetuje pozycje robota do współrzędnej 0,0 i wymazuje scieżkę
 *
 *
 */
void Robot::ResetujPozycjeRobota(){
  _SladZaRobotem -> Resetuj();
  Obroc(-_KatPolozenia);

  Wektor2D pozycjaZerowa;
  pozycjaZerowa[0] = - _PolozenieObiektu[0];
  pozycjaZerowa[1] = - _PolozenieObiektu[1];

  PrzesunOWektor(pozycjaZerowa[0],pozycjaZerowa[1] );

  _SladZaRobotem -> DodajWierzcholek( _PolozenieObiektu );
}

/*!
 *  Metoda zwraca aktualną pozycje środka robota
 *
 *
 * \param[iout] Wektor położenia robota
 *
 */
Wektor2D Robot::ZwrocPolozenie() const{
  return _PolozenieObiektu;
}

/*!
 *  Metoda inicjalizuje kształt robota poprzez dodanie do jego
 *  tablicy wierzchołków konkretnych punktów.
 *
 */
void  Robot::InicjalizujKsztalt(){
  _KatPolozenia = 0;

  Wektor2D poczatkowePolozenie;
  poczatkowePolozenie[0] += _PolozenieObiektu[0];
  poczatkowePolozenie[1] += _PolozenieObiektu[1];


  Wektor2D tmp[7];
  tmp[0][0] = 0;     tmp[0][1] = 0;
  tmp[1][0] = 20 ;   tmp[1][1] = 0;
  tmp[2][0] = 10 ;   tmp[2][1] = 20;
  tmp[3][0] = -20 ;  tmp[3][1] = 20;
  tmp[4][0] = -20 ;  tmp[4][1] = -20;
  tmp[5][0] = 10 ;   tmp[5][1] = -20;
  tmp[6][0] = 20 ;   tmp[6][1] = 0;


  for(int i = 0; i< 7; i++)
    _WzorRobota.push_back(tmp[i]);

  for( int i = 0; i < 7; i ++){
    tmp[i] = tmp[i] + poczatkowePolozenie;
    _TabWierz.push_back(tmp[i]);
  }


}

/*!
 * Metoda wymazuje poprzednią pozycje robota,
 * rysuje aktualną pozycje i jego ścieżkę.
 *
 */
void  Robot::Rysuj(){
  _SladZaRobotem -> Rysuj();

  if(_RysunekID)
    wskAPI -> wymaz_ksztalt(_RysunekID);
  _RysunekID = wskAPI -> rysuj_wielokat( _TabWierz );
}

/*!
 *  Metoda sprawia, że robot jedzie w konretne miejsce, poruszając się
 *  Pod kątem prostym do osi wpółrzędnych.
 *
 * \param[in] x, y - współrzędne, w które robot pojedzie
 *
 */
void  Robot::JedzWMiejsce(double x, double y,
              std::list<shared_ptr<ObiektGraficzny>> LstOb){
  Wektor2D WekCel;
  WekCel[0] = x;
  WekCel[1] = y;

  if( x < _PolozenieObiektu[0])
    Obroc_Animacja(180 - _KatPolozenia);
  else Obroc_Animacja(-_KatPolozenia);

  JedzWPrzod_Animacja(abs(x - _PolozenieObiektu[0]), LstOb);


  if( y < _PolozenieObiektu[1])
    Obroc_Animacja(-90-_KatPolozenia);
  else Obroc_Animacja(_KatPolozenia +90);

  JedzWPrzod_Animacja(abs(y - _PolozenieObiektu[1]), LstOb);
}

/*! Metoda obraca pozycje robota poprzez przemnozenie jego punktow
 *  przez macierz obrotu. Metoda nie nagromadza błedów.
 *
 *
 * \param[in] katWStopniach - kąt w stopniach o jaki robot zostanie obrócony
 *
 */
void  Robot::Obroc(double katWStopniach){
  _KatPolozenia += katWStopniach;
  while(_KatPolozenia >= 360)
    _KatPolozenia -= 360;

  double kat = _KatPolozenia* M_PI  / 180;
  Macierz2D macierzObrotu;

  macierzObrotu[0][0] = cos(kat);        macierzObrotu[0][1] = -sin(kat);
  macierzObrotu[1][0] = sin(kat);        macierzObrotu[1][1] =  cos(kat);

  double x = _PolozenieObiektu[0];
  double y = _PolozenieObiektu[1];
  PrzesunOWektor(-x, -y);

  for(unsigned int i = 0; i < _TabWierz.size(); i++){
    _TabWierz[i] = macierzObrotu * _WzorRobota[i];
  }

  PrzesunOWektor(x,y);
  this->Rysuj();
}

/*! Metoda skaluje obrys robota poprzez przemnożenie jego punktów
 *  przez poda liczbe
 *
 *
 * \param[in] mnoznik - współczynnik wielkosci robota
 *
 */
void  Robot::Skaluj(double mnoznik){
  double x = _PolozenieObiektu[0];
  double y = _PolozenieObiektu[1];
  double kat = _KatPolozenia;
  PrzesunOWektor(-x,-y);

  Obroc(-kat);
  for(unsigned int i = 0; i < _TabWierz.size(); i++){
    _WzorRobota[i] = _WzorRobota[i] * mnoznik;
    _TabWierz[i] = _WzorRobota[i];
  }
  Obroc(kat);

  PrzesunOWektor(x,y);
  Rysuj();

}


/*! Metoda sprawia ze robot jedzie w przód na podaną odległość
 *
 *
 *
 * \param[in] odleglosc - odleglość jaką przejedzie robot
 * \param[in] LstOb - lista obiektów graficznych z którymi mozliwa jest kolizja
 */
void Robot::JedzWPrzod(double odleglosc,
              std::list<shared_ptr<ObiektGraficzny>> LstOb){

  for (auto &elem : LstOb){
    if( Kolizja(elem) ){
      throw "\n!! Kolizja robota\n";
      return;
    }
  }

  PrzesunOWektor(
    odleglosc * cos(_KatPolozenia * M_PI/180),
    odleglosc * sin(_KatPolozenia * M_PI/180)  );
    _SladZaRobotem -> DodajWierzcholek(_PolozenieObiektu);
    this->Rysuj();
}

/*! Metoda dodaje animacje do jazdy roobta
 *
 *
 *
 * \param[in] odleglosc - odleglość jaką przejedzie robot
 * \param[in] LstOb - lista obiektów graficznych z którymi mozliwa jest kolizja
 */
void  Robot::JedzWPrzod_Animacja(double odleglosc,
                std::list<shared_ptr<ObiektGraficzny>> LstOb){
  for(int i = 1; i <= abs(odleglosc/SKOK) ; i++){
      try{
        if(odleglosc<0)
          this->JedzWPrzod(-SKOK, LstOb);
        else
          this->JedzWPrzod(SKOK, LstOb);
      } catch(const char * err){
        throw err;
        return;
      }
        usleep(_CzasSkoku);
  }
  try{
  this->JedzWPrzod(fmod(odleglosc, SKOK), LstOb);
} catch (const char * err){
  throw err;
  return;
}
  usleep(_CzasSkoku);
}
/*!  Metoda przesuwa robota i jego sciezke o zadany wektor
 *
 *
 *
 * \param[in] X, Y - liczby tworzace Wektor2D przesunięcia
 *
 */
void Robot::PrzesunCalosc(double X, double Y){
  PrzesunOWektor(X,Y);
  _SladZaRobotem->PrzesunOWektor(X,Y);
}
/*!  Metoda wyswietla polozenie robota
 *
 *
 */
void Robot::Info(){
  cout << "Robot" << ZwrocPolozenie() << endl;
}

/*!  Metoda sprawdza kolizje miedzy robotem a obiektami graficznymi
 *
 *
 *
 * \param[in] Ob - obiekt dla którego sprawdzana jest kolizja
 * \param[out] bool - zwraca prawde gdy kolizja zaszła
 *
 */
bool Robot::Kolizja(shared_ptr<ObiektGraficzny> Ob){
  // Sprawdzanie czy obiekt to robot
  if( Ob->nazwaKlasy() == "Robot"){
    shared_ptr<Robot> R1;
    // rzutowanie obiektu na robota
    R1 = dynamic_pointer_cast<Robot>(Ob);
    double odleglosc = this->_PolozenieObiektu.odleglosc(R1->ZwrocPolozenie());
    // zwraca prawde gdy odleglosci sa zbyt male
    if(odleglosc < 55 && odleglosc > 1)
      return 1;
    // sprawdza czy obiekt to przeszkoda
  }else if( Ob -> nazwaKlasy() == "Przeszkoda"){
    shared_ptr<Przeszkoda> P1;
    P1 = dynamic_pointer_cast<Przeszkoda>(Ob);
    // porownuje polozenie robota do zakresow przeszkody
    if ( this->_PolozenieObiektu[0] > P1->zwrocZakresX()[0] &&
         this->_PolozenieObiektu[0] < P1->zwrocZakresX()[1])
          if ( this->_PolozenieObiektu[1] > P1->zwrocZakresY()[0] &&
               this->_PolozenieObiektu[1] < P1->zwrocZakresY()[1])
                  return 1;
  }

  return 0;
}
