#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

struct Element{
    int i;
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
    int i;
    printf("Enter Dimensions\n");
    scanf("%d%d",&s->m,&s->n);
    printf("Enter the Count of Non Zero Elements\n");
    scanf("%d",&s->num);
    s->e = new Element[s->num];
    printf("Enter non Zero Elements\n");
    for(i=0;i<s->num;i++)
        scanf("%d%d%d",&s->e[i].i,&s->e[i].j,&s->e[i].x);
    printf("\n");
    printf("\n");
}

void display(struct Sparse s)
{
    int i,j,k=0;
    for(i=1;i<=s.m;i++){
        for(j=1;j<=s.n;j++){
            if(i==s.e[k].i && j==s.e[k].j)
                printf("%d ",s.e[k++].x);
            else
                printf("0 ");
        }
        printf("\n");
    }
}

struct Sparse * add(struct Sparse *s1,struct Sparse *s2)
{
    int i,j,k;
    i=j=k=0;
    struct Sparse *sum;
    if(s1->m != s2->m || s1->n != s2->n)
        return 0;
    sum = new Sparse;
    sum->m = s1->m;
    sum->n = s2->n;
    sum->e = new Element[s1->num + s2->num];
    while(i<s1->num && j<s2->num){
        if(s1->e[i].i < s2->e[j].i){
            sum->e[k++] = s1->e[i++];
        }
        else if(s1->e[i].i > s2->e[j].i){
            sum->e[k++] = s2->e[j++];
        }
        else{
            if(s1->e[i].j < s2->e[j].j){
                sum->e[k++] = s1->e[i++];
            }
            else if(s1->e[i].j > s2->e[j].j){
                sum->e[k++] = s2->e[j++];
            }
            else{
                sum->e[k] = s1->e[i++];
                sum->e[k++].x += s2->e[j++].x;
            }
        }
    }
    for(;i<s1->num;i++)
        sum->e[k++] = s1->e[i];
    for(;j<s2->num;j++)
        sum->e[k++] = s2->e[j];
    sum->num = k;
        
    return sum;
    
}

int main()
{
    struct Sparse s1,s2,*s3;
    create(&s1);
    create(&s2);
    s3 = add(&s1,&s2);
    display(*s3);
    return 0;
}