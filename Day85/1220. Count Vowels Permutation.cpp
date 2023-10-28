class Solution {
public:
// bool isValid(string s, int n){
//     ch one = s[0];
//     for(int i =1 ; i < n ; i++){
//         if(s[i-1]=='a' && s[i]=='e') continue;

//         if(s[i-1]=='e' && (s[i]=='a' || s[i]=='i')) continue;

//         if(s[i-1]=='e' && (s[i]=='a' || s[i]=='i')) continue;
//     }
//     for( char ch : s){
//     }
// }

    int countVowelPermutation(int n) {
        long mod = pow(10, 9)+7;
        long a = 1, e = 1, i = 1, o = 1, u = 1;
        long a2, e2, i2, o2, u2; 

        for(int j =2; j<=n ; j++){
            a2 = (e + i + u) % mod;
            e2 = (a + i) % mod;
            i2 = (e + o) % mod;
            o2 = i;
            u2 = (o + i) % mod;

            a = a2, e = e2, i = i2, o = o2, u = u2;
        }

        return (a + e + i + o + u) % mod;
    }
};