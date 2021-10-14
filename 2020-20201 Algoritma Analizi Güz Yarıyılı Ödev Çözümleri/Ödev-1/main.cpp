
#include <iostream>
#include <fstream>
#include <sstream>
#include <locale.h>
#include <string>
#define yerDegistir(type, i, j) {type T = i; i=j; j=T;}
#include "DinamikStack.h"
using namespace std;

typedef struct{
int Id;
string Ad;
float riskPuani;
int mahalleId;
}RiskPuani;

typedef struct{
int mahalleId;
float mahalleriskPuani;
}MahalleRiskPuani;

typedef struct{
int Id;
string Ad;
char Cinsiyet;
string Mahalle;
int Yas;
char Covid;
char Kronik;
char Ildisi;
} Kisiler;

void RiskPuaniStack(RiskPuani *arr, int n, int kok);
void KisiRiskPuaniSirala(RiskPuani *arr, int n);
void MahalleRiskPuaniStack(MahalleRiskPuani *arr, int n, int kok);
void MahalleRiskPuaniSirala(MahalleRiskPuani *arr, int n);
float yasKatsayi(int i);
void mahalleRiskPuanHesapla();
void riskPuaniHesapla();
float kronikRahatsizlikKatsayi(int i);
float **MatrisOlusturFloat(int rows, int columns);
void etkilesimGrafOlustur();
int ikiliArama(int D[], int N, int Aranan);
int maskeKatsayi(int i,int d);
float iliskiKatsayi(int i,int j);
int etkilesimKatsayi(int i,int j,int d);
int ikiliArama(string **D, int N, int Aranan);
int fsatir,fstun;
string **ReadFile(string fileName);
void SatirStunHesapla(string fileName);
void dosyaOku();
void genelSiralama();
void temasliKisileriBul();
void iliskiDerecesiGoster();
void etkilesimPuaniHesapla();
string **MatrisOlustur(int rows, int columns);
string **kisilerMatris;
string **iliskiMatris;
string **maskeMatrisi;
string **etkilesim1;
string **etkilesim2;
string **etkilesim3;
string **etkilesim4;
float **etkilesimGraf;
void mahalleBulasmaRiskSiralama();
RiskPuani *kisilerRiskPuani=new RiskPuani[50];
MahalleRiskPuani *mRiskPuani=new MahalleRiskPuani[5];
int main(){
try{
  dosyaOku();//tüm fonksiyonlar için çalıştırılması gerek.
  //iliskiDerecesiGoster();
  genelSiralama();
 // mahalleBulasmaRiskSiralama();
  //temasliKisileriBul();


}catch(exception e){
 cout<<"Dosya Okuma Hatasi";

}


}

void genelSiralama(){
etkilesimPuaniHesapla();
riskPuaniHesapla();
KisiRiskPuaniSirala(kisilerRiskPuani,50);
cout<<"Id\t"<<"Ad\t"<<"RiskPuani\t"<<endl;

for(int i=0;i<50;i++){
cout<<kisilerRiskPuani[i].Id<<"\t"<<kisilerRiskPuani[i].Ad<<"\t"<<kisilerRiskPuani[i].riskPuani<<endl;

}
 }
