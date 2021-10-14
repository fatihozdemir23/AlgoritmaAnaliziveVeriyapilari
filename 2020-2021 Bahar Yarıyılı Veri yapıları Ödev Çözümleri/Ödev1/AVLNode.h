#ifndef AVLNODE_H
#define AVLNODE_H
#include "MGorusmeSuresi.h"
class AVLNode
{
	 public:
       AVLNode *left;
       AVLNode *right;
       MGorusmeSuresi data;
       int height;
};

#endif
