#include <iostream>
using namespace std;

int main() {
    int matriks[3][3];
    int jumlahDiagonal = 0;

    cout << "Masukkan elemen matriks 3x3:" << endl;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> matriks[i][j];
        }
    }

    for (int i = 0; i < 3; i++) {
        jumlahDiagonal = jumlahDiagonal + matriks[i][i];
    }

    cout << "Jumlah diagonal utama: " << jumlahDiagonal << endl;

    return 0;
}