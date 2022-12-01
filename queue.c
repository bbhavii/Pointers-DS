#include <stdio.h>
#include <stdlib.h>


/*
You can have 2 ways to access a list:
FIFO - First In First Out - Queue
LIFO - Last In First Out - Stack

Insertion is the same, only extraction is different.

Queue of positive numbers only.

*/

struct queueType{
    int * data;
    int size;
    int start;
    int n; //no. of elements in the queue
};

typedef struct queueType * QueueAddress;

QueueAddress initQueue(){
    QueueAddress q = malloc(sizeof(struct queueType));
    q->n = 0;
    q->start = -1;
    q->size = 100;
    q->data = malloc(q->size*sizeof(int));
    return q;
}

void freeQueue(QueueAddress q){
    free(q);
}

int insertQueue(QueueAddress q, int val){
    if(q->n==(q->size)) return -1; //says queue is full

    q->data[q->start + q->n++] = val;
    return val;
}

int extractQueue(QueueAddress q){
    if(q->n<1) return -1;
    q->n--;
    return q->data[q->start++];
}

int main(){

    QueueAddress q = initQueue();

    insertQueue(q,10);
    insertQueue(q,20);
    insertQueue(q,30);
    insertQueue(q,555);

    printf("%d\n",extractQueue(q));
    printf("%d\n",extractQueue(q));
    printf("%d\n",extractQueue(q));
    printf("%d\n",extractQueue(q));

    freeQueue(q);
    return 0;
}