void dosyaOku(){
kisilerMatris=ReadFile("kisiler.txt");
iliskiMatris=ReadFile("iliski.txt");
etkilesim1=ReadFile("etkilesim1.txt");
etkilesim2=ReadFile("etkilesim2.txt");
etkilesim3=ReadFile("etkilesim3.txt");
etkilesim4=ReadFile("etkilesim4.txt");
maskeMatrisi=ReadFile("maske.txt");
}
void iliskiDerecesiGoster(){
    DinamikStack<string> iliskiAdimlari;
int kaynakindex,hedefindex;
string kaynakKisi,hedefKisi;
   int kaynakId,hedefId;
       cout<<"Kaynak Id:";
       cin>>kaynakId;
       cout<<"Hedef Id:";
       cin>>hedefId;
kaynakindex=ikiliArama(kisilerMatris,50,kaynakId);
hedefindex=ikiliArama(kisilerMatris,50,hedefId);
if(kaynakindex==-1 || hedefindex==-1){
cout<<"Kaynak veya hedef Id'lerden biri bulunamadi";

}
else{
kaynakKisi=kisilerMatris[kaynakindex][1];
hedefKisi=kisilerMatris[hedefindex][1];
if(iliskiMatris[kaynakindex][hedefindex]=="0")
    cout<<kaynakKisi<<" ile "<<hedefKisi<<" Arkadas Degil";
    else
        if(iliskiMatris[kaynakindex][hedefindex]=="1")
    cout<<kaynakKisi<<" ile "<<hedefKisi<<" Arkadas";
    else
        if(iliskiMatris[kaynakindex][hedefindex]=="2")
    cout<<kaynakKisi<<" ile "<<hedefKisi<<" Yakin Arkadas";
    else
        if(iliskiMatris[kaynakindex][hedefindex]=="3")
    cout<<kaynakKisi<<" ile "<<hedefKisi<<" Ayni Evde Yasiyor";
    for(int k=0;k<hedefindex;k++){
      if(iliskiMatris[kaynakindex][k]=="1" ||iliskiMatris[kaynakindex][k]=="2"||iliskiMatris[kaynakindex][k]=="3"){

    iliskiAdimlari.Ekle(kisilerMatris[k][1]);
      }

    }
    string temp;
    cout<<endl<<"Iliski Adimlari"<<endl;
    iliskiAdimlari.Yazdir(temp);

    delete []kisilerMatris;
    delete []iliskiMatris;

}
}
void etkilesimGrafOlustur(){
//ofstream dosya("etkilesimGraf.txt",ios::out);
dosyaOku();
etkilesimPuaniHesapla();
for(int i=0;i<50;i++){
for(int j=0;j<50;j++){
cout<<etkilesimGraf[i][j]<<" ";
//dosya<<etkilesimGraf[i][j]<<",";
}
//dosya<<"\n";
}
delete []etkilesimGraf;

}
void mahalleBulasmaRiskSiralama(){
mahalleRiskPuanHesapla();
MahalleRiskPuaniSirala(mRiskPuani,5);
cout<<"Mahalle ID\t"<<"Risk Puani"<<endl;
for(int i=0;i<5;i++){

cout<<mRiskPuani[i].mahalleId<<"\t \t"<<mRiskPuani[i].mahalleriskPuani<<endl;
}
delete []kisilerRiskPuani;
}
void mahalleRiskPuanHesapla(){
dosyaOku();
etkilesimPuaniHesapla();
riskPuaniHesapla();
int mNo;
mRiskPuani[0].mahalleId=1;
mRiskPuani[1].mahalleId=2;
mRiskPuani[2].mahalleId=3;
mRiskPuani[3].mahalleId=4;
mRiskPuani[4].mahalleId=5;
for(int i=0;i<50;i++){
mNo=kisilerRiskPuani[i].mahalleId;

if(mNo==1){

mRiskPuani[0].mahalleriskPuani+=kisilerRiskPuani[i].riskPuani;
}else
if(mNo==2){

mRiskPuani[1].mahalleriskPuani+=kisilerRiskPuani[i].riskPuani;
}
else
if(mNo==3){
mRiskPuani[2].mahalleriskPuani+=kisilerRiskPuani[i].riskPuani;
}
else
if(mNo==4){
mRiskPuani[3].mahalleriskPuani+=kisilerRiskPuani[i].riskPuani;
}
else
if(mNo==5){
mRiskPuani[4].mahalleriskPuani+=kisilerRiskPuani[i].riskPuani;
}
}



}
void temasliKisileriBul(){

DinamikStack<string> temasli;
int etkilesimDurum,covidDurum,day;
cout<<"Gun No girin(1,2,3,4):";
cin>>day;
system("CLS");
cout<<day<<".Gun Kisi Temas Listesi"<<endl;
for(int i=0;i<50;i++){

       stringstream  covid(kisilerMatris[i][5]);

       covid>>covidDurum;
for(int j=0;j<50;j++){

switch(day){
temasli.YiginBosalt();
case 1:{
        stringstream  etkilesim(etkilesim1[i][j]);
        etkilesim>>etkilesimDurum;

       if(etkilesimDurum==1 && covidDurum==1){

        temasli.Ekle(kisilerMatris[j][1]);


        }
}break;
case 2:{
  stringstream  etkilesim(etkilesim2[i][j]);
        etkilesim>>etkilesimDurum;

       if(etkilesimDurum==1 && covidDurum==1){
        temasli.Ekle(kisilerMatris[j][1]);

        }
}break;
case 3:{

  stringstream  etkilesim(etkilesim3[i][j]);
        etkilesim>>etkilesimDurum;
       if(etkilesimDurum==1 && covidDurum==1){
       temasli.Ekle(kisilerMatris[j][1]);

        }
}break;
case 4:{

  stringstream  etkilesim(etkilesim4[i][j]);
        etkilesim>>etkilesimDurum;
       if(etkilesimDurum==1 && covidDurum==1){
        temasli.Ekle(kisilerMatris[j][1]);

        }
}break;

}


}

if(covidDurum!=0){
 string temp;
cout<<endl<<kisilerMatris[i][1]<<" Temas Ettikleri\n";
temasli.Yazdir(temp);

}

}

delete []kisilerMatris;
}

