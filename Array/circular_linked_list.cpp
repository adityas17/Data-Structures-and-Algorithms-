#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

struct Node{
    int data;
    struct Node *next;
}*Head = NULL;

void create(int A[],int n){
    int i;
    struct Node *t,*last;
    Head = (struct Node *)malloc(sizeof(struct Node));
    Head->data = A[0];
    Head->next = Head;
    last = Head;
    for(i=1;i<n;i++){
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }
}

void display(struct Node *h){
    do{
        printf("%d ",h->data);
        h = h->next;
    }while(h!=Head);
}

void Rdisplay(struct Node *h){
    static int flag = 0;
    if( h!=Head || flag == 0 ){
        flag = 1;
        printf("%d ",h->data);
        Rdisplay(h->next);
    }
    flag = 0;
}

int length(struct Node *p){
    int len = 0;
    do{
        len++;
        p = p->next;
    }while(p!=Head);
    return len;
}

void insert(struct Node *p,int index,int x){
    int i;
    struct Node *t;
    if(index<0 && index>length(p))
        return;
    if(index == 0){
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = x;
        if(Head == NULL){
            Head = t;
            Head->next = Head;
        }
        else{
            while(p->next != Head){p = p->next;}
            p->next = t;
            t->next = Head;
            Head = t;
        }
    }
    else{
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = x;
        for(i=0;i<index-1;i++){
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
    }
}

int Delete(struct Node *p,int index){
    struct Node *q;
    int i,x;
    if(index<0 && index>length(p))
        return -1;
    if(index == 1){
        while(p->next != Head) p = p->next;
        if(Head == p){
            free(Head);
            Head = NULL;
        }
        else{
            p->next = Head->next;
            x = Head->data;
            free(Head);
            Head = p->next;
        }
    }
    else{
        for(i=0;i<index-2;i++){
            p = p->next;
        }
        q = p->next;
        p->next = q->next;
        x = q->data;
        free(q);
    }
    return x;
}



int main()
{
    int A[5] = {2,4,6,8,20};
    create(A,5);

    display(Head);
    Delete(Head,1);
    printf("\n");
    display(Head);
}