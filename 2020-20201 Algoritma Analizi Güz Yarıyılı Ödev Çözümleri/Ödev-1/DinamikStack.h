#ifndef DINAMIKSTACK_H
#define DINAMIKSTACK_H
#include<iostream>
using namespace std;


template < typename T >
class DinamikStack
{
private:
 T* Datas;
 int Top;
 unsigned int yeniBoyut;


public:
 DinamikStack(unsigned int boyut=10);
 ~DinamikStack();
 bool Ekle(T item);
 bool Cikar(T&  item);
 bool bosMu();
 int getBoyut();
 void Genislet(unsigned int boyut=10);
 void YiginBosalt();
 void Yazdir(T &temp);


};
template < typename T >
DinamikStack<T>::DinamikStack(unsigned int boyut)
{
  yeniBoyut=boyut;
  Top=0;
  Datas=new T[boyut];
}
template < typename T >
DinamikStack<T>::~DinamikStack()
{
    yeniBoyut=0;
    Top=0;
  delete[] Datas;
}
template < typename T >
void DinamikStack<T>::YiginBosalt()
{
    yeniBoyut=0;
    Top=0;
   delete[] Datas;
}
template < typename T >
bool DinamikStack<T>::Ekle( T item )
{
  if(Top>=yeniBoyut)
    Genislet();
  Datas[Top]=item;
  Top++;
  return true;

}
template < typename T >
bool DinamikStack<T>::Cikar(T& item)
{
  if(Top<=0)
    return false;
  Top--;
  item=Datas[Top];
  return true;

}
template < typename T >
bool DinamikStack<T>::bosMu()
{
  if(Top==0)
    return true;
else
  return false;

}
template < typename T >
int DinamikStack<T>::getBoyut()
{
 return Top;

}
template < typename T >
void DinamikStack<T>::Genislet(unsigned int ysize)
{
 T *ptemp=new T[yeniBoyut+ysize];
 for(int i=0;i<yeniBoyut;i++)
    ptemp[i]=Datas[i];
 delete[] Datas;
 Datas=ptemp;
yeniBoyut+=ysize;
}
template < typename T >
void DinamikStack<T>::Yazdir(T &temp){
while(Cikar(temp)!=false)
    cout<<temp<<endl;

}
#endif
