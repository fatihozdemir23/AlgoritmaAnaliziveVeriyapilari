#include "Arac.h"
#include "FileAction.h"
#include "mymethod.h"
#include <string>
#include <sstream>
#include <iostream>
using namespace std;
Arac::Arac()
{
AracKapasite=300;
}

Arac::~Arac()
{

}
void Arac::setAracId(int id){
AracId=id;
}
void Arac::setSubeId(int id){
AraSubeId=id;
}
void Arac::DagitimAracinaYukleme(){
    FileAction f;
    myMethod m;
    KuyrukSube sube;
 string fileName;
 remove("Dagitim1.txt");
 remove("Dagitim2.txt");
 remove("Dagitim3.txt");
 remove("Dagitim4.txt");
 remove("Dagitim5.txt");
int say=0,y_saat=0;
for(int i=1;i<=5;i++){
    fileName="Sube"+m.itos(i)+".txt";
    f.DosyaSatirStunHesap(fileName);
    f.ReadSubeTxt(fileName);

    for(int i=0;i<f.rows;i++){
     sube.enqueue(f.sube[i]);say++;
     SaatToplama(y_saat,f.sube[i].Sure);
     if(sube.size()>AracKapasite){
      cout<<endl<<"Arac doldu"<<endl;break;
     }
    }
    cout<<endl<<"Dagitim"+m.itos(i)+".txt"<<" dosyasi olusturuldu"<<endl;
     cout<<endl<<"Yukleme Suresi:"<<y_saat/60<<" saat"<<endl;
    cout<<endl<<"Adet:"<<say<<endl;
     cout<<endl<<"Toplam Hacim:"<<sube.size()<<" desimetre küp"<<endl;
     cout<<"----------------------------------------------------------"<<endl;
    say=0;y_saat=0;
    while(!sube.isEmpty()){
   f.FileWrite("Dagitim"+m.itos(i)+".txt",sube.front().GonderiId+","+m.itos(i)+","+m.dagitimYuklemeSaati(sube.front().Sure));
    sube.dequeue();

    }

}
}
void Arac::SaatToplama(int &saat,int yuklemesuresi){
saat+=yuklemesuresi;
}
