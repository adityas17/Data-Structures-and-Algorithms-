#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Stack{
    int size;
    int Top;
    char *s;
};

void push(struct Stack *st, char x){
    if(st->Top == st->size-1){
        printf("stacck overflow\n");
    }
    else{
        st->Top++;
        st->s[st->Top] = x;
    }
}

int pop(struct Stack *st){
    char x=-1;
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

int isbalanced(char *exp){
    struct Stack *st;
    st->size = strlen(exp);
    st->Top = -1;
    st->s = new char[st->size];
    for(int i=0; exp[i] != '\0';i++){
        if(exp[i] == '(')
            push(st,exp[i]);
        else if(exp[i] == ')'){
            if(isEmpty(*st)==1)
                return 0;
            pop(st);
        }
    }
    return isEmpty(*st)==1?1:0;
}

int main(){
    char exp[] = "(((a+b)-(b+c)))";
    printf("%d ",isbalanced(exp));
}