// #include <bits/stdc++.h>
// using namespace std;
// void findMaxSolvable( int time , string & s){
//     int ans =0;
//     vector<int> arr(26,0);
//     for( char c : s){
//         arr[c-'A']++;
//     }
//     int i =0;
//     while (time>0){
//         if(arr[i] == 0){
//             i++;
//             continue;
//         }
//         else{
//             time -= (i+1);
//             arr[i]--;
//             if(time>0) ans++;
//         }
//     }

//     cout<<ans<<endl;
// }

// int main(){
//     int t;
//     cin>>t;
//     vector<long long> ans;
//     for(int i = 0; i<t; i++){
//         int time;
//         string s;
//         cin>>time;
//         cin>>s;
//         findMaxSolvable(time,s);
//     }
//     return 0;
// }
// #include <stdio.h>

// int main() {
//     int t;
//     scanf("%d", &t);
//     while (t--) {
//         int n, k;
//         scanf("%d %d", &n, &k);
        
//         for (int i = n - k; i <= n; i++) {
//             printf("%d ", i);
//         }
        
//         for (int i = n - k - 1; i >= 1; i--) {
//             printf("%d ", i);
//         }
        
//         printf("\n");
//     }
//     return 0;
// }
// #include <bits/stdc++.h>
// using namespace std;
// void findMaxSolvable( int n , int k){
//     vector<int> ans;

//     for (int i = n - k; i <= n; i++) {
//         ans.push_back(i);
//     }
//     for (int i = n - k - 1; i >= 1; i--) {
//         ans.push_back(i);
//     }
//     for(int i = 0; i<n; i++){
//         cout<<ans[i]<<" ";
//     }
//     cout<<endl;
// }

// int main(){
//     int t;
//     cin>>t;
//     for(int i = 0; i<t; i++){
//         int n,k;
//         cin>>n;
//         cin>>k;
//         findMaxSolvable(n,k);
//     }
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// int main() {
//     int ttt;
//     cin >> ttt;

//     while (ttt--) {
//         int n, k;
//         cin >> n >> k;
//         vector<int> a(n), b(n);
//         for (int i = 0; i < n; i++) cin >> a[i];
//         for (int i = 0; i < n; i++) cin >> b[i];

//         int exp = 0, max_exp = 0, max_sub_exp = 0;

//         for (int curr_q = 0; curr_q < n; curr_q++) {
//             if (k == curr_q) {
//                 break;
//             }

//             exp += a[curr_q];
//             max_sub_exp = max(max_sub_exp, b[curr_q]);
//             max_exp = max(exp + (k - curr_q - 1) * max_sub_exp, max_exp);
//         }

//         cout << max_exp <<endl;
//     }

//     return 0;
// }

// E1. Game with Marbles
// After some discussion, Alice and Bob came up with the following game: players take turns, starting with Alice. On their turn, a player chooses a color i
//  such that both players have at least one marble of that color. The player then discards one marble of color i
// , and their opponent discards all marbles of color i
// . The game ends when there is no color i
//  such that both players have at least one marble of that color.
// Calculate the score at the end of the game if both players play optimally.
// Input
// The first line contains a single integer t(1≤t≤103) — the number of test cases.

// Each test case consists of three lines:

// the first line contains a single integer n(2≤n≤6) — the number of colors;
// the second line contains nintegers a1,a2,…,an(1≤ai≤109), where ai
//  is the number of marbles of the i-th color that Alice has;
// the third line contains nintegers b1,b2,…,bn(1≤bi≤109), where bi
// is the number of marbles of the i-th color that Bob has.
// Additional constraint on the input: the sum of n for all test cases does not exceed 2⋅105

#include <bits/stdc++.h>
// using namespace std;
// int findMaxIndex(vector<int>& arr){
//     int mx = 0;
//     int maxi=-1;
//     for(int i =0 ; i < arr.size(); i++){
//         if(mx < arr[i]){
//             mx = arr[i];
//             maxi = i;
//         }
//     }
//     return maxi;
// }
// int main() {
//     int ttt;
//     cin >> ttt;

