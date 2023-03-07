#include<stdio.h>
#include<stdlib.h>
#include "Queue1.h"

struct Node *root;

void create()
{
    struct Node *p,*t;
    int x;
    struct Queue q;
    Qcreate(&q,100);
    printf("Enter root value\n");
    scanf("%d",&x);
    root = (struct Node *)malloc(sizeof(struct Node));
    root->data = x;
    root->lchild = root->rchild = NULL;
    enqueue(&q,root);

    while(isEmpty(q)){
        p = Dequeue(&q);
        printf("Enter lchild\n");
        scanf("%d",&x);
        if(x!=-1){
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            enqueue(&q,t);
        }
        printf("Enter Rchild\n");
        scanf("%d",&x);
        if(x!=-1){
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            enqueue(&q,t);
        }
    }
}

void preorder(struct Node *p){
    if(p){
        printf("%d ",p->data);
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

int main()
{
    create();
    preorder(root);
    return 0;
}