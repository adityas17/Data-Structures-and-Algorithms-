#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

int A[10];

int fib(int n)
{
    int t0=0, t1=1,s,i;
    if(n<=1)
        return n;
    else
        for(i=2; i<=n; i++){
            s = t0 + t1;
            t0 = t1;
            t1 = s;
        }
    return s;
}

int mfib(int n)
{
    if(n<=1)
    {
        return n;
    }
    else{
        return mfib(n-2) + mfib(n-1);
    }
}

int nfib(int n)
{
    if(n<=1)
        return n;
    else{
        if(A[n-2]==-1)
            A[n-2] = nfib(n-2);
        if(A[n-1]==-1)
            A[n-1] = nfib(n-1);
        return A[n-2]+A[n-1];
    }    
}

int main()
{
    for(int i=0; i<10; i++){
        A[i] = -1;
    }
    printf("%d\n",fib(6));
    printf("%d\n",mfib(6));
    printf("%d\n",nfib(6));
    return 0;
}