//     while (ttt--) {
//         int n;
//         cin >> n;
//         int alice=0,bob=0;
//         vector<int> a(n), b(n);
//         for (int i = 0; i < n; i++) cin >> a[i];
//         for (int i = 0; i < n; i++) cin >> b[i];
//         vector<int> vis(n,0);
//         int turn1 = 1;
//         for(int x = 0; x<n; x++){
//             if(turn1){
//                 int bi =findMaxIndex(b);
//                 a[bi]--;
//                 b[bi]=0;
//                 turn1 = 0;
//             }
//             else{
//                 int ai= findMaxIndex(a);
//                 b[ai]--;
//                 a[ai]=0;
//                 turn1 = 1;
//             }
//         }
//         for(int i =0 ; i < n; i++){
//             alice+=a[i];
//             bob+=b[i];
//         }

//         cout << alice-bob <<endl;
//     }

//     return 0;
// }


// #include<bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int t;
//     cin >> t;
//     while(t--)
//     {
//         int n;
//     cin >> n;
//     int a[n], b[n];
//     for(int &x: a) cin >> x;
//     for(int &x: b) cin >> x;
//     vector<pair<int, int>> v(n);
//     for(int i = 0; i < n; i++) v[i] = {a[i] + b[i], i};
//     sort(v.begin(), v.end());
//     long long ans = 0, ops = 0;
//     for(int i = n - 1; i >= 0; i--)
//     {
//         if (ops % 2 == 0) ans += a[v[i].second] - 1;
//         else ans -= b[v[i].second] - 1;
//         ops++;
//     }
//     cout << ans << '\n';
//     }
// }



// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     int ttt;
//     cin >> ttt;

//     while (ttt--) {
//         int n;
//         cin >> n;
//         int alice=0,bob=0;
//         vector<int> a(n), b(n);
//         for (int i = 0; i < n; i++) cin >> a[i];
//         for (int i = 0; i < n; i++) cin >> b[i];
//         vector<pair<int, int>> v(n);

//         for(int i = 0; i < n; i++){
//             v[i] = {a[i] + b[i], i};
//         }
//         sort(v.begin(), v.end());

//         long long res = 0, ops = 0;
//         int turn1 = 1;
//         for(int i = n - 1; i >= 0; i--){
//             if (turn1){
//                 res += a[v[i].second] - 1;
//                 turn1=0;
//             } 
//             else{
//                 res -= b[v[i].second] - 1;
//                 turn1=1;
//             }
//             ops++;
//         }

//         cout <<res <<endl;
//     }

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
 
// int main() {
//     int ttt;
//     cin >> ttt;
 
//     while (ttt--) {
//         int n;
//         cin >> n;
//         int alice=0,bob=0;
//         vector<int> a(n), b(n);
//         for (int i = 0; i < n; i++) cin >> a[i];
//         for (int i = 0; i < n; i++) cin >> b[i];
//         vector<pair<int, int>> arr(n);
 
//         for(int i = 0; i < n; i++){
//             arr[i] = {a[i] + b[i], i};
//         }
//         sort(arr.begin(), arr.end());
 
//         long long res = 0;
//         int turn1 = 1;
//         for(int i = n - 1; i >= 0; i--){
//             if (turn1){
//                 res = res+ a[arr[i].second] - 1;
//                 turn1=0;
//             } 
//             else{
//                 res = res - b[arr[i].second] - 1;
//                 turn1=1;
//             }
//         }
 
//         cout <<res <<endl;
//     }
 
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;

int main() {
    int ttt;
    cin >> ttt;

    while (ttt--) {
        int n;
        cin >> n;
        int alice=0,bob=0;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];
        vector<pair<int, int>> arr(n);

        for(int i = 0; i < n; i++){
            arr[i] = {a[i] + b[i], i};
        }
        sort(arr.begin(), arr.end());

        long long res = 0;
        int turn1 = 1;
        for(int i = n - 1; i >= 0; i--){
            if (turn1){
                res += a[arr[i].second] - 1;
                turn1=0;
            } 
            else{
                res -= b[arr[i].second] - 1;
                turn1=1;
            }
        }

        cout <<res <<endl;
    }

    return 0;
}

