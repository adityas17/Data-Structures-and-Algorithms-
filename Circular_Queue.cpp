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

void enqueue(struct Queue *q,int x){
    if((q->rear+1)%q->size == q->front){
        printf("Queue is Full\n");
    }
    else{
        q->rear = (q->rear+1)%q->size;
        q->Q[q->rear] = x;
    }
}

int Dequeue(struct Queue *q){
    int x = -1;
    if(q->rear == q->front){
        printf("Queue is empty\n");
    }
    else{
        q->front = (q->front+1)%q->size;
        x = q->Q[q->front];
    }
    return x;
}

void display(struct Queue q){
    int i = q.front+1;
    do{
        printf("%d ",q.Q[i]);
        i = (i+1)%q.size;
    }while(i!=(q.rear+1)%q.size);
}

void create(struct Queue *q,int size){
    q->size = size;
    q->Q = new int[q->size];
    q->front = q->rear = 0;
}

int main(){
    struct Queue *q;
    create(q,7);
    enqueue(q,5);
    enqueue(q,3);
    enqueue(q,7);
    enqueue(q,9);
    Dequeue(q);
    Dequeue(q);
    display(*q);


}