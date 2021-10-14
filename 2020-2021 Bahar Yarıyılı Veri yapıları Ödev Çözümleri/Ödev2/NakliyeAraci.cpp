#include "NakliyeAraci.h"
NakliyeAraci::NakliyeAraci(){
toplamGonderi=new ToplamGonderi[5];
}
NakliyeAraci::~NakliyeAraci(){}
void NakliyeAraci::NakliyeAraciYukleme(){

f.DosyaSatirStunHesap("gonderi.txt");
NakliyeStack s=f.GonderiYukle("gonderi.txt");
cout<<endl<<"\tTOPLAM "<<s.size()<<" GONDERI BASARI ILE NAKLIYE ARACINA YUKLENDI"<<endl<<endl;
cout<<"\tYUKLENEN GONDERILERIN DETAYLI RAPORU ASAGIDAKI GIBIDIR."<<endl<<endl;
remove("Sube1.txt");remove("Sube2.txt");remove("Sube3.txt");remove("Sube4.txt");remove("Sube5.txt");
while(!s.isEmpty()){
 int sube_id=s.top().GetSubeId();;
 int tur_id=s.top().GetTurId();
int index =m.GonderiTurAra(m.gonderiTurler,tur_id,6);
int oncelik=m.gonderiTurler[index][1];
int desi=m.gonderiTurler[index][2];
int yuklemsuresi=m.gonderiTurler[index][3];
string gonderiId=s.top().GetGonderiId();
string writeFile=gonderiId+","+m.itos(tur_id)+","+m.itos(oncelik)+","+m.itos(desi)+","+m.itos(yuklemsuresi);
if(sube_id==1){
 f.FileWrite("Sube1.txt",writeFile);
 GonderiTurTopla(tur_id,0);
}else
if(sube_id==2){
    f.FileWrite("Sube2.txt",writeFile);
 GonderiTurTopla(tur_id,1);
}
else
if(sube_id==3){
  f.FileWrite("Sube3.txt",writeFile);
 GonderiTurTopla(tur_id,2);
}
else
if(sube_id==4){
    f.FileWrite("Sube4.txt",writeFile);
 GonderiTurTopla(tur_id,3);
}
else
if(sube_id==5){
 f.FileWrite("Sube5.txt",writeFile);
 GonderiTurTopla(tur_id,4);
}
s.pop();
 }
 int t_desi=0;
 for(int i=0;i<5;i++){
   t_desi+=toplamGonderi[i].T1*m.gonderiTurler[0][2];
   t_desi+=toplamGonderi[i].T2*m.gonderiTurler[1][2];
   t_desi+=toplamGonderi[i].T3*m.gonderiTurler[2][2];
   t_desi+=toplamGonderi[i].T4*m.gonderiTurler[3][2];
   t_desi+=toplamGonderi[i].T5*m.gonderiTurler[4][2];
   t_desi+=toplamGonderi[i].T6*m.gonderiTurler[5][2];
 cout<<"        \t\tSube-"<<i+1<<" "<<endl;
 cout<<"\tToplam Gonderi Kapasitesi "<<t_desi<<" Desimetre Kup"<<endl;t_desi=0;
 cout<<"  -------------------------------------------------------"<<endl;
 cout<<"Gonderi Turu \t1"<<"\t2"<<"\t3"<<"\t4"<<"\t5"<<"\t6"<<endl;
 cout<<"Adet       \t"<<toplamGonderi[i].T1;
 cout<<"\t"<<toplamGonderi[i].T2;
 cout<<"\t"<<toplamGonderi[i].T3;
 cout<<"\t"<<toplamGonderi[i].T4;
 cout<<"\t"<<toplamGonderi[i].T5;
 cout<<"\t"<<toplamGonderi[i].T6<<endl;
 cout<<"Desi\t";
  for(int j=0;j<6;j++){
   cout<<"\t"<<m.gonderiTurler[j][2];

  }
cout<<endl;
  cout<<"Oncelik\t";
  for(int j=0;j<6;j++){
   cout<<"\t"<<m.gonderiTurler[j][1];

  }
  cout<<endl;
  cout<<"Yukleme S.";
  for(int j=0;j<6;j++){
   cout<<"\t"<<m.gonderiTurler[j][3];

  }
  cout<<endl;
 cout<<"Toplam Desi \t"<<toplamGonderi[i].T1*m.gonderiTurler[0][2];
 cout<<"\t"<<toplamGonderi[i].T2*m.gonderiTurler[1][2];
 cout<<"\t"<<toplamGonderi[i].T3*m.gonderiTurler[2][2];
 cout<<"\t"<<toplamGonderi[i].T4*m.gonderiTurler[3][2];
 cout<<"\t"<<toplamGonderi[i].T5*m.gonderiTurler[4][2];
 cout<<"\t"<<toplamGonderi[i].T6*m.gonderiTurler[5][2]<<endl;
 cout<<"Toplam Yuk.S \t"<<toplamGonderi[i].T1*m.gonderiTurler[0][3];
 cout<<"\t"<<toplamGonderi[i].T2*m.gonderiTurler[1][3];
 cout<<"\t"<<toplamGonderi[i].T3*m.gonderiTurler[2][3];
 cout<<"\t"<<toplamGonderi[i].T4*m.gonderiTurler[3][3];
 cout<<"\t"<<toplamGonderi[i].T5*m.gonderiTurler[4][3];
 cout<<"\t"<<toplamGonderi[i].T6*m.gonderiTurler[5][3]<<endl;
 cout<<endl;
 cout<<"  -------------------------------------------------------"<<endl;
 }
}
void NakliyeAraci::GonderiTurTopla(int tur,int index){

switch(tur){
case 1:{
   toplamGonderi[index].T1++;
    toplamGonderi[index].desi=m.gonderiTurler[0][2];
}

    break;
    case 2:{
    toplamGonderi[index].T2++;
    toplamGonderi[index].desi=m.gonderiTurler[1][2];
    }

    break;
    case 3:{
    toplamGonderi[index].T3++;
    toplamGonderi[index].desi=m.gonderiTurler[2][2];
    }

    break;
    case 4:{
    toplamGonderi[index].T4++;
    toplamGonderi[index].desi=m.gonderiTurler[3][2];
    }

    break;
    case 5:{
     toplamGonderi[index].T5++;
    toplamGonderi[index].desi=m.gonderiTurler[4][2];
    }

    break;
    case 6:{
    toplamGonderi[index].T6++;
    toplamGonderi[index].desi=m.gonderiTurler[5][2];
    }

    break;
}
}

