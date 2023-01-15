#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

void fun(int n)
{
    if(n>0){
        fun(n-1);
        printf("%d\t",n);
    }
}

int main()
{
    int a = 4;
    fun(a);
    return 0;
}