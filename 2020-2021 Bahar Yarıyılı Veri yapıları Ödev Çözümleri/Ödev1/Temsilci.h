#ifndef TEMSILCI_H
#define TEMSILCI_H
#include <string>
using namespace std;
class Temsilci
{
 public:
       

        int GettemsilciID() { return temsilciID; }
        void SettemsilciID(int val) { temsilciID = val; }
        string GettemsilciAdi() { return temsilciAdi; }
        void SettemsilciAdi(string val) { temsilciAdi = val; }



    private:
         int temsilciID;
         string temsilciAdi;
};

#endif
