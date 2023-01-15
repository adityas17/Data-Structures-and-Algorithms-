#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

struct Matrix{
    int *A;
    int n;
};

void set(struct Matrix *m,int i,int j,int x)
{
    int z = i-j;
    if ( z == 1)
        m->A[i-1] = x;
    else if(z == 0)
        m->A[m->n+i-2] = x;
    else if(z == -1) 
        m->A[2*m->n + i - 2] = x;
}

void dislay(struct Matrix m){
    int i,j;
    for(i=1;i<=m.n;i++){
        for(j=1;j<=m.n;j++){
            int z = i-j;
            if ( z == 1)
                printf("%d ",m.A[i-1]);
            else if(z == 0)
                printf("%d ",m.A[m.n+i-2]);
            else if(z == -1) 
                printf("%d ",m.A[2*m.n + i - 2]);
            else
                printf("0 ");
        }
        printf("\n");
    }
}

int main()
{
    struct Matrix m;
    printf("Enter Dimemnions :: \n");
    scanf("%d ",m.n);
    m.A = (int *)malloc((3*m.n - 2)*sizeof(int));
    int x;
    int i,j;
    for(i=1;i<=m.n;i++){
        for(j=1;j<=m.n;j++){
            scanf("%d",&x);
            set(&m,i,j,x);
        }
    }
    printf("\n\n");
    dislay(m);

}