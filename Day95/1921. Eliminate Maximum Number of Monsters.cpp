// class Solution {
// public:
//     int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
//         int n = dist.size();
//         vector<int> time(n,0);
//         for(int i =0 ; i < n ; i++){
//             time[i]= ceil((float)dist[i]/ speed[i]);
//         }
//         sort(time.begin(), time.end());

//         for(int i =0; i < n ; i++){
//             if(i+1>time[i]) return i;
//         }

//         return n;
//     }
// };
class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        priority_queue<double, vector<double>, greater<double>> time;
        
        for(int i = 0; i < dist.size(); ++i)
            time.push(ceil((double)dist[i] / speed[i] ));
        
        int t = 0;
        while(time.size() && time.top() > t++) time.pop();
        return dist.size() - time.size();
    }
};