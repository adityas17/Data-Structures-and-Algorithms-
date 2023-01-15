#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        vector<int> A;
        if(x<0)
                return false;
        int i=0;
        while(x>0){
            A.push_back(x%10);
            i++;
            x=x/10;
        }
        for(int f:A){
            cout<<f<<endl;
        }
        cout<<i<<endl;
        int m,n;
        for(m=0,n=i-1;m<n;m++,n--){
            if(A[m] != A[n]){
                return false;
            }
            if(m==n){
                return true;
            }
        }
    }
};

int main()
{
    Solution ob;
    cout<<ob.isPalindrome(121)<<endl;
}