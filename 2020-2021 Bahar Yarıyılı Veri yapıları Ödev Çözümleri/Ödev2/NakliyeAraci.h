#ifndef NAKLIYEARACI_H
#define NAKLIYEARACI_H
#include "mymethod.h"
#include "FileAction.h"
class NakliyeAraci
{
    public:
         NakliyeAraci();
        ~NakliyeAraci();
        void NakliyeAraciYukleme();
        void NakliyeAraciIndirme();

    private:
    myMethod m;
    FileAction f;
    typedef struct{
    int SubeId;
    int T1=0;
    int T2=0;
    int T3=0;
    int T4=0;
    int T5=0;
    int T6=0;
    int oncelikPuan;
    int desi;
    int toplamDesi;
    int yuklemeSuresi;
    int toplamYuklemeSuresi;
    string fileLine;
    }ToplamGonderi;
    ToplamGonderi *toplamGonderi;
    void GonderiTurTopla(int tur_Id,int index);
};

#endif // NAKLIYEARACI_H
