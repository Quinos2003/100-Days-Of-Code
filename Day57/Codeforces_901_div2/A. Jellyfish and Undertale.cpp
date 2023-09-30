#include <bits/stdc++.h>
using namespace std;
int explodeTime(int a , int b ,  vector<int>& tool){
    int sum =0;
    for( int it : tool ){
        sum+= min(a,it);
    }
    return b+sum-1;
}
int main(){
    int t;
    cin>>t;
    vector<int> ans;
    for(int i = 0; i<t; i++){
        int b,a,n;
        cin>>a>>b>>n;
        vector<int> tool(n);
        for( int ttt =0 ; ttt < n ; ttt++){
            cin>>tool[ttt];
        }
        ans.push_back(explodeTime(a,b,tool));
    }
    for( int i =0 ; i < t ; i ++){
        cout<<ans[i]<<endl;
    }
    return 0;
}