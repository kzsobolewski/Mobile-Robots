#include "Fabryka.hh"

shared_ptr<ObiektGraficzny> Fabryka::Zbuduj(
      TypObiektu  TypOb , API * arg, double wspX, double wspY,
      double bokX, double bokY){
        return _Fabryka.UtworzObiekt(TypOb,arg,wspX,wspY,bokX,bokY);
      }


shared_ptr<ObiektGraficzny> Fabryka::UtworzObiekt(
     TypObiektu  TypOb , API * arg, double wspX, double wspY,
     double bokX, double bokY) const{
       switch (TypOb) {
           case TO_Robot:
             return make_shared<Robot>(arg, wspX, wspY);
             break;
           case TO_Przeszkoda:
             return make_shared<Przeszkoda>(arg,wspX,wspY,bokX,bokY);
             break;
           }

     return make_shared<Przeszkoda>(arg,wspX,wspY,bokX,bokY);
}
