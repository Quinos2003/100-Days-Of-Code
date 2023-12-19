#include <bits/stdc++.h>
using namespace std;
void findMaxSolvable( int time , string & s){
    int ans =0;
    vector<int> arr(26,0);
    for( char c : s){
        arr[c-'A']++;
    }
    int i =0;
    while (i<26){
        if(arr[i] >i){
            ans++;
        }
        i++;
    }

    cout<<ans<<endl;
}

int main(){
    int t;
    cin>>t;
    vector<long long> ans;
    for(int i = 0; i<t; i++){
        int time;
        string s;
        cin>>time;
        cin>>s;
        findMaxSolvable(time,s);
    }
    return 0;
}