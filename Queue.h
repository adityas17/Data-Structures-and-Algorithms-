#ifndef Queue_h
#define Queue_h
#include <stddef.h>

struct Node{
    struct Node *LeftChild;
    int data;
    struct Node *RightChild;
};

struct Queue{
    int size;
    int front;
    int rear;
    Node **Q;
};

void enqueue(struct Queue *q,Node* x){
        q->rear++;
        q->Q[q->rear] = x;
}

Node* Dequeue(struct Queue *q){
    Node * x = NULL;
    q->front++;
    x = q->Q[q->front];
    return x;
}

void create(struct Queue *q,int size){
    q->size = size;
    q->Q = new Node*[q->size];
    q->front = q->rear = -1;
}

int isEmpty(struct Queue q){
    return q.front == q.rear;
}


#endif