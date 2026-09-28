#include <iostream>
using namespace std;

void tukarDanKali(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;

    x = x * 10;
    y = y * 10;
}

int main() {
    int x, y;

    cout << "Masukkan nilai x dan y: ";
    cin >> x >> y;

    tukarDanKali(x, y);

    cout << "x = " << x << ", y = " << y << endl;

    return 0;
}