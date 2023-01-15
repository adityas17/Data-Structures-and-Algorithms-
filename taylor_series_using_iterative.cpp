#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

double e(int x,int n)
{
    double r;
    if (n == 0)
        return 1;
    for(;n>0;n--){
        r = 1 + x*r/n;
    }
    return r;
}

int main()
{
    printf("%lf", e(2,10));
    return 0;  
}