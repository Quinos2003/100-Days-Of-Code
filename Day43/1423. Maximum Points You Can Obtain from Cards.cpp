class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum = 0;
        for(int i =0 ; i < k ; i++) sum+= cardPoints[i];
        int curr = sum;
        int j =k-1;
        while(j>=0){
            curr-= cardPoints[j]; // remove the last element from initial window
            curr+= cardPoints[cardPoints.size()-k+j]; // add elements from last
            sum = max( curr , sum);
            j--;
        }
        return sum;
    }
};