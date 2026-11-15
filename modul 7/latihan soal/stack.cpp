#include <iostream>
#include "stack.h"
using namespace std;

void createStack(Stack &S) {
    S.top = 0;                    
}

void push(Stack &S, infotype x) {
    if (S.top < 20) {
        S.info[S.top] = x;        
        S.top++;
    }
}

infotype pop(Stack &S) {
    if (S.top == 0) return -1;   
    S.top--;
    return S.info[S.top];         
}

void printInfo(Stack S) {
    cout << "[TOP] ";
    for (int i = S.top - 1; i >= 0; i--)   
        cout << S.info[i] << " ";
    cout << endl;
}

void balikStack(Stack &S) {
    int kiri = 0, kanan = S.top - 1;
    while (kiri < kanan) {        
        int temp = S.info[kiri];
        S.info[kiri] = S.info[kanan];
        S.info[kanan] = temp;
        kiri++;
        kanan--;
    }
}

void pushAscending(Stack &S, infotype x) {
    if (S.top < 20) {
        int i = S.top - 1;
        while (i >= 0 && S.info[i] > x) {   
            S.info[i + 1] = S.info[i];
            i--;
        }
        S.info[i + 1] = x;                 
        S.top++;
    }
}

void getInputStream(Stack &S) {
    char c = cin.get();              
    while (c != '\n') {             
        push(S, c - '0');            
        c = cin.get();
    }
}