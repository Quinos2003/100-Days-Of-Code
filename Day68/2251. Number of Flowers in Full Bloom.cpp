// class Solution {
// public:
//     vector<int> fullBloomFlowers(vector<vector<int>>& nums, vector<int>&p) 
//     {
//         vector<int>ans(p.size());
//         multiset<long long>mp;
//         sort(nums.begin(),nums.end());
//         vector<vector<long long>>v;
//         for(int i=0;i<p.size();i++)
//         {
//             v.push_back({p[i],i});
//         }
//         sort(v.begin(),v.end());
//         int j=0;
//         for(int i=0;i<v.size();i++)
//         {
//             while(j<nums.size()&&v[i][0]>=nums[j][0])
//             {
//                 mp.insert(nums[j][1]);
//                 j++;
//             }
//             while(mp.size()&&v[i][0]>(*mp.begin()))
//             {
//                 mp.erase(mp.begin());
//             }
//             ans[v[i][1]]=mp.size();
//         }
//         return ans;
//     }
// };

class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& nums, vector<int>& p)
    {
        map<int,int>mp{{0,0}};
        for(auto &it:nums)
        {
            mp[it[0]]++;
            mp[it[1]+1]--;
        }
        int sum=0;
        for(auto &[value,counter]:mp)
        {
            sum+=counter;
            counter=sum;
        }
        vector<int>ans;
        for(int i=0;i<p.size();i++)
        {
            auto it=mp.upper_bound(p[i]);
            ans.push_back(prev(it)->second);
        }
        return ans;
    }
};

// // TLE
// class Solution {
// public:
//     vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
//         int f = flowers.size();
//         int p = people.size();

//         vector<int> ans;

//         for(int i = 0 ; i < p ;  i++){
//             int count =0;
//             for(int j =0 ; j<f ; j++){
//                 if( people[i] >= flowers[j][0] && people[i] <= flowers[j][1])
//                 count++;
//             }
//             ans.push_back(count);
//         }
//         return ans;

//     }
// };