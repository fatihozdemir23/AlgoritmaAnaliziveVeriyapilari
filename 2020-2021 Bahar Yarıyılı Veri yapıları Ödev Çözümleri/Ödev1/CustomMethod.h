#ifndef CUSTOMMETHOD_H
#define CUSTOMMETHOD_H
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

class CustomMethod
{
	public:
         CustomMethod();
        ~CustomMethod();
       string saatHesap(int dakika);
       int stoi(string);
       string itos(int);

    protected:

    private:
   int saat;
   int dakika;
};

#endif
