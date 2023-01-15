#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

int pow(int m, int n)
{
    if(n==0){
        return 1;
    }
    else{
        return pow(m,n-1)*m;
    }
}

int main()
{
    int a,b;
    printf("Enter\n");
    scanf("%d%d",&a,&b);
    printf("%d",pow(a,b));
    return 0;
}