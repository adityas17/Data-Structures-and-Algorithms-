#include<stdio.h>
#include <stdio.h>

int reverse(int x){
    int rem,rev=0;
    while(x){
        rem = x%10;
        rev = rev*10 + rem;
        x = x/10;
    }
    return rev;
}

int main()
{
    int x = 1534236469;
    int y = reverse(x);
    printf("%d",y);
}