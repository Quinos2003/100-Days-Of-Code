class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> st;
        st.push(n-1);
        vector<int> ans(n);

        for(int i = n-2; i>=0; i--){
            int temp = temperatures[i];

            while( st.size() && temp>= temperatures[st.top()]) 
            st.pop();

            if(st.size())
            ans[i] = st.top()-i;

            st.push(i);
        }
        return ans;
    }
};