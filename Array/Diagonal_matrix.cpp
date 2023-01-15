#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

struct Matrix{
    int *A;
    int n;
};

void set(struct Matrix *m,int i,int j,int x){
    if(i>=j)
        m->A[i*(i-1)/2 + j-1] = x;
}

int get(struct Matrix m,int i,int j){
    if(i>=j)
        return m.A[i*(i-1)/2 + j-1];
}

void display(struct Matrix m){
    for(int i=1;i<=m.n;i++){
        for(int j=1;j<=m.n;j++){
            if(i>=j)
                printf("%d ",m.A[i*(i-1)/2 + j-1]);
            else
                printf("0 ");
        }
        printf("\n");
    }
}

int main()
{
    struct Matrix m;
    printf("Enter the dimensions\n");
    scanf("%d",&m.n);
    m.A = (int *)malloc(m.n*(m.n + 1)/2 * sizeof(int));

    int i,j,x;
    printf("ENter Elements\n");
    for(i=1;i<=m.n;i++){
        for(j=1;j<=m.n;j++){
            scanf("%d",&x);
            set(&m,i,j,x);
        }
    }
    printf("\n\n");
    display(m);
}