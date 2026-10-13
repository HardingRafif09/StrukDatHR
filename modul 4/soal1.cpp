
#include <iostream>
#include <string>
using namespace std;

struct Node {
    string nama;
    Node* next;
};

Node* head = nullptr;

void insertLast(string nama) {
    Node* baru = new Node{nama, nullptr};

    if (head == nullptr) {
        head = baru;
    } else {
        Node* bantu = head;
        while (bantu->next != nullptr) {
            bantu = bantu->next;
        }
        bantu->next = baru;
    }
}

void deleteFirst() {
    if (head == nullptr) {
        cout << "Antrean kosong\n";
        return;
    }

    Node* hapus = head;
    cout << "Melayani: " << head->nama << endl;
    head = head->next;
    delete hapus;
}

void tampilkan() {
    cout << "Antrean: ";
    if (head == nullptr) {
        cout << "Kosong";
    }

    Node* bantu = head;
    while (bantu != nullptr) {
        cout << bantu->nama;
        if (bantu->next != nullptr) cout << " -> ";
        bantu = bantu->next;
    }
    cout << endl;
}

int main() {
    int pilihan;
    string nama;

    do {
        cout << "\n1. Tambah Nasabah\n";
        cout << "2. Layani Nasabah\n";
        cout << "3. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihan;
        cin.ignore();

        if (pilihan == 1) {
            cout << "Nama nasabah: ";
            getline(cin, nama);
            insertLast(nama);
            tampilkan();
        } else if (pilihan == 2) {
            deleteFirst();
            tampilkan();
        } else if (pilihan != 3) {
            cout << "Pilihan tidak valid\n";
        }
    } while (pilihan != 3);

    return 0;
}
