#include "FileAction.h"
#include "Subeler.h"
#include "Gonderiler.h"
#include "mymethod.h"
#include "NakliyeStack.h"
using namespace std;
FileAction::FileAction(){}
FileAction::~FileAction(){}
void FileAction::FileWrite(string fileName,string line){

ofstream dosyaYaz(fileName.c_str(),ios::app);
	 if (dosyaYaz.is_open()){
    dosyaYaz <<line<<"\n";
    dosyaYaz.close();
  }
}
NakliyeStack FileAction::GonderiYukle(string fileName){
string stun,satir;int r=0,c=0;
ifstream dosya(fileName.c_str(),ios::in);
string gonderiler[rows][cols];
if(!dosya){
cout<<"Dosya Okunamadi!!!";

}else
{

 while(getline(dosya,satir)){
  stringstream satir_oku(satir);
 c=0;
while(getline(satir_oku,stun,',')){
stringstream val(stun);
gonderiler[r][c]=stun;
c++;
}
r++;
}
 Gonderiler *gonderi=new Gonderiler[rows];
 NakliyeStack ns;
 myMethod m;
for(int i=0;i<rows;i++){

gonderi[i].SetGonderiId(gonderiler[i][0]);
gonderi[i].SetTurId(m.stoi(gonderiler[i][1]));
gonderi[i].SetSubeId(m.stoi(gonderiler[i][2]));
ns.push(gonderi[i]);
}
dosya.close();
return ns;
delete []gonderi;
delete []gonderiler;
}}

void FileAction::ReadSubeTxt(string fileName){
myMethod m;
string subeGonderiler[rows][cols];
string stun,satir;int r=0,c;
ifstream dosya(fileName.c_str(),ios::in);
if(!dosya){
cout<<"Dosya Okunamadi!!!";

}else
{
 while(getline(dosya,satir)){
  stringstream satir_oku(satir);
 c=0;
while(getline(satir_oku,stun,',')){
subeGonderiler[r][c]=stun;
c++;
}
r++;
}
dosya.close();

sube=new Subeler[rows];

for(int i=0;i<rows;i++){
sube[i].GonderiId=subeGonderiler[i][0];
sube[i].TurId=m.stoi(subeGonderiler[i][1]);
sube[i].Oncelik=m.stoi(subeGonderiler[i][2]);
sube[i].Desi=m.stoi(subeGonderiler[i][3]);
sube[i].Sure=m.stoi(subeGonderiler[i][4]);
}
}
}
void FileAction::GonderiList(string fileName){
string stun,satir;int r=0,c;
ifstream dosya(fileName.c_str(),ios::in);
if(!dosya){
cout<<"Dosya Okunamadi!!!";

}else
{
 while(getline(dosya,satir)){
  stringstream satir_oku(satir);
 c=0;
while(getline(satir_oku,stun,',')){
gonderiler[r][c]=stun;
c++;
}
r++;
}
dosya.close();
}
}
void FileAction::DosyaSatirStunHesap(string fileName){
string karakter,satir;
int dr,dc;
 ifstream dosya(fileName.c_str(),ios::in);

 while(getline(dosya,satir)){
  stringstream satirDizisi(satir);
  dc=0;
while(getline(satirDizisi,karakter,',')){
dc++;
}
dr++;
}
rows=dr;
cols=dc;
dosya.close();
}

