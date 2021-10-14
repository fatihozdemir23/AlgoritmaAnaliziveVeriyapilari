#include "mymethod.h"
#include <string>
#include <sstream>
#include <iostream>
using namespace std;
myMethod::myMethod(){}
myMethod::~myMethod(){}
string myMethod::saatHesap(int d){
string h,m,newTime;
dakika+=d;
if(dakika>=60){
saat++;
dakika=dakika-60;
}else{
saat=saat;
dakika=dakika;
}
stringstream hour;
stringstream minute;
hour<<saat;minute<<dakika;
hour>>h;minute>>m;
if(dakika<10)
m="0"+m;
if(saat<10)
h="0"+h;
newTime=h+":"+m;
return newTime;
}
string myMethod::dagitimYuklemeSaati(int saniye){
string h,m,newTime,s;
dagitimSaniye+=saniye;
if(dagitimSaniye>=60){
dagitimDakika++;
dagitimSaniye=dagitimSaniye-60;
}
if(dagitimDakika>=60){
dagitimSaati++;
dagitimDakika=dagitimDakika-60;
}else{
dagitimDakika=dagitimDakika;
dagitimSaati=dagitimSaati;
dagitimSaniye=dagitimSaniye;

}

stringstream hour;
stringstream minute;
stringstream seconds;
hour<<dagitimSaati;minute<<dagitimDakika;seconds<<dagitimSaniye;
hour>>h;minute>>m;seconds>>s;
if(dagitimDakika<10)
m="0"+m;
if(dagitimSaati<10)
h="0"+h;
if (dagitimSaniye<10)
s="0"+s;
newTime=h+":"+m+":"+s;
return newTime;
}
void myMethod::Sorting(string D[][3]){
int i,k,subeId;
    string ekle;

    for(i=1;i<500;i++){
        ekle=D[i][2];
    for(k=i-1;k>=0 && ekle>=D[k][2];k--)
        D[k+1][2]=D[k][2];/*geriye kaydırılıyor*/
          D[k+1][2]=ekle;/*uygun yer boşalıltıldı eklendi*/
    }

}
int myMethod::GonderiBul(string Dizi[][3],string GonderiId,int N){
int Ortadaki,Sol=0,Sag=N-1;
    while (Sol<=Sag)
    {
        Ortadaki=(Sol+Sag)/2;
        if(GonderiId ==Dizi[Ortadaki][0])
            return Ortadaki;
        else if(GonderiId>Dizi[Ortadaki][0])
        Sol=Ortadaki+1;
        else
            Sag=Ortadaki-1;
    }
    return -1;
}

int myMethod::GonderiTurAra(int Dizi[][4],int TurId,int N){
int Ortadaki,Sol=0,Sag=N-1;  int bulunan;
    while (Sol<=Sag)
    {
        Ortadaki=(Sol+Sag)/2;
        if(TurId ==Dizi[Ortadaki][0])
            return Ortadaki;
        else if(TurId>Dizi[Ortadaki][0])
        Sol=Ortadaki+1;
        else
            Sag=Ortadaki-1;
    }
    return -1;
}
string myMethod::itos(int i){//int to string
  string str;
  stringstream ss;
  ss << i;
  ss >> str;
  return str;
}
int myMethod::stoi(string s){//string to int
int num;
  stringstream ss;
  ss << s;
  ss >> num;
  return num;
}

