#ifndef PQUEUECYSS_H
#define PQUEUECYSS_H
#include "CYSSNode.h"
#include <string>
#include <iostream>
using namespace std;
class PQueueCYSS
{
 public:
         PQueueCYSS();
        ~PQueueCYSS();
        bool isEmpty()const{return root==NULL;}
        void enqueue(Musteri& value);
        void dequeue();
        void print()const;
        int size()const{return musteriSayisi;};
        Musteri Sondaki()const{if(!isEmpty())return tail->data;}
        Musteri Bastaki()const{if(!isEmpty())return root->data;}

    private:
        CYSSNode* root;
        CYSSNode* tail;
        int musteriSayisi;
        void makeEmpty();
};

#endif
