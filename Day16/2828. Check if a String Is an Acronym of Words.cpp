// class Solution {
// public:
//     bool isAcronym(vector<string>& words, string s) {
//         string compare = "";
//         for(auto it : words){
//             compare+=it[0];
//         }
//         return compare==s;
//     }
// };



class Solution {
public:
    bool isAcronym(vector<string>& words, string s) {
        if(words.size()!=s.length())
        return false;
        string compare = "";
        for(auto it : words){
            compare+=it[0];
        }
        return compare==s;
    }
};