// class Solution {
// public:
    
//     int minimumSum(int n, int k) {
//         int sum =0;
//         unordered_map<int, int> mp;
//         int index =0 , num=1;
//         while(index<n){
//             if(mp.find(k - num) == mp.end()){
//                 sum+=num;
//                 mp[num]=1;
//             }
//             num++;
//             index++;
//         }
//         return sum;
//     }
// };
class Solution {
public:
    int minimumSum(int n, int k) {
        int sum = 0;
        unordered_set<int> cantUse; 

        int index = 0, num = 1;
        while (index < n) {
            if (cantUse.find(num) == cantUse.end()) {
                sum += num;
                cantUse.insert(k - num); 
                index++;
            }
            num++;
        }
        return sum;
    }
};
// Leetcode Weeky contest 359