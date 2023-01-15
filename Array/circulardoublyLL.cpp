#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

struct Node{
    struct Node *prev;
    int data;
    struct Node *next;
}*head = NULL;

void create(int *A,int n)
{
    struct Node *t,*last;
    head = (struct Node *)malloc(sizeof(struct Node));
    head->prev = head;
    head->data = A[0];
    head->next = head;
    last = head;
    for(int i=1;i<n;i++){
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->prev = last;
        t->next = last->next;
        last->next = t;
        last = t;
        head->prev = last;
    }
}

void display(struct Node *p){
    do{
        printf("%d ",p->data);
        p = p->next;
    }while(p!=head);
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
    if(index<0 && index>length(p))
        return;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->prev = NULL;
    t->next = NULL;
    if(index == 0){
        t->prev = head->prev;
        t->next = head;
        
        head->prev->next = t;
        head->prev = t;

        head = t;
    }
    else{
        for(i=0;i<index-1;i++){
            p = p->next;
        }
        t->next = p->next;
        t->prev = p;

        p->next->prev = t;
        p->next = t;
    }
}

int Delete(struct Node *p,int index)
{
    int i,x;
    if(index<1 && index>length(p))
        return -1;
    if(index == 1){
        head = head->next;
        head->prev = p->prev;
        p->prev->next = head;
        x = p->data;
        free(p);
        return x;
    }
    else{
        for(i=0;i<index-1;i++)
            p = p->next;
        p->prev->next = p->next;
        p->next->prev = p->prev;
        x = p->data;
        free(p);
        return x;
    }
}

int main()
{
    int A[] = {2,4,6,7,9};
    create(A,5);
    display(head);
    printf("\n");
    Delete(head,3);
    display(head);
}