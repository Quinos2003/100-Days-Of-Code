class Solution {
public:
    void moveZeroes(vector<int>& num) {
        int countZero=0;
    for(int i=0;i<num.size();i++){
        if (num[i]==0){
            countZero++;
        }
        else if(countZero>0){
            num[i-countZero]=num[i];
            num[i]=0;
        }
    }
        
    }
};