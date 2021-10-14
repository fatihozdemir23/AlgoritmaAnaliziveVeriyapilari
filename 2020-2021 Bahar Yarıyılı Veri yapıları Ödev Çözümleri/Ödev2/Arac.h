#ifndef ARAC_H
#define ARAC_H
#include <string>
#include <sstream>
#include <iostream>
#include "KuyrukSube.h"
using namespace std;

class Arac
{
    public:
         Arac();
        ~Arac();
 void setAracId(int);
 void setSubeId(int);
 int getAracKapasite()const{return AracKapasite;}
 void DagitimAracinaYukleme();
 void SaatToplama(int &saat,int yuklemeSuresi);
     private:
        int AracId;
        int AracKapasite;
        int AraSubeId;
};

#endif // ARAC_H
