#include "PQueueCYSS.h"
PQueueCYSS::PQueueCYSS()
{
    root=NULL;
    tail=NULL;
    musteriSayisi=0;
}

PQueueCYSS::~PQueueCYSS()
{
  makeEmpty();
}
void PQueueCYSS::enqueue(Musteri& value)
{
CYSSNode *tmp, *temp1;
            tmp = new CYSSNode(value);
            tmp->data = value;

            if (root == NULL || value.GetoncelikPuani()> root->data.GetoncelikPuani())
            {
                tmp->next = root;
                root = tmp;
            }
            else
            {
                temp1 = root;
                while (temp1->next != NULL && temp1->next->data.GetoncelikPuani() >= value.GetoncelikPuani())
                temp1=temp1->next;
                tmp->next = temp1->next;
                temp1->next = tmp;
            }
musteriSayisi++;
}
void PQueueCYSS::dequeue()
{
if(!isEmpty()){
    CYSSNode* temp=root;
    if(root==tail)
    tail=temp->next;
    root=root->next;
    delete temp;
    musteriSayisi--;
    }
}
void PQueueCYSS::print()const{

  CYSSNode* temp=root;
  cout<<"Ad Soyad"<<"\t\tOncelik Puan"<<endl;
  while(temp!=NULL){
    cout<<temp->data.GetmusteriAdi()<<"\t\t"<<temp->data.GetgorusmeSuresi();
    temp=temp->next;
     cout<<endl;
  }
}

void PQueueCYSS::makeEmpty(){
    while(!isEmpty())
        dequeue();
}