void riskPuaniHesapla(){

float yasKatsayisi,kronikRahatsizlikKatsayisi,etkilesimPuani,riskPuan=0;

int id,mId;
float toplamRiskPuani;
for(int i=0;i<50;i++){
for(int j=0;j<50;j++){

yasKatsayisi=yasKatsayi(i);
kronikRahatsizlikKatsayisi=kronikRahatsizlikKatsayi(i);
etkilesimPuani=etkilesimGraf[i][j];
riskPuan=yasKatsayisi*kronikRahatsizlikKatsayisi*etkilesimPuani;

toplamRiskPuani=toplamRiskPuani+riskPuan;
}
stringstream ss(kisilerMatris[i][0]);
ss>>id;
stringstream mid(kisilerMatris[i][3]);
mid>>mId;
kisilerRiskPuani[i].mahalleId=mId;
kisilerRiskPuani[i].Id=id;
kisilerRiskPuani[i].Ad=kisilerMatris[i][1];
kisilerRiskPuani[i].riskPuani=toplamRiskPuani;
//cout<<kisilerRiskPuani[i].Ad<<" Risk Puani:"<<toplamRiskPuani<<endl;

toplamRiskPuani=0;
}
}
void etkilesimPuaniHesapla(){
etkilesimGraf=MatrisOlusturFloat(50,50);
int etkilesimKatsayisi,maskeKatsayisi;
float iliskiDurumKatsayisi,etkilesimPuani,toplamEtkilesimPuan=0;
for(int i=0;i<50;i++){
for(int j=0;j<50;j++){
//cout<<kisilerMatris[i][1]<<" ile "<<kisilerMatris[j][1]<<endl;
for(int d=1;d<=4;d++){
etkilesimKatsayisi=etkilesimKatsayi(i,j,d);
maskeKatsayisi=maskeKatsayi(i,d);
iliskiDurumKatsayisi=iliskiKatsayi(i,j);
etkilesimPuani=etkilesimKatsayisi*iliskiDurumKatsayisi*maskeKatsayisi;
//cout<<d<<".Gun:"<<etkilesimKatsayisi <<"x"<<iliskiKatsayi(i,j)<<"x"<<maskeKatsayi(i,d)<<"="<<etkilesimPuani<<endl;
toplamEtkilesimPuan=toplamEtkilesimPuan+etkilesimPuani;
}
//cout<<"toplam etkilesim puan:"<<toplamEtkilesimPuan<<endl<<endl;
etkilesimGraf[i][j]=toplamEtkilesimPuan;
toplamEtkilesimPuan=0;
}
}

delete []iliskiMatris;
delete []etkilesim1;
delete []etkilesim2;
delete []etkilesim3;
delete []etkilesim4;
delete []maskeMatrisi;

//delete []kisilerMatris;
}
float iliskiKatsayi(int i,int j){
if(iliskiMatris[i][j]=="-")
   return 0;
    else
if(iliskiMatris[i][j]=="0")
   return 1;
    else
        if(iliskiMatris[i][j]=="1")
    return 1.2;
    else
        if(iliskiMatris[i][j]=="2")
   return 1.5;
    else
        if(iliskiMatris[i][j]=="3")
    return 1.9;
}
int maskeKatsayi(int i,int d){
   if(maskeMatrisi[i][d]=="0")
   return 3;else
   if(maskeMatrisi[i][d]=="1")
   return 1;
}
float kronikRahatsizlikKatsayi(int i){
   if(kisilerMatris[i][6]=="0")
   return 1;else
   if(kisilerMatris[i][6]=="1")
   return 1.7;
}
float yasKatsayi(int i){
  stringstream ss(kisilerMatris[i][4]);
  int yas;
  ss>>yas;

if(yas>0 && yas<=5)
   return 0.2;else
if(yas>5 && yas<=20)
   return 0.5;else
if(yas>20 && yas<=55)
   return 1.0;else
if(yas>55 && yas<=75)
   return 1.7;else
if(yas>75)
   return 2.0;
}
int etkilesimKatsayi(int i,int j,int d){

   int toplam,val;

   switch(d){
case 1:{
       stringstream  stream(etkilesim1[i][j]);
       stream>>val;
       if(val==0) toplam=toplam+0;else
       if(val==1) toplam=toplam+1;

       }break;
case 2:{
       stringstream  stream(etkilesim2[i][j]);
       stream>>val;
       if(val==0) toplam=toplam+0;else
       if(val==1) toplam=toplam+1;

       }break;
case 3:{
       stringstream  stream(etkilesim3[i][j]);
       stream>>val;
       if(val==0) toplam=toplam+0;else
       if(val==1) toplam=toplam+1;

       }break;
case 4:{
       stringstream  stream(etkilesim4[i][j]);
       stream>>val;
       if(val==0) toplam=toplam+0;else
       if(val==1) toplam=toplam+1;

       }break;
   }

   return toplam;
}
void SatirStunHesapla(string fileName){
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
fsatir=dr;
fstun=dc;
dosya.close();
}
string **ReadFile(string fileName){
SatirStunHesapla(fileName);
string **myMatris=MatrisOlustur(fsatir,fstun);
string karakter,satir;int rows,cols;
ifstream dosya(fileName.c_str(),ios::in);
if(dosya==NULL){
cout<<"Dosya Okunamadi!!!";

}else{

 while(getline(dosya,satir)){
  stringstream karakterlerzinciri(satir);
  cols=0;
while(getline(karakterlerzinciri,karakter,',')){
myMatris[rows][cols]=karakter;cols++;}rows++;}
dosya.close();
return myMatris;
}
}

