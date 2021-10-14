#include "Gonderi.h"
#include "FileAction.h"
#include "mymethod.h"
#include <sstream>
#include <iostream>
#include <string>
using namespace std;
Gonderi::Gonderi()
{
    //ctor
}

Gonderi::~Gonderi()
{
    //dtor
}
void Gonderi::setGonderiId(string g_id){
GonderiId=g_id;
}
void Gonderi::setGonderiTurId(string t_id){
GonderiTurId=t_id;
}
void Gonderi::setGonderiOncelik(string oncelik){
GonderiOncelik=oncelik;
}
void Gonderi::setGonderiHacim(string hacim){
GonderiHacim=hacim;
}
void Gonderi::setSubeId(string sube){
SubeId=sube;
}
void Gonderi::HacimBul(string g_id){
FileAction f;myMethod m;
f.GonderiList("gonderi.txt");
int index=m.GonderiBul(f.gonderiler,g_id,500);
if(index!=-1){
int t_index=m.GonderiTurAra(m.gonderiTurler,m.stoi(f.gonderiler[index][1]),6);
setGonderiId(g_id);
setGonderiTurId(f.gonderiler[index][1]);
setGonderiOncelik(m.itos(m.gonderiTurler[t_index][1]));
setGonderiHacim(m.itos(m.gonderiTurler[t_index][2]));
setSubeId(f.gonderiler[index][2]);
cout<<"Gonderi Id:         "<<getGonderiId()<<endl;
cout<<"Gonderi Turu:       "<<getGonderiTurId()<<endl;
cout<<"Gonderi Oncelik:    "<<getGonderiOncelik()<<endl;
cout<<"Gonderi Hacim:      "<<getGonderiHacim()<<endl;
cout<<"Gonderi Sube:       "<<getSubeId()<<endl;
}

else
    cout<<"Gonderi Bulunamadi";

}
