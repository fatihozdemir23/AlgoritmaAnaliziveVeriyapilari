#ifndef NAKLIYENODE_H
#define NAKLIYENODE_H
#include <iostream>
#include <string>
#include "Gonderiler.h"
using namespace std;
class NakliyeNode
{
	public:
		Gonderiler data;
		NakliyeNode* next;
		NakliyeNode(const Gonderiler& data=Gonderiler(),NakliyeNode* next=NULL):data(data),next(next){}

};


#endif // NAKLIYENODE_H
