class Solution {
public:
    string reverseWords(string s) {

        stack <string> st;
        int n = s.size();
        string temp = "";
        string ans = "";

        for(int i =0; i <n ; i ++){
            char ch= s[i];
            if(ch==' '){
                if(temp!=""){
                    st.push(temp);
                    temp="";
                }
                
            }
            else
            temp = temp + ch;
        }
        if(temp!="")
        st.push(temp);

        while(!st.empty()){
            ans = ans + (st.top()+" ");
            st.pop();
        }
        ans.pop_back();
        return ans;
    }
};
 
 
// https://leetcode.com/problems/reverse-words-in-a-string/submissions/1014192882/