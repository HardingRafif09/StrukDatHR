#include <iostream>
#include "titik.h"

using namespace std;

int main() {
    Titik tA, tB;

    cout << "--- Input Titik Pertama ---" << endl;
    inputTitik(tA);

    cout << "--- Input Titik Kedua ---" << endl;
    inputTitik(tB);

    cout << "\nHasil Rekap Koordinat:" << endl;
    tampilTitik(tA);
    tampilTitik(tB);

    float jarak = hitungJarak(tA, tB);

    cout << "Jarak antara kedua titik: " << jarak << endl;

    return 0;
}