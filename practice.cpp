#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

struct Node{
    struct Node *prev;
    int data;
    struct Node *next;
}*first = NULL;

void create(int *A,int n){
    struct Node *t,*last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->prev = NULL;
    first->data = A[0];
    first->next = NULL;
    last = first;
    for(int i=1;i<n;i++){
        t =  (struct Node *)malloc(sizeof(struct Node));
        t->prev = last;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void display(struct Node *p){
    while(p!=NULL){
        printf("%d ",p->data);
        p = p->next;
    }
}

int main(){
    int A[5] = {2,4,5,6,7};
    create(A,5);
    display(first); 
}