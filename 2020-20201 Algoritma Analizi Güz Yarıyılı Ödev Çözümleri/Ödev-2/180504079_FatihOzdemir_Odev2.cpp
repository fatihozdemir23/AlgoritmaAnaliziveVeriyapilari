#include <limits.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <locale.h>
#include <string>
#include <iomanip>
#define haritaDugumSayisi 40
using namespace std;
string rotaTemp;
typedef struct{
int Id;
string Boy;
int Kalori;
int Hacim;
}Pizza;
typedef struct{
int PizzaId;
int Konum;
}PizzaYerlestir;
typedef struct{
int Maliyet;
string Rota;
string DsmnId;
float gEneji=0;
float kalanEnerji=0;
int dusmanEnerji=0;
float tgZaman=0;
int dharcananZaman=0;
int PEnerji=0;
int pizzaHacim=0;
}HaritaBilgisi;
typedef struct{
int Id;
int Konum;
int Sure;
int Kalori;
}Dusman;
int pizzaSayisi=0;
Pizza *pizzaBilgisi=new Pizza[4];
HaritaBilgisi *haritaBilgisi=new HaritaBilgisi[40];
PizzaYerlestir *pizzaYerlestir;
Dusman *dusmanBilgisi=new Dusman[6];
int pizzaArama ( int N, int Aranan);
int DusmanArama( int N, int Aranan);
int max(int a, int b) { return (a > b) ? a : b; };
string RotaYazdir(int rotaId[], int j,int i);
void enerjiMiktariHesapla(int dist[], int n,int parent[]);
int enKucukUzaklik(int uzakliklar[], bool ziyaretEdilenDugum[]);
int sirtCantasi(int W, HaritaBilgisi *wt,HaritaBilgisi *val, int n);
void EnKisaYolAlgoritmasi(int **haritaMatrisi, int ev);
void pizzaOlustur();
int fsatir,fstun;
int **ReadFile(string fileName);
void SatirStunHesapla(string fileName);
void grafOlustur();
void optimumYolBul();
void raporVer();
void PizzaBilgileri();
void DusmanBilgileri();
int **MatrisOlustur(int rows, int columns);
int **KanalBaglantiBilgileri;