string **MatrisOlustur(int rows, int columns) {

  string **matris = new string*[rows];

  for (int i = 0; i < rows; i++)

  {

   matris[i] = new string[columns];

  }
return matris;

 }
float **MatrisOlusturFloat(int rows, int columns) {

  float **matris = new float*[rows];

  for (int i = 0; i < rows; i++)

  {

   matris[i] = new float[columns];

  }
return matris;

 }

/*Arama ve Siralama Algoritmaları*/
int ikiliArama (string **D, int N, int Aranan)
{
    int bulunan;
    int Ortadaki,Sol=0,Sag=N-1;
    while (Sol<=Sag)
    {
        Ortadaki=(Sol+Sag)/2;
        stringstream dizi(D[Ortadaki][0]);
        dizi>>bulunan;
        if(Aranan ==bulunan)
            return Ortadaki;
        else if(Aranan>bulunan)
        Sol=Ortadaki+1;
        else
            Sag=Ortadaki-1;
    }
    return -1;
}

int ikiliArama (int D[], int N, int Aranan)
{

    int Ortadaki,Sol=0,Sag=N-1;
    while (Sol<=Sag)
    {
        Ortadaki=(Sol+Sag)/2;
        if(Aranan ==D[Ortadaki])
            return Ortadaki;
        else if(Aranan>D[Ortadaki])
        Sol=Ortadaki+1;
        else
            Sag=Ortadaki-1;
    }
    return -1;
}
void RiskPuaniStack(RiskPuani *arr, int n, int kok)
{
   int tepe = kok;
   int sol = 2*kok + 1;
   int sag = 2*kok + 2;


   if (sol < n && arr[sol].riskPuani < arr[tepe].riskPuani)
   tepe = sol;


   if (sag < n && arr[sag].riskPuani < arr[tepe].riskPuani)
   tepe = sag;


   if (tepe != kok)
      {

      yerDegistir(RiskPuani, arr[kok], arr[tepe]);

      RiskPuaniStack(arr, n, tepe);
      }
}

void KisiRiskPuaniSirala(RiskPuani *arr, int n)
{
   for (int i = n / 2 - 1; i >= 0; i--)
   RiskPuaniStack(arr, n, i);

   for (int i=n-1; i>=0; i--)
   {

      yerDegistir(RiskPuani,arr[0], arr[i]);


      RiskPuaniStack(arr, i, 0);
   }
}
void MahalleRiskPuaniStack(MahalleRiskPuani *arr, int n, int kok)
{
   int tepe = kok;
   int sol = 2*kok + 1;
   int sag = 2*kok + 2;


   if (sol < n && arr[sol].mahalleriskPuani < arr[tepe].mahalleriskPuani)
   tepe = sol;

   if (sag < n && arr[sag].mahalleriskPuani < arr[tepe].mahalleriskPuani)
   tepe = sag;

   if (tepe != kok)
      {

      yerDegistir(MahalleRiskPuani, arr[kok], arr[tepe]);
      MahalleRiskPuaniStack(arr, n, tepe);
      }
}

void MahalleRiskPuaniSirala(MahalleRiskPuani *arr, int n)
{

   for (int i = n / 2 - 1; i >= 0; i--)
   MahalleRiskPuaniStack(arr, n, i);

   for (int i=n-1; i>=0; i--)
   {
      yerDegistir(MahalleRiskPuani,arr[0], arr[i]);
      MahalleRiskPuaniStack(arr, i, 0);
   }
}
