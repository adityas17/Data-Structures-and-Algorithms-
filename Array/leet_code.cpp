#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        int i =0;
        for(int j=0;j<nums.size();j++){
            if(nums[j] != nums[i]){
                i++;
                nums[i] = nums[j];
            }
        }
        return i+1;
    }
};

int main()
{
    vector<int> A;
    A.push_back(1);
    A.push_back(1);
    A.push_back(2);

    Solution ob;
    cout<<ob.removeDuplicates(A)<<endl;
    for(int i:A){
        cout<<i;
    }
}