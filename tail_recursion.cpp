#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

using namespace std;

void fun(int n){
    if(n>0){
        printf("%d\t",n);
        fun(n-1);
    }
}

int main()
{
    int a = 5;
    fun(a);
    return 0;
}