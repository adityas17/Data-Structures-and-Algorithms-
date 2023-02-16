#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

using namespace std;

struct Node{
    int data;
    struct Node *next;
}*Top = NULL;

void push(int x){
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

int pop(){
    struct Node *p = Top;
    int x = -1;
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

int isbalanced(int *exp){
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

int isOperand(char x){
    if(x=='+' || x=='-' || x=='*' || x=='/')
        return 0;
    return 1;
}

int pre(char x){
    if(x=='+' || x=='-')
        return 1;
    else if(x=='*' || x=='/')
        return 2;
    return 0;
}

int Evaluate(char *exp){
    int i,x1,x2,r=0;
    for(i=0;exp[i]!='\0';i++){
        if(isOperand(exp[i])){
            push(exp[i]-'0');
        }
        else{
            x2 = pop();
            x1 = pop();
            switch(exp[i]){
                case '+': r = x1+x2; break;
                case '-': r = x1-x2; break;
                case '*': r = x1*x2; break;
                case '/': r = x1/x2; break;
            }
            push(r);
        }
    }
    return Top->data;
}

int main()
{
    char exp[] = "234*+82/-";
    printf("%d ",Evaluate(exp));
}
// int Eval(char *postfix)
// {
//  int i=0;
//  int x1,x2,r=0 ;

//  for(i=0;postfix[i]!='\0';i++)
//  {
//     if(isOperand(postfix[i]))
//     {
//         push(postfix[i]-'0');
//     }
//     else
//     {
//         x2=pop();x1=pop();
//         switch(postfix[i])
//             {
//             case '+':r=x1+x2; break;
//             case '-':r=x1-x2; break;
//             case '*':r=x1*x2; break;
//             case '/':r=x1/x2; break;
//             }
//         push(r);
//         }
//     }
//     return Top->data;
// }
// int main()
// {
//  char postfix[]="234*+82/-";

//  printf("Result is %d\n",Eval(postfix));

//  return 0;
// }