class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end()); 
        sort(s.begin(), s.end());
        int happy =0 ;

        int pg =0, ps=0; 

        while(pg<g.size() && ps<s.size()){
            if(g[pg]<= s[ps]){
                happy++;
                pg++;
            }
            ps++;
        }
        return happy;
    }
};
