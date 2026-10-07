#include <iostream>
#include "pelajaran.h"

using namespace std;

Pelajaran create_pelajaran(string namapel, string kodepel) {
    Pelajaran pel;

    pel.namapel = namapel;
    pel.kodepel = kodepel;

    return pel;
}

void tampil_pelajaran(Pelajaran pel) {
    cout << "nama pelajaran : " << pel.namapel << endl;
    cout << "nilai : " << pel.kodepel << endl;
}