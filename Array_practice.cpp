#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

struct Array{
    int A[10];
    int size;
    int length;
};

void display(struct Array arr)
{
    int i;
    for(i=0;i<arr.length;i++){
        printf("%d\t",arr.A[i]);
    }
}

void add(struct Array *arr,int x)
{
    if(arr->length < arr->size){
        arr->A[arr->length++] = x;
    }
}

void insert(struct Array *arr,int index,int x)
{
    if(index>0 && index<arr->size){
        for(int i=arr->length;i>index;i--){
            arr->A[i] = arr->A[i-1];
        }
        arr->A[index] = x;
        arr->length++;
    }
}

int del(struct Array *arr,int index)
{
    if(index>0 && index<arr->size){
        int x = arr->A[index];
        for(int i=index;i<arr->length-1;i++){
            arr->A[i] = arr->A[i+1];
        }
        arr->length--;
        return x;
    }
}

int linearSearch(struct Array *arr,int key)
{
    int i;
    for(i = 0; i<arr->length; i++){
        if(key == arr->A[i]){
            return i;
        }
    }
    return -1;
}

int binarySearch(struct Array *arr,int key)
{
    int l,h,mid;
    l=0;
    h=arr->length;
    while(l<=h){
        mid = (l+h)/2;
        if(key == arr->A[mid])
            return mid;
        else if(key < arr->A[mid])
            h = mid-1;
        else 
            l = mid+1;
    }
    return -1;
}

int Rbinary(int a[],int l,int h,int key)
{
    int mid;
    if(l<=h){
        if(key == a[mid])
            return mid;
        else if(key < a[mid])
            return Rbinary(a,l,mid-1,key);
        else    
            return Rbinary(a,mid+1,h,key);
    }
    return -1;
}

int get(struct Array arr,int index)
{
    if(index>=0 && index<arr.length)
        return arr.A[index];
}

int set(struct Array *arr,int index,int x)
{
    if(index >= 0 && index < arr->length)
        arr->A[index] = x;
}

int sum(struct Array arr)
{
    int i;
    int sum = 0;
    for(i=0; i<arr.length; i++){
        sum = sum + arr.A[i];
    }
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
    int i;
    double sum = 0;
    for(i=0; i<arr.length; i++){
        sum = sum + arr.A[i];
    }
    return sum/arr.length;
}

int max(struct Array arr)
{
    int max = arr.A[0];
    for(int i=0; i<arr.length; i++)
        if(arr.A[i]>max)
            max = arr.A[i];
    return max;
}

int min(struct Array arr)
{
    int min = arr.A[0];
    for(int i=0; i<arr.length; i++)
        if(arr.A[i]<min)
            min = arr.A[i];
    return min;
}

int reverse(struct Array *arr)
{
    int i,j;
    int *B;
    B = (int *)malloc(arr->length*sizeof(int));
    for(i=arr->length-1,j=0;i>=0;i--,j++)
    {
        B[j] = arr->A[i];
    }
    for(i=0;i<arr->length;i++){
        arr->A[i] = B[i];
    }
}

int swap(int *x,int *y)
{
    int temp = *x;
    *x=*y;
    *y=temp;
}

int reverse2(struct Array *arr)
{
    int i,j;
    for(i=0,j=arr->length-1;i<j;i++,j--){
        swap(&arr->A[i],&arr->A[j]);
    }
}

void insertsort(struct Array *arr,int x)
{
    int i = arr->length-1;
    if(arr->length == arr->size)
        return;
    while(i>=0 && arr->A[i]>x){
        arr->A[i+1] = arr->A[i];
        i--;
    }
    arr->A[i+1] = x;
    arr->length++;
}

int issorted(struct Array arr)
{
    for(int i=0; i<arr.length-1; i++)
        if(arr.A[i]>arr.A[i+1])
            return 0;
    return 1;
    
}

void Rearrange(struct Array *arr)
{
    int i,j;
    i=0;
    j=arr->length-1;
    while(i<j){
        while(arr->A[i]<0){i++;}
        while(arr->A[j]>0){j--;}
        if(i<j){
            swap(&arr->A[i],&arr->A[j]);
        }
    }
}

struct Array *mergesort(struct Array *arr1,struct Array *arr2)
{
    int i,j,k;
    i=j=k=0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
    while(i<arr1->length && j<arr2->length){
        if(arr1->A[i]<arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else
            arr3->A[k++] = arr2->A[j++];
    }
    for(;i<arr1->length;i++)
        arr3->A[k++] = arr1->A[i];
    for(;j<arr2->length;j++)
        arr3->A[k++] = arr2->A[j];

    arr3->length = arr1->length + arr2->length;
    arr3->size = 10;
    return arr3;
}

struct Array *Union(struct Array *arr1,struct Array *arr2)
{
    int i,j,k;
    i=j=k=0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
    while(i<arr1->length && j<arr2->length){
        if(arr1->A[i]<arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else if(arr2->A[j]<arr1->A[i])
            arr3->A[k++] = arr2->A[j++];
        else{
            arr3->A[k++] = arr2->A[i++];
            j++;
        }
    }
    for(;i<arr1->length;i++)
        arr3->A[k++] = arr1->A[i];
    for(;j<arr2->length;j++)
        arr3->A[k++] = arr2->A[j];

    arr3->length = k;
    arr3->size = 10;
    return arr3;
}

struct Array *Union2(struct Array *arr1,struct Array *arr2)
{
    int i,j,k;
    i=j=k=0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
    for(i=0;i<arr1->length;i++){
        arr3->A[k++]=arr1->A[i];
    }
    for(j=0;j<arr2->length;j++){
        if(linearSearch(arr1,arr2->A[j])==-1)
            arr3->A[k++] = arr2->A[j];
    }
    arr3->length = k;
    arr3->size = 10;
    return arr3;
}

struct Array *Intersection(struct Array *arr1,struct Array *arr2)
{
    int i,j,k;
    i=j=k=0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
    while(i<arr1->length && j<arr2->length){
        if(arr1->A[i]<arr2->A[j])
            i++;
        else if(arr2->A[j]<arr1->A[i])
            j++;
        else{
            arr3->A[k++] = arr2->A[i++];
            j++;
        }
    }
    arr3->length = k;
    arr3->size = 10;
    return arr3;
}

int main()
{
    struct Array arr1 = {{8,7,6,9,3},10,5};
    struct Array arr2 = {{10,7,8,2,9},10,5};

    struct Array *arr3;
    arr3 = Union2(&arr1,&arr2);
    
    display(*arr3);
}