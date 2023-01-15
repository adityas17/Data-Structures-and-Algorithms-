#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

double e(int x, int n)
{
    static double f = 1, p = 1;
    double r;
    if(n == 0)
        return 1;
    r = e(x,n-1);
    f = f*x;
    p = p*n;
    return r + f/p;
}

int main()
{
    printf("%lf",e(2,10));
    return 0;
}