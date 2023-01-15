#include<iostream>
#include<stdio.h>

using namespace std;



bool isAnagram(char * s, char * t){
    int H[150];
    for(int i=0;s[i]!= '\0';i++){
        H[s[i]]++;
    }
    for(int j=0;t[j]!= '\0';j++){
        H[s[j]]--;

    }
    for(int x=0;H[x]!='\0';x++){
        if(H[x]!=0)
            return false;
    }
    return true;  

}

int main(){

    

    return 0;
}