#include <iostream>
#include <iomanip>
using namespace std;

#define Nil NULL
typedef int infotype;

// =====================================================================
// BAGIAN 1: QUEUE DENGAN LINKED LIST
// =====================================================================

typedef struct elmQueue *address;

// Satu elemen menyimpan info dan alamat elemen berikutnya.
struct elmQueue {
    infotype info;
    address next;
};

// Queue cukup mengingat dua ujung: head (depan) dan tail (belakang).
struct Queue {
    address head, tail;
};

// Queue dikatakan kosong jika head = Nil.
void createQueue(Queue &Q) {
    Q.head = Nil;
    Q.tail = Nil;
}

bool isEmpty(Queue Q) {
    return Q.head == Nil;
}

// Membuat elemen baru dengan next = Nil (Gambar 8-2).
address alokasi(infotype X) {
    address P = new elmQueue;
    P->info = X;
    P->next = Nil;
    return P;
}

// Mengembalikan memori elemen ke sistem.
void dealokasi(address &P) {
    delete P;
    P = Nil;
}

// enqueue (di 8.3 bernama insert): selalu menyisipkan di belakang (tail).
void enqueue(Queue &Q, address P) {
    if (isEmpty(Q)) {
        // Kasus khusus yang tidak ada di kode modul: queue masih kosong,
        // jadi elemen pertama menjadi head sekaligus tail.
        Q.head = P;
        Q.tail = P;
    } else {
        (Q.tail)->next = P;   // Gambar 8-3: tail lama menunjuk elemen baru
        Q.tail = P;           // Gambar 8-4: tail pindah ke elemen baru
    }
}

// dequeue (di 8.3 bernama delete): selalu mengambil elemen di depan (head).
address dequeue(Queue &Q) {
    if (isEmpty(Q)) {
        return Nil;
    }
    address P = Q.head;       // Gambar 8-5: P menunjuk head
    Q.head = P->next;         // Gambar 8-6: head maju ke elemen berikutnya
    P->next = Nil;            // Gambar 8-7: elemen yang diambil dilepas
    if (Q.head == Nil) {
        Q.tail = Nil;         // queue menjadi kosong, tail ikut dikosongkan
    }
    return P;
}

// Mencari elemen dengan info = X. Mengembalikan alamatnya, atau Nil.
address findElm(Queue Q, infotype X) {
    address P = Q.head;
    while (P != Nil) {
        if (P->info == X) {
            return P;
        }
        P = P->next;
    }
    return Nil;
}

