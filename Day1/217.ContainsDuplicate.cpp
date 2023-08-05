#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    
}

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {

        sort(nums.begin(),nums.end());

        bool ans = false ; 
        int i =0;
        while(i < nums.size()-1){
            if(nums[i]==nums[i+1])
            return true;

            i++;
        }
        return ans;
    }
};