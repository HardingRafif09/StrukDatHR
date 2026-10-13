#include <iostream>
#include <string>
using namespace std;

struct Node {
    string judul;
    int tahun;
    Node* next;
};

Node* head = nullptr;

void insertLast(string judul, int tahun) {
    Node* baru = new Node{judul, tahun, nullptr};

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

void deleteLast() {
    if (head == nullptr) return;

    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }

    Node* bantu = head;
    while (bantu->next->next != nullptr) {
        bantu = bantu->next;
    }

    Node* hapus = bantu->next;
    bantu->next = nullptr;
    delete hapus;
}

void tampilkan() {
    cout << "Daftar Buku:\n";
    Node* bantu = head;
    while (bantu != nullptr) {
        cout << bantu->judul << " (" << bantu->tahun << ")\n";
        bantu = bantu->next;
    }
}

int main() {
    int N;
    string baris;

    cin >> N;
    cin.ignore();

    for (int i = 0; i < N; i++) {
        getline(cin, baris);
        size_t pos = baris.find_last_of(' ');
        string judul = baris.substr(0, pos);
        int tahun = stoi(baris.substr(pos + 1));
        insertLast(judul, tahun);
    }

    deleteLast();
    tampilkan();

    return 0;
}