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

void insertRear(struct Queue *q,int x){
    if(q->rear == q->size-1){
        printf("Queue is Full\n");
    }
    else{
        q->rear++;
        q->Q[q->rear] = x;
    }
}

void insertFront(struct Queue *q,int x){
    if(q->front == 0)
        printf("No place to insert\n");
    else{
        q->front--;
        q->Q[q->front] =  x;
    }
}

int DeleteFront(struct Queue *q){
    int x = -1;
    if(q->rear == q->front){
        printf("Queue is empty\n");
    }
    else{
        q->front++;
        x = q->Q[q->front];
    }
    return x;
}

int DeleteRear(struct Queue *q){
    int x = -1;
    if(q->rear == q->front){
        printf("Queue is empty\n");
    }
    else{
        q->rear--;
        x = q->Q[q->rear];
    }
    return x;
}

void display(struct Queue q){
    for(int i=q.front+1;i<=q.rear;i++){
        printf("%d ",q.Q[i]);
    }
}

void create(struct Queue *q,int size){
    q->size = size;
    q->Q = new int[q->size];
    q->front = q->rear = -1;
}

int main()
{
    struct Queue *q;
    create(q,5);
    insertRear(q,2);
    insertRear(q,3);
    insertRear(q,4);
    insertRear(q,5);
    display(*q);
}