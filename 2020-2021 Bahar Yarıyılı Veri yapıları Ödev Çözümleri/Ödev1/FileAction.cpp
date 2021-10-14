#include "FileAction.h"
#include "CustomMethod.h"
#include <string>
#include <iostream>
using namespace std;
FileAction::FileAction(string filename)
{
   DosyaSatirStunHesap(filename);
   Matris=MatrisOlustur();
   DosyaOku(filename);
}
FileAction::FileAction()
{

}
void FileAction::FileInit(string filename)
{
   DosyaSatirStunHesap(filename);
   Matris=MatrisOlustur();
   DosyaOku(filename);
}
void FileAction::DosyaOku(string fileName){
string karakter,satir;
int r=0,c;
ifstream dosya(fileName.c_str(),ios::in);

if(!dosya){
cout<<"Dosya Okunamadi!!!";

}else
{

 while(getline(dosya,satir)){
stringstream karakterlerzinciri(satir);
 c=0;
while(getline(karakterlerzinciri,karakter,',')){
stringstream val(karakter);
Matris[r][c]=karakter;
c++;
}
r++;
}
dosya.close();
}
}
FileAction::~FileAction(){}
void FileAction::FileWrite(string fileName,string line){

ofstream dosyaYaz(fileName.c_str(),ios::app);
	 if (dosyaYaz.is_open()){
    dosyaYaz <<line<<"\n";
    dosyaYaz.close();
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
string** FileAction::MatrisOlustur() {

  string **matris = new string*[rows];

  for (int i = 0; i < rows; i++)

  {

   matris[i] = new string[cols];

  }
return matris;

 }