int main(){


try{
 pizzaOlustur();
 grafOlustur();
 optimumYolBul();
 raporVer();



}
catch(exception e){cout<<"Dosya Okuma Hatasi";}}
void raporVer(){
cout<<"******************************"<<endl;
for(int i=1;i<40;i++){

cout<<"Rota:"<<"Ev->"<<haritaBilgisi[i].Rota<<"Ev"<<"\n";
cout<<"Karsilasilan Dusman:"<<haritaBilgisi[i].DsmnId<<"\n";
cout<<"Maliyet:"<<haritaBilgisi[i].Maliyet<<"\n";
cout<<"Gerekli Enerji:"<<haritaBilgisi[i].gEneji<<"\n";
cout<<"Toplanan Pizza Enerji:"<<haritaBilgisi[i].PEnerji<<"\n";
cout<<"Dusman Enerji:"<<haritaBilgisi[i].dusmanEnerji<<"\n";
cout<<"Dusman Zaman(dk):"<<haritaBilgisi[i].dharcananZaman<<"\n";
cout<<"Kalan Enerji:"<<haritaBilgisi[i].kalanEnerji<<"\n";
cout<<"********************************************************"<<"\n\n";
}
}
void optimumYolBul(){
EnKisaYolAlgoritmasi(KanalBaglantiBilgileri,0);
}
void pizzaOlustur(){
  int sayac=1,konum,pId;
  DusmanBilgileri();
  PizzaBilgileri();
  cout<<"Pizza sayisi:";
  cin>>pizzaSayisi;
pizzaYerlestir=new PizzaYerlestir[pizzaSayisi];
  while(sayac<=pizzaSayisi){
    cout<<sayac<<".Konum ID:";
    cin>>konum;
    cout<<"Pizza ID:";
    cin>>pId;
    pizzaYerlestir[sayac-1].Konum=konum;
    pizzaYerlestir[sayac-1].PizzaId=pId;
    sayac++;
  }
}
void EnKisaYolAlgoritmasi(int **haritaMatrisi, int ev)
{


    int enKisaMesafe[haritaDugumSayisi];
    bool ziyeretEdilen[haritaDugumSayisi];
    int rotaId[haritaDugumSayisi];
    for (int i = 0; i < haritaDugumSayisi; i++)
    {
        rotaId[0] = -1;

        enKisaMesafe[i] = INT_MAX;
        ziyeretEdilen[i] = false;
    }
    enKisaMesafe[ev] = 0;
    for (int j = 0; j < haritaDugumSayisi - 1; j++) {

        int u = enKucukUzaklik(enKisaMesafe, ziyeretEdilen);


        ziyeretEdilen[u] = true;
        for (int v = 0; v < haritaDugumSayisi; v++){

            if (!ziyeretEdilen[v] && haritaMatrisi[u][v] &&
                enKisaMesafe[u] + haritaMatrisi[u][v] < enKisaMesafe[v])
            {
                rotaId[v] = u;
                enKisaMesafe[v] = enKisaMesafe[u] + haritaMatrisi[u][v];
            }
        }
    }

   enerjiMiktariHesapla(enKisaMesafe, haritaDugumSayisi,rotaId);

}
void grafOlustur(){
KanalBaglantiBilgileri=ReadFile("KanalBaglantiBilgileri.txt");

}
int pizzaArama ( int N, int Aranan)
{

    int Ortadaki,Sol=0,Sag=N-1;
    while (Sol<=Sag)
    {
        Ortadaki=(Sol+Sag)/2;
        if(Aranan ==pizzaYerlestir[Ortadaki].Konum)
            return Ortadaki;
        else if(Aranan>pizzaYerlestir[Ortadaki].Konum)
        Sol=Ortadaki+1;
        else
            Sag=Ortadaki-1;
    }
    return -1;
}
int DusmanArama( int N, int Aranan)
{

    int Ortadaki,Sol=0,Sag=N-1;
    while (Sol<=Sag)
    {
        Ortadaki=(Sol+Sag)/2;
        if(Aranan ==dusmanBilgisi[Ortadaki].Konum)
            return Ortadaki;
        else if(Aranan>dusmanBilgisi[Ortadaki].Konum)
        Sol=Ortadaki+1;
        else
            Sag=Ortadaki-1;
    }
    return -1;
}
void SatirStunHesapla(string fileName){
string karakter,satir;
int dr=0,dc;
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
int **ReadFile(string fileName){
SatirStunHesapla(fileName);
int deger;
int **matrisTemp=MatrisOlustur(fsatir,fstun);
string karakter,satir;int rows,cols;
ifstream dosya(fileName.c_str(),ios::in);
if(dosya==NULL){
cout<<"Dosya Okunamadi!!!";

}else{

 while(getline(dosya,satir)){
  stringstream karakterlerzinciri(satir);
  cols=0;
while(getline(karakterlerzinciri,karakter,',')){
stringstream val(karakter);
val>>deger;
matrisTemp[rows][cols]=deger;cols++;}rows++;}
dosya.close();
return matrisTemp;
}
}

int **MatrisOlustur(int rows, int columns) {

  int **matris = new int*[rows];

  for (int i = 0; i < rows; i++)

  {

   matris[i] = new int[columns];

  }
return matris;

 }

 void PizzaBilgileri(){

 pizzaBilgisi[0].Id=1;
 pizzaBilgisi[0].Boy="Büyük";
 pizzaBilgisi[0].Kalori=1000;
 pizzaBilgisi[0].Hacim=1000;

 pizzaBilgisi[1].Id=2;
 pizzaBilgisi[1].Boy="Orta Boy";
 pizzaBilgisi[1].Kalori=500;
 pizzaBilgisi[1].Hacim=600;

 pizzaBilgisi[2].Id=3;
 pizzaBilgisi[2].Boy="Küçük Boy";
 pizzaBilgisi[2].Kalori=300;
 pizzaBilgisi[2].Hacim=400;

 pizzaBilgisi[3].Id=4;
 pizzaBilgisi[3].Boy="Dilim Pizza";
 pizzaBilgisi[3].Kalori=100;
 pizzaBilgisi[3].Hacim=200;


 }


 void DusmanBilgileri(){

 dusmanBilgisi[0].Id=1;
 dusmanBilgisi[0].Konum=4;
 dusmanBilgisi[0].Kalori=60;
 dusmanBilgisi[0].Sure=10;

 dusmanBilgisi[1].Id=2;
 dusmanBilgisi[1].Konum=2;
 dusmanBilgisi[1].Kalori=80;
 dusmanBilgisi[1].Sure=5;

 dusmanBilgisi[2].Id=3;
 dusmanBilgisi[2].Konum=5;
 dusmanBilgisi[2].Kalori=100;
 dusmanBilgisi[2].Sure=10;

 dusmanBilgisi[3].Id=4;
 dusmanBilgisi[3].Konum=7;
 dusmanBilgisi[3].Kalori=50;
 dusmanBilgisi[3].Sure=5;

 dusmanBilgisi[4].Id=5;
 dusmanBilgisi[4].Konum=11;
 dusmanBilgisi[4].Kalori=300;
 dusmanBilgisi[4].Sure=30;

 dusmanBilgisi[5].Id=6;
 dusmanBilgisi[5].Konum=15;
 dusmanBilgisi[5].Kalori=200;
 dusmanBilgisi[5].Sure=20;
 }
int sirtCantasi(int W, HaritaBilgisi *wt,HaritaBilgisi *val, int n)
{


    if (n == 0 || W == 0)
        return 0;


    if (wt[n - 1].pizzaHacim > W)
        return sirtCantasi(W, wt,val, n - 1);

    else
        return max(
            val[n - 1].PEnerji
                + sirtCantasi(W - wt[n - 1].pizzaHacim,
                           wt,val, n - 1),
            sirtCantasi(W, wt,val, n - 1));
}


int enKucukUzaklik(int uzakliklar[], bool ziyaretEdilenDugum[])
{

    int min = INT_MAX, min_index;

    for (int i = 0; i < haritaDugumSayisi; i++)
        if (ziyaretEdilenDugum[i] == false && uzakliklar[i] <= min)
            min = uzakliklar[i], min_index = i;

    return min_index;//en küçük uzaklığa sahip düğüm indeksi
}

string RotaYazdir(int rotaId[], int j,int i)
{
    string temp="";
    string pizza="";
    if (rotaId[j]==-1)
        return "";

RotaYazdir(rotaId, rotaId[j],i);
int result=pizzaArama(pizzaSayisi,j);
int dusmanresult=DusmanArama(6,j);
if(result!=-1){
        pizza="(pizza)";
         haritaBilgisi[i].PEnerji=haritaBilgisi[i].PEnerji+pizzaBilgisi[result].Kalori;
         haritaBilgisi[i].pizzaHacim=haritaBilgisi[i].pizzaHacim+pizzaBilgisi[result].Hacim;



}
   if(dusmanresult!=-1){

        stringstream dId;dId<<+dusmanBilgisi[dusmanresult].Id;
       temp="(Dusman)";
       haritaBilgisi[i].dusmanEnerji=dusmanBilgisi[dusmanresult].Kalori;
       haritaBilgisi[i].dharcananZaman=dusmanBilgisi[dusmanresult].Sure;
        haritaBilgisi[i].DsmnId="D"+dId.str();
        }

stringstream  j_str;j_str<<j;
rotaTemp=rotaTemp+"N"+j_str.str()+temp+pizza+"->";

return rotaTemp;

}

void enerjiMiktariHesapla(int dist[], int n,int parent[])
{
    for (int i = 0; i < haritaDugumSayisi; i++)
    {
 haritaBilgisi[i].Maliyet=dist[i];
 haritaBilgisi[i].gEneji=dist[i]*0.2;
 haritaBilgisi[i].Rota=RotaYazdir(parent, i,i);
 haritaBilgisi[i].kalanEnerji=500-haritaBilgisi[i].gEneji-haritaBilgisi[i].dusmanEnerji;

 rotaTemp="";

    }


}
