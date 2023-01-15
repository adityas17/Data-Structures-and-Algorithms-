#include<iostream>
#include<stdio.h>

using namespace std;

int main()
{
    int A[11] = {6,7,8,9,11,12,15,16,17,18,19};
    int x = A[0];
    for(int i=0;i<11;i++){
        if(A[i]!=x){
            printf("%d\t",x);
            x++;
            i--;
        }
        else{
            x++;
        }
    }
}