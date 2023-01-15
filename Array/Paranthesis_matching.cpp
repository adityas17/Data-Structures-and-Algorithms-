#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

using namespace std;

struct Stack{
    int size;
    int top;
    char *s;
};

void create(struct Stack *st)
{
    printf("Enter the size of stack :: ");
    scanf("%d",&st->size);
    st->s = new char[st->size];
    st->top = -1;
}

void push(struct Stack *st,char x)
{
    if(st->top == st->size-1)
        printf("Stack overflow\n");
    else{
        st->s[++st->top] = x;
    }
}

void display(struct Stack st)
{
    for(int i=st.top;i>=0;i--){
        printf("%d ",st.s[i]);
    }
}

int pop(struct Stack *st)
{
    int x = -1;
    if(st->top == -1)
        printf("Stack underflow\n");
    else{
        x = st->s[st->top];
        st->top--;
    }
    return x;
}

int isempty(struct Stack *st){
    if(st->top == -1)
        return 1;
    return 0;
}

int isFull(struct Stack st){
    if(st.top == st.size-1)
        return 1;
    return 0;
}

int stackTop(struct Stack st)
{
    if(st.top == -1)
        return -1;
    else
        return st.s[st.top];
}

int isbalanced(char *exp){
    struct Stack *st;
    st->size = strlen(exp);
    st->top = -1;
    st->s = (char *)malloc(st->size*sizeof(char));
    for(int i=0;exp[i]!='\0';i++){
        if(exp[i] == '(')
            push(st,exp[i]);
        else if(exp[i] == ')'){
            if(isempty(st))
                return 0;
            pop(st);
        }
    }
    return isempty(st)?1:0;
}


int main()
{
    char exp[] = "((a+b)-(a-b))";
    printf("%d ",isbalanced(exp));
}