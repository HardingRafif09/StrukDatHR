#ifndef QUEUE_H
#define QUEUE_H

typedef int infotype;
const int NMax = 5;

struct Queue {
    infotype info[NMax];
    int head;
    int tail;
    int count;
};

void createQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(Queue Q);

#endif