#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

struct Array{
    int A[10];
    int size;
    int n;
};

void display(struct Array arr)
{
    int i;
    for(i=0;i<arr.n;i++){
        printf("%d,\t",arr.A[i]);
    }
}

void append(struct Array *arr, int x)
{
    if(arr->n < arr->size){
        arr->A[arr->n++] = x;
    }
}

void insert(struct Array *arr,int index,int x){
    if(index >= 0 && index < arr->size){
        for(int i=arr->n;i>index;i--)
            arr->A[i] = arr->A[i-1];
        arr->A[index] = x;
        arr->n++;
    }
} 

void Delete(struct Array *arr,int index)
{
    if(index >= 0 && index < arr->size)
        int x = arr->A[index];
        for(int i = index;i< arr->n-1; i++){
            arr->A[i] = arr->A[i+1];
        }
        arr->n--;
}

void swap(int *x,int *y)
{
    int temp;
    temp= *x;
    *x = *y;
    *y = temp;
}

int linearsearch(struct Array *arr,int x)
{
    int i;
    for(i=0;i<arr->n;i++){
        if(x==arr->A[i]){
            return 0;
        }
    }
    return -1;
}

int binarysearch(struct Array *arr,int key)
{
    int l,h,m;
    l=0;
    h=arr->n-1;
    while(l<=h){
        m = (l+h)/2;
        if(key == arr->A[m])
            return m;
        else if(key<arr->A[m])
            h = m-1;
        else 
            l = m+1;  
    }
    return -1;
}

int Rbinarysearch(int a[],int l,int h,int key)
{
    int mid;
    if(l<=h){
        mid = (l+h)/2;
        if(key == a[mid])
            return mid;
        else if(key < a[mid])
            return Rbinarysearch(a,l,mid-1,key);
        else 
            return Rbinarysearch(a,mid+1,h,key);
    }
}

int get(struct Array arr, int index)
{
    if(index>=0 && index<arr.n)
        return arr.A[index];
    return -1;
}

int set(struct Array *arr,int index,int x)
{
    if(index>=0 && index<arr->n)
        arr->A[index] = x;
}

int max(struct Array arr)
{
    int i;
    int max = arr.A[0];
    for(i=1;i<arr.n;i++)
        if(arr.A[i]>max)
            max = arr.A[i];
    return max;
}

int min(struct Array arr)
{
    int i;
    int min = arr.A[0];
    for(i=1;i<arr.n;i++)
        if(arr.A[i]<min)
            min = arr.A[i];
    return min;
}

int sum(struct Array arr)
{
    int sum=0;
    for(int i=0;i<arr.n;i++)
        sum = sum + arr.A[i];
    return sum;
}

int Rsum(int A[],int n)
{
    if(n<0)
        return 0;
    return Rsum(A,n-1) + A[n];
}

double avg(struct Array arr)
{
    double sum=0;
    for(int i=0;i<arr.n;i++)
        sum = sum + arr.A[i];
    printf("%lf\n",sum);
    return sum/arr.n;
}

int reverse(struct Array *arr)
{
    int *B;
    int i,j;
    B = (int *)malloc(arr->n*sizeof(int));
    for(i=arr->n-1,j=0;i>=0;i--,j++)
    {
        B[j] = arr->A[i];
    }
    for(i=0;i<arr->n;i++)
    {
        arr->A[i] = B[i];
    }
}

int reverse2(struct Array *arr)
{
    int i,j;
    for(i=0,j=arr->n-1;i<j;i++,j--){
        swap(arr->A[i],arr->A[j]);
    }
}

int leftshift(struct Array *arr)
{
    int i;
    int x = arr->A[0];
    for(i=0;i<arr->n;i++)
    {
        arr->A[i] = arr->A[i+1];
    }
    arr->A[arr->n-1] = x;
}

void insertsort(struct Array *arr,int x)
{
    int i = arr->n-1;
    if(arr->n<arr->size)
        while(i>=0 && arr->A[i]>x){
            arr->A[i+1] = arr->A[i];
            i--;
        }
        arr->A[i+1] = x;
        arr->n++;
}

