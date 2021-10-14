#ifndef GORUSME_H
#define GORUSME_H

class Gorusme
{
 public:
        Gorusme() {}

        int GetgorusmeID() { return gorusmeID; }
        void SetgorusmeID(int val) { gorusmeID = val; }
        int GetmusteriID() { return musteriID; }
        void SetmusteriID(int val) { musteriID = val; }
        int GettemsilciID() { return temsilciID; }
        void SettemsilciID(int val) { temsilciID = val; }
        int GetoncelikPuani() { return oncelikPuani; }
        void SetoncelikPuani(int val) { oncelikPuani = val; }
        string GetgorBaslama() { return gorBaslama; }
        void SetgorBaslama(string val) { gorBaslama = val; }
        string GetgorBitis() { return gorBitis; }
        void SetgorBitis(string val) { gorBitis = val; }

    private:
        int gorusmeID;
        int musteriID;
        int temsilciID;
        int oncelikPuani;
        string gorBaslama;
        string gorBitis;
};

#endif
