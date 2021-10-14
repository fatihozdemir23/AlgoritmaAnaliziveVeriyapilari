#ifndef QUEUETEMSILCI_H
#define QUEUETEMSILCI_H
#include "TemsilciNode.h"
#include <string>
#include <iostream>
using namespace std;
class QueueTemsilci
{
	 public:
         QueueTemsilci();
        ~QueueTemsilci();
        bool isEmpty()const{return root==NULL;}
        void enqueue(const Temsilci& value);
        void dequeue();
        void print()const;
        Temsilci Sondaki()const{if(!isEmpty())return tail->data;}
        Temsilci Bastaki()const{if(!isEmpty())return root->data;}

    private:
        TemsilciNode* root;
        TemsilciNode* tail;
        void makeEmpty();
};

#endif
