// passed 
#include <bits/stdc++.h>
using namespace std;
void printMax(int a , int b , int c){
    int mx =0;
    mx = max(max(a,b),c);
    if(mx ==a) cout<<"1 0 0";
    else if(mx ==b) cout<<"0 1 0";
    else cout<<"0 0 1";
    cout<<endl;
}
void tankSize(int a , int b ,int c ){
    int ans =0;
    if(a==b && b==c){
        cout<<"1 1 1"<<endl;
    }
    else if(a==b || b==c || a==c){
        if(a==b) cout<<"0 0 1"<<endl;
        else if(b==c) cout<<"1 0 0"<<endl;
        else cout<<"0 1 0"<<endl;
    }
    else{
        printMax(a,b,c);
    }
}

int main(){
    int t;
    cin>>t;
    for(int i = 0; i<t; i++){
        int a,b,c;
        cin>>a>>b>>c;
        tankSize(a,b,c);
    }
    return 0;
}