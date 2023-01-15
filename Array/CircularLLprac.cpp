#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

struct Node{
    int data;
    struct Node *next;
}*head = NULL;

void create(int *A,int n){
    int i;
    struct Node *t,*last;
    head = (struct Node *)malloc(sizeof(struct Node));
    head->data = A[0];
    head->next = head;
    last = head;
    for(i=1;i<n;i++){
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }
}

void display(struct Node *p){
    do{
        printf("%d ",p->data);
        p=p->next;
    }while(p!=head);
}

int length(struct Node *p){
    int l;
    do{
        l++;
        p=p->next;
    }while(p!=head);
    return l;
}

void insert(struct Node *p,int index,int x)
{
    struct Node *t;
    int i;
    if(index<0 || index>length(p))
        return;
    t = (struct Node *)malloc(sizeof(struct Node *));
    t->data = x;
    if(index == 0){
        if(head == NULL){
            head = t;
            t->next = head;
        }
        else{
            while(p->next!=head){p=p->next;}
            p->next = t;
            t->next = head;
            head = t;
        }
    }
    else{
        for(i=0;i<index-1;i++){
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
    }
}

int Delete(struct Node *p,int index){
    struct Node *q;
    int x,i;
    if(index<1 || index>length(p))
        return -1;
    if(index == 1){
        while(p->next != head){p = p->next;}
        if(p==head){
            x = head->data;
            free(head);
            head = NULL;
        }
        else{
            p->next = head->next;
            x = head->data;
            free(head);
            head = p->next;
        }
    }
    else{
        for(i=0;i<index-2;i++){
            p=p->next;
        }
        q = p->next;
        p->next = q->next;
        x = q->data;
        free(q);
    }
    return x;
}

void reverse(struct Node *p){
    struct Node *q,*s,*r;
    r = s = p;
    while(s->next != head){s = s->next;}
    q = s;
    while(p->next != head){
        s = q;
        q = p;
        p = p->next;
        q->next = s;
    }
    p->next = q;
    head = p;
    //r->next = head; this line is correct as well 
}

void reverse2(struct Node *p){
    struct Node *q,*s,*r;
    r = s = p;
    p = p->next;
    q = s;
    while(p->next != r){
        s = q;
        q = p;
        p = p->next;
        q->next = s;
    }
    p->next = q;
    head = p;
    r->next = head;
}

int main()
{
    int A[] = {2,5,7,8,10};
    create(A,5);
    display(head);
    reverse2(head);
    printf("\n");
    display(head);
}