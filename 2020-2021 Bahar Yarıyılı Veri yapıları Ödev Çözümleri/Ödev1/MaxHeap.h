#ifndef MAXHEAP_H
#define MAXHEAP_H
#include "Musteri.h"
class MaxHeap
{
public:
MaxHeap(int cap,Musteri *musteri);
MaxHeap();
Musteri *arr;
int size;
int hlength;
int parent (int i) {return (i-1)/2;}
int left(int i) {return 2*i+1;}
int right (int i) {return 2*i+2;}
void insert(int key);
void heapify(Musteri *arr, int i);
void show();
void heapsort();
};

#endif
