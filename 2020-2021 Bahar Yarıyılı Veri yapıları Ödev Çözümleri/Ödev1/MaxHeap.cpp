#include "MaxHeap.h"
#include <iostream>
#include <string>
#include <sstream>
#define swap(type, i, j) {type T = i; i=j; j=T;}
using namespace std;

MaxHeap::MaxHeap(int cap,Musteri *musteri)
{
hlength=0;
size=cap;
arr=musteri;

}
MaxHeap::MaxHeap()
{


}
void MaxHeap::insert(int val)
{
if(hlength==size) {return;}

else{

hlength++;

int i=hlength-1;
arr[i].SetoncelikPuani(val);
while (arr[i].GetoncelikPuani()>arr[parent (i)].GetoncelikPuani())
{
        swap(Musteri,arr[i],arr[parent(i)]);
        i=parent(i);
}

}}
void MaxHeap::show(){
for(int i=0;i<hlength;i++){
    cout<<arr[i].GetmusteriAdi()<<"-"<<arr[i].GetoncelikPuani()<<endl;
}
}
void MaxHeap::heapify(Musteri *arr, int i) {


if(left(i)==hlength) {

return;
}
while(left(i)<hlength) {

    if(right(i)==hlength) {

        if(arr[left(i)].GetoncelikPuani()>arr[i].GetoncelikPuani())
        {
            swap(Musteri,arr[left(i)],arr[i]);
             i=left(i);
        }
break;
}
else if(right(i) <hlength) {


if(arr[left(i)].GetoncelikPuani()>arr[right (i)].GetoncelikPuani())
    {
    if(arr[left(i)].GetoncelikPuani()>arr[i].GetoncelikPuani())
        {

              swap(Musteri,arr[left(i)],arr[i]);
             i=left(i);
        }

else
break;

}

else if(arr[right(i)].GetoncelikPuani()>arr[left(i)].GetoncelikPuani())
{
    if(arr[right(i)].GetoncelikPuani()>arr[i].GetoncelikPuani())
    {

         swap(Musteri,arr[right(i)],arr[i]);

         i=right(i);
    }
else
break;
}
}
}

}

void MaxHeap::heapsort(){
heapify(arr, 0);
for (int i=hlength-1; i>0; i--)
{
swap(Musteri,arr[0],arr[i]);
hlength--;
heapify(arr, 0);
cout<<arr[i].GetmusteriAdi()<<"-"<<arr[i].GetoncelikPuani()<<endl;
}

}

