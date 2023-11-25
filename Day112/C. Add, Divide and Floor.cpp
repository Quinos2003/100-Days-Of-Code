#include <bits/stdc++.h>
using namespace std;
void tankSize(vector<int>& arr){
    int mx =0;
    int n = arr.size();
    for (int i = 0; i < arr.size(); i++) mx = max(mx,arr[i]);

    vector<int> ans;

    while (mx){
        int flag =1;
        for (int i = 1; i < n; i++){
            if(arr[i]!=arr[i-1]) flag =0;
        }
        if(flag) break;

        int index = (mx%2==0);

        for(int i =0 ; i < n ; i++){
            arr[i]= (arr[i]+index)/2;
        }
        mx = (mx + index)/2;
        ans.push_back(index);
    }
    cout<<ans.size()<<endl;

    if(ans.size()<=n){
        for(auto it : ans ){
            cout<<it<<" ";
        }
        cout<<endl;
    }

    
    
}

int main(){
    int t;
    cin>>t;
    vector<int> ans;
    for(int i = 0; i<t; i++){
        int n;
        cin>>n;
        vector<int> arr(n);
        for( int ttt =0 ; ttt < n ; ttt++){
            cin>>arr[ttt];
        }
        tankSize(arr);
    }

    return 0;
}