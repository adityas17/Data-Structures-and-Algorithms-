#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

void funB(int n);
void funA(int n){
    if(n>0){
        printf("%d\t",n);
        funB(n-1);
    }
}

void funB(int n){
    if(n>0){
        printf("%d\t",n);
        funA(n/2);
    }
}

int main()
{
    int a = 20;
    funA(a);
    return 0;
}