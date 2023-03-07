#ifndef Queue1_h
#define Queue1_h
#include<stdio.h>
#include<stdlib.h>
#include "Queue1.h"

struct Node{
    struct Node *lchild;
    int data;
    struct Node *rchild;
};

struct Queue{
    int size;
    int front;
    int rear;
    struct Node **Q;
};

void Qcreate(struct Queue *q,int size){
    q->size = size;
    q->Q = (struct Node **)malloc(q->size*sizeof(struct Node**));
    q->front = q->rear = 0;
}

void enqueue(struct Queue *q,struct Node *x){
    if((q->rear+1)%q->size == q->front){
        printf("Queue is Full\n");
    }
    else{
        q->rear = (q->rear+1)%q->size;
        q->Q[q->rear] = x;
    }
}

struct Node * Dequeue(struct Queue *q){
     struct Node * x = NULL;
    if(q->rear == q->front){
        printf("Queue is empty\n");
    }
    else{
        q->front = (q->front+1)%q->size;
        x = q->Q[q->front];
    }
    return x;
}

int isEmpty(struct Queue q){
    return q.front == q.rear;
}

#endif /*Queue1_h*/