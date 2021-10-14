#ifndef SUBENODE_H
#define SUBENODE_H
#include <string>
#include "Subeler.h"
class SubeNode
{
    public:
         Subeler  data;
         SubeNode* next;
         SubeNode(const Subeler& data=Subeler(),SubeNode* next=NULL):data(data),next(next){};
};
#endif

