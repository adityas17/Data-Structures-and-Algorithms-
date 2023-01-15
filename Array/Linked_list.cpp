#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

struct Node{
    int data;
    struct Node *next;
}*first = NULL,*second=NULL,*third=NULL;

void create(int A[],int n){
    int i;
    struct Node *last,*t;
    first = new Node[1];
    first->data = A[0];
    first->next = NULL;
    last = first;
    for(i=1;i<n;i++){
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void create2(int A[],int n){
    int i;
    struct Node *last,*t;
    second = new Node[1];
    second->data = A[0];
    second->next = NULL;
    last = second;
    for(i=1;i<n;i++){
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void display(struct Node *p)
{
    while(p!=NULL){
        printf("%d ", p->data);
        p = p->next;
    }
}

void Rdisplay(struct Node *p)
{
    if(p!=0){
        printf("%d ",p->data);
        Rdisplay(p->next);
    }
}

int count(struct Node *p){
    int c=0;
    while(p){
        c++;
        p = p->next;
    }
return c;
}

int Rcount(struct Node *p){
    static int c = 0;
    if(p == 0)
        return c;
    c++;
    return Rcount(p->next);
}

int sum(struct Node *p){
    int s = 0;
    while(p!=NULL){
        s += p->data;
        p = p->next; 
    }
    return s;
}

int Rsum(struct Node *p){
    if(p==0)
        return 0;
    return Rsum(p->next)+p->data;
}

int max(struct Node *p){
    int max = -32768;
    while(p){
        if(p->data>max)
            max = p->data;
        p = p->next;
    }
    return max;
}

int Rmax(struct Node *p){
    int x=0;
    if(p == 0)
        return INT32_MIN;
    x = Rmax(p->next);
    return x>p->data ? x:p->data;
}

struct Node * RSearch(struct Node *p,int key)
{
    if(p==0)
        return NULL;
    if(key == p->data)
        return p;
    return RSearch(p->next,key);
}

struct Node * LSearch(struct Node *p,int key)
{
    while(p!=NULL){
        if(key == p->data)
            return p;
        p = p->next;
    }
    return NULL;
}

struct Node * HeadSearch(struct Node *p,int key){
    struct Node *q = NULL;
    while(p!=NULL){
        if(key == p->data){
            q->next = p->next;
            p->next = first->next;
            first = p;
        }
        else{
            q=p;
            p = p->next;
        }
    }
}

void insert(struct Node *p,int index,int x)
{
    struct Node *t;
    int i;
    if(index < 0 && index > count(p))
        return;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    if(index == 0){
        t->next = first;
        first = t;
    }
    else{
        for(i=0;i<index-1 && p;i++){
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
    }
}

void insertLast(struct Node *p,int x){
    struct Node *t,*last;
    last = p;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;
    if(p == NULL){
        p = last = t;
    }
    else{
        while(last != NULL){
            printf("En\n");
            last = last->next;
        }
        last->next = t;
        last = t;
    }
    
}

void sortedinsert(struct Node *p,int x){
    struct Node *t,*q=NULL;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;
    if(first == NULL)
        first = t;
    else{
        while(p && p->data < x){
            q = p;
            p = p->next;
        }
        if(p == first){
            t->next = first;
            first  = t;
        }
        else{
            t->next = q->next;
            q->next = t;
        }
    }
}

int Delete(struct Node *p,int index){
    struct Node *q;
    int x = -1,i;
    if(index<0 || index>count(p))
        return x;
    if(index == 1){
        q = first;
        x = first->data;
        first = first->next;
        delete q;
    }
    else{
        for(i=0;i<index-1;i++){
            q = p;
            p = p->next;
        }
        q->next = p->next;
        x= p->data;
        delete p;
        return x;
    }
}

int issorted(struct Node *p)
{
    int x = INT32_MIN;
    while(p!=NULL){
        if(p->data<x)
            return 0;
        x = p->data;
        p = p->next;
    }
    return 1;
}

void duplicates(struct Node *p){
    struct Node *q = p->next;
    while(q!=NULL){
        if(p->data != q->data){
            p=q;
            q = q->next;
        }
        else{
            p->next = q->next;
            delete q;
            q = p->next;
        }
    }
}

void reverse1(struct Node *p){
    struct Node *q;
    int i = 0;
    q = p;
    int *A;
    A = (int *)malloc(sizeof(int)*count(p));
    while(q){
        A[i] = q->data;
        i++;
        q = q->next;      
    }
    i--;
    while(p){
        p->data = A[i--];
        p = p->next;
    }
}

void reverse2(struct Node *p){
    struct Node *q,*r;
    q = NULL;
    r =  NULL;
    while(p){
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
}

void reverse3(struct Node *p,struct Node *q){
    if(p){
        reverse3(p->next,p);
        p->next = q;
    }
    else{
        first = q;
    }

}

void concate(struct Node *p,struct Node *q){
    third = p;
    while(p->next!=NULL){
        p = p->next;
    }
    p->next = q;
}

void Merge(struct Node *p,struct Node *q){
    struct Node *last = NULL;
    if(p->data < q->data){
        last = third = p;
        p = p->next;
        last->next = NULL;
    }
    else{
        last = third = q;
        q = q->next;
        last->next = NULL;
    }
    while(p!=NULL && q!=NULL){
        if(p->data < q->data){
            last->next = p;
            last = p;
            p = p->next;
            last->next = NULL;
        }
        else{
            last->next = q;
            last = q;
            q = q->next;
            last->next = NULL;
        }
        if(p!=NULL)
        last->next = p;
        else
        last->next = q;
    }
}

int isLoop(struct Node *f){
    struct Node *p,*q;
    p = q = f;
    do{
        p = p->next;
        q = q->next;
        q = q?q->next:NULL;
    }while(p && q && p!=q);
    return p==q?1:0;
}

void MiddleElement(struct Node *p){
    struct Node *q;
    q = p;
    while(q){
        q = q->next;
        if(q)
            q = q->next;
        if(q)
            p = p->next;
    }
    printf("Middle Element is :: %d",p->data);
}


int main()
{
    struct Node *t1,*t2;
    int A[] = {3,5,8,23,33,44,66};
    create(A,7);
    MiddleElement(first);

}