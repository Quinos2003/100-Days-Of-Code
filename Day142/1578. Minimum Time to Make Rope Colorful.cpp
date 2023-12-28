class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size(),count =1,minTime =0;
        int maxTimeColor =neededTime[0],totalTimeColor =neededTime[0];
        for(int i =1 ; i < n ; i++){
            if(colors[i-1] == colors[i]){
                count++;
                maxTimeColor = max(maxTimeColor,neededTime[i]);
                totalTimeColor += neededTime[i];
            }
            else{
                if(count>1)minTime +=(totalTimeColor - maxTimeColor);
                count =1;
                totalTimeColor=neededTime[i];
                maxTimeColor =neededTime[i];
            }
        }
        if(count>1) minTime +=(totalTimeColor - maxTimeColor);
        return minTime;
    }
};