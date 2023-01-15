#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

struct Node{
    struct Node *prev;
    int data;
    struct Node *next;
}*first=NULL;

void create(int A[],int n){
    struct Node *t,*last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->prev = NULL;
    first->next = NULL;
    last = first;
    for(int i=1;i<n;i++){
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->prev = last;
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void display(struct Node *p){
    while(p){
        printf("%d ",p->data);
        p = p->next;
    }
}

int length(struct Node *p){
    int c = 0;
    while(p){
        c++;
        p = p->next;
    }
    return c;
}

void insert(struct Node *p,int index,int x){
    int i;
    struct Node *t;
    if(index<0 || index>length(p))
        return;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->prev = NULL;
    t->next = NULL;
    if(index == 0){
        if(first == NULL){
            first = t;
        }
        else{
            t->next = first;
            first->prev = t;
            first = t;
        }
    }
    else{
        for(i=0;i<index-1;i++){
            p=p->next;
        }
        t->prev = p;
        t->next = p->next;
        if(p->next)
            p->next->prev = t;
        p->next = t;
    }
}

int Delete(struct Node *p,int index){
    int i,x;
    if(index<1 || index>length(p))
        return -1;
    if(index == 1){
        first = first->next;
        if(first)
            first->prev = NULL;
        x = p->data;
        free(p);
        return x;
    }
    else{
        for(i=0;i<index-1;i++)
            p = p->next;
        p->prev->next = p->next;
        if(p->next)
            p->next->prev = p->prev;
        x = p->data;
        free(p);
        return x;
    }
}

void Reverse(struct Node *p){
    struct Node *temp;
    while(p){
        temp = p->next;
        p->next = p->prev;
        p->prev = temp;
        p = p->prev;
        if(p!=NULL && p->next==NULL)
            first = p;
    }
}

int main()
{
    int A[] = {2,3,5,3,1};
    create(A,5);
    display(first);
    printf("\n");
    Reverse(first);
    display(first);
}