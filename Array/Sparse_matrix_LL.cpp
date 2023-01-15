#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

struct Node{
    int col;
    int data;
    struct Node *next;
};

void display(struct Node *p,int m,int n){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(j == p->col){
                printf("%d ",p->data);
                p = p->next;
            }
            else
                printf("0 ");
        }
        printf("\n");
    }
}

int main()
{
    int m,n;
    printf("Enter Dimensions :: \n");
    scanf("%d%d",&m,&n);
    struct Node *A[m],*last,*t;
    int x,i=0,j;
    while(i<m){
        printf("Enter number of non zero elements in %d row\n",i);
        scanf("%d",&x);
        if(x<1)
            i++;
        else{
            t = (struct Node *)malloc(sizeof(struct Node));
            printf("Enter column Number and data::\n");
            scanf("%d%d",&t->col,&t->data);
            t->next = NULL;
            A[i] = t;
            last = t;
            for(j=1;j<x;j++){
                t = (struct Node *)malloc(sizeof(struct Node));
                printf("Enter column Number and data::\n");
                scanf("%d%d",&t->col,&t->data);
                last->next = t;
                last = t;
            }
            i++;
        }
    }

    display(*A,m,n);
}