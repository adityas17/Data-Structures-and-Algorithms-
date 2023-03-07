#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

struct Stack{
    int size;
    int Top;
    int *s;
}*st1,*st2;


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


void enqueue(char x){
    push(st1,x);
}

int Dequeue(){
    if(isEmpty(*st2)){
        if(isEmpty(*st1)){
            printf("Queue is Empty\n");
            return -1;
        }
        else{
            while(!isEmpty(*st1)){
                push(st2,pop(st1));
            }
        }
    }
    return pop(st2);
}



int main()
{
    st1->size = st2->size = 10;
    st1->Top = st2->Top = -1;
    st1->s = new int[st1->size];
    st2->s = new int[st2->size]; 
    enqueue(4);
    enqueue(5);
    enqueue(6);
    enqueue(7);
    printf("%d \n",Dequeue());
    enqueue(8);
    printf("%d \n",Dequeue());
}
