#ifndef FILEACTION_H
#define FILEACTION_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

class FileAction
{
 public:
 int  rows;
 int cols;

        string** MatrisOlustur();
        string **Matris;
		FileAction();
		FileAction(string filename);
         void FileInit(string filename);
         void DosyaOku(string filename);
         void ReadSubeTxt(string filename);
		 void FileWrite(string filename,string line);
		 void DosyaSatirStunHesap(string fileName);
		~FileAction();
};

#endif
