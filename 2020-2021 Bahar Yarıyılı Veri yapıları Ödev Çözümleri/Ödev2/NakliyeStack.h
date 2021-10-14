#ifndef NAKLIYESTACK_H
#define NAKLIYESTACK_H
#include "NakliyeNode.h"
#include <iostream>
#include <string>
using namespace std;
class NakliyeStack
{
private:
        NakliyeNode* root;
        void NakliyeStackBosalt();
public:
int elemanSayisi;
		 NakliyeStack();
		~NakliyeStack();
		NakliyeStack(const NakliyeStack& rhs):NakliyeStack(){*this=rhs;}
		Gonderiler begin()const{return root->data;}
		NakliyeNode* end()const{return NULL;}
		bool isEmpty()const;
		void push(Gonderiler& value);
		void print()const;
		void pop();
        Gonderiler top()const;
        int size()const;
       NakliyeStack& assign(const NakliyeStack& rhs);
       NakliyeStack& operator=(const NakliyeStack& rhs){return assign(rhs);}
       friend ostream & operator << (ostream &out,  Gonderiler &gonderi);
};
#endif
