// 1021. Remove Outermost Parentheses
class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.length();
        int p1 =0;
        int local =0;

        stack <char> st;
        string ans;


        for(int i=0; i < n; i ++){
            if(s[i]=='('){
                if(!st.empty()){
                    ans.push_back('(');
                }
                st.push('(');
            }
            else{
                st.pop();
                if(!st.empty()){
                    ans.push_back(')');
                }
            }
        }
        return ans;
    }
};