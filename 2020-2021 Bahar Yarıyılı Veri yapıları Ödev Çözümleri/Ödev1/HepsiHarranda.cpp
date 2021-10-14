#include "HepsiHarranda.h"
HepsiHarranda::HepsiHarranda()
{
f.FileInit("musteriler.txt");
kayitSayisi=f.rows;
musteri=new Musteri[kayitSayisi];
gorusme=new Gorusme[kayitSayisi];
mg=new MGorusmeSuresi[kayitSayisi];
heap=MaxHeap(kayitSayisi,musteri);
TemsilciListesi();
}

HepsiHarranda::~HepsiHarranda()
{
    //dtor
}
void HepsiHarranda::gorusmeDetay(){
cout<<"GorusmeId\tMusteriId\tTemsilciId\tOncelikPuani\tGorusmeBaslama\tGorusmeBitis"<<endl;
for(int i=0;i<kayitSayisi;i++){
cout<<gorusme[i].GetgorusmeID()<<"\t\t";
cout<<gorusme[i].GetmusteriID()<<"\t\t";
cout<<gorusme[i].GettemsilciID()<<"\t\t";
cout<<gorusme[i].GetoncelikPuani()<<"\t\t";
cout<<gorusme[i].GetgorBaslama()<<"\t\t";
cout<<gorusme[i].GetgorBitis()<<endl;

}
}
void HepsiHarranda::gorusmeYap(){
int i=0;
while(!cyss.isEmpty()){
Temsilci t;
t.SettemsilciID(qtemsilci.Bastaki().GettemsilciID());
t.SettemsilciAdi(qtemsilci.Bastaki().GettemsilciAdi());
gorusme[i].SetgorusmeID(i+1);
gorusme[i].SettemsilciID(t.GettemsilciID());
gorusme[i].SetmusteriID(cyss.Bastaki().GetmusteriID());
gorusme[i].SetoncelikPuani(cyss.Bastaki().GetoncelikPuani());
gorusme[i].SetgorBaslama(m.saatHesap(0));
gorusme[i].SetgorBitis(m.saatHesap(cyss.Bastaki().GetgorusmeSuresi()));
mg[i].SetgorusmeSuresi(cyss.Bastaki().GetgorusmeSuresi());
mg[i].SetmusteriAdi(cyss.Bastaki().GetmusteriAdi());
root=avl.insert(root,mg[i]);
cyss.dequeue();
qtemsilci.dequeue();
qtemsilci.enqueue(t);
i++;
}
}
void HepsiHarranda::gorusmeListele(){
avl.listele(root);
}
void HepsiHarranda::oncelikPuaniveGorusmeSuresiHesapla(){
for(int i=0;i<kayitSayisi;i++){
 musteri[i].SetmusteriID(m.stoi(f.Matris[i][0]));
 musteri[i].SetmusteriAdi(f.Matris[i][1]);
 musteri[i].SetuyelikDurumu(m.stoi(f.Matris[i][2]));
 musteri[i].SetcuzdanDurumu(m.stoi(f.Matris[i][3]));
 musteri[i].SetaylikHarcama(m.stoi(f.Matris[i][4]));
 musteri[i].SetyorumSayisi(m.stoi(f.Matris[i][5]));
 musteri[i].SeturunCesidi(m.stoi(f.Matris[i][6]));
 musteri[i].SetislemTuru(m.stoi(f.Matris[i][7]));
 musteri[i].SetoncelikPuani(oncelikPuaniHesapla(musteri,i));//Oncelik Puani hesaplaniyor
 musteri[i].SetgorusmeSuresi(gorusmeSuresiHesapla(musteri,i));//Gorusme Suresi hesaplaniyor
cyss.enqueue(musteri[i]);//musteri cyss kuyruguna ekleniyor
}

}
void HepsiHarranda::musteriKayitEkle(){

for(int i=0;i<kayitSayisi;i++){
heap.insert(musteri[i].GetoncelikPuani());
}
}
int HepsiHarranda::oncelikPuaniHesapla(Musteri *musteri,int i){

int uyelikDurumu=0,cuzdanDurumu=0,aylikHarcama=0,yorumSayisi=0,urunCesidi=0;
//üyelik durumu
switch(musteri[i].GetuyelikDurumu())
{
case 1:
    uyelikDurumu=10;
    break;
case 0:
    uyelikDurumu=0;
    break;
}
//cüzdan durumu
switch(musteri[i].GetcuzdanDurumu())
{
case 1:
    cuzdanDurumu=15;
    break;
case 0:
    cuzdanDurumu=0;
    break;
}
//aylyk harcama
if(musteri[i].GetaylikHarcama()>=0 && musteri[i].GetaylikHarcama()<=99 )
    aylikHarcama=0;
else if(musteri[i].GetaylikHarcama()>=100 && musteri[i].GetaylikHarcama()<=999 )
    aylikHarcama=5;
else if(musteri[i].GetaylikHarcama()>=1000 && musteri[i].GetaylikHarcama()<=3999 )
    aylikHarcama=10;
else if(musteri[i].GetaylikHarcama()>=4000)
    aylikHarcama=15;
//yorum sayysy
if(musteri[i].GetyorumSayisi()>=0 && musteri[i].GetaylikHarcama()<=1 )
    yorumSayisi=0;
else if(musteri[i].GetyorumSayisi()>=2 && musteri[i].GetyorumSayisi()<=7 )
    yorumSayisi=5;
else if(musteri[i].GetyorumSayisi()>=8)
    yorumSayisi=10;

//ürün çesidi
if(musteri[i].GeturunCesidi()>=0 && musteri[i].GeturunCesidi()<=1 )
    urunCesidi=0;
else if(musteri[i].GeturunCesidi()>=2 && musteri[i].GeturunCesidi()<=5 )
    urunCesidi=5;
else if(musteri[i].GeturunCesidi()>=6 && musteri[i].GeturunCesidi()<10 )
    urunCesidi=10;
else if(musteri[i].GeturunCesidi()>=10)
    urunCesidi=15;
return uyelikDurumu+cuzdanDurumu+aylikHarcama+yorumSayisi+urunCesidi;
}
int HepsiHarranda::gorusmeSuresiHesapla(Musteri *musteri,int i){
    int islemSuresi=0,oncelikPuanKatkisi=0;
 switch(musteri[i].GetislemTuru())
{
case 1:
    islemSuresi=3;
    break;
case 2:
    islemSuresi=8;
    break;
case 3:
    islemSuresi=7;
    break;
case 4:
    islemSuresi=6;
    break;
case 5:
    islemSuresi=4;
    break;
}
if(musteri[i].GetoncelikPuani()>=15 && musteri[i].GetoncelikPuani()<40)
    oncelikPuanKatkisi=3;
else if(musteri[i].GetoncelikPuani()>=40)
    oncelikPuanKatkisi=5;
return islemSuresi+oncelikPuanKatkisi;
}
void  HepsiHarranda::TemsilciListesi(){
Temsilci *temsilciler=new Temsilci[5];
temsilciler[0].SettemsilciID(1);
temsilciler[0].SettemsilciAdi("Temsilci1");

temsilciler[1].SettemsilciID(2);
temsilciler[1].SettemsilciAdi("Tesmilci2");

temsilciler[2].SettemsilciID(3);
temsilciler[2].SettemsilciAdi("Tesmilci3");

temsilciler[3].SettemsilciID(4);
temsilciler[3].SettemsilciAdi("Tesmilci4");

temsilciler[4].SettemsilciID(5);
temsilciler[4].SettemsilciAdi("Tesmilci5");
qtemsilci.enqueue(temsilciler[0]);
qtemsilci.enqueue(temsilciler[1]);
qtemsilci.enqueue(temsilciler[2]);
qtemsilci.enqueue(temsilciler[3]);
qtemsilci.enqueue(temsilciler[4]);
}
