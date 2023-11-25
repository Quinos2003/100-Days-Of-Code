
// There is a ribbon divided into n
//  cells, numbered from 1
//  to n
//  from left to right. Initially, an integer 0
//  is written in each cell.

// Monocarp plays a game with a chip. The game consists of several turns. During the first turn, Monocarp places the chip in the 1
// -st cell of the ribbon. During each turn except for the first turn, Monocarp does exactly one of the two following actions:

// move the chip to the next cell (i. e. if the chip is in the cell i
// , it is moved to the cell i+1
// ). This action is impossible if the chip is in the last cell;
// choose any cell x
//  and teleport the chip into that cell. It is possible to choose the cell where the chip is currently located.
// At the end of each turn, the integer written in the cell with the chip is increased by 1
// .

// Monocarp's goal is to make some turns so that the 1
// -st cell contains the integer c1
// , the 2
// -nd cell contains the integer c2
// , ..., the n
// -th cell contains the integer cn
// . He wants to teleport the chip as few times as possible.

// Help Monocarp calculate the minimum number of times he has to teleport the chip.

// Input
// The first line contains one integer t
//  (1≤t≤104
// ) — the number of test cases.

// Each test case consists of two lines:

// the first line contains one integer n
//  (1≤n≤2⋅105
// );
// the second line contains n
//  integers c1,c2,…,cn
//  (0≤ci≤109
// ; c1≥1
// ).
// It can be shown that under these constraints, it is always possible to make a finite amount of turns so that the integers in the cells match the sequence c1,c2,…,cn
// .

// Additional constraint on the input: the sum of values of n
//  over all test cases does not exceed 2⋅105
// .

// Output
// For each test case, print one integer — the minimum number of times Monocarp has to teleport the chip.

#include <bits/stdc++.h>
using namespace std;
long long minTeleport( vector<int>& arr){
    long long ans =0;
    int mn = 0;
    for(int i =1 ; i < arr.size(); i++){
        if(arr[i]>mn){
            ans+=arr[i]-mn;
            mn = arr[i];
        }
        else mn = arr[i];
    }
    return ans-1;
}

int main(){
    int t;
    cin>>t;
    vector<long long> ans;
    for(int i = 0; i<t; i++){
        int n;
        cin>>n;
        vector<int> arr(n+1);
        for( int ttt =1 ; ttt <= n ; ttt++){
            cin>>arr[ttt];
        }
        ans.push_back(minTeleport(arr));
    }
    for( int i =0 ; i < t ; i ++){
        cout<<ans[i]<<endl;
    }
    return 0;
}