#include <iostream>
using namespace std;

int main() {
    int N;

    cout << "Masukkan jumlah mahasiswa: ";
    cin >> N;

    int nilai[N];
    int total = 0;

    cout << "Masukkan nilai mahasiswa: " << endl;

    for (int i = 0; i < N; i++) {
        cin >> nilai[i];
        total = total + nilai[i];
    }

    int rataRata = total / N;
    int jumlahDiAtas = 0;

    for (int i = 0; i < N; i++) {
        if (nilai[i] > rataRata) {
            jumlahDiAtas++;
        }
    }

    cout << "Rata-rata: " << rataRata << endl;
    cout << "Di atas rata-rata: " << jumlahDiAtas << endl;

    return 0;
}