// Menampilkan semua info dari head sampai tail.
void printInfo(Queue Q) {
    if (isEmpty(Q)) {
        cout << "(kosong)" << endl;
        return;
    }
    address P = Q.head;
    while (P != Nil) {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}

// Mengembalikan jumlah elemen pada queue.
int nbList(Queue Q) {
    int n = 0;
    address P = Q.head;
    while (P != Nil) {
        n++;
        P = P->next;
    }
    return n;
}

// Menghapus semua elemen: dequeue berulang, lalu dealokasi.
void delAll(Queue &Q) {
    while (!isEmpty(Q)) {
        address P = dequeue(Q);
        dealokasi(P);
    }
}

void demoLinkedList() {
    cout << "=== BAGIAN 1: QUEUE DENGAN LINKED LIST ===" << endl;

    Queue Q;
    createQueue(Q);
    cout << "Queue kosong? " << (isEmpty(Q) ? "ya" : "tidak") << endl;

    // Tiga orang masuk antrean berurutan.
    int data[3] = {10, 20, 30};
    for (int i = 0; i < 3; i++) {
        enqueue(Q, alokasi(data[i]));
        cout << "enqueue " << data[i] << " -> ";
        printInfo(Q);
    }
    cout << "Jumlah elemen: " << nbList(Q) << endl;

    if (findElm(Q, 20) != Nil) {
        cout << "Elemen 20 ditemukan" << endl;
    }
    if (findElm(Q, 99) == Nil) {
        cout << "Elemen 99 tidak ada" << endl;
    }

    // FIFO: yang keluar pertama adalah yang masuk pertama, yaitu 10.
    address P = dequeue(Q);
    cout << "dequeue " << P->info << " -> ";
    dealokasi(P);
    printInfo(Q);

    enqueue(Q, alokasi(40));
    cout << "enqueue 40 -> ";
    printInfo(Q);

    delAll(Q);
    cout << "delAll -> ";
    printInfo(Q);
}

// =====================================================================
// BAGIAN 2: QUEUE DENGAN TABEL (ARRAY)
//
// Beda dengan pointer (Tabel 8-1): jumlah elemen terbatas sebesar NMax
// dan tidak ada manajemen memori. Antrean kosong ditandai head = -1 dan
// tail = -1 (seperti CreateQueue di modul 8.4.2). Indeks array dimulai
// dari 0.
// =====================================================================

const int NMax = 5;   // modul memakai 10, kita pakai 5 supaya cepat penuh

struct QueueTabel {
    infotype info[NMax];
    int head, tail;
};

void createQueueTabel(QueueTabel &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyTabel(QueueTabel Q) {
    return Q.head == -1;
}

// Menampilkan posisi head, tail, dan isi antrean.
// Penelusuran memakai % NMax supaya juga benar untuk Alternatif 3,
// ketika tail sudah berputar ke depan dan lebih kecil dari head.
void printInfoTabel(QueueTabel Q) {
    cout << "[H=" << Q.head << " T=" << Q.tail << "] ";
    if (isEmptyTabel(Q)) {
        cout << "kosong" << endl;
        return;
    }
    int i = Q.head;
    while (true) {
        cout << Q.info[i] << " ";
        if (i == Q.tail) {
            break;
        }
        i = (i + 1) % NMax;
    }
    cout << endl;
}

// ---------------------------------------------------------------------
// ALTERNATIF 1: head diam di indeks 0, tail bergerak
// ---------------------------------------------------------------------

bool isFullAlt1(QueueTabel Q) {
    return Q.tail == NMax - 1;
}

// Tambah elemen: cukup "memajukan" tail.
void enqueueAlt1(QueueTabel &Q, infotype X) {
    if (isFullAlt1(Q)) {
        cout << "(penuh) ";
        return;
    }
    if (isEmptyTabel(Q)) {
        Q.head = 0;       // kasus khusus: antrean kosong
        Q.tail = 0;
    } else {
        Q.tail++;
    }
    Q.info[Q.tail] = X;
}

// Hapus elemen (I.S. antrean tidak kosong): ambil head, lalu geser semua
// elemen satu langkah ke kiri. Mirip orang yang maju di antrean sungguhan,
// tapi tidak efisien.
infotype dequeueAlt1(QueueTabel &Q) {
    infotype X = Q.info[Q.head];
    for (int i = Q.head; i < Q.tail; i++) {
        Q.info[i] = Q.info[i + 1];
    }
    Q.tail--;
    if (Q.tail < 0) {     // tadi hanya ada satu elemen
        Q.head = -1;
    }
    return X;
}

// ---------------------------------------------------------------------
// ALTERNATIF 2: head bergerak, tail bergerak
// ---------------------------------------------------------------------

// Penuh hanya jika head di awal dan tail di ujung. Kalau head sudah maju,
// di sebelah kiri masih ada ruang kosong.
bool isFullAlt2(QueueTabel Q) {
    return Q.head == 0 && Q.tail == NMax - 1;
}

void enqueueAlt2(QueueTabel &Q, infotype X) {
    if (isFullAlt2(Q)) {
        cout << "(penuh) ";
        return;
    }
    if (isEmptyTabel(Q)) {
        Q.head = 0;
        Q.tail = 0;
    } else {
        if (Q.tail == NMax - 1) {
            // Penuh "semu" (Gambar 8-13): tail sudah di ujung, padahal
            // bagian kiri kosong. Geser dulu elemen ke indeks 0.
            cout << "(geser) ";
            int jumlah = Q.tail - Q.head + 1;
            for (int i = 0; i < jumlah; i++) {
                Q.info[i] = Q.info[Q.head + i];
            }
            Q.head = 0;
            Q.tail = jumlah - 1;
        }
        Q.tail++;
    }
    Q.info[Q.tail] = X;
}

// Hapus elemen (I.S. antrean tidak kosong): ambil head, lalu head tinggal
// "maju". Tanpa pergeseran.
infotype dequeueAlt2(QueueTabel &Q) {
    infotype X = Q.info[Q.head];
    if (Q.head == Q.tail) {
        Q.head = -1;      // elemen terakhir diambil, antrean jadi kosong
        Q.tail = -1;
    } else {
        Q.head++;
    }
    return X;
}

// ---------------------------------------------------------------------
// ALTERNATIF 3: head dan tail berputar (circular buffer)
// ---------------------------------------------------------------------

// Penuh jika successor dari tail adalah head. Saat kosong head = -1,
// jadi kondisi ini tidak pernah terpenuhi.
bool isFullAlt3(QueueTabel Q) {
    return (Q.tail + 1) % NMax == Q.head;
}

// Successor dari indeks terakhir (NMax-1) adalah 0, sehingga tail berputar
// kembali ke awal dan ruang kosong di kiri langsung terpakai.
void enqueueAlt3(QueueTabel &Q, infotype X) {
    if (isFullAlt3(Q)) {
        cout << "(penuh) ";
        return;
    }
    if (isEmptyTabel(Q)) {
        Q.head = 0;
        Q.tail = 0;
    } else {
        Q.tail = (Q.tail + 1) % NMax;
    }
    Q.info[Q.tail] = X;
}

// head juga berputar dengan cara yang sama, jadi tidak perlu pergeseran.
infotype dequeueAlt3(QueueTabel &Q) {
    infotype X = Q.info[Q.head];
    if (Q.head == Q.tail) {
        Q.head = -1;
        Q.tail = -1;
    } else {
        Q.head = (Q.head + 1) % NMax;
    }
    return X;
}

// ---------------------------------------------------------------------
// Menjalankan skenario yang sama untuk ketiga alternatif
// ---------------------------------------------------------------------

// Pointer ke fungsi enqueue dan dequeue. Dengan ini skenario yang sama bisa
// dijalankan ke tiap alternatif, kita tinggal mengganti mekanismenya.
typedef void (*FungsiEnqueue)(QueueTabel &, infotype);
typedef infotype (*FungsiDequeue)(QueueTabel &);

void skenario(FungsiEnqueue enq, FungsiDequeue deq) {
    QueueTabel Q;
    createQueueTabel(Q);
    cout << "awal        ";
    printInfoTabel(Q);

    // Langkah 1: isi sampai penuh, lalu coba tambah satu lagi (99).
    int isi[6] = {8, 3, 6, 9, 15, 99};
    for (int i = 0; i < 6; i++) {
        cout << "enqueue " << left << setw(3) << isi[i] << " ";
        enq(Q, isi[i]);
        printInfoTabel(Q);
    }

    // Langkah 2: keluarkan dua elemen paling depan.
    for (int i = 0; i < 2; i++) {
        infotype X = deq(Q);
        cout << "dequeue " << left << setw(3) << X << " ";
        printInfoTabel(Q);
    }

    // Langkah 3: tambah dua elemen. Di sini perbedaan ketiga alternatif
    // terlihat. Alt 2 harus menggeser (penuh semu), Alt 3 berputar ke 0.
    int tambah[2] = {1, 7};
    for (int i = 0; i < 2; i++) {
        cout << "enqueue " << left << setw(3) << tambah[i] << " ";
        enq(Q, tambah[i]);
        printInfoTabel(Q);
    }

    // Langkah 4: keluarkan semuanya sampai antrean kosong lagi.
    while (!isEmptyTabel(Q)) {
        infotype X = deq(Q);
        cout << "dequeue " << left << setw(3) << X << " ";
        printInfoTabel(Q);
    }
}

int main() {
    demoLinkedList();

    cout << endl << "=== BAGIAN 2: QUEUE DENGAN TABEL, NMax = " << NMax << " ===" << endl;

    cout << endl << "--- Alternatif 1: head diam, tail bergerak ---" << endl;
    skenario(enqueueAlt1, dequeueAlt1);

    cout << endl << "--- Alternatif 2: head bergerak, tail bergerak ---" << endl;
    skenario(enqueueAlt2, dequeueAlt2);

    cout << endl << "--- Alternatif 3: head dan tail berputar ---" << endl;
    skenario(enqueueAlt3, dequeueAlt3);

    return 0;
}