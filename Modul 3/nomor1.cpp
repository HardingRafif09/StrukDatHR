#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    float uts;
    float uas;
    float tugas;
    float nilaiAkhir;
};

int main() {
    Mahasiswa mhs[10];
    int n;

    cout << "Jumlah mahasiswa: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "\nMahasiswa ke-" << i + 1 << endl;

        cout << "Nama  : ";
        cin >> mhs[i].nama;

        cout << "NIM   : ";
        cin >> mhs[i].nim;

        cout << "UTS   : ";
        cin >> mhs[i].uts;

        cout << "UAS   : ";
        cin >> mhs[i].uas;

        cout << "Tugas : ";
        cin >> mhs[i].tugas;

        mhs[i].nilaiAkhir =
            0.3 * mhs[i].uts +
            0.4 * mhs[i].uas +
            0.3 * mhs[i].tugas;
    }

    cout << "\n=== Data Mahasiswa ===" << endl;

    for (int i = 0; i < n; i++) {
        cout << "\nNama       : " << mhs[i].nama << endl;
        cout << "NIM        : " << mhs[i].nim << endl;
        cout << "Nilai Akhir: " << mhs[i].nilaiAkhir << endl;
    }

    return 0;
}