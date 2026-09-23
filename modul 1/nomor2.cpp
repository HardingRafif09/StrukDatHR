#include <iostream>
#include <string>
using namespace std;

string satuan(int n) {
    string angka[] = {
        "nol", "satu", "dua", "tiga", "empat",
        "lima", "enam", "tujuh", "delapan", "sembilan"
    };

    return angka[n];
}

string terbilang(int n) {

    if (n < 10) {
        return satuan(n);
    }

    if (n == 10) {
        return "sepuluh";
    }

    if (n == 11) {
        return "sebelas";
    }

    if (n < 20) {
        return satuan(n - 10) + " belas";
    }

    if (n < 100) {
        int puluhan = n / 10;
        int sisa = n % 10;

        if (sisa == 0) {
            return satuan(puluhan) + " puluh";
        }

        return satuan(puluhan) + " puluh " + satuan(sisa);
    }

    if (n == 100) {
        return "seratus";
    }

    return "angka tidak valid";
}

int main() {
    int angka;

    cout << "Masukkan angka (0-100): ";
    cin >> angka;

    cout << angka << " : " << terbilang(angka) << endl;

    return 0;
}