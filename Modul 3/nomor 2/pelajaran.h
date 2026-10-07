#ifndef PELAJARAN_H
#define PELAJARAN_H

#include <string>
using namespace std;

struct Pelajaran {
    string namapel;
    string kodepel;
};

Pelajaran create_pelajaran(string namapel, string kodepel);
void tampil_pelajaran(Pelajaran pel);

#endif