#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

struct Node{
    int data;
    struct Node *next;
}*front=NULL,*rear=NULL;

void enqueue(int x){
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    if(t==NULL)
        printf("Queue is full\n");
    else{
        t->data = x;
        t->next = NULL;
        if(front==NULL)
            front = rear = t;
        rear->next = t;
        rear = t;
    }
}

int Dequeue(){
    int x = -1;
    if(front==NULL)
        printf("Queue is Empty\n");
    struct Node *p = front;
    front = front->next;
    x = p->data;
    return x;     
}

void display(){
    struct Node *p = front;
    while(p){
        printf("%d ",p->data);
        p = p->next;
    }
}

int main()
{
    enqueue(5);
    enqueue(6);
    Dequeue();
    enqueue(7);
    enqueue(8);
    display();
}