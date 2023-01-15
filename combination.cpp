#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

int fact(int x)
{
    if(x==0)
        return 1;
    return fact(x-1)*x;
}

int C(int n,int r)
{
    int t1,t2,t3;
    t1=fact(n);
    t2=fact(r);
    t3=fact(n-r);
    return t1/(t2*t3);
}

int C2(int n,int r)
{
    if(r==0 || n==r)
        return 1;
    return C2(n-1,r-1) + C2(n-1,r);
}

int main()
{
    printf("%d\n",C(5,3));
    printf("%d",C2(5,3));
}