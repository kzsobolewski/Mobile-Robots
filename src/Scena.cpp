/*!
 * \file
 * \brief Zawiera definicje metod klasy Scena
 *
 * Zawiera definicje metod klasy Scena
 * wraz z ich opisem.
 */

#include "Scena.hh"

//Fabryka Fabryka::_Fabryka;

/*!
 *  \brief metoda zapewnia lepsze wykorzystanie funkcji usleep
 *
 *
 * \param[in] de - liczba opóżnienia w 0,1 sec
 *
 */
void delay(int de = 5){
  usleep(de*100000);
}

/*!
 * Konstruktor Sceny tworzy obiekt API, obiekt Robot
 * oraz zeruje pozycje sceny
 *
 *
 */
Scena::Scena(){
  api = new APIGnuPlot(-300, -300, 500, 500);
  dodajRobota(0,0);
  Pozycja[0] = 0;
  Pozycja[1] = 0;
}


/*!  Metoda dodaje robota do planszy
 *
 *
 *
 * \param[in] wspX - wspolrzedna X srodka utworzonego robota
 * \param[in] wspY - wspolrzedna Y srodka utworzonego robota
 *
 *
 */
void Scena::dodajRobota(double wspX, double wspY){
  shared_ptr<ObiektGraficzny> tmpObj =
              Fabryka::Zbuduj(TO_Robot, api, wspX, wspY);
  Lista_obiektow.push_back(tmpObj);
  R = dynamic_pointer_cast<Robot>(tmpObj);
  Lista_robotow.push_back( R );
}

void Scena::dodajKilkaObiekow(){
  dodajPrzeszkode(-350,200, 300, 400);
  dodajPrzeszkode(-200,-250, 100, 100);
  dodajRobota(-100,20);
  dodajRobota(300,-100);
  wyborRobota(1);
}

/*!  Metoda dodaje przeszkode do planszy
 *
 *
 *
 * \param[in] wspX - wspolrzedna X lewej dolnej krawędzi przeszkody
 * \param[in] wspY - wspolrzedna Y lewej dolnej krawędzi przeszkody
 * \param[in] bokX - dlugosc boku wzdloz osi OX
 * \param[in] bokY - dlugosc boku wzdloz osi OY
 *
 *
 */
void Scena::dodajPrzeszkode(double wspX, double wspY, double bokX, double bokY){
  shared_ptr<ObiektGraficzny> P1 = Fabryka::Zbuduj(TO_Przeszkoda,api,wspX,wspY,bokX,bokY);
  Lista_obiektow.push_back( P1 );
}


/*!
 * Metoda wyświetla menu do obługi Sceny
 *
 *
 */
void Scena::wyswietlMenu(){
    SWektor<double,2> Wek;
  cout << "\n    STEROWANIE ROBOTEM MOBILNYM \n\n"
       << "Ilosc obiektow Wektor2D: " << Wek._StworzoneObiekty << endl
       << "Polozenie robota: " << R->ZwrocPolozenie() << endl << endl
       << " 1 - Obroc robota \n"
       << " 2 - Jedz na wprost\n"
       << " 3 - Zmien Robota\n"
       << " 4 - Dodaj Robota\n"
       << " 5 - Dodaj Przeszkode\n"
       << "\n e - Zakoncz program\n\n"
       << "  > ";
}

/*!
 * Metoda wyswietla menu oraz zapenia obługe całego programu
 * przez uzytkowniaka
 *
 *
 */
void Scena::MenuSceny(){
  char znak = '0';
  double wejscieFunkcji;
  double wspX;
  double wspY;
  double bokX;
  double bokY;

  while(znak != 'e'){
    system("clear");
    wyswietlMenu();
    cin  >> znak;
    cout << endl;
    switch(znak){
      case '1':   // OBROC
        cout << "\n Podaj kat obrotu: ";
        cin >> wejscieFunkcji;
        R->Obroc_Animacja(wejscieFunkcji);
      break;
      case '2':
        cout  << "\n Podaj odleglosc: ";
        cin >> wejscieFunkcji;
        try {
        R-> JedzWPrzod_Animacja(wejscieFunkcji, Lista_obiektow);
      } catch(const char * err){
        cout << err << endl;
        usleep(3000000);
      }
      break;
      case '3':
        system("clear");
        pokazListe();
        cout << "\n Wybierz nr robota ktorym chesz sterowac: ";
        cin >> wejscieFunkcji;
        wyborRobota(wejscieFunkcji);
        break;
      case '4':
        cout << "\n Podaj wspolrzedne gdzie Robot ma sie pojawić:";
        cin >> wspX;
        cin >> wspY;
        dodajRobota(wspX,wspY);
        system("clear");
        break;
      case '5':
        cout << "\n Podaj wspolrzedne gdzie Przeszkoda ma sie pojawić, oraz dlugosci bokow figury:";
        cin >> wspX;
        cin >> wspY;
        cin >> bokX;
        cin >> bokY;
        dodajPrzeszkode(wspX,wspY,bokX,bokY);
        break;
      case 'e':
      return;

    }
  }
}

/*!  Metoda wyswietla liste dostępnych robotow i daje mozliwosc wyboru
 *
 *
 *
 */
void Scena::wyborRobota(int wybor){
  int i = 1;
  for(auto &elem : Lista_robotow){
    if(i == wybor)
      R = elem;
    i++;
  }
}

void Scena::pokazListe(){
  int i = 1;
  for (auto &elem : Lista_robotow){
    cout << i << ". ";
    elem->Info();
    i++;
  }
}

/*!  Metoda przesuwa całą scene o podany wektor
 *
 *
 *
 * \param[in] X,Y - wektor przesunięcia
 *
 */
void Scena::PrzesunScene(double X, double Y){
  Pozycja[0] += X;
  Pozycja[1] += Y;
  R -> PrzesunCalosc(X,Y);
  R -> Rysuj();
}
