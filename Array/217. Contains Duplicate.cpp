#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

class Solution {
    public:
        bool containsDuplicate(vector<int>& nums) {
            
            unordered_set<int> mySet;

            for(int i=0;i<nums.size();i++){
                int number = nums[i];

                if(mySet.find(number) == mySet.end()){
                    mySet.insert(number);
                }
                else{
                    return true;
                }
            }

            return false;

        }
};

int main(){


}