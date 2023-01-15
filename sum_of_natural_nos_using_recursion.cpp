#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

int fun(int n){
    if(n==0){
        return 0;
    }
    else{
        return fun(n-1) + n;
    }
}

int main()
{
    int a;
    scanf("%d",&a);
    printf("%d",fun(a));
    return 0;
}