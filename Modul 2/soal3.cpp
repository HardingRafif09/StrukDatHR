#include <iostream>
#include <string>
using namespace std;

int hitungKarakter(string kata, char karakter) {
    int jumlah = 0;

    for (int i = 0; i < kata.length(); i++) {
        if (kata[i] == karakter) {
            jumlah++;
        }
    }

    return jumlah;
}

int main() {
    string kata;
    char karakter;

    cout << "Masukkan kata: ";
    cin >> kata;

    cout << "Masukkan karakter yang dicari: ";
    cin >> karakter;

    int hasil = hitungKarakter(kata, karakter);

    cout << "Jumlah kemunculan karakter: " << hasil << endl;

    return 0;
}