// // /**
// //  * // This is the Master's API interface.
// //  * // You should not implement it, or speculate about its implementation
// //  * class Master {
// //  *   public:
// //  *     int guess(string word);
// //  * };
// //  */
// // class Solution {
// // public:
// //     void findSecretWord(vector<string>& wordlist, Master& master) {
// //         for (int i = 0; i < 10; ++i) {
// //             string& guessWord = wordlist[rand() % wordlist.size()];
// //             int guessMatch = master.guess(guessWord);
            
// //             vector<string> newlist;
// //             for (string& word : wordlist) {
// //                 if (guessMatch == myMatch(word, guessWord)) {
// //                     newlist.push_back(word);
// //                 }
// //             }
// //             wordlist = newlist;
// //         }
// //     }
    
// // private:
// //     int myMatch(string& word1, string& word2) {
// //         int cnt = 0;
        
// //         for (int i = 0; i < 6; ++i) {
// //             if (word1[i] == word2[i]) {
// //                 ++cnt;
// //             }
// //         }
        
// //         return cnt;
// //     }
// // };
// class Solution {
// public:
//     int check( string &a, string &b) {
//         int ct = 0 ; 
//         for(int i =0 ; i < 6 ; i++) 
//             if(a[i] == b[i])
//                 ct++ ; 
//         return ct ; 
//     }
    
//     void findSecretWord(vector<string>& words, Master& master) {
//         for(int i=0, matches = 0; i < 30 and matches !=6 ; i++) {
//             string trial = words[words.size()/2]  ; // since we have to pick a random word for each iteration
//             matches = master.guess(trial) ; 
//             vector<string> possibilities ; 
//             for(auto word: words) {
//                 if(check(word, trial) == matches)
//                     possibilities.push_back(word); 
//             }
//             words = possibilities ; 
//         }
//     }
// };
/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
public:
    int countOfMatchedLetters(string& s1,string& s2){
        int count = 0;
        for(int i=0;i<6;i++){
            count+=(s1[i] == s2[i]);
        }
        return count;
    }
    
    
    void findSecretWord(vector<string>& words, Master& master) {
        srand(time(0));
        vector<string> v;
        for(string& s : words)v.push_back(s);
        while(!v.empty()){
            vector<string>add;
            int n = v.size();
            int randomIndex = rand()%n;
            string randomStr = v[randomIndex];
            int machedLetters = master.guess(randomStr);
            if(machedLetters == 6)return ;
            for(string& s : v){
                if(countOfMatchedLetters(s,randomStr) == machedLetters){
                    add.push_back(s);
                }
            }
            v = add;
        }
        return ;
    }
};