class Solution {
public:
    int numberOfMatches(int n) {
        int matches =0;
        while(n>1){
            matches+=n/2;
            n= ceil((float)n/2);
        }
        return matches;
    }
};