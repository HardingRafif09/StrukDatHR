#include <iostream>
#include "stack.h"

int isEmpty(Stack S) {
    if (S.Top == 0) {
        return 1;
    }
    return 0;
}

void createStack(Stack &S) {
    S.Top = 0;
}

void push(Stack &S, infotype X) {
    if (S.Top < 10) {
        S.Top = S.Top + 1;
        S.info[S.Top - 1] = X;
    }
}

void pop(Stack &S, infotype &X) {
    if (isEmpty(S) == 0) {
        X = S.info[S.Top - 1];
        S.Top = S.Top - 1;
    }
}

void viewStack(Stack S) {
    if (isEmpty(S) == 0) {
        int i = S.Top - 1;
        while (i >= 0) { 
            std::cout << S.info[i].nim << '\n';
            i--;
        }
    }
}


int main() {
    Stack S;
    createStack(S);

    // Membuat contoh data mahasiswa untuk dimasukkan ke stack
    infotype mhs1 = {"123456", "Budi"};
    infotype mhs2 = {"654321", "Andi"};

    // Uji coba fungsi push
    push(S, mhs1);
    push(S, mhs2);

    std::cout << "--- Isi Stack (NIM) ---" << std::endl;
    viewStack(S);

    // Uji coba fungsi pop
    infotype mhsKeluar;
    pop(S, mhsKeluar);
    std::cout << "\nMahasiswa yang di-pop: " << mhsKeluar.nama << " (" << mhsKeluar.nim << ")\n";

    std::cout << "\n--- Isi Stack Setelah Pop ---" << std::endl;
    viewStack(S);

    return 0;
}