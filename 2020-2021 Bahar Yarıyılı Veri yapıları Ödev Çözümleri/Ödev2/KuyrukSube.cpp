#include "KuyrukSube.h"

KuyrukSube::KuyrukSube()
{
    root=NULL;
    tail=NULL;
    ToplamDesi=0;
}
KuyrukSube::~KuyrukSube(){makeEmpty();}
void KuyrukSube::enqueue(const Subeler& value){

            SubeNode *tmp, *temp1;
            tmp = new SubeNode(value);
            tmp->data = value;

            if (root == NULL || value.Oncelik< root->data.Oncelik)
            {
                tmp->next = root;
                root = tmp;
            }
            else
            {
                temp1 = root;
                while (temp1->next != NULL && temp1->next->data.Oncelik <= value.Oncelik)
                temp1=temp1->next;
                tmp->next = temp1->next;
                temp1->next = tmp;
            }
    ToplamDesi+=value.Desi;
}

void KuyrukSube::print()const{
  SubeNode* temp=root;
  while(temp!=NULL){
    cout<<temp->data.GonderiId<<" ";
    cout<<temp->data.Oncelik<<" ";
    cout<<temp->data.TurId<<" ";
    cout<<temp->data.Sure<<endl;
    temp=temp->next;
  }
  cout<<endl;
}

void KuyrukSube::dequeue(){
    if(!isEmpty()){
    SubeNode* temp=root;
    if(root==tail)
    tail=temp->next;
    root=root->next;

    ToplamDesi-=temp->data.Desi;
    delete temp;
    }
}

int KuyrukSube::size()const{ return ToplamDesi;}

void KuyrukSube::makeEmpty(){
    while(!isEmpty())
        dequeue();
}

