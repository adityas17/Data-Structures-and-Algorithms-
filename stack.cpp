#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

struct Stack{
    int size;
    int Top;
    int *s;
};

void push(struct Stack *st, int x){
    if(st->Top == st->size-1){
        printf("stacck overflow\n");
    }
    else{
        st->Top++;
        st->s[st->Top] = x;
    }
}

int pop(struct Stack *st){
    int x=-1;
    if(st->Top == -1){
        printf("stack Underflow\n");
    }
    else{
        x = st->s[st->Top];
        st->Top--;
    }
    return x;
}

void Display(struct Stack *st){
    for(int i=st->Top; i>=0; i--){
        printf("%d ",st->s[i]);
    }
}

int peek(struct Stack *st,int pos){
    int x = -1;
    if(st->Top - pos + 1 < 0)
        printf("invalid pos");
    else{
        x = st->s[st->Top-pos+1];
    }
    return x;
}

int stackTop(struct Stack *st){
    if(st->Top == -1)
        return -1;
    else
        return st->s[st->Top];
}

int isEmpty(struct Stack st){
    if(st.Top == -1)
        return 1;
    return 0;
}

int isFull(struct Stack st){
    if(st.Top == st.size-1)
        return 1;
    return 0;
}

int main()
{
    struct Stack st;
    printf("Enter the size of the stack\n");
    scanf("%d",&st.size);
    st.s = new int[st.size];
    st.Top = -1;
    push(&st,2);
    push(&st,4);
    push(&st,5);
    push(&st,6);
    push(&st,2);
    printf("%d \n",stackTop(&st));
    Display(&st);
}
