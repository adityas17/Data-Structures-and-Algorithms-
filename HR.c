#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reversestring(int *A,int n)
{
    int x,y;
    int temp;
    for(x=0,y=n-1;x<y;x++,y--){
        temp=A[x];
        A[x]=A[y];
        A[y]=temp;      
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    int A[n];
    int i;
    for(i=0;i<n;i++){
        scanf("%d",&A[i]);
    }
    reversestring(A,n);
    for(i=0;i<n;i++){
        printf("%d",A[i]);
    }
}


