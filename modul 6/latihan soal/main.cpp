#include "Doublylist.h"

int main() {
    list L;
    CreateList(L);

    int jumlah;

    cout << "Masukkan jumlah data kendaraan: ";
    cin >> jumlah;
    cin.ignore();

    for (int i = 0; i < jumlah; i++) {
        infotype x;

        cout << "\nMasukkan nomor polisi: ";
        getline(cin, x.nopol);

        if (findElm(L, x) != Nil) {
            cout << "Nomor polisi sudah terdaftar!"
                 << endl;
            i--;
            continue;
        }

        cout << "Masukkan warna kendaraan: ";
        getline(cin, x.warna);

        cout << "Masukkan tahun kendaraan: ";
        cin >> x.thnBuat;
        cin.ignore();

        insertLast(L, alokasi(x));
    }

    cout << "\nDATA LIST 1" << endl;
    printInfo(L);

    infotype cari;

    cout << "\nMasukkan nomor polisi yang dicari: ";
    getline(cin, cari.nopol);

    address hasil = findElm(L, cari);

    if (hasil != Nil) {
        cout << "\nData kendaraan ditemukan:" << endl;
        cout << "Nomor Polisi : "
             << hasil->info.nopol << endl;
        cout << "Warna        : "
             << hasil->info.warna << endl;
        cout << "Tahun        : "
             << hasil->info.thnBuat << endl;
    } else {
        cout << "Data kendaraan tidak ditemukan."
             << endl;
    }

    string hapus;

    cout << "\nMasukkan nomor polisi yang akan dihapus: ";
    getline(cin, hapus);

    if (deleteByNopol(L, hapus)) {
        cout << "Data dengan nomor polisi "
             << hapus << " berhasil dihapus."
             << endl;
    } else {
        cout << "Data kendaraan tidak ditemukan."
             << endl;
    }

    cout << "\nDATA LIST SETELAH PENGHAPUSAN"
         << endl;
    printInfo(L);

    while (L.first != Nil) {
        address P = Nil;
        deleteFirst(L, P);
        dealokasi(P);
    }

    return 0;
}