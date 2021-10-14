#ifndef MUSTERI_H
#define MUSTERI_H
#include <string>
#include <iostream>
using namespace std;
class Musteri
{
	 public:
        Musteri() {}

        int GetmusteriID() { return musteriID; }
        void SetmusteriID(int val) { musteriID = val; }
        string GetmusteriAdi() { return musteriAdi; }
        void SetmusteriAdi(string val) { musteriAdi = val; }
        int GetuyelikDurumu() { return uyelikDurumu; }
        void SetuyelikDurumu(int val) { uyelikDurumu = val; }
        int GetcuzdanDurumu() { return cuzdanDurumu; }
        void SetcuzdanDurumu(int val) { cuzdanDurumu = val; }
        int GetaylikHarcama() { return aylikHarcama; }
        void SetaylikHarcama(int val) { aylikHarcama = val; }
        int GetyorumSayisi() { return yorumSayisi; }
        void SetyorumSayisi(int val) { yorumSayisi = val; }
        int GeturunCesidi() { return urunCesidi; }
        void SeturunCesidi(int val) { urunCesidi = val; }
        int GetislemTuru() { return islemTuru; }
        void SetislemTuru(int val) { islemTuru = val; }
        int GetoncelikPuani() { return oncelikPuani; }
        void SetoncelikPuani(int val) { oncelikPuani = val; }
        int GetgorusmeSuresi() { return gorusmeSuresi; }
        void SetgorusmeSuresi(int val) { gorusmeSuresi = val; }

    private:
        int musteriID;
        string musteriAdi;
        int uyelikDurumu;
        int cuzdanDurumu;
        int aylikHarcama;
        int yorumSayisi;
        int urunCesidi;
        int islemTuru;
        int oncelikPuani;
        int gorusmeSuresi;
};

#endif
#ifndef MUSTERI_H
#define MUSTERI_H

class Musteri
{
	public:
	protected:
};

#endif
