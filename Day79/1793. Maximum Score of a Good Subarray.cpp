class Solution {
public:
    int maximumScore(vector<int>& A, int k) {
        int n = A.size();
        int mx= A[k];
        int mini = A[k];
        int i =k , j=k;
        while(i>0 || j<n-1){
            int leftVal = (i>0 ? A[i-1]: 0);
            int rightVal = (j<n-1 ? A[j+1]: 0);

            if(leftVal<rightVal) mini = min(mini, A[++j]);
            else mini= min( mini , A[--i]);

            mx = max(mx , mini* (j-i+1));
        }
        return mx;
    }
};