void NakliyeAraci::NakliyeAraciIndirme(){
try{
f.DosyaSatirStunHesap("gonderi.txt");
NakliyeStack s=f.GonderiYukle("gonderi.txt");
remove("Nakliye.txt");
if(s.isEmpty())
 cout<<endl<<"\tLÜTFEN ÖNCE NAKLIYE  ARACINA GÖNDERI YÜKLEYINIZ"<<endl;
else{

int top,say=0;string s1,s2;
cout<<endl<<"\tNAKLIYE ARACI SUBELERE GONDERI DAGITIM RAPORU"<<endl<<endl;
  f.FileWrite("Nakliye.txt",m.saatHesap(0)+" Genel Merkezden Çıkış");
cout<<m.saatHesap(0)+" Genel Merkezden Cikis"<<endl;
while(!s.isEmpty()){
top=s.top().GetSubeId();
switch(top){
case 1:{
 s1=m.saatHesap(60);
 f.FileWrite("Nakliye.txt",s1+" Şube1'e varış") ;
cout<<s1+" Sube1'e varis"<<endl;
while(s.top().GetSubeId()==1){
s.pop(); say++;
}
}
break;
case 2:{
s1=m.saatHesap(30);
s2=m.saatHesap(20);
f.FileWrite("Nakliye.txt",s1+" Şube1'den hareket(Toplam "+m.itos(say)+" gonderi indirildi)");
f.FileWrite("Nakliye.txt",s2+" Şube2'e varış");
cout<<s1+" Sube1'den hareket(Toplam "<<say<<" gonderi indirildi)"<<endl;
cout<<s2+" Sube2'e varis"<<endl;say=0;
while(s.top().GetSubeId()==2)
 {
s.pop(); say++;
}
}
break;
case 3:{
s1=m.saatHesap(30);
s2=m.saatHesap(20);
f.FileWrite("Nakliye.txt",s1+" Şube2'den hareket(Toplam "+m.itos(say)+" gonderi indirildi)");
f.FileWrite("Nakliye.txt",s2+" Şube3'e varış");
cout<<s1+" Sube2'den hareket(Toplam "<<say<<" gonderi indirildi)"<<endl;
cout<<s2+" Sube3'e Varis"<<endl;say=0;
while(s.top().GetSubeId()==3)
 {
s.pop(); say++;
}}
break;
case 4:{
s1=m.saatHesap(30);
s2=m.saatHesap(20);
f.FileWrite("Nakliye.txt",s1+" Şube3'ten hareket(Toplam "+m.itos(say)+" gonderi indirildi)");
f.FileWrite("Nakliye.txt",s2+" Şube4'e varış");
cout<<s1+" Sube3'ten hareket(Toplam "<<say<<" gonderi indirildi)"<<endl;
cout<<s2+" Sube4'e Varis"<<endl;say=0;
while(s.top().GetSubeId()==4)
 {
s.pop(); say++;
}

}
break;
case 5:{

s1=m.saatHesap(30);
s2=m.saatHesap(20);
f.FileWrite("Nakliye.txt",s1+" Şube4'den hareket(Toplam "+m.itos(say)+" gonderi indirildi)");
f.FileWrite("Nakliye.txt",s2+" Şube5'e varış");
cout<<s1+" Sube4'ten hareket(Toplam "<<say<<" gonderi indirildi)"<<endl;
cout<<s2+" Sube5'e Varis"<<endl;say=0;
s1=m.saatHesap(30);
s2=m.saatHesap(60);
f.FileWrite("Nakliye.txt",s1+" Şube5'ten hareket(Toplam "+m.itos(s.size())+" gonderi indirildi)");
f.FileWrite("Nakliye.txt",s2+" Genel Merkeze Varış");
cout<<s1+" Sube5'ten hareket(Toplam "<<s.size()<<" gonderi indirildi)"<<endl;
cout<<s2+" Genel Merkeze Varis"<<endl;

while(s.top().GetSubeId()==5 && !s.isEmpty())
{
s.pop();
say++;
}

}
break;

}//switch
}//stack boş değilse

 }
 }

catch(exception hat){
cout<<"hata";
}

}
