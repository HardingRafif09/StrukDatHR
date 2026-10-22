#include "SingleLinkedList.h"
#include <iostream>
using namespace std;

int main() {
    List L;
    ElmList* hasil;
    ElmList* P;
    int total = 0;

    CreateList(L);

    // 1. Insert First
    insertFirst(L, 2);
    insertFirst(L, 0);
    insertFirst(L, 8);
    insertFirst(L, 12);
    insertFirst(L, 9);

    cout << "List awal: ";
    printInfo(L);

    // 2. Searching
    hasil = findElm(L, 8);

    if (hasil != nullptr) {
        cout << "Angka 8 ditemukan." << endl;
    } else {
        cout << "Angka 8 tidak ditemukan." << endl;
    }

    // 3. Menghitung total nilai
    P = L.First;

    while (P != nullptr) {
        total = total + P->info;
        P = P->next;
    }

    cout << "Total nilai: " << total << endl;

    // 4. Insert Last
    insertLast(L, 20);
    cout << "Setelah insertLast(20): ";
    printInfo(L);

    // 5. Insert After
    insertAfter(L, 12, 99);
    cout << "Setelah insertAfter(12, 99): ";
    printInfo(L);

    // 6. Update
    update(L, 99, 100);
    cout << "Setelah update(99, 100): ";
    printInfo(L);

    // 7. Delete After
    delAfter(L, 12);
    cout << "Setelah delAfter(12): ";
    printInfo(L);

    // 8. Delete berdasarkan nilai
    delP(L, 8);
    cout << "Setelah delP(8): ";
    printInfo(L);

    // 9. Delete First
    delFirst(L);
    cout << "Setelah delFirst: ";
    printInfo(L);

    // 10. Delete Last
    delLast(L);
    cout << "Setelah delLast: ";
    printInfo(L);

    // 11. Menghitung jumlah node
    cout << "Jumlah node: " << nbList(L) << endl;

    // 12. Menghapus semua node
    delAll(L);
    cout << "Setelah delAll: ";
    printInfo(L);

    return 0;
}
