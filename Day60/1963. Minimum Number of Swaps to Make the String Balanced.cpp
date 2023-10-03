class Solution {
public:
    int minSwaps(string s) {
        int answer=0;

        stack<char> st;
        st.push(']'); 

        int n = s.size();

        for(int i=0;i<n;i++){
            char top = st.top();

            if(s[i]==']'){

                // is the '[' bracket correctly placed
                // if yes then just pop
                if (top=='[') {
                    st.pop();
                }
                // if '[' is not correctly placed 
                // then correct it (push '[') 
                else{ 
                    st.push('[');
                    answer++;
                }
            }
            else{
                st.push('[');
            }
        }
        return answer;
    }
};