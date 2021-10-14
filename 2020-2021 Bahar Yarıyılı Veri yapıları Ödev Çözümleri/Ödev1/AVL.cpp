#include "AVL.h"
AVL::AVL()
{
   root=NULL;
}

AVL::~AVL()
{
    //dtor
}
int AVL::calheight(AVLNode *p){
if(p->left && p->right){
            if (p->left->height < p->right->height)
                return p->right->height + 1;
            else return  p->left->height + 1;
            }
            else if(p->left && p->right == NULL){
               return p->left->height + 1;
            }
            else if(p->left ==NULL && p->right){
               return p->right->height + 1;
            }
            return 0;
}
int AVL::bf(AVLNode *n){
 if(n->left && n->right){
                return n->left->height - n->right->height;
            }
            else if(n->left && n->right == NULL){
                return n->left->height;
            }
            else if(n->left== NULL && n->right ){
                return -n->right->height;
            }
}
AVLNode* AVL::llrotation(AVLNode *n){
        AVLNode *p;
        AVLNode *tp;
        p = n;
        tp = p->left;

        p->left = tp->right;
        tp->right = p;
        return tp;
}
AVLNode* AVL:: rrrotation(AVLNode *n){
        AVLNode *p;
        AVLNode *tp;
        p = n;
        tp = p->right;

        p->right = tp->left;
        tp->left = p;

        return tp;
}
AVLNode* AVL::rlrotation(AVLNode *n){
        AVLNode *p;
        AVLNode *tp;
        AVLNode *tp2;
        p = n;
        tp = p->right;
        tp2 =p->right->left;

        p -> right = tp2->left;
        tp ->left = tp2->right;
        tp2 ->left = p;
        tp2->right = tp;

        return tp2;
}
AVLNode* AVL::lrrotation(AVLNode *n){
        AVLNode *p;
        AVLNode *tp;
        AVLNode *tp2;
        p = n;
        tp = p->left;
        tp2 =p->left->right;

        p -> left = tp2->right;
        tp ->right = tp2->left;
        tp2 ->right = p;
        tp2->left = tp;

        return tp2;
}
AVLNode* AVL::insert(AVLNode *r,MGorusmeSuresi data){
       if(r==NULL){
           AVLNode *n=new AVLNode();
            n->data = data;
            r = n;
            r->left = r->right = NULL;
            r->height = 1;
            return r;
        }
        else{
            if(data.GetgorusmeSuresi() < r->data.GetgorusmeSuresi())
            r->left = insert(r->left,data);
            else
            r->right = insert(r->right,data);
        }

        r->height = calheight(r);

        if(bf(r)==2 && bf(r->left)==1){
            r = llrotation(r);
        }
        else if(bf(r)==-2 && bf(r->right)==-1){
            r = rrrotation(r);
        }
        else if(bf(r)==-2 && bf(r->right)==1){
            r = rlrotation(r);
        }
        else if(bf(r)==2 && bf(r->left)==-1){
            r = lrrotation(r);
        }

        return r;

}
void AVL::listele(AVLNode *root){

if(root != NULL)
    {
        listele(root->right);
        cout << root->data.GetgorusmeSuresi()<<" dk\t\t"<<root->data.GetmusteriAdi()<<endl;
        listele(root->left);
    }
}

