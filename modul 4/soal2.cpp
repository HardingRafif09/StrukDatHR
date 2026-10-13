
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = nullptr;

void insertLast(int nilai) {
    Node* baru = new Node{nilai, nullptr};

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

void insertAfter(int cari, int nilaiBaru) {
    Node* bantu = head;

    while (bantu != nullptr && bantu->data != cari) {
        bantu = bantu->next;
    }

    if (bantu == nullptr) {
        cout << "Data tidak ditemukan\n";
        return;
    }

    Node* baru = new Node{nilaiBaru, bantu->next};
    bantu->next = baru;
}

void tampilkan() {
    Node* bantu = head;

    while (bantu != nullptr) {
        cout << bantu->data;
        if (bantu->next != nullptr) cout << " -> ";
        bantu = bantu->next;
    }
    cout << endl;
}

int main() {
    int N, nilai, cari, baru;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> nilai;
        insertLast(nilai);
    }

    cin >> cari >> baru;
    insertAfter(cari, baru);
    tampilkan();

    return 0;
}
