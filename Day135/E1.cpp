// // E1. Game with Marbles
// // After some discussion, Alice and Bob came up with the following game: players take turns, starting with Alice. On their turn, a player chooses a color i
// //  such that both players have at least one marble of that color. The player then discards one marble of color i
// // , and their opponent discards all marbles of color i
// // . The game ends when there is no color i
// //  such that both players have at least one marble of that color.
// // Calculate the score at the end of the game if both players play optimally.
// // Input
// // The first line contains a single integer t(1≤t≤103) — the number of test cases.

// // Each test case consists of three lines:

// // the first line contains a single integer n(2≤n≤6) — the number of colors;
// // the second line contains nintegers a1,a2,…,an(1≤ai≤109), where ai
// //  is the number of marbles of the i-th color that Alice has;
// // the third line contains nintegers b1,b2,…,bn(1≤bi≤109), where bi
// // is the number of marbles of the i-th color that Bob has.
// // Additional constraint on the input: the sum of n for all test cases does not exceed 2⋅105

// #include <bits/stdc++.h>
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
