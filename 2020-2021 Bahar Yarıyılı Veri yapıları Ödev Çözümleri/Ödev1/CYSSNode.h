#ifndef CYSSNODE_H
#define CYSSNODE_H
#include "Musteri.h"

class CYSSNode
{
	 public:
         CYSSNode() {}
         Musteri  data;
         CYSSNode* next;
         CYSSNode(const Musteri& data=Musteri(),CYSSNode* next=NULL):data(data),next(next){};
};

#endif
