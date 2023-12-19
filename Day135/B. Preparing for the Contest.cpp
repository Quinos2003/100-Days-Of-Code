#include <bits/stdc++.h>
using namespace std;
void findMaxSolvable( int n , int k){
    vector<int> ans;

    for (int i = n - k; i <= n; i++) {
        ans.push_back(i);
    }
    for (int i = n - k - 1; i >= 1; i--) {
        ans.push_back(i);
    }
    for(int i = 0; i<n; i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int t;
    cin>>t;
    for(int i = 0; i<t; i++){
        int n,k;
        cin>>n;
        cin>>k;
        findMaxSolvable(n,k);
    }
    return 0;
}