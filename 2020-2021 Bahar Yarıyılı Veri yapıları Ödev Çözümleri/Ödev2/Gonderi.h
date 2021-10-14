#ifndef GONDERI_H
#define GONDERI_H
#include <iostream>
#include <string>
using namespace std;

class Gonderi
{
    public:
         Gonderi();
        ~Gonderi();
        string getGonderiId()const{return GonderiId;};
        string getGonderiTurId()const{return GonderiTurId;};
        string getGonderiOncelik()const{return GonderiOncelik;};
        string getGonderiHacim()const{return GonderiHacim;};
        string getSubeId()const{return SubeId;};
        void setGonderiId(string);
        void setGonderiTurId(string);
        void setGonderiOncelik(string);
        void setGonderiHacim(string);
        void setSubeId(string);
        void HacimBul(string);

    private:
         string GonderiId;
         string GonderiTurId;
         string GonderiOncelik;
         string GonderiHacim;
         string SubeId;
};

#endif // GONDERI_H
