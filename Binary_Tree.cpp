#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

struct Node{
    struct Node *LeftChild;
    int data;
    struct Node *RightChild;
}*Root = NULL;

struct Queue{
    int size;
    int front;
    int rear;
    Node **Q;
};

void enqueue(struct Queue *q,Node* x){
    if(q->rear == q->size-1){
        printf("Queue is Full\n");
    }
    else{
        q->rear++;
        q->Q[q->rear] = x;
    }
}

Node* Dequeue(struct Queue *q){
    Node * x = NULL;
    if(q->rear == q->front){
        printf("Queue is empty\n");
    }
    else{
        q->front++;
        x = q->Q[q->front];
    }
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

void TreeCreate(){
    struct Node *t,*p;
    int x;
    struct Queue *q;
    create(q,100);
    printf("Enter the Node\n");
    scanf("%d ",&x);
    Root->data = x;
    Root->LeftChild = NULL;
    Root->RightChild = NULL;
    enqueue(q,Root);
    
    while(isEmpty(*q)){
        p = Dequeue(q);
        printf("ENter Left Child\n");
        scanf("%d ",&x);
        if(x!=-1){
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->LeftChild = NULL;
            t->RightChild = NULL;
            p->LeftChild = t;
            enqueue(q,p);
        }
        printf("ENter Right Child\n");
        scanf("%d ",&x);
        if(x!=-1){
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->LeftChild = NULL;
            t->RightChild = NULL;
            p->RightChild = t;
            enqueue(q,p);
        }
    }
}

void preorder(struct Node *p){
    if(p){
        printf("%d ",p->data);
        preorder(p->LeftChild);
        preorder(p->RightChild);
    }
}

int main(){
    TreeCreate();
    preorder(Root);
}