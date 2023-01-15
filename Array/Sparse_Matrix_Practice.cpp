#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

struct Element{
    int  i;
    int j;
    int x;
};

struct Sparse{
    int m;
    int n;
    int num;
    struct Element *e;
};

void create(struct Sparse *s)
{
    printf("Enter Dimensions\n");
    scanf("%d%d",&s->m,&s->n);
    printf("Enter Number of Non zero Elements :: \n");
    scanf("%d ",&s->num);
    s->e = new Element[s->num];
    for(int i=0;i<s->num;i++){
        scanf("%d%d%d",&s->e[i].i,&s->e[i].j,&s->e[i].x);
    }
}

void display(struct Sparse s)
{
    int k=0;
    for(int i=1;i<=s.m;i++){
        for(int j=1;j<=s.n;j++){
            if(i == s.e[k].i && j == s.e[k].j)
                printf("%d ",s.e[k++].x);
            else
                printf("0 ");
        }
        printf("\n");
    }
}

int main()
{
    struct Sparse s;
    create(&s);
    display(s);
}