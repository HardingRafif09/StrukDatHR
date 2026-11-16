#include "queue.h"
#include <iostream>
using namespace std;

// Membuat queue kosong
void createQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
    Q.count = 0;
}

// Mengecek apakah queue kosong
bool isEmptyQueue(Queue Q) {
    return Q.count == 0;
}

// Mengecek apakah queue penuh
bool isFullQueue(Queue Q) {
    return Q.count == NMax;
}

// Menambahkan data ke dalam queue
void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) {
        cout << "Antrean Penuh!" << endl;
        return;
    }

    if (isEmptyQueue(Q)) {
        Q.head = 0;
        Q.tail = 0;
    } else {
        if (Q.tail == NMax - 1) {
            int j = 0;

            for (int i = Q.head; i <= Q.tail; i++) {
                Q.info[j] = Q.info[i];
                j++;
            }

            Q.tail = Q.count - 1;
            Q.head = 0;
        }

        Q.tail++;
    }

    Q.info[Q.tail] = x;
    Q.count++;
}

// Menghapus data dari depan queue
infotype dequeue(Queue &Q) {
    if (isEmptyQueue(Q)) {
        cout << "Antrean Kosong!" << endl;
        return -1;
    }

    infotype x = Q.info[Q.head];
    Q.count--;

    if (isEmptyQueue(Q)) {
        Q.head = -1;
        Q.tail = -1;
    } else {
        Q.head++;
    }

    return x;
}

// Menampilkan isi queue
void printInfo(Queue Q) {
    cout << Q.head << " - " << Q.tail << " | ";

    if (isEmptyQueue(Q)) {
        cout << "empty queue";
    } else {
        for (int i = Q.head; i <= Q.tail; i++) {
            cout << Q.info[i] << " ";
        }
    }

    cout << endl;
}

// Program utama
int main() {
    Queue Q;

    createQueue(Q);

    cout << "----------------------" << endl;
    cout << "H - T | Queue Info" << endl;
    cout << "----------------------" << endl;

    printInfo(Q);

    enqueue(Q, 8);
    printInfo(Q);

    enqueue(Q, 3);
    printInfo(Q);

    enqueue(Q, 6);
    printInfo(Q);

    enqueue(Q, 9);
    printInfo(Q);

    enqueue(Q, 15);
    printInfo(Q);

    dequeue(Q);
    printInfo(Q);

    enqueue(Q, 1);
    printInfo(Q);

    return 0;
}