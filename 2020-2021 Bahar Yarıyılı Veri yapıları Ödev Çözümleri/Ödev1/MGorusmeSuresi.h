#ifndef MGORUSMESURESI_H
#define MGORUSMESURESI_H
#include <string>
#include <iostream>
using namespace std;
class MGorusmeSuresi
{
 public:
        MGorusmeSuresi() {}
        int GetgorusmeSuresi() { return gorusmeSuresi; }
        void SetgorusmeSuresi(int val) { gorusmeSuresi = val; }
        string GetmusteriAdi() { return musteriAdi; }
        void SetmusteriAdi(string val) { musteriAdi = val; }
    private:
        int gorusmeSuresi;
        string musteriAdi;
};

#endif
