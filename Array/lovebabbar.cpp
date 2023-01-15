#include<iostream>

using namespace std;

void pattern1(int n)
{
    int i = 1, j;
    while(i<=n){
        j = 1;
        int k = i;
        while(j<=i){
            cout<< i - j + 1 << " ";
            k--;
            j++;
        }
        cout<<endl;
        i++;
    }
}

void pattern2(int n){
    int i=1,j=1;
    char x = 'A';
    while(i<=n){
        j = 1;
        while(j<=i){
            cout<< x  << " ";
            x++;
            j++;
        }
        cout<<endl;
        i++;
    }
}

int main()
{
    pattern2(3);
}