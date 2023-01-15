#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

using namespace std;

struct Node{
    int coeff;
    int exp;
    struct Node *next;
}*poly = NULL;

void create()
{
    struct Node *last,*t;
    int x,y,num;
    printf("Enter Number of terms in the equation:: \n");
    scanf("%d",&num);
    for(int i=0;i<num;i++){
        printf("Enter term no.%d:: ",i);
        t = (struct Node *)malloc(sizeof(struct Node));
        scanf("%d%d",&t->coeff,&t->exp);
        t->next = NULL;
        if(poly == NULL){
            poly = last = t;
        }
        else{
            last->next = t;
            last = t;
        }
    }
}

void display(struct Node *p){
    while(p){
        printf("%dx%d +",p->coeff,p->exp);
        p = p->next;  
    }
}

void evaluate(struct Node *p,int x){
    double sum = 0.0;
    while(p){
        sum += p->coeff*pow(x,p->exp);
        p = p->next;
    }

    printf("Sum is :: %lf",sum);

}

int main()
{
    create();
    display(poly);
    printf("\n");
    evaluate(poly,1);
}