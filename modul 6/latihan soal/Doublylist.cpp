#include "Doublylist.h"

void CreateList(list &L) {
    L.first = Nil;
    L.last = Nil;
}

address alokasi(infotype x) {
    address P = new elmlist;

    if (P != Nil) {
        P->info = x;
        P->next = Nil;
        P->prev = Nil;
    }

    return P;
}

void dealokasi(address &P) {
    if (P != Nil) {
        delete P;
        P = Nil;
    }
}

void insertLast(list &L, address P) {
    if (P == Nil) return;

    P->next = Nil;
    P->prev = L.last;

    if (L.first == Nil) {
        L.first = P;
        L.last = P;
    } else {
        L.last->next = P;
        L.last = P;
    }
}

void printInfo(const list &L) {
    address P = L.first;

    if (P == Nil) {
        cout << "List kosong." << endl;
        return;
    }

    while (P != Nil) {
        cout << "Nomor Polisi : "
             << P->info.nopol << endl;
        cout << "Warna        : "
             << P->info.warna << endl;
        cout << "Tahun        : "
             << P->info.thnBuat << endl;

        P = P->next;
    }
}

address findElm(const list &L, infotype x) {
    address P = L.first;

    while (P != Nil) {
        if (P->info.nopol == x.nopol) {
            return P;
        }

        P = P->next;
    }

    return Nil;
}

void deleteFirst(list &L, address &P) {
    if (L.first == Nil) {
        P = Nil;
        return;
    }

    P = L.first;
    L.first = P->next;

    if (L.first != Nil) {
        L.first->prev = Nil;
    } else {
        L.last = Nil;
    }

    P->next = Nil;
    P->prev = Nil;
}

void deleteLast(list &L, address &P) {
    if (L.last == Nil) {
        P = Nil;
        return;
    }

    P = L.last;
    L.last = P->prev;

    if (L.last != Nil) {
        L.last->next = Nil;
    } else {
        L.first = Nil;
    }

    P->next = Nil;
    P->prev = Nil;
}

void deleteAfter(address Prec, address &P) {
    if (Prec == Nil || Prec->next == Nil) {
        P = Nil;
        return;
    }

    P = Prec->next;
    Prec->next = P->next;

    if (P->next != Nil) {
        P->next->prev = Prec;
    }

    P->next = Nil;
    P->prev = Nil;
}

bool deleteByNopol(list &L, const string &nopol) {
    address P = L.first;

    while (P != Nil && P->info.nopol != nopol) {
        P = P->next;
    }

    if (P == Nil) {
        return false;
    }

    if (P == L.first) {
        address Hapus = Nil;
        deleteFirst(L, Hapus);
        dealokasi(Hapus);
    } else if (P == L.last) {
        address Hapus = Nil;
        deleteLast(L, Hapus);
        dealokasi(Hapus);
    } else {
        address Prec = P->prev;
        address Hapus = Nil;

        deleteAfter(Prec, Hapus);
        dealokasi(Hapus);
    }

    return true;
}