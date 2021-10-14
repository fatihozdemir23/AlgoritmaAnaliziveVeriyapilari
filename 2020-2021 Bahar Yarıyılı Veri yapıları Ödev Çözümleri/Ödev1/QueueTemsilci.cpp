#include "QueueTemsilci.h"
#include <string>
#include <iostream>
using namespace std;
QueueTemsilci::QueueTemsilci()
{
    root=NULL;
    tail=NULL;
}

QueueTemsilci::~QueueTemsilci()
{
makeEmpty();
}
void QueueTemsilci::enqueue(const Temsilci& value)
{

    if(isEmpty()){
      root=new TemsilciNode(value);
      tail=root;
    }
    else{

        tail->next=new TemsilciNode(value);
        tail=tail->next;
    }

}
void QueueTemsilci::dequeue()
{
if(!isEmpty()){
    TemsilciNode* temp=root;
    if(root==tail)
    tail=temp->next;
    root=root->next;
    delete temp;

    }
}
void QueueTemsilci::print()const{

  TemsilciNode* temp=root;
  while(temp!=NULL){
    cout<<temp->data.GettemsilciID()<<" ";
    cout<<temp->data.GettemsilciAdi()<<" ";
    temp=temp->next;
     cout<<endl;
  }



}

void QueueTemsilci::makeEmpty(){
    while(!isEmpty())
        dequeue();
}

