#ifndef GONDERILER_H
#define GONDERILER_H
#include <iostream>
#include <string>
using namespace std;

class Gonderiler
{
    public:
         Gonderiler();
        ~Gonderiler();

        string GetGonderiId() { return GonderiId; }
        void SetGonderiId(string val) { GonderiId = val; }
        int GetTurId() { return TurId; }
        void SetTurId(int val) { TurId = val; }
        int GetSubeId() { return SubeId; }
        void SetSubeId(int val) { SubeId = val; }
    private:
        string GonderiId;
        int TurId;
        int SubeId;
};

#endif // GONDERILER_H
