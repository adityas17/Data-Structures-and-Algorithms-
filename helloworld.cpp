#include<iostream>
#include<stdio.h>

using namespace std;

int F[20];

int fib(int n)
{
    if(n<=1){
        F[n] = n;
        return n;
    }
    else{
        if(F[n-2] == -1)
            F[n-2] = fib(n-2);
        if(F[n-1] == -1)
            F[n-1] = fib(n-1);
        return F[n-2] + F[n-1];
    }
}

int C(int n,int r)
{
    if(n == r || r == 0)
        return 1;
    return C(n-1,r-1) + C(n-1,r);
}

int main()
{
    int a = -1;
    for(int i=0;i<20;i++){
        F[i] = a;
    }
   printf("%d",C(4,3));
}