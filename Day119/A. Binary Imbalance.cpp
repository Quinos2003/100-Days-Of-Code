// s.contains("0");
#include <bits/stdc++.h>
using namespace std;
bool zeroPresent(int n, string s){
    return s.find('0') != string::npos;
}

int main(){
    int t;
    cin>>t;
    vector<int> ans;
    for(int i = 0; i<t; i++){
        int n;
        string s;
        cin>>n>>s;
        if(zeroPresent(n,s)){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}