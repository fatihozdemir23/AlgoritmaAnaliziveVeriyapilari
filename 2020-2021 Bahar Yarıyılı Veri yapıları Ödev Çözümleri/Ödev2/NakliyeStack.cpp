#include "NakliyeStack.h"
#include <iostream>
using namespace std;
NakliyeStack::NakliyeStack(){
root=NULL;
elemanSayisi=0;
}
NakliyeStack::~NakliyeStack()
{
NakliyeStackBosalt();
}
void NakliyeStack::push(Gonderiler& value){

	       NakliyeNode *tmp, *q;
            tmp = new NakliyeNode(value);
            tmp->data = value;

            if (root == NULL || value.GetSubeId()< root->data.GetSubeId())
            {
                tmp->next = root;
                root = tmp;
            }
            else
            {
                q = root;
                while (q->next != NULL && q->next->data.GetSubeId() <= value.GetSubeId())
                q=q->next;
                tmp->next = q->next;
                q->next = tmp;
            }
	elemanSayisi++;
}
void NakliyeStack::print()const{
NakliyeNode* temp=root;
while(temp!=end()){
cout<<temp->data.GetGonderiId()<<" ";
cout<<temp->data.GetTurId()<<" ";
cout<<temp->data.GetSubeId()<<endl;
temp=temp->next;
}

}
void NakliyeStack::pop(){
    if(!isEmpty()){
NakliyeNode* temp=root;
root=temp->next;
delete temp;
elemanSayisi--;
    }
}
bool NakliyeStack::isEmpty()const{
return root==end();
}
Gonderiler NakliyeStack::top()const{
  if(!isEmpty())
      return root->data;
}
int NakliyeStack::size()const{return elemanSayisi;}
void NakliyeStack::NakliyeStackBosalt(){
    while(!isEmpty())
        pop();
}

NakliyeStack& NakliyeStack::assign(const NakliyeStack& rhs){
  NakliyeStackBosalt();//
  elemanSayisi=rhs.elemanSayisi;
    if(!rhs.isEmpty())
        {
        root=new NakliyeNode(rhs.top());
        NakliyeNode* rhsTemp=rhs.root->next;
        NakliyeNode* lhsTemp=root;
        while(rhsTemp!=rhs.end()){
            lhsTemp->next=new NakliyeNode(rhsTemp->data);
            lhsTemp=lhsTemp->next;
            rhsTemp=rhsTemp->next;
        }
        return *this;

    }

}

ostream & operator << (ostream &out, Gonderiler &gonderi)
{
out<<gonderi.GetGonderiId()<<endl;
    return out;
}
