#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

struct Node{
    char data;
    struct Node *next;
}*Top = NULL;

void push(char x){
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    if(t == NULL){
        printf("Stack Overflow\n");
    }
    else{
        t->data = x;
        t->next = Top;
        Top = t;
    }
}

char pop(){
    struct Node *p = Top;
    char x = -1;
    if(Top==NULL)
        printf("Stack Underflow\n");
    else{
        Top = Top->next;
        x = p->data;
        free(p);
    }
    return x;
}

void display(struct Node *p){
    while(p!=NULL){
        printf("%d\n",p->data);
        p = p->next;
    }
}

int stackTop(){
    if(Top==NULL)
        return -1;
    else{
        return Top->data;
    }
}
int peek(struct Node *p,int pos){
    for(int i=0; p!=NULL && i<pos-1; i++){
        p = p->next;
    }
    return p->data;
}

int IsEmpty(){
    if(Top==NULL)
        return 1;
    return 0;
}

int isFull(){
    if(Top==NULL)
        return 0;
    return 1;
}

int isbalanced(char *exp){
    for(int i=0;exp[i]!='\0';i++){
        if(exp[i] == '(')
            push(exp[i]);
        else if(exp[i] == ')'){
            if(IsEmpty()==1)
                return 0;
            pop();
        }
    }
    return IsEmpty()==1?1:0;
}

int main()
{
    char exp[] = "((a+b) - (b+c))";
    printf("%d ",isbalanced(exp));
}