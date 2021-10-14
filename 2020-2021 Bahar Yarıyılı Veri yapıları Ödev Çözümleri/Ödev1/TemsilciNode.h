#ifndef TEMSILCINODE_H
#define TEMSILCINODE_H
#include "Temsilci.h"
class TemsilciNode
{
public:
        Temsilci data;
        TemsilciNode* next;
        TemsilciNode(const Temsilci& data=Temsilci(),TemsilciNode* next=NULL):data(data),next(next){};
};

#endif
