#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

struct Node{
    int data;
    struct Node *next;
}*Top = NULL;

void push(int x){
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    if(t==NULL)
        printf("Stack Overflow\n");
    else{
        t->data = x;
        t->next = Top;
        Top = t;
    }
}

int pop(struct Node *p){
    int x=-1;
    if(p==NULL){
        printf("Stack Underflow\n");
        return x;
    }
    else{
        x = p->data;
        Top = Top->next;
        free(p);
        return x;
    }
}

void display(struct Node *p)
{
    while(p){
        printf("%d ",p->data);
        p = p->next;
    }
}

int peek(struct Node *p,int pos){
    int x =-1;
    for(int i=0; p && i<pos-1;i++){
        p = p->next;
    }
    if(p)
        x = p->data;
    return x;
}

int StackTop(){
    if(Top == NULL)
        return 0;
    return Top->data;
}

int isEmpty(){
    if(Top == NULL)
        return 1;
    return 0;
}

int isFull(){
    if(Top == NULL)
        return 0;
    return 1;
}

int isbalanced(char *exp){
    int i;
    for(i=0;exp[i]!='\0';i++){
        if(exp[i]=='(')
            push(exp[i]);
        else if(exp[i]==')'){
            if(isEmpty())
                return 0;
            pop(Top);
        }
    }

    return isEmpty()?1:0;
}

int isbalanced2(char *exp){
    int x;
    for(int i=0;exp[i]!='\0';i++){
        if(exp[i]=='(' || exp[i]=='{' || exp[i]=='[')
            push(exp[i]);
        else if(exp[i]==')' || exp[i]=='}' || exp[i]==']'){
            if(isEmpty())
                return 0;
            x = pop(Top);
            if(exp[i] - x > 2 || exp[i] - x <0)
                return 0;
        }
    }
    return isEmpty()?1:0;
}


int main()
{
    char exp[] = "{{[(a+b)-(a-b)]}}";
    printf("%d ",isbalanced2(exp));
}