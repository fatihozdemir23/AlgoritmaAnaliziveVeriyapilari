#include <string>
#include <iostream>
#include <sstream>
#include "HepsiHarranda.h"

using namespace std;


int main(int argc, char** argv) {
HepsiHarranda h;
//oncelik puan hesaplama ile gorusme suresi hesaplamayý tek bir fonksiyonda birlestirdim
h.oncelikPuaniveGorusmeSuresiHesapla();
h.musteriKayitEkle();
h.gorusmeYap();
h.gorusmeListele();
h.gorusmeDetay();

getchar();

	return 0;
}
