#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

struct Queue{
    int size;
    int front;
    int rear;
    int *Q;
};

void create(struct Queue *q,int size){
    q->size = size;
    q->Q = new int[q->size];
    q->front = q->rear = 0;
}

void enqueue(struct Queue *q, int x){
    if((q->rear+1)%q->size == q->size-1)
        printf("Queue is full\n");
    else{
        q->rear = (q->rear+1)%q->size;
        q->Q[q->rear] = x;
    }
}

int Dequeue(struct Queue *q){
    int x = -1;
    if(q->front == q->rear)
        printf("Queue is Empty\n");
    else{
        q->front = (q->front+1)%q->size;
        x=q->Q[q->front];
    }
    return x;
}

void display(struct Queue q){
    int i=q.front+1;
    do{
        printf("%d ",q.Q[i]);
        i = (i+1)% q.size;
        // i++;
    }while(i!=(q.rear+1)%q.size);
}

int main()
{
    struct Queue *q;
    create(q,5);
    enqueue(q,9);
    enqueue(q,10);
    enqueue(q,23);
    display(*q);
}