#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;
void fun(int n)
{
    if(n>0){
        printf("%d",n);
        fun(n-1);
        fun(n-1);
    }
}

int main()
{
    int a;
    scanf("%d", &a);
    fun(a);
    return 0;
}