int Issorted(struct Array arr)
{
    int i;
    for(i=0;i<arr.n-1;i++){
        if(arr.A[i]>arr.A[i+1])
            return 0;
    }
    return 1;
}

void REarrange(struct Array *arr)
{
    int i,j;
    i = 0;
    j = arr->n-1;
    while(i<j)
    {
        while(arr->A[i]<0){i++;}
        while(arr->A[j]>0){j--;}
        if(i<j){
            swap(&arr->A[i],&arr->A[j]);
        }
    }
}

struct Array *merge(struct Array *arr1,struct Array *arr2)
{
    int i,j,k;
    i=j=k=0;
    struct Array *arr3;
    arr3 = (struct Array *)malloc(sizeof(struct Array));
    while(i<arr1->n && j<arr2->n){
        if(arr1->A[i]<arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else
            arr3->A[k++] = arr2->A[j++];
    }
    for(;i<arr1->n;i++){
        arr3->A[k++] = arr1->A[i];
    }
    for(;j<arr2->n;j++){
        arr3->A[k++] = arr2->A[j];
    }
    arr3->n=arr1->n+arr2->n;
    arr3->size=10;

    return arr3;
}

struct Array *Union(struct Array *arr1,struct Array *arr2)
{
    int i,j,k;
    i=j=k=0;
    struct Array *arr3;
    arr3 = (struct Array *)malloc(sizeof(struct Array));
    while(i<arr1->n && j<arr2->n){
        if(arr1->A[i]<arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else if(arr2->A[j]<arr1->A[i])
            arr3->A[k++] = arr2->A[j++];
        else{
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
    }
    for(;i<arr1->n;i++){
        arr3->A[k++] = arr1->A[i];
    }
    for(;j<arr2->n;j++){
        arr3->A[k++] = arr2->A[j];
    }
    arr3->n=k;
    arr3->size=10;

    return arr3;
}

struct Array * Union2(struct Array *arr1,struct Array *arr2)
{
    int i,j,k;
    int x;
    i=j=k=0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
    for(x=0;x<arr1->n;x++){
        arr3->A[k++] = arr1->A[x];
    }
    printf("%d",x);
    for(j=0;j<arr2->n;j++){
        if(linearsearch(arr1,arr2->A[j])==-1)
            arr3->A[k++] = arr2->A[j];
    }
    printf("%d\n",k);
    arr3->n = k;
    arr3->size = 10;

    return arr3;
}

struct Array *Intersection(struct Array *arr1,struct Array *arr2)
{
    int i,j,k;
    i=j=k=0;
    struct Array *arr3;
    arr3 = (struct Array *)malloc(sizeof(struct Array));
    while(i<arr1->n && j<arr2->n){
        if(arr1->A[i]<arr2->A[j])
            i++;
        else if(arr2->A[j]<arr1->A[i])
            j++;
        else{
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
    }
    
    arr3->n=k;
    arr3->size=10;

    return arr3;
}

struct Array * Intersection2(struct Array *arr1,struct Array *arr2)
{
    int i,j,k;
    int x;
    i=j=k=0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
    for(j=0;j<arr2->n;j++){
        if(linearsearch(arr1,arr2->A[j])==0)
            arr3->A[k++] = arr2->A[j];
    }
    arr3->n = k;
    arr3->size = 10;

    return arr3;
}

struct Array *Difference(struct Array *arr1,struct Array *arr2)
{
    int i,j,k;
    i=j=k=0;
    struct Array *arr3;
    arr3 = (struct Array *)malloc(sizeof(struct Array));
    while(i<arr1->n && j<arr2->n){
        if(arr1->A[i]<arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else if(arr2->A[j]<arr1->A[i])
            j++;
        else{
            i++;
            j++;
        }
    }
    for(;i<arr1->n;i++){
        arr3->A[k++] = arr1->A[i];
    }

    arr3->n=k;
    arr3->size=10;

    return arr3;
}

int main()
{
    struct Array arr1 = {{8,7,6,9,3},10,5};
    struct Array arr2 = {{10,7,8,2,9},10,5};
    struct Array *arr3;
    arr3 = Intersection2(&arr1,&arr2);
    display(*arr3);
}