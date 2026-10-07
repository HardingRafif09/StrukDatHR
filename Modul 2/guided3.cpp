#include <iostream>
using namespace std;

// A. Pemanggilan dengan Nilai / Call by Value
// Cuma disalin, data asli aman
void tukarValue(int x, int y) {
    int temp = x;
    x = y;
    y = temp;
}

// B. Pemanggilan dengan Pointer
// Alamat dikirim pakai pointer, data asli berubah
void tukarPointer(int *px, int *py) {
    int temp = *px;
    *px = *py;
    *py = temp;
}

// C. Pemanggilan dengan Referensi
// Data asli ikut berubah
void tukarReference(int &px, int &py) {
    int temp = px;
    px = py;
    py = temp;
}

int main() {
    int a = 4, b = 6;

    cout << "Kondisi Awal -> a: " << a << " b: " << b << endl;

    // Test Call by Value
    tukarValue(a, b);
    cout << "Setelah tukarValue -> a: " << a << " b: " << b << endl;
    // Hasil: a dan b tetap 4 dan 6

    // Test Call by Pointer
    tukarPointer(&a, &b);
    cout << "Setelah tukarPointer -> a: " << a << " b: " << b << endl;
    // Hasil: a jadi 6, b jadi 4 (berhasil ditukar)

    // Test Call by Reference
    // Kita tukar balik kondisinya
    tukarReference(a, b);
    cout << "Setelah tukarReference -> a: " << a << " b: " << b << endl;
    // Hasil: a jadi 4, b jadi 6 (berhasil ditukar lagi)

    return 0;
}