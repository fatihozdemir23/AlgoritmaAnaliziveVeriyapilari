#ifndef KUYRUKSUBE_H
#define KUYRUKSUBE_H
#include "SubeNode.h"
#include <string>
#include <iostream>
using namespace std;
class KuyrukSube
{

public:

         KuyrukSube();
        ~KuyrukSube();
        KuyrukSube(const KuyrukSube& rhs):KuyrukSube(){*this=rhs;}//kopyalama kurucusu
        bool isEmpty()const{return root==NULL;}
        void enqueue(const Subeler& value);
        void dequeue();
        void print()const;
        int size()const;
        Subeler back()const{if(!isEmpty())return tail->data;}
        Subeler front()const{if(!isEmpty())return root->data;}

private:
        SubeNode* tail;
        int ToplamDesi;
        void makeEmpty();
        SubeNode* root;

};



#endif // KUYRUKSUBE_H
