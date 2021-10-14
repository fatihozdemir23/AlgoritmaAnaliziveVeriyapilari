#ifndef AVL_H
#define AVL_H
#include "AVLNode.h"
class AVL
{
 public:
        AVLNode *root;
         AVL();
        ~AVL();
        int calheight(AVLNode *p);
        int bf(AVLNode *n);
        AVLNode* llrotation(AVLNode *n);
        AVLNode* rrrotation(AVLNode *n);
        AVLNode* rlrotation(AVLNode *n);
        AVLNode* lrrotation(AVLNode *n);
        AVLNode* insert(AVLNode *r,MGorusmeSuresi data);
        MGorusmeSuresi& operator=(MGorusmeSuresi& rhs){return rhs;}
        void listele(AVLNode *root);
};

#endif
