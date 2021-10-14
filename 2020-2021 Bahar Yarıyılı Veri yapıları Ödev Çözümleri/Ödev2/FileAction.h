#ifndef FILEACTION_H
#define FILEACTION_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Subeler.h"
#include "NakliyeStack.h"
using namespace std;
class FileAction
{
public:
        int rows;
        int cols;
	    Subeler *sube;
        string gonderiler[500][3];
        FileAction();
        NakliyeStack GonderiYukle(string filename);
        void ReadSubeTxt(string filename);
        void GonderiList(string filename);
        void FileWrite(string filename,string line);
        void DosyaSatirStunHesap(string fileName);
		~FileAction();
};

#endif
