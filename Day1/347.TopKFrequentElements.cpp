
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        // unordered_map<int,int> freq;

        // int n = nums.size();

        // for(int i =0 ; i <n ; i++){
        //     freq[nums[i]]++;
        // }



        // return {};
        unordered_map <int,int>counts; //first int is number and second is count
        priority_queue<pair<int,int>>maxi;
        //first int is count and second is number

        for(int i=0;i<nums.size();i++){
            counts[nums[i]]++;
        }

        //now put the values of counts in maxi andg get the top K out of max heap
        while(!counts.empty()){
            maxi.push({counts.begin()->second,counts.begin()->first});
            counts.erase(counts.begin());
        }

        vector<int>ans;
        for(int i=0;i<k;i++){
            ans.push_back(maxi.top().second);
            maxi.pop();
        }
        return ans;
    }
};