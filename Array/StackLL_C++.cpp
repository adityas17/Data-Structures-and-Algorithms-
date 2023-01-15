#include<iostream>

using namespace std;

class Node{
    public:
        int data;
        Node *next;
};

class Stack{
    private:
        Node *Top;
    public:
        Stack(){Top = NULL;}
        void push(int x);
        int pop();
        void display();
        int isEmpty();
        int isbalanced(char *exp);
};

void Stack::push(int x){
    Node *t = new Node;
    if(t == NULL)
        cout<<"Stack Overflow "<<endl;
    else{
        t->data = x;
        t->next = Top;
        Top = t;
    }
}

int Stack::pop(){
    int x = -1;
    Node *t = Top;
    if(t == NULL)
        cout<<"Stack Underflow "<<endl;
    else{
        Top = Top->next;
        x = t->data;
        delete t;
    }
}

void Stack::display(){
    Node *t = Top;
    while(t){
        cout<<t->data<< " ";
        t = t->next;
    }
}

int Stack::isEmpty(){
    if(Top == NULL)
        return 1;
    return 0;
}

int isbalanced(char *exp)
{
    Stack st;
    int i;
    for(i=0;exp[i]!='\0';i++){
        if(exp[i]=='(')
           st.push(exp[i]);
        else if(exp[i]==')'){
            if(st.isEmpty())
                return 0;
            st.pop();
        }
    }
    return st.isEmpty()?1:0;
}

int main()
{
    char exp[] = "((a+b)-(c-d))";
    Stack jk;
    cout<< jk.isbalanced(exp)<<endl; 
    
}