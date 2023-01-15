#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

double e(int x,int n)
{
    static double r=1;
    if(n==0)
        return r;
    else
        r = 1 + (x*r)/n;
        return e(x,n-1);
}

int main()
{
    printf("%lf",e(2,10));
}