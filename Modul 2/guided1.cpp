#include <iostream>
using namespace std;

int main() {
    // Array 1 Dimensi

    int nilai1D[3] = {80, 85, 90};
    cout << "=== ARRAY 1 DIMENSI ===" << endl;
    cout << "Nilai pertama: " << nilai1D[0] << endl;
    cout << "Nilai kedua: " << nilai1D[1] << endl;
    cout << "Nilai ketiga: " << nilai1D[2] << endl;
    
    // Array 2 Dimensi
    int nilai2D[2][3] = {
        {80, 85, 90},
        {75, 80, 95}
    };
    cout << endl;
    cout << "=== ARRAY 2 DIMENSI ===" << endl; 
    cout << "Nilai baris 0, kolom 0: " << nilai2D[0][0] << endl;
    cout << "Nilai baris 0, kolom 1: " << nilai2D[0][1] << endl;
    cout << "Nilai baris 1, kolom 2: " << nilai2D[1][2] << endl;
    
    // Array 3 Dimensi
    int nilai3D[2][2][2] = {
        {
            {80, 85},
            {75, 90}
        },
        {
            {88, 92},
            {78, 86}
        }
    };
    cout << endl;
    cout << "=== ARRAY 3 DIMENSI ===" << endl;
    cout << "Data [0][0][0]: " << nilai3D[0][0][0] << endl;
    cout << "Data [0][1][1]: " << nilai3D[0][1][1] << endl;
    cout << "Data [1][0][0]: " << nilai3D[1][0][0] << endl;
    cout << "Data [1][1][1]: " << nilai3D[1][1][1] << endl;

    return 0;
}

