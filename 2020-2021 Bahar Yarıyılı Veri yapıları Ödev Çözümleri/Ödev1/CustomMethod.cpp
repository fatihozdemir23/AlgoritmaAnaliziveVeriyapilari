#include "CustomMethod.h"
CustomMethod::CustomMethod()
{
   saat=9;
   dakika=0;
}

CustomMethod::~CustomMethod()
{
    //dtor
}
string CustomMethod::saatHesap(int d){
string h,m,newTime;
dakika+=d;
if(dakika>=60){
saat++;
dakika=dakika-60;
}else{
saat=saat;
dakika=dakika;
}
if(saat>=24){
saat=24-saat;
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
string CustomMethod::itos(int i){//int to string
  string str;
  stringstream ss;
  ss << i;
  ss >> str;
  return str;
}
int CustomMethod::stoi(string s){//string to int
int num;
  stringstream ss;
  ss << s;
  ss >> num;
  return num;
}

