#include<iostream>
#include<stdio.h>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    char A[] = "madam";
    int i,j;
    for(j=-0;A[j]!='\0';j++){}
    j=j-1;
    for(i=0;i<j;i++,j--){
        if(A[i]!=A[j]){
            printf("Not a palindrome\n");
            break;
        } 
    }
    if(i==j){
        printf("its pallindrome");
    }
    
}