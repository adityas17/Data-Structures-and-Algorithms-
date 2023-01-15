#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

struct Term{
    int coeff;
    int exp;
};

struct Poly{
    int n;
    struct Term *t;
};

void create(struct Poly *p)
{
    int i;
    printf("Enter number of terms:: \n");
    scanf("%d",&p->n);
    p->t = new Term[p->n];
    printf("Enter elements\n");
    for(i=0;i<p->n;i++){
        scanf("%d%d",&p->t[i].coeff,&p->t[i].exp);
    }
}

void display(struct Poly p)
{
    int i;
    for(i=0;i<p.n;i++){
        printf("%dx%d + ",p.t[i].coeff,p.t[i].exp);
    }
    printf("\n");
    printf("\n");
}

struct Poly* add(struct Poly *p1,struct Poly *p2)
{
    int i,j,k;
    i=j=k=0;
    struct Poly *p3=new Poly;
    p3->t= new Term[p1->n + p2->n];
    while(i<p1->n && j<p2->n){
        if(p1->t[i].exp > p2->t[j].exp)
            p3->t[k++] = p1->t[i++];
        else if(p1->t[i].exp < p2->t[j].exp)
            p3->t[k++] = p2->t[j++];
        else{
            p3->t[k] = p1->t[i];
            p3->t[k++].coeff = p1->t[i++].coeff + p2->t[j++].coeff;
        }
        for(;i<p1->n;i++)
            p3->t[k++] = p1->t[i];
        for(;j<p2->n;j++)
            p3->t[k++] = p2->t[j];
        
        p3->n = k;
        return p3;
    }
}

int main()
{
    struct Poly p1,p2,*p3;
    create(&p1);
    create(&p2);
    p3 = add(&p1,&p2);
    display(p1);
    printf("\n");
    printf("\n");
    display(p2);
    printf("\n");
    printf("\n");
    display(*p3);
}