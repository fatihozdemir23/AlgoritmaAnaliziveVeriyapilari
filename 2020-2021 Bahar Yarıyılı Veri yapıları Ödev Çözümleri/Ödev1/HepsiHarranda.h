#ifndef HEPSIHARRANDA_H
#define HEPSIHARRANDA_H
#include "FileAction.h"
#include "QueueTemsilci.h"
#include "CustomMethod.h"
#include "Musteri.h"
#include "MaxHeap.h"
#include "PQueueCYSS.h"
#include "Gorusme.h"
#include "AVL.h"
class HepsiHarranda
{
 public:
         HepsiHarranda();
        ~HepsiHarranda();
        void oncelikPuaniveGorusmeSuresiHesapla();
        void musteriKayitEkle();
        void DosyadanOku();
        void gorusmeYap();
        void gorusmeDetay();
        void gorusmeListele();
        PQueueCYSS cyss;
         MaxHeap heap;


    private:
        AVL avl;
        AVLNode *root=NULL;
        Musteri *musteri;
        QueueTemsilci qtemsilci;
        Gorusme *gorusme;
        MGorusmeSuresi *mg;
        FileAction f;
        int kayitSayisi;
        CustomMethod m;

        int oncelikPuaniHesapla(Musteri *musteri,int i);
        int gorusmeSuresiHesapla(Musteri *musteri,int i);
        void TemsilciListesi();

};

#endif
