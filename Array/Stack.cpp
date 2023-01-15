#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

struct Stack{
    int size;
    int top;
    int *s;
};

void create(struct Stack *st)
{
    printf("Enter the size of stack :: ");
    scanf("%d",&st->size);
    st->s = new int[st->size];
    st->top = -1;
}

void push(struct Stack *st,int x)
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

int isempty(struct Stack st){
    if(st.top == -1)
        return 1;
    return 0;
}

int isempty(struct Stack st){
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

int main()
{
    struct Stack st;
    create(&st);
    push(&st,3);
    push(&st,2);
    display(st);
    printf("\n");
    push(&st,1);
    display(st);
    printf("Popped element is :: %d\n",pop(&st));
    display(st);
    printf("\n");
    push(&st,5);
    display(st);
}