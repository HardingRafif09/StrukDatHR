#include <iostream>
using namespace std;

void tampilArray(int arr[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void tukarArray(int arr1[3][3], int arr2[3][3], int baris, int kolom) {
    int temp = arr1[baris][kolom];
    arr1[baris][kolom] = arr2[baris][kolom];
    arr2[baris][kolom] = temp;
}

void tukarPointer(int *p1, int *p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int main() {
    int arr1[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int arr2[3][3] = {
        {10, 11, 12},
        {13, 14, 15},
        {16, 17, 18}
    };

    int *p1 = &arr1[0][0];
    int *p2 = &arr2[0][0];

    cout << "Array 1 sebelum ditukar:" << endl;
    tampilArray(arr1);

    cout << "\nArray 2 sebelum ditukar:" << endl;
    tampilArray(arr2);

    tukarArray(arr1, arr2, 1, 1);

    cout << "\nSetelah menukar posisi [1][1]:" << endl;

    cout << "\nArray 1:" << endl;
    tampilArray(arr1);

    cout << "\nArray 2:" << endl;
    tampilArray(arr2);

    tukarPointer(p1, p2);

    cout << "\nSetelah menukar nilai melalui pointer:" << endl;
    cout << "arr1[0][0] = " << arr1[0][0] << endl;
    cout << "arr2[0][0] = " << arr2[0][0] << endl;

    return 0;
}