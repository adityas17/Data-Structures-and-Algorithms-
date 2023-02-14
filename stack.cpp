#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

using namespace std;

struct Stack{
    int size;
    int Top;
    char *s;
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

int isOperand(char x){
    if(x == '+' || x == '-' || x == '*' || x == '/')
        return 0;
    return 1;
}

int pre(char x){
    if(x == '+' || x == '-')
        return 1;
    else if(x == '*' || x == '/')
        return 2;
    return 0;
}

char * convert(char *infix){
    struct Stack st;
    st.size = strlen(infix);
    st.s = new char[st.size];
    char *postfix = new char[strlen(infix) + 1];
    int i=0,j=0;
    while(infix[i]!='\0'){
        if(isOperand(infix[i])){
            postfix[j++] = infix[i++];
        }
        else{
            if(pre(infix[i])>pre(stackTop(&st))){
                push(&st,infix[i++]);
            }
            else{
                postfix[j++] = pop(&st);
            }
        }
    }
    while(!isEmpty(st)){
        postfix[j++] = pop(&st);
    }
    postfix[j] = '\0';

    return postfix;
}

int main()
{
    char exp[] ="a+b*c-d/e";
    printf("%s ",convert(exp));
}
