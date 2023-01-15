#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

struct Node{
    int data;
    struct Node *next;

}*first = NULL;

void create(int *A,int n)
{
    struct Node *t,*last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;
    for(int i=1;i<n;i++){
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }
}

void display(struct Node *p)
{
    while(p){
        printf("%d ",p->data);
        p = p->next;
    }
}

int main()
{
    int A[5] = {2,3,4,6,7};
    create(A,5);
    display(first);
}
