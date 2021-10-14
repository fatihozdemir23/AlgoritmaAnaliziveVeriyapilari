#ifndef MYMETHOD_H
#define MYMETHOD_H
#include <string>
#include <iostream>
#include <sstream>
#include "FileAction.h"
using namespace std;
class myMethod
{
public:
   int gonderiTurler[6][4]={
    {1,1,1,6},
    {2,2,3,30},
    {3,3,5,60},
    {4,3,1,6},
    {5,4,3,30},
    {6,5,5,60}
    };
    /*
    0.stun türId
    1.stun öncelik puaný
    2.stun desi
    3.stun yükleme süresi
    */
         myMethod();
        ~myMethod();
       string saatHesap(int dakika);
       string dagitimYuklemeSaati(int saniye);
       void Sorting(string D[][3]);
       int GonderiBul(string Dizi[][3],string GonderiId,int N);
       int GonderiTurAra(int Dizi[][4],int TurId,int N);
       int stoi(string);
       string itos(int);

private:
   int saat=7,dakika=0;
   int dagitimSaati=8;
   int dagitimDakika=0;
   int dagitimSaniye=0;


};

#endif // MYMETHOD_H
